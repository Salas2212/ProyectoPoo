#include <bits/stdc++.h>
#include "Pasajero.h"
#include "Aeronave.h"
#include "Vuelo.h"
#include "PuertaDeEmbarque.h"
#include "TorreDeControl.h"
using namespace std;

class SistemaPrincipal{
    private:
        vector<Vuelo>vuelos;
        vector<Aeronave>aeronaves;
        TorreDeControl torrePrincipal;



	public:
		/// Funcion para generar de forma amigable una aeronave.
		SistemaPrincipal(int numeroDePuertasDeEmbarque);
		Aeronave construirAeronave();
		void agregarAeronave(Aeronave aeronave);
	

};
