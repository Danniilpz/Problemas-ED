// Daniel López Marqués
// A39


#include <iostream>
#include <iomanip>
#include <fstream>

void erase(int& pos,int* &v, int& contador){
    for(int i=pos;i<contador-1;i++){
        std::swap(v[i],v[i+1]);
    }
    contador--;
}

// función que resuelve el problema
int resolver(int* &v,int& contador,int& salto) {
    int pos=0;
    while(contador>1){
        pos=(pos+salto)%contador;
        erase(pos,v,contador);
    }
    return v[0];
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len, salto;
    std::cin>>len>>salto;
    if (len==0&&salto==0)
        return false;
    int* v=new int[len];
    int contador=0;
    for(int i=1;i<=len;i++){
        v[i-1]=i;
        contador++;
    }
    std::cout<<resolver(v,contador,salto);
    std::cout<<"\n";
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    while (resuelveCaso())
        ;

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}
