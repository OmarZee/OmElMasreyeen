#ifndef NURSEWINDOW_H
#define NURSEWINDOW_H

#include <QDialog>

extern QString patientName, patientNumber, diabetes, bloodType, RBC, WBC, CBC;

namespace Ui {
class NurseWindow;
}

class NurseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit NurseWindow(QWidget *parent = nullptr);
    ~NurseWindow();

private slots:
    void on_pushButton_addResults_clicked();

private:
    Ui::NurseWindow *ui;
};

#endif // NURSEWINDOW_H
