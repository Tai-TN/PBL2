set(CMAKE_PREFIX_PATH "C:/Qt/6.9.2/mingw_64/lib/cmake")

cmake_minimum_required(VERSION 3.19)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
project(PBL2 LANGUAGES CXX)

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets Charts)

qt_standard_project_setup()
qt_add_resources(APP_RESOURCES resources.qrc)

qt_add_executable(PBL2
    WIN32 MACOSX_BUNDLE
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
    Task.cpp
    Task.h
    heap_manager.cpp
    heap_manager.h
    Trie.h
    Trie.cpp
    AdvancedTaskDialog.h
    AdvancedTaskDialog.cpp
    TaskItemQwidget.h
    TaskItemQwidget.cpp
    TaskListWidget.h
    TaskListWidget.cpp
    CategoryItemWidget.h
    CategoryItemWidget.cpp
    ${APP_RESOURCES}  
)
target_link_libraries(PBL2
    PRIVATE
        Qt::Core
        Qt::Widgets
        Qt::Charts
)

include(GNUInstallDirs)

install(TARGETS PBL2
    BUNDLE  DESTINATION .
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
)

qt_generate_deploy_app_script(
    TARGET PBL2
    OUTPUT_SCRIPT deploy_script
    NO_UNSUPPORTED_PLATFORM_ERROR
)
install(SCRIPT ${deploy_script})