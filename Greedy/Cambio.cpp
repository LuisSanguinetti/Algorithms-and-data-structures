using namespace std;
#include <iostream>
#include "../Lista/lista.cpp"
#include "../heap_1-main/datastructures/maxheap.cpp"
#define INF 99999

class par {
    public:
        int valor;
        int cantidad;
    par(int valor, int cantidad) : valor(valor), cantidad(cantidad) {}

    void agregar(int cant){
        cantidad += cant;
    }
};

Lista<par> Cambio(Heap<int> ListaMonedas, int& cambio){
    Lista<par> Resultado;
    int pos =0;
    while(!ListaMonedas.esVacia() && cambio >0)
    {
        int monAct = ListaMonedas.valorTope();
        if(cambio-monAct>=0)
        {
            cambio -= monAct;
            if(!Resultado.EsVacia() && Resultado.ObtenerFin().valor == monAct){
                Resultado.ObtenerFin().agregar(1);
            }else{
                par monPar = par(monAct, 1);
                Resultado.InsertarFin(monPar);
            }
        }
        ListaMonedas.eliminarTope();
    }
    return Resultado;
}


// esta mal porqu eel max heap reppite prioridad y dato pero bueno no quiro cambiar todo no jodan leru leru
int main() {
    int cantMonedas, moneda, cambio;
    cin >> cantMonedas;
    Heap<int> prioriMonedas = Heap<int>(cantMonedas);
    // usar maxheap
    for(int i =0;i<cantMonedas;i++){
        cin >> moneda;
        prioriMonedas.insertar(moneda,moneda);
    }
    cin >> cambio;
    int originalCambio = cambio;
    Lista<par> MonedasCambio = Cambio(prioriMonedas, cambio);
    cout << "Cambio: " << originalCambio - cambio << " Pesos " << " Falto: "<< cambio << " Pesos " << " Dale un caramelo"<< endl;
    while (!MonedasCambio.EsVacia()){
        par mon = MonedasCambio.ObtenerPpio();
        cout << "Moneda de: " << mon.valor << " Pesos "<< " Cantidad: " << mon.cantidad << endl;
        MonedasCambio.BorrarPpio();
    }
    return 0;
}