// #pragma once
// #include <QWidget>
// #include <QLabel>
// #include "Task.h"
// #include <QCheckBox>

// class TaskItemWidget : public QWidget
// {
//     Q_OBJECT

// public:
//     explicit TaskItemWidget(Task* task, QWidget *parent = nullptr);

//     void updateTaskData(Task* task);
//     Task* getTask() const {return m_task; }

// signals:  // gửi tín hiệu khi bấm
//     void taskStatusChanged(Task* task, bool completed); // tín hiệu khi thay đổi trạng thái 
//     void taskClicked(Task* task); // tín hiệu khi bấm vào widget

// private slots:
//     void onCheckboxStateChanged(int state); // hàm gọi khi checkbox thay đổi trạng thái

// private:
//     void setupUI();
//     void applyCompletedStyle(bool completed); // đổi giao diện, đổi màu chữ :))

//     Task* m_task;
//     QCheckBox* m_checkbox;
//     QLabel* m_titleLabel;
//     QLabel* m_descriptionLabel;
//     QLabel* m_priorityLabel;
//     QLabel* m_timeLabel;
// };