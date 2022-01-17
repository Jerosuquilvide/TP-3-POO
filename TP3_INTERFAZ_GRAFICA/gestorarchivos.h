#ifndef GESTORARCHIVOS_H
#define GESTORARCHIVOS_H
#include <vector>
#include <iostream>
#include <fstream>
#include <simulacion.h>

struct dataPastizal{
    bool estado;
    int crece;
    int muere;
};

struct dataCasillero{
    int tipo;
};

struct dataMapa{
    int f;
    int c;
};

struct dataSimulacion{
    int cantPoblaciones;
    int diaActual;
    int cantDias;
    int tiempo;
};

struct dataConfig{
    int filas;
    int columnas;
    int mpasto;
    int tipoA;
    int tipoB;
    int dias;
    int tiempo;
    bool existe ;
};

using namespace std;

class GestorArchivos
{
public:
    GestorArchivos();

    Simulacion* cargarSimulacion();

    void guardarSimulacion(Simulacion * simulacion);

    void guardarCasillero(int i,int j, Simulacion * simulacion, ofstream &archivoC);

    void guardarPastizal(int i,int j,Simulacion * simulacion,ofstream &archivoP);

    void guardarPoblacion(int i,int j,Simulacion * simulacion, ofstream &archivoPob,int &cont);

    void setConfig(dataConfig x);

    dataConfig getConfig();

};

#endif // GESTORARCHIVOS_H
