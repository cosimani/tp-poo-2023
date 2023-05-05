#include "login.h"
#include "ui_login.h"

#include <QDebug>
#include <QMessageBox>

#include "ventana.h"

Login::Login(QWidget *parent) : QWidget(parent),
                                ui(new Ui::Login),
                                manager( new QNetworkAccessManager( this ) ),
                                ventana( new Ventana )
{
    ui->setupUi(this);


    connect( ui->pbIngresar, SIGNAL( pressed() ), this, SLOT( slot_validar_con_API() ) );
    connect( ui->leClave, SIGNAL( returnPressed() ), this, SLOT( slot_validar_con_API() ) );
    connect( manager, SIGNAL( finished( QNetworkReply * ) ),
             this, SLOT( slot_descargaFinalizada( QNetworkReply * ) ) );

    ui->leUsuario->setFocus();
}

Login::~Login()
{
    delete ui;
}

void Login::slot_validar_con_API()  {
    // Aqui armar la solicitud para el webservice

    QString sUrl = "https://www.cesarosimani.com.ar/poo/api.php?usuario=";
    sUrl += ui->leUsuario->text();
    sUrl += "&clave=";
    sUrl += ui->leClave->text();

    manager->get( QNetworkRequest( QUrl( sUrl ) ) );
}

/**
 * @brief Login::slot_descargaFinalizada se ejecuta cuando la respuesta llega aqui
 * @param reply es toda la info que mando el server
 */
void Login::slot_descargaFinalizada( QNetworkReply * reply )  {
    QByteArray ba = reply->readAll();
    qDebug() << ba;

    QString respuestaServer( ba );

    if ( respuestaServer.simplified().startsWith( "denegado" ) )  {
        QMessageBox::critical( this, "Sin permisos", "Usuario y/o clave incorrectos." );
    }
    else  {
        if ( respuestaServer.split( "::" ).size() > 3 )  {
            QString nombre = respuestaServer.split( "::" ).at( 1 );
            QString apellido = respuestaServer.split( "::" ).at( 2 );
            ventana->setLabelBienvenida( nombre + " " + apellido );
        }

        ventana->show();
    }
}


