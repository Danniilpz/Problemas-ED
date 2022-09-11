// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"

struct tSol{
    int altura;
    int completo;
    int alturaMax;
};
tSol subarbolMayor(bintree<char> arbol){
    if(arbol.empty()) return {0,false,0};
    else{
        tSol aux;
        tSol iz=subarbolMayor(arbol.left());
        tSol dcha=subarbolMayor(arbol.right());
        aux.completo=iz.completo&&dcha.completo;
        aux.alturaMax=std::max(iz.alturaMax,dcha.alturaMax);
        if(!arbol.left().empty()&&!arbol.right().empty()){
            if(aux.completo){
                aux.altura=std::min(iz.alturaMax,dcha.alturaMax)+1;
                if(aux.altura>aux.alturaMax) aux.alturaMax=aux.altura;
            }
            else{
                aux.completo=true;
                aux.altura=1;
                if(aux.altura>aux.alturaMax) aux.alturaMax=aux.altura;
            }
        }
        else{
            aux.completo=true;
            aux.altura=1;
            if(aux.altura>aux.alturaMax) aux.alturaMax=aux.altura;
        }
        return aux;
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol=leerArbol('.');
    // escribir sol
    std::cout<<subarbolMayor(arbol).alturaMax<<"\n";

    
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