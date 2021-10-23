#ifndef COMPANY_H
#define COMPANY_H

#include <QMainWindow>

namespace Ui {
class Company;
}

class Company : public QMainWindow
{
    Q_OBJECT

public:
    explicit Company(QWidget *parent = nullptr);
    ~Company();

private:
    Ui::Company *ui;
};

#endif // COMPANY_H
