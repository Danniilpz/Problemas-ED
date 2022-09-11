#ifndef HORA
#define HORA

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <stdexcept>
#include <vector>
using namespace std;

class Hora{
    const int HORAS_MAX=23,MINUTOS_MAX=59,SEGUNDOS_MAX=59;
    int hora,minuto,segundo;
    public:
        //Hora():hora(0),minuto(0),segundo(0){}
        Hora(int h=0,int m=0,int s=0):hora(h),minuto(m),segundo(s){
            if(h<0||h>HORAS_MAX) throw std::invalid_argument("ERROR");
            if(m<0||m>MINUTOS_MAX) throw std::invalid_argument("ERROR");
            if(s<0||s>SEGUNDOS_MAX) throw std::invalid_argument("ERROR");
        }
        bool operator<(Hora const& h) const{
            if(this->hora<h.hora) return true;
            else if(this->hora>h.hora) return false;
            else if(this->minuto<h.minuto) return true;
            else if(this->minuto>h.minuto) return false;
            else if(this->segundo<h.segundo) return true;
            else return false;
        }
        Hora& operator=(Hora const& h){
            if(this!=&h){
                hora=h.hora;
                minuto=h.minuto;
                segundo=h.segundo;
            }
            return *this;
        }
        int get_hora() {return hora;}
        int get_minuto() {return minuto;}
        int get_segundo() {return segundo;}
        void print(){
            cout<<setw(2)<<setfill('0')<<hora<<":"<<setw(2)<<setfill('0')<<minuto<<":"<<setw(2)<<setfill('0')<<segundo;
        }
};
inline istream& operator>>(istream& in,Hora& h){
    int hh,ss,mm;
    char aux;
    in>>hh>>aux>>mm>>aux>>ss;
    h=Hora(hh,mm,ss);
    return in;
}
inline ostream& operator<<(ostream& out,Hora& h){
    //out<<setw(2)<<setfill('0')<<h.get_hora()<<setw(2)<<setfill('0')<<h.get_minuto()<<setw(2)<<setfill('0')<<h.get_segundo();
    h.print();
    return out;
}
#endif
