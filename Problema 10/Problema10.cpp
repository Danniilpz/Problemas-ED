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
        for(Nodo * i=this->prim;i!=nullptr;i=i->sig){
            std::cout<<i->elem<<" ";
        }
    }
    void invertir(){
        Nodo * siguiente_aux, * primero_aux, * anterior_aux;
        for(Nodo * i=this->prim;i!=nullptr;i=siguiente_aux){
            siguiente_aux=i->sig;
            if(i==this->prim){
                i->sig=nullptr;
                primero_aux=i;
            }
            else{
                i->sig=anterior_aux;
            }
            anterior_aux=i;
        }
        this->prim=this->ult;
        this->ult=primero_aux;
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
        lista.invertir();
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
