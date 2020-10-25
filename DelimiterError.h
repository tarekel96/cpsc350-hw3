#ifndef DELIMITERERROR_H
#define DELIMITERERROR_H
#include <iostream>
#include <fstream>
#include <string>
#include "FileError.h"
#include "GenStack.h"
using namespace std;
/*
  * @name DelimiterError - class responsible for checking delimiter syntax in a file
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
class DelimiterError{
  private:
    string m_file; /* file to be processed */
    GenStack<char>* m_stack;    /* stores the left delimiters of the file */
    GenStack<int>* m_stackLine; /* keep track of the line numbers for the delimiters */
  public:
    /* DEFAULT CONSTRUCTOR */
    DelimiterError();
    /* OVERLOADED CONSTRUCTOR */
    DelimiterError(string file);
    /* DESTRUCTOR */
    ~DelimiterError();
    /* ACCESSOR */
    string getFile();
    /* MUTATOR */
    void setFile(string file);
    /* HELPER METHOD */
    string compliment(char c);
    /* MAIN METHOD */
    bool pass();
};
#endif
