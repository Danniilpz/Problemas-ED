// Daniel López Marqués
// A39
// https://www.youtube.com/watch?v=eYu3Y8u3BRA

#include <iostream>
#include <iomanip>
#include <fstream>
#include "ipud.h"



// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::string operacion;
    std::cin>>operacion;
    if (! std::cin)
        return false;
    std::string param1,param2;
    int param3;
    ipud sistema=ipud();
    while(operacion!="FIN"){
        if(operacion=="addSong"){
            std::cin>>param1>>param2>>param3;
            try{
                sistema.addSong(param1,param2,param3);
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR "<<e.what()<<"\n";
            }
        }
        else if(operacion=="addToPlaylist"){
            std::cin>>param1;
            try{
                sistema.addToPlaylist(param1);
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR "<<e.what()<<"\n";
            }
        }
        else if(operacion=="current"){
            try{
                std::string aux=sistema.current();
                std::cout<<aux<<"\n";
            }
            catch(std::domain_error& e){
                std::cout<<"ERROR "<<e.what()<<"\n";
            }
        }
        else if(operacion=="play"){
            std::cin>>param1;
            std::string aux=sistema.play();
            if(aux=="") std::cout<<"No hay canciones en la lista\n";
            else std::cout<<"Sonando "<<aux<<"\n";
        }
        else if(operacion=="totalTime"){
            int aux=sistema.totalTime();
            std::cout<<"Tiempo total "<<aux<<"\n";
        }
        else if(operacion=="recent"){
            std::cin>>param3;
            std::list<std::string> aux=sistema.recent(param3);
            std::cout<<"Las "<<param3<<" mas recientes\n";
            for(std::string cancion:aux){
                std::cout<<"    "<<cancion<<"\n";
            }
        }
        else if(operacion=="deleteSong"){
            std::cin>>param1;
            sistema.deleteSong(param1);
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