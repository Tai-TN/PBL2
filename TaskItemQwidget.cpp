#include "mainwindow.h"           
#include "ui_mainwindow.h"        
#include "TaskItemQwidget.h"
#include <QMessageBox>
TaskItemWidget::TaskItemWidget(Task* task, QWidget* parent)
    : QWidget(parent), m_task(task)
{
    setupUI();
    updateTaskData();

}

void TaskItemWidget::setupUI(){
    QHBoxLayout *mainLayout = new QHBoxLayout(this); // chua checkbox va noi dung
    mainLayout->setContentsMargins(10, 8, 10, 8) ; // can le

    checkbox_text = new QWidget(this);
    QHBoxLayout *checkbox_textLayout = new QHBoxLayout(checkbox_text);
    checkbox_textLayout->setContentsMargins(10, 8, 10, 8);
    
    m_checkbox = new QCheckBox(this);
    m_checkbox->setFixedSize(30, 30);
    m_checkbox->setFocusPolicy(Qt::NoFocus);
    checkbox_textLayout->addWidget(m_checkbox);


    QWidget *textWidget = new QWidget(this); // widget đẻ hiển thị 
    QVBoxLayout *textLayout = new QVBoxLayout(textWidget);
    textLayout->setContentsMargins(0, 0, 0, 0);

    QWidget *headerWidget = new QWidget(this);// chua tieu de, thoi gian, ...
    QHBoxLayout *headerLayout = new QHBoxLayout(headerWidget);
    headerLayout->setContentsMargins(0, 0, 0, 0);
    //headerLayout->setSpacing(5);
    
    m_titleLabel = new QLabel(this);
    m_titleLabel->setStyleSheet("font-weight : bold; font-size : 14px;");
    m_titleLabel->setAlignment(Qt::AlignBottom);


    m_priorityLabel = new QLabel(this);
    m_priorityLabel->setStyleSheet("font-size: 12px; color: #666;");
    m_priorityLabel->setFixedSize(90, 20);
    //m_priorityLabel->setStyleSheet("border-radius : 6px;");

    m_timeLabel = new QLabel(this);
    m_timeLabel->setStyleSheet("font-size: 12px; color: #666;");


    headerLayout->addWidget(m_titleLabel);
    headerLayout->addStretch(); // tao 1 khoang trongt
    headerLayout->addWidget(m_priorityLabel);
    headerLayout->addWidget(m_timeLabel);

    QWidget *bottomWidget = new QWidget(this);
    QHBoxLayout *bottomLayout = new QHBoxLayout(bottomWidget);
    bottomLayout->setContentsMargins(0, 0, 0 ,0);


    m_descriptionLabel = new QLabel(this);
    m_descriptionLabel->setStyleSheet("font-size: 12px; color: #777");
    m_descriptionLabel->setWordWrap(true); // xuong dong neu qua dai
    m_descriptionLabel->setAlignment(Qt::AlignTop);

    recurrence_label = new QLabel(this);
    recurrence_label->setFocusPolicy(Qt::NoFocus);
    recurrence_label->setFixedSize(24, 24);
    recurrence_label->setPixmap(QPixmap(":/blueIcons/resources/icons/refresh-cw.svg"));

    recurrence_text_label = new QLabel(this);
    recurrence_text_label->setFocusPolicy(Qt::NoFocus);


    edit_btn = new QPushButton(this);
    edit_btn->setFixedSize(30, 30);
    edit_btn->setFocusPolicy(Qt::NoFocus);

    delete_btn = new QPushButton(this);
    delete_btn->setFixedSize(30, 30);
    delete_btn->setFocusPolicy(Qt::NoFocus);
    edit_btn->setIcon(QIcon(":/blueIcons/resources/icons/edit.svg"));
    delete_btn->setIcon(QIcon(":blueIcons/resources/icons/bin.png"));
    edit_btn->setIconSize(QSize(18,18));
    delete_btn->setIconSize(QSize(18,18));
    edit_btn->setStyleSheet(
        "QPushButton { border: none; background: transparent; }"
        "QPushButton:hover { background: #e3f2fd; border-radius: 8px; }"
    );
    delete_btn->setStyleSheet(
        "QPushButton { border: none; background: transparent; }"
        "QPushButton:hover { background: #ffebee; border-radius: 8px; }"
    );

    bottomLayout->addWidget(m_descriptionLabel);
    bottomLayout->addStretch();
    bottomLayout->addWidget(recurrence_label);
    bottomLayout->addWidget(recurrence_text_label);
    bottomLayout->addWidget(edit_btn);
    bottomLayout->addWidget(delete_btn);
    

    textLayout->addWidget(headerWidget);
    textLayout->addWidget(bottomWidget);

    checkbox_textLayout->addWidget(textWidget, 1);
    mainLayout->addWidget(checkbox_text);
    checkbox_text->setObjectName("taskContainer"); // Đặt tên đối tượng
    checkbox_text->setStyleSheet("#taskContainer { background-color: white; }");
    m_checkbox->setStyleSheet(
    "QCheckBox::indicator {"
        "width: 30px;" // Kích thước indicator
        "height: 30px;"
        "border: 1px solid gray;" // Viền cho ô vuông
        "background-color: transparent;"
    "}"
    "QCheckBox::indicator:unchecked {"
        "image: url(:blueIcons/resources/icons/circle_tick.svg);" // Icon ô vuông trống khi chưa chọn
    "}"
    "QCheckBox::indicator:checked {"
        "image: url(:blueIcons/resources/icons/check-circle.svg);" 
    "}"

);  
    this->setObjectName("TaskItemWidget");
    this->setAttribute(Qt::WA_StyledBackground);// widget tu tao co the ve background
    this->setStyleSheet(
        "#TaskItemWidget {"
        "background-color : white;"
        "border-radius : 10px;"
        "border: 1px solid  #76b9dbff;"

        "}"
    );
    connect(m_checkbox, &QCheckBox::stateChanged, this, &TaskItemWidget::onCheckboxStateChanged);
    connect(edit_btn, &QPushButton::clicked, this, &TaskItemWidget::onEditClicked);
    connect(delete_btn,&QPushButton::clicked, this, &TaskItemWidget::onDeleteClicked);


}


void TaskItemWidget::updateTaskData(){
    if (!m_task) {
        QMessageBox::warning(this, "Loi", "Loi khong tim thay m_task o ham updateTaskData~");
        return;
    }
    //title
   m_titleLabel->setText(QString::fromStdString(m_task->getTitle()));
   m_descriptionLabel->setText(QString::fromStdString(m_task->getDescription()));
   QString priorityStyle, priorityText;

   switch(m_task->getPriority()){
    case 3:
        priorityText = "Priority:High";
        break;
    case 2:
        priorityText = "Priority:Medium";
        break;
    case 1:
        priorityText = "Priority:Low";
        break;
    default:
        priorityText = "Priority:No";
        break;
   }


   m_priorityLabel->setText(priorityText);

   //time

   if (m_task->isCompleted()){
        m_timeLabel->setText("Hoàn thành");

   }
   else  if (m_task->isOverdue()){
        m_timeLabel->setText(QString::fromStdString("Quá hạn " + m_task->getDeadline()));
   }
   else{
        m_timeLabel->setText(QString::fromStdString("Hạn " + m_task->getDeadline()));
   }

   recurrence_text_label->setText(QString::fromStdString(m_task->getRecurrence()));
    m_checkbox->setCheckState((m_task->isCompleted()) ? Qt::Checked : Qt::Unchecked);

   applyCompletedStyle(m_task->isCompleted());

}



//----------------------------------------------------------------------
void TaskItemWidget::applyCompletedStyle(bool completed)
{
     if (completed) {
        m_titleLabel->setStyleSheet("text-decoration: line-through; color: #95a5a6;");
    } else {
         m_titleLabel->setStyleSheet("font-weight: bold; font-size: 14px;");

}
}
void TaskItemWidget::onCheckboxStateChanged(int state)
{
    bool completed = (state == Qt::Checked);
    applyCompletedStyle(completed);
    emit taskStatusChanged(m_task, completed);
}

void TaskItemWidget::setCategoryColor(const QColor& color){
    this->setStyleSheet(QString("TaskItemWidget { border-left: 4px solid %1; background-color: white; }")
                        .arg(color.name()));
    }

void TaskItemWidget::onEditClicked(){
    emit editTaskRequest(m_task);
}

void TaskItemWidget::onDeleteClicked(){
    emit deleteTaskRequest(m_task);
}

