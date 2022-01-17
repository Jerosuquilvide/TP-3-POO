/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_6;
    QLabel *label_7;
    QVBoxLayout *verticalLayout;
    QSpinBox *SpinFilas;
    QSpinBox *SpinColumnas;
    QSpinBox *SpinMesetas;
    QSpinBox *SpinTipoA;
    QSpinBox *SpinTipoB;
    QSpinBox *SpinDias;
    QSpinBox *SpinTiempo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Simular;
    QPushButton *GuardarValores;
    QPushButton *RecuperarSimulacion;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(345, 276);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(10);
        font.setBold(true);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_4);

        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_5);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_2);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_6);

        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(label_7);


        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        SpinFilas = new QSpinBox(centralwidget);
        SpinFilas->setObjectName(QString::fromUtf8("SpinFilas"));

        verticalLayout->addWidget(SpinFilas);

        SpinColumnas = new QSpinBox(centralwidget);
        SpinColumnas->setObjectName(QString::fromUtf8("SpinColumnas"));

        verticalLayout->addWidget(SpinColumnas);

        SpinMesetas = new QSpinBox(centralwidget);
        SpinMesetas->setObjectName(QString::fromUtf8("SpinMesetas"));

        verticalLayout->addWidget(SpinMesetas);

        SpinTipoA = new QSpinBox(centralwidget);
        SpinTipoA->setObjectName(QString::fromUtf8("SpinTipoA"));

        verticalLayout->addWidget(SpinTipoA);

        SpinTipoB = new QSpinBox(centralwidget);
        SpinTipoB->setObjectName(QString::fromUtf8("SpinTipoB"));

        verticalLayout->addWidget(SpinTipoB);

        SpinDias = new QSpinBox(centralwidget);
        SpinDias->setObjectName(QString::fromUtf8("SpinDias"));

        verticalLayout->addWidget(SpinDias);

        SpinTiempo = new QSpinBox(centralwidget);
        SpinTiempo->setObjectName(QString::fromUtf8("SpinTiempo"));

        verticalLayout->addWidget(SpinTiempo);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        Simular = new QPushButton(centralwidget);
        Simular->setObjectName(QString::fromUtf8("Simular"));

        horizontalLayout_2->addWidget(Simular);

        GuardarValores = new QPushButton(centralwidget);
        GuardarValores->setObjectName(QString::fromUtf8("GuardarValores"));

        horizontalLayout_2->addWidget(GuardarValores);

        RecuperarSimulacion = new QPushButton(centralwidget);
        RecuperarSimulacion->setObjectName(QString::fromUtf8("RecuperarSimulacion"));

        horizontalLayout_2->addWidget(RecuperarSimulacion);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 345, 23));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Cantidad de Filas:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Cantidad de Columnas: ", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Cantidad de Mesetas con Pasto:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Cantidad de Ciervos Tipo A:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Cantidad de Ciervos Tipo B:", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Cantidad de Dias:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Duracion de cada Dia: ", nullptr));
        Simular->setText(QCoreApplication::translate("MainWindow", "Simular", nullptr));
        GuardarValores->setText(QCoreApplication::translate("MainWindow", "Guardar Valores Iniciales", nullptr));
        RecuperarSimulacion->setText(QCoreApplication::translate("MainWindow", "Recuperar Simulacion", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
