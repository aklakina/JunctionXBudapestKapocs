QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    auth.cpp \
    company.cpp \
    main.cpp \
    mentor.cpp \
    unemployed.cpp

HEADERS += \
    auth.h \
    company.h \
    json.hpp \
    mentor.h \
    unemployed.h

FORMS += \
    Mentor.ui \
    auth.ui \
    company.ui \
    unemployed.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
RC_ICONS = icon.ico
RESOURCES += \
  resources.qrc

DISTFILES += \
  Auth.json \
  DATA.json \
  icon.ico
