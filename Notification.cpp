#include "Notification.h"

NotificationWidget::NotificationWidget(QWidget* parent)
    : QWidget(parent), notificationCount(0){
        setupUI();
    }


void NotificationWidget::setupUI(){

    emptyLabel = new QLabel("Không có thông báo nào");
        emptyLabel->setAlignment(Qt::AlignCenter);
        emptyLabel->setStyleSheet(
            "QLabel { "
            "   color: #333; "
            "   font-size: 14px; "
            "   padding: 20px; "
            "}"
        );
        emptyLabel->hide();
    clearAllbtn = new QPushButton(this);
    clearAllbtn->setText("🗑️ Xóa tất cả"); 
    clearAllbtn->hide();
    clearAllbtn->setStyleSheet(
        "QPushButton { "
        "   background-color: #e74c3c; "
        "   color: white; "
        "   border: none; "
        "   border-radius: 6px; "
        "   padding: 8px 20px; "
        "   font-size: 13px; "
        "   font-weight: bold; "
        "   margin: 10px 0; "
        "} "
        "QPushButton:hover { "
        "   background-color: #c0392b; "
        "} "
        "QPushButton:pressed { "
        "   background-color: #a93226; "
        "}"
    );

    mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); 
    scrollArea->setStyleSheet("QScrollArea { border: none; background: transparent; }");

    scrollContent = new QWidget(this);
    scrollLayout = new QVBoxLayout(scrollContent);
    scrollLayout->setContentsMargins(10, 10 , 10, 10);
    scrollLayout->setSpacing(10);
    scrollLayout->setSpacing(10);

    scrollLayout->addWidget(clearAllbtn, 0, Qt::AlignHCenter);
    scrollLayout->addWidget(emptyLabel);
    scrollLayout->addStretch();
    
    scrollArea->setWidget(scrollContent);
    mainLayout->addWidget(scrollArea);

    setStyleSheet("QWidget { background-color: #f5f5f5; }");

    connect(clearAllbtn, &QPushButton::clicked, this,[=](){
        m_clearAll = true;
        clearAllNotifications();
    });
}

int NotificationWidget::countNotifications() {
    return notificationCount;
}


QFrame* NotificationWidget::createNotificationCard(Task* task, const QString& type) {
    QFrame* card = new QFrame();
    card->setFrameShape(QFrame::Box);
    card->setLineWidth(1);
    
    QString borderColor =  "#f44336";
    QString bgColor =  "#ffebee";
    
    card->setStyleSheet(QString(
        "QFrame { "
        "   background-color: %1; "
        "   border: 2px solid %2; "
        "   border-radius: 8px; "
        "   padding: 12px; "
        "}"
    ).arg(bgColor, borderColor));
    
    QVBoxLayout* cardLayout = new QVBoxLayout(card);
    cardLayout->setSpacing(8);
    
    QHBoxLayout* headerLayout = new QHBoxLayout();
    
    
    QLabel* typeLabel = new QLabel(
        (type == "overdue") ? "QUÁ HẠN" : "SẮP ĐẾN HẠN"
    );
    typeLabel->setStyleSheet(QString(
        "QLabel { "
        "   color: #333; "
        "   font-weight: bold; "
        "   font-size: 12px; "
        "}"
    ));
    
    headerLayout->addWidget(typeLabel);
    headerLayout->addStretch();
    
    QLabel* titleLabel = new QLabel(QString::fromStdString(task->getTitle()));
    titleLabel->setStyleSheet(
        "QLabel { "
        "   font-size: 16px; "
        "   font-weight: bold; "
        "   color: #333; "
        "}"
    );
    titleLabel->setWordWrap(true);
    
    QLabel* deadlineLabel = new QLabel(
        "Hạn: " + QString::fromStdString(task->getDeadline())
    );
    deadlineLabel->setStyleSheet(
        "QLabel { "
        "   font-size: 13px; "
        "   color: #333; "
        "}"
    );
    
    QString priorityText;
    QString priorityStr = QString::number(task->getPriority());
    if (priorityStr == "high") priorityText = " Cao";
    else if (priorityStr == "medium") priorityText = " Trung bình";
    else priorityText = " Thấp";
    
    QLabel* priorityLabel = new QLabel("Độ ưu tiên: " + priorityText);
    priorityLabel->setStyleSheet(
        "QLabel { "
        "   font-size: 13px; "
        "   color: #333; "
        "}"
    );
    
    cardLayout->addLayout(headerLayout);
    cardLayout->addWidget(titleLabel);
    cardLayout->addWidget(deadlineLabel);
    cardLayout->addWidget(priorityLabel);
    
    return card;
}


void NotificationWidget::addNotificationItem(Task* task, const QString& type) {
    QFrame* card = createNotificationCard(task, type);
    scrollLayout->insertWidget(1 + notificationCount, card);
    notificationCount++;
}

void NotificationWidget::clearAllNotifications() {
    while (scrollLayout->count() > 3) { // giữ lại clearAllbtn, emptyLabel, và stretch
        QLayoutItem* item = scrollLayout->takeAt(1);
        if (item && item->widget()) {
            delete item->widget();
        }
        delete item;
    }
    
    notificationCount = 0;
    
    emptyLabel->show();
    clearAllbtn->hide();
}





void NotificationWidget::updateNotifications(std::vector<Task*> tasks) {
    clearAllNotifications();
    
    if (m_clearAll == false){
    for (Task* task : tasks) {
        if (task->isCompleted()) continue;
        
        QDateTime deadline = QDateTime::fromString(
            QString::fromStdString(task->getDeadline()), 
            "yyyy-MM-dd HH:mm"
        );
        
        QDateTime now = QDateTime::currentDateTime();
        
        if (deadline < now) {
            addNotificationItem(task, "overdue");
        }
        else if (deadline <= now.addDays(1)) {
            addNotificationItem(task, "upcoming");
        }
    }
}
    if (notificationCount == 0) {
        emptyLabel->show();
        clearAllbtn->hide();
    }
    else {
        emptyLabel->hide();
        clearAllbtn->show();
    }
}
