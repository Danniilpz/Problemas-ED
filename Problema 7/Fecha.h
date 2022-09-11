#ifndef FECHA
#define FECHA

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <stdexcept>
#include <vector>
using namespace std;

class Fecha{
    const int DIA_MAX=31,MES_MAX=12;
    int dia,mes,anio;
    public:
        Fecha(int d=0,int m=0,int a=0):dia(d),mes(m),anio(a){
            if(d<0||d>DIA_MAX) throw std::invalid_argument("ERROR");
            if(m<0||m>MES_MAX) throw std::invalid_argument("ERROR");
            if(a<0) throw std::invalid_argument("ERROR");
        }
        bool operator<(Fecha const& f) const{
            if (this->anio < f.anio) return true;
            else if (this->anio > f.anio) return false;
            else if (this->mes < f.mes) return true;
            else if (this->mes > f.mes) return false;
            else if (this->dia < f.dia) return true;
            else if (this->dia > f.dia) return false;
            else return false;
        }
        bool operator==(Fecha const& f) const {
            if (this->anio == f.anio && this->mes == f.mes && this->dia == f.dia) return true;
            else return false;
        }
        bool operator>(Fecha const& f) const {
            return !((*this) < f) && !((*this) == f);
        }
        bool operator>=(Fecha const& f) const {
            return !((*this) < f);
        }
        Fecha& operator=(Fecha const& f){
            if(this!=&f){
                dia = f.dia;
                mes = f.mes;
                anio = f.anio;
            }
            return *this;
        }
        void print(){
            cout<<setw(2)<<setfill('0')<<dia<<":"<<setw(2)<<setfill('0')<<mes<<":"<<setw(4)<<setfill('0')<<anio;
        }
};
inline istream& operator>>(istream& in,Fecha& f){
    int d,m,a;
    char aux;
    in>>d>>aux>>m>>aux>>a;
    f=Fecha(d,m,a);
    return in;
}
inline ostream& operator<<(ostream& out,Fecha& f){
    f.print();
    return out;
}
#endif
