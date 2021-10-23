#include "unemployed.h"
#include "ui_unemployed.h"

Unemployed::Unemployed(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Unemployed)
{
    ui->setupUi(this);
}

Unemployed::~Unemployed()
{
    delete ui;
}
