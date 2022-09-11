// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "bintree_eda.h"
template <class T>
class bintree_ext: public bintree<T>{
    using Link = typename bintree<T>::Link;
private:
    T minimo(Link r){
        if(r==nullptr) throw new std::invalid_argument("arbol vacio");
        else if(r->left==nullptr&&r->right==nullptr) return r->elem;
        else if(r->right!=nullptr&&r->left==nullptr){
            T elem= minimo(r->right);
            return std::min(elem,r->elem);
        }
        else if(r->left!=nullptr&&r->right==nullptr){
            T elem= minimo(r->left);
            return std::min(elem,r->elem);
        }
        else{
            T elemIz=minimo(r->left);
            T elemDcha=minimo(r->right);
            return std::min({elemIz,elemDcha,r->elem});
        }
    }
public:
    bintree_ext () : bintree <T >() {}
    bintree_ext ( bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T >(l,e,r){}
    T minimo(){
        return this->minimo(this->raiz);
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
bool resuelveCaso() {
    // leer los datos de la entrada
    char tipo;
    std::cin>>tipo;
    if (! std::cin)
        return false;
    if(tipo=='N'){
        bintree_ext<int> arbol=leerArbol_ext(-1);
        std::cout<<arbol.minimo()<<"\n";
    }
    else if(tipo=='P'){
        std::string vacio="#";
        bintree_ext<std::string> arbol=leerArbol_ext(vacio);
        std::cout<<arbol.minimo()<<"\n";
    }
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