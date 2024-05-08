#include "patientwindow.h"
#include "ui_patientwindow.h"
#include "scheduleappointment.h"
#include "ui_scheduleappointment.h"
#include "chatbox.h"
#include "ui_chatbox.h"

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
    ScheduleAppointment* schedule_window = new ScheduleAppointment();
    schedule_window->show();
}


void patientWindow::on_chatButton_clicked()
{
    hide();
    ChatBox* chat_window = new ChatBox();
    chat_window->show();
}

