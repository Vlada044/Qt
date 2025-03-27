#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include "form3.h"
#include "cylinder1.h"


namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();
signals:
    void sendArea(int area);
private slots:
    void on_calculateButton_clicked();
public slots:
    void clearInputs1();
private:
    Ui::Form *ui;
    Form3 *form3;
    Cylinder1 cylinder;
    int R1;
    int H;
};
#endif
