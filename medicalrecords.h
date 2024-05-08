#ifndef MEDICALRECORDS_H
#define MEDICALRECORDS_H

#include <QDialog>
#include <QString>
#include "medicalrecord.h"

namespace Ui {
class MedicalRecords;
}

class MedicalRecords : public QDialog
{
    Q_OBJECT

public:
    explicit MedicalRecords(QWidget *parent = nullptr);
    MedicalRecord records_arr[50];
    int count;
    ~MedicalRecords();

private slots:
    void on_pushButton_addRecord_clicked();

    void on_backButton_clicked();

private:
    Ui::MedicalRecords *ui;
};

#endif // MEDICALRECORDS_H
