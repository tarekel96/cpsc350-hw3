#ifndef GENSTACK_H
#define GENSTACK_H
#include <iostream>
using namespace std;
/*
  * @name GenStack - a Stack Data Structure implemented with a template class and an m_stackArray
*/
template <class T>
class GenStack{
  private:
    T *m_stackArray;  /* the array pointer that is used to implement the Stack and store the values of the Stack */
    int m_top;        /* keeps track of the Stack */
    int m_size;       /* the size of the array that used to implement the Stack */
  public:
    /* DEFAULT CONSTRUCTOR */
    GenStack(){
      m_stackArray = new T[128];
      m_top = -1;
      m_size = 128;
    }
    /*
      * OVERLOADED CONSTRUCTOR
      * @param maxSize - the size of the array allocated for the GenStack instance
    */
    GenStack(int maxSize){
      m_stackArray = new T[maxSize];
      m_top = -1;
      m_size = maxSize;
    }
    /* DESTRUCTOR */
    ~GenStack(){
      delete m_stackArray;
    }
    /* CORE FUNCTIONS */
    /*
      * @param data - the data to be pushed to the top of the Stack
    */
    void push(T data){
        if(!isFull())
          m_stackArray[++m_top] = data;
        else{
          cerr << "ERROR: STACK OVERFLOW" << endl;
        }
    }
    /*
      * @return - returns the item that is popped from the Stack
    */
    T pop(){
      if(!isEmpty())
        return m_stackArray[m_top--];
      else{
        cerr << "ERROR: STACK IS EMPTY" << endl;
      }
    }
    /*
      *@return - returns the item at the top of the Stack
    */
    T peek(){
      if(!isEmpty())
        return m_stackArray[m_top];
      else{
        cerr << "ERROR: STACK IS EMPTY" << endl;
      }
    }
    /* AUXILIARY FUNCTIONS */
    /*
      * @return - returns true if stack is full and false otherwise
    */
    bool isFull(){
      return (m_top == m_size - 1);
    }
    /*
      * @return - returns true if the stack is empty and false otherwise
    */
    bool isEmpty(){
      return (m_top == -1);
    }
    /*
      * @return - returns the size of the stack
    */
    int getSize(){
      return m_top + 1;
    }
};
#endif
