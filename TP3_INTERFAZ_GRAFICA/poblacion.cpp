#include "poblacion.h"

Poblacion::Poblacion()
{

}

Poblacion::Poblacion(char tipo)
{
    this->sincomer = 0;
    this->tipo = tipo;
}

void Poblacion::setComio(bool x)
{
    if(x==false){
        sincomer++;
    }else
        sincomer=0;
}

void Poblacion::setsincomer(int x)
{
    this->sincomer = x;
}

void Poblacion::setCoordX(int coordX){ this->coordX = coordX; }

void Poblacion::setCoordY(int coordY){ this->coordY = coordY; }

void Poblacion::setTipo(char tipo){ this->tipo = tipo; }

int Poblacion::getSincomer(){ return sincomer; }

int Poblacion::getCoordX(){ return coordX; }

int Poblacion::getCoordY(){ return coordY; }

char Poblacion::getTipo(){ return tipo; }
