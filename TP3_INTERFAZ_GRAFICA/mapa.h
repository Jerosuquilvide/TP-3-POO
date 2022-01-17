#ifndef MAPA_H
#define MAPA_H
#include <casillero.h>
#include <vector>

using namespace std;

class Mapa
{
private:
    vector<Casillero*> * mapa;
    int f;
    int c;
public:
    Mapa();

    //Crea mapa cuando recupero datos
    Mapa(int f, int c);

    //Crea pastizal cuando recupero dato
    void setPastizal(int i,int j,bool estado,int crece,int muere);

    //Crea mapa para iniciar una simulacion nueva
    void crearMapa(int cantpastos);


    // *********** Set ***********

    //Mapa
    void setFilas(int f);
    void setColumnas(int c);

    //Casillero
    void setTipo(int i,int j,int tipo);


    // *********** Get ***********

    //Mapa
    int getFilas();
    int getColumnas();

    //Casillero
    int getTipo(int i,int j);

    //Pastizal
    bool getEstado(int i,int j);
    int getCrece(int i,int j);
    int getMuere(int i,int j);

    //Modificadores para iteracion por dias
    void actualizar(int x, int y);
    void modificarmapa(int x,int y);

    bool tienePasto(int i,int j);
};

#endif // MAPA_H
