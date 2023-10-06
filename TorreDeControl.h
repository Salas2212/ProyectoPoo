#ifndef TORRE_DE_CONTROL_H
#define TORRE_DE_CONTROL_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory>
#include "PuertaDeEmbarque.h"
#include "Vuelo.h"
#include "Aeronave.h"

using namespace std;

/*
    La torre de control se encarga de entregar y recibir la informacion sobre las aeronaves.

    Se hizo enfasis en mantener las coordenadas de las aeronaves actualizadas, y que todas las 
    aeronaves puedan saber la ubicacion del resto en "tiempo real".

    Ademas, tambien se encarga de asignar las puertas, y manipularlas.

    Aqui es donde se guardan los punteros a las aeronaves.

*/

class TorreDeControl {
public:
    vector<pair<double, double>> coordenadas_aeronaves;
    vector<PuertaDeEmbarque> puertas_embarques;
    vector<Vuelo*> vuelos;
    
    // aeronaves
    // unique_ptr nos ayudara a guardar 
    // cualquier tipo de clase derivada de Aeronave.
    vector< unique_ptr<Aeronave> > aero; 
    
    // Desde la misma creacion de la torre de control se definen y se crean las puertas de embarque.
    TorreDeControl(int numeroDePuertasEmbarque);

    // Actualiza la ubicacion de una sola aeronave y la guarda
    void actualizar_ubi_aero(int id);

    // Devuelve las coordenadas de una aeronave.
    pair<double, double> obtener_ubi(int id);

    // Agrega una aeronave al sistema
    void agregarAeronave(unique_ptr<Aeronave>&nuevaAeronave);

    // Actualiza toda la informacion de coordenadas para todas.
    void actualizarTodasLasAeronaves();

    // Asigna una puerta a un vuelo. Es util a la hora de generar un vuelo.
    int asignar_puertas(Vuelo* flight);
    void desocupar_puerta(int cualPuerta);

    bool hayPuertasDisponibles(int &numeroPuertaDisponible);
    bool hayAeronavesDisponibles(int &numeroAeronaveDisponible);
};

#endif
