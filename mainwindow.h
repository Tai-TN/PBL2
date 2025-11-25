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
#include <set>
#include <QTimer>
#include "Trie.h"
#include "AdvancedTaskDialog.h"
#include "TaskListWidget.h"
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QBarSeries>
#include <QtCharts/QChart>
#include <QtCharts/QValueAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QHorizontalStackedBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QStackedBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include "CategoryItemWidget.h"
#include <QDir>
#include <QTextCharFormat>  
#include "Notification.h"
#include <QMenu>
#include <QWidgetAction>
#include <QStackedLayout>
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
    void onTimeFilterChanged(int index);

    void onFilterListPageClicked();
    //chuc nang thong bao
    void showNotificationMenu();
    void updateCountLabel();
private:

    void LoadFile(const std::string&, HeapManager&);
    void SaveToFile(const std::string&);
    bool leftMenuVisible;
    int originalMenuWidth;
    bool isFilterTaskPage = false;
    void setupStatistics();
    void updateStatistics();

    void loadCategories(const std::string&);
    void saveCategories(const std::string&);

    void onTaskStatusChanged(Task* task, bool completed);
    void onTaskEditClicked(Task* task);
    void onTaskDeleteClicked(Task* task);
    void updateCalendarDots();

    //chuc nang thong bao
    NotificationWidget* m_notificationWidget;
    QMenu* m_notificationMenu;
    QLabel* m_countNotificationLabel;

private:
    Ui::MainWindow *ui;
    HeapManager manager;
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
    
    std::set<std::string> m_categories;
    const QString CATEGORY_FILE_PATH = "D:\\PBL\\PBL2\\PBL2\\Data\\category.txt";
    //Bieu do tron
    // QChart *m_pieChart;
    // QPieSeries* m_pieSeries;
    // QChartView* m_pieView;

    //buieu do cot 
    QChart* m_barChart;
    QHorizontalBarSeries* m_barSeries;
    QChartView *m_barView;



    //staacked bar chart
    QChartView* m_stackedView;
    QChart* m_stackedChart;
    QStackedBarSeries* m_stackedSeries;
    QBarCategoryAxis *axisXStacked;
    QValueAxis *axisYStacked;
    QBarSet* m_setCompleted;
    QBarSet* m_setIncompleted;
    
    //donut
    QPieSeries* m_donutSeries;
    QLabel* m_percentLabel;


    QMap<QString, QListWidgetItem*> m_categoryWidgets;
    void updateCategoryView();
    void addNewCategory();
    void editCategory(const QString& oldName);
    void deleteCategory(const QString& name);

    QDate getFilterStartDate() const;
    QDate getFilterEndDate() const;

    void updateStats(int total, int completed, int highPriority, int remaining);
    void refreshDashboardStats(QDate date);
    Vector<Task*> getTaskbyDate(QDate date);
    bool eventFilter(QObject* obj, QEvent* event) override;
    void updateWeeklyStats();
    QLabel* summaryLabel;

struct CategoryDonut {
        QChart* chart;
        QChartView* chartView;
        QPieSeries* series;
        QLabel* categoryLabel;
        QLabel* percentLabel;
    };
    QMap<QString, CategoryDonut> m_categoryDonuts;
    
    void updateCategoryDonuts();

};
#endif // MAINWINDOW_H