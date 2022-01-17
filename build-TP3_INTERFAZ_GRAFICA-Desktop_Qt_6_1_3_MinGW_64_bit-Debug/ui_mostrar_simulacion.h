/********************************************************************************
** Form generated from reading UI file 'mostrar_simulacion.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MOSTRAR_SIMULACION_H
#define UI_MOSTRAR_SIMULACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mostrar_Simulacion
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *GuardarSimulacion;
    QPushButton *EjecutarSimulacion;
    QPushButton *PausarSimulacion;
    QLCDNumber *lcdNumber;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QLCDNumber *LCDDias;
    QPushButton *SalirSimulacion;

    void setupUi(QDialog *Mostrar_Simulacion)
    {
        if (Mostrar_Simulacion->objectName().isEmpty())
            Mostrar_Simulacion->setObjectName(QString::fromUtf8("Mostrar_Simulacion"));
        Mostrar_Simulacion->resize(1157, 991);
        gridLayoutWidget = new QWidget(Mostrar_Simulacion);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 20, 1141, 921));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        layoutWidget = new QWidget(Mostrar_Simulacion);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 960, 1131, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        GuardarSimulacion = new QPushButton(layoutWidget);
        GuardarSimulacion->setObjectName(QString::fromUtf8("GuardarSimulacion"));

        horizontalLayout->addWidget(GuardarSimulacion);

        EjecutarSimulacion = new QPushButton(layoutWidget);
        EjecutarSimulacion->setObjectName(QString::fromUtf8("EjecutarSimulacion"));

        horizontalLayout->addWidget(EjecutarSimulacion);

        PausarSimulacion = new QPushButton(layoutWidget);
        PausarSimulacion->setObjectName(QString::fromUtf8("PausarSimulacion"));

        horizontalLayout->addWidget(PausarSimulacion);

        lcdNumber = new QLCDNumber(layoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        horizontalLayout->addWidget(lcdNumber);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        LCDDias = new QLCDNumber(layoutWidget);
        LCDDias->setObjectName(QString::fromUtf8("LCDDias"));

        horizontalLayout->addWidget(LCDDias);

        SalirSimulacion = new QPushButton(layoutWidget);
        SalirSimulacion->setObjectName(QString::fromUtf8("SalirSimulacion"));

        horizontalLayout->addWidget(SalirSimulacion);


        retranslateUi(Mostrar_Simulacion);

        QMetaObject::connectSlotsByName(Mostrar_Simulacion);
    } // setupUi

    void retranslateUi(QDialog *Mostrar_Simulacion)
    {
        Mostrar_Simulacion->setWindowTitle(QCoreApplication::translate("Mostrar_Simulacion", "Dialog", nullptr));
        GuardarSimulacion->setText(QCoreApplication::translate("Mostrar_Simulacion", "Guardar", nullptr));
        EjecutarSimulacion->setText(QCoreApplication::translate("Mostrar_Simulacion", "Ejecutar", nullptr));
        PausarSimulacion->setText(QCoreApplication::translate("Mostrar_Simulacion", "Pausar", nullptr));
        label->setText(QCoreApplication::translate("Mostrar_Simulacion", "Dia:", nullptr));
        SalirSimulacion->setText(QCoreApplication::translate("Mostrar_Simulacion", "Salir", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mostrar_Simulacion: public Ui_Mostrar_Simulacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MOSTRAR_SIMULACION_H
