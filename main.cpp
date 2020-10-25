#include "GenStack.h"
#include "FileError.h"
#include "DelimiterError.h"

int getResponse(){
  int res = -1;
  while(true){
    cout << "ENTER 0 TO EXIT AND 1 IF WOULD LIKE TO CHECK ANOTHER FILE" << endl;
    cin >> res;
    if(cin.fail()){
      cerr << "ERROR: INVALID INPUT, PLEASE FOLLOW DIRECTIONS" << endl;
      cin.clear();
      cin.ignore(10000,'\n');
      continue;
    }
    else{
      if(res == 1 || res == 0) break;
      else{
        cerr << "ERROR: INVALID INPUT, PLEASE FOLLOW DIRECTIONS" << endl;
        continue;
      }
    }
  }
  return res;
}

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

  response = getResponse();
  if(response == 1){
    while(response == 1){
      FE_2 = new FileError();
      while(true){
        FE_2->setFile(FE_2->getFile());
        if(FE_2->pass()) break;
      }
      string newFile = FE_2->getFileValue();
      DelimiterError* DE_2 = new DelimiterError(newFile);
      DE_2->pass() ? cout << "COMPILED" : cout << "FAILED";
      cout << endl;
      response = getResponse();
    }
  }
  else if(response == 0){
    cout << "PROGRAM TERMINATED" << endl;
    delete DE_2;
    delete FE_2;
    return 0;
  }

  return 0;
}
