#include <bits/stdc++.h>
//#include "PuertaDeEmbarque.h"
//#include "Aeronave.h"
//#include "PuertaDeEmbarque.h"
using namespace std;
class TorreDeControl{
	public: 
		vector<pair<double, double> > coordenadas_aeronaves;
		vector<PuertaDeEmbarque>puertas_embarques;
		vector<Vuelo*>vuelos;

		vector<Aeronave*>aeronaves;
        
        TorreDeControl(int numeroDePuertasEmbarque){
            for(int i = 0 ; i < numeroDePuertasEmbarque ; i ++){
                // 1/3 de las puertas son nacionales
                // y las otras internacionales
                string ubic;
                if(i < numeroDePuertasEmbarque/3)ubic = "Vuelos Nacionales";
                else ubic = "Vuelos Internacionales";
                PuertaDeEmbarque nueva(i, ubic);
                puertas_embarques.push_back(nueva);
            }
        }

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

	    int asignar_puertas(Vuelo* flight){
            bool hayDisponibilidad = false;
            int cualPuerta = 0;
            for(int i = 0 ; i < puertas_embarques.size() ; i ++){
                if(puertas_embarques[i].disponible){
                    hayDisponibilidad = true;
                    cualPuerta = i;
                    break;
                }
            }
            if(!hayDisponibilidad){
                cout << "El vuelo no fue asignado pues no hay puertas Disponibles\n";
                return -1;
            }else{
                flight->puerta_embarque = cualPuerta;
                puertas_embarques[cualPuerta].disponible = false;
                // Cereamos una hora de embarque al azar.
                int hora = rand() % 24;
                int minuto = rand() % 60;
                string result = to_string(hora)+ ":" + to_string(minuto);
                puertas_embarques[cualPuerta].hora_embarque = result;

                srand(time(NULL));
                Vuelo copia(flight);
                puertas_embarques[cualPuerta].historial.push_back(copia);

                return cualPuerta;
            }
        }

        void desocupar_puerta(int cualPuerta){
            puertas_embarques[cualPuerta].disponible = true;
        }
			
		
};
