#include <iostream>
#include "tree.h"

using namespace std;

int main()
{

    Tree<int> t1;
    Node<int> *aux;
    vector <Node<int>*> *aux2;
   // vector <Nodo*> *aux3;
    vector <int> num;


    num.push_back(2);
    num.push_back(3);
 //   num.push_back(4);

    aux = t1.init(1);
    aux2 = t1.insert(aux,num);

    num.clear();
    num.push_back(5);
    num.push_back(6);
    num.push_back(7);

    t1.insert(aux2->at(0),num);

    num.clear();
    num.push_back(8);
    num.push_back(9);
    num.push_back(10);

    t1.insert(aux2->at(1),num);

    t1.preorder(aux);


    return 0;
}
