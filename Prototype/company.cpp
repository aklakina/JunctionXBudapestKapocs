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

    auto temp=Auth::LoadData(*data_file);
    for (auto i:*temp) {
        ui->treeWidget->addTopLevelItem(i);
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

