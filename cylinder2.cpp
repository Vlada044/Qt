#include "cylinder2.h"

Cylinder2::Cylinder2(int R1, int R2, int H, QObject *parent)
    : Cylinder1(R1, H, parent), m_R2(R2)
{
}

void Cylinder2::setR2(int R2)
{
    m_R2 = R2;
}

int Cylinder2::calculateArea()
{
    const double Pi = 3.14159;
    int area = static_cast<int>(2 * Pi * (m_R1 + m_R2) * (m_H + m_R1 - m_R2));
    return area;
}
