#ifndef MAINWINDOW1_H
#define MAINWINDOW1_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QGroupBox>
#include <QListWidget>
#include <QLabel>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QFileSystemWatcher>  // 파일 변경 감지를 위한 QFileSystemWatcher 포함

class MainWindow2;  // Forward declaration of MainWindow2

class MainWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow1(QWidget *parent = nullptr);

private slots:
    void onDashboardButtonClicked();
    void onFileChanged(const QString &path);  // 파일 변경 시 호출되는 슬롯 함수
    void onRefreshButtonClicked();  // 새로고침 버튼 클릭 슬롯 함수

private:
    void setupWidgets();
    void setupFileWatcher();  // 파일 변경 감지 설정 함수
    void loadRfidDetails();   // rfid_details.csv 파일을 읽어 상자에 이름을 표시하는 함수

    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;

    QWidget *topWidget;
    QHBoxLayout *topLayout;
    QLabel *programNameLabel;

    QWidget *sideWidget;
    QVBoxLayout *sideLayout;
    QPushButton *btnDashboard;
    QPushButton *btnGenerateReport; // Search Items 버튼 제거

    QWidget *contentWidget;
    QVBoxLayout *contentLayout;
    QLabel *contentTitleLabel;
    QGridLayout *boxesGridLayout;
    QGroupBox *smallBoxGroup;
    QListWidget *listSmallBox;
    QGroupBox *mediumBoxGroup;
    QListWidget *listMediumBox;
    QGroupBox *largeBoxGroup;
    QListWidget *listLargeBox;
    QHBoxLayout *boxButtonLayout;
    QPushButton *btnAddItem;
    QPushButton *btnRemoveItem;
    QPushButton *btnRefresh;  // 새로고침 버튼 추가

    MainWindow2 *mainWindow2;

    QFileSystemWatcher *fileWatcher;  // 파일 변경 감지기 포인터
};

#endif // MAINWINDOW1_H
