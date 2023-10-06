#ifndef AERONAVE_H
#define AERONAVE_H

#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

class Aeronave {
public:
    string registro_de_marca;
    int capacidad_de_pasajeros;
    int velocidad_max;
    int autonomia;
    int ano_fabricacion;
    string estado;
    pair<double, double> coordenadas;
    vector<pair<double, double> > coor_aeronaves;


    int id; // guardar identificación para la torre de control.
	int numeroDeVuelosAsignados;
	int sillasRestantes;

    Aeronave(string registro, int capacidad, int velMax, int aut, int yFabric, string state);


	// Funciones del sistema de coordenadas.
    void guardar_coordenadas(); // Genera coordenadas al azar
    pair<double, double> obtenerCoordenadas(); // Retorna las coordenadas actuales

	//Por medio de esta, se actualiza la informacion que tiene esta aeronave sobre otra en el sistema.
    void consultarCoordenadasAero(int idAeronave, pair<double, double> ubi_aeronave); 

	// Se actualizan las coordenadas de todos.
    void reiniciar(vector<pair<double, double> > &coordenadas_aeronaves);

	// Es necesaria puesto que hay que cambiar el tamano del vector donde guardamos las coordenadas de cada aeronave.
	void agregarAeronaveAlSistema();

	// Avion, Helicoptero, JetPrivado...
    string getTipo();

	/*
	Estas funciones son virtual, puesto que la informacion especifica es diferente para cada subclase
	derivada de Aeronave. Es por esto que cuando se hereda, esta funcion se modifica, con lo cual
	la funcion debe ser virtual.
	
	*/
    virtual void imprimirInformacionEspecifica() {
        cout << "Información especifica no disponible para esta aeronave.\n";
    }
	virtual void editarInformacionEspecifica() {
		cout << "Información especifica no disponible para esta aeronave.\n";
	}

	// Funciones auxiliares para el menu.
	bool disponible();
	void asignarVuelo();
	void asignarSilla();

	// Funcion necesaria para cuando un Vuelo es despachado y se desea reusar la aeronave.
	void vaciarAeronave();
protected:
	string tipo;
};


class Avion : public Aeronave{
	public: 
		int altitud_maxima;
		int cantidad_de_motores;
		string categoria;
		Avion(string registro, int capacidad, int velMax, int aut, int yFabric, string state, int AltMax, int cantMotores, string category) : Aeronave(registro, capacidad, velMax, aut, yFabric, state){
			altitud_maxima = AltMax;
			cantidad_de_motores = cantMotores;
			categoria = category;
			tipo = "Avion";
		}
		// Sobreescritura de las funciones segun la clase
		void imprimirInformacionEspecifica() override {
			cout << "Altitud maxima: " << altitud_maxima << "\n";
			cout << "Cantidad de motores: " << cantidad_de_motores << "\n";
			cout << "Categoria: " << categoria << "\n";
		}
		void editarInformacionEspecifica() override ;
};

class Helicoptero : public Aeronave{
	public: 
		int cantidad_de_rotores;
		int capacidad_de_elevacion;
		string uso_especifico;
		Helicoptero(string registro, int capacidad, int velMax, int aut, int yFabric, string state, int cantRotores, int capacidadElevacion, string usoEspecifico) : Aeronave(registro, capacidad, velMax, aut, yFabric, state){
			cantidad_de_rotores = cantRotores;
			capacidad_de_elevacion = capacidadElevacion;
			uso_especifico = usoEspecifico;
			tipo = "Helicoptero";
		}
		// Sobreescritura de las funciones segun la clase
		void imprimirInformacionEspecifica() override {
			cout << "Cantidad de rotores: " << cantidad_de_rotores << "\n";
			cout << "Capacidad de elevacion: " << capacidad_de_elevacion << "\n";
			cout << "Uso especifico: " << uso_especifico << "\n";
		}
		void editarInformacionEspecifica() override ;
			
};

class JetPrivado : public Aeronave{
	public:
		string propietario;
		string lista_de_servicios_a_bordo;
		string lista_de_destinos_frecuentes;
		JetPrivado(string registro, int capacidad, int velMax, int aut, int yFabric, string state, string owner, string listaDeServiciosABordo, string listaDeDestinosFrecuentes) : Aeronave(registro, capacidad, velMax, aut, yFabric, state){
			propietario = owner;
			lista_de_servicios_a_bordo = listaDeServiciosABordo;
			lista_de_destinos_frecuentes = listaDeDestinosFrecuentes;
			tipo = "JetPrivado";
		}
		// Sobreescritura de las funciones segun la clase
		void imprimirInformacionEspecifica() override {
			cout << "Propietario: " << propietario << "\n";
			cout << lista_de_servicios_a_bordo << "\n";
			cout  << lista_de_destinos_frecuentes << "\n";
		}
		void editarInformacionEspecifica() override ;
};

#endif
