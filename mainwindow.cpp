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
    setupStatistics();
    updateStatistics();


    connect(ui->menuBtn, &QPushButton::clicked, this, &MainWindow::toggleLeftMenu);
    connect(ui->taskList, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->calendarList, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->categorybtn, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->statisticsbtn, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->todayTask, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::updateTaskList);
    //connect(ui->editTaskButton, &QPushButton::clicked, this, &MainWindow::editTask);
    connect(ui->taskCompleted, &QPushButton::clicked, this, &MainWindow::onCompletedClicked);
    connect(ui->allTask, &QPushButton::clicked, this,&MainWindow::onAllTaskClicked);

    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainWindow::updateTaskList);
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::onCalendarDateClicked);

    //category 
    connect(ui->addCategorybtn, &QPushButton::clicked, this, &MainWindow::addNewCategory);
    connect(ui->backCatetorybtn, &QPushButton::clicked, this, &MainWindow::backCategory);  
    
    //TaskListWidget
    m_taskListWidget = new TaskListWidget(ui->taskListcontainer);
    m_todayListWidget = new TaskListWidget(ui->todayListcontainer);

    m_categoryListWidget = new TaskListWidget(ui->categoryListcontainer);
    QVBoxLayout* catLayout = new QVBoxLayout(ui->categoryListcontainer);
    catLayout->addWidget(m_categoryListWidget);
    catLayout->setContentsMargins(0, 0, 0, 0);
    catLayout->setSpacing(0);

    QVBoxLayout* layout = new QVBoxLayout(ui->taskListcontainer);
    layout->addWidget(m_taskListWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QVBoxLayout* todayLayout = new QVBoxLayout(ui->todayListcontainer);
    todayLayout->addWidget(m_todayListWidget);
    todayLayout->setContentsMargins(0, 0, 0, 0);
    todayLayout->setSpacing(0);
    //noTaskLabel = new QLabel(ui->todayListcontainer);
    // noTaskLabel->setText("Không có task nào cho ngày hôm nay! ");
    // noTaskLabel->setAlignment(Qt::AlignCenter); 
    ui->noTaskLabel->hide();
    // noTaskLabel->setStyleSheet(
//     "QLabel {"
//         "color: #808080;"                 // Màu chữ xám nhạt (ví dụ)
//         "font-size: 16px;"                // Kích thước chữ lớn hơn
//         "font-weight: bold;"              // In đậm
//         "padding: 20px;"                  // Thêm khoảng đệm xung quanh chữ
//         "border: 2px dashed #D3D3D3;"     // Thêm đường viền nét đứt nhẹ nhàng
//         "border-radius: 8px;"             // Bo tròn góc viền
//         "background-color: #F0F0F0;"      // Màu nền hơi xám/trắng nhạt
//     "}"
// );


    updateTaskList();

    connect(m_taskListWidget, &TaskListWidget::taskStatusChanged, this, &MainWindow::onTaskStatusChanged);
    connect(m_taskListWidget, &TaskListWidget::editTaskRequest, this, &MainWindow::onTaskEditClicked);
    connect(m_taskListWidget, &TaskListWidget::deleteTaskRequest, this, &MainWindow::onTaskDeleteClicked);
    connect(m_todayListWidget, &TaskListWidget::taskStatusChanged, this , &MainWindow::onTaskStatusChanged);
    connect(m_todayListWidget, &TaskListWidget::editTaskRequest, this, &MainWindow::onTaskEditClicked);
    connect(m_todayListWidget, &TaskListWidget::deleteTaskRequest, this, &MainWindow::onTaskDeleteClicked);
    connect(m_categoryListWidget, &TaskListWidget::taskStatusChanged, this, &MainWindow::onTaskStatusChanged);
    connect(m_categoryListWidget, &TaskListWidget::editTaskRequest, this, &MainWindow::onTaskEditClicked);
    connect(m_categoryListWidget, &TaskListWidget::deleteTaskRequest, this, &MainWindow::onTaskDeleteClicked);
//  connect(m_taskListWidget, &TaskListWidget::taskClicked, this, &MainWindow::onTaskClicked);

    ui->comboBox->addItem("Ưu tiên");
    ui->comboBox->addItem("Deadline");

    isListView = true;

    buildTrie();
    
    ui->stackedWidget->setCurrentWidget(ui->listPage);
    ui->calendarWidget->setSelectedDate(QDate::currentDate()); // set mac dinh
    onCalendarDateClicked(QDate::currentDate());
    updateCategoryView();
    
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
            updateCategoryView();
            updateStatistics();
            buildTrie(); 
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
    if (!ui->taskListcontainer) {
        QMessageBox::critical(this, "Lỗi", "taskListcontainer không được khởi tạo!");
        return;
    }

    // Thiết lập giao diện
    
    QString prefix = ui->searchBar->text().trimmed().toLower();
    std::vector<QString> matchedTitles;

    if (!prefix.isEmpty()){
        matchedTitles = taskTrie.Suggest(prefix);
    }
    // Lấy danh sách task
    QString sortMode = ui->comboBox ? ui->comboBox->currentText() : "Ưu tiên";
    QString filterMode = (showCompleteTasks == false) ? "Incomplete" : "Completed";
    if (showAllTask == true) filterMode = "All";
    loadTaskListWidget(prefix, sortMode, filterMode);
    loadTodayTaskListWidget();


}

void MainWindow::loadTaskListWidget( const QString& prefix, const QString& sortMode, const QString& filterMode){
    m_taskListWidget->clearAllTasks();
    std::vector<Task*> tasks;

    if (sortMode == "Ưu tiên"){
        tasks = manager.ShowTaskByPriority();
    }
    else{
        tasks = manager.ShowTaskByDeadline();
    }

    std::vector<QString> matchedTitles;
    if (!prefix.isEmpty()){
        matchedTitles = taskTrie.Suggest(prefix);
    }

    for (Task* task : tasks){
        QString title = QString::fromStdString(task->getTitle());
        bool showTask = false;

        if (!prefix.isEmpty() && std::find(matchedTitles.begin(), matchedTitles.end(), title) == matchedTitles.end()){
            continue;
        }
        if (filterMode == "Incomplete" && (!task->isCompleted())){
            showTask = true;
        }
        else if (filterMode == "Completed" && task->isCompleted()){
            showTask = true;
        }
        else if (filterMode == "All" || filterMode.isEmpty()){
            showTask = true;
        }

        if (showTask){
        //     TaskItemWidget *item = new TaskItemWidget(task, m_taskListWidget);

        // QString category = QString::fromStdString(task->getCategory());
        // if (m_categoryColors.contains(category)) {
        //     item->setCategoryColor(m_categoryColors[category]);
        // } else {
        //     // Thiết lập màu mặc định nếu không tìm thấy
        //     item->setCategoryColor(QColor("#AAAAAA")); 
        // }
            m_taskListWidget->addTask(task);
            
        }
    }
}


void MainWindow::loadTodayTaskListWidget(){
    if (!m_todayListWidget){
        return;
    }
    int taskCount = 0;
    m_todayListWidget->clearAllTasks();
    QDate today = QDate::currentDate();
    for (Task* task : manager.ShowTaskByPriority()){
        QString deadlineStr = QString::fromStdString(task->getDeadline());
        QDate taskDate = QDateTime::fromString(deadlineStr.left(10), "yyyy-MM-dd").date();

        if (taskDate == today){
            m_todayListWidget->addTask(task);
            taskCount++;
        }
    }
    if (taskCount == 0){
        //noTaskLabel->setText("Không có task cho ngày hôm nay!");
        m_todayListWidget->hide();
        ui->noTaskLabel->show();
    }
    else{
        m_todayListWidget->show();
        ui->noTaskLabel->hide();
    }
}

void MainWindow::onCompletedClicked(){
    showCompleteTasks = !showCompleteTasks;
    showAllTask = false;
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

void MainWindow::onAllTaskClicked(){
    showAllTask = true;
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
        ui->stackedWidget->setCurrentWidget(ui->calendarPage);
    }
    else if (clickedButton->objectName() == "taskList"){
        ui->stackedWidget->setCurrentWidget(ui->listPage);
    }
    else if (clickedButton->objectName() == "categorybtn"){
        ui->stackedWidget->setCurrentWidget(ui->categoryPage);
    }
    else if (clickedButton->objectName() == "statisticsbtn"){
        ui->stackedWidget->setCurrentWidget(ui->statisticsPage);
    }
    else if (clickedButton->objectName() == "todayTask"){
        ui->stackedWidget->setCurrentWidget(ui->todayPage);
    }
    highlightActiveButton(clickedButton); // doi nen nut dang chon
}

void MainWindow::highlightActiveButton(QPushButton* clickedButton){
    QList<QPushButton*> menuButtons = {  // danh sach cac nut menu
        ui->taskList, ui->calendarList, ui->categorybtn, ui->statisticsbtn, ui->todayTask
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




void MainWindow::updateCategoryView() {
    ui->categoryListWidget->clear();
    m_categoryWidgets.clear();
    loadCategoryListWidget(m_currentCategory);
    std::map<std::string, std::vector<Task*>> categoryMap;
    for (Task* t : manager.ShowTaskByPriority()) {
        std::string cat = t->getCategory();
        if (cat.empty()) cat = "Không phân loại";
        categoryMap[cat].push_back(t);
    }

    for (const auto& [catName, tasks] : categoryMap) {
        QString name = QString::fromStdString(catName);

        CategoryItemWidget* widget = new CategoryItemWidget(name, tasks.size());
        QListWidgetItem* item = new QListWidgetItem(ui->categoryListWidget);
        item->setSizeHint(QSize(0, 90));
        ui->categoryListWidget->setItemWidget(item, widget);
        m_categoryWidgets[name] = item;

        connect(widget, &CategoryItemWidget::clicked, [this, name]() {
            ui->stackedWidget->setCurrentWidget(ui->categoryListPage);
            loadCategoryListWidget(name);
        });
        connect(widget, &CategoryItemWidget::editRequested, [this, name]() { editCategory(name); });
        connect(widget, &CategoryItemWidget::deleteRequested, [this, name]() { deleteCategory(name); });
    }

    QWidget* addWidget = new QWidget();
    addWidget->setObjectName("addCategoryWidget");
    QHBoxLayout* addLayout = new QHBoxLayout(addWidget);
    addLayout->setContentsMargins(12, 16, 12, 16);
    QLabel* plus = new QLabel("+ Thêm danh mục mới");
    plus->setStyleSheet("color: #3498db; font-weight: bold; font-size: 14px;");
    addLayout->addWidget(plus);
    QListWidgetItem* addItem = new QListWidgetItem();
    addItem->setSizeHint(QSize(0, 50));
    ui->categoryListWidget->addItem(addItem);
    ui->categoryListWidget->setItemWidget(addItem, addWidget);
    addWidget->installEventFilter(this);
}



void MainWindow::setupStatistics(){
    // barchart theo chieu ngang
    m_barChart = new QChart();
    m_barSeries = new QHorizontalBarSeries();

    QBarSet* dataSet = new QBarSet("Số lượng");
    *dataSet << 0 << 0 << 0;
    dataSet->setBrush(QColor(46, 204, 113));

    m_barSeries->append(dataSet);

    m_barChart->addSeries(m_barSeries);
    m_barChart->setTitle("THỐNG KÊ ĐỘ ƯU TIÊN");
    m_barChart->legend()->setVisible(false); // truc y co nhan roi nen khong can mo ta


    QValueAxis* axisX = new QValueAxis();
    axisX->setRange(0, 35);
    axisX->setLabelFormat("%i"); //so nguyen
    m_barChart->addAxis(axisX, Qt::AlignBottom); // nam duoi barChart
    m_barSeries->attachAxis(axisX); // Gắn Series vào trục Y

    QBarCategoryAxis *axisY = new QBarCategoryAxis();
    axisY->append({"Thấp", "Trung Bình", "Cao"});
    m_barChart->addAxis(axisY, Qt::AlignLeft);
    m_barSeries->attachAxis(axisY);// gắn series vào trục X

    m_barView = new QChartView(m_barChart); // tao khung hien thi
    m_barView->setRenderHint(QPainter::Antialiasing); //chống răng của
    if (!ui->statisticsLayout_1->layout()) {
        QMessageBox::warning(this, "Error", "Không có Layout~");
        ui->statisticsLayout_1->setLayout(new QHBoxLayout());
    }
    ui->statisticsLayout_1->layout()->addWidget(m_barView);



    // Pie Chart
    m_pieChart = new QChart();
    m_pieSeries = new QPieSeries();
    m_pieSeries->append("Hoàn thành", 0);
    m_pieSeries->append("Quá hạn", 0);
    m_pieSeries->append("Chưa hoàn thành", 0);

    m_pieChart->addSeries(m_pieSeries);
    m_pieChart->setTitle("Tỷ lệ (%)");

    m_pieView = new QChartView(m_pieChart);
    m_pieView->setRenderHint(QPainter::Antialiasing);
    m_pieView->setVisible(true);
    m_pieChart->legend()->setVisible(false);
    ui->statisticsLayout_2->layout()->addWidget(m_pieView);



}


void MainWindow::updateStatistics(){
    std::vector<Task*> allTasks = manager.ShowTaskByPriority();
    int total = allTasks.size();

    if (total == 0){
        QMessageBox::warning(this, "Error", "Không tìm tháy task để thống kê");
        return;
    }
    ui->numberAllTask->setText(QString::number(total));
    int p_low = 0, p_medium = 0, p_high = 0;
    int completed = 0, overdue = 0, incomplete = 0;
    for (Task* t : allTasks){
        if (t->isCompleted()) completed++;
        else if (t->isOverdue()) overdue++;
        else{
            incomplete++;
        }
        int m_priority = t->getPriority();
        if (m_priority == 1){
            p_low++;
        }
        else if (m_priority == 2){
            p_medium++;
        }
        else{
            p_high++;
        }
    }
    ui->numberCompletedTask->setText(QString::number(completed));
    ui->numberPendingTask->setText(QString::number(total-completed));
    ui->numberProgress->setText(QString::number(100.0*completed / total) + "%");

    m_barSeries->barSets().at(0)->replace(0, p_low);
    m_barSeries->barSets().at(0)->replace(1, p_medium);
    m_barSeries->barSets().at(0)->replace(2, p_high);
    

    m_barChart->update();
    m_barView->repaint();


    double completedRate = (double)completed / total * 100;
    double overRate = (double)overdue / total * 100;
    double incompleteRate = (double)incomplete / total * 100;

    m_pieSeries->clear();

    QPieSlice *completedSlice = m_pieSeries->append("Hoàn thành", completedRate);
    completedSlice->setBrush(Qt::green);
    completedSlice->setLabelVisible(true);
    completedSlice->setLabel(QString("Hoàn thành:%1%").arg(completedRate, 0 , 'f', 1));

    QPieSlice *overdueSlice = m_pieSeries->append("Quá hạn", overRate);
    overdueSlice->setBrush(Qt::red);
    overdueSlice->setLabelVisible(true);
    overdueSlice->setLabel(QString("Quá hạn:%1%").arg(overRate, 0 , 'f', 1));


    QPieSlice *incompleteSlice = m_pieSeries->append("Chưa hoàn thành", incompleteRate);
    incompleteSlice->setBrush(Qt::blue);
    incompleteSlice->setLabelVisible(true);
    incompleteSlice->setLabel(QString("Chưa hoàn thành:%1%").arg(incompleteRate, 0, 'f', 1));


    m_pieChart->update();
    m_pieView->repaint();
    

}




void MainWindow::onTaskStatusChanged(Task* task, bool completed)
{
    if (!task) {
        QMessageBox::warning(this, "Error", "Task null");
        return;
    }
    
    // Cập nhật task trong manager
    task->setCompleted(completed);
    
    // Lưu file
    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
    m_taskListWidget->updateTask(task);
    //updateTaskList();
}

void MainWindow::onTaskEditClicked(Task* task){
    AdvancedTaskDialog dialog(task, manager, this);
    if (dialog.exec() == QDialog::Accepted) {
        SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
        updateTaskList();
        //m_taskListWidget->updateTask(task);
        buildTrie(); 
    }
}

// void MainWindow::onTaskClicked(Task* task)
// {
//     if (!task) {
//         qDebug() << "Error: Task is null in onTaskClicked";
//         return;
//     }
    
//     qDebug() << "TaskListWidget: Task clicked -" 
//              << QString::fromStdString(task->getTitle());
    
//     //Mở dialog edit task
//     //editTaskForTaskListWidget(task);
// }

//---------------------------------------------------------------

void MainWindow::backCategory(){
    ui->stackedWidget->setCurrentWidget(ui->categoryPage);
    updateCategoryView();
}

bool MainWindow::eventFilter(QObject* obj, QEvent* event) {
    if (obj->objectName() == "addCategoryWidget" && event->type() == QEvent::MouseButtonPress) {
        addNewCategory();
        return true;
    }
    return QMainWindow::eventFilter(obj, event);
}



void MainWindow::addNewCategory() {
    bool ok;
    QString name = QInputDialog::getText(this, "Tạo danh mục", "Tên danh mục:", QLineEdit::Normal, "", &ok);
    if (!ok || name.isEmpty()) return;

    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");  // Đồng bộ task
    updateCategoryView();
    updateTaskList(); 
}

void MainWindow::editCategory(const QString& oldName) {
    bool ok;
    QString newName = QInputDialog::getText(this, "Sửa danh mục", "Tên mới:", QLineEdit::Normal, oldName, &ok);
    if (!ok || newName.isEmpty() || newName == oldName) return;

   

    // Cập nhật task
    for (Task* t : manager.ShowTaskByPriority()) {
        if (QString::fromStdString(t->getCategory()) == oldName) {
            t->setCategory(newName.toStdString());
        }
    }


    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
    updateCategoryView();
    updateTaskList();
}

void MainWindow::deleteCategory(const QString& name) {
    if (QMessageBox::question(this, "Xác nhận", 
        QString("Xóa danh mục \"%1\"?\nTask sẽ chuyển về \"Không phân loại\".").arg(name)) != QMessageBox::Yes)
        return;

    for (Task* t : manager.ShowTaskByPriority()) {
        if (QString::fromStdString(t->getCategory()) == name) {
            t->setCategory("Không phân loại");
        }
    }

    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
    updateCategoryView();
    updateTaskList();
}

void MainWindow::loadCategoryListWidget(const QString& category){
    m_categoryListWidget->clearAllTasks();
    m_currentCategory = category;
    std::vector<Task*> tasks = manager.ShowTaskByPriority();
    for (Task* task : tasks){
        if (QString::fromStdString(task->getCategory()) == category) m_categoryListWidget->addTask(task);
    }
}

void MainWindow::onTaskDeleteClicked(Task* task){
    if (!task) QMessageBox::warning(this, "Error", "Không có task để xóa !");

    if (QMessageBox::question(this,"Xác nhận", QString("Xóa task")) != QMessageBox::Yes) return;
    manager.removeTask(task->getID());
    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt");
    updateTaskList();
    updateCategoryView();
    updateStatistics();
}