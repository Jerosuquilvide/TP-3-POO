#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    miGestor = new GestorArchivos;

    miGestor->getConfig();
    dataConfig datos = miGestor->getConfig();
    if(datos.existe){
    this->ui->SpinFilas->setValue(datos.filas);
    this->ui->SpinColumnas->setValue(datos.columnas);
    this->ui->SpinMesetas->setValue(datos.mpasto);
    this->ui->SpinTipoA->setValue(datos.tipoA);
    this->ui->SpinTipoB->setValue(datos.tipoB);
    this->ui->SpinDias->setValue(datos.dias);
    this->ui->SpinTiempo->setValue(datos.tiempo);
    }

    else{
        QMessageBox::StandardButton  r1;
        r1 = QMessageBox::information(this,"No se encontro configuracion previa","Al no encontrar los valores, se usan los predeterminados, para cambiar esto "
                                                                                 "setee sus propios valores y toque el boton de guardar",QMessageBox::Ok);
        this->ui->SpinFilas->setValue(10);
        this->ui->SpinColumnas->setValue(10);
        this->ui->SpinMesetas->setValue(15);
        this->ui->SpinTipoA->setValue(5);
        this->ui->SpinTipoB->setValue(5);
        this->ui->SpinDias->setValue(10);
        this->ui->SpinTiempo->setValue(2);
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_GuardarValores_clicked()
{
    dataConfig nuevaConfig;
    nuevaConfig.filas =  this->ui->SpinFilas->text().toInt();
    nuevaConfig.columnas = this->ui->SpinColumnas->text().toInt();
    nuevaConfig.mpasto = this->ui->SpinMesetas->text().toInt();
    nuevaConfig.tipoA = this->ui->SpinTipoA->text().toInt();
    nuevaConfig.tipoB = this->ui->SpinTipoB->text().toInt();
    nuevaConfig.dias = this->ui->SpinDias->text().toInt();
    nuevaConfig.tiempo = this->ui->SpinTiempo->text().toInt();
    miGestor->setConfig(nuevaConfig);
}

void MainWindow::on_Simular_clicked()
{

    dataConfig data;
    data.filas =  this->ui->SpinFilas->text().toInt();
    data.columnas = this->ui->SpinColumnas->text().toInt();
    data.mpasto = this->ui->SpinMesetas->text().toInt();
    data.tipoA = this->ui->SpinTipoA->text().toInt();
    data.tipoB = this->ui->SpinTipoB->text().toInt();
    data.dias = this->ui->SpinDias->text().toInt();
    data.tiempo = this->ui->SpinTiempo->text().toInt();

    miSimulacion = new Simulacion(data.filas,data.columnas,data.mpasto,
                                  data.tipoA,data.tipoB,data.dias,data.tiempo);

    Mostrar_Simulacion * ventana = new Mostrar_Simulacion(this);
    ventana->setModal(true);
    ventana->setSimulacion(miSimulacion,false);
    ventana->show();
}

void MainWindow::on_RecuperarSimulacion_clicked()
{
    miSimulacion = miGestor->cargarSimulacion();
    Mostrar_Simulacion * ventana = new Mostrar_Simulacion(this);
    ventana->setModal(true);
    ventana->setSimulacion(miSimulacion,true);
    ventana->show();
}

