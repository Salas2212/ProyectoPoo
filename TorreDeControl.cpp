#include "TorreDeControl.h"
#include <iostream>

using namespace std;

TorreDeControl::TorreDeControl(int numeroDePuertasEmbarque) {
    /*
        Para simular el sistema, se decidio que 1/3 de las puertas serian para vuelos nacionales
        y otras para internacionales.
    */
    for (int i = 0; i < numeroDePuertasEmbarque; i++) {
        string ubic;
        if (i < numeroDePuertasEmbarque / 3) ubic = "Vuelos Nacionales";
        else ubic = "Vuelos Internacionales";
        PuertaDeEmbarque nueva(i, ubic);
        puertas_embarques.push_back(nueva);
    }
}

void TorreDeControl::actualizar_ubi_aero(int id) {
    coordenadas_aeronaves[id] = aero[id]->obtenerCoordenadas();
    for (int i = 0; i < aero.size(); i++) {
        aero[i]->consultarCoordenadasAero(id, aero[id]->obtenerCoordenadas());
    }
}

pair<double, double> TorreDeControl::obtener_ubi(int id) {
    return coordenadas_aeronaves[id];
}

void TorreDeControl::agregarAeronave(unique_ptr<Aeronave> &nuevaAeronave) {
    nuevaAeronave->id = aero.size();
    nuevaAeronave->guardar_coordenadas();
    aero.push_back(move(nuevaAeronave));
    coordenadas_aeronaves.push_back({0, 0});
    for (int i = 0; i < aero.size(); i++) {
        aero[i]->agregarAeronaveAlSistema(); // agrego una aeronave para todas las que estan en el sistema.
    }
    for(int i = 0 ; i < aero.size() -1 ; i ++){
        aero.back()->agregarAeronaveAlSistema(); // agrego celdas para guardar la informacion de todas las que ya estan en el sistema.
    }

    // Le pasa todas las coordenadas actualizadas
    // a la nueva aeronave
    aero.back()->reiniciar(coordenadas_aeronaves); 
    

    actualizar_ubi_aero(aero.size()-1); // Actualiza las coordenadas de dicha aeronave en todos los lugares.
}

void TorreDeControl::actualizarTodasLasAeronaves() {
    for (int i = 0; i < aero.size(); i++) {
        aero[i]->guardar_coordenadas();
        coordenadas_aeronaves[i] = aero[i]->coordenadas;
    }
    for (int i = 0; i < aero.size(); i++) {
        aero[i]->reiniciar(coordenadas_aeronaves);
    }
}

int TorreDeControl::asignar_puertas(Vuelo* flight) {
    int cualPuerta;
    bool hayDisponibilidad = hayPuertasDisponibles(cualPuerta);
    if (!hayDisponibilidad) {
        cout << "El vuelo no fue asignado pues no hay puertas Disponibles\n";
        return -1;
    } else {
        flight->puerta_embarque = cualPuerta;
        puertas_embarques[cualPuerta].setDisponible(false);
        int hora = rand() % 24;
        int minuto = rand() % 60;
        string result = to_string(hora) + ":" + to_string(minuto);
        puertas_embarques[cualPuerta].setHoraEmbarque(result);
        puertas_embarques[cualPuerta].setVueloAsignado(flight);
        srand(time(NULL));
        puertas_embarques[cualPuerta].agregarHistorial(flight);
        return cualPuerta;
    }
}

void TorreDeControl::desocupar_puerta(int cualPuerta) {
    puertas_embarques[cualPuerta].setDisponible(true);
}

// Funcion que checkea si hay alguna puerta disponible, y si la hay guarda el numero en el parametro
// recibido. Sino, retorna falso y el numero de puerta retornado es -1.
bool TorreDeControl::hayPuertasDisponibles(int &numeroPuertaDisponible){
    bool hayDisponibilidad = false;
    int cualPuerta = 0;
    for (int i = 0; i < puertas_embarques.size(); i++) {
        if (puertas_embarques[i].getDisponible()) {
            hayDisponibilidad = true;
            cualPuerta = i;
            break;
        }
    }
    numeroPuertaDisponible = cualPuerta;
    return hayDisponibilidad;
}

bool TorreDeControl::hayAeronavesDisponibles(int &numeroDeAeronaveDisponible){
    bool hayDisponibilidad = false;
    int cualAeronave = 0;
    for (int i = 0; i < aero.size(); i++) {
        if (aero[i]->disponible()) {
            hayDisponibilidad = true;
            cualAeronave = i;
            break;
        }
    }
    numeroDeAeronaveDisponible = cualAeronave;
    return hayDisponibilidad;
}