// Daniel López Marqués
// A39
// https://www.youtube.com/watch?v=eYu3Y8u3BRA

#include <iostream>
#include <iomanip>
#include <fstream>
#include "academia_chino.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string operacion;
    std::cin>>operacion;
    if (! std::cin)
        return false;
    std::string param1;
    int param2;
    academia_chino sistema=academia_chino();
    while(operacion!="FIN"){
        if(operacion=="nuevo_estudiante"){
            std::cin>>param1>>param2;
            try{
                sistema.nuevo_estudiante(param1,param2);
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        else if(operacion=="promocionar"){
            std::cin>>param1;
            try{
                sistema.promocionar(param1);
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        else if(operacion=="grupo_estudiante"){
            std::cin>>param1;
            try{
                int aux=sistema.grupo_estudiante(param1);
                std::cout<<param1<<" esta en el grupo "<<aux<<"\n";
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        else if(operacion=="graduados"){
            try{
                std::list<std::string> lista=sistema.graduados();
                std::cout<<"Lista de graduados: ";
                for(std::string s:lista) std::cout<<s<<" ";
                std::cout<<"\n";
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR: "<<e.what()<<"\n";
            }
        }
        else if(operacion=="novato"){
            std::cin>>param2;
            try{
                std::string aux=sistema.novato(param2);
                std::cout<<"Novato de "<<param2<<": "<<aux<<"\n";
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