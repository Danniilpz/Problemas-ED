#ifndef CARNET_PUNTOS
#define CARNET_PUNTOS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <list>

using DNI=std::string;

class carnet_puntos{
    std::unordered_map<DNI,std::pair<int,std::list<DNI>::iterator>> conductores;
    std::vector<std::list<DNI>> por_puntos;
    std::list<DNI>::iterator insertar_por_puntos(DNI dni, int puntos){
        auto& lista=por_puntos[puntos];
        return lista.insert(lista.begin(),dni);
    };
    public:
        carnet_puntos():por_puntos(16){}
        void nuevo(DNI dni){
            if(conductores.count(dni)!=0) throw std::domain_error("Conductor duplicado");
            else{
                conductores[dni]={15,insertar_por_puntos(dni,15)};
            }
        }
        void quitar(DNI dni,int puntos){
            if(conductores.count(dni)==0) throw std::domain_error("Conductor inexistente");
            else{
                por_puntos[conductores[dni].first].erase(conductores[dni].second);
                conductores[dni].first-=puntos;
                if(conductores[dni].first<0) conductores[dni].first=0;
                conductores[dni].second=insertar_por_puntos(dni,conductores[dni].first);
            }
        }
        int consultar(DNI dni){
            if(conductores.count(dni)==0) throw std::domain_error("Conductor inexistente");
            else{
                return conductores[dni].first;
            }
        }
        int cuantos_con_puntos(int puntos){
            if(puntos<0||puntos>15) throw std::domain_error("Puntos no validos");
            else{
                return por_puntos[puntos].size();
            }
        }
};


#endif
