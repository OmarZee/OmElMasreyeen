#include "patientwindow.h"
#include "ui_patientwindow.h"
#include "scheduleappointment.h"
#include "ui_scheduleappointment.h"
#include "chatbox.h"
#include "ui_chatbox.h"
#include "patientschedules.h"
#include "ui_patientschedules.h"
#include "nursewindow.h"
#include "ui_nursewindow.h"

patientWindow::patientWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::patientWindow)
{
    ui->setupUi(this);
}

patientWindow::~patientWindow()
{
    delete ui;
}

void patientWindow::on_scheduleButton_clicked()
{
    hide();
    PatientSchedules* schedule_window = new PatientSchedules();
    schedule_window->show();


}


void patientWindow::on_chatButton_clicked()
{
    hide();
    ChatBox* chat_window = new ChatBox();
    chat_window->show();
}


void patientWindow::on_recordsButton_clicked()
{
    // qDebug() << "Patient name: " << Nurses::patientName << "\n";
    // qDebug() << "Patient number: " << Nurses::patientNumber << "\n";
    // qDebug() << "Diabetes: " << Nurses::diabetes << "\n";
    // qDebug() << "BloodType: " << Nurses::bloodType << "\n";
    // qDebug() << "RBC: " << Nurses::RBC << "\n";
    // qDebug() << "WBC: " << Nurses::WBC << "\n";
    // qDebug() << "CBC: " << Nurses::CBC << "\n";
}

