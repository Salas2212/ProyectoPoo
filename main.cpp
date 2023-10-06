#include <iostream>
#include <vector>
#include "Aeronave.h"
#include "Pasajero.h"
#include "Vuelo.h"
#include "PuertaDeEmbarque.h"
#include "TorreDeControl.h"
#include "SistemaPrincipal.h"

using namespace std;


string generarStringAleatorio(int largo){
    string ans = "";
    if(largo < 0)return ans;
    for(int i = 0 ; i < largo ; i ++){
        char generado = (rand()%('z'-'a'+1))+97;
        ans += generado;
    }
    return ans;
}

int generarEnteroAleatorio(int minimo, int maximo){
    return (rand()%(maximo-minimo+1)) + minimo;
}

// Genera varias aeronaves en el sistema, para poder probar las funciones mas rapido cuando se ejecute el programa.
void generarAeronaveAlAzar(int cantidad, SistemaPrincipal &sys){
    srand(time(NULL));
    while(cantidad -- ){
        string registro;
        int capacidad, velMax, aut, yFabric;
        string state;
        registro = generarStringAleatorio(6);
        capacidad = generarEnteroAleatorio(10, 200);
        velMax = generarEnteroAleatorio(400, 2500);
        aut = generarEnteroAleatorio(10, 70);
        yFabric = generarEnteroAleatorio(1960, 2023);

        state = "En servicio";

        int dado = rand()%3;

        if (dado == 0) {
            int altitudMaxima, cantidadMotores;
            string categoria;
            altitudMaxima = generarEnteroAleatorio(5000, 20000);
            cantidadMotores = generarEnteroAleatorio(1, 6);
            categoria = "Comercial";

            unique_ptr<Aeronave> avion = make_unique<Avion>(registro, capacidad, velMax, aut, yFabric, state, altitudMaxima, cantidadMotores, categoria);
            sys.ingresarAeronave(avion);

            
        } else if (dado == 1) {
            int cantidadRotores, capacidadElevacion;
            string usoEspecifico;
        
            cantidadRotores = generarEnteroAleatorio(2, 7);
            capacidadElevacion = generarEnteroAleatorio(3000, 13000);

            usoEspecifico = "Combate";

            // Crear una instancia de Helicoptero
            unique_ptr<Aeronave> helicoptero = make_unique<Helicoptero>(registro, capacidad, velMax, aut, yFabric, state, cantidadRotores, capacidadElevacion, usoEspecifico);
            sys.ingresarAeronave(helicoptero);
        } else {
            string propietario, listaDeServiciosABordo, listaDeDestinosFrecuentes;
            propietario = "propietario " + to_string(generarEnteroAleatorio(1, 60));
            listaDeServiciosABordo = "Servicios: ";
            int canti = generarEnteroAleatorio(1, 5);
            for(int i = 0 ; i < canti ; i ++)listaDeServiciosABordo += to_string(generarEnteroAleatorio(1, 10)) + (i + 1 < canti ? ", " : "");
            listaDeDestinosFrecuentes = "Destinos frecuentes: ";
            canti = generarEnteroAleatorio(1, 5);
            for(int i = 0 ; i < canti ; i ++)listaDeServiciosABordo += to_string(generarEnteroAleatorio(1, 10)) + (i + 1 < canti ? ", " : "");
            // Crear una instancia de JetPrivado
            unique_ptr<Aeronave> jetPrivado = std::make_unique<JetPrivado>(registro, capacidad, velMax, aut, yFabric, state, propietario, listaDeServiciosABordo, listaDeDestinosFrecuentes);
            sys.ingresarAeronave(jetPrivado);
        }
    }

}





int main() {
	//freopen("input.txt", "r", stdin);
    SistemaPrincipal sys(10);
    /*
    
    generarAeronaveAlAzar(10, sys);
    sys.obtenerInfoAeronave(9);
    sys.editarInformacionAeronave(9);
    sys.obtenerInfoAeronave(9);
    */

   //Descomentar para no tener que introducir datos.
   //generarAeronaveAlAzar(10, sys);

    while(true){
        int ans = sys.ejecutarMenu();
    }
    return 0;
}
