#ifndef HORA
#define HORA

#include <iostream>
#include <iomanip>
#include <fstream>
#include <array>
#include <stdexcept>
#include <vector>

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
        bool operator==(Hora const& h) const {
            return this->hora==h.hora && this->minuto==h.minuto && this->segundo==h.segundo;
        }
        bool operator<=(Hora const& h) const {
            return (*this < h) || *this == h;
        }
        bool operator>(Hora const& h) const{
            return !(*this <= h);
        }
        bool operator>=(Hora const& h) const {
            return (*this > h) || *this == h;
        }
        Hora& operator=(Hora const& h){
            if(this!=&h){
                hora=h.hora;
                minuto=h.minuto;
                segundo=h.segundo;
            }
            return *this;
        }
        Hora operator+(Hora const& h2){
            int h=0,m=0,s=0;
            /*if(segundo+h2.segundo>SEGUNDOS_MAX) m++;
            s=(segundo+h2.segundo)% SEGUNDOS_MAX;

            if(minuto+h2.minuto+m>MINUTOS_MAX) h++;
            m=(minuto+h2.minuto+m)% MINUTOS_MAX;

            if(h+hora+h2.hora>HORAS_MAX) throw std::out_of_range("ERROR");
            h=hora+h2.hora+h;*/
            h=hora+h2.get_hora();
            m=minuto+h2.get_minuto();
            s=segundo+h2.get_segundo();

            if(s>SEGUNDOS_MAX){
                s-= SEGUNDOS_MAX+1;
                m++;
            }
            if(m>MINUTOS_MAX){
                m-= MINUTOS_MAX+1;
                h++;
            }
            if(h>HORAS_MAX) throw std::out_of_range("ERROR");
            return Hora(h,m,s);
        }
        int get_hora() const {return hora;}
        int get_minuto() const {return minuto;}
        int get_segundo() const {return segundo;}
        void print(){
            std::cout<<std::setw(2)<<std::setfill('0')<<hora<<":"<< std::setw(2)<< std::setfill('0')<<minuto<<":"<< std::setw(2)<< std::setfill('0')<<segundo;
        }
};
inline std::istream& operator>>(std::istream& in,Hora& h){
    int hh,ss,mm;
    char aux;
    in>>hh>>aux>>mm>>aux>>ss;
    h=Hora(hh,mm,ss);
    return in;
}
inline std::ostream& operator<<(std::ostream& out,Hora& h){
    //out<< std::setw(2)<< std::setfill('0')<<h.get_hora()<<":"<< std::setw(2)<< std::setfill('0')<<h.get_minuto()<<":"<< std::setw(2)<< std::setfill('0')<<h.get_segundo();
    h.print();
    return out;
}
#endif
