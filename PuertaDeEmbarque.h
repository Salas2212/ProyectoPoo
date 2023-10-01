#include <bits/stdc++.h>
//#include "Vuelo.h"
using namespace std;
class PuertaDeEmbarque{
    public:
        Vuelo* vuelo_asignado;
        bool disponible;
        int identificacion;
        string ubicacion;
        string hora_embarque;
        vector<Vuelo>historial;
        PuertaDeEmbarque(int id, string ubi){
            identificacion = id;
            ubicacion = ubi;
            disponible = true;
        }
        

};
