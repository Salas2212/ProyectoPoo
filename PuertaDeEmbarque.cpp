#include <bits/stdc++.h>
#include "PuertaDeEmbarque.h"

using namespace std;

PuertaDeEmbarque::PuertaDeEmbarque(int id, string ubi) {
    identificacion = id;
    ubicacion = ubi;
    disponible = true;
    vuelo_asignado = nullptr;
    hora_embarque = "Sin asignar";
}

Vuelo* PuertaDeEmbarque::getVueloAsignado() {
    return vuelo_asignado;
}

void PuertaDeEmbarque::setVueloAsignado(Vuelo* vuelo) {
    vuelo_asignado = vuelo;
}

bool PuertaDeEmbarque::getDisponible() {
    return disponible;
}

void PuertaDeEmbarque::setDisponible(bool dispo) {
    disponible = dispo;
}

int PuertaDeEmbarque::getIdentificacion() {
    return identificacion;
}

void PuertaDeEmbarque::setIdentificacion(int& id) {
    identificacion = id;
}

std::string PuertaDeEmbarque::getUbicacion() {
    return ubicacion;
}

void PuertaDeEmbarque::setUbicacion(std::string& ubi) {
    ubicacion = ubi;
}

std::string PuertaDeEmbarque::getHoraEmbarque() {
    return hora_embarque;
}

void PuertaDeEmbarque::setHoraEmbarque(std::string horaEmb) {
    hora_embarque = horaEmb;
}

std::vector<Vuelo> PuertaDeEmbarque::getHistorial() {
    return historial;
}

void PuertaDeEmbarque::agregarHistorial(Vuelo vuelo) {
    historial.push_back(vuelo);
}

void PuertaDeEmbarque::agregarHistorial(Vuelo *vuelo){
    historial.push_back(Vuelo(vuelo));
}

void PuertaDeEmbarque::removerHistorial() {
    if (!historial.empty()) {
        historial.pop_back();
    }
}


void PuertaDeEmbarque::imprimirInfo() {
    cout << "id: " << identificacion << " | ubicacion: " << ubicacion << " | disponible: " << (disponible ? "Si" : "No") << "\n";
    if(!disponible){
        cout << "  Id vuelo: " << vuelo_asignado->numero_de_identificacion << " | hora embarque: " << hora_embarque << "\n";
    }
}

void PuertaDeEmbarque::imprimirHistorial(){
    for(int i = 0 ; i < historial.size() ; i ++){
        cout << i+1 << ". " << historial[i].numero_de_identificacion << " | " << historial[i].ciudad_origen << " - " << historial[i].ciudad_destino << ". Fecha: " << historial[i].fecha << "\n";
    }
}
