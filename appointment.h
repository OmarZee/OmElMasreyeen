#ifndef APPOINTMENT_H
#define APPOINTMENT_H
#include <QString>

class Appointment
{
private:
    QString date;
    QString time;
    QString doctor;
public:
    Appointment(const QString& date, const QString& time, const QString& doctor);
public slots:
    void scheduleAppointment();
    void rescheduleAppointment();
    void cancelAppointment();
};

#endif // APPOINTMENT_H
