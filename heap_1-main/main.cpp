#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "./datastructures/minheap.cpp"
#include "../Lista/lista.cpp"
using namespace std;

int main()
{
    int cantidadListas;
    cin >> cantidadListas;
    Heap<Lista<int>*>* heap = new Heap<Lista<int>*>(cantidadListas);
    // agrega todos los elementos a una lista???? porque
    for (int i = 0; i < cantidadListas; i++)
    {
        int cantElem, elem;
        cin >> cantElem;
        Lista<int>* l = new Lista<int>();
        for (int i = 0; i < cantElem; i++)
        {
            cin >> elem;
            l->InsertarFin(elem);
        }
        heap->insertar(l->ObtenerPpio(), l);
    }

    // porque esta hecho de esta forma tan rara???? no era mas facil insertar directo al heap sisn lista???
    while(!heap->esVacia()){
        Lista<int>* l = heap->valorTope();
        cout << l->ObtenerPpio() << endl;
        heap->eliminarTope();
        l->BorrarPpio();
        if(!l->EsVacia()){
            heap->insertar(l->ObtenerPpio(), l);
        } else {
            delete l;
        }
    }
    
    return 0;
}