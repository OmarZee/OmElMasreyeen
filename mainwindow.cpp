#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"
#include "registerwindow.h"
#include "ui_registerwindow.h"
#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "patientwindow.h"
#include "ui_patientwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_error->setVisible(false);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Login_button_clicked()
{
   for(int i=0;i<100;i++)
    {
        if((usernames[i] == ui->lineEdit_username->text()) && (passwords[i] == ui->lineEdit_password->text())){
            ui->label_error->setVisible(false);
            if (ui->Role->currentText() == "Admin"){
                AdminWindow* Admin_window = new AdminWindow();
                Admin_window->show();
            }
            hide();
            break;
        }
        else if((usernames[i] == ui->lineEdit_username->text()) && (passwords[i] == ui->lineEdit_password->text())){
            ui->label_error->setVisible(false);
            if (ui->Role->currentText() == "Patient"){
                patientWindow* Patient_window = new patientWindow();
                Patient_window->show();
            }
            hide();
            break;
        }
        else{
            ui->label_error->setVisible(true);
        }
    }

}


void MainWindow::on_Register_button_clicked()
{
    // role = ui->Role->currentText();
    // usernames.push_back(ui->lineEdit_username->text());
    // passwords.push_back(ui->lineEdit_password->text());

    hide();
    registerWindow* registration_window = new registerWindow();
    registration_window->show();

   // hide();

}

