#pragma once
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QCheckBox>
#include <QSpinBox>
#include <QDateTimeEdit>
#include <QLabel>
#include <QDialogButtonBox>
#include "heap_manager.h"
#include "Task.h"
#include <set>


class AdvancedTaskDialog : public QDialog{
    Q_OBJECT
public:
    AdvancedTaskDialog(HeapManager& manager, 
std::set<std::string>& m_categories, QWidget* parent = nullptr); 
    AdvancedTaskDialog(Task* task, HeapManager& manager,
std::set<std::string>& m_categories, QWidget* parent = nullptr);
    Task* getCreatedTask(){return createdTask;}
private slots:
    void onSaveClicked();
    void onCancelClicked();
    void onPriorityChanged(int priority);
    void updateDateTimeValidation();
private:
    void setupUI();
    void setupConnections();
    void loadTaskData();
    void setupCategoryCombo();
    void setupRecurrenceCombo();
    std::set<std::string>& m_customCategories;
    QLineEdit* titleEdit;
    QTextEdit* descriptionEdit;
    QSpinBox* prioritySpin;
    QDateTimeEdit* deadlineEdit;
    QComboBox* categoryCombo;
    QLineEdit* tagsEdit;
    QComboBox* recurrenceCombo;
    QCheckBox* completedCheckbox;
    QLabel* priorityLabel;
    QLabel* deadlineLabel;
    QDialogButtonBox* buttonBox;
    HeapManager& manager;
    Task* existingTask; //edit mode
    Task* createdTask;// create mode
    bool isEditMode;
};

