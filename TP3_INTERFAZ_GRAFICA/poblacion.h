#ifndef POBLACION_H
#define POBLACION_H

class Poblacion
{
private:
    int sincomer;
    int coordX;
    int coordY;
    char tipo;
public:
    Poblacion();
    Poblacion(char tipo);

    // *********** Set ***********
    void setComio(bool x);
    void setsincomer(int x);
    void setCoordX(int coordX);
    void setCoordY(int coordY);
    void setTipo(char tipo);

    // *********** Get ***********
    int getSincomer();
    int getCoordX();
    int getCoordY();
    char getTipo();
};

#endif // POBLACION_H
