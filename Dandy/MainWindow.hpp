#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QLabel>
#include <QMainWindow>
#include <QToolBar>

#include "FSDock.hpp"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    
private:
    void setupUI();
    
    Ui::MainWindow *_ui;
    
    QToolBar *_toolBar;
    QLabel *_statusLabel;
    FSDock *_fsDock;
    
    QAction *_actionRun;
    QAction *_actionDebug;
};
#endif // MAINWINDOW_H
