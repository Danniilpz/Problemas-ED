#ifndef COMPLEJO
#define COMPLEJO

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <math.h>

template <typename T>
class Complejo{
    T real,imaginaria;
    public:
        Complejo(T r=0,T i=0):real(r),imaginaria(i){            
        }
        Complejo operator+(Complejo const& c){
            float r=0,i=0;
            r=this->real+c.real;
            i=this->imaginaria+c.imaginaria;
            return Complejo(r,i);
        }
        Complejo operator*(Complejo const& c){
            float r=0,i=0;
            r=(this->real*c.real)-(this->imaginaria*c.imaginaria);
            i=this->real*c.imaginaria+c.real*this->imaginaria;
            return Complejo(r,i);
        }
        float modulo(){
            float resultado=(real*real+imaginaria*imaginaria);
            resultado=sqrt(resultado);
            return resultado;
        }
};

#endif