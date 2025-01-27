/**
  * a class that opens a file to check if there are any errors in the process
  * @author Tarek El-Hajjaoui
  * @version 1.0
*/
#ifndef FILERROR_H
#define FILERROR_H
#include <iostream>
#include <fstream>
using namespace std;
class FileError{
  /* private fields */
  private:
    string m_file;
    ifstream m_inFile;
  /* public fields */
  public:
    /* Default Constructor */
    FileError();
    /* Overloaded Constructor - takes a string representing the name of the file to open */
    FileError(string file);
    /* Destructor */
    ~FileError();
    /* MUTATOR */
    void setFile(string file);
    /* HELPER FUNCTIONS */
    string getFile(); // prompts user for the name of the file to check
    string getFileValue();
    int checkFile(); // opens a file and checks if it fails - returns true if successful and false if it failed to open the file
    bool pass(); // opens a file and checks if it fails - returns result of checkFile()

};
#endif
