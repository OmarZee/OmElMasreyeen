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
    } else     if (isUsernamePresent == true) {
        ui->label_name_error->show();
    }
    else {
        role = ui->Role->currentText();
        usernames.push_back(ui->lineEdit_username->text());
        passwords.push_back(ui->lineEdit_password->text());

        QFile file("C:/Users/dalia/OneDrive/Desktop/Spring 2024 semester/CS2 lab/Mostashfa Om el Masreyeen/Patients.txt");
        QTextStream out(&file);

        if (!file.open(QIODevice::Append | QIODevice::Text)){
            qDebug() << "Error: Unable to open file for writing!";
            qDebug() << "Error detail: " << file.errorString();
            return;
        }
        else if (ui->Role->currentText() == "Patient"){
            out << ui->lineEdit_username->text() << ", ";

            out << "\n";

            // Flush stream to ensure data is written
            out.flush();
            file.close();

            qDebug() << "Patient name successfully added!";
        }

        hide();
        MainWindow* login_window = new MainWindow();
        login_window->show();
    }

}

