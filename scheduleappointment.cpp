#include "scheduleappointment.h"
#include "ui_scheduleappointment.h"

ScheduleAppointment::ScheduleAppointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScheduleAppointment)
{
    ui->setupUi(this);
}

ScheduleAppointment::~ScheduleAppointment()
{
    delete ui;
}
