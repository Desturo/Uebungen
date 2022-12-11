#pragma once
#include "Raumschiff.h"
class Jaeger :
    public Raumschiff
{
private:
    unsigned int m_munitionMax;
    unsigned int m_munition;
    KanonenStatus m_kanonenStatus;
public:
    std::string SendeSignal();
    Jaeger(unsigned int munitionMax, std::string name);
    void Fliegen();
    void Feuern();
    void Aufladen();
};

