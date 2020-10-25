#include "DelimiterError.h"

/* DEFAUT CONSTRUCTOR */
DelimiterError::DelimiterError(){}
/* OVERLOADED CONSTRUCTOR */
/*
  * @param file - the name of the file to be processed
*/
DelimiterError::DelimiterError(string file){
  m_file = file;
}
/* DESTRUCTOR */
DelimiterError::~DelimiterError(){
  delete m_stack;
  delete m_stackLine;
}
/*
  * pass is the function that checks the delimiters in a file
  @return - returns true if there are no delimiters errors and false otherwise
*/
bool DelimiterError::pass(){
  ifstream inFile;
  string currentLine;
  int lineNumber = 0;
  /* STACKS */
  m_stack= new GenStack<char>();      /* stores left delimiters */
  m_stackLine = new GenStack<int>();  /* keep track of the line numbers for the delimiters */

  inFile.open(m_file);
  while(getline(inFile, currentLine)){
    lineNumber++;
    for(int i = 0; i < currentLine.length(); ++i){
      char curr = currentLine[i];
      /* push left limiters to delimiter stack */
      if((curr == '(') || (curr == '{') || (curr == '[')){
        m_stack->push(curr);
        m_stackLine->push(lineNumber);
        continue;
      }
      /* right delimiters are compared to the top of the stack */
      /* PARENTHESIS */
      else if(curr == ')'){
        if(m_stack->peek() == '('){
          m_stack->pop();
          m_stackLine->pop();
        }
        else{
          cerr << "ERROR: Line " << lineNumber << " expected a (" << endl;
          return false;
        }
      }
      /* CURLY BRACES */
      else if(curr == '}'){
        if(m_stack->peek() == '{'){
          m_stack->pop();
          m_stackLine->pop();
        }
        else{
          cerr << "ERROR: Line " << lineNumber << " expected a {" << endl;
          return false;
        }
      }
      /* BRACES */
      else if(curr == ']'){
        if(m_stack->peek() == '['){
          m_stack->pop();
          m_stackLine->pop();
        }
        else{
          cerr << "ERROR: Line " << lineNumber << " expected a [" << endl;
          return false;
        }
      }
    }
  }
  inFile.close();
  /* in certain situations when a right delimiter is missing, the above code will not catch the error.
  The code below accounts for those situations and that is why needed a stack for line numbers */
  if(!m_stack->isEmpty()){
    inFile.open(m_file);
    string line;
    int lineNumber = 0;
    while(getline(inFile, line)){
      ++lineNumber;
      if(lineNumber == m_stackLine->peek()){
        cerr << "ERROR: Line " << lineNumber << " missing a " << compliment(m_stack->peek()) << endl;
        return false;
      }
    }
  }
}
/*
  * @param c - delimiter supplied to receive its compliment
  * @return - returns the compliment to the left delimiter parameter
*/
string DelimiterError::compliment(char c){
  if(c == '{') return "}";
  if(c == '(') return ")";
  if(c == '[') return "]";
  return "";
}
