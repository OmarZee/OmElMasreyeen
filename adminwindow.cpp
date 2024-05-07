#include "adminwindow.h"
#include <QDebug>
#include "doctor.h"
#include "medicalrecords.h"
#include "registerwindow.h"
#include "ui_adminwindow.h"
#include "ui_medicalrecords.h"
#include <QFile>
#include <QTextStream>

std::vector<Doctor> doctor_vector;
std::vector<Patient> Patient_vector;

AdminWindow::AdminWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AdminWindow)
{
    ui->setupUi(this);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}

// void AdminWindow::on_addDoctorButton_clicked()
// {
//     Doctor *doctor = new Doctor();
//     doctor->name = ui->lineEdit_doctorName->text();

//     qDebug() << doctor->name;

// }

// void AdminWindow::on_addSpecialtyButton_clicked()
// {

// }

int AdminWindow::count = -1;

// void AdminWindow::on_addTimeButton_clicked()
// {

//     //qDebug() << doctor_arr->specialty;
//     //qDebug() <<
// }

void AdminWindow::on_addButton_clicked() {
    count++;
    Doctor *doctor = new Doctor();
    doctor_arr[count] = *doctor;
    doctor->name = ui->lineEdit_doctorName->text();
    doctor->specialty = ui->lineEdit_specialty->text();
    doctor->timings.push_back(ui->lineEdit_time_1->text());
    doctor->timings.push_back(ui->lineEdit_time_2->text());
    doctor->timings.push_back(ui->lineEdit_time_3->text());
    doctor_vector.push_back(*doctor);

    QFile file("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Doctors.txt");
    QTextStream out(&file);

    if (!file.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "Error: Unable to open file for writing!";
        qDebug() << "Error detail: " << file.errorString();
        return;
    }
    else {
        out << doctor->name << ", " << doctor->specialty << ", ";
        for(const auto& time : doctor->timings) {
            out << time << ", ";
        }
        out << "\n";

        // Flush stream to ensure data is written
        out.flush();
        file.close();

        qDebug() << "Doctor successfully added!";

        qDebug() << doctor->name;
    }
}

// void AdminWindow::on_addButton_2_clicked()
// {
//     count++;
//     Patient *patient = new Patient();
//     patient_arr[count] = *patient;
//     patient->username = ui->lineEdit_patientname->text();
//     patient->Number.push_back(ui->lineEdit_patientNumber->text());

//     Patient_vector.push_back(*patient);

//     QFile file("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Patients.txt");

//     QTextStream out(&file);

//     if (!file.open(QIODevice::Append | QIODevice::Text)){
//         qDebug() << "Error: Unable to open file for writing!";
//         qDebug() << "Error detail: " << file.errorString();
//         return;
//     }
//     else if (ui->lineEdit_patientname->text() == "Patient"){
//         out << ui->lineEdit_patientname->text() << ", ";

//         out << "\n";

//         // Flush stream to ensure data is written
//         out.flush();
//         file.close();

//         qDebug() << "Patient name successfully added!";
//     }
// }

void AdminWindow::on_pushButton_addPatient_clicked()
{
    count++;
    Patient *patient = new Patient();
    patient_arr[count] = *patient;
    patient->username = ui->lineEdit_patientname->text();
    patient->Number.push_back(ui->lineEdit_patientNumber->text());

    Patient_vector.push_back(*patient);

    QFile file("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Patients.txt");
    QTextStream out(&file);

    if (!file.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "Error: Unable to open file for writing!";
        qDebug() << "Error detail: " << file.errorString();
        return;
    }
    else {
        out << ui->lineEdit_patientname->text() << ", " << ui->lineEdit_patientNumber->text();

        out << "\n";

        // Flush stream to ensure data is written
        out.flush();
        file.close();

        qDebug() << "Patient name successfully added!";
    }
}


void AdminWindow::on_pushButton_addRecord_clicked()
{
    hide();
    MedicalRecords* MedicalRecords_window = new MedicalRecords();
    MedicalRecords_window->show();
}

