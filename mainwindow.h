#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "heap_manager.h"
#include <string>
#include <iostream>
#include <QTreeWidget>
#include <QHeaderView>
#include <QFile>
#include <QCoreApplication>
#include <QDir>
#include <QTimer>
#include "Trie.h"
#include "AdvancedTaskDialog.h"
#include "TaskListWidget.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalBarSeries>
#include "CategoryItemWidget.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();
    void updateTaskList();
    void onCompletedClicked();
    void onAllTaskClicked();
    void onCalendarDateClicked(const QDate& date);
    void onMenuButtonClicked();
    void toggleLeftMenu();
    void highlightActiveButton(QPushButton*);
    void backCategory();
private:

    void LoadFile(const std::string&, HeapManager&);
    void SaveToFile(const std::string&);
    bool leftMenuVisible;
    int originalMenuWidth;
    void setupStatistics();
    void updateStatistics();

    void onCategoryClicked();
    void onAddCategoryClicked();
    // void onDeleteCategoryClicked();

    void onTaskStatusChanged(Task* task, bool completed);
    void onTaskEditClicked(Task* task);
    void onTaskDeleteClicked(Task* task);
    //void onTaskClicked(Task* task);
    //QTreeWidgetItem* createTaskItem(Task* t);


private:
    Ui::MainWindow *ui;
    HeapManager manager;
    //QLabel* noTaskLabel;
    bool showCompleteTasks = false;
    bool showAllTask = false;
    Trie taskTrie;
    QString m_currentCategory;
    void buildTrie(); // tạo trie từ danh sách task (đọc từ tiêu đề vào)
    bool isListView = true;
    TaskListWidget *m_taskListWidget;
    TaskListWidget *m_todayListWidget;
    TaskListWidget *m_categoryListWidget;
    void loadTaskListWidget(const QString& ,const QString& sortMode = "Ưu tiên", const QString & filterMode = "Incomplete");
    void loadTodayTaskListWidget();
    void loadCategoryListWidget(const QString& category);
    void setUpCategories();
    

    QChart *m_pieChart;
    QPieSeries* m_pieSeries;
    QChartView* m_pieView;

    QChart* m_barChart;
    QHorizontalBarSeries* m_barSeries;
    QChartView *m_barView;


    QMap<QString, QListWidgetItem*> m_categoryWidgets;
    void updateCategoryView();
    void addNewCategory();
    void editCategory(const QString& oldName);
    void deleteCategory(const QString& name);
protected:
    bool eventFilter(QObject* obj, QEvent* event) override;
};
#endif // MAINWINDOW_H