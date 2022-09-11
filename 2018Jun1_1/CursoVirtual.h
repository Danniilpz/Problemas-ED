#ifndef cursovirtual
#define cursovirtual

#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_set>
#include <unordered_map>

class CursoVirtual{
    std::unordered_set<std::string,std::greater<>> estudiantes;
    std::unordered_map<std::string,std::pair<int,std::unordered_map<std::string,double>> tareas_estudiantes;
public:
    void addStudent(std::string id){
        if(estudiantes.count(id)>0) throw new domain_error("addStudent");
        else{
            estudiantes.insert(id);
        }
    }
    void addAssignment(std::string tarea,int peso){
        if(tareas_estudiantes.count(tarea)>0) throw new domain_error("addAssignment");
        else{
            std::unordered_map<std::string,int> estudiantes_notas;
            tareas_estudiantes[tarea]={peso,estudiantes_notas};
        }
    }
    void setMark(std::string estudiante,std::string tarea,double nota){
        if(estudiantes.count(estudiante)>0||tareas_estudiantes.count(tarea)>0) throw new domain_error("setMark");
        else{
            tareas_estudiantes[tarea].second[estudiante]=nota;
        }
    }
    double getFinalMark(std::string estudiante,double nota){
        if(estudiantes.count(estudiante)>0) throw new domain_error("getFinalMark");
        else{
            double nota=0;
            for(std::pair<int,std::unordered_map<std::string,double> p:tareas_estudiantes){
                nota+=p.second[estudiante];
            }
            return nota;
        }
    }
    void setAssignmentWeight(std::string tarea,int peso){
        if(tareas_estudiantes.count(tarea)=0) throw new domain_error("setAssignmentWeight");
        else{
            tareas_estudiantes[tarea].first=peso;
        }
    }
    void listOfStudents(std::list<std::string>& lista){
        for(std::string s:estudiantes) lista.insert(lista.end(),s);
    }
};

#endif