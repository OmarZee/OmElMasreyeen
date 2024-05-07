#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include "admin.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    Doctor doctor_arr[50];
    static int count;
    explicit AdminWindow(QWidget *parent = nullptr);
    ~AdminWindow();

private slots:
    // void on_addDoctorButton_clicked();

    // void on_addSpecialtyButton_clicked();

    // void on_addTimeButton_clicked();

    void on_addButton_clicked();

private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
