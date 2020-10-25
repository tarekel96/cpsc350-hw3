#include "GenStack.h"
#include "FileError.h"
#include "DelimiterError.h"

int main(int argc, char ** argv){
  FileError* FE;
  int response;

  if(argc > 1){
    FE = new FileError(argv[1]);

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }
  else {
    FE = new FileError();

    if(FE->pass() == false){
      while(true){
        FE->setFile(FE->getFile());
        if(FE->pass()) break;
      }
    }
  }

  string file = FE->getFileValue();
  DelimiterError* DE = new DelimiterError(file);
  DE->pass() ? cout << "COMPILED" : cout << "FAILED";
  cout << endl;

  delete DE;
  delete FE;

  DelimiterError* DE_2;
  FileError* FE_2;

  cout << "ENTER 0 TO EXIT AND 1 IF WOULD LIKE TO CHECK ANOTHER FILE" << endl;
  cin >> response;
  if(response == 1){
    while(response == 1){
      FE_2 = new FileError();
      while(true){
        FE_2->setFile(FE_2->getFile());
        cout << "FILE NAME " << FE_2->getFileValue() << endl;
        if(FE_2->pass()) break;
      }
      string newFile = FE_2->getFileValue();
      DelimiterError* DE_2 = new DelimiterError(newFile);
      DE_2->pass() ? cout << "COMPILED" : cout << "FAILED";
      cout << endl;
      cout << "ENTER 0 TO EXIT AND 1 IF WOULD LIKE TO CHECK ANOTHER FILE" << endl;
      cin >> response;
    }
  }
  else if(response == 0){
    delete DE_2;
    delete FE_2;
    return 0;
  }
  // TODO
  delete DE_2;
  delete FE_2;
  return 0;
}
