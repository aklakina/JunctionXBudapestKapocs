#include "company.h"
#include "ui_company.h"
#include "auth.h"

Company::Company(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Company)
{
    ui->setupUi(this);
    QFile f(QCoreApplication::applicationDirPath()+"/DATA.json");
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream stream(&f);
        big_data= new json(json::parse(stream.readAll().toStdString()));
    }
    f.close();
    data_file=new json();
    if (big_data->contains("Companies")) {
        *data_file=big_data->find("Companies").value();
    }

    LoadDataAgain();

}

void Company::LoadDataAgain() {
    ui->treeWidget->clear();
    auto temp=Auth::LoadData(*data_file);
    for (auto i:*temp) {
        ui->treeWidget->addTopLevelItem(i);
    }
    delete temp;

    for (auto i=0;i<ui->treeWidget->topLevelItemCount();i++) {
        if (ui->treeWidget->topLevelItem(i)->text(0)==Auth::username) {
            ui->treeWidget->topLevelItem(i)->setBackground(0,QBrush(QColor(57, 194, 215)));
        }
    }
}

json* Company::big_data=nullptr;


json* Company::data_file=nullptr;
Company::~Company()
{
    delete ui;
}

void Company::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    auto temp=big_data->find("Mentors").value();
    if (item->parent()->text(0)=="Mentors" && temp.contains(item->text(0).toStdString())) {
        ui->textBrowser->setText(
                    QString::fromStdString(temp.find(item->text(0).toStdString()).value().find("Description").value()
                    ));
    }
}


void Company::on_pushButton_clicked()
{
    auto *temp=&big_data->find("Companies").value();
    auto temp2=temp->find(Auth::username.toStdString());
    if (temp2!=temp->end()) {
        temp=&(temp2.value());
        temp2=temp->find("Positions");
        temp=&temp2.value();
        if ((*temp).contains(ui->lineEdit->text().toStdString())) {
            QMessageBox::warning(this,tr("Adding position"),tr("You already have a position named like this opened."));
        } else {
            json temp3=json();
            temp3[ui->lineEdit->text().toStdString()]=json();
            temp3[ui->lineEdit->text().toStdString()]["Mentors"]=json::array();
            temp3[ui->lineEdit->text().toStdString()]["Requisites"]=json::array();
            auto temp4=ui->textEdit->toPlainText().split("\n");
            int k=0;
            for (const auto &i:temp4) {
                temp3[ui->lineEdit->text().toStdString()]["Requisites"][k]=i.toStdString();
                k++;
            }
            (*temp)[temp3.items().begin().key()]=temp3.items().begin().value();
        }
    } else {
        json temp3=json();
        temp3[Auth::username.toStdString()]=json();
        temp3[Auth::username.toStdString()]["Address"]="A postal code, Some city, a typic street, the usual house";
        temp3[Auth::username.toStdString()]["Positions"]=json();
        temp3[Auth::username.toStdString()]["Positions"][ui->lineEdit->text().toStdString()]=json();
        temp3[Auth::username.toStdString()]["Positions"][ui->lineEdit->text().toStdString()]["Mentors"]=json::array();
        temp3[Auth::username.toStdString()]["Positions"][ui->lineEdit->text().toStdString()]["Requisites"]=json::array();
        auto temp4=ui->textEdit->toPlainText().split("\n");
        int k=0;
        for (const auto &i:temp4) {
            temp3[Auth::username.toStdString()]["Positions"][ui->lineEdit->text().toStdString()]["Requisites"][k]=i.toStdString();
            k++;
        }
        (*temp)[temp3.items().begin().key()]=temp3.items().begin().value();
    }
    QFile f(QCoreApplication::applicationDirPath()+"/DATA.json");
    if (f.open(QIODevice::WriteOnly)) {
        QTextStream stream(&f);
        stream<<QString::fromStdString(big_data->dump(4));
    }
    f.close();
    delete big_data;
    if (f.open(QIODevice::ReadOnly)) {
        QTextStream stream(&f);
        big_data= new json(json::parse(stream.readAll().toStdString()));
    }
    f.close();
    data_file=new json();
    if (big_data->contains("Companies")) {
        *data_file=big_data->find("Companies").value();
    }
    LoadDataAgain();
}

