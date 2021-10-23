#ifndef UNEMPLOYED_H
#define UNEMPLOYED_H

#include <QMainWindow>

#include <QMainWindow>

#include <QFile>
#include <QMessageBox>
#include "./json.hpp"
#include <QTreeWidget>

using json=nlohmann::json;
namespace Ui {
class Unemployed;
}

class Unemployed : public QMainWindow
{
    Q_OBJECT

public:
    explicit Unemployed(QWidget *parent = nullptr);
    ~Unemployed();

private slots:
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);

private:
    Ui::Unemployed *ui;
    static json* data_file;
    static json* big_data;
};

#endif // UNEMPLOYED_H
