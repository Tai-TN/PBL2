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
#include <string>
#include <algorithm>
#include <map>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QString iconPath = "../blueIcons/resources/icons/iconWindow.png";
    QIcon windowIcon(iconPath);
    this->setWindowIcon(windowIcon);
    this->setWindowTitle("To Do List");
    LoadFile("D:\\PBL\\PBL2\\PBL2\\Data\\tasks.txt", manager);
    loadCategories("D:\\PBL\\PBL2\\PBL2\\Data\\categories.txt");
    ui->comboFilterTime->addItems({"Hôm nay", "Tuần này", "Tháng này", "Tùy chọn"});
    ui->dateFrom->setVisible(false);
    ui->dateTo->setVisible(false);
    leftMenuVisible = true;
    originalMenuWidth = ui->leftMenu->width(); // luu width goc
    setupStatistics();
    


    connect(ui->menuBtn, &QPushButton::clicked, this, &MainWindow::toggleLeftMenu);
    connect(ui->taskList, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->calendarList, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->categorybtn, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->statisticsbtn, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    connect(ui->todayTask, &QPushButton::clicked, this, &MainWindow::onMenuButtonClicked);
    
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::updateTaskList);
    connect(ui->taskCompleted, &QPushButton::clicked, this, &MainWindow::onCompletedClicked);
    connect(ui->allTask, &QPushButton::clicked, this,&MainWindow::onAllTaskClicked);

    connect(ui->searchBar, &QLineEdit::textChanged, this, &MainWindow::updateTaskList);
    connect(ui->calendarWidget, &QCalendarWidget::clicked, this, &MainWindow::onCalendarDateClicked);

    //category 
    connect(ui->addCategorybtn, &QPushButton::clicked, this, &MainWindow::addNewCategory);
    connect(ui->backCatetorybtn, &QPushButton::clicked, this, &MainWindow::backCategory);  
    connect(ui->filterListPagebtn, &QPushButton::clicked, this, &MainWindow::onFilterListPageClicked);

    //TaskListWidget
    m_taskListWidget = new TaskListWidget(ui->taskListcontainer);
    m_todayListWidget = new TaskListWidget(ui->todayTaskList);

    m_categoryListWidget = new TaskListWidget(ui->categoryListcontainer);
    QVBoxLayout* catLayout = new QVBoxLayout(ui->categoryListcontainer);
    catLayout->addWidget(m_categoryListWidget);
    catLayout->setContentsMargins(0, 0, 0, 0);
    catLayout->setSpacing(0);

    QVBoxLayout* layout = new QVBoxLayout(ui->taskListcontainer);
    layout->addWidget(m_taskListWidget);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

    QVBoxLayout* todayLayout = new QVBoxLayout(ui->todayTaskList);
    todayLayout->addWidget(m_todayListWidget);
    todayLayout->setContentsMargins(0, 0, 0, 0);
    todayLayout->setSpacing(0);
    


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

    connect(ui->comboFilterTime, &QComboBox::currentIndexChanged, this, &MainWindow::onTimeFilterChanged);
    ui->comboFilterTime->setCurrentIndex(1);
    connect(ui->dateFrom, &QDateEdit::dateChanged, this, &MainWindow::updateStatistics);
    connect(ui->dateTo, &QDateEdit::dateChanged, this, &MainWindow::updateStatistics);

    ui->comboBox->addItem("Ưu tiên");
    ui->comboBox->addItem("Deadline");
    isListView = true;
    buildTrie();

    
    ui->stackedWidget->setCurrentWidget(ui->listPage);
    ui->calendarWidget->setSelectedDate(QDate::currentDate()); // set mac dinh
    onCalendarDateClicked(QDate::currentDate());
    updateCategoryView();
    updateStatistics();


    // chuc nang thong bao
    m_notificationWidget = new NotificationWidget(this);
    m_notificationMenu = new QMenu(this);
    QWidgetAction* widgetAction = new QWidgetAction(this);
    widgetAction->setDefaultWidget(m_notificationWidget);
    m_notificationMenu->addAction(widgetAction);

    m_countNotificationLabel = new QLabel(ui->notifi_btn);
    m_countNotificationLabel->setStyleSheet("background : red; color : white; border-radius : 5px;");
    m_countNotificationLabel->setGeometry(25, 5, 20, 20);
    m_countNotificationLabel->setVisible(false);

    connect(ui->notifi_btn, &QPushButton::clicked, this, &MainWindow::showNotificationMenu);
}




    
     
MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::addTask()
{   
    AdvancedTaskDialog dialog(manager,m_categories, this);
    if (dialog.exec() == QDialog::Accepted) {
        Task* newTask = dialog.getCreatedTask();
        if (newTask) {
            manager.addTask(newTask);
            SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\tasks.txt");
            saveCategories("D:\\PBL\\PBL2\\PBL2\\Data\\categories.txt");
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
        Vector<std::string> fields;
        std::string field;

        while(getline(ss, field, '|')){
            fields.push_back(field);
        }

        
        
        if (fields.size() >= 10){
            size_t id = std::stoul(fields[0]);
            std::string title = fields[1];
            std::string description = fields[2];
            int priority = std::stoi(fields[3]);
            std::string deadline = fields[4];
            bool completed = (fields[5] == "1");
            std::string createdAt = fields[6];
            std::string updatedAt = fields[7];
            std::string category = fields[8];
            std::string recurrence = fields[9];
            Task* t = new Task(title,description, priority, deadline, category,recurrence, completed);
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
    Vector<Task*> tasks = manager.ShowTaskByPriority();

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
          << t->getRecurrence();
        
        
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
    Vector<QString> matchedTitles;

    if (!prefix.isEmpty()){
        matchedTitles = taskTrie.Suggest(prefix);
    }
    // Lấy danh sách task
    QString sortMode = ui->comboBox ? ui->comboBox->currentText() : "Ưu tiên";
    QString filterMode = (showCompleteTasks == false) ? "Incomplete" : "Completed";
    if (showAllTask == true) filterMode = "All";
    loadTaskListWidget(prefix, sortMode, filterMode);
    loadTodayTaskListWidget();
    updateCalendarDots();

}

void MainWindow::loadTaskListWidget( const QString& prefix, const QString& sortMode, const QString& filterMode){
    m_taskListWidget->clearAllTasks();
    Vector<Task*> tasks;

    if (sortMode == "Ưu tiên"){
        tasks = manager.ShowTaskByPriority();
    }
    else{
        tasks = manager.ShowTaskByDeadline();
    }

    Vector<QString> matchedTitles;
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
        ui->noTaskLabel->setText("📅 Không có task cho ngày hôm nay!");
        ui->stackedWidget_2->setCurrentWidget(ui->noLabelPage);
    }
    else{
        ui->stackedWidget_2->setCurrentWidget(ui->todayTaskList);
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
    Vector<Task*> tasks = manager.ShowTaskByPriority();
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

    Vector<Task*> tasks = manager.ShowTaskByDeadline();
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

    refreshDashboardStats(date);

}


void MainWindow::toggleLeftMenu(){
    leftMenuVisible = !leftMenuVisible;
    QIcon align_sign(":/blueIcons/resources/icons/align-justify2.svg");
    QIcon back_sign(":/blueIcons/resources/icons/arrow-left.svg");
    
    
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
    std::map<std::string, Vector<Task*>> categoryMap;
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
    m_barChart->setAnimationOptions(QChart::SeriesAnimations);

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
    m_barView->setMinimumHeight(300);
    ui->statisticsLayout_1->layout()->addWidget(m_barView);


    //stacked Chart;
    
    m_stackedSeries = new QStackedBarSeries();
    m_stackedChart = new QChart();
    m_stackedView = new QChartView(m_stackedChart);
    m_stackedView->setMinimumHeight(300);
    m_stackedChart->setTitle("TIẾN ĐỘ TRONG TUẦN");
    m_stackedChart->legend()->setVisible(true);
    m_stackedChart->legend()->setAlignment(Qt::AlignTop);
    m_stackedChart->legend()->setMarkerShape(QLegend::MarkerShapeRectangle);
    m_stackedChart->setTitleBrush(QBrush(Qt::green)); // Mau chu tieu de
    m_stackedChart->setAnimationOptions(QChart::SeriesAnimations);
    m_stackedView->setRenderHint(QPainter::Antialiasing); // Khử răng cưa

    ui->statisticsLayout3->addWidget(m_stackedView, 2);
    m_setCompleted = new QBarSet("Hoàn thành");
    m_setIncompleted = new QBarSet("Chưa hoàn thành");
    m_setCompleted->setColor(QColor("#27ae60"));
    m_setIncompleted->setColor(QColor("#d5f5e3"));

    QStackedBarSeries* series = new QStackedBarSeries();
    series->setBarWidth(0.8);
    series->append(m_setCompleted); // chua hoan thanh nam tren, hoan thanh nam duoi
    series->append(m_setIncompleted);
    m_stackedChart->addSeries(series);

    QStringList categories;
    categories << "Th 2" << "Th 3" << "Th 4" << "Th 5" << "Th6" << "Th7" << "CN";
    axisXStacked = new QBarCategoryAxis();
    axisXStacked->append(categories);
    axisXStacked->setGridLineVisible(false);    
    m_stackedChart->addAxis(axisXStacked, Qt::AlignBottom);
    series->attachAxis(axisXStacked); // Gắn trục X này với series, nếu ko có sẽ không thể hiển thị đúng
    
    axisYStacked = new QValueAxis();
    axisYStacked->setRange(0, 5);
    axisYStacked->setLabelFormat("%d");// chi hien so nguyen
    m_stackedChart->addAxis(axisYStacked, Qt::AlignLeft);
    series->attachAxis(axisYStacked);


    //donut Chart
    QWidget* donutContainer = new QWidget();
    donutContainer->setMinimumSize(200, 200);
    QStackedLayout* stackLayout = new QStackedLayout(donutContainer);


    m_percentLabel = new QLabel("0%");
    m_percentLabel->setAlignment(Qt::AlignCenter);
    m_percentLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    m_percentLabel->setStyleSheet("font-size: 32px; font-weight: bold; color: #27ae60; background: transparent;");

    stackLayout->setStackingMode(QStackedLayout::StackAll);// hien de len nhau
    QVBoxLayout *rightLayout = new QVBoxLayout();
    rightLayout->addWidget(donutContainer);
    
    summaryLabel = new QLabel("0/0 Việc đã hoàn thành");
    summaryLabel->setAlignment(Qt::AlignCenter);
    summaryLabel->setStyleSheet("color: #27ae60;border:none; font-weight: bold; font-size: 32px;");
    rightLayout->addWidget(summaryLabel);
    ui->statisticsLayout3->addLayout(rightLayout, 1);

    //ui->statisticsLayout_3->setStyleSheet("background-color: white, border-radius: 10px;");
    m_donutSeries = new QPieSeries();
    m_donutSeries->setHoleSize(0.5); // lo rong o giua

    QChart* m_donutChart = new QChart();
    m_donutChart->addSeries(m_donutSeries);
    m_donutChart->legend()->hide();
    m_donutChart->setAnimationOptions(QChart::AllAnimations);
    m_donutChart->setBackgroundRoundness(0);
    m_donutChart->setMargins(QMargins(0, 0, 0, 0));  // bo le thua
    m_donutChart->setBackgroundBrush(QBrush(Qt::transparent));

    QChartView* donutChartView = new QChartView(m_donutChart);
    donutChartView->setStyleSheet("background:transparent;");
    donutChartView->setRenderHint(QPainter::Antialiasing);
    stackLayout->addWidget(donutChartView);
    stackLayout->addWidget(m_percentLabel);
    stackLayout->setCurrentIndex(1);
   

}


void MainWindow::updateStatistics(){
    Vector<Task*> allTasks = manager.ShowTaskByPriority();
    Vector<Task*> filteredTasks;
    map<std::string,std::pair<int, int>> categoryStats; // ten category, hoan thanh , khong hoan thanh
    QDate start = getFilterStartDate();
    QDate end = getFilterEndDate();

    for (Task* t : allTasks){
        QDate taskDate = QDateTime::fromString(QString::fromStdString(t->getDeadline()), "yyyy-MM-dd HH:mm").date();
    
        if (taskDate >= start && taskDate <= end){
            filteredTasks.push_back(t);
        
        }
}

    //donut chart category
    for (Task* task : filteredTasks){
        std::string category = task->getCategory();
        if (task->isCompleted()){
            categoryStats[category].first++;
        }
        else{
            categoryStats[category].second++;
        }
    }
    // xoa donut cu
    QLayoutItem *item;
    while((item = ui->m_categoryDonutLayout->takeAt(0)) != nullptr){
        if (item->widget()){
            item->widget()->deleteLater();
        }
        delete item;
    }
    m_categoryDonuts.clear();
    // Không có dữ liệu
    if (categoryStats.empty()){
        QLabel* noDataLabel = new QLabel("Không có dữ liệu");
        noDataLabel->setAlignment(Qt::AlignCenter);
        noDataLabel->setStyleSheet("font-size: 16px; color: gray;");
        ui->m_categoryDonutLayout->addWidget(noDataLabel, 0, 0);
        return;
    }
    int row = 0;
    int col = 0;
    const int COLUMNS = 2;

    for (auto& [categoryStr, stats] : categoryStats){
        QString category = QString::fromStdString(categoryStr);
        int completed = stats.first;
        int incomplete = stats.second;
        int total = completed + incomplete;

        QWidget* categoryWidget = new QWidget();
                categoryWidget->setMinimumWidth(280);
        categoryWidget->setMaximumWidth(350);
        categoryWidget->setMinimumHeight(320);
        categoryWidget->setMaximumHeight(380);
        categoryWidget->setStyleSheet(
            "QWidget {"
            "    background-color: white;"
            "    border: 1px solid #ecf0f1;"
            "    border-radius: 10px;"
            "    padding: 10px;"
            "}"
        );



        QVBoxLayout* categoryLayout = new QVBoxLayout(categoryWidget);
        categoryLayout->setSpacing(10);
        categoryLayout->setContentsMargins(10, 10, 10, 10);


        // Label tên category
        QLabel* categoryLabel = new QLabel(category);
        categoryLabel->setAlignment(Qt::AlignCenter);
        categoryLabel->setStyleSheet(
            "font-size: 14px; "
            "font-weight: bold; "
            "color: #2c3e50; "
            "padding: 5px;"
        );
        categoryLayout->addWidget(categoryLabel);

        //Donut chart
        QWidget* donutContainer = new QWidget();
        QStackedLayout* stackedLayout = new QStackedLayout(donutContainer);

        QLabel* percentLabel = new QLabel("0%");
        percentLabel->setAlignment(Qt::AlignCenter);
        percentLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
        percentLabel->setStyleSheet("font-size: 36px; font-weight: bold; color: #27ae60; background: transparent;");

        stackedLayout->setStackingMode(QStackedLayout::StackAll);
        stackedLayout->setAlignment(Qt::AlignCenter);


        QChart* donutChart = new QChart();
        QPieSeries* pieSeries = new QPieSeries();



        double completedPercent = 0;
        double incompletePercent = 0;
        int percent_category = 0;
        if (total > 0){
            completedPercent = 100.0*completed / total;
            incompletePercent = 100.0*incomplete / total;
            percent_category = 100.0*completed / total;
        }

        percentLabel->setText(QString::number(percent_category) + "%");
        QPieSlice* completedSlice = pieSeries->append("Hoàn thành", completedPercent);
        completedSlice->setColor(QColor("#27ae60"));
        
        // Slice chưa hoàn thành
        QPieSlice* incompleteSlice = pieSeries->append("Chưa hoàn thành", incompletePercent);
        incompleteSlice->setColor(QColor("#d5f5e3"));

        pieSeries->setHoleSize(0.5); //Lo rong donut
        
        donutChart->addSeries(pieSeries);
        donutChart->legend()->setVisible(false);
        donutChart->setAnimationOptions(QChart::SeriesAnimations);
        donutChart->setBackgroundBrush(QBrush(Qt::transparent));
        donutChart->setMargins(QMargins(0, 0, 0, 0));
        donutChart->setTitleBrush(QBrush(Qt::green));
        
        // Chart View
        QChartView* chartView = new QChartView(donutChart);
        chartView->setRenderHint(QPainter::Antialiasing);
        chartView->setStyleSheet("background: transparent; border: none;");
        chartView->setMinimumHeight(200);
        stackedLayout->addWidget(chartView);
        stackedLayout->addWidget(percentLabel);
        stackedLayout->setCurrentIndex(1);
        categoryLayout->addWidget(donutContainer, 1);

        
        // Label hiển thị số lượng
        QString summaryText = QString("%1/%2 hoàn thành").arg(completed).arg(total);
        QLabel* summaryLabel = new QLabel(summaryText);
        summaryLabel->setAlignment(Qt::AlignCenter);
        summaryLabel->setStyleSheet(
            "font-size: 12px; "
            "color: #27ae60; "
            "font-weight: bold; "
            "padding: 5px;"
        );
        categoryLayout->addWidget(summaryLabel);
        
        // Thêm vào grid layout
        ui->m_categoryDonutLayout->addWidget(categoryWidget, row, col);
         // Cập nhật vị trí
        col++;
        if (col >= COLUMNS) {
            col = 0;
            row++;
        }
        
        // Lưu reference
        CategoryDonut donutData;
        donutData.chart = donutChart;
        donutData.chartView = chartView;
        donutData.series = pieSeries;
        donutData.categoryLabel = categoryLabel;
        m_categoryDonuts[category] = donutData;
    }




    int total = filteredTasks.size();
    ui->numberAllTask->setText(QString::number(total));
    int p_low = 0, p_medium = 0, p_high = 0;
    int completed = 0, overdue = 0, incomplete = 0;
    for (Task* t : filteredTasks){
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
    
    m_barChart->axisX()->setRange(0,5 + std::max(p_low ,std::max(p_medium, p_high)));
    m_barChart->update();
    m_barView->repaint();



//Stacked Chart , 7 ngay trong tuan
    updateWeeklyStats();


}
void MainWindow::updateWeeklyStats(){
    int currentday = QDate::currentDate().dayOfWeek(); // tra ve 1 (thu 2)... 7(chu nhat)
    QDate currentDay = QDate::currentDate();

    QDate monday = currentDay.addDays(-(currentday - 1));
    QDate sunday = monday.addDays(6);

    std::vector<int> dataCompleted(7, 0);
    std::vector<int> dataIncompleted(7, 0);
    double totalCompleted = 0;
    double totalTask = 0;
    Vector<Task*> tasks = manager.ShowTaskByDeadline();

    for (Task* t : tasks){
        QString dateStr = QString::fromStdString(t->getDeadline());
        QDateTime tDateTime = QDateTime::fromString(dateStr, "yyyy-MM-dd HH:mm");
        QDate tDate = tDateTime.date();
        
        if (tDate.isValid() && tDate >= monday && tDate <= sunday){
            int index = tDate.dayOfWeek() - 1;
            totalTask++;
            if (index >= 0 && index <= 6){
                if (t->isCompleted()){
                    dataCompleted[index]++;
                    totalCompleted++;
                }
                else{
                    dataIncompleted[index]++;
                }
            }
        }
    }
    int max = 0;
    for (int i=0;i<7;i++){
        if ((dataCompleted[i] + dataIncompleted[i]) > max){
            max = (dataCompleted[i] + dataIncompleted[i]);
        } 
    }
    axisYStacked->setRange(0, max+2);
    m_setCompleted->remove(0, m_setCompleted->count());
    m_setIncompleted->remove(0, m_setIncompleted->count());
    
    for (int i=0;i<7;i++){
        *m_setCompleted << dataCompleted[i];
        *m_setIncompleted << dataIncompleted[i];
    }

    m_donutSeries->clear();
    double percent = 0;
    if (totalTask > 0) percent = (100*totalCompleted / totalTask);
    QPieSlice* sliceDone= m_donutSeries->append("Done", totalCompleted);
    QPieSlice* sliceLeft = m_donutSeries->append("Left", totalTask - totalCompleted);

    sliceDone->setColor(QColor("#27ae60"));
    sliceLeft->setColor(QColor("#d5f5e3"));

    m_percentLabel->setText(QString::number(int(percent)) + "%");
    summaryLabel->setText(QString("%1/%2 Việc đã hoàn thành").arg(totalCompleted).arg(totalTask));

}




void MainWindow::onTaskStatusChanged(Task* task, bool completed)
{
    if (!task) {
        QMessageBox::warning(this, "Error", "Task null");
        return;
    }
    
    // Cập nhật task trong manager
    task->setCompleted(completed);
    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\tasks.txt");
    m_taskListWidget->updateTask(task);
    m_todayListWidget->updateTask(task);
    m_categoryListWidget->updateTask(task);
    if (!showAllTask && !showCompleteTasks && completed){
        QTimer::singleShot(2000, this, [this, task](){
            m_taskListWidget->removeTask(task);
            m_todayListWidget->removeTask(task);
            m_categoryListWidget->removeTask(task);
            
        });
}
    updateStatistics();

}
void MainWindow::onTaskEditClicked(Task* task){
    AdvancedTaskDialog dialog(task, manager, m_categories,this);
    if (dialog.exec() == QDialog::Accepted) {
        SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\tasks.txt");
        saveCategories("D:\\PBL\\PBL2\\PBL2\\Data\\categories.txt");

        updateTaskList();
        //m_taskListWidget->updateTask(task);
        buildTrie(); 
    }
}


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
    
    m_categories.insert(name.toStdString());

    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\tasks.txt");  // Đồng bộ task
    saveCategories("D:\\PBL\\PBL2\\PBL2\\Data\\categories.txt");

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


    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\tasks.txt");
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

    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\tasks.txt");
    updateCategoryView();
    updateTaskList();
}

void MainWindow::loadCategoryListWidget(const QString& category){
    m_categoryListWidget->clearAllTasks();
    m_currentCategory = category;
    Vector<Task*> tasks = manager.ShowTaskByPriority();
    for (Task* task : tasks){
        if (QString::fromStdString(task->getCategory()) == category) m_categoryListWidget->addTask(task);
    }
}

void MainWindow::onTaskDeleteClicked(Task* task){
    if (!task) QMessageBox::warning(this, "Error", "Không có task để xóa !");

    if (QMessageBox::question(this,"Xác nhận", QString("Xóa task")) != QMessageBox::Yes) return;
    manager.removeTask(task->getID());
    SaveToFile("D:\\PBL\\PBL2\\PBL2\\Data\\tasks.txt");
    updateTaskList();
    updateCategoryView();
    updateStatistics();
}

void MainWindow::loadCategories(const std::string& filename){
    std::ifstream f(filename);
    if (!f){
        std::ofstream newFile(filename);
        newFile.close();        
        m_categories.insert("Học tập");
        m_categories.insert("Công việc");
        m_categories.insert("Cá nhân");
        m_categories.insert("Sức khỏe");
        m_categories.insert("Giải Trí");
        m_categories.insert("Tài Chính");
        m_categories.insert("Gia Đình");
        m_categories.insert("Khác");
        m_categories.insert("Không phân loại");
        saveCategories(filename);
        return;
    }
    std::string line;
    while(getline(f,line)){
        if (!line.empty()){
            m_categories.insert(line);
        }
    }
    f.close();;

    
}

void MainWindow::saveCategories(const std::string& filename){
    std::ofstream file(filename);

    if (!file){
        QMessageBox::critical(this, "Error", "Cannot open file for saving : " + QString::fromStdString(filename));
        return;
    }
    for (const std::string& cat : m_categories){
        file << cat << "\n";
    }
    file.close();
}

QDate MainWindow::getFilterStartDate() const{
    QDate today = QDate::currentDate();
    switch(ui->comboFilterTime->currentIndex()){
        case 0: return today;
        case 1: {
            return today.addDays(-6);
        }
        case 2: return today.addDays(-30);
        case 3: return ui->dateFrom->date();
        default : return today;

    }
}

QDate MainWindow::getFilterEndDate() const{
    QDate today = QDate::currentDate();
    switch(ui->comboFilterTime->currentIndex()){
        case 0: return today;
        case 1: return today;
        case 2: return today; 
        case 3: return ui->dateTo->date();
        default : return today;
}
}

void MainWindow::onTimeFilterChanged(int index){
    bool custom = (index == 3);
    if (custom == true){
        ui->dateFrom->setVisible(custom);
        ui->dateTo->setVisible(custom);
    }
    else{
        ui->dateFrom->setVisible(false);
        ui->dateTo->setVisible(false);
    }
    updateStatistics();
}


void MainWindow::onFilterListPageClicked(){
    isFilterTaskPage = !isFilterTaskPage;
    if (isFilterTaskPage){
        QDate start = ui->dateFrom1->date();
        QDate end = ui->dateTo1->date();
        Vector<Task*> allTasks = manager.ShowTaskByPriority();
        m_taskListWidget->clearAllTasks();       
        for (Task* t : allTasks){
            QDate taskDate = QDateTime::fromString(QString::fromStdString(t->getDeadline()), "yyyy-MM-dd HH:mm").date();
        
            if (taskDate >= start && taskDate <= end){
                m_taskListWidget->addTask(t);
            }
    }
    ui->filterListPagebtn->setIcon(QIcon(":/blueIcons/resources/icons/filter.png"));
    ui->filterListPagebtn->setIconSize(QSize(24,24));
    }
    else{
        ui->filterListPagebtn->setIcon(QIcon(":/blueIcons/resources/icons/filter.svg"));
        updateTaskList();
    }
}

void MainWindow::updateCalendarDots(){
    if (!ui->calendarWidget) return;
    QTextCharFormat defaultFormat;
    //QDate() se ap dung cho tat ca cac ngay
    ui->calendarWidget->setDateTextFormat(QDate(), defaultFormat); //reset lai format thanh mac dinh

    Vector<Task*> tasks = manager.ShowTaskByDeadline();

    QTextCharFormat taskFormat;
    taskFormat.setFontWeight(QFont::Bold);

    //tranh format nhieu lan
    QSet<QDate> processedDates;
    for (Task* task : tasks){
        QString deadlineStr = QString::fromStdString(task->getDeadline());
        QDate taskDate = QDate::fromString(deadlineStr.left(10), "yyyy-MM-dd");
        if (taskDate.isValid() && !processedDates.contains(taskDate)){
            ui->calendarWidget->setDateTextFormat(taskDate, taskFormat);
            processedDates.insert(taskDate);
        }
    }



}


void MainWindow::showNotificationMenu(){
    m_notificationWidget->updateNotifications(manager);

    QPoint globalPos = ui->notifi_btn->mapToGlobal( QPoint(0 , ui->notifi_btn->height())); // Chuyển tọa độ góc dưới của nút thông báo thành tọa độ để hiển thị QMENU

    m_notificationMenu->popup(globalPos);
    updateCountLabel();

}

void MainWindow::updateCountLabel(){
    int count = m_notificationWidget->countNotifications();

    if (count > 0){
        m_countNotificationLabel->setText(QString::number(count));
        m_countNotificationLabel->setVisible(true);
    }
    else{
        m_countNotificationLabel->setVisible(false);
    }
}

void MainWindow::updateStats(int total, int completed, int highPriority, int remaining){
    ui->m_totalLabel->setNum(total);
    ui->m_completedLabel->setNum(completed);
    ui->m_highPriorityLabel->setNum(highPriority);
    ui->m_remainLabel->setNum(remaining);

    int percent = 0;
    if (total > 0){
        percent = completed*100 / total;

    }
    ui->m_percentLabel->setText(QString::number(percent) + "%");
    ui->m_progressBar->setValue(percent);
}

void MainWindow::refreshDashboardStats(QDate date) {
    Vector<Task*> tasks = getTaskbyDate(date);
    int total = tasks.size();
    int completed = 0;
    int remaining = 0;
    int high = 0;
    for(Task* t : tasks){
        if (t->getPriority() == 3) high++;

        if (t->isCompleted()){
            completed++;
        }
        else{
            remaining++;
        }
    }
    updateStats(total, completed, high, remaining);
}   


Vector<Task*> MainWindow::getTaskbyDate(QDate date){
    Vector<Task*> allTasks = manager.ShowTaskByPriority();
    Vector<Task*> filteredTasks;


    for (Task* t : allTasks){
        QDate taskDate = QDateTime::fromString(QString::fromStdString(t->getDeadline()), "yyyy-MM-dd HH:mm").date();
    
        if (date == taskDate){
            filteredTasks.push_back(t);
        }
}
    return filteredTasks;
}


