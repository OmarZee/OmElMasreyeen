#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "admin.h"
#include "Patient.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    Doctor doctor_arr[50];
    static int count;
    Patient patient_arr[50];
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    // void on_addDoctorButton_clicked();

    // void on_addSpecialtyButton_clicked();

    // void on_addTimeButton_clicked();

    void on_addButton_clicked();

    // void on_addButton_2_clicked();

    // void on_addButton_3_clicked();

    // void on_addButton_4_clicked();

    void on_pushButton_addPatient_clicked();

    void on_pushButton_addRecord_clicked();

    void on_scheduleButton_clicked();

    void on_pushButton_deleteRecord_clicked();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
