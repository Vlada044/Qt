#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "form.h"
#include "form2.h"
#include "form3.h"


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void clearInputs1();
    void clearInputs2();
private slots:
    void on_chooseButton_clicked();
    void reopenMainWindow();
public slots:
    void clearRadioButtons();
private:
    Ui::MainWindow *ui;

    Form *form;
    Form2 *form2;
    Form3 *form3;

};

#endif // MAINWINDOW_H
