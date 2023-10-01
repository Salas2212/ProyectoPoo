#include <bits/stdc++.h>
//#include "Vuelo.h"
using namespace std;
class Vuelo{
    public:
		vector<Tripulacion>tripulacion;
		vector<Pasajero>pasajeros;
		string numero_de_identificacion;
		string fecha;
		string ciudad_origen;
		string ciudad_destino;
		int puerta_embarque;
		
		 // Constructor que recibe un puntero a Vuelo como parámetro
		Vuelo(Vuelo* vueloPtr) {
			// Copiar los valores del vuelo apuntado por vueloPtr a este objeto
			tripulacion = vueloPtr->tripulacion;
			pasajeros = vueloPtr->pasajeros;
			numero_de_identificacion = vueloPtr->numero_de_identificacion;
			fecha = vueloPtr->fecha;
			ciudad_origen = vueloPtr->ciudad_origen;
			ciudad_destino = vueloPtr->ciudad_destino;
			puerta_embarque = vueloPtr->puerta_embarque;
		}
		Vuelo(string num_identificacion, string fecha_vuelo, string origen, string destino, int puerta) {
			numero_de_identificacion = num_identificacion;
			fecha = fecha_vuelo;
			ciudad_origen = origen;
			ciudad_destino = destino;
			puerta_embarque = puerta;
		}
};
