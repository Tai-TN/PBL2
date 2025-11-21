#include "TaskListWidget.h"

TaskListWidget::TaskListWidget(QWidget* parent) : QWidget(parent){
    setupUI();
}

    void TaskListWidget::setupUI(){
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->setContentsMargins(0, 0, 0, 0);
        mainLayout->setSpacing(0);

        QScrollArea *scrollArea = new QScrollArea(this);
        scrollArea->setWidgetResizable(true); // tu dong co gian 
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // an thanh cuon ngang
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded); // hien thanh cuon doc khi can

        m_listContainer = new QWidget();
        m_mainLayout = new QVBoxLayout(m_listContainer);
        m_mainLayout->setContentsMargins(5, 5, 5, 5);
        m_mainLayout->setSpacing(2);
        m_mainLayout->addStretch(); // day cac item len tren
    
        scrollArea->setWidget(m_listContainer);
        mainLayout->addWidget(scrollArea);
    }





void TaskListWidget::addTask(Task* task){
    if (!task) return;

    //tránh thêm trùng
    if (m_taskWidgets.contains(task)){
        return;
    }

    TaskItemWidget *item = new TaskItemWidget(task, m_listContainer);
    m_mainLayout->insertWidget(m_mainLayout->count()-1, item);
    m_taskWidgets[task] = item; // lưu ánh xạ
    connect(item, &TaskItemWidget::taskStatusChanged, this, &TaskListWidget::onTaskItemStatusChanged);
    connect(item, &TaskItemWidget::editTaskRequest, this, &TaskListWidget::onTaskEditClicked);
    connect(item, &TaskItemWidget::deleteTaskRequest, this, &TaskListWidget::onTaskDeleteClicked);


}
void TaskListWidget::clearAllTasks()
{
    // Xóa giao diện
    for (TaskItemWidget *widget : m_taskWidgets.values()) {
        m_mainLayout->removeWidget(widget);
        widget->deleteLater();
    }
    m_taskWidgets.clear();
    
}

void TaskListWidget::updateTask(Task* task){
    TaskItemWidget *widget = m_taskWidgets.value(task);
    if (widget){
        widget->updateTaskData(); // cap nhat giao dien
    }
}

void TaskListWidget::removeTask(Task* task){
    TaskItemWidget *widget = m_taskWidgets.value(task);
    if (widget){
        m_mainLayout->removeWidget(widget);
        widget->deleteLater();
        m_taskWidgets.remove(task);
    }
}

// Slot
void TaskListWidget::onTaskItemStatusChanged(Task* task, bool completed){
    //cap nhat giao dien
    updateTask(task);
    // chuyen tin hieu len MainWindow
    emit taskStatusChanged(task, completed);
}

void TaskListWidget::onTaskEditClicked(Task* task){
    emit editTaskRequest(task);
}

void TaskListWidget::onTaskDeleteClicked(Task* task){
    emit deleteTaskRequest(task);
}

