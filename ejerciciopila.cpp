#include <iostream>
using namespace std;

template <typename T>
class Pila {
private:
    T arr[10];
    T* top = NULL;

public:
    Pila() {
        top = arr;
    }

    void push(T valor) {
        if (top == arr + 10) {
            cout << "La pila está llena. No se puede insertar " << valor << endl;
        }
        else {

            for (T* ptr = top; ptr > arr; --ptr) {
                *ptr = *(ptr - 1);
            }

            *arr = valor;
            top++;
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
        for (T* ptr = arr; ptr < top; ++ptr) {
            cout << *ptr << "-->";
        }
        cout << endl;
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