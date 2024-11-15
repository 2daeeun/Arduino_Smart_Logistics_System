// MainWindow2.cpp
#include "MainWindow2.h"

MainWindow2::MainWindow2(QWidget *parent)
    : QMainWindow(parent)
{
    setupWidgets();
    populateTable();

    // 창 크기를 설정합니다. (예: resize(가로, 세로))
    resize(800, 400);
}

void MainWindow2::setupWidgets()
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    tableWidget = new QTableWidget(centralWidget);
    tableWidget->setColumnCount(6);  // Columns: uid, size, name, sender, receiver, origin
    tableWidget->setHorizontalHeaderLabels({"ID", "uid", "size", "name", "sender", "receiver", "origin"});
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // Buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();
    btnAddItem = new QPushButton("Add Item", centralWidget);
    btnRemoveItem = new QPushButton("Remove Item", centralWidget);
    btnEditItem = new QPushButton("Edit Item", centralWidget);

    buttonLayout->addWidget(btnAddItem);
    buttonLayout->addWidget(btnRemoveItem);
    buttonLayout->addWidget(btnEditItem);

    mainLayout->addWidget(tableWidget);
    mainLayout->addLayout(buttonLayout);

    // Connect signals to slots
    connect(tableWidget->horizontalHeader(), &QHeaderView::sectionClicked, this, &MainWindow2::sortByColumn);
    connect(btnAddItem, &QPushButton::clicked, this, &MainWindow2::addItem);
    connect(btnRemoveItem, &QPushButton::clicked, this, &MainWindow2::removeItem);
    connect(btnEditItem, &QPushButton::clicked, this, &MainWindow2::editItem);
}

void MainWindow2::populateTable()
{
    // Example data: Adding some initial rows
    tableWidget->setRowCount(10);

    // 데이터 추가
    tableWidget->setItem(0, 0, new QTableWidgetItem("0E0B5D18"));
    tableWidget->setItem(0, 1, new QTableWidgetItem("s"));
    tableWidget->setItem(0, 2, new QTableWidgetItem("Naruto"));
    tableWidget->setItem(0, 3, new QTableWidgetItem("Adam"));
    tableWidget->setItem(0, 4, new QTableWidgetItem("Alan"));
    tableWidget->setItem(0, 5, new QTableWidgetItem(""));

    tableWidget->setItem(1, 0, new QTableWidgetItem("EE2A2617"));
    tableWidget->setItem(1, 1, new QTableWidgetItem("m"));
    tableWidget->setItem(1, 2, new QTableWidgetItem("Sasuke"));
    tableWidget->setItem(1, 3, new QTableWidgetItem("Ben"));
    tableWidget->setItem(1, 4, new QTableWidgetItem("Bill"));
    tableWidget->setItem(1, 5, new QTableWidgetItem(""));

    tableWidget->setItem(2, 0, new QTableWidgetItem("EE2DD517"));
    tableWidget->setItem(2, 1, new QTableWidgetItem("b"));
    tableWidget->setItem(2, 2, new QTableWidgetItem("Sakura"));
    tableWidget->setItem(2, 3, new QTableWidgetItem("Amy"));
    tableWidget->setItem(2, 4, new QTableWidgetItem("Anna"));
    tableWidget->setItem(2, 5, new QTableWidgetItem(""));

    tableWidget->setItem(3, 0, new QTableWidgetItem("314"));
    tableWidget->setItem(3, 1, new QTableWidgetItem("s"));
    tableWidget->setItem(3, 2, new QTableWidgetItem("Kakashi"));
    tableWidget->setItem(3, 3, new QTableWidgetItem("Chris"));
    tableWidget->setItem(3, 4, new QTableWidgetItem("Don"));
    tableWidget->setItem(3, 5, new QTableWidgetItem(""));

    tableWidget->setItem(4, 0, new QTableWidgetItem("159"));
    tableWidget->setItem(4, 1, new QTableWidgetItem("m"));
    tableWidget->setItem(4, 2, new QTableWidgetItem("Hinata"));
    tableWidget->setItem(4, 3, new QTableWidgetItem("Dave"));
    tableWidget->setItem(4, 4, new QTableWidgetItem("Eric"));
    tableWidget->setItem(4, 5, new QTableWidgetItem(""));

    tableWidget->setItem(5, 0, new QTableWidgetItem("6535"));
    tableWidget->setItem(5, 1, new QTableWidgetItem("b"));
    tableWidget->setItem(5, 2, new QTableWidgetItem("Luffy"));
    tableWidget->setItem(5, 3, new QTableWidgetItem("Gary"));
    tableWidget->setItem(5, 4, new QTableWidgetItem("Jack"));
    tableWidget->setItem(5, 5, new QTableWidgetItem(""));

    tableWidget->setItem(6, 0, new QTableWidgetItem("89"));
    tableWidget->setItem(6, 1, new QTableWidgetItem("s"));
    tableWidget->setItem(6, 2, new QTableWidgetItem("Zoro"));
    tableWidget->setItem(6, 3, new QTableWidgetItem("Jay"));
    tableWidget->setItem(6, 4, new QTableWidgetItem("Jeff"));
    tableWidget->setItem(6, 5, new QTableWidgetItem(""));

    tableWidget->setItem(7, 0, new QTableWidgetItem("7932"));
    tableWidget->setItem(7, 1, new QTableWidgetItem("m"));
    tableWidget->setItem(7, 2, new QTableWidgetItem("Nami"));
    tableWidget->setItem(7, 3, new QTableWidgetItem("John"));
    tableWidget->setItem(7, 4, new QTableWidgetItem("Matt"));
    tableWidget->setItem(7, 5, new QTableWidgetItem(""));

    tableWidget->setItem(8, 0, new QTableWidgetItem("9805"));
    tableWidget->setItem(8, 1, new QTableWidgetItem("s"));
    tableWidget->setItem(8, 2, new QTableWidgetItem("gallxy"));
    tableWidget->setItem(8, 3, new QTableWidgetItem("Nora"));
    tableWidget->setItem(8, 4, new QTableWidgetItem("Rick"));
    tableWidget->setItem(8, 5, new QTableWidgetItem(""));

    tableWidget->setItem(9, 0, new QTableWidgetItem("521"));
    tableWidget->setItem(9, 1, new QTableWidgetItem("m"));
    tableWidget->setItem(9, 2, new QTableWidgetItem("Hong"));
    tableWidget->setItem(9, 3, new QTableWidgetItem("Sara"));
    tableWidget->setItem(9, 4, new QTableWidgetItem("Tom"));
    tableWidget->setItem(9, 5, new QTableWidgetItem(""));
}

void MainWindow2::sortByColumn(int column)
{
    tableWidget->sortItems(column);
}

void MainWindow2::addItem()
{
    int row = tableWidget->rowCount();
    tableWidget->insertRow(row);

    for (int col = 0; col < tableWidget->columnCount(); ++col)
    {
        tableWidget->setItem(row, col, new QTableWidgetItem("New Data"));
    }
}

void MainWindow2::removeItem()
{
    QList<QTableWidgetItem*> selectedItems = tableWidget->selectedItems();
    if (selectedItems.isEmpty()) return;

    int row = selectedItems.first()->row();
    tableWidget->removeRow(row);
}

void MainWindow2::editItem()
{
    QList<QTableWidgetItem*> selectedItems = tableWidget->selectedItems();
    if (selectedItems.isEmpty()) return;

    QTableWidgetItem *item = selectedItems.first();
    bool ok;
    QString text = QInputDialog::getText(this, "Edit Item", "New value:", QLineEdit::Normal, item->text(), &ok);
    if (ok && !text.isEmpty())
    {
        item->setText(text);
    }
}
