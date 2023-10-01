#include <bits/stdc++.h>
using namespace std;

class Aeronave{
	public:
		string registro_de_marca;
		int capacidad_de_pasajeros;
		int velocidad_max;
		int autonomia;
		int ano_fabricacion;
		string estado;
		pair<double, double>coordenadas;
		vector<pair<double, double> >coor_aeronaves;

		int id; // guardar identificacion para la torre de control.	
		
		//vector<vuelo>vuelos;
		Aeronave(string registro, int capacidad, int velMax, int aut, int yFabric, string state){
			registro_de_marca = registro;
			capacidad_de_pasajeros = capacidad;
			velocidad_max = velMax;
			autonomia = aut;
			ano_fabricacion = yFabric;
			estado = state;
		}
		void guardar_coordenadas(){
			double x = -100.0 + ((200.0) * (random() % 1000000L))/ 1000000L;
			srandom(time(NULL));
			double y = -100.0 + ((200.0) * (random() % 1000000L))/ 1000000L;
			coordenadas = {x, y};
		}
		pair<double, double>obtenerCoordenadas(){
				return coordenadas;
		}

		void consultarCoordenadasAero(int idAeronave, pair<double, double>ubi_aeronave){
			coor_aeronaves[idAeronave] = ubi_aeronave;
		}
		void reiniciar(vector<pair<double, double> > coordenadas_aeronaves /*coordenadas de todos actualizadas*/){
			coor_aeronaves = coordenadas_aeronaves;
		}
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
		}
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
		}
			
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
		}
};









