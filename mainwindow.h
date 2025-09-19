#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include "heap_manager.h"
#include <string>
#include <iostream>

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
    //void showTask(){};
    void updateTaskList();
private:
    // QListWidget *taskList;
    // QPushButton *addButton;
    void LoadFile(const std::string&, HeapManager&);
private:
    Ui::MainWindow *ui;
    HeapManager manager;
};
#endif // MAINWINDOW_H