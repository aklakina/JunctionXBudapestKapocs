#include "unemployed.h"
#include "ui_unemployed.h"
#include "auth.h"

Unemployed::Unemployed(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Unemployed)
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

Unemployed::~Unemployed()
{
    delete ui;
}
json* Unemployed::big_data=nullptr;


json* Unemployed::data_file=nullptr;


void Unemployed::on_treeWidget_itemClicked(QTreeWidgetItem *item, int column)
{
    auto temp=big_data->find("Mentors").value();
    if (item->parent()->text(0)=="Mentors" && temp.contains(item->text(0).toStdString())) {
        ui->textBrowser->setText(
                    QString::fromStdString(temp.find(item->text(0).toStdString()).value().find("Description").value()
                    ));
    }
}
