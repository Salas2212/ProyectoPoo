#include "Pasajero.h"
#include "Aeronave.h"
#include "Vuelo.h"
#include "PuertaDeEmbarque.h"
#include "TorreDeControl.h"
using namespace std;
/*
	Esta es la clase que mantiene la interfaz para hacer uso de todas las clases restantes.

	Solamente es publico el constructor y el menu, pues la idea es que los otros metodos esten protegidos y no se accedan por medio de 
	otros programas.



*/




class SistemaPrincipal{
    private:
        vector<Vuelo*>vuelos;
		vector<Tripulacion*>tripulacion;
        TorreDeControl torrePrincipal;

		// Se crea una referencia, esto es para no tener que poner torrePrincipal.aero, sino solo aeronaves,
		// de manera que el codigo sea mas legible.
		vector<unique_ptr<Aeronave> >&aeronaves;

		
		int getCantidadAeronaves();
		
		void obtenerInfoAeronave(int idx);
		int seleccionMenu(); // Procede segun lo que se eligio en el menu.
		

		//1
		void comprarUnVuelo();
		//2
		void consultarPuertasDeEmbarque();

		//3
		void consultarVuelos(bool expandible, bool imprimirSillas);
		//5
		void construirAeronave(); // La construye y la guarda inmediatamente

		//6
		void consultarInformacionAeronaves();

		//7 
		
		void editarInformacionAeronave();
		void editarInformacionAeronave(int i); // Polimorfismo

		//8
		void generarVuelo();

		//9
		void agregarTripulacionAlSistema();
		Pasajero* crearPasajero();
		Pasajero* pasajeroPrecreado(); // Funcion para crear un pasajero rapidamente nada mas para probar el programa.
		Tripulacion* crearTripulacion();
		Tripulacion* tripulacionPrecreada(); // Funcion para crear un tripulante rapidamente nada mas para probar el programa.

		//10
		void consultarTripulaciones();
		void consultarTripulaciones(int idx); // Polimorfismo

		//11
		void consultarHistorialPuerta();
		void consultarHistorialPuerta(int idx);

		//12
		void despacharVuelo();

		
		bool admin(); // Pide al usuario identificarse como administrador
		// Esto pues algunas funciones no deberian darse a un usuario normal.
		



	public:

		
		SistemaPrincipal(int numeroDePuertasDeEmbarque);
		int ejecutarMenu();

		// La siguiente funcion perfectamente podria ser publica, pero desde el codigo del main se creo un codigo
		// Para generar aeronaves rapidamente y poder testear el programa. 
		void ingresarAeronave(unique_ptr<Aeronave>&aeron);
		

};
