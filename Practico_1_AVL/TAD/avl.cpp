#include <stdio.h>
#include <iostream>
using namespace std;

struct NodoAVL
{
  int h;
  int data;
  NodoAVL* left;
  NodoAVL* right;
  NodoAVL(int k) : data(k), h(1), left(nullptr), right(nullptr) {}
};


struct RepresentacionAVL
{
  NodoAVL *raiz;
};
typedef RepresentacionAVL *AVL;

// auxiliary funtions

int height(NodoAVL * a)
{
  return a ? a->h : 0;
}

int getBalance(NodoAVL * a)
{
  return a ? height(a->left) - height(a->right) : 0;
}

//



AVL crearAVL()
{
    AVL a =new RepresentacionAVL();
    a->raiz = nullptr;
    return a;  
}

// aca habia un x y ese no iba de ninguna forma
void rotacionesIzq(NodoAVL *&pa)
{
  if(!pa || !pa->right) return;
  NodoAVL* r = pa->right;
  NodoAVL* t2 = r->left;

  r->left = pa;
  pa->right = t2;

  pa->h = 1 + max(height(pa->left), height(pa->right));
  r->h = 1 + max(height(r->left), height(r->right));

  pa = r;
}

// aca habia in int x y ese no iba de ningua forma
void rotacionesDer(NodoAVL *&pa)
{
  if (!pa || !pa->left) return;
  NodoAVL* l = pa->left;
  NodoAVL* t2 = l->right;

  l->right = pa;
  pa->left = t2;

  pa->h = 1 + max(height(pa->left), height(pa->right));
  l->h  = 1 + max(height(l->left),  height(l->right));

  pa = l;
}

// inserta el nodo en el AVL utilizando recursion
void insertarAVLRec(NodoAVL *&pa, int x)
{
  if (!pa) { pa = new NodoAVL(x); return; }

  // Permitir duplicados: iguales van a LA DERECHA
  if (x < pa->data) insertarAVLRec(pa->left, x);
  else              insertarAVLRec(pa->right, x);

  pa->h = 1 + max(height(pa->left), height(pa->right));
  int balance = getBalance(pa);

  // Left heavy
  if (balance > 1) {
    if (x < pa->data) { rotacionesDer(pa); }
    else              { rotacionesIzq(pa->left); rotacionesDer(pa); }
    return;
  }
  // Right heavy (tratar iguales como derecha)
  if (balance < -1) {
    if (x >= pa->data) { rotacionesIzq(pa); }
    else               { rotacionesDer(pa->right); rotacionesIzq(pa); }
    return;
  }
}


// Metodo principal para insertar en el AVL
void insertarAVL(AVL a, int e)
{
  NodoAVL *curr= a->raiz;
  while(curr)
  {
    if(curr->data>e)
    {
      curr = curr->left;
    }else if(curr->data<e)
    {
      curr = curr->right;
    }
  }
  curr = new NodoAVL(e);
}

// Imprime el AVL en orden creciente de forma recursiva
void inorderAVLRec(NodoAVL* a)
{
  if(!a) return;
  //root
  inorderAVLRec(a->left);
  // left
  cout << a->data << '\n';
  inorderAVLRec(a->right);
  //right
}

// Metodo principal para imprimir el AVL en orden
void inorderAVL(AVL a)
{

}