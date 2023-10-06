#ifndef PUERTA_DE_EMBARQUE_H
#define PUERTA_DE_EMBARQUE_H

#include <string>
#include <vector>
#include "Vuelo.h"

class Vuelo;


class PuertaDeEmbarque {
public:
	PuertaDeEmbarque(int id, std::string ubi);	// Desde el principio se debe definir una ubicacion.
	
    /*
        Getters y Setters.
    */

	Vuelo* getVueloAsignado();
    void setVueloAsignado(Vuelo* vuelo);

    bool getDisponible();
    void setDisponible(bool dispo);

    int getIdentificacion();
    void setIdentificacion(int& id);

    std::string getUbicacion();
    void setUbicacion(std::string& ubi);

    std::string getHoraEmbarque();
    void setHoraEmbarque(std::string horaEmb);

    std::vector<Vuelo> getHistorial();
    void agregarHistorial(Vuelo vuelo);
    void agregarHistorial(Vuelo *vuelo);
    void removerHistorial();

    void imprimirInfo(); // Funcion auxiliar.
    void imprimirHistorial(); // Funcion auxiliar.
	
private:
    Vuelo* vuelo_asignado;
    bool disponible;
    int identificacion;
    std::string ubicacion;
    std::string hora_embarque;
    std::vector<Vuelo> historial;
    
};

#endif
