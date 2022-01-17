#ifndef PASTIZAL_H
#define PASTIZAL_H


class Pastizal
{
private:
    bool estado;
    int crece;
    int muere;
public:
    Pastizal();

    //Constructor para crear pastizales que recupero
    Pastizal(bool estado, int crece, int muere);


    // *********** Set ***********
    void setEstado(bool estado);
    void setCrece(int crece);
    void setMuere(int muere);


    // *********** Get ***********
    bool getEstado();
    int getCrece();
    int getMuere();

};

#endif // PASTIZAL_H
