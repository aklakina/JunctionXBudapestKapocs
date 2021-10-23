#include "mentor.h"
#include "ui_Mentor.h"
#include "auth.h"

Mentor::Mentor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mentor)
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
    delete temp;
    *data_file=big_data->find("Unemployed").value();
    temp=Auth::LoadData(*data_file);
    for (auto i:*temp) {
        ui->treeWidget_2->addTopLevelItem(i);
    }
    delete temp;


    auto temp2=big_data->find("Mentors").value();
    if (temp2.contains(Auth::username.toStdString())) {
        ui->textEdit->setText(
                    QString::fromStdString(temp2.find(Auth::username.toStdString()).value().find("Description").value()
                    ));

        auto holder=temp2.find(Auth::username.toStdString()).value().find("Mentored").value();
        for (const auto &i:data_file->items()) {
            json holder2;
            holder2[i.key()]=i.value();
            for (auto k:holder.items()) {
                if (k.value()==i.key()) {
                    temp=Auth::LoadData(holder2);
                    for (auto i:*temp) {
                        ui->treeWidget_3->addTopLevelItem(i);
                    }
                    delete temp;
                }
            }
        }
    }
}

json* Mentor::big_data=nullptr;


json* Mentor::data_file=nullptr;
Mentor::~Mentor()
{
    delete ui;
}
