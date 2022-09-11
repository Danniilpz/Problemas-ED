// Nombre del alumno .....
// Andres Romero
// Usuario del Juez ......
// A61


#include <iostream>
#include <iomanip>
#include <fstream>
#include "conjunto.h"
#include <algorithm>
using namespace std;


// función que resuelve el problema
template <typename T>
void resolver(T fin, int k) 
{
    set<T> s;

    T centinela;
    int cont = 0;

    cin >> centinela;
    while (centinela != fin && cont < k)
    {
       if (!s.contains(centinela))
        {
            s.insert(centinela);
            cont++;
        }
        cin >> centinela;
    }
    //cout << s;
    while (centinela != fin)
    {
        if (centinela > s.get_min())
        {
            if (!s.contains(centinela))
            {
                s.delete_min();
            }
            s.insert(centinela);
        }
        cin >> centinela;
    }
    cout << s;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() 
{
    // leer los datos de la entrada
    char aux;
    cin >> aux;
    if (! std::cin)
        return false;
    int k;
    cin >> k;
    if (aux == 'N')
    {
        resolver(-1, k);
    }
    else
    {
        string aux = "FIN";
        resolver(aux, k);
    }
    
    //if (aux == 'N')
    //{
    //    set<int> s;
    //    int centinela;
    //    int cont = 0;
    //    cin >> centinela;
    //    while (centinela != -1 && cont < k)
    //    {
    //        s.insert(centinela);
    //        cont++;
    //        cin >> centinela;
    //    }

    //    while (centinela != -1)
    //    {
    //        if (centinela > s.get_min())
    //        {
    //            if (!s.contains(centinela))
    //            {
    //                s.delete_min();
    //            }
    //            s.insert(centinela);
    //        }
    //        cin >> centinela;
    //    }
    //    cout << s;
    //}
    //else
    //{
    //    set<string> s;
    //    string centinela;
    //    int cont = 0;
    //    cin >> centinela;
    //    //cout << centinela << " " << k << endl;
    //    while (centinela != "FIN" && cont < k)
    //    {
    //        s.insert(centinela);
    //        cont++;
    //        cin >> centinela;
    //    }

    //    //sort(s, (s + s.get_cont), greater<int>());
    //    //cout << s << endl;

    //    while (centinela != "FIN")
    //    {
    //        if (centinela > s.get_min())
    //        {
    //            if (!s.contains(centinela))
    //            {
    //                s.delete_min();
    //            }
    //            s.insert(centinela);
    //        }
    //        cin >> centinela;
    //    }
    //    cout << s;

    //    //set<string> s;
    //    //string centinela;
    //    //cin >> centinela;
    //    //while (centinela != "FIN")
    //    //{
    //    //    s.insert(centinela);
    //    //    cin >> centinela;
    //    //}

    //    //
    //    ///*s.printSet(0);
    //    //cout << endl;*/
    //    //set<string> set;
    //    //set.copiaOrdenada(s);
    //    //set.printSet(k);
    //    ////cout << set;
    //    //cout << endl;
    //}

    //// escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("sample5.in");
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