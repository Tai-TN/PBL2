#include <QWidget>
#include "Vector.h"
#include <QVBoxLayout>
#include <QScrollArea>
#include "Task.h"
#include <QLabel>
#include <QFrame>
#include <QPushButton>
#ifndef NOTIFICATIONWIDGET_H
#define NOTIFICATIONWIDGET_H
class NotificationWidget : public QWidget{
    Q_OBJECT
public:
    NotificationWidget(QWidget* parent = nullptr);
    void updateNotifications(Vector<Task*> tasks);
    int countNotifications();

private:
    QVBoxLayout* mainLayout;
    QScrollArea* scrollArea;
    QWidget* scrollContent;
    QVBoxLayout* scrollLayout;
    QPushButton* clearAllbtn;
    bool m_clearAll = false;
    QLabel* emptyLabel;
    int notificationCount;
    void clearAllNotifications();
    void addNotificationItem(Task* task, const QString& type);
    void setupUI();
    QFrame* createNotificationCard(Task* task, const QString& type);

};
#endif
