//
// Created by Christofer Chaves on 21/9/2022.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<Array<Integer>> lista = LinkedList<Array<Integer>>::addFactorialToLinkedList(1000);
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Factorial de 1000"<<endl;
    cout << lista.toString() << endl;

    lista = LinkedList<Array<Integer>>::addFibonnacciToLinkedList(1000);
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Fibonacci de 1000"<<endl;
    cout << lista.toString() << endl;

    /*lista = LinkedList<Array<Integer>>::addCombinationalToLinkedList(1000,500);
    lista.flipLinkedList();
    cout<<"---------------------------------"<<endl;
    cout<<"Combinatoria de 1000 y 500"<<endl;
    cout << lista.toString() << endl;*/

    return 0;
}
