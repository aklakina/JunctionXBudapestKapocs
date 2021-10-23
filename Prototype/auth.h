#ifndef AUTH_H
#define AUTH_H

#include <QMainWindow>
#include "./json.hpp"
#include <QMessageAuthenticationCode>
#include <QByteArray>
#include <QFile>
#include <QMessageBox>
#include "mentor.h"
#include "unemployed.h"
#include "company.h"
#include <QTreeWidgetItem>

using json=nlohmann::json;
namespace Ui {
class Auth;
}

class Auth : public QMainWindow
{
    Q_OBJECT

public:
    explicit Auth(QWidget *parent = nullptr);
    ~Auth();

    static unsigned short getstate();

    static const QString &getusername();
    static QString username;
    static std::vector<QTreeWidgetItem*>* LoadData(json & data, QTreeWidgetItem* root=nullptr);

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::Auth *ui;
    static json* auth_file;
    static unsigned short state;
    QMainWindow* next_ui;
};

#endif // AUTH_H
