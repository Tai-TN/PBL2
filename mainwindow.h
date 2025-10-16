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
    void editTask();
    void onItemChanged(QTreeWidgetItem *item, int column);
    void onItemClicked(QTreeWidgetItem *item, int column);
    void onCompletedClicked();
    void switchView();
    void onCalendarDateClicked(const QDate& date);
private:

    void LoadFile(const std::string&, HeapManager&);
    void SaveToFile(const std::string&);
private:
    Ui::MainWindow *ui;
    HeapManager manager;
    bool showCompleteTasks = false;
    Trie taskTrie;
    void buildTrie(); // tạo trie từ danh sách task (đọc từ tiêu đề vào)
    bool isListView = true;
};
#endif // MAINWINDOW_H