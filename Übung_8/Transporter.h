#pragma once
#include "Raumschiff.h"
class Transporter :
    public Raumschiff
{
public:
    std::string SendeSignal();
    Transporter(std::string name);
    void Fliegen();

};
