#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include <QFile>
#include <QTextStream>

registerWindow::registerWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::registerWindow)
{
    ui->setupUi(this);
    ui->label_name_error->hide();
    ui->label_pass_error->hide();
}

registerWindow::~registerWindow()
{
    delete ui;
}

void registerWindow::on_registerButton_clicked()
{
    bool isUsernamePresent = false;
    ui->label_name_error->hide();
    ui->label_pass_error->hide();
    for (int i = 0; i < usernames.size(); i++) {
        if (ui->label_username->text() == usernames[i]) {
            isUsernamePresent = true;
            ui->label_name_error->show();
        }
        else {
            isUsernamePresent = false;
            ui->label_name_error->hide();
        }
    }


    if (ui->lineEdit_password->text() != ui->lineEdit_re_pass->text()) {
        ui->label_pass_error->show();
    } else if (isUsernamePresent == true) {
        ui->label_name_error->show();
    }
    else {
        role = ui->Role->currentText();
        usernames.push_back(ui->lineEdit_username->text());
        passwords.push_back(ui->lineEdit_password->text());
        roles.push_back(ui->Role->currentText());

        QFile filePatient("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Patients.txt");
        QTextStream out(&filePatient);

        if (!filePatient.open(QIODevice::Append | QIODevice::Text)){
            qDebug() << "Error: Unable to open file for writing!";
            qDebug() << "Error detail: " << filePatient.errorString();
            return;
        }
        else if (ui->Role->currentText() == "Patient"){
            out << ui->lineEdit_username->text() << ", ";

            out << "\n";

            // Flush stream to ensure data is written
            out.flush();
            filePatient.close();

            qDebug() << "Patient name successfully added!";
        }

        QFile fileNurse("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Nurses.txt");
        QTextStream out2(&fileNurse);

        if (!fileNurse.open(QIODevice::Append | QIODevice::Text)){
            qDebug() << "Error: Unable to open file for writing!";
            qDebug() << "Error detail: " << fileNurse.errorString();
            return;
        }
        else if (ui->Role->currentText() == "Nurse"){
            out2 << ui->lineEdit_username->text() << ", ";

            out2 << "\n";

            // Flush stream to ensure data is written
            out2.flush();
            fileNurse.close();

            qDebug() << "Nurse name successfully added!";
        }

        QFile fileDoctor("C:/Users/omars/OneDrive/Desktop/Uni/AUC/Semester 6/CS II/Lab/Extra Practice/OmElMasreyeen/DoctorsRegistered.txt");
        QTextStream out3(&fileDoctor);

        if (!fileDoctor.open(QIODevice::Append | QIODevice::Text)){
            qDebug() << "Error: Unable to open file for writing!";
            qDebug() << "Error detail: " << fileDoctor.errorString();
            return;
        }
        else if (ui->Role->currentText() == "Doctor"){
            out3 << ui->lineEdit_username->text() << ", ";

            out3 << "\n";

            // Flush stream to ensure data is written
            out3.flush();
            fileDoctor.close();

            qDebug() << "Doctor name successfully added!";
        }

        hide();
        MainWindow* login_window = new MainWindow();
        login_window->show();
    }

}

