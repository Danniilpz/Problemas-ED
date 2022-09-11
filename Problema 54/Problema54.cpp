// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>
#include "oficinaEmpleo.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    oficinaEmpleo sistema;
    std::string operacion;
    std::string param1,param2;
    std::cin>>operacion;
    if (! std::cin)
        return false;
    while(operacion!="FIN"){
        if(operacion=="altaOficina"){
            std::cin>>param1>>param2;
            sistema.altaOficina(param1,param2);
        }
        else if(operacion=="ofertaEmpleo"){
            std::cin>>param1;
            try{
                std::string aux=sistema.ofertaEmpleo(param1);
                std::cout<<param1<<": "<<aux<<"\n";
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        else if(operacion=="listadoEmpleos"){
            std::cin>>param1;
            try{
                std::vector<std::string> aux=sistema.listadoEmpleos(param1);
                std::cout<<param1<<": ";
                for(std::string s:aux){
                    std::cout<<s<<" ";
                }
                std::cout<<"\n";
            }
            catch(std::domain_error& e) {
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        std::cin>>operacion;
    }
    std::cout<<"---\n";
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
