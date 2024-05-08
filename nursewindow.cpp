#include "nursewindow.h"
#include "ui_nursewindow.h"
#include "testresults.h"
#include <QDebug>
#include <QString>

//extern std::vector<TestResults> testResults;

QString patientName, patientNumber, diabetes, bloodType, RBC, WBC, CBC;

NurseWindow::NurseWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NurseWindow)
{
    ui->setupUi(this);
}

NurseWindow::~NurseWindow()
{
    delete ui;
}

void NurseWindow::on_pushButton_addResults_clicked()
{
    TestResults* result;
    result->patient->username = ui->lineEdit_patientName->text();
    //result->patient.Number = ui->lineEdit_patientNumber->text();
    result->patient->Number.push_back(ui->lineEdit_patientNumber->text());
    result->diabetes = ui->lineEdit_diabetes->text();
    result->bloodType = ui->lineEdit_diabetes->text();
    result->RBC = ui->lineEdit_rbc->text();
    result->WBC = ui->lineEdit_wbc->text();
    result->CBC = ui->lineEdit_cbc->text();

    patientName = ui->lineEdit_patientName->text();
    patientNumber = ui->lineEdit_patientNumber->text();
    diabetes = ui->lineEdit_diabetes->text();
    bloodType = ui->lineEdit_diabetes->text();
    RBC = ui->lineEdit_rbc->text();
    WBC = ui->lineEdit_wbc->text();
    CBC = ui->lineEdit_cbc->text();

    testResults.push_back(*result);

    qDebug() << ui->lineEdit_patientName->text();
}

