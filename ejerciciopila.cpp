#include <iostream>
using namespace std;

template <typename T>
class Pila {
private:
    T arr[10];
    T* top = NULL;

public:
    
    void push(T valor) {
        if (top == NULL) {
            top = arr;
            *top = valor;
        }
        else if (top == arr + 10) {
            cout << "La pila está llena. No se puede insertar " << valor << endl;
        }
        else {
            top++;
          
            for (T* ptr = top; ptr > arr; --ptr) {
                *ptr = *(ptr - 1);
            }

            *arr = valor;
            cout << "Se inserto: " << valor << endl;
        }
    }

    bool pop(T& valor) {
        if (top == arr) {
            cout << "La pila esta vacia." << endl;
            return false;
        }
        else {
            valor = *arr;
            cout << "Se elimino: " << valor << endl;


            for (T* ptr = arr; ptr < top - 1; ++ptr) {
                *ptr = *(ptr + 1);
            }

            top--;
            return true;
        }
    }

    void imprimir() {
        cout << "Pila -> ";
        for (T* p = arr; Top && p <= Top; p++) {
            cout << *p << " -> ";
        }
        cout << "end;" << endl;

    }
};
int main() {
    Pila<int> miPila;
    int Elim;

    miPila.push(10);
    miPila.push(20);
    miPila.push(30);
    miPila.imprimir(); 
    if (miPila.pop(Elim)) {
        cout << "eliminado";
    }
    miPila.imprimir();


    return 0;
}
