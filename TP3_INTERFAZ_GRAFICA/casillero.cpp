#include "casillero.h"
#include <iostream>

Casillero::Casillero()
{
    this->pasto = NULL;
}

Casillero::Casillero(int tipo){
    this->pasto = NULL;
    this->tipo = tipo;
}

void Casillero::crearPastizal()
{
    this->pasto = new Pastizal();
    this->tipo = 3;
}

void Casillero::setTipo(int tipo){ this->tipo = tipo; }

void Casillero::setPastizal(bool estado, int crece, int muere)
{
    pasto = new Pastizal;
    pasto->setEstado(estado);
    pasto->setCrece(crece);
    pasto->setMuere(muere);
}


void Casillero::setEstado(bool estado){ pasto->setEstado(estado); }

void Casillero::setCrece(int x){ pasto->setCrece(x); }

void Casillero::setMuere(int x){ pasto->setMuere(x); }

int Casillero::getTipo(){ return this->tipo; }

bool Casillero::getEstado(){ return pasto->getEstado(); }

int Casillero::getCrece(){ return pasto->getCrece();}

int Casillero::getMuere(){ return pasto->getMuere();}

bool Casillero::tienePasto()
{
    if(pasto != NULL) return true;
    return false;
}
