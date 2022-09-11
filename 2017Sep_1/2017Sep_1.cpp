// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "queue_eda.h"

template <class T>
class ListaAmpliada:public queue<T>{
    using Nodo = typename queue<T>::Nodo;
public:
    void llevarAlPrincipio(unsigned int pos){
        if(pos>this->nelems) throw new std::invalid_argument("Posicion inexistente");
        else{
            Nodo * n=this->prim;
            if(pos>1){
                if(pos>2) for(int i=0;i<pos-2;i++,n=n->sig);
                Nodo * anterior=n;
                Nodo * aMover=n->sig;
                Nodo * siguiente=aMover->sig;
                aMover->sig=this->prim;
                this->prim=aMover;
                anterior->sig=siguiente;
            }
        }
    }
    void print(){
        for(Nodo * i=this->prim;i!=nullptr;i=i->sig){
            std::cout<<i->elem<<" ";
        }
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    ListaAmpliada<int> cola;
    int n,pos;
    std::cin>>n;
    while(n!=0){
        cola.push(n);
        std::cin>>n;
    }
    std::cin>>pos;
    cola.llevarAlPrincipio(pos);
    cola.print();
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