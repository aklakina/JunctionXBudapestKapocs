#include "auth.h"
#include "ui_auth.h"

Auth::Auth(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Auth)
{
    ui->setupUi(this);
    QFile f(QCoreApplication::applicationDirPath()+"/Auth.json");
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream stream(&f);
        auth_file= new json(json::parse(stream.readAll().toStdString()));
    }
    f.close();
}

Auth::~Auth()
{
    delete ui;
}

json* Auth::auth_file=nullptr;

void Auth::on_pushButton_clicked()
{
    auto temp=auth_file->find("Users").value();
    auto pwd=QMessageAuthenticationCode::hash(QByteArray(ui->lineEdit_pwd->text().toStdString().c_str()), QByteArray(((std::string)(temp.find("key").value())).c_str()), QCryptographicHash::Sha256).toHex();
    qDebug()<<pwd;
    if (!temp.contains(ui->lineEdit_usr->text().toStdString())) {
        goto noSuchUser;
    }
    if (temp.find(ui->lineEdit_usr->text().toStdString()).value()[0]==pwd.toStdString()) {
        state=((unsigned short)(temp.find(ui->lineEdit_usr->text().toStdString()).value()[1]));
        this->hide();
        if (state==1) {
            next_ui=new Mentor(this);
        } else if (state==2) {
            next_ui=new Company(this);
        } else if (state==3) {
            next_ui=new Unemployed(this);
        }
        next_ui->show();
        hide();
    } else {
        noSuchUser:
        state=0;
        int res=QMessageBox::warning(this,tr("Login"),tr("No matching combination of this username and password"),QMessageBox::Ok|QMessageBox::Cancel);
        if (res==QMessageBox::Cancel) {
            this->close();
        }
    }
}

unsigned short Auth::getstate()
{
    return state;
}

unsigned short Auth::state=0;

void Auth::on_pushButton_2_clicked()
{
    auto pwd=QMessageAuthenticationCode::hash(QByteArray(ui->lineEdit_pwd->text().toStdString().c_str()), QByteArray(((std::string)(auth_file->find("Users").value().find("key").value())).c_str()), QCryptographicHash::Sha256).toHex();
    auto &temp=auth_file->find("Users").value();
    if (!temp.contains(ui->lineEdit_usr->text().toStdString())) {
        json temp3;
        temp3[0]=pwd.toStdString();
        temp3[1]=rand()%3+1;
        temp[ui->lineEdit_usr->text().toStdString()]=temp3;
        QFile f(QCoreApplication::applicationDirPath()+"/Auth.json");
        if (f.open(QIODevice::WriteOnly)) {
            QTextStream stream(&f);
            stream<<QString::fromStdString(auth_file->dump(4));
        }
    } else {
        QMessageBox::warning(this,tr("Login"),tr("This username is already taken"),QMessageBox::Ok);
    }
}

