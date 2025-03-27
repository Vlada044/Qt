#include "cylinder1.h"

Cylinder1::Cylinder1(int R1, int H, QObject *parent)
    : QObject(parent), m_R1(R1), m_H(H)
{
}

void Cylinder1::setR1(int R1)
{
    m_R1 = R1;
}

void Cylinder1::setH(int H)
{
    m_H = H;
}

int Cylinder1::calculateArea()
{
    const double Pi = 3.14159;
    int area = 2 * Pi * m_R1 * (m_H + m_R1);

    return area;
}
