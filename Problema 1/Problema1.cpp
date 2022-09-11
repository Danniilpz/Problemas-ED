// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <stdexcept>
#include <vector>
#include "Hora.h"
#include <algorithm>

using namespace std;


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int trenes,horas;
    cin>>trenes>>horas;
    if (trenes==0||horas==0)
        return false;
    vector<Hora> horario(trenes);
    for(Hora& h:horario) cin>>h;
    for(int j=0;j<horas;j++){
        try{
            Hora t;
            cin>>t;
            auto pos=lower_bound(horario.begin(),horario.end(),t);
            if(pos==horario.end()) cout<<"No\n";
            else std::cout<<*pos<<"\n";
        }
        catch(invalid_argument& e){
            cout<<e.what()<<"\n";
        }
    }
    cout<<"---\n";    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
