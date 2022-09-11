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
    void invertirSegmento(int ini,int len){
        Nodo * siguiente_aux, * inicio_aux,* primero_aux=nullptr, * anterior_aux, * pre_segmento=nullptr;
        int pos=1;
        for(Nodo * i=this->prim;pos<ini+len&&i!=nullptr;pos++,i=siguiente_aux){
            siguiente_aux=i->sig;
            if(pos+1==ini){
                pre_segmento=i;
            }
            else if(pos==ini){
                if(i==this->prim) primero_aux=i;
                inicio_aux=i;
            }
            else if(pos>ini){
                if(pos-ini+1==len){
                    inicio_aux->sig=siguiente_aux;
                    if(pre_segmento!=nullptr) pre_segmento->sig=i;
                    if(this->ult==i){
                        this->ult=inicio_aux;
                        if(primero_aux!=nullptr) this->prim=i;
                    }
                }
                i->sig=anterior_aux;
            }
            anterior_aux=i;
        }
    }
};



bool resuelveCaso() {
    int n,ini,len;
    std::cin >> n>>ini>>len;
    if (!std::cin) return false;
    ListaAmpliada<int> lista;
    for (int i = 0; i<n; ++i) {
        int num;
        std::cin >> num;
        lista.push(num);
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
