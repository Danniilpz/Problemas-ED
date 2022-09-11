#ifndef HORA
#define HORA

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <stdexcept>
#include <vector>

class Persona{
    const int EDAD_MAX=100,EDAD_MIN=0;
    std::string nombre;
    int edad;
    public:
        Persona(std::string n="",int e=0):nombre(n),edad(e){
            if(e<EDAD_MIN||e>EDAD_MAX) throw std::invalid_argument("ERROR");
        }
        Persona& operator=(Persona const& p){
            if(this!=&p){
                nombre=p.nombre;
                edad=p.edad;
            }
            return *this;
        }
        std::string get_nombre() const {return nombre;}
        int get_edad() const {return edad;}
        void print(){
            std::cout<<nombre;
        }
};
inline std::istream& operator>>(std::istream& in,Persona& p){
    std::string n;
    int e;
    in>>e;
    std::cin.ignore();
    std::getline(std::cin,n);
    p=Persona(n,e);
    return in;
}
inline std::ostream& operator<<(std::ostream& out,Persona& p){
    p.print();
    return out;
}
class filtro_edad {
    int edadMin,edadMax;
public:
    filtro_edad(int emin=0,int emax=0):edadMin(emin),edadMax(emax){}
    bool operator ()(Persona p) {
        return p.get_edad()>=edadMin&&p.get_edad()<=edadMax;
    }
};
#endif
