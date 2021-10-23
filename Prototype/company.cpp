#include "company.h"
#include "ui_company.h"

Company::Company(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Company)
{
    ui->setupUi(this);
}

Company::~Company()
{
    delete ui;
}
