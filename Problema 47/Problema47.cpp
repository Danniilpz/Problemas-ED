// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "carnet_puntos.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string operacion;
    std::cin>>operacion;
    if (! std::cin)
        return false;
    std::string param1;
    int param2,aux;
    carnet_puntos sistema=carnet_puntos();
    while(operacion!="FIN"){
        if(operacion=="nuevo"){
            std::cin>>param1;
            try{
                sistema.nuevo(param1);
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        else if(operacion=="cuantos_con_puntos"){
            std::cin>>param2;
            try{
                aux=sistema.cuantos_con_puntos(param2);
                std::cout<<"Con "<<param2<<" puntos hay "<<aux<<"\n";
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        else if(operacion=="quitar"){
            std::cin>>param1>>param2;
            try{
                sistema.quitar(param1,param2);
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        else if(operacion=="consultar"){
            std::cin>>param1;
            try{
                aux=sistema.consultar(param1);
                std::cout<<"Puntos de "<<param1<<": "<<aux<<"\n";
            }
            catch(std::domain_error& e){
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