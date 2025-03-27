#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QGraphicsOpacityEffect>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    form = new Form;
    form2 = new Form2;
    form3 = new Form3;

    this->setStyleSheet(
        "QMainWindow {"
        "background-image: url(:/img/img/5246845835818428521.jpg);"
        "background-repeat: no-repeat;"
        "background-size: cover;"
        "}"
        );
    ui->radioButton->setStyleSheet(
        "QRadioButton {"
        "color: #de8c9d;"
        "font-family: Roboto;"
        "font-size: 18pt;"
        "font-weight: 700;"
        "}"
        "QRadioButton::indicator {"
        "width: 16px;"
        "height: 16px;"
        "border-radius: 8px;"
        "}"
        "QRadioButton::indicator:checked {"
        "background-color: rgb(216, 167, 177);"
        "border: 1px solid #FFFFFF;"
        "}"
        "QRadioButton::indicator:unchecked {"
        "background-color: #FFFFFF;"
        "border: 1px solid rgb(216, 167, 177);"
        "}"
        );

    ui->radioButton_2->setStyleSheet(
        "QRadioButton {"
        "color: #de8c9d;"
        "font-family: Roboto;"
        "font-size: 18pt;"
        "font-weight: 700;"
        "}"
        "QRadioButton::indicator {"
        "width: 16px;"
        "height: 16px;"
        "border-radius: 8px;"
        "}"
        "QRadioButton::indicator:checked {"
        "background-color: rgb(216, 167, 177);"
        "border: 1px solid #FFFFFF;"
        "}"
        "QRadioButton::indicator:unchecked {"
        "background-color: #FFFFFF;"
        "border: 1px solid rgb(216, 167, 177);"

        "}"
        );
    ui-> chooseButton->setStyleSheet(
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
    ui->label->setText(
        "<span>Выберите </span><span style='color:#de8c9d;'>тип цилиндра</span><span></span>"
        );
    connect(ui->chooseButton, &QPushButton::clicked, this, &MainWindow::on_chooseButton_clicked);
    connect(form3, &Form3::reopenMainWindow, this, &MainWindow::reopenMainWindow);
    connect(form, &Form::sendArea, form3, &Form3::receiveArea);
    connect(form2, &Form2::sendArea, form3, &Form3::receiveArea);
    connect(form, &Form::sendArea, form3, &Form3::show);
    connect(form2, &Form2::sendArea, form3, &Form3::show);
    connect(form3, &Form3::clearRadioButtons, this, &MainWindow::clearRadioButtons);
    connect(this, &MainWindow::clearInputs1, form, &Form::clearInputs1);
    connect(this, &MainWindow::clearInputs2, form2, &Form2::clearInputs2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_chooseButton_clicked()
{
    if (ui->radioButton_2->isChecked()) {
        form->show();
        emit clearInputs1();
    } else if (ui->radioButton->isChecked()) {
        form2->show();
        emit clearInputs2();
    }
}

void MainWindow::reopenMainWindow()
{
    form->hide();
    form2->hide();
    this->show();
}
void MainWindow::clearRadioButtons() {
    ui->radioButton->setAutoExclusive(false);
    ui->radioButton_2->setAutoExclusive(false);
    ui->radioButton->setChecked(false);
    ui->radioButton_2->setChecked(false);
    ui->radioButton->setAutoExclusive(true);
    ui->radioButton_2->setAutoExclusive(true);
}



