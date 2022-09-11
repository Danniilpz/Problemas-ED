// Daniel López Marqués
// A39

#include <iostream>
#include <iomanip>
#include <fstream>
#include "autoescuela.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string operacion;
    std::cin>>operacion;
    if (! std::cin)
        return false;
    std::string param1,param2;
    int param3,aux;
    bool aux2;
    autoescuela sistema=autoescuela();
    while(operacion!="FIN"){
        if(operacion=="alta"){
            std::cin>>param1>>param2;
            sistema.alta(param1,param2);
        }
        else if(operacion=="es_alumno"){
            std::cin>>param1>>param2;
            aux2=sistema.es_alumno(param1,param2);
            if(aux2) std::cout<<param1<<" es alumno de "<<param2<<"\n";
            else std::cout<<param1<<" no es alumno de "<<param2<<"\n";
        }
        else if(operacion=="puntuacion"){
            std::cin>>param1;
            try{
                aux=sistema.puntuacion(param1);
                std::cout<<"Puntuacion de "<<param1<<": "<<aux<<"\n";
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR\n";
            }
        }
        else if(operacion=="actualizar"){
            std::cin>>param1>>param3;
            try{
                sistema.actualizar(param1,param3);
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR\n";
            }
        }
        else if(operacion=="aprobar"){
            std::cin>>param1;
            try{
                sistema.aprobar(param1);
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR\n";
            }
        }
        else if(operacion=="examen"){
            std::cin>>param1>>param3;
            try{
                std::vector<std::string> lista=sistema.examen(param1,param3);
                std::cout<<"Alumnos de "<<param1<<" a examen:\n";
                for(std::string s:lista) std::cout<<s<<"\n";
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR\n";
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