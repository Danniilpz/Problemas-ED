// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "Complejo.h"


// función que resuelve el problema
bool mandelbrot(Complejo<float>& c,int iter) {
    bool pertenece=true;
    Complejo<float> aux=c;
    for(int i=1;i<iter;i++){
        aux=aux*aux+c;
        if(aux.modulo()>2) pertenece=false;
    }
    return pertenece;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    float real,imaginaria,iter;
    std::cin>>real>>imaginaria>>iter;
    if(real<-2||real>2) throw std::invalid_argument("ERROR1");
    if(imaginaria<-2||imaginaria>2) throw std::invalid_argument("ERROR2");
    if(iter<100||iter>500) throw std::invalid_argument("ERROR3");
    Complejo<float> c=Complejo<float>(real, imaginaria);
    bool pertenece = mandelbrot(c,iter);
    if(pertenece) std::cout<<"SI\n";
    else std::cout<<"NO\n";   
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