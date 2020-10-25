#include "DelimiterError.h"

// DEFAUT CONSTRUCTOR
DelimiterError::DelimiterError(){

}

// OVERLOADED CONSTRUCTOR
DelimiterError::DelimiterError(string file){
  m_file = file;
}

DelimiterError::~DelimiterError(){
  delete m_stack;
}

bool DelimiterError::pass(){
  ifstream inFile;
  string currentLine;
  int lineNumber = 0;
  m_stack= new GenStack<char>();
  m_stackLine = new GenStack<int>();

  inFile.open(m_file);
  while(getline(inFile, currentLine)){
    lineNumber++;
    for(int i = 0; i < currentLine.length(); ++i){
      char curr = currentLine[i];
      if((curr == '(') || (curr == '{') || (curr == '[')){
        m_stack->push(curr);
        m_stackLine->push(lineNumber);
        continue;
      }

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
string DelimiterError::compliment(char c){
  if(c == '{') return "}";
  if(c == '(') return ")";
  if(c == '[') return "]";
  return "";
}
// if(currentLine[i] == '[' || currentLine[i] == ']' || currentLine[i] == '{' || currentLine[i] == '}' || currentLine[i] == '(' || currentLine[i] == ')'){
//   count++;
// }

// if(currentLine[i] == ')' || currentLine[i] == '}' || currentLine[i] == ']'){
//   char curr = currentLine[i];
//   char peek = m_stack->peek();
//   if(curr == ')'){
//     if(peek == '('){
//       m_stack->pop();
//     }
//     else {
//       cerr << "ERROR: Line " << lineNumber << " expected a ) but found a " << curr << endl;
//       break;
//     }
//   }
//   else if(curr == '}'){
//     if(peek == '{'){
//       m_stack->pop();
//     }
//     else {
//       cerr << "ERROR: Line " << lineNumber << " expected a } but found a " << curr << endl;
//       break;
//     }
//   }
//   else if(curr == ']'){
//     if(peek == '['){
//       m_stack->pop();
//     }
//     else {
//       cerr << "ERROR: Line " << lineNumber << " expected a ] but found a " << curr << endl;
//       break;
//     }
//   }
// }
