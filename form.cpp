#include "form.h"
#include "ui_form.h"
#include <QMessageBox>
#include <QPixmap>
#include <QGraphicsOpacityEffect>

void showStyledMessageBox(QWidget *parent, const QString &title, const QString &text) {
    QMessageBox messageBox(parent);
    messageBox.setWindowTitle(title);
    messageBox.setText(text);
    messageBox.setIcon(QMessageBox::Warning);
    messageBox.setStyleSheet(
        "QMessageBox {"
        "background-color: #fbffee;"
        "border: 2px solid #de8c9d;"
        "font-family: Roboto;"
        "font-size: 14px;"
        "color: #333333;"
        "}"
        "QLabel {"
        "color: #de8c9d;"
        "font-weight: bold;"
        "font-size: 16px;"
        "}"
        "QPushButton {"
        "background-color: #4CAF50;"
        "color: white;"
        "border: none;"
        "padding: 10px 20px;"
        "font: bold 12pt Roboto;"
        "border-radius: 5px;"
        "}"
        "QPushButton:hover {"
        "background-color: #45a049;"
        "}"
        "QPushButton:pressed {"
        "background-color: #2E7D32;"
        "}"
        );
    messageBox.addButton(QMessageBox::Ok);
    messageBox.exec();
}

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
    , form3(new Form3(this))
{
    ui->setupUi(this);

    ui->label->setStyleSheet(
        "background-color: transparent;"
        "color: rgb(216, 167, 177);"
        "font: 20pt 'Roboto';"
        "font-weight: 700;"
        );
    ui->label->setText(
        "<span></span>"
        "<span style='color:#de8c9d;'>Введите</span>"
        "<span> необходимые</span>"
        );
    ui->label_2->setStyleSheet(
        "background-color: transparent;"
        "color: rgb(216, 167, 177);"
        "font: 20pt 'Roboto';"
        "font-weight: 700;"
        );
    ui->label_3->setStyleSheet(
        "background-color: transparent;"
        "color: #de8c9d;"
        "font: 18pt 'Roboto';"
        "font-weight: 700;"
        );
    ui->label_4->setStyleSheet(
        "background-color: transparent;"
        "color: #de8c9d;"
        "font: 18pt 'Roboto';"
        "font-weight: 700;"
        );
    ui->InputR1->setStyleSheet(
        "background-color: transparent;"
        "border: none;"
        "border-bottom: 1px solid black;"
        "color: rgb(216, 167, 177);"
        "font: 18pt 'Roboto';"
        );
    ui->InputH->setStyleSheet(
        "background-color: transparent;"
        "border: none;"
        "border-bottom: 1px solid black;"
        "color: rgb(216, 167, 177);"
        "font: 18pt 'Roboto';"
        );

    QPalette palette;
    QPixmap pixmap(":/img/img/5246845835818428521.jpg");
    palette.setBrush(QPalette::Window, QBrush(pixmap));
    this->setPalette(palette);

    ui->calculateButton->setStyleSheet(
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

    form3->hide();
    connect(this, &Form::sendArea, form3, &Form3::receiveArea);
}

Form::~Form() {
    delete ui;
}
void Form::on_calculateButton_clicked() {
    QString textR1 = ui->InputR1->text();
    QString textH = ui->InputH->text();

    if ((textR1.startsWith("0") && textR1.length() > 1) || (textH.startsWith("0") && textH.length() > 1)) {
        showStyledMessageBox(this, "Ошибка ввода", "Число не должно начинаться с 0.");
        return;
    }
    if ((textR1.length() > 3) || (textH.length() > 3)) {
        showStyledMessageBox(this, "Ошибка ввода", "Число должно быть однозначным, двухзначным или трёхзначным.");
        return;
    }
    R1 = textR1.toInt();
    H = textH.toInt();
    if (R1 <= 0 || H <= 0) {
        showStyledMessageBox(
            this,
            "Ошибка ввода",
            "Пожалуйста, введите положительные значения для радиуса и высоты."
            );
        return;
    }
    Cylinder1 cylinder;
    cylinder.setR1(R1);
    cylinder.setH(H);
    int area = cylinder.calculateArea();
    emit sendArea(area);
}

void Form::clearInputs1() {
    ui->InputR1->clear();
    ui->InputH->clear();
}
