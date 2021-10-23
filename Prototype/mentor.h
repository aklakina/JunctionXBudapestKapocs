#ifndef MENTOR_H
#define MENTOR_H

#include <QMainWindow>

namespace Ui {
class Mentor;
}

class Mentor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mentor(QWidget *parent = nullptr);
    ~Mentor();

private:
    Ui::Mentor *ui;
};

#endif // MENTOR_H
