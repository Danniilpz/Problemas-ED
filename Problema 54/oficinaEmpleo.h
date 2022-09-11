
#ifndef PROBLEMA_54_OFICINAEMPLEO_H
#define PROBLEMA_54_OFICINAEMPLEO_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <set>
#include <vector>
#include <map>
#include <list>
#include <unordered_map>

class oficinaEmpleo{
    std::unordered_map<std::string, std::map<std::string,std::list<std::string>::iterator,std::less<>>> personas;
    std::unordered_map<std::string,std::list<std::string>> empleos;
public:
    void altaOficina(std::string nombre,std::string empleo){
        if(personas.count(nombre)==0||personas[nombre].count(empleo)==0){
            auto it=empleos[empleo].insert(empleos[empleo].end(),nombre);
            personas[nombre][empleo]=it;
        }
    };
    std::string ofertaEmpleo(std::string empleo){
        if(empleos.count(empleo)==0) throw std::domain_error("No existen personas apuntadas a este empleo");
        std::string persona=empleos[empleo].front();
        for(auto& p: personas[persona] ){
            empleos[p.first].erase(p.second);
            if(empleos[p.first].size()==0) empleos.erase(p.first);
        }
        personas.erase(persona);
        return persona;
    }
    std::vector<std::string> listadoEmpleos(std::string persona){
        if(personas.count(persona)==0) throw std::domain_error("Persona inexistente");
        else{
            std::vector<std::string> aux;
            auto lista=personas[persona];
            for(auto& p:lista){
                aux.push_back(p.first);
            }
            return aux;
        }
    }
};

#endif //PROBLEMA_54_OFICINAEMPLEO_H
