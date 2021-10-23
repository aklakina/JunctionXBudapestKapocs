#include "mentor.h"
#include "ui_mentor.h"

Mentor::Mentor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Mentor)
{
    ui->setupUi(this);
}

Mentor::~Mentor()
{
    delete ui;
}
