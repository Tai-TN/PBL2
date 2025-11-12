#pragma once
#include <QWidget>
#include <QLabel>
#include "Task.h"
#include <QCheckBox>
#include <QHBoxLayout>
#include <QString>
#include <QPushButton>
class TaskItemWidget : public QWidget
{
    Q_OBJECT

public:
    explicit TaskItemWidget(Task* task, QWidget *parent = nullptr);

    void updateTaskData();
    Task* getTask() const {return m_task; }

signals:  // gửi tín hiệu khi bấm
    void taskStatusChanged(Task* task, bool completed); // tín hiệu khi thay đổi trạng thái 
    //void taskClicked(Task* task); // tín hiệu khi bấm vào widget
    void editTaskRequest(Task* task);
    void deleteTaskRequest(Task* task);

private slots:
    void onCheckboxStateChanged(int state); // hàm gọi khi checkbox thay đổi trạng thái
    void onEditClicked();
    void onDeleteClicked();
private:
    void setupUI();
    void applyCompletedStyle(bool completed); // đổi giao diện, đổi màu chữ :))
    Task* m_task;
    QCheckBox* m_checkbox;
    QPushButton* edit_btn;
    QPushButton* delete_btn;
    QLabel* m_titleLabel;
    QLabel* m_descriptionLabel;
    QLabel* m_priorityLabel;
    QLabel* m_timeLabel;
    QWidget* m_tagContainer;
    QWidget *checkbox_text;
public:
    void setCategoryColor(const QColor& color);

};