#ifndef DELIMITERERROR_H
#define DELIMITERERROR_H
#include <iostream>
#include <fstream>
#include <string>
#include "FileError.h"
#include "GenStack.h"
using namespace std;
class DelimiterError{
  private:
    string m_file;
    GenStack<char>* m_stack;
    GenStack<int>* m_stackLine;
  public:
    DelimiterError();
    DelimiterError(string file);
    ~DelimiterError();
    // ACCESSORS
    string getFile();
    // MUTATORS
    void setFile(string file);
    string compliment(char c);
    bool pass();
};
#endif
