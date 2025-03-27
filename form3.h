#ifndef FORM3_H
#define FORM3_H

#include <QWidget>


namespace Ui {
class Form3;
}

class Form3 : public QWidget
{
    Q_OBJECT

public:
    explicit Form3(QWidget *parent = nullptr);
    ~Form3();


public slots:
    void receiveArea(int area);

signals:
    void reopenMainWindow();
    void clearRadioButtons();
private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private:
    Ui::Form3 *ui;

};

#endif // FORM3_H
