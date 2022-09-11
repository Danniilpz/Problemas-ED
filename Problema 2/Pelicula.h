#ifndef PELICULA
#define PELICULA

#include <iostream>
#include <stdexcept>
#include <string>
#include "Hora.h"

class Pelicula{
    Hora hora_ini,hora_fin,duracion;
    std::string nombre;
    public:
        Pelicula(Hora ini=Hora(),Hora dur=Hora(),std::string nom=""):hora_ini(ini),duracion(dur),nombre(nom){
            hora_fin=hora_ini+duracion;
        }
        bool operator<(Pelicula const& p) const{
            if(this->hora_fin<p.hora_fin) return true;
            else if(this->hora_fin>p.hora_fin) return false;
            else return this->nombre<p.nombre;
        }
        Pelicula& operator=(Pelicula const& h){
            if(this!=&h){
                hora_ini=h.hora_ini;
                hora_fin=h.hora_fin;
                duracion=h.duracion;
                nombre = h.nombre;
            }
            return *this;
        }

        Hora get_hora_ini() const{return hora_ini;}
        Hora get_hora_fin() const {return hora_fin;}
        Hora get_duracion() const {return duracion;}
        std::string get_nombre() const {return nombre;}
        void print(){
            std::cout<<hora_fin<<" "<<nombre;
        }
};
inline std::istream& operator>>(std::istream& in,Pelicula& p){
    Hora ini,dur;
    std::string n;
    in>>ini>>dur;
    std::getline(std::cin,n);
    p=Pelicula(ini,dur,n);
    return in;
}
inline std::ostream& operator<<(std::ostream& out,Pelicula& p){
    p.print();
    //out<<p.get_hora_fin()<<" "<<p.get_nombre();
    return out;
}
#endif
