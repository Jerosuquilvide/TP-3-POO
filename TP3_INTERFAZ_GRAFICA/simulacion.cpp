#include "simulacion.h"
#include <iostream>

Simulacion::Simulacion()
{
    mapa = NULL;
}

Simulacion::Simulacion(int f, int c, int mpasto, int tipoA, int tipoB, int cantDias, int tiempo)
{
    this->cantPoblaciones = 0;

    this->mapa = new Mapa(f,c);
    this->mapa->crearMapa(mpasto);

    this->cantDias = cantDias;
    this->tiempo = tiempo;

    for(int i=0;i<tipoA; i++) agregarPoblacion('A');
    for(int i=0; i<tipoB; i++) agregarPoblacion('B');
}

void Simulacion::agregarPoblacion(char dato)
{
    Poblacion * nuevo= new Poblacion(dato);

    bool band = false;
    int i; int j;
    while(band!=true){

        i=(1+ rand()% mapa->getFilas() )-1;
        j=(1+ rand()% mapa->getColumnas() )-1;

        if(mapa->getTipo(i,j) != 1){
            nuevo->setCoordX(i);
            nuevo->setCoordY(j);
            band=true;
        }
    }
    this->cantPoblaciones++;
    poblaciones.push_back(*nuevo);
}

void Simulacion::ControlSimulacion()
{
    controlPoblaciones();
    accionPoblacion();
    actualizarCasillerosCiervos();
    actualizarMapa();
    moverPoblaciones();
}

void Simulacion::controlPoblaciones()
{
    int x, y;

    for(auto i = poblaciones.begin();i != poblaciones.end(); ++i){
        x= i->getCoordX();
        y= i->getCoordY();

        if(mapa->getTipo(x,y) == 3){
            if(mapa->getEstado(x,y)==true){ //true esta vivo..
                i->setComio(true); // comio
            }else i->setComio(false); //No comio
        }else i->setComio(false);//No comio

        if(i->getSincomer() == 3){
            i = poblaciones.erase(i);
            this->cantPoblaciones--;
        }
    }
}

void Simulacion::accionPoblacion()
{
    list<Poblacion> aux;

    copy(poblaciones.begin(),poblaciones.end(), back_inserter(aux));

    for(auto prim = poblaciones.begin(); prim != poblaciones.end(); ++prim){
        for(auto segu = poblaciones.begin(); segu != poblaciones.end(); ++segu){
            if(prim != segu){
                if(prim->getCoordX() == segu->getCoordX() &&
                        prim->getCoordY() == segu->getCoordY()){

                    char tipo1=prim->getTipo();
                    char tipo2=segu->getTipo();

                    if(tipo1 == 'A' && tipo2 == 'A'){
                        agregarPoblacion('A');
                    }

                    if(tipo1 == 'B' && tipo2 == 'B'){
                        prim = poblaciones.erase(prim);
                        this->cantPoblaciones--;
                    }
                }
            }
        }
    }
}

void Simulacion::actualizarCasillerosCiervos()
{
    int x,y;
    for(auto i = poblaciones.begin(); i != poblaciones.end(); ++i){
        x=i->getCoordX();
        y=i->getCoordY();
        mapa->actualizar(x,y);
    }
}

void Simulacion::actualizarMapa()
{
    for(int i=0;i<mapa->getFilas();i++){
        for(int j=0;j<mapa->getColumnas();j++){
            mapa->modificarmapa(i,j);
        }
    }
}

void Simulacion::moverPoblaciones()
{
    int dir; //variable de direccion
    int x,y;
    bool band;
    for(auto i=poblaciones.begin(); i!=poblaciones.end(); i++){

        dir=1+rand()%4; //N° azar (entre 1 - 4) .. 1:Izquierda 2:Derecha 3:Arriba 4:Abajo
        band=false;

        while(band==false){
            x=i->getCoordX();
            y=i->getCoordY();

            if(dir==1){ //Izquierda
                if(y-1 >= 0){
                    if(mapa->getTipo(x,y-1) != 1){
                        y-=1;
                        i->setCoordX(x);
                        i->setCoordY(y);
                        band=true;
                    }
                }
            }

            if(dir==2){ //Derecha
                if(y+1 < mapa->getColumnas()){
                    if(mapa->getTipo(x,y+1) != 1){
                        y+=1;
                        i->setCoordX(x);
                        i->setCoordY(y);
                        band=true;
                    }
                }
            }

            if(dir==3){ //Arriba
                if(x-1 >= 0){
                    if(mapa->getTipo(x-1,y) != 1){
                        x-=1;
                        i->setCoordX(x);
                        i->setCoordY(y);
                        band=true;
                    }
                }
            }

            if(dir==4){ //Abajo
                if(x+1 < mapa->getFilas()){ //Considerar si esta adentro del "mapa"
                    if(mapa->getTipo(x+1,y) != 1){
                        x+=1;
                        i->setCoordX(x);
                        i->setCoordY(y);
                        band=true;
                    }
                }
            }

            if(band==false) dir=1+rand()%4;
        }
    }
}

bool Simulacion::tienePasto(int i, int j)
{
    return mapa->tienePasto(i,j);
}

int Simulacion::getTipoCasillero(int i, int j)
{
    return mapa->getTipo(i,j);
}

bool Simulacion::getEstadoPastizal(int i, int j)
{
    return mapa->getEstado(i,j);
}

int Simulacion::getCrecePastizal(int i, int j)
{
    return mapa->getCrece(i,j);
}

int Simulacion::getMuerePastizal(int i, int j)
{
    return mapa->getMuere(i,j);
}

int Simulacion::getSinComerPoblacion(int i, int j)
{
    for(auto k=poblaciones.begin(); k!=poblaciones.end(); ++k){
        if(k->getCoordX() == i && k->getCoordY() == j){
            return k->getSincomer();
        }
    }
    return -1;
}

int Simulacion::getcoordXPoblacion(int i, int j)
{
    for(auto k=poblaciones.begin(); k!=poblaciones.end(); ++i){
        if(k->getCoordX() == i && k->getCoordY() == j){
            return k->getCoordX();
        }
    }
    return -1;
}

int Simulacion::getcoordYPoblacion(int i, int j)
{
    for(auto k=poblaciones.begin(); k!=poblaciones.end(); ++i){
        if(k->getCoordX() == i && k->getCoordY() == j){
            return k->getCoordY();
        }
    }
    return -1;
}

char Simulacion::getTipoPoblacion(int i, int j)
{
    for(auto k=poblaciones.begin(); k!=poblaciones.end(); ++i){
        if(k->getCoordX() == i && k->getCoordY() == j){
            return k->getTipo();
        }
    }
}


dataPoblacion Simulacion::getPoblacion(int j)
{
    dataPoblacion aux; aux.tipo = 'C'; aux.coordY = aux.coordX = aux.sincomer = -1;
    int cont=0;
    for(auto i=poblaciones.begin();i!=poblaciones.end(); ++i){
        if(cont==j){
            aux.tipo = i->getTipo();
            aux.coordX = i->getCoordX();
            aux.coordY = i->getCoordY();
            aux.sincomer = i->getSincomer();
            return aux;
        }
        cont++;
    }
    return aux;
}


int Simulacion::getFilas() { return mapa->getFilas(); }


int Simulacion::getColumnas() { return mapa->getColumnas(); }


int Simulacion::getCantPoblaciones() { return cantPoblaciones; }


char Simulacion::getPoblacion(int l,int x, int y)
{
    int cont=0;
    for(auto i = poblaciones.begin(); i != poblaciones.end(); ++i){
        if(cont == l){
            if(i->getCoordX() == x && i->getCoordY() == y){
                return i->getTipo();
            }
        }
        cont++;
    }
    return 'N';
}

int Simulacion::getDiaActual() { return diaActual; }


int Simulacion::getCantDias() { return cantDias; }


int Simulacion::getTiempo() { return tiempo; }


void Simulacion::setPoblacion(char tipo, int x, int y, int sincomer)
{
    Poblacion aux;
    aux.setTipo(tipo); aux.setCoordX(x); aux.setCoordY(y), aux.setsincomer(sincomer);
    poblaciones.push_back(aux);
}


void Simulacion::setMapa(int f, int c) { this->mapa = new Mapa(f,c); }


void Simulacion::setDatos(int cantDias, int diaActual, int cantPoblaciones, int tiempo)
{
    this->cantDias = cantDias;
    this->diaActual = diaActual;
    this->cantPoblaciones = cantPoblaciones;
    this->tiempo = tiempo;
}

void Simulacion::setDiaActual(int diaActual) { this->diaActual = diaActual; }


void Simulacion::setCantDias(int cantDias) { this->cantDias = cantDias; }


void Simulacion::setTiempo(int tiempo) { this->tiempo = tiempo; }


void Simulacion::setTipoCasillero(int i,int j,int tipo) { this->mapa->setTipo(i,j,tipo); }


void Simulacion::setPastizalCasillero(int i, int j, bool estado, int crece, int muere)
{
    this->mapa->setPastizal(i,j,estado,crece,muere);
}

