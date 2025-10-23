#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QInputDialog>
#include <QListWidgetItem>
#include <QFont>
#include <fstream>
#include <sstream>
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString iconPath = QDir(QCoreApplication::applicationDirPath()).filePath("../resources/icons/iconWindow.png");
    QIcon windowIcon(iconPath);
    this->setWindowIcon(windowIcon);
    this->setWindowTitle("To Do List");
    
    LoadFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt", manager);

    leftMenuVisible = true;
    originalMenuWidth = ui->leftMenu->width(); // luu width goc


    connect(ui->menuBtn, &QPushButton::clicked, this, &MainWindow::toggleLeftMenu);
    connect(ui->taskList, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->calendarList, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);

    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::updateTaskList);
    connect(ui->editTaskButton, &QPushButton::clicked, this, &MainWindow::editTask);
    connect(ui->taskTree, &QTreeWidget::itemChanged,this, &MainWindow::onItemChanged);
    connect(ui->taskCompleted, &QPushButton::clicked, this, &MainWindow::onCompletedClicked);
    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainWindow::updateTaskList);

    //connect(ui->viewSwitchButton, &QPushButton::clicked, this, &MainWindow::switchView);
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::onCalendarDateClicked);





    ui->taskTree->header()->setSectionsMovable(true);
    ui->taskTree->header()->setSectionsClickable(true);
    ui->comboBox->addItem("Ưu tiên");
    ui->comboBox->addItem("Deadline");
    ui->comboBox->setCurrentIndex(0); // mặc định "Ưu tiên"
    ui->taskTree->setColumnCount(4);
    ui->taskTree->setHeaderLabels(QStringList() << "Title" << "Priority" << "Deadline" << "Xóa");
    //Cho phép resize cột 
    
    ui->taskTree->setAlternatingRowColors(true); // mau xen ke cho hang
    ui->taskTree->setIconSize(QSize(16,16));
    
    ui->taskTree->setColumnWidth(0, 400); 
    ui->taskTree->setColumnWidth(1, 50); 
    ui->taskTree->setColumnWidth(2, 151); 
    ui->taskTree->setColumnWidth(3, 50); 
    ui->taskTree->header()->setSectionResizeMode(QHeaderView::Interactive);
    
    isListView = true;

    buildTrie();
    
    ui->stackedWidget->setCurrentIndex(3);
    updateTaskList();
    
    ui->calendarWidget->setSelectedDate(QDate::currentDate()); // set mac dinh
    onCalendarDateClicked(QDate::currentDate());
}




    
     
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addTask()
{
    AdvancedTaskDialog dialog(manager, this);
    if (dialog.exec() == QDialog::Accepted) {
        Task* newTask = dialog.getCreatedTask();
        if (newTask) {
            manager.addTask(newTask);
            SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
            updateTaskList();
            buildTrie(); // 🆕 cap nhật Trie
        }
    }  
}


void MainWindow::LoadFile(const std::string& filename, HeapManager& manager){

    std::ifstream f(filename);
    if (!f){
        std::cout << "Khong mo duoc file" << std::endl;
        return;
    }
    std::string line;
    while(getline(f,line)){
        std::stringstream ss(line);
        std::vector<std::string> fields;
        std::string field;

        while(getline(ss, field, '|')){
            fields.push_back(field);
        }

        
        
        if (fields.size() >= 12){
            size_t id = std::stoul(fields[0]);
            std::string title = fields[1];
            std::string description = fields[2];
            int priority = std::stoi(fields[3]);
            std::string deadline = fields[4];
            bool completed = (fields[5] == "1");
            std::string createdAt = fields[6];
            std::string updatedAt = fields[7];
            std::string category = fields[8];
            int estimatedHours = std::stoi(fields[9]);
            int actualHours = std::stoi(fields[10]);
            std::string recurrence = fields[11];
            Task* t = new Task(title,description, priority, deadline, {}, category, estimatedHours, recurrence, completed);
            manager.addTask(t);

        }

        
    }
    f.close();

}

void MainWindow::SaveToFile(const std::string& pos){
    std::ofstream f(pos);

    if (!f){
        QMessageBox::critical(this, "Error", "Cannot open file for saving : " + QString::fromStdString(pos));
        return;
    }
    std::vector<Task*> tasks = manager.ShowTaskByPriority();

    for (Task* t : tasks){
        f << t->getID() << "|" 
          << t->getTitle() << "|" 
          << t->getDescription() << "|"
          << t->getPriority() << "|" 
          << t->getDeadline() << "|" 
          << (t->isCompleted() ? 1 : 0) << "|"
          << t->getCreatedAt() << "|"
          << t->getUpdatedAt() << "|"
          << t->getCategory() << "|"
          << t->getEstimatedHours() << "|"
          << t->getActualHours() << "|"
          << t->getRecurrence();
        
        // Lưu tags nếu có
        std::vector<std::string> tags = t->getTags();
        if (!tags.empty()) {
            f << "|";
            for (size_t i = 0; i < tags.size(); ++i) {
                f << tags[i];
                if (i < tags.size() - 1) {
                    f << ","; // Phân cách tags bằng dấu phẩy
                }
            }
        }
        
        f << "\n";
    }
    f.close();
}
void MainWindow::updateTaskList() {
    if (!ui->taskTree) {
        QMessageBox::critical(this, "Lỗi", "QTreeWidget không được khởi tạo!");
        return;
    }

    ui->taskTree->blockSignals(true); // Ngăn tín hiệu itemChanged khi thêm item
    ui->taskTree->clear();

    // Thiết lập giao diện
    ui->taskTree->setColumnCount(4);
    ui->taskTree->setHeaderLabels(QStringList() << "Title" << "Priority" << "Deadline" << "Xóa");
    ui->taskTree->header()->setSectionResizeMode(QHeaderView::Interactive);
    ui->taskTree->setIconSize(QSize(24, 24));
    ui->taskTree->setColumnWidth(3, 60);
    ui->taskTree->header()->setSectionResizeMode(3, QHeaderView::ResizeToContents);


    
    QString prefix = ui->searchBar->text().trimmed().toLower();
    std::vector<QString> matchedTitles;

    if (!prefix.isEmpty()){
        matchedTitles = taskTrie.Suggest(prefix);
    }



    // Lấy danh sách task
    QString mode = ui->comboBox ? ui->comboBox->currentText() : "Ưu tiên";
    std::vector<Task*> tasks;
    if (mode == "Ưu tiên") {
        tasks = manager.ShowTaskByPriority();
    } else if (mode == "Deadline") {
        tasks = manager.ShowTaskByDeadline();
    }

    if (tasks.empty()) {
        ui->taskTree->blockSignals(false);
        ui->taskTree->viewport()->update();
        return;
    }

    QString iconPath = QDir(QCoreApplication::applicationDirPath()).filePath("../resources/icons/bin.png");
    QIcon binIcon(iconPath);
    if (binIcon.isNull()) {
        QMessageBox::warning(this, "Fail", "Fail to load icon!");
        return;
    }

    for (Task* t : tasks) {

        QString title = QString::fromStdString(t->getTitle());

        if (!prefix.isEmpty() && std::find(matchedTitles.begin(), matchedTitles.end(), title) == matchedTitles.end()){
            continue;
        }



        if ((t->isCompleted() && showCompleteTasks) || (!showCompleteTasks && !t->isCompleted())){
        QTreeWidgetItem *item = new QTreeWidgetItem(ui->taskTree);
        item->setFlags(Qt::ItemIsEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
        item->setCheckState(0, t->isCompleted() ? Qt::Checked : Qt::Unchecked);
        item->setText(0, QString::fromStdString(t->getTitle()));
        item->setText(1, QString::number(t->getPriority()));
        item->setText(2, QString::fromStdString(t->getDeadline()));
        item->setData(0, Qt::UserRole, QVariant((qulonglong)t->getID()));
        item->setIcon(3, binIcon);
        if (t->isCompleted()){
            QFont font = item->font(0);
            font.setStrikeOut(true);
            item->setFont(0, font);

        }
    }
}

    ui->taskTree->blockSignals(false);
    ui->taskTree->viewport()->update();

    disconnect(ui->taskTree, &QTreeWidget::itemClicked, this, &MainWindow::onItemClicked);
    connect(ui->taskTree, &QTreeWidget::itemClicked, this, &MainWindow::onItemClicked);


}

void MainWindow::editTask()
{
    QTreeWidgetItem* currentItem = ui->taskTree->currentItem();
    if (!currentItem) {
        QMessageBox::warning(this, "No selection", "Vui lòng chọn task để sửa!");
        return;
    }
    
    size_t taskID = currentItem->data(0, Qt::UserRole).toULongLong();
    Task* task = manager.getTaskByID(taskID);
    if (!task) {
        QMessageBox::warning(this, "Lỗi", "Không tìm thấy task!");
        return;
    }
    
    AdvancedTaskDialog dialog(task, manager, this);
    if (dialog.exec() == QDialog::Accepted) {
        SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
        updateTaskList();
        buildTrie(); // 🆕 Cập nhật Trie
    }
}

void MainWindow::onItemChanged(QTreeWidgetItem *item, int column)
{
    if (!item || column != 0) {
        qDebug() << "Invalid item or column in onItemChanged: item=" << item << ", column=" << column;
        return;
    }

    size_t taskID = item->data(0, Qt::UserRole).toULongLong();
    bool newState = (item->checkState(0) == Qt::Checked);

    // Tạm ngắt tín hiệu
    ui->taskTree->blockSignals(true);

    // Cập nhật trạng thái
    Task* task = manager.getTaskByID(taskID);
    if (task) {
        task->setCompleted(newState);
        SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
        

        if (newState){
            QFont font = item->font(0);
            font.setStrikeOut(true);
            item->setFont(0, font);

            //Xóa sau 2 giây
            QTimer::singleShot(2000, this, [this, item, taskID](){
                // manager.removeTask(taskID);
                // SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
                updateTaskList();
            });
        }
        else{
            QFont font = item->font(0);
            font.setStrikeOut(false);
            item->setFont(0, font);
        }
        
        // Cập nhật trạng thái checkbox
        item->setCheckState(0, newState ? Qt::Checked : Qt::Unchecked);
    } else {
        
            QMessageBox::warning(this, "Lỗi", "Không tìm thấy task với ID: " + QString::number(taskID));
        }


    // Bật lại tín hiệu
    ui->taskTree->blockSignals(false);
    ui->taskTree->viewport()->update();
}


void MainWindow::onItemClicked(QTreeWidgetItem *item, int column){
    if (column == 3){
        size_t taskID = item->data(0, Qt::UserRole).toULongLong();
        QString taskTitle = item->text(0);
        Task* task = manager.getTaskByID(taskID);
        if (task){
            taskTrie.DeleteWord(taskTitle);
            manager.removeTask(taskID);

            SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
            updateTaskList();
        }
        else{
            QMessageBox::warning(this, "Warning!", "Không tìm thấy Task!");
        }
    }
}


void MainWindow::onCompletedClicked(){
    showCompleteTasks = !showCompleteTasks;
    QIcon completedIcon(":/blueIcons/resources/icons/check-circle.svg");
    QIcon incompleteIcon(":/blueIcons/resources/icons/x-circle.svg");
    if (showCompleteTasks) {
        ui->taskCompleted->setIcon(incompleteIcon);
        ui->taskCompleted->setText("Incompleted Tasks");
        
    } else {
        ui->taskCompleted->setIcon(completedIcon);
        ui->taskCompleted->setText("Completed Tasks");
        
    }
    
    updateTaskList();
}


void MainWindow::buildTrie(){
    taskTrie.Clear();
    std::vector<Task*> tasks = manager.ShowTaskByPriority();
    for (Task* t : tasks){
        QString title = QString::fromStdString(t->getTitle());
        taskTrie.Insert(title);
    }

} 


void MainWindow::onCalendarDateClicked(const QDate& date){
    if (!ui->calendarTaskList){
        QMessageBox::warning(this, "Error", "Không tìm thấy calendar TaskList");
        return;
    }

    ui->calendarTaskList->clear();

    std::vector<Task*> tasks = manager.ShowTaskByDeadline();
    int taskCount = 0;

    for (Task* task : tasks){
        QString deadlinestr = QString::fromStdString(task->getDeadline());
        QDate taskDate = QDate::fromString(deadlinestr.left(10), "yyyy-MM-dd");

        if (taskDate == date){
            QString status = task->isCompleted() ? "✅" : "⏳";
            QString priorityEmoji;
            QColor bgColor;
            switch(task->getPriority()){
                case 1: priorityEmoji = "🟢"; bgColor = QColor(220, 255, 220); break;
                case 2: priorityEmoji = "🟡"; bgColor = QColor(255, 255, 200); break;
                case 3: priorityEmoji = "🔴"; bgColor = QColor(255, 220, 220); break;
                default: priorityEmoji = "⚪"; break;
            }
            QString itemText = QString("%1 %2 %3\n%4")
                              .arg(status)
                              .arg(priorityEmoji)
                              .arg(QString::fromStdString(task->getTitle()))
                              .arg(QString::fromStdString(task->getDeadline()));
        
            QListWidgetItem* item = new QListWidgetItem(itemText, ui->calendarTaskList);
            item->setBackground(bgColor);
            item->setData(Qt::UserRole, QVariant((qulonglong)task->getID()));

            QFont font = item->font();
            font.setPointSize(10);
            item->setFont(font);

            item->setSizeHint(QSize(0, 50));// chieu cao

            taskCount++;
            }
    }

    if (taskCount == 0) {
        QListWidgetItem* item = new QListWidgetItem("📝 Không có task nào cho ngày này", ui->calendarTaskList);
        item->setTextAlignment(Qt::AlignCenter);
        item->setForeground(Qt::gray);
        
        QFont font = item->font();
        font.setItalic(true);
        font.setPointSize(11);
        item->setFont(font);

        item->setSizeHint(QSize(0, 60));
    }


}


void MainWindow::toggleLeftMenu(){
    leftMenuVisible = !leftMenuVisible;
    QIcon align_sign(":/blueIcons/resources/icons/align-justify2.svg");
    QIcon back_sign(":/blueIcons/resources/icons/arrow-left1.svg");
    
    
    if (leftMenuVisible){
        ui->menuBtn->setIcon(back_sign);
        
        for (int w = 0; w <= originalMenuWidth; w += 10) {
            QTimer::singleShot(w * 2, this, [this, w]() {
                ui->leftMenu->setMinimumWidth(w);
                ui->leftMenu->setMaximumWidth(w);
            });
        }
    }
    else{ 
        ui->menuBtn->setIcon(align_sign);
        
        int currentWidth = ui->leftMenu->width();
        for (int w = currentWidth; w >= 0; w -= 10) {
            QTimer::singleShot((currentWidth - w) * 2, this, [this, w]() {
                ui->leftMenu->setMinimumWidth(w);
                ui->leftMenu->setMaximumWidth(w);
            });
        }
    }
}


void MainWindow::onMenuButtonClicked(){
    QPushButton* clickedButton = qobject_cast<QPushButton*>(sender()); // xac dinh nut duoc bam
    if (!clickedButton) return;

    if (clickedButton->objectName() == "calendarList"){
        ui->stackedWidget->setCurrentIndex(0);
    }
    else if (clickedButton->objectName() == "taskList"){
        ui->stackedWidget->setCurrentIndex(3);
    }
    else if (clickedButton->objectName() == "categorybtn"){
        ui->stackedWidget->setCurrentIndex(3);
    }
    highlightActiveButton(clickedButton); // doi nen nut dang chon
}

void MainWindow::highlightActiveButton(QPushButton* clickedButton){
    QList<QPushButton*> menuButtons = {  // danh sach cac nut menu
        ui->taskList, ui->calendarList
    };
    foreach(QPushButton* btn, menuButtons){  // foreach : duyet qua va so sanh  
        if (btn == clickedButton){
            btn->setStyleSheet("background-color : #fefeff; padding : 10px 5px; text-align: left; border-top-radius : 20px;");
        }
        else{
            btn->setStyleSheet("background-color: transparent;padding : 10px 5px; text-align: left;"); // nen trong suot
        }
    }

}