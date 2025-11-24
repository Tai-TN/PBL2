/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
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
    QPushButton *statisticsbtn;
    QPushButton *todayTask;
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
    QPushButton *notifi_btn;
    QStackedWidget *stackedWidget;
    QWidget *calendarPage;
    QHBoxLayout *horizontalLayout_8;
    QWidget *widget_10;
    QVBoxLayout *verticalLayout_21;
    QWidget *widget_11;
    QHBoxLayout *horizontalLayout_19;
    QCalendarWidget *calendarWidget;
    QWidget *widget_12;
    QVBoxLayout *verticalLayout_10;
    QFrame *frame_5;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_4;
    QLabel *label_3;
    QLabel *label_5;
    QLabel *label_6;
    QFrame *frame_6;
    QHBoxLayout *horizontalLayout_21;
    QLabel *label_7;
    QLabel *label_8;
    QListWidget *calendarTaskList;
    QWidget *categoryListPage;
    QVBoxLayout *verticalLayout_14;
    QVBoxLayout *verticalLayout_13;
    QPushButton *backCatetorybtn;
    QWidget *categoryListcontainer;
    QWidget *categoryPage;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_11;
    QFrame *headerCategory;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_14;
    QPushButton *addCategorybtn;
    QListWidget *categoryListWidget;
    QWidget *statisticsPage;
    QVBoxLayout *verticalLayout_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_18;
    QGroupBox *filterGroup;
    QHBoxLayout *horizontalLayout_18;
    QComboBox *comboFilterTime;
    QDateEdit *dateFrom;
    QDateEdit *dateTo;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_15;
    QWidget *widget_6;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_10;
    QLabel *numberAllTask;
    QWidget *widget_7;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_12;
    QLabel *numberCompletedTask;
    QWidget *widget_8;
    QVBoxLayout *verticalLayout_16;
    QLabel *label_14;
    QLabel *numberPendingTask;
    QWidget *widget_9;
    QVBoxLayout *verticalLayout_17;
    QLabel *label_16;
    QLabel *numberProgress;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_20;
    QWidget *statisticsLayout_1;
    QVBoxLayout *verticalLayout_19;
    QWidget *statisticsLayout_2;
    QHBoxLayout *horizontalLayout_20;
    QWidget *statisticsLayout_3;
    QHBoxLayout *horizontalLayout_22;
    QWidget *todayPage;
    QHBoxLayout *horizontalLayout_16;
    QWidget *todayListcontainer;
    QVBoxLayout *verticalLayout_15;
    QStackedWidget *stackedWidget_2;
    QWidget *todayTaskList;
    QWidget *noLabelPage;
    QLabel *noTaskLabel;
    QWidget *listPage;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_7;
    QHBoxLayout *horizontalLayout_10;
    QFrame *frame_10;
    QHBoxLayout *horizontalLayout_11;
    QPushButton *allTask;
    QPushButton *taskCompleted;
    QFrame *frame_9;
    QHBoxLayout *horizontalLayout_13;
    QComboBox *comboBox;
    QPushButton *filterListPagebtn;
    QDateEdit *dateFrom1;
    QDateEdit *dateTo1;
    QFrame *frame_8;
    QHBoxLayout *horizontalLayout_12;
    QWidget *taskListcontainer;
    QMenuBar *menubar;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1053, 680);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("*{\n"
"	color : #000;\n"
"	border : none;\n"
"}\n"
"#leftMenu{\n"
"background-color : #2596be;\n"
"}\n"
"\n"
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
"#appHeader {\n"
"	color : #2596be;\n"
"}\n"
"#todayList{\n"
"backgroud-color : #2596be;\n"
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
"#editTaskButton , #taskCompleted , #allTask , #addCategorybtn{\n"
"	background-color :#dff6ff;\n"
"	padding : 5px 10px;\n"
"	 border-radius : 15px;\n"
"}\n"
"\n"
"#listPage{\n"
"	background-color : #fefeff;\n"
"}\n"
"\n"
"#label_10,#label_11,#label_12, #label_13,#label_14,#label_15, #label_16, #label_17 {\n"
"/*font-size: 10px; color: #555555; font-we"
                        "ight: bold;*/\n"
"color: #555555; font-size: 24px; font-weight: 800;\n"
"}\n"
"/*#label_12{\n"
"color: #8E44AD; font-size: 24px; font-weight: 800;}*/\n"
"\n"
"#widget_5{\n"
"    /*  n\341\273\201n tr\341\272\257ng */\n"
"    background-color: white; \n"
"    /* Vi\341\273\201n m\341\273\217ng m\303\240u x\303\241m nh\341\272\241t */\n"
"    border: 1px solid #E0E0E0; \n"
"    /* Bo g\303\263c */\n"
"    border-radius: 12px; \n"
"}\n"
"#noTaskLabel{\n"
"    color: black;\n"
"    font-size: 16px;\n"
"    font-weight: bold;\n"
"    padding: 20px;\n"
"    border: 2px dashed #D3D3D3;\n"
"    border-radius: 8px;\n"
"    background-color: #F0F0F0;\n"
"}\n"
"\n"
"\n"
"\n"
"\n"
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
        icon.addFile(QString::fromUtf8(":/blueIcons/resources/icons/check-square.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        taskList->setIcon(icon);
        taskList->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(taskList);

        addTaskButton = new QPushButton(frame_4);
        addTaskButton->setObjectName("addTaskButton");
        addTaskButton->setFont(font1);
        addTaskButton->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/blueIcons/resources/icons/plus-circle.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        icon3.addFile(QString::fromUtf8(":/blueIcons/resources/icons/folder-minus1.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        categorybtn->setIcon(icon3);
        categorybtn->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(categorybtn);

        statisticsbtn = new QPushButton(frame_4);
        statisticsbtn->setObjectName("statisticsbtn");
        statisticsbtn->setMaximumSize(QSize(250, 16777215));
        statisticsbtn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/blueIcons/resources/icons/bar-chart.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        statisticsbtn->setIcon(icon4);
        statisticsbtn->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(statisticsbtn);

        todayTask = new QPushButton(frame_4);
        todayTask->setObjectName("todayTask");
        todayTask->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/blueIcons/resources/icons/tag1.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        todayTask->setIcon(icon5);
        todayTask->setIconSize(QSize(24, 24));

        verticalLayout_6->addWidget(todayTask);


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
        widget->setStyleSheet(QString::fromUtf8("#menuBtn:hover {\n"
"    background-color: #f5f9fc;\n"
"    border-color: #2596be;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        menuBtn = new QPushButton(widget);
        menuBtn->setObjectName("menuBtn");
        menuBtn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/blueIcons/resources/icons/arrow-left.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
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
        notifi_btn = new QPushButton(widget_4);
        notifi_btn->setObjectName("notifi_btn");
        notifi_btn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        notifi_btn->setStyleSheet(QString::fromUtf8("QPushButton { border: none; background: transparent; }\n"
"QPushButton:hover { background: #ffebee; border-radius: 8px; }\n"
" "));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/blueIcons/resources/icons/bell.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        notifi_btn->setIcon(icon7);
        notifi_btn->setIconSize(QSize(25, 25));

        horizontalLayout_6->addWidget(notifi_btn);


        horizontalLayout_2->addWidget(widget_4, 0, Qt::AlignmentFlag::AlignRight);


        verticalLayout->addWidget(headerFrame, 0, Qt::AlignmentFlag::AlignTop);

        stackedWidget = new QStackedWidget(mainBody);
        stackedWidget->setObjectName("stackedWidget");
        sizePolicy1.setHeightForWidth(stackedWidget->sizePolicy().hasHeightForWidth());
        stackedWidget->setSizePolicy(sizePolicy1);
        calendarPage = new QWidget();
        calendarPage->setObjectName("calendarPage");
        calendarPage->setStyleSheet(QString::fromUtf8("QCalendarWidget {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #e0e7ee;\n"
"    border-radius: 12px;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton {\n"
"    background-color: #2596be;\n"
"    color: white;\n"
"    border-radius: 6px;\n"
"    padding: 5px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QCalendarWidget QToolButton:hover {\n"
"    background-color: #1a7a99;\n"
"}\n"
"\n"
"QCalendarWidget QMenu {\n"
"    background-color: white;\n"
"    border: 2px solid #e0e7ee;\n"
"}\n"
"\n"
"QCalendarWidget QSpinBox {\n"
"    background-color: white;\n"
"    border: 1px solid #e0e7ee;\n"
"    border-radius: 4px;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:enabled {\n"
"    font-size: 13px;\n"
"    background-color: white;\n"
"    selection-background-color: #2596be;\n"
"    selection-color: white;\n"
"}\n"
"\n"
"QCalendarWidget QAbstractItemView:disabled {\n"
"    color: #bdc3c7;\n"
"}\n"
""));
        horizontalLayout_8 = new QHBoxLayout(calendarPage);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        widget_10 = new QWidget(calendarPage);
        widget_10->setObjectName("widget_10");
        verticalLayout_21 = new QVBoxLayout(widget_10);
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setObjectName("verticalLayout_21");
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        widget_11 = new QWidget(widget_10);
        widget_11->setObjectName("widget_11");
        horizontalLayout_19 = new QHBoxLayout(widget_11);
        horizontalLayout_19->setObjectName("horizontalLayout_19");
        calendarWidget = new QCalendarWidget(widget_11);
        calendarWidget->setObjectName("calendarWidget");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy2);

        horizontalLayout_19->addWidget(calendarWidget);

        widget_12 = new QWidget(widget_11);
        widget_12->setObjectName("widget_12");
        sizePolicy1.setHeightForWidth(widget_12->sizePolicy().hasHeightForWidth());
        widget_12->setSizePolicy(sizePolicy1);
        QFont font4;
        font4.setWeight(QFont::ExtraLight);
        widget_12->setFont(font4);
        verticalLayout_10 = new QVBoxLayout(widget_12);
        verticalLayout_10->setObjectName("verticalLayout_10");
        frame_5 = new QFrame(widget_12);
        frame_5->setObjectName("frame_5");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(frame_5->sizePolicy().hasHeightForWidth());
        frame_5->setSizePolicy(sizePolicy3);
        frame_5->setFrameShape(QFrame::Shape::StyledPanel);
        frame_5->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_9 = new QHBoxLayout(frame_5);
        horizontalLayout_9->setSpacing(9);
        horizontalLayout_9->setObjectName("horizontalLayout_9");
        horizontalLayout_9->setContentsMargins(9, 9, 9, 9);
        label_4 = new QLabel(frame_5);
        label_4->setObjectName("label_4");

        horizontalLayout_9->addWidget(label_4);

        label_3 = new QLabel(frame_5);
        label_3->setObjectName("label_3");

        horizontalLayout_9->addWidget(label_3);

        label_5 = new QLabel(frame_5);
        label_5->setObjectName("label_5");

        horizontalLayout_9->addWidget(label_5);

        label_6 = new QLabel(frame_5);
        label_6->setObjectName("label_6");

        horizontalLayout_9->addWidget(label_6);


        verticalLayout_10->addWidget(frame_5, 0, Qt::AlignmentFlag::AlignTop);

        frame_6 = new QFrame(widget_12);
        frame_6->setObjectName("frame_6");
        sizePolicy3.setHeightForWidth(frame_6->sizePolicy().hasHeightForWidth());
        frame_6->setSizePolicy(sizePolicy3);
        frame_6->setFrameShape(QFrame::Shape::StyledPanel);
        frame_6->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_21 = new QHBoxLayout(frame_6);
        horizontalLayout_21->setSpacing(9);
        horizontalLayout_21->setObjectName("horizontalLayout_21");
        label_7 = new QLabel(frame_6);
        label_7->setObjectName("label_7");

        horizontalLayout_21->addWidget(label_7);

        label_8 = new QLabel(frame_6);
        label_8->setObjectName("label_8");

        horizontalLayout_21->addWidget(label_8);


        verticalLayout_10->addWidget(frame_6, 0, Qt::AlignmentFlag::AlignTop);


        horizontalLayout_19->addWidget(widget_12);


        verticalLayout_21->addWidget(widget_11);

        calendarTaskList = new QListWidget(widget_10);
        calendarTaskList->setObjectName("calendarTaskList");

        verticalLayout_21->addWidget(calendarTaskList);


        horizontalLayout_8->addWidget(widget_10);

        stackedWidget->addWidget(calendarPage);
        categoryListPage = new QWidget();
        categoryListPage->setObjectName("categoryListPage");
        QSizePolicy sizePolicy4(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(categoryListPage->sizePolicy().hasHeightForWidth());
        categoryListPage->setSizePolicy(sizePolicy4);
        verticalLayout_14 = new QVBoxLayout(categoryListPage);
        verticalLayout_14->setSpacing(0);
        verticalLayout_14->setObjectName("verticalLayout_14");
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_13 = new QVBoxLayout();
        verticalLayout_13->setObjectName("verticalLayout_13");
        backCatetorybtn = new QPushButton(categoryListPage);
        backCatetorybtn->setObjectName("backCatetorybtn");
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/blueIcons/resources/icons/align-justify.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        backCatetorybtn->setIcon(icon8);
        backCatetorybtn->setIconSize(QSize(24, 24));

        verticalLayout_13->addWidget(backCatetorybtn);

        categoryListcontainer = new QWidget(categoryListPage);
        categoryListcontainer->setObjectName("categoryListcontainer");

        verticalLayout_13->addWidget(categoryListcontainer);


        verticalLayout_14->addLayout(verticalLayout_13);

        stackedWidget->addWidget(categoryListPage);
        categoryPage = new QWidget();
        categoryPage->setObjectName("categoryPage");
        sizePolicy2.setHeightForWidth(categoryPage->sizePolicy().hasHeightForWidth());
        categoryPage->setSizePolicy(sizePolicy2);
        verticalLayout_12 = new QVBoxLayout(categoryPage);
        verticalLayout_12->setObjectName("verticalLayout_12");
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setObjectName("verticalLayout_11");
        headerCategory = new QFrame(categoryPage);
        headerCategory->setObjectName("headerCategory");
        sizePolicy4.setHeightForWidth(headerCategory->sizePolicy().hasHeightForWidth());
        headerCategory->setSizePolicy(sizePolicy4);
        headerCategory->setFrameShape(QFrame::Shape::StyledPanel);
        headerCategory->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_17 = new QHBoxLayout(headerCategory);
        horizontalLayout_17->setObjectName("horizontalLayout_17");
        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName("horizontalLayout_14");
        addCategorybtn = new QPushButton(headerCategory);
        addCategorybtn->setObjectName("addCategorybtn");
        addCategorybtn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/blueIcons/resources/icons/plus.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        addCategorybtn->setIcon(icon9);
        addCategorybtn->setIconSize(QSize(24, 24));

        horizontalLayout_14->addWidget(addCategorybtn, 0, Qt::AlignmentFlag::AlignLeft);


        horizontalLayout_17->addLayout(horizontalLayout_14);


        verticalLayout_11->addWidget(headerCategory, 0, Qt::AlignmentFlag::AlignBottom);

        categoryListWidget = new QListWidget(categoryPage);
        categoryListWidget->setObjectName("categoryListWidget");
        categoryListWidget->setStyleSheet(QString::fromUtf8("QListWidget { background: #fefeff; border: none; }\n"
"      QListWidget::item { padding: 6px; margin: 4px 8px; border-radius: 10px; }\n"
"      QListWidget::item:hover { background: #f1f3f5; }\n"
"      QListWidget::item:selected { background: #e3f2fd; }"));
        categoryListWidget->setResizeMode(QListView::ResizeMode::Adjust);
        categoryListWidget->setSpacing(8);

        verticalLayout_11->addWidget(categoryListWidget);


        verticalLayout_12->addLayout(verticalLayout_11);

        stackedWidget->addWidget(categoryPage);
        statisticsPage = new QWidget();
        statisticsPage->setObjectName("statisticsPage");
        verticalLayout_2 = new QVBoxLayout(statisticsPage);
        verticalLayout_2->setObjectName("verticalLayout_2");
        scrollArea = new QScrollArea(statisticsPage);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 835, 524));
        verticalLayout_18 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_18->setObjectName("verticalLayout_18");
        filterGroup = new QGroupBox(scrollAreaWidgetContents);
        filterGroup->setObjectName("filterGroup");
        filterGroup->setStyleSheet(QString::fromUtf8("QComboBox {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #e0e7ee;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    min-height: 32px;\n"
"    font-size: 13px;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QComboBox:hover {\n"
"    border-color: #2596be;\n"
"}\n"
"\n"
"QComboBox:focus {\n"
"    border-color: #2596be;\n"
"    background-color: #f8fcfe;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"}\n"
"\n"
"QComboBox::down-arrow {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #2596be;\n"
"    border-radius: 8px;\n"
"    selection-background-color: #e3f2fd;\n"
"    selection-color: #1976d2;\n"
"    padding: 4px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item {\n"
"    padding: 8px 12px;\n"
"    border-radius: 4px;\n"
"    min-height: 30px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView::item:hover {\n"
"    background-color: #f0f7fc;\n"
"}\n"
"\n"
"\n"
""
                        "\n"
"QDateEdit {\n"
"    background-color: #ffffff;\n"
"    border: 2px solid #e0e7ee;\n"
"    border-radius: 8px;\n"
"    padding: 8px 12px;\n"
"    min-height: 32px;\n"
"    font-size: 13px;\n"
"    color: #2c3e50;\n"
"}\n"
"\n"
"QDateEdit:hover {\n"
"    border-color: #2596be;\n"
"    box-shadow: 0 2px 8px rgba(37, 150, 190, 0.15);\n"
"}\n"
"\n"
"QDateEdit:focus {\n"
"    border-color: #2596be;\n"
"    background-color: #f8fcfe;\n"
"}\n"
"\n"
"QDateEdit::drop-down {\n"
"    border: none;\n"
"    width: 30px;\n"
"}\n"
"\n"
"QDateEdit::down-arrow {\n"
"    width: 16px;\n"
"    height: 16px;\n"
"}\n"
"\n"
"QDateEdit::up-button, QDateEdit::down-button {\n"
"    background-color: transparent;\n"
"    border: none;\n"
"    width: 20px;\n"
"}\n"
"\n"
"QDateEdit::up-button:hover, QDateEdit::down-button:hover {\n"
"    background-color: #e3f2fd;\n"
"    border-radius: 4px;\n"
"}\n"
""));
        horizontalLayout_18 = new QHBoxLayout(filterGroup);
        horizontalLayout_18->setObjectName("horizontalLayout_18");
        comboFilterTime = new QComboBox(filterGroup);
        comboFilterTime->setObjectName("comboFilterTime");
        comboFilterTime->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        comboFilterTime->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_18->addWidget(comboFilterTime);

        dateFrom = new QDateEdit(filterGroup);
        dateFrom->setObjectName("dateFrom");
        dateFrom->setCalendarPopup(true);
        dateFrom->setDate(QDate(2025, 1, 1));

        horizontalLayout_18->addWidget(dateFrom);

        dateTo = new QDateEdit(filterGroup);
        dateTo->setObjectName("dateTo");
        dateTo->setCalendarPopup(true);
        dateTo->setDate(QDate(2025, 1, 1));

        horizontalLayout_18->addWidget(dateTo);


        verticalLayout_18->addWidget(filterGroup);

        widget_5 = new QWidget(scrollAreaWidgetContents);
        widget_5->setObjectName("widget_5");
        QSizePolicy sizePolicy5(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(widget_5->sizePolicy().hasHeightForWidth());
        widget_5->setSizePolicy(sizePolicy5);
        horizontalLayout_15 = new QHBoxLayout(widget_5);
        horizontalLayout_15->setObjectName("horizontalLayout_15");
        horizontalLayout_15->setContentsMargins(0, 0, 0, 0);
        widget_6 = new QWidget(widget_5);
        widget_6->setObjectName("widget_6");
        sizePolicy5.setHeightForWidth(widget_6->sizePolicy().hasHeightForWidth());
        widget_6->setSizePolicy(sizePolicy5);
        verticalLayout_8 = new QVBoxLayout(widget_6);
        verticalLayout_8->setObjectName("verticalLayout_8");
        label_10 = new QLabel(widget_6);
        label_10->setObjectName("label_10");

        verticalLayout_8->addWidget(label_10, 0, Qt::AlignmentFlag::AlignTop);

        numberAllTask = new QLabel(widget_6);
        numberAllTask->setObjectName("numberAllTask");
        numberAllTask->setFont(font);

        verticalLayout_8->addWidget(numberAllTask, 0, Qt::AlignmentFlag::AlignTop);


        horizontalLayout_15->addWidget(widget_6, 0, Qt::AlignmentFlag::AlignTop);

        widget_7 = new QWidget(widget_5);
        widget_7->setObjectName("widget_7");
        sizePolicy5.setHeightForWidth(widget_7->sizePolicy().hasHeightForWidth());
        widget_7->setSizePolicy(sizePolicy5);
        verticalLayout_9 = new QVBoxLayout(widget_7);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_12 = new QLabel(widget_7);
        label_12->setObjectName("label_12");

        verticalLayout_9->addWidget(label_12, 0, Qt::AlignmentFlag::AlignTop);

        numberCompletedTask = new QLabel(widget_7);
        numberCompletedTask->setObjectName("numberCompletedTask");
        numberCompletedTask->setFont(font);

        verticalLayout_9->addWidget(numberCompletedTask, 0, Qt::AlignmentFlag::AlignTop);


        horizontalLayout_15->addWidget(widget_7, 0, Qt::AlignmentFlag::AlignTop);

        widget_8 = new QWidget(widget_5);
        widget_8->setObjectName("widget_8");
        sizePolicy5.setHeightForWidth(widget_8->sizePolicy().hasHeightForWidth());
        widget_8->setSizePolicy(sizePolicy5);
        verticalLayout_16 = new QVBoxLayout(widget_8);
        verticalLayout_16->setObjectName("verticalLayout_16");
        label_14 = new QLabel(widget_8);
        label_14->setObjectName("label_14");

        verticalLayout_16->addWidget(label_14, 0, Qt::AlignmentFlag::AlignTop);

        numberPendingTask = new QLabel(widget_8);
        numberPendingTask->setObjectName("numberPendingTask");
        numberPendingTask->setFont(font);

        verticalLayout_16->addWidget(numberPendingTask, 0, Qt::AlignmentFlag::AlignTop);


        horizontalLayout_15->addWidget(widget_8, 0, Qt::AlignmentFlag::AlignTop);

        widget_9 = new QWidget(widget_5);
        widget_9->setObjectName("widget_9");
        sizePolicy5.setHeightForWidth(widget_9->sizePolicy().hasHeightForWidth());
        widget_9->setSizePolicy(sizePolicy5);
        verticalLayout_17 = new QVBoxLayout(widget_9);
        verticalLayout_17->setObjectName("verticalLayout_17");
        label_16 = new QLabel(widget_9);
        label_16->setObjectName("label_16");

        verticalLayout_17->addWidget(label_16, 0, Qt::AlignmentFlag::AlignTop);

        numberProgress = new QLabel(widget_9);
        numberProgress->setObjectName("numberProgress");
        numberProgress->setFont(font);

        verticalLayout_17->addWidget(numberProgress, 0, Qt::AlignmentFlag::AlignTop);


        horizontalLayout_15->addWidget(widget_9, 0, Qt::AlignmentFlag::AlignTop);


        verticalLayout_18->addWidget(widget_5);

        widget_2 = new QWidget(scrollAreaWidgetContents);
        widget_2->setObjectName("widget_2");
        verticalLayout_20 = new QVBoxLayout(widget_2);
        verticalLayout_20->setObjectName("verticalLayout_20");
        statisticsLayout_1 = new QWidget(widget_2);
        statisticsLayout_1->setObjectName("statisticsLayout_1");
        sizePolicy.setHeightForWidth(statisticsLayout_1->sizePolicy().hasHeightForWidth());
        statisticsLayout_1->setSizePolicy(sizePolicy);
        verticalLayout_19 = new QVBoxLayout(statisticsLayout_1);
        verticalLayout_19->setObjectName("verticalLayout_19");

        verticalLayout_20->addWidget(statisticsLayout_1);

        statisticsLayout_2 = new QWidget(widget_2);
        statisticsLayout_2->setObjectName("statisticsLayout_2");
        sizePolicy4.setHeightForWidth(statisticsLayout_2->sizePolicy().hasHeightForWidth());
        statisticsLayout_2->setSizePolicy(sizePolicy4);
        horizontalLayout_20 = new QHBoxLayout(statisticsLayout_2);
        horizontalLayout_20->setObjectName("horizontalLayout_20");

        verticalLayout_20->addWidget(statisticsLayout_2);

        statisticsLayout_3 = new QWidget(widget_2);
        statisticsLayout_3->setObjectName("statisticsLayout_3");
        sizePolicy1.setHeightForWidth(statisticsLayout_3->sizePolicy().hasHeightForWidth());
        statisticsLayout_3->setSizePolicy(sizePolicy1);
        horizontalLayout_22 = new QHBoxLayout(statisticsLayout_3);
        horizontalLayout_22->setObjectName("horizontalLayout_22");

        verticalLayout_20->addWidget(statisticsLayout_3);


        verticalLayout_18->addWidget(widget_2);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout_2->addWidget(scrollArea);

        stackedWidget->addWidget(statisticsPage);
        todayPage = new QWidget();
        todayPage->setObjectName("todayPage");
        horizontalLayout_16 = new QHBoxLayout(todayPage);
        horizontalLayout_16->setObjectName("horizontalLayout_16");
        todayListcontainer = new QWidget(todayPage);
        todayListcontainer->setObjectName("todayListcontainer");
        QFont font5;
        font5.setBold(true);
        todayListcontainer->setFont(font5);
        todayListcontainer->setStyleSheet(QString::fromUtf8("backgroud-color : #2596be;"));
        verticalLayout_15 = new QVBoxLayout(todayListcontainer);
        verticalLayout_15->setObjectName("verticalLayout_15");
        stackedWidget_2 = new QStackedWidget(todayListcontainer);
        stackedWidget_2->setObjectName("stackedWidget_2");
        todayTaskList = new QWidget();
        todayTaskList->setObjectName("todayTaskList");
        stackedWidget_2->addWidget(todayTaskList);
        noLabelPage = new QWidget();
        noLabelPage->setObjectName("noLabelPage");
        noLabelPage->setStyleSheet(QString::fromUtf8(""));
        noTaskLabel = new QLabel(noLabelPage);
        noTaskLabel->setObjectName("noTaskLabel");
        noTaskLabel->setGeometry(QRect(120, 20, 441, 91));
        noTaskLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget_2->addWidget(noLabelPage);

        verticalLayout_15->addWidget(stackedWidget_2);


        horizontalLayout_16->addWidget(todayListcontainer);

        stackedWidget->addWidget(todayPage);
        listPage = new QWidget();
        listPage->setObjectName("listPage");
        verticalLayout_5 = new QVBoxLayout(listPage);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        frame_7 = new QFrame(listPage);
        frame_7->setObjectName("frame_7");
        sizePolicy5.setHeightForWidth(frame_7->sizePolicy().hasHeightForWidth());
        frame_7->setSizePolicy(sizePolicy5);
        frame_7->setStyleSheet(QString::fromUtf8("\n"
"\n"
"QPushButton#filterListPagebtn:hover {\n"
"    background-color: #e3f2fd;\n"
"    border-color: #2596be;\n"
"}\n"
""));
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
        horizontalLayout_11->setSpacing(10);
        horizontalLayout_11->setObjectName("horizontalLayout_11");
        allTask = new QPushButton(frame_10);
        allTask->setObjectName("allTask");
        allTask->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/blueIcons/resources/icons/clipboard.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        allTask->setIcon(icon10);
        allTask->setIconSize(QSize(24, 24));

        horizontalLayout_11->addWidget(allTask, 0, Qt::AlignmentFlag::AlignHCenter|Qt::AlignmentFlag::AlignVCenter);

        taskCompleted = new QPushButton(frame_10);
        taskCompleted->setObjectName("taskCompleted");
        taskCompleted->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/blueIcons/resources/icons/check-circle.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        taskCompleted->setIcon(icon11);
        taskCompleted->setIconSize(QSize(24, 24));

        horizontalLayout_11->addWidget(taskCompleted, 0, Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignVCenter);


        horizontalLayout_10->addWidget(frame_10, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        frame_9 = new QFrame(frame_7);
        frame_9->setObjectName("frame_9");
        frame_9->setFrameShape(QFrame::Shape::StyledPanel);
        frame_9->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_13 = new QHBoxLayout(frame_9);
        horizontalLayout_13->setObjectName("horizontalLayout_13");
        comboBox = new QComboBox(frame_9);
        comboBox->setObjectName("comboBox");

        horizontalLayout_13->addWidget(comboBox, 0, Qt::AlignmentFlag::AlignTop);


        horizontalLayout_10->addWidget(frame_9, 0, Qt::AlignmentFlag::AlignVCenter);

        filterListPagebtn = new QPushButton(frame_7);
        filterListPagebtn->setObjectName("filterListPagebtn");
        QSizePolicy sizePolicy6(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(filterListPagebtn->sizePolicy().hasHeightForWidth());
        filterListPagebtn->setSizePolicy(sizePolicy6);
        filterListPagebtn->setMinimumSize(QSize(24, 24));
        filterListPagebtn->setFocusPolicy(Qt::FocusPolicy::NoFocus);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/blueIcons/resources/icons/filter.svg"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        filterListPagebtn->setIcon(icon12);
        filterListPagebtn->setIconSize(QSize(24, 24));

        horizontalLayout_10->addWidget(filterListPagebtn);

        dateFrom1 = new QDateEdit(frame_7);
        dateFrom1->setObjectName("dateFrom1");
        dateFrom1->setCalendarPopup(true);
        dateFrom1->setDate(QDate(2025, 11, 1));

        horizontalLayout_10->addWidget(dateFrom1);

        dateTo1 = new QDateEdit(frame_7);
        dateTo1->setObjectName("dateTo1");
        dateTo1->setCalendarPopup(true);
        dateTo1->setDate(QDate(2025, 11, 1));

        horizontalLayout_10->addWidget(dateTo1);


        verticalLayout_5->addWidget(frame_7);

        frame_8 = new QFrame(listPage);
        frame_8->setObjectName("frame_8");
        frame_8->setStyleSheet(QString::fromUtf8(""));
        frame_8->setFrameShape(QFrame::Shape::StyledPanel);
        frame_8->setFrameShadow(QFrame::Shadow::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame_8);
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName("horizontalLayout_12");
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        taskListcontainer = new QWidget(frame_8);
        taskListcontainer->setObjectName("taskListcontainer");

        horizontalLayout_12->addWidget(taskListcontainer);


        verticalLayout_5->addWidget(frame_8);

        stackedWidget->addWidget(listPage);

        verticalLayout->addWidget(stackedWidget);


        horizontalLayout->addWidget(mainBody);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1053, 33));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName("toolBar");
        MainWindow->addToolBar(Qt::ToolBarArea::TopToolBarArea, toolBar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Task Manager", nullptr));
        taskList->setText(QCoreApplication::translate("MainWindow", "Task List", nullptr));
        addTaskButton->setText(QCoreApplication::translate("MainWindow", " Add Task", nullptr));
        calendarList->setText(QCoreApplication::translate("MainWindow", "Calendar", nullptr));
        categorybtn->setText(QCoreApplication::translate("MainWindow", "Category", nullptr));
        statisticsbtn->setText(QCoreApplication::translate("MainWindow", "Statistics", nullptr));
        todayTask->setText(QCoreApplication::translate("MainWindow", "Today", nullptr));
        menuBtn->setText(QString());
        appHeader->setText(QCoreApplication::translate("MainWindow", "Dashboard", nullptr));
        label_2->setText(QString());
        searchBar->setPlaceholderText(QCoreApplication::translate("MainWindow", "Search Something...", nullptr));
        notifi_btn->setText(QString());
        label_4->setText(QCoreApplication::translate("MainWindow", "\304\220\341\273\231 \306\260u ti\303\252n :", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\360\237\237\242 Th\341\272\245p", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\360\237\237\241 Trung b\303\254nh", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\360\237\224\264 Cao", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "\342\217\263: Ch\306\260a ho\303\240n th\303\240nh", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\342\234\205 : Ho\303\240n th\303\240nh", nullptr));
        backCatetorybtn->setText(QString());
#if QT_CONFIG(tooltip)
        categoryPage->setToolTip(QCoreApplication::translate("MainWindow", "<html><head/><body><p><br/></p></body></html>", nullptr));
#endif // QT_CONFIG(tooltip)
        addCategorybtn->setText(QCoreApplication::translate("MainWindow", "Th\303\252m Danh M\341\273\245c", nullptr));
        filterGroup->setTitle(QString());
        label_10->setText(QCoreApplication::translate("MainWindow", "ALL TASKS", nullptr));
        numberAllTask->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "COMPLETED", nullptr));
        numberCompletedTask->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "PENDING", nullptr));
        numberPendingTask->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "PROGRESS", nullptr));
        numberProgress->setText(QCoreApplication::translate("MainWindow", "0%", nullptr));
        noTaskLabel->setText(QCoreApplication::translate("MainWindow", "Kh\303\264ng c\303\263 Task cho ng\303\240y h\303\264m nay!", nullptr));
        allTask->setText(QCoreApplication::translate("MainWindow", "All Task", nullptr));
        taskCompleted->setText(QCoreApplication::translate("MainWindow", "Completed Tasks", nullptr));
        filterListPagebtn->setText(QString());
        toolBar->setWindowTitle(QCoreApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
