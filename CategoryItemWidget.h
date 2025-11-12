// CategoryItemWidget.h
#ifndef CATEGORYITEMWIDGET_H
#define CATEGORYITEMWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QMouseEvent>

class CategoryItemWidget : public QWidget {
    Q_OBJECT
public:
    CategoryItemWidget(const QString& name, int taskCount, QWidget* parent = nullptr);

signals:
    void clicked();
    void editRequested();
    void deleteRequested();

protected:
    void mousePressEvent(QMouseEvent* event) override;

private:
    QLabel* m_nameLabel;
    QLabel* m_countLabel;
    QPushButton* m_editBtn;
    QPushButton* m_deleteBtn;
};

#endif