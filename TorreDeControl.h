#include <bits/stdc++.h>
//#include "PuertaDeEmbarque.h"
#include "Aeronave.h"
using namespace std;
class TorreDeControl{
		public: 
			vector<pair<double, double> > coordenadas_aeronaves;
			vector<PuertaDeEmbarque>puertas_embarques;
			vector<*vuelo>vuelos;

			vector<Aeronave*>aeronaves;
			void actualizar_ubi_aero(int id){
				coordenadas_aeronaves[id] = aeronaves[id]->obtenerCoordenadas();
				for(int i = 0 ; i < aeronaves.size() ; i ++){
						aeronaves[i]->consultarCoordenadasAero(id, aeronaves[id]->obtenerCoordenadas());
				}
			}
			pair<double, double> obtener_ubi(int id){
				return coordenadas_aeronaves[id];
			}
			void agregarAeronave(Aeronave* aero){
					aero->id = aeronaves.size();
					aero->guardar_coordenadas();
					aeronaves.push_back(aero);
					coordenadas_aeronaves.push_back({0, 0});
					actualizar_ubi_aero(aero->id);
			}
			void actualizarTodasLasAeronaves(){
				for(int i = 0 ; i < aeronaves.size() ; i ++){
					aeronaves[i]->guardar_coordenadas();
					coordenadas_aeronaves[i] = aeronaves[i]->coordenadas;
				}
				for(int i = 0 ; i < aeronaves.size() ; i ++){
					aeronaves[i]->reiniciar(coordenadas_aeronaves);
				}

			}
			void eliminarAeronave(int id){
				vector<Aeronave*>aux;	
				for(auto aeronave : aeronaves){
					if(aeronave->id != id) aux.push_back(aeronave);
				}
				aeronaves = aux;
				actualizarTodasLasAeronaves();
			}
};
