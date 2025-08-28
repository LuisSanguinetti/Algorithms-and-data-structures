#include <stdio.h>
#include <iostream>
using namespace std;

struct NodoAVL
{
    int dato;
    NodoAVL *izq;
    NodoAVL *der;
    int fVal;

    NodoAVL(int x): dato(x), izq(NULL), der(NULL), fVal(0) {}
};

struct RepresentacionAVL
{
  NodoAVL *raiz;
  int cantElementos;

  RepresentacionAVL(): raiz(NULL), cantElementos(0) {}
};
typedef RepresentacionAVL *AVL;

AVL crearAVL()
{
    return new RepresentacionAVL();
}

// inserta el nodo en el AVL utilizando recursion
bool insertarAVLRec(NodoAVL *&pa, int x, bool &varioAltura)
{
    bool insertado;
    if (pa == NULL)
    {
        pa = new NodoAVL(x);
        varioAltura = true;
        return true;
    }
    if (x < pa->dato)
    {
        insertado = insertarAVLRec(pa->izq, x, varioAltura);
        if (varioAltura)
        {
            switch (pa->fVal)
            {
                case 1:
                    pa->fVal = 0;
                    varioAltura = false;
                    break;
                case 0:
                    pa->fVal = -1;
                    break;
                case -1:
                    NodoAVL *p1 = pa->izq;
                    if(p1->fVal == -1){
                        pa->izq = p1->der;
                        p1->der = pa;
                        pa->fVal = 0;
                        pa = p1;
                    } else {
                        NodoAVL *p2 = p1->der;
                        p1->der = p2->izq;
                        p2->izq = p1;
                        pa->izq = p2->der;
                        p2->der = pa;
                        pa->fVal = p2->fVal == -1 ? 1 : 0;
                        p1->fVal = p2->fVal == 1 ? -1 : 0;
                        pa = p2;
                    }
                    pa->fVal = 0;
                    varioAltura = false;
                    break;
            }
            varioAltura = false;
        }
        return insertado;
    }
    else if (x > pa->dato)
    {
        insertado = insertarAVLRec(pa->der, x, varioAltura);
        if (varioAltura)
        {
            switch (pa->fVal)
            {
                case -1:
                    pa->fVal = 0;
                    varioAltura = false;
                    break;
                case 0:
                    pa->fVal = 1;
                    break;
                case 1:
                    NodoAVL *p1 = pa->der;
                    if(p1->fVal == 1){
                        pa->der = p1->izq;
                        p1->izq = pa;
                        pa->fVal = 0;
                        pa = p1;
                    } else {
                        NodoAVL *p2 = p1->izq;
                        p1->izq = p2->der;
                        p2->der = p1;
                        pa->der = p2->izq;
                        p2->izq = pa;
                        pa->fVal = p2->fVal == 1 ? -1 : 0;
                        p1->fVal = p2->fVal == -1 ? 1 : 0;
                        pa = p2;
                        //return insertado;
                        pa->fVal = 0;
                    }
                    varioAltura = false;
                    break;
            }
            varioAltura = false;
        }
        return insertado;
    } else return false;
}

// Metodo principal para insertar en el AVL
void insertarAVL(AVL a, int e)
{
    bool varioAltura = false;
    bool insertado = insertarAVLRec(a->raiz, e, varioAltura);
    if (insertado)
    {
        a->cantElementos++;
    }
}

// Imprime el AVL en orden creciente de forma recursiva
void inorderAVLRec(NodoAVL* a)
{
    if (a != NULL)
    {
        inorderAVLRec(a->izq);
        cout << a->dato << endl;
        inorderAVLRec(a->der);
    }
}

// Metodo principal para imprimir el AVL en orden
void inorderAVL(AVL a)
{
    inorderAVLRec(a->raiz);
}

/*
int main()
{
    AVL a = crearAVL();
    int cant;
    cin >> cant;
    for (int i = 0; i < cant; i++)
    {
        int x;
        cin >> x;
        insertarAVL(a, x);
    }
    inorderAVL(a);
    return 0;
}
*/