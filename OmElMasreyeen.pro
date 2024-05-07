QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    adminwindow.cpp \
    appointment.cpp \
    doctor.cpp \
    main.cpp \
    mainwindow.cpp \
    medicalrecord.cpp \
    medicalrecords.cpp \
    nurse.cpp \
    patient.cpp \
    patientmanagementsystem.cpp \
    patientwindow.cpp \
    registerwindow.cpp \
    scheduleappointment.cpp \
    staffmanagementsystem.cpp \
    user.cpp

HEADERS += \
    admin.h \
    adminwindow.h \
    appointment.h \
    doctor.h \
    mainwindow.h \
    medicalrecord.h \
    medicalrecords.h \
    nurse.h \
    patient.h \
    patientmanagementsystem.h \
    patientwindow.h \
    registerwindow.h \
    scheduleappointment.h \
    staffmanagementsystem.h \
    user.h

FORMS += \
    adminwindow.ui \
    araf.ui \
    mainwindow.ui \
    medicalrecords.ui \
    patientwindow.ui \
    registerwindow.ui \
    scheduleappointment.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
