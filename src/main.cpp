<<<<<<< HEAD
//
// Created by Christofer Chaves on 21/9/2022.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    unsigned beggin = 0, end = 0;
    beggin = clock();
    LinkedList<Array<Integer>> lista = LinkedList<Array<Integer>>::addFactorialToLinkedList(1000, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Factorial de 1000"<<endl;
    cout << lista.toString() << endl;

    double time = (double(end-beggin)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de Factorial con 3 numeros enteros en cada celda del Array: " << time << endl;

   beggin = clock();
    lista = LinkedList<Array<Integer>>::addFibonnacciToLinkedList(1000, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Fibonacci de 1000"<<endl;
    cout << lista.toString() << endl;
    time = (double(end-beggin)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de Fibonnacci con 3 numeros enteros en cada celda del Array: " << time << endl;

    beggin = clock();
    lista = LinkedList<Array<Integer>>::addCombinationalToLinkedList(1000,500, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 500"<<endl;
    cout << lista.toString() << endl;
    time = (double(end-beggin)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de Fibonnacci con 3 numeros enteros en cada celda del Array: " << time << endl;

    return 0;
}
=======
//
// Created by Christofer Chaves on 21/9/2022.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    unsigned beggin = 0, end = 0;
    beggin = clock();
    LinkedList<Array<Integer>> lista = LinkedList<Array<Integer>>::addFactorialToLinkedList(1000, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Factorial de 1000"<<endl;
    cout << lista.toString() << endl;

    double time = (double(end-beggin)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de Factorial con 3 numeros enteros en cada celda del Array: " << time << endl;

    beggin = clock();
    lista = LinkedList<Array<Integer>>::addFibonnacciToLinkedList(1000, 3);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Fibonacci de 1000"<<endl;
    cout << lista.toString() << endl;
    time = (double(end-beggin)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de Fibonnacci con 3 numeros enteros en cada celda del Array: " << time << endl;

    beggin = clock();
    lista = LinkedList<Array<Integer>>::addCombinationalToLinkedList(1000,500);
    end = clock();
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 500"<<endl;
    cout << lista.toString() << endl;
    time = (double(end-beggin)/CLOCKS_PER_SEC);
    cout << "Tiempo de ejecucion de Fibonnacci con 3 numeros enteros en cada celda del Array: " << time << endl;

    return 0;
}
>>>>>>> 31344a19717938d0a7b13d079f50d8f153da8a85
