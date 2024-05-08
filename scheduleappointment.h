#ifndef SCHEDULEAPPOINTMENT_H
#define SCHEDULEAPPOINTMENT_H

#include <QDialog>

namespace Ui {
class ScheduleAppointment;
}

class ScheduleAppointment : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleAppointment(QWidget *parent = nullptr);
    ~ScheduleAppointment();

private slots:
    void on_addToScheduleButton_clicked();

private:
    Ui::ScheduleAppointment *ui;
};

#endif // SCHEDULEAPPOINTMENT_H
