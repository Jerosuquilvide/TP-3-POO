#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <gestorarchivos.h>
#include <mostrar_simulacion.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_GuardarValores_clicked();

    void on_Simular_clicked();

    void on_RecuperarSimulacion_clicked();

private:
    Ui::MainWindow *ui;
    GestorArchivos * miGestor = NULL;
    Simulacion * miSimulacion = NULL;
};
#endif // MAINWINDOW_H
