#ifndef VUELO_H
#define VUELO_H

#include <string>
#include <vector>
#include "Pasajero.h"
	
using namespace std;

class Tripulacion;
class Pasajero;

class Vuelo {
public:
    vector<Tripulacion*> tripulacion;
    vector<Pasajero*> pasajeros;
    string numero_de_identificacion;
    string fecha;
    string ciudad_origen;
    string ciudad_destino;
    int puerta_embarque;

    int idAeronave;
    // Constructores
    Vuelo();
    Vuelo(Vuelo* vueloPtr);
    Vuelo(string num_identificacion, string fecha_vuelo, string origen, string destino, int puerta);

    // Agregar punteros a verctores correspondientes.
    void agregarTripulante(Tripulacion* tripulante);
    void agregarPasajero(Pasajero *pasajero);
};

#endif
