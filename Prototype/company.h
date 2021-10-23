#ifndef COMPANY_H
#define COMPANY_H

#include <QMainWindow>

#include <QFile>
#include <QMessageBox>
#include "./json.hpp"
#include <QTreeWidget>


using json=nlohmann::json;
namespace Ui {
class Company;
}

class Company : public QMainWindow
{
    Q_OBJECT

public:
    explicit Company(QWidget *parent = nullptr);
    ~Company();

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

    void on_pushButton_clicked();

private:
    Ui::Company *ui;
    static json* data_file;
    static json* big_data;
    void LoadDataAgain();
};

#endif // COMPANY_H
