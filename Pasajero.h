#include <bits/stdc++.h>
using namespace std;

class pasajero{
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
		string numero_telefono;
		string correo;

		string NoVuelo;
		
		void obtenerVuelo(){
			// preguntar Torre de control.
		}
		int obtener_numero_maletas(){
			return numero_maletas;
		}
		void poner_numero_maletas(int numeroMaletas){
				numero_maletas = numeroMaletas;
		}


};


class Tripulacion : public pasajero{
	public:
		string puesto;
		int anios_experiencia;
		int cant_max_horasdiarias;
	
};

