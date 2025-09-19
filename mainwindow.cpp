#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
#include <QInputDialog>
#include <QListWidgetItem>
#include <QFont>
#include <fstream>
#include <sstream>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("To Do List");
    // QWidget *central = new QWidget(this);
    // QVBoxLayout *layout = new QVBoxLayout(central);

    // taskList = new QListWidget(this);
    // addButton = new QPushButton("➕ Add Task", this);

    // layout->addWidget(taskList);
    // layout->addWidget(addButton);

    // setCentralWidget(central);

    LoadFile("D:\\PBL\\PBL2\\PBL2\\Data\\test.txt", manager);

    ui->comboBox->addItem("Ưu tiên");
    ui->comboBox->addItem("Deadline");
    ui->comboBox->setCurrentIndex(0); // mặc định "Ưu tiên"
    // Khi nhấn nút "Add Task"
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
    // Khi đổi trạng thái hiển thị
    connect(ui->comboBox, &QComboBox::currentIndexChanged, this, &MainWindow::updateTaskList);
    //Show mặc định khi mở app
    updateTaskList();

    //Khi thay đổi trạng thái checkbox
    connect(ui->taskList, &QListWidget::itemChanged, this, [=](QListWidgetItem *item){
        if(item->checkState() == Qt::Checked){
            item->setForeground(Qt::gray); // đổi màu
            QFont font = item->font();
            font.setStrikeOut(true);       // gạch ngang
            item->setFont(font);
        } else {
            item->setForeground(Qt::black);
            QFont font = item->font();
            font.setStrikeOut(false);
            item->setFont(font);
        }
    });



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

    QString taskInfo = QString ("%1 | Priority : %2 | Deadline : %3").arg(title).arg(priority).arg(deadline);
    QListWidgetItem *item = new QListWidgetItem(taskInfo);
    // Đặt check box để tick khi hoàn thành
    item->setFlags(item->flags() | Qt::ItemIsUserCheckable); 
    item->setCheckState(Qt::Unchecked); // mặc định chưa làm
    ui->taskList->addItem(item);
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


void MainWindow::updateTaskList(){
    ui->taskList->clear();
    QString mode = ui->comboBox->currentText();
    std::vector<Task*> tasks;
    if (mode == "Ưu tiên"){
        tasks = manager.ShowTaskByPriority();
    }
    else if (mode == "Deadline"){
        tasks = manager.ShowTaskByDeadline();
    }
    for (Task* t : tasks){
        QString itemtext = QString::fromStdString(t->getTitle() + " | " + t->getDeadline());
        QListWidgetItem *item = new QListWidgetItem(itemtext);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(t->isCompleted() ? Qt::Checked : Qt::Unchecked);
        ui->taskList->addItem(item);
    }
}


