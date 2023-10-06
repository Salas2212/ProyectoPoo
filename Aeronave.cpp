#include "Aeronave.h"
#include <cstdlib> // para la funcion random()
using namespace std;

Aeronave::Aeronave(string registro, int capacidad, int velMax, int aut, int yFabric, string state) {
    registro_de_marca = registro;
    capacidad_de_pasajeros = capacidad;
    velocidad_max = velMax;
    autonomia = aut;
    ano_fabricacion = yFabric;
    estado = state;
	numeroDeVuelosAsignados = 0;
	sillasRestantes = capacidad_de_pasajeros;
}

void Aeronave::guardar_coordenadas() {
    double x = -100.0 + ((200.0) * (rand() % 1000000L)) / 1000000L;
    srand(time(NULL));
    double y = -100.0 + ((200.0) * (rand() % 1000000L)) / 1000000L;
    coordenadas = {x, y};
}

pair<double, double> Aeronave::obtenerCoordenadas() {
    return coordenadas;
}

void Aeronave::consultarCoordenadasAero(int idAeronave, pair<double, double> ubi_aeronave) {
    coor_aeronaves[idAeronave] = ubi_aeronave;
}

void Aeronave::reiniciar(vector<pair<double, double>> &coordenadas_aeronaves) {
    coor_aeronaves = coordenadas_aeronaves;
}

string Aeronave::getTipo(){
	return tipo;
}

void Aeronave::agregarAeronaveAlSistema(){
    coor_aeronaves.push_back({-1, -1});
}

bool Aeronave::disponible(){
	return "En servicio" == estado;
}
void Aeronave::asignarVuelo(){
	numeroDeVuelosAsignados ++;
	if(numeroDeVuelosAsignados == 3){
		estado = "Totalmente asignada";
	}
}
void Aeronave::asignarSilla(){
	sillasRestantes --;
}
void Aeronave::vaciarAeronave(){
	sillasRestantes = capacidad_de_pasajeros;
	numeroDeVuelosAsignados --;
}

void Avion::editarInformacionEspecifica(){

    cout << "¿Qué característica deseas modificar?" << endl;
	cout << "1. Altitud maxima" << endl;
	cout << "2. Cantidad de motores" << endl;
	cout << "3. Categoria" << endl;
	int ans;
	cin >> ans;
	switch (ans){
	case 1:
		cout << "Nueva altitud máxima: ";
		cin >> altitud_maxima;
		break;
	case 2:
		cout << "Nueva cantidad de motores: ";
        cin >> cantidad_de_motores;
		break;
	case 3:
		cout << "Nueva categoría: ";
        cin >> categoria;
		break;
	default:
		cout << "Opcion no valida\n";
		break;
	}
}

void Helicoptero::editarInformacionEspecifica(){
    cout << "¿Qué característica deseas modificar?" << endl;
	cout << "1. Cantidad de rotores" << endl;
	cout << "2. Capacidad de elevacion" << endl;
	cout << "3. Uso especifico" << endl;
	int ans;
	cin >> ans;
	switch (ans){
	case 1:
		cout << "Nueva cantidad de rotores: ";
		cin>>cantidad_de_rotores;
		break;
	case 2:
		cout << "Nueva capacidad de elevacion: ";
        cin>>capacidad_de_elevacion;
		break;
	case 3:
		cout << "Nuevo uso especifico: ";
        cin>>uso_especifico;
		break;
	default:
		cout << "Opcion no valida\n";
		break;
	}
}

void JetPrivado::editarInformacionEspecifica(){

    cout << "¿Qué característica deseas modificar?" << endl;
	cout << "1. Propietario" << endl;
	cout << "2. Lista de servicios a bordo" << endl;
	cout << "3. Lista de destinos frecuentes" << endl;
	int ans;
	cin >> ans;
	switch (ans){
	case 1:
		cout << "Nuevo propietario: ";
		cin>>propietario;
		break;
	case 2:
		cout << "Nueva lista de servicios a bordo: ";
        cin>>lista_de_servicios_a_bordo;
		break;
	case 3:
		cout << "Nueva lista de destinos frecuentes: ";
        cin>>lista_de_destinos_frecuentes;
		break;
	default:
		cout << "Opcion no valida\n";
		break;
	}
}

