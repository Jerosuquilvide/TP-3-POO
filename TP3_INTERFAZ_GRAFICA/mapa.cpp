#include "mapa.h"
#include <iostream>
Mapa::Mapa()
{
    mapa = NULL;

}

Mapa::Mapa(int f,int c){
    mapa = NULL;
    this->f = f;
    this->c = c;

    mapa = new vector<Casillero*>[f];
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            mapa[i].push_back(new Casillero(1));
        }
    }
}

void Mapa::setPastizal(int i, int j, bool estado, int crece, int muere)
{
    mapa[i][j]->setPastizal(estado,crece,muere);
}

void Mapa::crearMapa(int cantpastos){

    //Creo un mapa que va a estar compuesto por vector que contienen punteros a casillero
    mapa = new vector<Casillero*>[f];

    //Cargo la matriz con casilleros de tipo 1
    for(int i=0; i<f; i++){
        for(int j=0; j<c; j++){
            mapa[i].push_back(new Casillero(1));
        }
    }

    int fcentro = f/2 ; int ccentro = c/2;

    mapa[fcentro][ccentro]->setTipo(2);

    int cont = 0;   //contador para controlar cantidad de mesetas con pasto
    int dir;        //Variable de direccion

    int TotalM = (f*c)*2; //Con este calculo cambio la cant de mesetas
    while(cont<cantpastos){
        while(cont<TotalM){

            dir=1+rand()%4; //N° azar (entre 1 - 4) .. 1:Izquierda 2:Derecha 3:Arriba 4:Abajo

            if(dir==1){ //Izquierda
                if(ccentro!=0){ //Si no esta en la columna 0 puede desplazar a la izquierda
                    ccentro-=1;
                    mapa[fcentro][ccentro]->setTipo(2);
                    cont++;
                }
            }
            if(dir==2){ //Derecha
                if(ccentro!=c-1){ //Si no esta en la columna c-1 puede desplazar a la derecha
                    ccentro+=1;
                    mapa[fcentro][ccentro]->setTipo(2);
                    cont++;
                }
            }
            if(dir==3){ //Arriba
                if(fcentro!=0){ //Si no esta en la fila 0 puede desplazar hacia arriba
                    fcentro-=1;
                    mapa[fcentro][ccentro]->setTipo(2);
                    cont++;
                }
            }
            if(dir==4){ //Abajo
                if(fcentro!=f-1){ //Si no esta en la fila f-1 puede desplazar hacia abajo
                    fcentro+=1;
                    mapa[fcentro][ccentro]->setTipo(2);;
                    cont++;
                }
            }
        }

    }
    cont = 0;

    while(cont<cantpastos){ //mpasto = mesetas con pasto...

        //De forma aleatoria selecciono una posicion en la matriz
        fcentro=(1+rand()%f)-1;
        ccentro=(1+rand()%c)-1;

        if(mapa[fcentro][ccentro]->getTipo()==2){ //Si en esa posicion hay un 2 (meseta) reemplazo por 3 (M c/pasto)
            mapa[fcentro][ccentro]->crearPastizal();
            cont++;
        }
    }
}

void Mapa::setFilas(int f)
{
    this->f = f;
}

void Mapa::setColumnas(int c)
{
    this->c = c;
}

void Mapa::setTipo(int i,int j,int tipo)
{
    mapa[i][j]->setTipo(tipo);
}

void Mapa::actualizar(int x, int y)
{
    if(mapa[x][y]->getTipo()==3){
        if(mapa[x][y]->getEstado()==true){
            mapa[x][y]->setEstado(false);
            mapa[x][y]->setCrece(0);
            mapa[x][y]->setMuere(0);
        }
    }
}

void Mapa::modificarmapa(int x,int y){

    if(mapa[x][y]->getTipo() == 3){
        if(mapa[x][y]->getEstado()==false){
            mapa[x][y]->setCrece(mapa[x][y]->getCrece()+1);
            if(mapa[x][y]->getCrece() == 5){
                mapa[x][y]->setCrece(0);
                mapa[x][y]->setEstado(true);
                mapa[x][y]->setMuere(10);
            }
        }else if(mapa[x][y]->getEstado()==true){
                    mapa[x][y]->setMuere(mapa[x][y]->getMuere()-1);
                    if(mapa[x][y]->getMuere() == 0){
                        mapa[x][y]->setEstado(false);
                        mapa[x][y]->setCrece(0);
                        mapa[x][y]->setMuere(10);
                    }
        }
    }
}

bool Mapa::tienePasto(int i,int j)
{
    return mapa[i][j]->tienePasto();
}

int Mapa::getFilas(){ return f; }

int Mapa::getColumnas(){ return c; }

int Mapa::getTipo(int i,int j){ return mapa[i][j]->getTipo(); }

bool Mapa::getEstado(int i,int j){ return mapa[i][j]->getEstado(); }

int Mapa::getCrece(int i, int j){ return mapa[i][j]->getCrece(); }

int Mapa::getMuere(int i, int j) { return mapa[i][j]->getMuere(); }

