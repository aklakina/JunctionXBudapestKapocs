#ifndef MENTOR_H
#define MENTOR_H

#include <QMainWindow>

#include <QFile>
#include <QMessageBox>
#include "./json.hpp"
#include <QTreeWidget>


using json=nlohmann::json;
namespace Ui {
class Mentor;
}

class Mentor : public QMainWindow
{
    Q_OBJECT

public:
    explicit Mentor(QWidget *parent = nullptr);
    ~Mentor();
private slots:

private:
    Ui::Mentor *ui;
    static json* data_file;
    static json* big_data;
};

#endif // MENTOR_H
