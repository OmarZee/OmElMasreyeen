#ifndef CHATBOX_H
#define CHATBOX_H

#include <QDialog>

namespace Ui {
class ChatBox;
}

class ChatBox : public QDialog
{
    Q_OBJECT

public:
    explicit ChatBox(QWidget *parent = nullptr);
    ~ChatBox();

private slots:
    void on_sendButton_clicked();

private:
    Ui::ChatBox *ui;
};

#endif // CHATBOX_H
