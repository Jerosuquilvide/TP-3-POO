#include "mostrar_simulacion.h"
#include "ui_mostrar_simulacion.h"
#include<QMessageBox>
#include<fstream>
using namespace std;
Mostrar_Simulacion::Mostrar_Simulacion(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Mostrar_Simulacion)
{
    ui->setupUi(this);
    timer1 = new QTimer();
    timer1->connect(timer1,SIGNAL(timeout()),this,SLOT(incrementar()));
}

Mostrar_Simulacion::~Mostrar_Simulacion()
{
    delete ui;
}

void Mostrar_Simulacion::setSimulacion(Simulacion *simulacion,bool band)
{
    if(band){
        this->dias = simulacion->getDiaActual();
        this->tiempo = simulacion->getTiempo();
    }
    this->simulacion = simulacion;   int cont;

    this->labels = new QLabel**[simulacion->getFilas()];
        for (int i = 0; i < simulacion->getFilas(); i++) {
            this->labels[i] = new QLabel*[simulacion->getColumnas()];
            for (int j = 0; j < simulacion->getFilas(); j++) {

                    this->labels[i][j] = new QLabel();

                    this->labels[i][j]->setText(QString::number(simulacion->getTipoCasillero(i,j)));


                    if(simulacion->tienePasto(i,j) == true){ //TIENE PASTO

                        if(simulacion->getEstadoPastizal(i,j) == true){
                            this->labels[i][j]->setText( labels[i][j]->text() + QString(QChar::fromLatin1('V')));
                        }
                        else{
                            this->labels[i][j]->setText( labels[i][j]->text() + QString(QChar::fromLatin1('M')));
                        }

                        cont=0;
                        for(int l=0;l<simulacion->getCantPoblaciones();l++){
                            if(simulacion->getPoblacion(l,i,j) != 'N'){
                                this->labels[i][j]->setText( labels[i][j]->text() +
                                                             QString(QChar::fromLatin1(simulacion->getPoblacion(l,i,j))));
                                cont++;
                            }
                        }


                    }else { //NO TIENE PASTO
                        this->labels[i][j]->setText(QString::number(simulacion->getTipoCasillero(i,j)));
                        cont=0;
                        for(int l=0;l<simulacion->getCantPoblaciones();l++){
                            if(simulacion->getPoblacion(l,i,j) != 'N'){
                                this->labels[i][j]->setText( labels[i][j]->text() +
                                                             QString(QChar::fromLatin1(simulacion->getPoblacion(l,i,j))));
                                cont++;
                            }
                        }
                    }
                    this->ui->gridLayout->addWidget(labels[i][j] ,i,j);
            }


        }

}

void Mostrar_Simulacion::mostrarSimulacion(){
//Limpio los labels del dia anterior
    for(int i=0;i<simulacion->getFilas();i++){
        for(int j=0;j<simulacion->getColumnas();j++){
            this->labels[i][j]->clear();
        }
    }

for(int i=0;i<simulacion->getFilas();i++){
     for(int j=0;j<simulacion->getColumnas();j++){

         if(simulacion->tienePasto(i,j) == true){ //TIENE PASTO

             if(simulacion->getEstadoPastizal(i,j) == true){
                 this->labels[i][j]->setText( labels[i][j]->text() + QString(QChar::fromLatin1('V')));
             }
             else{
                 this->labels[i][j]->setText( labels[i][j]->text() + QString(QChar::fromLatin1('M')));
             }


             cont=0;
             for(int l=0;l<simulacion->getCantPoblaciones();l++){
                 if(simulacion->getPoblacion(l,i,j) != 'N'){
                     this->labels[i][j]->setText( labels[i][j]->text() +
                                                  QString(QChar::fromLatin1(simulacion->getPoblacion(l,i,j))));
                     cont++;
                 }
             }


              }
                        else { //NO TIENE PASTO
                                 this->labels[i][j]->setText(QString::number(simulacion->getTipoCasillero(i,j)));
                                 cont=0;
                                 for(int l=0;l<simulacion->getCantPoblaciones();l++){
                                     if(simulacion->getPoblacion(l,i,j) != 'N'){
                                         this->labels[i][j]->setText( labels[i][j]->text() +
                                                                      QString(QChar::fromLatin1(simulacion->getPoblacion(l,i,j))));
                                         cont++;
                                     }
                                 }
                             }

                     }
     }



}

void Mostrar_Simulacion::on_SalirSimulacion_clicked()
{
    close();
}


void Mostrar_Simulacion::on_GuardarSimulacion_clicked(){
            unGestor->guardarSimulacion(simulacion);
}


void Mostrar_Simulacion::on_EjecutarSimulacion_clicked(){
                    if(simulacion->getDiaActual() < simulacion->getCantDias()){
                                        MTime();
                            this->ui->EjecutarSimulacion->setDisabled(true);
                         }
    }



void Mostrar_Simulacion::on_PausarSimulacion_clicked(){
    if(timer1->isActive()){
            timer1->stop();
            this->ui->PausarSimulacion->setText("Continuar");
            this->ui->GuardarSimulacion->setDisabled(false);
        }else{
            this->ui->PausarSimulacion->setText("Pausar");
            timer1->start(1000);
            this->ui->GuardarSimulacion->setDisabled(true);
        }
}

void Mostrar_Simulacion::MTime(){
    timer1->setInterval(simulacion->getTiempo()*1000);
    timer1->start(1000);
}

void Mostrar_Simulacion::incrementar(){

if(this->cont < simulacion->getTiempo()) {
                        this->ui->lcdNumber->display(this->ui->lcdNumber->value() + 1);
                        this->cont++;
                        this->tiempo ++;
    }
    else{

                mostrarSimulacion();//Muestra la simulacion desde la UI
                simulacion->controlPoblaciones();//Controla a las poblaciones
               simulacion->accionPoblacion();//Acciones ciervos
                simulacion->actualizarCasillerosCiervos(); //Cambia el estado de los pastos si hay ciervos
                simulacion->actualizarMapa();//actualiza estado de los pastos
                simulacion->moverPoblaciones();//Mueve a las poblaciones

               this->dias ++;
               //simulacion->setDiaActual(dias);
               this->ui->LCDDias->display(this->dias);
              this->cont =0;
              this->tiempo = 0;
              this->ui->lcdNumber->display("0");
               if(this->dias == simulacion->getCantDias()){
                   QMessageBox::StandardButton respuesta1;
                   respuesta1 = QMessageBox::warning(this,"Simulacion","Simulacion Finalizada");//,QMessageBox::Ok | QMessageBox::Save );
                   if(respuesta1 == QMessageBox::Ok){
                       close();
                       simulacion->~Simulacion();
                   }

               }
        }

}


