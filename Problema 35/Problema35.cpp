// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include "bintree_eda.h"

struct tSol{
    int altura;
    int caminoMax;
};
tSol caminoMayor(bintree<int> arbol){
    if(arbol.empty()) return {0,0};
    else{
        tSol iz=caminoMayor(arbol.left());
        tSol dcha=caminoMayor(arbol.right());
        int altura,caminoMax;
        if(arbol.root()%2==0){
            altura=std::max(iz.altura,dcha.altura)+1;
            caminoMax=std::max({iz.caminoMax,dcha.caminoMax,iz.altura+dcha.altura+1});
        }
        else{
            altura=0;
            caminoMax=std::max(iz.caminoMax,dcha.caminoMax);
        }
        return {altura,caminoMax};

    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol=leerArbol(-1);
    // escribir sol
    std::cout<<caminoMayor(arbol).caminoMax<<"\n";

    
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