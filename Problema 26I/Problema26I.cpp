// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "bintree_eda.h"

template <class T>
class bintree_ext: public bintree<T>{
    using Link = typename bintree<T>::Link;
private:
    int numeroNodos(Link r){
        if(r==nullptr) return 0;
        else{
            int numIz=numeroNodos(r->left);
            int numDcha=numeroNodos(r->right);
            return numIz+numDcha+1;
        }
    }
    int numHojas(Link r){
        if(r==nullptr) return 0;
        else{
            int numIz=numHojas(r->left);
            int numDcha=numHojas(r->right);
            if(numIz==0&&numDcha==0) return 1;
            else return numIz+numDcha;
        }
    }
    int altura(Link r){
        if(r==nullptr) return 0;
        else{
            int numIz=altura(r->left);
            int numDcha=altura(r->right);
            return ((numIz>numDcha)?numIz:numDcha)+1;
        }
    }
public:
    bintree_ext () : bintree <T >() {}
    bintree_ext ( bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T >(l,e,r){}
    int numeroNodos(){
        return this->numeroNodos(this->raiz);
    }
    int numHojas(){
        return this->numHojas(this->raiz);
    }
    int altura(){
        return this->altura(this->raiz);
    }
};

template <typename T>
inline bintree_ext<T> leerArbol_ext(T vacio) {
    T raiz;
    std::cin >> raiz;
    if (raiz == vacio) { // es un árbol vacío
        return {};
    } else { // leer recursivamente los hijos
        auto iz = leerArbol_ext(vacio);
        auto dr = leerArbol_ext(vacio);
        return {iz, raiz, dr};
    }
}


// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    bintree_ext<char> arbol=leerArbol_ext('.');
    // escribir sol
    std::cout<<arbol.numeroNodos()<<" "<<arbol.numHojas()<<" "<<arbol.altura()<<"\n";
    
    
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