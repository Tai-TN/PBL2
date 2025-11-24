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
    void taskStatusChanged(Task* task, bool completed); // khi nhan checkbox
    void taskClicked(Task* task);
    void editTaskRequest(Task* task);
    void deleteTaskRequest(Task* task);
private slots:
    void onTaskItemStatusChanged(Task* task, bool completed);
    //void onTaskItemClicked(Task* task);
    void onTaskEditClicked (Task* task);
    void onTaskDeleteClicked(Task* task);

private:
    void setupUI();
    QVBoxLayout *m_mainLayout = nullptr;
    QWidget *m_listContainer = nullptr;
    QMap<Task*, TaskItemWidget*> m_taskWidgets; // lưu key và giao diện là TaskListWidget

    bool m_showCompleted = true;
};

