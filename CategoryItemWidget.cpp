// CategoryItemWidget.cpp
#include "CategoryItemWidget.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QIcon>

CategoryItemWidget::CategoryItemWidget(const QString& name, int taskCount, QWidget* parent)
    : QWidget(parent)
{
    QHBoxLayout* mainLayout = new QHBoxLayout(this);
    mainLayout->setContentsMargins(12, 12, 12, 12);
    mainLayout->setSpacing(12);

    setStyleSheet(QString(
        "CategoryItemWidget {"
        "  background: white;"
        "  border-left: 5px solid;"
        "  border-radius: 12px;"
        "  padding: 8px;"
        "}"
        "CategoryItemWidget:hover {"
        "  background: #f5f7fa;"
        "  border-left: 5px solid %1;"
        "}"
    )
);

    QLabel* iconLabel = new QLabel();
    QPixmap pixmap = QIcon(":/blueIcons/resources/icons/folder-minus.svg").pixmap(28, 28);
    iconLabel->setPixmap(pixmap);
    iconLabel->setFixedSize(28, 28);
    mainLayout->addWidget(iconLabel);

    QVBoxLayout* textLayout = new QVBoxLayout();
    textLayout->setSpacing(2);

    m_nameLabel = new QLabel(name);
    m_nameLabel->setStyleSheet("font-weight: bold; font-size: 15px; color: #2c3e50;");
    textLayout->addWidget(m_nameLabel);

    m_countLabel = new QLabel(QString("%1 task").arg(taskCount));
    m_countLabel->setStyleSheet("font-size: 13px; color: #7f8c8d;");
    textLayout->addWidget(m_countLabel);

    mainLayout->addLayout(textLayout, 1);

    m_editBtn = new QPushButton();
    m_editBtn->setIcon(QIcon(":/blueIcons/resources/icons/edit.svg"));
    m_editBtn->setFixedSize(32, 32);
    m_editBtn->setStyleSheet(
        "QPushButton { border: none; background: transparent; }"
        "QPushButton:hover { background: #e3f2fd; border-radius: 8px; }"
    );
    mainLayout->addWidget(m_editBtn);

    m_deleteBtn = new QPushButton();
    m_deleteBtn->setIcon(QIcon(":/blueIcons/resources/icons/bin.png"));
    m_deleteBtn->setFixedSize(32, 32);
    m_deleteBtn->setStyleSheet(
        "QPushButton { border: none; background: transparent; }"
        "QPushButton:hover { background: #ffebee; border-radius: 8px; }"
    );
    mainLayout->addWidget(m_deleteBtn);

    connect(m_editBtn, &QPushButton::clicked, this, &CategoryItemWidget::editRequested);
    connect(m_deleteBtn, &QPushButton::clicked, this, &CategoryItemWidget::deleteRequested);
}
// bắt sự kiện khi nhấn chuột lên 1 category
void CategoryItemWidget::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) { // chuột trái
        emit clicked();
    }
    QWidget::mousePressEvent(event);
}