//
// Created by Christofer Chaves on 21/9/2022.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    unsigned beggin, end;
    double time;

    beggin=clock();
    LinkedList<Array<AlmacenaNum>>lista = LinkedList<Array<AlmacenaNum>>::addFactorialToLinkedList(1000, 4);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Factorial de 1000"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo Factorial de 3 numeros en cada posicion del Array: " << time << endl;

    beggin=clock();
     lista = LinkedList<Array<AlmacenaNum>>::addFibonnacciToLinkedList(1000, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Fibonacci de 1000"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo Fibonnacci de 3 numeros en cada posicion del Array: " << time << endl;

    beggin=clock();
     lista = LinkedList<Array<AlmacenaNum>>::addCombinationalToLinkedList(1000,500, 4);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 500"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo Fibonacci de 3 numeros en cada posicion del Array: " << time << endl;

    return 0;
}
