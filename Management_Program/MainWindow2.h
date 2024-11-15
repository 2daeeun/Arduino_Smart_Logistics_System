// MainWindow2.h
#ifndef MAINWINDOW2_H
#define MAINWINDOW2_H

#include <QMainWindow>
#include <QTableWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QHeaderView>
#include <QInputDialog>
#include <QMessageBox>

class MainWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow2(QWidget *parent = nullptr);

private slots:
    void sortByColumn(int column);
    void addItem();
    void removeItem();
    void editItem();

private:
    void setupWidgets();
    void populateTable();

    QTableWidget *tableWidget;
    QPushButton *btnAddItem;
    QPushButton *btnRemoveItem;
    QPushButton *btnEditItem;
};

#endif // MAINWINDOW2_H
