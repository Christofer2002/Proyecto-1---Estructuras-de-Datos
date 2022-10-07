//
// Created by Christofer Chaves on 21/9/2022.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    unsigned beggin, end;
    double time;
    cout<<"--------------Pruebas con 3 numeros-------------------"<<endl;
    beggin=clock();
    LinkedList<Array<AlmacenaNum>>lista = LinkedList<Array<AlmacenaNum>>::addFactorialToLinkedList(1000, 3);
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
    lista = LinkedList<Array<AlmacenaNum>>::addCombinationalToLinkedList(1000,350, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 350"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo combinatoria de 3 numeros en cada posicion del Array: " << time << endl;

    beggin=clock();
    lista = LinkedList<Array<AlmacenaNum>>::addCombinationalToLinkedList(1000,650, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 650"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo combinatoria de 3 numeros en cada posicion del Array: " << time << endl;

    beggin=clock();
    lista = LinkedList<Array<AlmacenaNum>>::addCombinationalToLinkedList(1000,500, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 500"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo combinatoria de 3 numeros en cada posicion del Array: " << time << endl;

    cout<<"\n--------------Pruebas con 4 numeros-------------------"<<endl;
    beggin=clock();
    lista = LinkedList<Array<AlmacenaNum>>::addFactorialToLinkedList(1000, 4);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Factorial de 1000"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo Factorial de 4 numeros en cada posicion del Array: " << time << endl;

    beggin=clock();
    lista = LinkedList<Array<AlmacenaNum>>::addFibonnacciToLinkedList(1000, 4);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Fibonacci de 1000"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo Fibonnacci de 4 numeros en cada posicion del Array: " << time << endl;

    beggin=clock();
    lista = LinkedList<Array<AlmacenaNum>>::addCombinationalToLinkedList(1000,350, 4);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 350"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo combinatoria de 4 numeros en cada posicion del Array: " << time << endl;

    beggin=clock();
    lista = LinkedList<Array<AlmacenaNum>>::addCombinationalToLinkedList(1000,650, 4);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 650"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo combinatoria de 4 numeros en cada posicion del Array: " << time << endl;

    beggin=clock();
    lista = LinkedList<Array<AlmacenaNum>>::addCombinationalToLinkedList(1000,500, 4);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 500"<<endl;
    cout << lista.toString() << endl;
    time = (double(end - beggin) / CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de metodo combinatoria de 4 numeros en cada posicion del Array: " << time << endl;

    return 0;
}
