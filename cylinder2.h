#ifndef CYLINDER2_H
#define CYLINDER2_H

#include "cylinder1.h"

class Cylinder2 : public Cylinder1
{
    Q_OBJECT

public:
    Cylinder2(int R1 = 0, int R2 = 0, int H = 0, QObject *parent = nullptr);

    void setR2(int R2);

    int calculateArea() override;

private:
    int m_R2;
};

#endif // CYLINDER2_H
