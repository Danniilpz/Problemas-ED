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
    void frontera(Link r,std::vector<T>& v){
        if(r!=nullptr){
            if(r->left==nullptr&&r->right==nullptr) v.push_back(r->elem);
            else{
                frontera(r->left,v);
                frontera(r->right,v);
            }
        }
    }
public:
    bintree_ext () : bintree <T >() {}
    bintree_ext ( bintree_ext <T> const & l, T const & e, bintree_ext <T> const & r) : bintree <T >(l,e,r){}
    void frontera(std::vector<T>& v){
        this->frontera(this->raiz,v);
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
    bintree_ext<int> arbol=leerArbol_ext(-1);
    // escribir sol
    std::vector<int> sol;
    arbol.frontera(sol);
    for(int n:sol){
        std::cout<<n<<" ";
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