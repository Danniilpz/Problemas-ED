// Daniel López Marqués
// A39

#include <iostream>
#include <fstream>

#include "queue_eda.h"


template <class T>
class ListaAmpliada : public queue<T> {
    using Nodo = typename queue<T>::Nodo;
public:
    void print() const {
        for(Nodo * i=this->prim;i!=this->ult->sig;i=i->sig){
            std::cout<<i->elem<<" ";
        }
    }
    void duplicar(){
        Nodo * nuevo=NULL;
        for(Nodo * i=this->prim;i!=this->ult->sig;i=nuevo->sig){
            nuevo= new Nodo(i->elem);
            if(i==this->ult) this->ult=nuevo;
            nuevo->sig=i->sig;
            i->sig=nuevo;
        }
    }
};



bool resuelveCaso() {
    int n;
    std::cin >> n;
    if (!std::cin) return false;
    ListaAmpliada<int> lista;
    for (size_t i = 0; n!=0; ++i) {
        lista.push(n);
        std::cin >> n;
    }
    if(!lista.empty()){
        lista.duplicar();
        lista.print();
    }
    std::cout<<"\n";
    

    
    return true;
}


int main() {
  #ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
  #endif
    
  while (resuelveCaso()) {} //Resolvemos todos los casos

  #ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
  #endif

  return 0;
}
