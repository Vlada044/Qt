#ifndef CYLINDER1_H
#define CYLINDER1_H

#include <QObject>

class Cylinder1 : public QObject
{
    Q_OBJECT

public:
    Cylinder1(int R1 = 0, int H = 0, QObject *parent = nullptr);

    void setR1(int R1);
    void setH(int H);

    virtual int calculateArea();


protected:
    int m_R1;
    int m_H;
};

#endif // CYLINDER1_H
