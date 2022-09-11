#ifndef ACADEMIA_CHINO
#define ACADEMIA_CHINO

// https://www.youtube.com/watch?v=eYu3Y8u3BRA

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <algorithm> 
#include <unordered_map>
#include <list>
#include <set>

using DNI=std::string;
struct info{
    int grupo;
    bool graduado;
    std::list<DNI>::iterator iterador;
};

class academia_chino{
    std::unordered_map<DNI,info> academia;
    std::unordered_map<int,std::list<DNI>> grupos;
    std::pair<bool,std::set<DNI,std::less<>>> grad;
    std::list<DNI> listaGrad;
    std::list<DNI>::iterator insertar_en_grupo(DNI dni, int grupo){
        auto& lista=grupos[grupo];
        return lista.insert(lista.begin(),dni);
    };
    public:
        //O(1)
        void nuevo_estudiante(DNI dni,int grupo){
            if(academia.count(dni)!=0) throw std::domain_error("Estudiante existente");
            else if(grupo<1||grupo>6) throw std::domain_error("Grupo incorrecto");
            else{
                academia[dni]={grupo,false,insertar_en_grupo(dni,grupo)};
            }
        }
        //O(log n)
        void promocionar(DNI dni){
            if(academia.count(dni)==0) throw std::domain_error("Estudiante no existente");
            else if(academia[dni].graduado) throw std::domain_error("Estudiante ya graduado");
            else{
                info i=academia[dni];
                grupos[i.grupo].erase(i.iterador);//O(1)
                if(i.grupo+1>6){//O(log n)
                    academia[dni].graduado=true;
                    grad.first=true;
                    grad.second.insert(dni);
                }
                else{//O(1)
                    academia[dni].grupo++;
                    academia[dni].iterador=insertar_en_grupo(dni,i.grupo+1);
                }
            }
        }
        //O(1)
        int grupo_estudiante(DNI dni){
            if(academia.count(dni)==0) throw std::domain_error("Estudiante no existente");
            else if(academia[dni].graduado) throw std::domain_error("Estudiante ya graduado");
            else{
                return academia[dni].grupo;
            }
        }
        //O(n)
        std::list<DNI> graduados(){
            if(grad.first){
                std::list<DNI> nuevaLista;
                for(DNI dni:grad.second)  nuevaLista.insert(nuevaLista.end(),dni);
                listaGrad=nuevaLista;
                grad.first=false;
            }
            return listaGrad;
        }
        //O(1)
        DNI novato(int grupo){
            if(grupo<1||grupo>6) throw std::domain_error("Grupo incorrecto");
            else if(grupos[grupo].size()==0) throw std::domain_error("Grupo vacio");
            else{
                return grupos[grupo].front();
            }
        }
};


#endif
