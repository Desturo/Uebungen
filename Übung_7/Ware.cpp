#include "Ware.h"

unsigned int Ware::getGroesse()
{
    return m_groesse;
}

unsigned int Ware::getGewicht()
{
    return m_gewicht;
}

Ware::Ware(unsigned int groesse, unsigned int gewicht)
{
    this->m_groesse = groesse;
    this->m_gewicht = gewicht;
}

Ware::Ware() {
    this->m_gewicht = 1;
    this->m_groesse = 1;
}
