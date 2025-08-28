#include <cassert>
#include <string>
#include <iostream>
#include <limits>
//#include "TAD/avl.cpp"
#include "TAD/avl_Profesor.cpp"
using namespace std;

// codigo profesor avl
int main()
{
    int n;
    if (!(cin >> n)) return 0;

    AVL a = crearAVL();
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        insertarAVL(a, x);
    }

    // imprimir in-order, un número por línea
    inorderAVLRec(a->raiz); // cambia la línea de impresión si querés \n (ver nota)
    cout << '\n';
    return 0;
}

//mi codigo para el avl
/*
int main()
{
    int n;
    if (!(cin >> n)) return 0;

    AVL a = crearAVL();
    for (int i = 0; i < n; ++i) {
        int x; 
        cin >> x;
        insertarAVLRec(a->raiz, x);
    }

    // imprimir in-order, un número por línea
    inorderAVLRec(a->raiz); // cambia la línea de impresión si querés \n (ver nota)
    cout << '\n';
    return 0;
}

*/