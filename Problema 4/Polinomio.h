#ifndef POLINOMIO
#define POLINOMIO

#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdexcept>
#include <math.h>
#include <vector>
#include <algorithm> 

class Polinomio{
    std::vector<std::pair<int,int>> monomios;
    public:
        Polinomio(){}
        void addMonomio(std::pair <int,int> const& m){
             auto pos=std::lower_bound(monomios.begin(),monomios.end(),m,comparador());
             if(pos==monomios.end()||(*pos).second!=m.second){ //no se encuentra el exponente
                monomios.push_back(m);
                for(int i=(int)monomios.size()-1;i>0&&monomios[i].second<monomios[i-1].second;i--){
                    std::swap(monomios[i],monomios[i-1]);
                }
            }
            else{ //se encuentra el exponente
                (*pos).first+=m.first;
            }
        }
        long long int evaluar(int valor){
            long long int resultado=0;
            int expAnterior=0;
            long long int potencia=1;
            for(int i=0;i<monomios.size();i++){
                for(int j=expAnterior;j<monomios[i].second;j++){
                    potencia*=valor;
                }
                resultado+=potencia*monomios[i].first;
                expAnterior=monomios[i].second;
            }
            return resultado;
        }
        class comparador {
        public:
            bool operator ()(std::pair <int,int> const& m1, std::pair <int,int>const& m2) {
                return m1.second < m2.second;
            }
        };
};


#endif
