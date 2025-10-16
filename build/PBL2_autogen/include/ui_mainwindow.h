/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *calendarPage;
    QCalendarWidget *calendarWidget;
    QListWidget *calendarTaskList;
    QWidget *page_3;
    QWidget *listPage;
    QTreeWidget *taskTree;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox;
    QLineEdit *searchBar;
    QPushButton *editTaskButton;
    QPushButton *addTaskButton;
    QPushButton *taskCompleted;
    QPushButton *viewSwitchButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1116, 667);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 40, 1011, 571));
        calendarPage = new QWidget();
        calendarPage->setObjectName("calendarPage");
        calendarWidget = new QCalendarWidget(calendarPage);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(0, 10, 256, 190));
        calendarTaskList = new QListWidget(calendarPage);
        calendarTaskList->setObjectName("calendarTaskList");
        calendarTaskList->setGeometry(QRect(270, 10, 661, 541));
        stackedWidget->addWidget(calendarPage);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        listPage = new QWidget();
        listPage->setObjectName("listPage");
        taskTree = new QTreeWidget(listPage);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        taskTree->setHeaderItem(__qtreewidgetitem);
        taskTree->setObjectName("taskTree");
        taskTree->setGeometry(QRect(150, 10, 781, 531));
        taskTree->header()->setStretchLastSection(false);
        verticalLayoutWidget = new QWidget(listPage);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(0, 30, 141, 143));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName("comboBox");

        verticalLayout->addWidget(comboBox);

        searchBar = new QLineEdit(verticalLayoutWidget);
        searchBar->setObjectName("searchBar");
        searchBar->setReadOnly(false);

        verticalLayout->addWidget(searchBar);

        editTaskButton = new QPushButton(verticalLayoutWidget);
        editTaskButton->setObjectName("editTaskButton");

        verticalLayout->addWidget(editTaskButton);

        addTaskButton = new QPushButton(verticalLayoutWidget);
        addTaskButton->setObjectName("addTaskButton");

        verticalLayout->addWidget(addTaskButton);

        taskCompleted = new QPushButton(verticalLayoutWidget);
        taskCompleted->setObjectName("taskCompleted");

        verticalLayout->addWidget(taskCompleted);

        stackedWidget->addWidget(listPage);
        viewSwitchButton = new QPushButton(centralwidget);
        viewSwitchButton->setObjectName("viewSwitchButton");
        viewSwitchButton->setGeometry(QRect(0, 0, 111, 31));
        viewSwitchButton->setCheckable(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1116, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        searchBar->setPlaceholderText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Nh\341\272\255p t\341\273\253 kh\303\263a t\303\254m ki\341\272\277m...", nullptr));
        editTaskButton->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217Edit Task", nullptr));
        addTaskButton->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Add Task", nullptr));
        taskCompleted->setText(QCoreApplication::translate("MainWindow", "Completed Tasks", nullptr));
        viewSwitchButton->setText(QCoreApplication::translate("MainWindow", "\360\237\223\205 Xem L\341\273\213ch", nullptr));
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
