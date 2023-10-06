#include <iostream>
#include <windows.h> 
#include <set>

#include "SistemaPrincipal.h"

#define password "aeropuerto2023"

using namespace std;

SistemaPrincipal::SistemaPrincipal(int numeroDePuertasDeEmbarque)
    : torrePrincipal(numeroDePuertasDeEmbarque), // llama al constructor de torreDeControl
      aeronaves(torrePrincipal.aero) { // Crea la referencia a torrePrincipal.aero.
}

void SistemaPrincipal::ingresarAeronave(unique_ptr<Aeronave>&aeron){
	torrePrincipal.agregarAeronave(aeron);	
}

void SistemaPrincipal::construirAeronave(){
	string registro;
	int capacidad, velMax, aut, yFabric;
	string state;

	cout << "Ingrese el registro de la Aeronave: ";
	cin >> registro;
	
	cout << "Ingrese la capacidad de pasajeros: ";
	cin >> capacidad;

	cout << "Ingrese la velocidad maxima: ";
	cin >> velMax;

	cout << "Ingrese la autonomia: ";
	cin >> aut;

	cout << "Ingrese el año de fabricacion: ";
	cin >> yFabric;

	//cout << "Ingrese el estado: ";
	//cin >> state;
	state = "En servicio";

	// Crear una instancia de Aeronave con los valores ingresados
	
	cout << "¿Que tipo de aeronave deseas construir? (Avion, Helicoptero, JetPrivado)\n";
	string respuesta;
	
	cin >> respuesta;
	if (respuesta == "Avion") {
		int altitudMaxima, cantidadMotores;
		string categoria;
		
		cout << "Ingrese la altitud maxima: ";
		cin >> altitudMaxima;

		cout << "Ingrese la cantidad de motores: ";
		cin >> cantidadMotores;

		cout << "Ingrese la categoria: ";
		cin >> categoria;

		// Crear una instancia de Avion
		unique_ptr<Aeronave> avion = make_unique<Avion>(registro, capacidad, velMax, aut, yFabric, state, altitudMaxima, cantidadMotores, categoria);
		torrePrincipal.agregarAeronave(avion);

		
	} else if (respuesta == "Helicoptero") {
		int cantidadRotores, capacidadElevacion;
		string usoEspecifico;
		
		cout << "Ingrese la cantidad de rotores: ";
		cin >> cantidadRotores;

		cout << "Ingrese la capacidad de elevacion: ";
		cin >> capacidadElevacion;

		cout << "Ingrese el uso especifico: ";
		cin >> usoEspecifico;

		// Crear una instancia de Helicoptero
		unique_ptr<Aeronave> helicoptero = make_unique<Helicoptero>(registro, capacidad, velMax, aut, yFabric, state, cantidadRotores, capacidadElevacion, usoEspecifico);
		torrePrincipal.agregarAeronave(helicoptero);
	} else if (respuesta == "JetPrivado") {
		string propietario, listaDeServiciosABordo, listaDeDestinosFrecuentes;
		
		cout << "Ingrese el propietario: ";
		cin >> propietario;

		cout << "Ingrese la lista de servicios a bordo: ";
		cin >> listaDeServiciosABordo;

		cout << "Ingrese la lista de destinos frecuentes: ";
		cin >> listaDeDestinosFrecuentes;

		// Crear una instancia de JetPrivado
		unique_ptr<Aeronave> jetPrivado = std::make_unique<JetPrivado>(registro, capacidad, velMax, aut, yFabric, state, propietario, listaDeServiciosABordo, listaDeDestinosFrecuentes);
		torrePrincipal.agregarAeronave(jetPrivado);
	} else {
		cout << "Tipo no valido!\n";
	}
}

int SistemaPrincipal::getCantidadAeronaves(){
	return (int)aeronaves.size();
}

void SistemaPrincipal::obtenerInfoAeronave(int idx){
    if (idx >= 0 && idx < aeronaves.size()) {
        cout << "Registro de marca: " << aeronaves[idx]->registro_de_marca << "\n";
        cout << "Capacidad de pasajeros: " << aeronaves[idx]->capacidad_de_pasajeros << "\n";
        cout << "Velocidad maxima: " << aeronaves[idx]->velocidad_max << "\n";
        cout << "Autonomia: " << aeronaves[idx]->autonomia << "\n";
        cout << "Anio de fabricacion: " << aeronaves[idx]->ano_fabricacion << "\n";
        cout << "Estado: " << aeronaves[idx]->estado << "\n";
        cout << "Coordenadas: (" << aeronaves[idx]->coordenadas.first << ", " << aeronaves[idx]->coordenadas.second << ")\n";
        
        cout << endl << "Informacion especifica: " << endl;
        cout << "Tipo = " << aeronaves[idx]->getTipo() << endl;
		aeronaves[idx]->imprimirInformacionEspecifica();	
    } else {
        cout << "Indice de aeronave fuera de rango.\n";
    }
}


void SistemaPrincipal::editarInformacionAeronave(int i) {
    if (i >= 0 && i < aeronaves.size()) {
        cout << "¿Qué característica deseas modificar?" << endl;
        cout << "1. Registro de marca" << endl;
        cout << "2. Capacidad de pasajeros" << endl;
        cout << "3. Velocidad máxima" << endl;
        cout << "4. Autonomía" << endl;
        cout << "5. Año de fabricación" << endl;
        cout << "6. Estado" << endl;
        cout << "7. Modificar atributos específicos" << endl;
        cout << "8. Cancelar" << endl;
        int opcion;
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "Nuevo registro de marca: ";
                cin >> aeronaves[i]->registro_de_marca;
                break;
            case 2:
                cout << "Nueva capacidad de pasajeros: ";
                cin >> aeronaves[i]->capacidad_de_pasajeros;
                break;
            case 3:
                cout << "Nueva velocidad máxima: ";
                cin >> aeronaves[i]->velocidad_max;
                break;
            case 4:
                cout << "Nueva autonomía: ";
                cin >> aeronaves[i]->autonomia;
                break;
            case 5:
                cout << "Nuevo año de fabricación: ";
                cin >> aeronaves[i]->ano_fabricacion;
                break;
            case 6:
                cout << "Nuevo estado: ";
                cin >> aeronaves[i]->estado;
                break;
            case 7:
                // Modifica atributos específicos según el tipo de aeronave
				aeronaves[i]->editarInformacionEspecifica();
                break;
            case 8:
                cout << "Operación cancelada." << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
                break;
        }
    } else {
        cout << "Índice de aeronave fuera de rango." << endl;
    }
}

void SistemaPrincipal::editarInformacionAeronave(){
	if(aeronaves.empty()){
		cout << "Hasta ahora, no hay ninguna aeronave registrada en el sistema.\n";
		return ;
	}
	cout << "Existen " << aeronaves.size() << " aeronaves registradas en el sistema. \n";
	cout << "Digite el numero de la aeronave que desea consultar ( 1 - " << aeronaves.size() << "): ";
	int idx ;
	cin >> idx;
	idx --;
	editarInformacionAeronave(idx);
}

bool SistemaPrincipal::admin(){
	int cuenta = 3; // Se le dan 3 intentos.
	
	while(cuenta --){
		cout << "\n";
		cout << "Por favor, ingrese la contrasena de administrador:\n";
		string pass;
		cin >> pass;
		if(pass == password)return true;
		else{
			cout << "Contrasena incorrecta!\n";
			cout << "Quedan " << cuenta << " intentos.\n";
		}
	}
	cout << "Se ha bloqueado el sistema por seguridad. Llame al administrador.";
	return false;
}

int SistemaPrincipal::seleccionMenu(){
	cout << "\n";
	cout << "Seleccione la accion que desea realizar: \n";
	cout << "1. Comprar un vuelo.\n";
	cout << "2. Consultar puertas de embarque.\n";
	cout << "3. Consultar vuelos.\n";
	cout << "4. Ver opciones de administrador\n";
	int ans;
	cin >> ans;
	if(ans == 4){
		if(!admin())return -1;
		cout << "\n\n";
		cout << "Seleccione la accion que desea realizar: \n";
		cout << "5. Agregar una nave.\n";
		cout << "6. Consultar informacion de las naves.\n";
		cout << "7. Editar la informacion de una nave.\n";
		cout << "8. Generar un vuelo.\n";
		cout << "9. Ingresar una tripulacion al sistema.\n";
		cout << "10. Consultar tripulaciones\n";
		cout << "11. Consultar historial de una puerta de embarque\n";
		cout << "12. Despachar un vuelo\n";
		cin >> ans;
		if(ans < 5 or ans > 12)return -1;
		return ans;

	}else if(ans > 4 or ans < 1)return -1;
	return ans;
}

int SistemaPrincipal::ejecutarMenu(){
	int respuesta = seleccionMenu();
	if(respuesta == -1)return -1;
	switch (respuesta)
	{
	case 1: // Comprar un vuelo.
		comprarUnVuelo();
		break;
	case 2: // Consultar puertas de embarque.
		consultarPuertasDeEmbarque();
		break;
	case 3: // ConsultarVuelos.
		consultarVuelos(true, false);
		break;
	case 5: // Agregar una nave.
		construirAeronave();
		break;
	case 6: // Consultar informacion de las naves.
		consultarInformacionAeronaves();
		break;
	case 7: // Editar informacion de una aeronave.
		editarInformacionAeronave();
		break;
	case 8:  // Genera un nuevo vuelo.
		generarVuelo();
		break;
	case 9: // Ingresar tripulacion al sistema:
		agregarTripulacionAlSistema();
		break;
	case 10: // Consultar tripulaciones en el sistema:
		consultarTripulaciones();
		break;
	case 11: // Consultar Historial de alguna puerta de embarque:
		consultarHistorialPuerta();
		break;
	case 12:
		despacharVuelo();
		break;
	default:
		break;
	}

}

void SistemaPrincipal::consultarPuertasDeEmbarque(){
	for(int i = 0 ; i < torrePrincipal.puertas_embarques.size() ; i ++){
		torrePrincipal.puertas_embarques[i].imprimirInfo();
		cout << "\n";
	}
}

void SistemaPrincipal::consultarInformacionAeronaves(){
	if(aeronaves.size() == 0){
		cout << "Hasta ahora, no hay ninguna aeronave registrada en el sistema.\n";
		return ;
	}
	cout << "Existen " << aeronaves.size() << " aeronaves registradas en el sistema. \n";
	cout << "Digite el numero de la aeronave que desea consultar ( 1 - " << aeronaves.size() << "): ";
	int idx ;
	cin >> idx;
	idx --;
	obtenerInfoAeronave(idx);
}

void SistemaPrincipal::generarVuelo(){
	int aeronaveDisponible, puertaDisponible;
	bool dispAeronaves = torrePrincipal.hayAeronavesDisponibles(aeronaveDisponible);
	bool dispPuertas = torrePrincipal.hayPuertasDisponibles(puertaDisponible);
	if(!dispAeronaves || !dispPuertas || tripulacion.empty()){
		cout << "ERROR: \n";
		if(!dispAeronaves)cout << "No hay aeronaves disponibles por el momento.\n";
		if(!dispPuertas)cout << "No hay puertas de embarque disponibles por el momento\n";
		if(tripulacion.empty())cout << "No hay tripulaciones registradas en el sistema.\n";
		return ;
	}
	Vuelo *nuevoVuelo = new Vuelo();
	cout << "Digite la ciudad de destino\n";
	cin >> nuevoVuelo->ciudad_destino;
	cout << "Digite la ciudad de origen\n";
	cin >> nuevoVuelo->ciudad_origen;
	cout << "Digite la fecha del vuelo\n";
	cin >> nuevoVuelo->fecha;
	if(nuevoVuelo->ciudad_destino.size() < 2 or nuevoVuelo->ciudad_origen.size() < 2 or nuevoVuelo->fecha.size() < 2){
		cout << "La informacion dada no es valida\n";
		return;
	}
	// Lo siguiente es para generar el id con los primeros dos caracteres de los strings dados.
	string id = nuevoVuelo->ciudad_origen.substr(0, 2);
	id += nuevoVuelo->ciudad_destino.substr(0, 2);
	id+= nuevoVuelo->fecha.substr(0, 2);
	srand(time(NULL));
	id += to_string(rand()%100000); // Agregarle un numero al azar.
	nuevoVuelo->numero_de_identificacion = id;
	cout << "Las aeronaves disponibles son: \n";
	for(int i = 0 ; i < aeronaves.size() ; i++ ){
		if(aeronaves[i]->disponible()){
			cout << i << ". ";
			cout << aeronaves[i]->getTipo() << " | autonomia: " << aeronaves[i]->autonomia << " | capacidad de pasajeros: " << aeronaves[i]->capacidad_de_pasajeros << "\n";
		}
	}
	cout << "Por favor digite el numero de la aeronave a usar. (Para cancelar, digite -1)\n";
	bool valid = false;
	int ansAero;
	while(!valid){
		cin >> ansAero;
		if(ansAero == -1)return ;
		if(ansAero >= 0 and ansAero < aeronaves.size() and aeronaves[ansAero]->disponible())valid = true;
		else cout << "El numero digitado no corresponde a una opcion\n";
	}
	cout << "Se ha escogido la aeronave " << ansAero << ":\n";
	obtenerInfoAeronave(ansAero);
	cout << "\n\n";
	int ansPuerta = torrePrincipal.asignar_puertas(nuevoVuelo);

	cout << "Existen " << tripulacion.size() << " tripulaciones registradas en el sistema: \n";
	for(int i = 0 ; i < tripulacion.size() ; i ++){
		cout << i+1 << ": " << tripulacion[i]->apellidos << ": Cantidad maxima de horas: " << tripulacion[i]->cant_max_horasdiarias << "\n";
	}
	cout << "Digite los codigos de los tripulantes a agregar separados por enter: \n";
	cout << "Si no desea agregar mas, digite 0\n";
	set<int>agregados;
	int ans = -1;
	while(ans != 0){
		cin >> ans;
		if(agregados.find(ans) != agregados.end())cout << "Este tripulante ya fue agregado!\n";
		else if(ans < 0 or ans > tripulacion.size())cout << "Opcion invalida\n";
		else if(ans != 0){
			nuevoVuelo->agregarTripulante(tripulacion[ans-1]);
			tripulacion[ans-1]->NoVuelo = nuevoVuelo->numero_de_identificacion;
			agregados.insert(ans);
			cout << "Agregado!\n";
		}
	}
	nuevoVuelo->puerta_embarque = ansPuerta;

	nuevoVuelo->idAeronave = aeronaves[ansAero]->id;
	aeronaves[ansAero]->asignarVuelo();

	vuelos.push_back(nuevoVuelo);
	cout << "Vuelo generado con exito.\n";
}

Pasajero* SistemaPrincipal::crearPasajero(){

	cout << "Desea usar datos guardados en las cookies? (S/N)";
	char ans;
	cin >> ans;
	if(ans == 'S'){
		return pasajeroPrecreado();
	}

	Pasajero *pasajero = new Pasajero();

	cout << "Ingrese la nacionalidad:\n";
	cin >> pasajero->nacionalidad;

	cout << "Ingrese el numero de maletas:\n";
	cin >> pasajero->numero_maletas;

	cout << "Ingrese el url a su informacion medica:\n";
	cin >> pasajero->resumen_infomedica;

	cout << "Ingrese el numero de su cedula:\n";
	cin >> pasajero->cedula;

	cout << "Ingrese su Nombre (solo uno):\n";
	cin >> pasajero->nombres;

	cout << "Ingrese su apellido (solo uno):\n";
	cin >> pasajero->apellidos;

	cout << "Ingrese el numero de su fecha de nacimiento:\n";
	cin >> pasajero->fecha_de_nacimiento;

	cout << "Ingrese su genero:\n";
	cin >> pasajero->genero;

	cout << "Ingrese su direccion:\n";
	cin >> pasajero->direccion;

	cout << "Ingrese su numero de telefono:\n";
	cin >> pasajero->numero_telefono;

	cout << "Ingrese su correo:\n";
	cin >> pasajero->correo;

	return pasajero;

}

Pasajero* SistemaPrincipal::pasajeroPrecreado(){
	Pasajero *pasajero = new Pasajero();
	pasajero->nacionalidad = "Colombiano";
	pasajero->numero_maletas = 2;
	pasajero->resumen_infomedica = "https://www.mayoclinic.org/es/first-aid/emergency-health-information/basics/art-20134333";
	pasajero->cedula = 1023216346;
	pasajero->nombres = "Juan";
	pasajero->apellidos = "Mendoza";
	pasajero->fecha_de_nacimiento = "03/02/1993";
	pasajero->genero = "Masculino";
	pasajero->direccion = "Cra 12 # 5-14";
	pasajero->numero_telefono = 313258356;
	pasajero->correo = "miasaval@gmail.com";
	return pasajero;
}

Tripulacion* SistemaPrincipal::tripulacionPrecreada(){
	Tripulacion *tripulante = new Tripulacion();
	tripulante->nacionalidad = "Colombiano";
	tripulante->numero_maletas = 3;
	tripulante->resumen_infomedica = "https://www.mayoclinic.org/es/first-aid/emergency-health-information/basics/art-20134333";
	tripulante->cedula = 2003340346;
	tripulante->nombres = "Maria";
	tripulante->apellidos = "Nieves";
	tripulante->fecha_de_nacimiento = "03/02/1980";
	tripulante->genero = "Femenino";
	tripulante->direccion = "Cra 15 # 5-12";
	tripulante->numero_telefono = 322358264;
	tripulante->correo = "MariaNieves@gmail.com";
	
	tripulante->puesto = "Capitan";

	tripulante->anios_experiencia = 8;

	tripulante->cant_max_horasdiarias = 20;
	return tripulante;
}

Tripulacion* SistemaPrincipal::crearTripulacion(){
	cout << "Desea usar datos guardados en las cookies? (S/N)";
	char ans;
	cin >> ans;
	if(ans == 'S'){
		return tripulacionPrecreada();
	}

	Tripulacion *tripulante = new Tripulacion();

	cout << "Ingrese la nacionalidad:\n";
	cin >> tripulante->nacionalidad;

	tripulante->numero_maletas = 3;

	cout << "Ingrese el url a su informacion medica:\n";
	cin >> tripulante->resumen_infomedica;

	cout << "Ingrese el numero de su cedula:\n";
	cin >> tripulante->cedula;

	cout << "Ingrese su Nombre (solo uno):\n";
	cin >> tripulante->nombres;

	cout << "Ingrese su apellido (solo uno):\n";
	cin >> tripulante->apellidos;

	cout << "Ingrese el numero de su fecha de nacimiento:\n";
	cin >> tripulante->fecha_de_nacimiento;

	cout << "Ingrese su genero:\n";
	cin >> tripulante->genero;

	cout << "Ingrese su direccion:\n";
	cin >> tripulante->direccion;

	cout << "Ingrese su numero de telefono:\n";
	cin >> tripulante->numero_telefono;

	cout << "Ingrese su correo:\n";
	cin >> tripulante->correo;

	cout << "Ingrese el puesto:\n";
	cin >> tripulante->puesto;

	cout << "Ingrese los anios de experiencia:\n";
	cin >> tripulante->anios_experiencia;

	cout << "Ingrese la cantidad maxima de horas diarias:\n";
	cin >> tripulante->cant_max_horasdiarias;

	return tripulante;
}

void SistemaPrincipal::agregarTripulacionAlSistema(){
	Tripulacion *creado = crearTripulacion();
	tripulacion.push_back(creado);
	cout << "Tripulacion guardada exitosamente\n";
}

void SistemaPrincipal::consultarTripulaciones(){
	if(tripulacion.empty()){
		cout << "Hasta ahora, no hay ninguna tripulacion registrada en el sistema.\n";
		return ;
	}
	cout << "Existen " << tripulacion.size() << " tripulaciones registradas en el sistema. \n";
	cout << "Digite el numero de la tripulacion que desea consultar ( 1 - " << tripulacion.size() << "): ";
	int idx ;
	cin >> idx;
	idx --;
	consultarTripulaciones(idx);
}

void SistemaPrincipal::consultarTripulaciones(int idx){
	tripulacion[idx]->imprimirInfoTripulacion();
}

void SistemaPrincipal::consultarVuelos(bool expandible, bool imprimirSillas){
	/*
		Expandible: True si quiero que permita revisar un vuelo especifico.
		ImprimirSillas: True si quiero que tambien me imprima el numero de sillas disponibles.
	*/
	if(vuelos.empty()){
		cout << "Por el momento, no hay vuelos disponibles :(\n";
		return ;
	}
	cout << "Existen " << vuelos.size() << " vuelos disponibles: \n";
	for(int i = 0 ; i < vuelos.size() ; i ++){
		cout << i << ". "<< vuelos[i]->numero_de_identificacion << " | " << vuelos[i]->ciudad_origen << "-" << vuelos[i]->ciudad_destino;
		cout << "\nFecha: " << vuelos[i]->fecha << ". Puerta de embarque: " << vuelos[i]->puerta_embarque << " (" << torrePrincipal.puertas_embarques[vuelos[i]->puerta_embarque].getUbicacion() << ").\n";
		if(imprimirSillas)cout << "Sillas disponibles: " << aeronaves[vuelos[i]->idAeronave]->sillasRestantes;
	}

	if(!expandible or vuelos.empty())return ;
	cout << "Si desea consultar informacion adicional sobre vuelos en especifico, debera iniciar sesion\n";
	cout << "Desea continuar? (S/N)\n";

	char ans;
	cin >> ans;
	if(ans != 'S'){
		return ;
	}
	if(!admin())return ;
	cout << "Digite el numero del vuelo entre las opciones dadas\n";
	int idx ;
	cin >> idx;
	if(idx >= vuelos.size() or idx < 0){
		cout << "Opcion no valida";
		return ;
	}

	cout << "Vuelo " << idx << " escogido.\n";
	cout << "id de la aeronave: " << vuelos[idx]->idAeronave << "\n";
	cout << "Tripulacion: \n";
	for(int i = 0 ; i < vuelos[idx]->tripulacion.size() ; i++){
		cout << vuelos[idx]->tripulacion[i]->cedula << " - " << vuelos[idx]->tripulacion[i]->nombres << " " << vuelos[idx]->tripulacion[i]->apellidos << "\n";
	}
	cout << "Pasajeros: \n";
	for(int i = 0 ; i < vuelos[idx]->pasajeros.size() ; i ++){
		cout << vuelos[idx]->pasajeros[i]->nombres << " " << vuelos[idx]->pasajeros[i]->apellidos << ". Maletas: " << vuelos[idx]->pasajeros[i]->numero_maletas << "\n";
	}

}

void SistemaPrincipal::comprarUnVuelo(){
	if(vuelos.empty()){
		cout << "Por el momento, no hay vuelos disponibles :(\n";
		return ;
	}
	cout << "Para comprar un vuelo debe iniciar sesion.\n";
	cout << "Vamos a crear tu perfil.\n";
	Pasajero *usuario = crearPasajero();
	cout << endl << endl;
	cout << "Vale, ahora selecciona el vuelo que deseas comprar: \n";
	consultarVuelos(false, true);
	int ans;
	do{
		cout << "\n(Digita el numero al principio del vuelo, o digita -1 para cancelar)\n";
		cin >> ans;
		if(ans == -1)return ;
		if(ans < 0 or ans >= vuelos.size())continue;
		if(aeronaves[vuelos[ans]->idAeronave]->sillasRestantes <= 0)cout << "Este vuelo esta copado. Por favor seleccione otro.\n";
		break;
	}while(true);
	aeronaves[vuelos[ans]->idAeronave]->asignarSilla();
	vuelos[ans]->agregarPasajero(usuario);
	cout << "Compra realizada exitosamente.\n";
}

void SistemaPrincipal::consultarHistorialPuerta(){
	cout << "Se tienen " << torrePrincipal.puertas_embarques.size() << " puertas de embarque.\n";
	cout << "Digite el numero de la que desea consultar (1 - " << torrePrincipal.puertas_embarques.size() <<"):\n";
	int idx ;
	cin >> idx;
	idx --;
	if(idx < 0 or idx >= torrePrincipal.puertas_embarques.size()){
		cout << "indice invalido\n";
		return ;
	}
	consultarHistorialPuerta(idx);
}

void SistemaPrincipal::consultarHistorialPuerta(int idx){
	torrePrincipal.puertas_embarques[idx].imprimirHistorial();
}


void SistemaPrincipal::despacharVuelo(){
	consultarVuelos(false, false);
	if(vuelos.empty()){
		return ;
	}
	int ans;
	do{
		cout << "Digite el numero del vuelo a despachar\n";
		cin >> ans;
		if(ans < 0 or ans >= vuelos.size()){
			cout << "Opcion no valida.\n\n";
			continue;
		}
		break;
	}while(true);

	// Claramente no puedo quitar un vuelo del vector porque la informacion se dana. Entonces simplemente
	// Voy a desocupar la puerta de embarque.
	// No es lo mas realista pero es una aproximacion.
	torrePrincipal.puertas_embarques[vuelos[ans]->puerta_embarque].setDisponible(true);
	aeronaves[vuelos[ans]->idAeronave]->vaciarAeronave();
}