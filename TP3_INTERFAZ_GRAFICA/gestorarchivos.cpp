#include "gestorarchivos.h"

GestorArchivos::GestorArchivos()
{

}

Simulacion* GestorArchivos::cargarSimulacion()
{
    dataMapa aux;
    ifstream archivoM("Archivo_mapa.dat",ios::binary | ios::in);
    archivoM.read((char *)&aux, sizeof(dataMapa));
    archivoM.close();

    Simulacion * simulacion = new Simulacion;
    simulacion->setMapa(aux.f,aux.c);

    dataSimulacion aux0;
    ifstream archivoS("Archivo_simulacion.dat",ios::binary | ios::in);
    archivoS.read((char *)&aux0, sizeof(dataSimulacion));
    simulacion->setDatos(aux0.cantDias,aux0.diaActual,aux0.cantPoblaciones,aux0.tiempo);
    archivoS.close();

    dataPoblacion aux1;
    ifstream archivoPob("Archivo_poblaciones.dat",ios::binary | ios::in);
    for(int i=0;i<simulacion->getCantPoblaciones(); i++){
        archivoPob.read((char *)&aux1, sizeof(dataPoblacion));
        simulacion->setPoblacion(aux1.tipo,aux1.coordX,aux1.coordY,aux1.sincomer);
    }
    archivoPob.close();

    dataCasillero aux2;
    dataPastizal aux3;
    ifstream archivoC("Archivo_casilleros.dat",ios::binary | ios::in);
    ifstream archivoP("Archivo_pastizales.dat",ios::binary | ios::in);

    for(int i=0; i<aux.f; i++){
        for(int j=0; j<aux.c; j++){

            archivoC.read((char *)&aux2, sizeof(dataCasillero));

            simulacion->setTipoCasillero(i,j,aux2.tipo);

            if(aux2.tipo == 3){
                archivoP.read((char *)&aux3, sizeof(dataPastizal));
                simulacion->setPastizalCasillero(i,j,aux3.estado,aux3.crece,aux3.muere);
            }
        }
        //cout << endl << endl ;
    }
    //cout << endl;
    archivoC.close();
    archivoP.close();

    return simulacion;
}


void GestorArchivos::guardarSimulacion(Simulacion * simulacion)
{

    ofstream archivoS ("Archivo_simulacion.dat", ios::out | ios::binary);
    dataSimulacion aux0;
    aux0.cantPoblaciones = simulacion->getCantPoblaciones();
    aux0.cantDias = simulacion->getCantDias();
    aux0.diaActual = simulacion->getDiaActual();
    aux0.tiempo = simulacion->getTiempo();
    archivoS.write((char *)&aux0, sizeof(dataSimulacion));
    archivoS.close();

    ofstream archivoM ("Archivo_mapa.dat", ios::out | ios::binary);
    dataMapa aux1;
    aux1.f = simulacion->getFilas(); aux1.c = simulacion->getColumnas();
    archivoM.write((char *)&aux1, sizeof(dataMapa));
    archivoM.close();

    ofstream archivoC ("Archivo_casilleros.dat", ios::out | ios::binary);
    ofstream archivoP ("Archivo_pastizales.dat", ios::out | ios::binary);
    ofstream archivoPob ("Archivo_poblaciones.dat", ios::out | ios::binary);

    int band;
    //bool band2;


    //MIENTRAS CARGO LOS ARCHIVOS Y MUESTRO
    int cont=0;
    for(int i=0; i<simulacion->getFilas(); i++){
        for(int j=0; j<simulacion->getColumnas(); j++){

            guardarCasillero(i,j,simulacion,archivoC); //GUARDO CASILLERO

            band = simulacion->getTipoCasillero(i,j);

            //cout << band;

            if(band == 3){

                guardarPastizal(i,j,simulacion,archivoP); //GUARDO PASTIZAL

                //band2 = simulacion->getEstadoPastizal(i,j);

                //if(band2 == true) cout << "V";
                //else cout << "M";

            }
            if(cont < simulacion->getCantPoblaciones()){
                guardarPoblacion(i,j,simulacion,archivoPob,cont); //GUARDO POBLACION
            }

            //cout << "   ";
        }
        //cout << endl << endl;
    }

    archivoP.close();
    archivoC.close();
    archivoPob.close();
}

void GestorArchivos::guardarCasillero(int i, int j, Simulacion *simulacion, ofstream &archivoC)
{
    dataCasillero aux;
    aux.tipo = simulacion->getTipoCasillero(i,j);
    archivoC.write((char *)&aux, sizeof(dataCasillero));
}

void GestorArchivos::guardarPastizal(int i, int j,Simulacion *simulacion, ofstream &archivoP)
{
    dataPastizal aux;
    aux.estado = simulacion->getEstadoPastizal(i,j);
    aux.crece = simulacion->getCrecePastizal(i,j);
    aux.muere = simulacion->getMuerePastizal(i,j);
    archivoP.write((char *)&aux, sizeof(dataPastizal));
}

void GestorArchivos::guardarPoblacion(int i, int j, Simulacion *simulacion, ofstream &archivoPob,int &cont)
{
    dataPoblacion aux;
    for(int k=0; k<simulacion->getCantPoblaciones(); k++){

        aux = simulacion->getPoblacion(k);

        if(aux.coordX == i && aux.coordY == j){
            //cout << aux.tipo <<" "<< aux.coordX <<" "<< aux.coordY ;
            archivoPob.write((char *)&aux, sizeof(dataPoblacion));
            cont++;
        }
    }
}

void GestorArchivos::setConfig(dataConfig x){
    ofstream archi;
    archi.open("config.txt");
    if(archi.is_open()){
        archi << x.filas;
        archi << '-';
        archi << x.columnas;
        archi << '-';
        archi << x.mpasto ;
        archi << '-';
        archi << x.tipoA ;
        archi << '-';
        archi << x.tipoB ;
        archi << '-';
        archi << x.dias ;
        archi << '-';
        archi << x.tiempo;
    }
}

dataConfig GestorArchivos::getConfig()
{
    string buffer;
    dataConfig aux;
    ifstream archivoConfig("config.txt");
    if(archivoConfig.is_open()){
        while(!archivoConfig.eof()){
                getline(archivoConfig,buffer,'-');
                aux.filas = stoi(buffer);

                getline(archivoConfig,buffer,'-');
                aux.columnas = stoi(buffer);

                getline(archivoConfig,buffer,'-');
                aux.mpasto = stoi(buffer);

                getline(archivoConfig,buffer,'-');
                aux.tipoA = stoi(buffer);

                getline(archivoConfig,buffer,'-');
                aux.tipoB = stoi(buffer);

                getline(archivoConfig,buffer,'-');
                aux.dias = stoi(buffer);

                getline(archivoConfig,buffer,'-');
                aux.tiempo = stoi(buffer);
        }
        aux.existe = true;

    }else {
        aux.existe = false;
    }
    archivoConfig.close();

    return aux;
}
