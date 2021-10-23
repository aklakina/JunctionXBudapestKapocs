#include "mentor.h"
#include "unemployed.h"
#include "company.h"
#include "auth.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Auth login;
    login.show();
    return a.exec();
    auto state=login.getstate();
    if (state==0) return 0;
}
