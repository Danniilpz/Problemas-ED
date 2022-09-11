// Daniel López Marqués
// A39

#include <iostream>
#include <fstream>

#include "deque_eda.h"


template <class T>
class ListaDobleAmpliada : public deque<T> {
    using Nodo = typename deque<T>::Nodo;
public:
    void print() const {
        for(Nodo * i=(this->fantasma)->sig;i!=(this->fantasma);i=i->sig){
            std::cout<<i->elem<<" ";
        }
    }
    void invertirSegmento(int ini,int len){
        Nodo * siguiente_aux, * inicio_aux;
        int pos=1;
        for(Nodo * i=(this->fantasma)->sig;pos<ini+len&&i!=(this->fantasma);pos++,i=siguiente_aux){
            siguiente_aux=i->sig;
            if(pos>=ini){
                if(pos==ini){
                    inicio_aux=i;
                }
                i->sig=i->ant;
                i->ant=siguiente_aux;
                if(pos-ini+1==len){
                    siguiente_aux->ant=inicio_aux;
                    i->ant=inicio_aux->sig;
                    (inicio_aux->sig)->sig=i;
                    inicio_aux->sig=siguiente_aux;

                }
            }
        }
    }
};



bool resuelveCaso() {
    int n,ini,len;
    std::cin >> n>>ini>>len;
    if (!std::cin) return false;
    ListaDobleAmpliada<int> lista;
    for (int i = 0; i<n; ++i) {
        int num;
        std::cin >> num;
        lista.push_back(num);
    }
    if(!lista.empty()){
        lista.invertirSegmento(ini,len);

    }
    lista.print();
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
