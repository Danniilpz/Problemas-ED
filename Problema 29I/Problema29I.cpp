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
template <class T>
class bintree_ext: public bintree<T>{
    using Link = typename bintree<T>::Link;
private:
    int altura(Link r){
        if(r==nullptr) return 0;
        else{
            int numIz=altura(r->left);
            int numDcha=altura(r->right);
            return ((numIz>numDcha)?numIz:numDcha)+1;
        }
    }
    tSol diametro(Link r){
        if(r==nullptr) return {0,0};
        else{
            tSol iz=diametro(r->left);
            tSol dcha=diametro(r->right);
            int altura=iz.altura>=dcha.altura?iz.altura+1:dcha.altura+1;
            int diametro=iz.diametro>=dcha.diametro?iz.diametro:dcha.diametro;
            diametro=diametro>=(iz.altura+dcha.altura+1)?diametro:(iz.altura+dcha.altura+1);
            return {altura,diametro};
        }
    }
public:
    bintree_ext () : bintree <T >() {}
    bintree_ext ( bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T >(l,e,r){}
    int altura(){
        return this->altura(this->raiz);
    }
    int diametro(){
        return this->diametro(this->raiz).diametro;
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
    std::cout<<arbol.diametro()<<"\n";
    
    
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