#include "chatbox.h"
#include "ui_chatbox.h"

ChatBox::ChatBox(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ChatBox)
{
    ui->setupUi(this);
    ui->textEdit_chat->setPlainText("Hello! How can I assist you today?");
}

ChatBox::~ChatBox()
{
    delete ui;
}

void ChatBox::on_sendButton_clicked()
{
    ui->textEdit_chat->append("Patient: " + ui->lineEdit_message->text());
    ui->lineEdit_message->clear();

    // Send message to doctor (for simulation, emits signal to receiveMessage)
    //emit messageSent(message);

    QString lowercaseMessage = ui->lineEdit_message->text().toLower();

    // Check for keywords in the patient's message and generate a response accordingly
    if (lowercaseMessage.contains("pain")) {
        ui->textEdit_chat->append("Doctor: I'm sorry to hear that you're experiencing pain. Have you taken any medication for it?");
    } else if (lowercaseMessage.contains("appointment")) {
        ui->textEdit_chat->append("Doctor: Sure, let's schedule an appointment. Please provide your preferred date and time.");
    } else if (lowercaseMessage.contains("medication") || lowercaseMessage.contains("prescription")) {
        ui->textEdit_chat->append("Doctor: Are you currently taking any medication? Please provide details.");
    } else if (lowercaseMessage.contains("symptoms") || lowercaseMessage.contains("symptom")) {
        ui->textEdit_chat->append("Doctor: Could you please describe your symptoms in more detail?");
    } else if (lowercaseMessage.contains("diagnosis") || lowercaseMessage.contains("diagnose")) {
        ui->textEdit_chat->append("Doctor: Based on your symptoms, it's possible that you have a common cold. I recommend rest and hydration.");
    } else if (lowercaseMessage.contains("treatment") || lowercaseMessage.contains("treat")) {
        ui->textEdit_chat->append("Doctor: Treatment options depend on the diagnosis. Let's discuss your symptoms further.");
    } else {
        ui->textEdit_chat->append("Doctor: I'm here to help. Is there anything else you'd like to discuss?");
    }

}

