#ifndef PASAJERO_H
#define PASAJERO_H

#include <string>

using namespace std;

class Pasajero {
public:
    string nacionalidad;
    int numero_maletas;
    string resumen_infomedica;
    int cedula;
    string nombres;
    string apellidos;
    string fecha_de_nacimiento;
    string genero;
    string direccion;
    long long numero_telefono;
    string correo;

    string NoVuelo;

    void setVuelo(string vuelo);
    int obtener_numero_maletas();
    void poner_numero_maletas(int numeroMaletas);

    void imprimirInfo();
};



class Tripulacion : public Pasajero{
	public:
		string puesto;
		long long anios_experiencia;
		long long cant_max_horasdiarias;	
        void imprimirInfoTripulacion();
};

#endif
