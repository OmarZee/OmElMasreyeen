#include "medicalrecords.h"
#include "ui_medicalrecords.h"
#include "medicalrecord.h"
#include <QFile>
#include "adminwindow.h"
#include "ui_adminwindow.h"

std::vector<MedicalRecord> Records_vector;

MedicalRecords::MedicalRecords(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::MedicalRecords)
{
    ui->setupUi(this);
}

MedicalRecords::~MedicalRecords()
{
    delete ui;
}

void MedicalRecords::on_pushButton_addRecord_clicked()
{
    count++;
    MedicalRecord *record = new MedicalRecord();
    records_arr[count] = *record;
    record->patient->username = ui->lineEdit_patientName->text();
    //record->patient->Number = ui->lineEdit_patientNumber->text();
    record->patient->Number.push_back(ui->lineEdit_patientNumber->text());
    record->diagnosis = ui->lineEdit_diagnosis->text();
    record->prescription = ui->lineEdit_prescription->text();
    record->treatment = ui->lineEdit_treament->text();

    Records_vector.push_back(*record);

    QFile file("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Records.txt");
    QTextStream out(&file);

    if (!file.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "Error: Unable to open file for writing!";
        qDebug() << "Error detail: " << file.errorString();
        return;
    }
    else {
        out << ui->lineEdit_patientName->text() << ", " << ui->lineEdit_patientNumber->text() << ", " << ui->lineEdit_diagnosis->text()
            << ", " << ui->lineEdit_prescription->text() << ", " << ui->lineEdit_treament->text();

        out << "\n";

        // Flush stream to ensure data is written
        out.flush();
        file.close();

        qDebug() << "Patient name successfully added!";
    }
}


void MedicalRecords::on_backButton_clicked()
{
    hide();
    AdminWindow* Admin_window = new AdminWindow();
    Admin_window->show();
}

