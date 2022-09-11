// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "treemap_eda.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len;
    std::cin>>len;
    if (len==0)
        return false;
    map<std::string,int> notas;
    std::string clave;
    std::string valor_str;
    int valor;
    for(int i=0;i<len;i++){
        std::cin.ignore();
        std::getline(std::cin,clave);
        std::cin>>valor_str;
        if(valor_str=="INCORRECTO") valor=-1;
        else if(valor_str=="CORRECTO") valor=1;
        notas[clave]+=valor;
    }
    for (auto n : notas) {
        if(n.valor!=0) std::cout << n.clave << ", " << n.valor << "\n";
    }
    std::cout<<"---\n";
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
