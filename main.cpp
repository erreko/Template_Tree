#include <iostream>
#include "tree.h"

using namespace std;

int main()
{

    Tree<string> t1;
    Node<string> *aux;
    vector <Node<string>*> *aux2;
   // vector <Nodo*> *aux3;
    vector <string> num;


    num.push_back("palabra1");
    num.push_back("palabra2");
 //   num.push_back(4);

    aux = t1.init("palabra0");
    aux2 = t1.insert(aux,num);

    num.clear();
    num.push_back("palabra4");
    num.push_back("palabra5");
    num.push_back("palabra6");

    t1.insert(aux2->at(0),num);

    num.clear();
    num.push_back("palabra7");
    num.push_back("palabra8");
    num.push_back("palabra9");

    t1.insert(aux2->at(1),num);

    t1.preorder(aux);


    return 0;
}
