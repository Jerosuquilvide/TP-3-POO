#ifndef SIMULACION_H
#define SIMULACION_H
#include <mapa.h>
#include <poblacion.h>
#include <list>

struct dataPoblacion{
    int sincomer;
    int coordX;
    int coordY;
    char tipo;
};

using namespace std;

class Simulacion
{

    Mapa * mapa;
    list<Poblacion> poblaciones;
    int cantPoblaciones;
    int cantDias;
    int diaActual;
    int tiempo;
public:
    Simulacion();
    Simulacion(int f,int c,int mpasto,int tipoA,int tipoB,int CantDias,int tiempo);

    // *********** Set ***********

    void agregarPoblacion(char dato);

    void setPoblacion(char tipo,int X,int y,int sincomer);
    void setMapa(int f,int c);

    void setDatos(int cantDias,int diaActual,int cantPoblaciones,int tiempo);

    void setDiaActual(int diaActual);
    void setCantDias(int cantDias);
    void setTiempo(int tiempo);


    void setTipoCasillero(int i,int j,int tipo);
    void setPastizalCasillero(int i,int j,bool estado,int crece,int muere);

    // *********** Get ***********
    int getTipoCasillero(int i,int j);

    bool getEstadoPastizal(int i,int j);
    int getCrecePastizal(int i,int j);
    int getMuerePastizal(int i,int j);


    int getSinComerPoblacion(int i,int j);
    int getcoordXPoblacion(int i,int j);
    int getcoordYPoblacion(int i,int j);
    char getTipoPoblacion(int i,int j);

    dataPoblacion getPoblacion(int j);

    int getFilas();
    int getColumnas();
    int getCantPoblaciones();
    char getPoblacion(int l,int x,int y);

    int getDiaActual();
    int getCantDias();
    int getTiempo();

    // ***** Control simulacion *****
    void ControlSimulacion();           // <- Maneja todas las 5 funciones de abajo
    void controlPoblaciones();          //
    void accionPoblacion();             //
    void actualizarCasillerosCiervos(); //
    void actualizarMapa();              //
    void moverPoblaciones();            //

    bool tienePasto(int i,int j);

};

#endif // SIMULACION_H
