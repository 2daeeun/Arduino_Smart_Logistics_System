#include "MainWindow1.h"
#include "MainWindow2.h"
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QByteArray>

MainWindow1::MainWindow1(QWidget *parent)
    : QMainWindow(parent), mainWindow2(nullptr)
{
    setupWidgets(); // 위젯들을 설정하는 함수 호출
    setupFileWatcher(); // 파일 변경 감지 기능 설정
}

void MainWindow1::setupWidgets()
{
    // 중앙 위젯 설정
    centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    verticalLayout = new QVBoxLayout(centralWidget);

    // 상단 위젯 설정
    topWidget = new QWidget(centralWidget);
    topLayout = new QHBoxLayout(topWidget);

    // 프로그램 이름 라벨 생성 및 레이아웃에 추가
    programNameLabel = new QLabel("스마트 물류시스템 관리 프로그램", topWidget);
    topLayout->addWidget(programNameLabel);

    topWidget->setLayout(topLayout);
    verticalLayout->addWidget(topWidget);

    // 사이드 위젯 설정
    sideWidget = new QWidget(centralWidget);
    sideLayout = new QVBoxLayout(sideWidget);

    // 대시보드, 보고서 생성 버튼 생성 및 레이아웃에 추가
    btnDashboard = new QPushButton("Dashboard", sideWidget);
    btnGenerateReport = new QPushButton("Generate Report", sideWidget);

    sideLayout->addWidget(btnDashboard);
    sideLayout->addWidget(btnGenerateReport);

    sideWidget->setLayout(sideLayout);
    verticalLayout->addWidget(sideWidget);

    // 콘텐츠 위젯 설정
    contentWidget = new QWidget(centralWidget);
    contentLayout = new QVBoxLayout(contentWidget);

    // 관리 상자 제목 라벨 생성 및 중앙 정렬 후 레이아웃에 추가
    contentTitleLabel = new QLabel("Manage Boxes", contentWidget);
    contentTitleLabel->setAlignment(Qt::AlignCenter);
    contentLayout->addWidget(contentTitleLabel);

    boxesGridLayout = new QGridLayout();

    // 작은 상자 그룹 생성 및 레이아웃에 추가
    smallBoxGroup = new QGroupBox("Small Box", contentWidget);
    QVBoxLayout *smallBoxLayout = new QVBoxLayout(smallBoxGroup);
    listSmallBox = new QListWidget(smallBoxGroup);
    smallBoxLayout->addWidget(listSmallBox);
    smallBoxGroup->setLayout(smallBoxLayout);

    // 중간 상자 그룹 생성 및 레이아웃에 추가
    mediumBoxGroup = new QGroupBox("Medium Box", contentWidget);
    QVBoxLayout *mediumBoxLayout = new QVBoxLayout(mediumBoxGroup);
    listMediumBox = new QListWidget(mediumBoxGroup);
    mediumBoxLayout->addWidget(listMediumBox);
    mediumBoxGroup->setLayout(mediumBoxLayout);

    // 큰 상자 그룹 생성 및 레이아웃에 추가
    largeBoxGroup = new QGroupBox("Large Box", contentWidget);
    QVBoxLayout *largeBoxLayout = new QVBoxLayout(largeBoxGroup);
    listLargeBox = new QListWidget(largeBoxGroup);
    largeBoxLayout->addWidget(listLargeBox);
    largeBoxGroup->setLayout(largeBoxLayout);

    boxesGridLayout->addWidget(smallBoxGroup, 0, 0);
    boxesGridLayout->addWidget(mediumBoxGroup, 0, 1);
    boxesGridLayout->addWidget(largeBoxGroup, 0, 2);

    contentLayout->addLayout(boxesGridLayout);

    // 버튼 레이아웃 설정
    boxButtonLayout = new QHBoxLayout();

    // 항목 추가, 삭제 및 새로고침 버튼 생성 후 레이아웃에 추가
    btnAddItem = new QPushButton("Add Item", contentWidget);
    btnRemoveItem = new QPushButton("Remove Item", contentWidget);
    btnRefresh = new QPushButton("새로고침", contentWidget);  // 새로고침 버튼 추가

    boxButtonLayout->addStretch();
    boxButtonLayout->addWidget(btnAddItem);
    boxButtonLayout->addWidget(btnRemoveItem);
    boxButtonLayout->addWidget(btnRefresh);  // 새로고침 버튼 레이아웃에 추가
    boxButtonLayout->addStretch();

    contentLayout->addLayout(boxButtonLayout);

    contentWidget->setLayout(contentLayout);
    verticalLayout->addWidget(contentWidget);

    // 대시보드 버튼 클릭 시 onDashboardButtonClicked 슬롯 함수와 연결
    connect(btnDashboard, &QPushButton::clicked, this, &MainWindow1::onDashboardButtonClicked);

    // 새로고침 버튼 클릭 시 onRefreshButtonClicked 슬롯 함수와 연결
    connect(btnRefresh, &QPushButton::clicked, this, &MainWindow1::onRefreshButtonClicked);
}

// 파일 변경 감지 설정 함수
void MainWindow1::setupFileWatcher()
{
    fileWatcher = new QFileSystemWatcher(this);
    fileWatcher->addPath("C:/Users/ilove/Desktop/Arduino_Smart_Logistics_System/Management_Program/rfid_details.csv");
    connect(fileWatcher, &QFileSystemWatcher::fileChanged, this, &MainWindow1::onFileChanged);
    // 초기 파일 로드
    loadRfidDetails();
}
// 파일 변경 시 호출되는 슬롯 함수
void MainWindow1::onFileChanged(const QString &/*path*/)
{
    // QMessageBox::information(this, "File Changed", "rfid_details.csv 파일이 변경되었습니다.");
    loadRfidDetails();
}
// rfid_details.csv 파일을 읽어 상자에 이름을 표시하는 함수
void MainWindow1::loadRfidDetails()
{
    // 각 리스트 초기화
    listSmallBox->clear();
    listMediumBox->clear();
    listLargeBox->clear();
    QFile file("C:/Users/ilove/Desktop/Arduino_Smart_Logistics_System/Management_Program/rfid_details.csv");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "File Error", "rfid_details.csv 파일을 열 수 없습니다.");
        return;
    }
    // QByteArray를 사용하여 UTF-8로 파일 읽기
    QByteArray fileContent = file.readAll();
    QString fileText = QString::fromUtf8(fileContent);
    QTextStream in(&fileText);
    // CSV 파일을 읽어서 size에 따라 이름을 리스트에 추가
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList fields = line.split(',');
        if (fields.size() >= 3) { // uid, size, name 등 최소한의 데이터가 있는지 확인
            QString size = fields.at(1).trimmed();
            QString name = fields.at(2).trimmed();
            if (size == "s") {
                listSmallBox->addItem(name);
            } else if (size == "m") {
                listMediumBox->addItem(name);
            } else if (size == "b") {
                listLargeBox->addItem(name);
            }
        }
    }
    file.close();
}
// 대시보드 버튼 클릭 시 호출되는 슬롯 함수
void MainWindow1::onDashboardButtonClicked()
{
    // MainWindow2 객체가 없으면 새로 생성
    if (!mainWindow2) {
        mainWindow2 = new MainWindow2(this);
    }
    // MainWindow2 표시
    mainWindow2->show();
}
// 새로고침 버튼 클릭 시 호출되는 슬롯 함수
void MainWindow1::onRefreshButtonClicked()
{
    loadRfidDetails();  // rfid_details.csv 파일을 다시 로드
}
