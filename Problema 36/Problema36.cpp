// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"

struct tSol{
    int altura;
    bool completo;
    bool semicompleto;
};
tSol completo(bintree<char> arbol){
    if(arbol.empty()) return {0,true,true};
    else{
        tSol iz=completo(arbol.left());
        tSol dcha=completo(arbol.right());
        if(iz.altura==dcha.altura&&iz.completo&&dcha.completo) return {iz.altura+1,true,true};
        else if(iz.altura==dcha.altura&&iz.completo&&dcha.semicompleto)return {iz.altura+1,false,true};
        else if(iz.altura==dcha.altura+1&&iz.semicompleto&&dcha.completo)return {iz.altura+1,false,true};
        else return {iz.altura+1,false,false};

    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol=leerArbol('.');
    // escribir sol
    tSol s=completo(arbol);
    if(s.completo) std::cout<<"COMPLETO";
    else if(s.semicompleto) std::cout<<"SEMICOMPLETO";
    else std::cout<<"NADA";
    std::cout<<"\n";

    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}