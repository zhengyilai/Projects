#include <iostream>

#include <fstream>

#include  <cstdlib>

using namespace std;


void callMenu();
void itemToCheckList();
void diplayCheckList();
void exitMenu();
bool getInput();
void inputToCheckList();
void printCheckList();
void inputForFileName(string & fileName);
void extensionsForFileName(string & extensions);
void writingFileName(string & fileName, string & extensions);
void showingFileName(string & fileName, string & extensions);
void enter(string & enterKey);
void enterOrReturn(string & inputForCheckList);
void error();
void optionInputMenu(string & inputMenu);
int main() {
  callMenu();
}
void callMenu() {
  do{
    itemToCheckList();
  diplayCheckList();
  exitMenu();
  }while (!getInput());
}
void itemToCheckList() {
  cout << "1. Add an item to a checklist." << endl;

}
void diplayCheckList() {
  cout << "2. Display the contents of a checklist." << endl;
}
void exitMenu() {
  cout << "3. Exit" << endl;
}

bool getInput() {
  string inputMenu;
  optionInputMenu(inputMenu);
  if (inputMenu == "1") {
    inputToCheckList();
    return 1;
  }
  if (inputMenu == "2") {
    printCheckList();
    return 1;
  } else if (inputMenu == "3") {
    exit(1);
  } else if(inputMenu!="3") {
    cout<<endl;
    cout << "Invalid option, please try again." << endl;
    cout<<endl;
    return 0;
  }

}
void inputToCheckList() {
  ofstream outputFile;
  string fileName, inputForCheckList, extensions;
  cout<<endl;
  inputForFileName(fileName);
  extensionsForFileName(extensions);
  writingFileName(fileName, extensions);
  outputFile.open(fileName, ios::app);
  while (inputForCheckList != "RETURN") {
    enterOrReturn(inputForCheckList);
    if (inputForCheckList != "RETURN") {
      outputFile << inputForCheckList << endl;
    }
    if (inputForCheckList == "RETURN") {
      cout << endl;
      callMenu();
    }

  }

  outputFile.close();
}
void printCheckList() {
  ifstream inputFile;
  string fileName, inputForCheckList, extensions;
  string outputConsole, enterKey;
  int lineCount = 0;
  cout<<endl;
  inputForFileName(fileName);
  extensionsForFileName(extensions);
  showingFileName(fileName, extensions);
  inputFile.open(fileName);
  if (inputFile.fail()) {
    error();
    callMenu();
  }
  cout << endl;
  enter(enterKey);
  for (int i = 0; i < 1000; i++) {
    getline(inputFile, outputConsole);
    cout << outputConsole << endl;
    lineCount++;
    if (lineCount % 10 == 0) {
      cout << endl;
      enter(enterKey);
    }
    if (inputFile.eof()) {
      break;
    }
  }
  cout << endl;
  callMenu();

  inputFile.close();
}
void enter(string & enterKey) {
  cout << "Press enter to check for items" << endl;
  getline(cin, enterKey);
}
void optionInputMenu(string & inputMenu) {
  cout << "Enter option:";
  getline(cin, inputMenu);
}
void enterOrReturn(string & inputForCheckList) {
  cout << "Enter item to the checklist/RETURN when finished: ";
  getline(cin, inputForCheckList);
}
void inputForFileName(string & fileName) {
  cout << "Enter file name of the checklist: ";
  getline(cin, fileName);
}
void extensionsForFileName(string & extensions) {
  cout << "Enter extensions for file name: ";
  getline(cin, extensions);
}
void writingFileName(string & fileName, string & extensions) {
  ofstream outputFile;
  fileName = fileName + extensions;
}
void showingFileName(string & fileName, string & extensions) {
  ifstream inputFile;
  fileName = fileName + extensions;
}
void error() {
  cerr << "404 error" << endl;
  cout << endl;
}
