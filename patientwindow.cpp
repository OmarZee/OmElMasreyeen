#include "patientwindow.h"
#include "ui_patientwindow.h"
#include "scheduleappointment.h"
#include "ui_scheduleappointment.h"

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

