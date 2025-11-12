#include "AdvancedTaskDialog.h"
#include <QPushButton>
#include <QMessageBox>
#include <QVBoxLayout>
#include <QFormLayout>

AdvancedTaskDialog::AdvancedTaskDialog(HeapManager& manager, QWidget* parent)
    :QDialog(parent), manager(manager), existingTask(nullptr), createdTask(nullptr), isEditMode(false){

        setupUI();
        setupConnections();
        setWindowTitle("➕Add Task");
    }

AdvancedTaskDialog::AdvancedTaskDialog(Task* task, HeapManager& manager, QWidget* parent)
    : QDialog(parent), manager(manager), existingTask(task), createdTask(nullptr), isEditMode(true)
{
    setupUI();
    setupConnections();
    loadTaskData();
    setWindowTitle("✏️Edit Task");
}


void AdvancedTaskDialog::setupUI()
{
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    
    
    QFormLayout* formLayout = new QFormLayout();// 1 dòng có thể có label + widget hoặc 1 trong 2 đều đc
    
    // Title 
    titleEdit = new QLineEdit(this);
    titleEdit->setPlaceholderText("Nhập tiêu đề task...");
    formLayout->addRow("📝Title :", titleEdit);
    
    // Description
    descriptionEdit = new QTextEdit(this);
    descriptionEdit->setMaximumHeight(80);
    descriptionEdit->setPlaceholderText("Mô tả chi tiết...");
    formLayout->addRow("📄Description:", descriptionEdit);
    
    // Priority với màu sắc
    prioritySpin = new QSpinBox(this);
    prioritySpin->setRange(1, 3);
    prioritySpin->setValue(2);// giá trị mặc định khi mở addTask
    priorityLabel = new QLabel("🟡 Trung bình", this);
    formLayout->addRow("Độ ưu tiên (1-3):", prioritySpin);
    formLayout->addRow("", priorityLabel);  
    
    // Deadline với datetime
    deadlineEdit = new QDateTimeEdit(this);
    deadlineEdit->setDateTime(QDateTime::currentDateTime().addDays(1));
    deadlineEdit->setDisplayFormat("yyyy-MM-dd HH:mm");
    deadlineEdit->setCalendarPopup(true);
    deadlineLabel = new QLabel("⏰ " + deadlineEdit->dateTime().toString("dd/MM/yyyy HH:mm"), this);
    formLayout->addRow("📅 Deadline :", deadlineEdit);
    formLayout->addRow("", deadlineLabel);
    
    // Category
    categoryCombo = new QComboBox(this);
    setupCategoryCombo();
    formLayout->addRow("📁 Danh mục:", categoryCombo);
    
    // Tags
    tagsEdit = new QLineEdit(this);
    tagsEdit->setPlaceholderText("tag1, tag2, tag3...");
    formLayout->addRow("🏷️ Tags:", tagsEdit);
    
    // Time tracking
    estimatedHoursSpin = new QSpinBox(this);
    estimatedHoursSpin->setRange(0, 100);
    estimatedHoursSpin->setSuffix(" giờ");
    estimatedHoursSpin->setSpecialValueText("Không ước tính");
    formLayout->addRow("⏱️ Thời gian ước tính:", estimatedHoursSpin);
    
    actualHoursSpin = new QSpinBox(this);
    actualHoursSpin->setRange(0, 100);
    actualHoursSpin->setSuffix(" giờ");
    actualHoursSpin->setSpecialValueText("Chưa thực hiện");
    formLayout->addRow("⏱️ Thời gian thực tế:", actualHoursSpin);
    
    //Lặp lại
    recurrenceCombo = new QComboBox(this);
    setupRecurrenceCombo();
    formLayout->addRow("🔄 Lặp lại:", recurrenceCombo);
    
    // Completed (chỉ hiện trong edit mode)
    if (isEditMode) {
        completedCheckbox = new QCheckBox("✅ Đã hoàn thành", this);
        formLayout->addRow("", completedCheckbox);
    }
    
    mainLayout->addLayout(formLayout);
    
    
    buttonBox = new QDialogButtonBox(QDialogButtonBox::Save | QDialogButtonBox::Cancel, this);// tạo 2 nút save và cancel
    mainLayout->addWidget(buttonBox);
    
    // style
    setMinimumWidth(500);
    setStyleSheet(R"(
        QDialog { background: white; }
        QLabel { font-weight: bold; }
        QLineEdit, QTextEdit, QSpinBox, QComboBox, QDateTimeEdit { 
            padding: 8px; 
            border: 1px solid #ccc; 
            border-radius: 4px; 
        }
        QTextEdit { font-family: Arial; }
    )");
}


void AdvancedTaskDialog::setupCategoryCombo()
{
    categoryCombo->addItem("📚 Học Tập");
    categoryCombo->addItem("💼 Công Việc");
    categoryCombo->addItem("❤️ Cá Nhân");
    categoryCombo->addItem("🏥 Sức Khỏe");
    categoryCombo->addItem("🎉 Giải Trí");
    categoryCombo->addItem("💰 Tài Chính");
    categoryCombo->addItem("🏠 Gia Đình");
    categoryCombo->addItem("🔧 Khác");
}

void AdvancedTaskDialog::setupRecurrenceCombo()
{
    recurrenceCombo->addItem("❌ Không lặp lại", "none");
    recurrenceCombo->addItem("📅 Hàng ngày", "daily");
    recurrenceCombo->addItem("📅 Hàng tuần", "weekly");
    recurrenceCombo->addItem("📅 Hàng tháng", "monthly");
}

void AdvancedTaskDialog::setupConnections()
{
    connect(buttonBox, &QDialogButtonBox::accepted, this, &AdvancedTaskDialog::onSaveClicked);
    connect(buttonBox, &QDialogButtonBox::rejected, this, &AdvancedTaskDialog::onCancelClicked);
    connect(prioritySpin, QOverload<int>::of(&QSpinBox::valueChanged), this, &AdvancedTaskDialog::onPriorityChanged);// Chọn phiên bản int thay vì QString
    connect(deadlineEdit, &QDateTimeEdit::dateTimeChanged, this, &AdvancedTaskDialog::updateDateTimeValidation);
}

void AdvancedTaskDialog::loadTaskData()
{
    if (!existingTask) return;
    
    titleEdit->setText(QString::fromStdString(existingTask->getTitle()));
    descriptionEdit->setPlainText(QString::fromStdString(existingTask->getDescription()));
    prioritySpin->setValue(existingTask->getPriority());
    
    // Parse deadline
    QDateTime deadline = QDateTime::fromString(
        QString::fromStdString(existingTask->getDeadline()), 
        "yyyy-MM-dd HH:mm"
    );
    if (deadline.isValid()) {
        deadlineEdit->setDateTime(deadline);
    }
    
    // Category
    QString category = QString::fromStdString(existingTask->getCategory());
    int categoryIndex = categoryCombo->findText(category);
    if (categoryIndex >= 0) {
        categoryCombo->setCurrentIndex(categoryIndex);
    }
    
    // Tags
    auto tags = existingTask->getTags();
    QStringList tagList;
    for (const auto& tag : tags) {
        tagList << QString::fromStdString(tag);
    }
    tagsEdit->setText(tagList.join(", "));
    
    // Time tracking
    estimatedHoursSpin->setValue(existingTask->getEstimatedHours());
    actualHoursSpin->setValue(existingTask->getActualHours());
    
    // Recurrence
    QString recurrence = QString::fromStdString(existingTask->getRecurrence());
    int recurIndex = recurrenceCombo->findData(recurrence);
    if (recurIndex >= 0) {
        recurrenceCombo->setCurrentIndex(recurIndex);
    }
    
    // Completed
    if (completedCheckbox) {
        completedCheckbox->setChecked(existingTask->isCompleted());
    }
}

void AdvancedTaskDialog::onPriorityChanged(int priority)
{
    QString text, color;
    switch(priority) {
        case 1: text = "🟢 Thấp"; color = "green"; break;
        case 2: text = "🟡 Trung bình"; color = "orange"; break;
        case 3: text = "🔴 Cao"; color = "red"; break;
    }
    priorityLabel->setText(text);
    priorityLabel->setStyleSheet(QString("color: %1; font-weight: bold;").arg(color));
}

void AdvancedTaskDialog::updateDateTimeValidation()
{
    QDateTime selected = deadlineEdit->dateTime();
    QDateTime now = QDateTime::currentDateTime();
    
    deadlineLabel->setText("⏰ " + selected.toString("dd/MM/yyyy HH:mm"));
    
    if (selected < now) {
        deadlineLabel->setText("🚨 " + selected.toString("dd/MM/yyyy HH:mm") + " (QUÁ KHỨ!)");
        deadlineLabel->setStyleSheet("color: red; font-weight: bold;");
    } else {
        deadlineLabel->setStyleSheet("color: blue; font-weight: bold;");
    }
}

void AdvancedTaskDialog::onSaveClicked()
{
    
    if (titleEdit->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Lỗi", "📝 Vui lòng nhập tiêu đề task!");
        titleEdit->setFocus();// đưa con trỏ chuột trở lại tiêu đề
        return;
    }
    
    if (deadlineEdit->dateTime() < QDateTime::currentDateTime()) {
        int result = QMessageBox::warning(this, "Cảnh báo", 
            "Deadline đã qua thời gian hiện tại!\nBạn có chắc muốn tiếp tục?",
            QMessageBox::Yes | QMessageBox::No);
        if (result == QMessageBox::No) return;
    }
    
    // Chuan bị dữ liệu
    std::string title = titleEdit->text().trimmed().toStdString();
    std::string description = descriptionEdit->toPlainText().trimmed().toStdString();
    int priority = prioritySpin->value();
    std::string deadline = deadlineEdit->dateTime().toString("yyyy-MM-dd HH:mm").toStdString();
    std::string category = categoryCombo->currentText().toStdString();
    
    // Parse tags
    std::vector<std::string> tags;
    QStringList tagList = tagsEdit->text().split(',', Qt::SkipEmptyParts);
    for (const QString& tag : tagList) {
        tags.push_back(tag.trimmed().toStdString());
    }
    
    int estimatedHours = estimatedHoursSpin->value();
    int actualHours = actualHoursSpin->value();
    std::string recurrence = recurrenceCombo->currentData().toString().toStdString();
    bool completed = isEditMode ? completedCheckbox->isChecked() : false;
    
    // Tạo hoặc sửa task
    if (isEditMode && existingTask) {
        // Update existing task
        existingTask->setTitle(title);
        existingTask->setDescription(description);
        existingTask->setPriority(priority);
        existingTask->setDeadline(deadline);
        existingTask->setCategory(category);
        existingTask->setEstimatedHours(estimatedHours);
        existingTask->setActualHours(actualHours);
        existingTask->setRecurrence(recurrence);
        existingTask->setCompleted(completed);
        
        // Update tags
        existingTask->getTags().clear();
        for (const auto& tag : tags) {
            existingTask->addTag(tag);
        }
    } else {
        // Create new task
        createdTask = new Task(title, description, priority, deadline, tags, category, estimatedHours, recurrence, completed);
    }
    
    accept();
}

void AdvancedTaskDialog::onCancelClicked()
{
    reject();
}