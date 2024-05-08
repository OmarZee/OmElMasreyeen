#ifndef PATIENTSCHEDULES_H
#define PATIENTSCHEDULES_H

#include <QDialog>

namespace Ui {
class PatientSchedules;
}

class PatientSchedules : public QDialog
{
    Q_OBJECT

public:
    explicit PatientSchedules(QWidget *parent = nullptr);
    ~PatientSchedules();

private slots:
    void on_requestButton_clicked();

    void on_rescheduleButton_clicked();

    void on_cancelButton_clicked();

private:
    Ui::PatientSchedules *ui;
};

#endif // PATIENTSCHEDULES_H
