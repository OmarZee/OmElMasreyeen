#include "scheduleappointment.h"
#include "ui_scheduleappointment.h"
#include <QFile>
#include <QTextStream>

ScheduleAppointment::ScheduleAppointment(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScheduleAppointment)
{
    ui->setupUi(this);
    // Clear the ComboBox
    ui->comboBox_doctors->clear();
    ui->comboBox_speciality->clear();

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
            ui->comboBox_speciality->addItem(doctor.trimmed());
        }

        // if (doctors.size() > 1) {
        //     QString doctor = doctors.at(1).trimmed();
        //     ui->comboBox_doctors->addItem(doctor);
        // }

        // if (!doctors.isEmpty()) {
        //     QString firstWord = doctors.at(0).trimmed();
        //     ui->comboBox_doctors->addItem(firstWord);
        // }
    }

    // Close the file
    file.close();
}

ScheduleAppointment::~ScheduleAppointment()
{
    delete ui;
}

void ScheduleAppointment::on_addToScheduleButton_clicked()
{
    QFile file("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Schedule.txt");
    QTextStream out(&file);

    if (!file.open(QIODevice::Append | QIODevice::Text)){
        qDebug() << "Error: Unable to open file for writing!";
        qDebug() << "Error detail: " << file.errorString();
        return;
    }
    else {
        out << ui->lineEdit_patientName->text() << ", " << ui->lineEdit_patienNumber->text() << ", " << ui->comboBox_doctors->currentText()
            << ", " << ui->comboBox_speciality->currentText() << ", " << ui->dateTimeEdit->currentSection() ; //<< ", " << ui->calendarWidget->currentPageChanged();

        out << "\n";

        // Flush stream to ensure data is written
        out.flush();
        file.close();

        qDebug() << "Patient name successfully added!";
    }

    QFile file2("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Doctors.txt");
    if (!file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file:" << file2.fileName();
        return;
    }

    // Read the content of the file
    QTextStream in2(&file);
    while (!in2.atEnd()) {
        QString line = in2.readLine();
        QStringList dates = line.split(","); // Assuming CSV format: date, data

        if (dates.size() == 2) {
            QString dateString = dates.at(0).trimmed();
            QDate date = QDate::fromString(dateString, "yyyy-MM-dd"); // Adjust the format as needed

            if (date.isValid()) {
                QString data = dates.at(1).trimmed();
                ui->calendarWidget->setDateTextFormat(date, QTextCharFormat()); // Clear any existing format
                //ui->calendarWidget->setDateTextFormat(date, QTextCharFormat(), false); // Reset any existing format

                // Customize the format to highlight the date or display additional data
                QTextCharFormat format;
                format.setForeground(Qt::red); // Example: Highlight the date in red
                format.setToolTip(data); // Example: Set the data as tooltip
                ui->calendarWidget->setDateTextFormat(date, format);
            } else {
                qDebug() << "Invalid date format:" << dateString;
            }
        } else {
            qDebug() << "Invalid CSV line:" << line;
        }
    }

    // Close the file
    file.close();
}

