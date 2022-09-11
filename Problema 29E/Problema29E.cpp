// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
struct tSol{
    int altura;
    int diametro;
};
tSol diametro(bintree<char> arbol){
    if(arbol.empty()) return {0,0};
    else{
        tSol iz=diametro(arbol.left());
        tSol dcha=diametro(arbol.right());
        int altura=iz.altura>=dcha.altura?iz.altura+1:dcha.altura+1;
        int diametro=iz.diametro>=dcha.diametro?iz.diametro:dcha.diametro;
        diametro=diametro>=(iz.altura+dcha.altura+1)?diametro:(iz.altura+dcha.altura+1);
        return {altura,diametro};
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<char> arbol=leerArbol('.');
    // escribir sol
    std::cout<<diametro(arbol).diametro<<"\n";
    
    
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