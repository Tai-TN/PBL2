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
    this->setWindowTitle("To Do List");
    LoadFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt", manager);


    // Khi nhấn nút "Add Task"
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    // Khi đổi trạng thái hiển thị
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::updateTaskList);
    connect(ui->editTaskButton, &QPushButton::clicked, this, &MainWindow::editTask);
    connect(ui->taskTree, &QTreeWidget::itemChanged,this, &MainWindow::onItemChanged);
    connect(ui->taskCompleted, &QPushButton::clicked, this, &MainWindow::onCompletedClicked);
    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainWindow::updateTaskList);

    connect(ui->viewSwitchButton, &QPushButton::clicked, this, &MainWindow::switchView);
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
    //showCompleteTasks = true;

    buildTrie();
    
    ui->stackedWidget->setCurrentIndex(2);
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
    bool ok;
    QString title = QInputDialog::getText(this, "Title", "Enter task name:",QLineEdit::Normal, "", &ok);

    if (!ok || title.isEmpty() ) return;

    int priority = QInputDialog::getInt(this, "Priority", "Enter priority",QLineEdit::Normal,1,10,1,&ok);

    if (!ok) return;

    QString deadline = QInputDialog::getText(this,"Deadline","Enter Deadline (yyyy-mm-dd)", QLineEdit::Normal,"",&ok);

    if (!ok || deadline.isEmpty()) return;

    Task* task = new Task(title.toStdString(), priority, deadline.toStdString(), false);
    manager.addTask(task);
    taskTrie.Insert(title);
    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
    updateTaskList();   
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
        std::string idStr, title , priorityStr, deadline, completedStr;
        
        getline(ss,idStr,'|');
        getline(ss,title,'|');
        getline(ss,priorityStr,'|');
        getline(ss,deadline,'|');
        getline(ss,completedStr,'|');

        size_t id = size_t(stoll(idStr));
        int priority = stoi(priorityStr);
        bool completed = (completedStr == "1");

        Task* t = new Task(title, priority, deadline, completed);
        manager.addTask(t);
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
        f << t->getID() << "|" << t->getTitle() << "|" << t->getPriority() << "|" << t->getDeadline() << "|" << (t->isCompleted() ? 1 : 0) << "\n";
    }
    f.close();
    //QMessageBox::information(this, "Succes", "Data saved successfully!");
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

void MainWindow::editTask(){
    QTreeWidgetItem *currentItem = ui->taskTree->currentItem();
    if (!currentItem){
        QMessageBox::warning(this, "No selection", "Please select a task to edit!");
        return;
    }

    QString oldTitle = currentItem->text(0);
    size_t taskID = currentItem->data(0, Qt::UserRole).toULongLong();
     bool ok;
    QString newTitle = QInputDialog::getText(this, "Edit Task", "Enter new title:",QLineEdit::Normal, "", &ok);

    if (!ok || newTitle.isEmpty() ) return;

    int newPriority = QInputDialog::getInt(this, "Priority", "Enter priority",QLineEdit::Normal,1,3,1,&ok);

    if (!ok) return;

    QString newDeadline = QInputDialog::getText(this,"Deadline","Enter Deadline (yyyy-mm-dd)", QLineEdit::Normal,"",&ok);

    if (!ok || newDeadline.isEmpty()) return;

    if (oldTitle!=newTitle){
        taskTrie.DeleteWord(oldTitle);
        taskTrie.Insert(newTitle);
    }
    manager.removeTask(taskID);
    Task* newTask = new Task(newTitle.toStdString(),newPriority, newDeadline.toStdString(), currentItem->checkState(0) == Qt::Checked);
    manager.addTask(newTask);
    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
    updateTaskList();

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
        // qDebug() << "Task not found: ID=" << taskID;
        // // Chỉ hiển thị thông báo một lần và thoát
        // static bool errorShown = false;
        // if (!errorShown) {
        //     errorShown = true;
            QMessageBox::warning(this, "Lỗi", "Không tìm thấy task với ID: " + QString::number(taskID));
           // QTimer::singleShot(1000, this, [&]() { errorShown = false; }); // Reset sau 1 giây
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



// void MainWindow::onCompletedClicked(){
//     QString currentText = ui->taskCompleted->text();
//     if (currentText == "Incomplete Tasks"){
//         showCompleteTasks = false;
//     }
//     else{
//         showCompleteTasks = true;
//     }
//     ui->taskCompleted->setText(showCompleteTasks  ? "Incomplete Tasks" : "Complete Tasks" );
//     updateTaskList();
// }

void MainWindow::onCompletedClicked(){
    showCompleteTasks = !showCompleteTasks;
    
    if (showCompleteTasks) {
        ui->taskCompleted->setText("📋Incompleted Tasks");
    } else {
        ui->taskCompleted->setText("✅Completed Tasks");
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


void MainWindow::switchView(){
    isListView = !isListView;

    if (isListView){
        ui->stackedWidget->setCurrentIndex(2);
        ui->viewSwitchButton->setText("📅 Xem Lịch");
        updateTaskList();
    }
    else{
        ui->stackedWidget->setCurrentIndex(0);
        ui->viewSwitchButton->setText("📋 Xem Danh Sách");
        onCalendarDateClicked(ui->calendarWidget->selectedDate());
    }

    
}


