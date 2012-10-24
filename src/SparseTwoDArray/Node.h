#ifndef __NODE_H_
#define __NODE_H_

template <typename T>
class Node {
  private:
    Node<T>* nextRow;
    Node<T>* nextCol;
    T value;
    int row;
    int col;
  public: 
    Node<T>(Node<T>* nxtRow, Node<T>* nxtCol, T val, int r, int c);
    ~Node<T>();
    void setNextRow(Node<T>* nxt);
    void setNextCol(Node<T>* nxt);
    void setRow(int r);
    void setCol(int c);
    int getRow();
    int getCol();
    Node<T>* getNextRow();
    Node<T>* getNextCol();
    T getValue();
};

#endif
