#include "doctorwindow.h"
#include "ui_doctorwindow.h"
#include "medicalrecords.h"
#include "ui_medicalrecords.h"

DoctorWindow::DoctorWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DoctorWindow)
{
    ui->setupUi(this);
}

DoctorWindow::~DoctorWindow()
{
    delete ui;
}

void DoctorWindow::on_addRecordButton_clicked()
{
    hide();
    MedicalRecords* Medical_window = new MedicalRecords();
    Medical_window->show();
}

