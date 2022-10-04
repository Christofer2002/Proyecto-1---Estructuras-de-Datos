//
// Created by Christofer Chaves on 21/9/2022.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    unsigned beggin, end;

    beggin=clock();
    LinkedList<Array<Integer>>lista = LinkedList<Array<Integer>>::addFactorialToLinkedList(1000, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Factorial de 1000"<<endl;
    cout << lista.toString() << endl;
    double time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo Factorial de 3 numeros en cada posicion del Array: " << time << endl;

    lista = LinkedList<Array<Integer>>::addFibonnacciToLinkedList(1000, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Fibonacci de 1000"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo Fibonnacci de 3 numeros en cada posicion del Array: " << time << endl;

    lista = LinkedList<Array<Integer>>::addCombinationalToLinkedList(1000,500, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 500"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo Fibonacci de 3 numeros en cada posicion del Array: " << time << endl;

    return 0;
}
