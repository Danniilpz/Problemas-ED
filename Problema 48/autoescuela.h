#ifndef AUTOESCUELA
#define AUTOESCUELA

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <list>
#include <set>

using nombre=std::string;

struct info{
    int puntuacion;
    nombre profesor;
};

class autoescuela{
    std::unordered_map<nombre,std::set<nombre>> profesor_alumnos;
    std::unordered_map<nombre,info> alumnos;
    public:
    //constante
        void alta(nombre alumno,nombre profesor){
            if(alumnos.count(alumno)==0){
                alumnos[alumno]={0,profesor};
                profesor_alumnos[profesor].insert(alumno);
            }
            else{
                profesor_alumnos[alumnos[alumno].profesor].erase(alumno);
                alumnos[alumno].profesor=profesor;
                profesor_alumnos[profesor].insert(alumno);
            }
        }
        //constante
        bool es_alumno(nombre alumno,nombre profesor){
            if(alumnos[alumno].profesor==profesor) return true;
            else return false;
        }
        //constante
        int puntuacion(nombre alumno){
            if(alumnos.count(alumno)==0) throw std::domain_error("El alumno "+alumno+" no esta matriculado");
            else{
                return alumnos[alumno].puntuacion;
            }
        }
        //constante
        void actualizar(nombre alumno,int puntos){
            if(alumnos.count(alumno)==0) throw std::domain_error("El alumno "+alumno+" no esta matriculado");
            else{
                alumnos[alumno].puntuacion+=puntos;
            }
        }
        //n
        std::vector<nombre> examen(nombre profesor,int puntos){
            std::set<nombre> cjtoIni=profesor_alumnos[profesor];
            std::vector<nombre> sol;
            for(nombre alumno:cjtoIni){
                if(alumnos[alumno].puntuacion>=puntos) sol.push_back(alumno);
            }
            return sol;
        }
        //log n
        void aprobar(nombre alumno){
            if(alumnos.count(alumno)==0) throw std::domain_error("El alumno "+alumno+" no esta matriculado");
            else{
                profesor_alumnos[alumnos[alumno].profesor].erase(alumno);
                alumnos.erase(alumno);
            }
        }

};


#endif
