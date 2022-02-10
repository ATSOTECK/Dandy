#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    _ui(new Ui::MainWindow),
    _toolBar(new QToolBar(this)),
    _statusLabel(new QLabel(this)),
    _fsDock(new FSDock(this)),
    _actionRun(new QAction(QIcon(":/res/img/run_white.png"), "Run", this)),
    _actionDebug(new QAction(QIcon(":/res/img/debug_lite.png"), "Debug", this))
{
    _ui->setupUi(this);
    
    setupUI();
}

MainWindow::~MainWindow() {
    delete _ui;
}

void MainWindow::setupUI() {
    QString styleStr;
    QFile *style = new QFile(":/res/styles/style.css");
    if (style->open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in(style);
        styleStr = in.readAll();
    }
    style->close();
    delete style;
    setStyleSheet(styleStr);
    
    addToolBar(Qt::LeftToolBarArea, _toolBar);
    _toolBar->setMovable(false);
    _toolBar->setToolButtonStyle(Qt::ToolButtonIconOnly);
    _toolBar->addAction(_actionRun);
    _toolBar->addAction(_actionDebug);
    
    _statusLabel->setText("1/1: 0  ");
    _statusLabel->setFont(QFont("Monaco"));
    _statusLabel->setStyleSheet("color:#929292;");
    statusBar()->addPermanentWidget(_statusLabel);
    
    setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
    setCorner(Qt::BottomRightCorner, Qt::RightDockWidgetArea);
    addDockWidget(Qt::LeftDockWidgetArea, _fsDock);
}

