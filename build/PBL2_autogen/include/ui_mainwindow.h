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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QHBoxLayout *horizontalLayout;
    QWidget *leftMenu;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_6;
    QPushButton *taskList;
    QPushButton *addTaskButton;
    QPushButton *calendarList;
    QPushButton *categorybtn;
    QPushButton *statistics;
    QPushButton *pushButton;
    QWidget *mainBody;
    QVBoxLayout *verticalLayout;
    QWidget *headerFrame;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *menuBtn;
    QLabel *appHeader;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_4;
    QFrame *searchFrame;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *searchBar;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *accountBtn;
    QStackedWidget *stackedWidget;
    QWidget *calendarPage;
    QCalendarWidget *calendarWidget;
    QListWidget *calendarTaskList;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_7;
    QLabel *label_8;
    QWidget *categoryPag3_3;
    QLabel *label_10;
    QWidget *page_3;
    QWidget *listPage;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_10;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *editTaskButton;
    QPushButton *taskCompleted;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_9;
    QComboBox *comboBox;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_12;
    QTreeWidget *taskTree;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(874, 681);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("*{\n"
"	color : #000;\n"
"	border : none;\n"
"}\n"
"#leftMenu{\n"
"background-color : #2596be;\n"
"}\n"
"#headerFrame{\n"
"	background-color: #fefeff;\n"
"}\n"
"#centralwidget{\n"
"background-color : #eff9fe;\n"
"}\n"
"QLineEdit{\n"
"	background:transparent;\n"
"}\n"
"#searchFrame{\n"
"	border-radius : 10px;\n"
"	border: 2px solid #2596be;	\n"
"}\n"
"#appHeader{\n"
"	color : #2596be;\n"
"}\n"
"#taskList{\n"
"	background-color : #fefeff;\n"
"	padding : 10px 5px;\n"
"	text-align: left;\n"
"	border-top-radius : 20px;\n"
"}\n"
"QPushButton{\n"
"	\n"
"	padding : 10px 5px;\n"
"	text-align: left;\n"
"	\n"
"}\n"
"#editTaskButton , #taskCompleted{\n"
"	background-color :#dff6ff;\n"
"	padding : 5px 10px;\n"
"	 border-radius : 15px;\n"
"}\n"
"\n"
"#listPage{\n"
"	background-color : #fefeff;\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        leftMenu = new QWidget(centralwidget);
        leftMenu->setObjectName("leftMenu");
        leftMenu->setMinimumSize(QSize(200, 0));
        leftMenu->setMaximumSize(QSize(200, 16777215));
        leftMenu->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_3 = new QVBoxLayout(leftMenu);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(15, 0, 0, 0);
        frame = new QFrame(leftMenu);
        frame->setObjectName("frame");
        frame->setMinimumSize(QSize(0, 0));
        frame->setMaximumSize(QSize(200, 16777215));
        frame->setFrameShape(QFrame::Shape::StyledPanel);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        frame_3 = new QFrame(frame);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::StyledPanel);
        frame_3->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame_3);
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        label = new QLabel(frame_3);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        label->setFont(font);

        horizontalLayout_7->addWidget(label, 0, Qt::AlignmentFlag::AlignTop);


        verticalLayout_4->addWidget(frame_3);

        frame_2 = new QFrame(frame);
        frame_2->setObjectName("frame_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setMinimumSize(QSize(380, 528));
        frame_2->setFrameShape(QFrame::Shape::StyledPanel);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_7 = new QVBoxLayout(frame_2);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName("verticalLayout_7");
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        frame_4 = new QFrame(frame_2);
        frame_4->setObjectName("frame_4");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame_4->sizePolicy().hasHeightForWidth());
        frame_4->setSizePolicy(sizePolicy1);
        frame_4->setFrameShape(QFrame::Shape::StyledPanel);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        verticalLayout_6 = new QVBoxLayout(frame_4);
        verticalLayout_6->setSpacing(10);
        verticalLayout_6->setObjectName("verticalLayout_6");
        verticalLayout_6->setSizeConstraint(QLayout::SizeConstraint::SetNoConstraint);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        taskList = new QPushButton(frame_4);
        taskList->setObjectName("taskList");
        taskList->setMaximumSize(QSize(250, 16777215));
        QFont font1;
        font1.setBold(false);
        taskList->setFont(font1);
        taskList->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/blueIcons/resources/icons/check-square1.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        taskList->setIcon(icon);
        taskList->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(taskList);

        addTaskButton = new QPushButton(frame_4);
        addTaskButton->setObjectName("addTaskButton");
        addTaskButton->setFont(font1);
        addTaskButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/blueIcons/resources/icons/plus-square1.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addTaskButton->setIcon(icon1);
        addTaskButton->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(addTaskButton);

        calendarList = new QPushButton(frame_4);
        calendarList->setObjectName("calendarList");
        calendarList->setMaximumSize(QSize(250, 16777215));
        QFont font2;
        font2.setBold(false);
        font2.setKerning(true);
        calendarList->setFont(font2);
        calendarList->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/blueIcons/resources/icons/calendar.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        calendarList->setIcon(icon2);
        calendarList->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(calendarList);

        categorybtn = new QPushButton(frame_4);
        categorybtn->setObjectName("categorybtn");
        categorybtn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/blueIcons/resources/icons/command (1).svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        categorybtn->setIcon(icon3);
        categorybtn->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(categorybtn);

        statistics = new QPushButton(frame_4);
        statistics->setObjectName("statistics");
        statistics->setMaximumSize(QSize(250, 16777215));
        statistics->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/blueIcons/resources/icons/bar-chart.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        statistics->setIcon(icon4);
        statistics->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(statistics);

        pushButton = new QPushButton(frame_4);
        pushButton->setObjectName("pushButton");
        pushButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/blueIcons/resources/icons/hash.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        pushButton->setIcon(icon5);
        pushButton->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(pushButton);


        verticalLayout_7->addWidget(frame_4, 0, Qt::AlignmentFlag::AlignTop);


        verticalLayout_4->addWidget(frame_2);


        verticalLayout_3->addWidget(frame);


        horizontalLayout->addWidget(leftMenu);

        mainBody = new QWidget(centralwidget);
        mainBody->setObjectName("mainBody");
        verticalLayout = new QVBoxLayout(mainBody);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        headerFrame = new QWidget(mainBody);
        headerFrame->setObjectName("headerFrame");
        horizontalLayout_2 = new QHBoxLayout(headerFrame);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 10);
        widget = new QWidget(headerFrame);
        widget->setObjectName("widget");
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        menuBtn = new QPushButton(widget);
        menuBtn->setObjectName("menuBtn");
        menuBtn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/blueIcons/resources/icons/arrow-left1.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        menuBtn->setIcon(icon6);
        menuBtn->setIconSize(QSize(24, 24));

        horizontalLayout_3->addWidget(menuBtn);

        appHeader = new QLabel(widget);
        appHeader->setObjectName("appHeader");
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setUnderline(false);
        font3.setStrikeOut(false);
        appHeader->setFont(font3);

        horizontalLayout_3->addWidget(appHeader);


        horizontalLayout_2->addWidget(widget, 0, Qt::AlignmentFlag::AlignLeft);

        widget_3 = new QWidget(headerFrame);
        widget_3->setObjectName("widget_3");
        horizontalLayout_4 = new QHBoxLayout(widget_3);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        searchFrame = new QFrame(widget_3);
        searchFrame->setObjectName("searchFrame");
        searchFrame->setMinimumSize(QSize(250, 0));
        searchFrame->setMaximumSize(QSize(16777215, 16777215));
        searchFrame->setFrameShape(QFrame::Shape::StyledPanel);
        searchFrame->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_5 = new QHBoxLayout(searchFrame);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(searchFrame);
        label_2->setObjectName("label_2");
        label_2->setMinimumSize(QSize(30, 30));
        label_2->setMaximumSize(QSize(30, 30));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/blueIcons/resources/icons/search.svg")));
        label_2->setScaledContents(true);

        horizontalLayout_5->addWidget(label_2);

        searchBar = new QLineEdit(searchFrame);
        searchBar->setObjectName("searchBar");
        searchBar->setFocusPolicy(Qt::FocusPolicy::WheelFocus);

        horizontalLayout_5->addWidget(searchBar);


        horizontalLayout_4->addWidget(searchFrame, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);


        horizontalLayout_2->addWidget(widget_3, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        widget_4 = new QWidget(headerFrame);
        widget_4->setObjectName("widget_4");
        horizontalLayout_6 = new QHBoxLayout(widget_4);
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        accountBtn = new QPushButton(widget_4);
        accountBtn->setObjectName("accountBtn");
        accountBtn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/blueIcons/resources/icons/bell\304\203.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        accountBtn->setIcon(icon7);
        accountBtn->setIconSize(QSize(25, 25));

        horizontalLayout_6->addWidget(accountBtn);


        horizontalLayout_2->addWidget(widget_4, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout->addWidget(headerFrame, 0, Qt::AlignmentFlag::AlignTop);

        stackedWidget = new QStackedWidget(mainBody);
        stackedWidget->setObjectName("stackedWidget");
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        calendarPage = new QWidget();
        calendarPage->setObjectName("calendarPage");
        calendarWidget = new QCalendarWidget(calendarPage);
        calendarWidget->setObjectName("calendarWidget");
        calendarWidget->setGeometry(QRect(0, 10, 256, 190));
        calendarTaskList = new QListWidget(calendarPage);
        calendarTaskList->setObjectName("calendarTaskList");
        calendarTaskList->setGeometry(QRect(270, 10, 661, 541));
        frame_5 = new QFrame(calendarPage);
        frame_5->setObjectName("frame_5");
        frame_5->setGeometry(QRect(0, 200, 264, 36));
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_8 = new QHBoxLayout(frame_5);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        label_4 = new QLabel(frame_5);
        label_4->setObjectName("label_4");

        horizontalLayout_8->addWidget(label_4);

        label_3 = new QLabel(frame_5);
        label_3->setObjectName("label_3");

        horizontalLayout_8->addWidget(label_3);

        label_5 = new QLabel(frame_5);
        label_5->setObjectName("label_5");

        horizontalLayout_8->addWidget(label_5);

        label_6 = new QLabel(frame_5);
        label_6->setObjectName("label_6");

        horizontalLayout_8->addWidget(label_6);

        frame_6 = new QFrame(calendarPage);
        frame_6->setObjectName("frame_6");
        frame_6->setGeometry(QRect(0, 240, 228, 36));
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_6);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        label_7 = new QLabel(frame_6);
        label_7->setObjectName("label_7");

        horizontalLayout_9->addWidget(label_7);

        label_8 = new QLabel(frame_6);
        label_8->setObjectName("label_8");

        horizontalLayout_9->addWidget(label_8);

        stackedWidget->addWidget(calendarPage);
        categoryPag3_3 = new QWidget();
        categoryPag3_3->setObjectName("categoryPag3_3");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(categoryPag3_3->sizePolicy().hasHeightForWidth());
        categoryPag3_3->setSizePolicy(sizePolicy2);
        label_10 = new QLabel(categoryPag3_3);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(20, 10, 49, 16));
        stackedWidget->addWidget(categoryPag3_3);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        listPage = new QWidget();
        listPage->setObjectName("listPage");
        verticalLayout_5 = new QVBoxLayout(listPage);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_7 = new QFrame(listPage);
        frame_7->setObjectName("frame_7");
        frame_7->setFrameShape(QFrame::Shape::StyledPanel);
        frame_7->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_10 = new QHBoxLayout(frame_7);
        horizontalLayout_10->setSpacing(10);
        horizontalLayout_10->setObjectName("horizontalLayout_10");
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        frame_10 = new QFrame(frame_7);
        frame_10->setObjectName("frame_10");
        frame_10->setFrameShape(QFrame::Shape::StyledPanel);
        frame_10->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_11 = new QHBoxLayout(frame_10);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        editTaskButton = new QPushButton(frame_10);
        editTaskButton->setObjectName("editTaskButton");
        editTaskButton->setFont(font1);
        editTaskButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/blueIcons/resources/icons/edit1.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        editTaskButton->setIcon(icon8);
        editTaskButton->setIconSize(QSize(24, 24));

        horizontalLayout_11->addWidget(editTaskButton);

        taskCompleted = new QPushButton(frame_10);
        taskCompleted->setObjectName("taskCompleted");
        taskCompleted->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/blueIcons/resources/icons/check-circle.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        taskCompleted->setIcon(icon9);
        taskCompleted->setIconSize(QSize(24, 24));

        horizontalLayout_11->addWidget(taskCompleted);


        horizontalLayout_10->addWidget(frame_10, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_9);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        label_9 = new QLabel(frame_9);
        label_9->setObjectName("label_9");
        label_9->setMinimumSize(QSize(30, 30));
        label_9->setMaximumSize(QSize(30, 16777215));
        label_9->setPixmap(QPixmap(QString::fromUtf8(":/blueIcons/resources/icons/filter.svg")));

        horizontalLayout_13->addWidget(label_9);

        comboBox = new QComboBox(frame_9);
        comboBox->setObjectName("comboBox");

        horizontalLayout_13->addWidget(comboBox);


        horizontalLayout_10->addWidget(frame_9);


        verticalLayout_5->addWidget(frame_7);

        frame_8 = new QFrame(listPage);
        frame_8->setObjectName("frame_8");
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_8);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        taskTree = new QTreeWidget(frame_8);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QString::fromUtf8("1"));
        taskTree->setHeaderItem(__qtreewidgetitem);
        taskTree->setObjectName("taskTree");
        sizePolicy.setHeightForWidth(taskTree->sizePolicy().hasHeightForWidth());
        taskTree->setSizePolicy(sizePolicy);
        taskTree->setFocusPolicy(Qt::FocusPolicy::NoFocus);

        horizontalLayout_12->addWidget(taskTree);


        verticalLayout_5->addWidget(frame_8);

        stackedWidget->addWidget(listPage);

        verticalLayout->addWidget(stackedWidget);


        horizontalLayout->addWidget(mainBody);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 874, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "To Do List", nullptr));
        taskList->setText(QCoreApplication::translate("MainWindow", "Task List", nullptr));
        addTaskButton->setText(QCoreApplication::translate("MainWindow", " Add Task", nullptr));
        calendarList->setText(QCoreApplication::translate("MainWindow", "Calendar", nullptr));
        categorybtn->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        statistics->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Tags", nullptr));
        menuBtn->setText(QString());
        appHeader->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        label_2->setText(QString());
        searchBar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search Something...", nullptr));
        accountBtn->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\304\220\341\273\231 \306\260u ti\303\252n :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\360\237\237\242 Th\341\272\245p", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\360\237\237\241 Trung b\303\254nh", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\360\237\224\264 Cao", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\342\217\263: Ch\306\260a ho\303\240n th\303\240nh", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\342\234\205 : Ho\303\240n th\303\240nh", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        editTaskButton->setText(QCoreApplication::translate("MainWindow", "Edit Task", nullptr));
        taskCompleted->setText(QCoreApplication::translate("MainWindow", "Completed Tasks", nullptr));
        label_9->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
