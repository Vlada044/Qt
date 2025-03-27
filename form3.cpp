#include "form3.h"
#include "ui_form3.h"
#include <QApplication>

Form3::Form3(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form3)
{
    ui->setupUi(this);

    ui->label->setStyleSheet(
        "background-color: transparent;"
        "color: rgb(216, 167, 177);"
        "font: 20pt 'Roboto';"
        "font-weight: 700;"
        );
    ui->label_2->setStyleSheet(
        "background-color: transparent;"
        "color: #de8c9d;"
        "font: 18pt 'Roboto';"
        "font-weight: 700;"
        );
    ui->resultLabel->setStyleSheet(
        "background-color: transparent;"
        "color: rgb(216, 167, 177);"
        "font: 18pt 'Roboto';"
        "font-weight: 700;"
        );
    ui->label_4->setStyleSheet(
        "background-color: transparent;"
        "color: rgb(216, 167, 177);"
        "font: 20pt 'Roboto';"
        "font-weight: 700;"
        );
    ui->label_3->setStyleSheet(
        "background-color: #de8c9d;"
        "color: #de8c9d;"
        );
    ui->label_5->setStyleSheet(
        "background-color: #de8c9d;"
        "color: #de8c9d;"
        );

    ui->pushButton_2->setStyleSheet(
        "QPushButton {"
        "background-color: #4CAF50;"
        "color: white;"
        "border: none;"
        "padding: 10px 20px;"
        "font: bold 16pt Roboto;"
        "border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "background-color: #45a049;"
        "}"
        "QPushButton:pressed {"
        "background-color: #2E7D32;"
        "}"
        );
    ui->pushButton->setStyleSheet(
        "QPushButton {"
        "background-color: #ec1832;"
        "color: white;"
        "border: none;"
        "padding: 10px 20px;"
        "font: bold 16pt Roboto;"
        "border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "background-color: #d4112a;"
        "}"
        "QPushButton:pressed {"
        "background-color: #bc0b21;"
        "}"
        );

    QPalette palette;
    QPixmap pixmap(":/img/img/5246845835818428521.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);
}

Form3::~Form3() {
    delete ui;
}

void Form3::receiveArea(int area) {
    ui->resultLabel->setText(QString::number(area));
}

void Form3::on_pushButton_clicked() {
    QApplication::quit();
}

void Form3::on_pushButton_2_clicked() {
    emit clearRadioButtons();
    this->hide();
    emit reopenMainWindow();
}

