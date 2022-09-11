// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"
template<typename T>
struct infoArbol{
    int altura;
    bintree<T> arbol;
};

template<typename T>
std::queue<T> resolver(bintree<T> const &arbol) {
    int actAltura=0;
    int altura=0;
    std::queue<T> perfil;
    if(arbol.empty()) return perfil;
    else if(arbol.left().empty()&&arbol.right().empty()){
        perfil.push(arbol.root());
        return perfil;
    }
    std::queue<infoArbol<T>> cola;
    cola.push({1,arbol});
    while(!cola.empty()){
        infoArbol<T> const &par=cola.front();
        altura=par.altura;
        bintree<T> const &arbol=par.arbol;
        if (!arbol.left().empty())
            cola.push({par.altura + 1, arbol.left()});
        if (!arbol.right().empty())
            cola.push({par.altura + 1, arbol.right()});
        if(altura>actAltura){
            perfil.push(cola.front().arbol.root());
            actAltura++;
        }
        cola.pop();
    }
    return perfil;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree<int> arbol = leerArbol(-1);
    std::queue<int> p = resolver(arbol);
    while(!p.empty()){
        std::cout<<p.front()<<" ";
        p.pop();
    }
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