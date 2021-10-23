#include "mainwindow.h"
#include "ui_mainwindow.h"

unsigned short MainWindow::state=0;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bool ok=false;
    while (!ok) {
        QString user = QInputDialog::getText(this, tr("Login"),
                                             tr("User name:"), QLineEdit::Normal,
                                             QDir::home().dirName(), &ok);
        if (ok && !user.isEmpty()) {
        } else {
            break;
        }
        QString pwd = QInputDialog::getText(this, tr("Login"),
                                     tr("Password: "), QLineEdit::Password,
                                     QDir::home().dirName(), &ok);
        if (ok && !pwd.isEmpty()) {
        } else {
            break;
        }
        if (user=="unemployed" && pwd=="uep") {
            state=1;
        } else if (user=="mentor" && pwd=="mt"){
            state=2;
        } else {
            ok=false;
            QMessageBox::warning(this, tr("Login"),
                                           tr("Authentication failed"),
                                           QMessageBox::Ok);
        }
    }

    QFile f("./companies");
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream stream(&f);
        companies= new json(json::parse(stream.readAll().toStdString()));
    }

}

json* MainWindow::companies=nullptr;

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    this->close();
}

unsigned short MainWindow::getState()
{
    return state;
}

