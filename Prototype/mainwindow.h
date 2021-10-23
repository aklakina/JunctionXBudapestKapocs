#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QInputDialog>
#include <QDir>
#include <QMessageBox>
#include "json.hpp"


using json=nlohmann::json;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    static unsigned short getState();

private slots:
    void on_pushButton_2_clicked();

private:
    static unsigned short state;
    static json* companies;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
