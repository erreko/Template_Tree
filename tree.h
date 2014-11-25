#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Node
{
private:
    T data;
    Node *parent;
    vector <Node*> childs;

public:

    Node();
    Node(T data,Node *parent);

    int getData();
    void setData(T value);
    Node<T> *getParent(Node *a);
    void setParent(Node *value);
    void setChilds(int size);
    Node<T>* getChilds(int i);
    vector<Node<T> *> *getChilds2();
    int getChilds3();
    Node<T> *getChilds4(int i, Node *a);
};

template<class T>
class Tree
{

private:
    Node<T> *root;
    Node<T> *current;

public:
     Tree();
     Node<T> *init(T data);
     vector<Node<T>*> *insert(Node<T>* ref, vector <T> data);
     void preorder(Node<T>* n);

};

#endif // TREE_H
using namespace std;

template<class T>
Node<T>::Node()
{
    parent = NULL;
    childs.clear();
    data = 0;

}

template<class T>
 Node<T>::Node(T data, Node *parent=NULL):data(data),parent(parent)
 {
     childs.clear();
 }

 template<class T>
 Tree<T>::Tree():root(NULL),current(NULL)
 {
 }

 template<class T>
 Node<T> *Tree<T>::init(T data)
 {
     if(root==NULL)
     {
         root = new Node<T>(data);
         current = root;
     }

     return root;
 }

 template<class T>
  vector<Node<T> *> *Tree<T>::insert(Node<T> *ref, vector<T> data)
  {
      current = ref;
      current->setChilds(data.size());

      for(unsigned int i = 0;i<data.size();i++)
      {
          Node<T> *newNode = new Node<T>(data[i]); //quien soy
          newNode->getParent(current); //de donde vengo

          current->getChilds4(i,newNode);
      }

      return current->getChilds2();
  }

template<class T>
void Tree<T>::preorder(Node<T> *n)
{
    if(n==NULL) return;

    cout<<n->getData()<<endl;

    for( int i = 0;i<n->getChilds3();i++)
    {
        preorder(n->getChilds(i));

    }
}

template<class T>
int Node<T>::getData()
{
    return data;
}

template<class T>
void Node<T>::setData(T value)
{
    data = value;
}

template<class T>
Node<T> *Node<T>::getParent(Node *a)
{
    parent = a;
    return parent;
}

template<class T>
void Node<T>::setParent(Node *value)
{
    parent = value;
}

template<class T>
void Node<T>::setChilds(int size)
{
    childs.resize(size);
}

template<class T>
Node<T> *Node<T>::getChilds(int i)
{
    return childs[i];
}

template<class T>
vector<Node<T> *> *Node<T>::getChilds2()
{
    return &childs;
}

template<class T>
int Node<T>::getChilds3()
{
    return childs.size();
}

template<class T>
Node<T>* Node<T>::getChilds4(int i, Node *a)
{
    childs[i] = a;

    return childs[i];
}
