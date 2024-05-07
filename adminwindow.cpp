#include "adminwindow.h"
#include <QDebug>
#include "doctor.h"
#include "ui_adminwindow.h"
#include <QFile>
#include <QTextStream>

std::vector<Doctor> doctor_vector;

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

    QFile file("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Lab/Extra Practice/OmElMasreyeen/Doctors.txt");

    if (!file.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "Error: Unable to open file for writing!";
        qDebug() << "Error detail: " << file.errorString();
        return;
    }

    QTextStream out(&file);
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
