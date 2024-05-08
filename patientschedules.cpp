#include "patientschedules.h"
#include "ui_patientschedules.h"
#include <QFile>
#include "user.h"
#include <QDebug>

PatientSchedules::PatientSchedules(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PatientSchedules)
{
    ui->setupUi(this);

    ui->setupUi(this);
    // Clear the ComboBox
    ui->comboBox_doctors->clear();
    //ui->comboBox_speciality->clear();

    // Open the file
    QFile file("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Doctors.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file.fileName();
        return;
    }

    // Read the content of the file
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList doctors = line.split("\n"); // Assuming CSV format

        // Add each field to the ComboBox
        for (const QString& doctor : doctors) {
            ui->comboBox_doctors->addItem(doctor.trimmed());
            //ui->comboBox_speciality->addItem(doctor.trimmed());
        }
    }

    file.close();
}

PatientSchedules::~PatientSchedules()
{
    delete ui;
}

void PatientSchedules::on_requestButton_clicked()
{
    if ((ui->comboBox_doctors->currentText() == "John Smith: Oncology") && (!User::Dr_1)){
        User::Dr_1 = true;
    }
    else if ((ui->comboBox_doctors->currentText() == "John Smith: Oncology") && (User::Dr_1)){
        Dr1_queue.push(ui->lineEdit_patientName->text());
    }
    if ((ui->comboBox_doctors->currentText() == "Mark Johnson: Bones") && (!User::Dr_2)){
        User::Dr_2 = true;
    }
    else if ((ui->comboBox_doctors->currentText() == "Mark Johnson: Bones") && (User::Dr_2)){
        Dr2_queue.push(ui->lineEdit_patientName->text());
    }
    if ((ui->comboBox_doctors->currentText() == "David Smol: Heart") && (!User::Dr_3)){
        User::Dr_3 = true;
    }
    else if ((ui->comboBox_doctors->currentText() == "David Smol: Heart") && (User::Dr_3)){
        Dr3_queue.push(ui->lineEdit_patientName->text());
    }
}


void PatientSchedules::on_cancelButton_clicked()
{
    if ((ui->comboBox_doctors->currentText() == "John Smith: Oncology") && (User::Dr_1) && (Dr1_queue.empty())){
        User::Dr_1 = false;
    }
    else if ((ui->comboBox_doctors->currentText() == "John Smith: Oncology") && (User::Dr_1) && (!Dr1_queue.empty())){
        Dr1_queue.pop();
    }
    if ((ui->comboBox_doctors->currentText() == "Mark Johnson: Bones") && (!User::Dr_2) && (Dr2_queue.empty())){
        User::Dr_2 = true;
    }
    else if ((ui->comboBox_doctors->currentText() == "Mark Johnson: Bones") && (User::Dr_2) && (!Dr2_queue.empty())){
        Dr2_queue.pop();
    }
    if ((ui->comboBox_doctors->currentText() == "David Smol: Heart") && (!User::Dr_3) && (Dr3_queue.empty())){
        User::Dr_3 = true;
    }
    else if ((ui->comboBox_doctors->currentText() == "David Smol: Heart") && (User::Dr_3) && (!Dr3_queue.empty())){
        Dr3_queue.pop();
    }
}

