#ifndef MOSTRAR_SIMULACION_H
#define MOSTRAR_SIMULACION_H
#include<gestorarchivos.h>
#include <QDialog>
#include <simulacion.h>
#include<QLabel>
#include<QTimer>
namespace Ui {
class Mostrar_Simulacion;
}

class Mostrar_Simulacion : public QDialog
{
    Q_OBJECT

public:
    explicit Mostrar_Simulacion(QWidget *parent = nullptr);
    ~Mostrar_Simulacion();
    void setSimulacion(Simulacion * simulacion,bool band);
    void mostrarSimulacion();
private slots:
    void on_SalirSimulacion_clicked();

    void on_GuardarSimulacion_clicked();

    void on_EjecutarSimulacion_clicked();

    void on_PausarSimulacion_clicked();

    void MTime();

    void incrementar();

private:
    Ui::Mostrar_Simulacion *ui;
    Simulacion * simulacion = NULL;
    QLabel *** labels;
    QTimer *timer1;
    GestorArchivos *unGestor;
    int cont=0,tiempo=0,dias=0;
};

#endif // MOSTRAR_SIMULACION_H
