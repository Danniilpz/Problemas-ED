// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "list_eda.h"

template <class T>
class ListaAmpliada:public list<T>{
    using Nodo = typename deque<T>::Nodo;
public:
    void estremece(){
        Nodo * n=this->fantasma->ant->ant;
        Nodo * ant;
        int i=this->nelems-2;
        while(i>0){
            ant=n->ant;
            if(i%2!=0){
                unlinkNodo(n);
                Nodo* ant=this->fantasma->ant;
                ant->sig=n;
                n->ant=ant;
                n->sig=this->fantasma;
                this->fantasma->ant=n;
            }
            i--;
            n=ant;
        }

    }
    void unlinkNodo(Nodo * n){
        n->ant->sig=n->sig;
    }
};
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    ListaAmpliada<int> lista;
    int valor;
    std::cin>>valor;
    while(valor!=-1){
        lista.insert(lista.end(),valor);
        std::cin>>valor;
    }
lista.estremece();
    for(int&n :lista){
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