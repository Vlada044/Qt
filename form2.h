#ifndef FORM2_H
#define FORM2_H

#include <QWidget>
#include "form3.h"
#include "cylinder2.h"

namespace Ui {
class Form2;
}

class Form2 : public QWidget
{
    Q_OBJECT

public:
    explicit Form2(QWidget *parent = nullptr);
    ~Form2();
signals:
    void sendArea(int area);
private slots:
    void on_calculateButton_clicked();
public slots:
    void clearInputs2();
private:
    Ui::Form2 *ui;
    Form3 *form3;
    Cylinder2 cylinder;
    int R1;
    int R2;
    int H;
};

#endif // FORM2_H
