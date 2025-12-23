#pragma once
#include <QWidget>
#include <QHBoxLayout>
#include <QScrollArea>
#include "TaskItemQwidget.h"
#include "Task.h"
#include <QMap>
#include <QList>
class TaskListWidget : public QWidget{
    Q_OBJECT
public:
    explicit TaskListWidget(QWidget *parent = nullptr);

    void addTask(Task* task);
    void removeTask(Task* task);
    void clearAllTasks();
    void updateTask(Task* task);

signals:
// khi nhan checkbox
    void taskStatusChanged(Task* task, bool completed); 
    void taskClicked(Task* task);
    void editTaskRequest(Task* task);
    void deleteTaskRequest(Task* task);
private slots:
    void onTaskItemStatusChanged(Task* task, bool completed);
    void onTaskEditClicked (Task* task);
    void onTaskDeleteClicked(Task* task);

private:
    void setupUI();
    QVBoxLayout *m_mainLayout = nullptr;
    QWidget *m_listContainer = nullptr;
     // lưu key và giao diện là TaskListWidget
    QMap<Task*, TaskItemWidget*> m_taskWidgets;

    bool m_showCompleted = true;
};

