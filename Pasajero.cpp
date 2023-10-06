#include "Pasajero.h"
#include <iostream>

using namespace std;

void Pasajero::setVuelo(string vuelo) {
    NoVuelo = vuelo;
}

int Pasajero::obtener_numero_maletas() {
    return numero_maletas;
}

void Pasajero::poner_numero_maletas(int numeroMaletas) {
    numero_maletas = numeroMaletas;
}
void Pasajero::imprimirInfo(){
    cout << "Nacionalidad: " << nacionalidad<< "\n";
    cout << "Numero de maletas: " << numero_maletas << "\n";
    cout << "Resumen info medica: " << resumen_infomedica << "\n";
    cout << "Cedula: " << cedula << "\n";
    cout << "Nombres: " << nombres << "\n";
    cout << "Apellidos: " << apellidos << "\n";
    cout << "Fecha de nacimiento: " << fecha_de_nacimiento << "\n";
    cout << "Genero: " << genero << "\n";
    cout << "Direccion: " << direccion << "\n";
    cout << "Numero de telefono: " << numero_telefono<< "\n";
    cout << "Correo " << correo << "\n";
}

void Tripulacion::imprimirInfoTripulacion(){
    imprimirInfo();
    cout << "Puesto: " << puesto << "\n";
    cout << "Anios de experiencia: " << anios_experiencia << "\n";
    cout << "Cantidad maxima de horas diarias: " << cant_max_horasdiarias << "\n";
}