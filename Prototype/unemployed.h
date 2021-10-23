#ifndef UNEMPLOYED_H
#define UNEMPLOYED_H

#include <QMainWindow>

namespace Ui {
class Unemployed;
}

class Unemployed : public QMainWindow
{
    Q_OBJECT

public:
    explicit Unemployed(QWidget *parent = nullptr);
    ~Unemployed();

private:
    Ui::Unemployed *ui;
};

#endif // UNEMPLOYED_H
