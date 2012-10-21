#ifndef __NODE_H_
#define __NODE_H_

template <typename T>
class Node {
  private:
    Node<T>* next;
    T value;
  public: 
    Node<T>(Node<T>* nxt, T val);
    ~Node<T>();
    void setNext(Node* nxt);
    Node<T>* getNext();
    T getValue();
};

#endif
