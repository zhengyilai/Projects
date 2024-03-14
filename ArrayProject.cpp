#include <iostream>

#include <fstream>

#include  <cstdlib>

using namespace std;


void menu();
void endLine();
void enterKey();
void error();
bool getInput(string inputMenu);
void openFile(string list[], string listNumber[], int & size, int & numberSize);
void optionInputMenu(string & inputMenu);
void addItemToMemory(string list[], int & size, string itemInput);
void addingItem(string & itemInput);
void printList(string list[], int & size);
void inputForFileName(string & fileName);
void extensionsForFileName(string & extensions);
void writingFileName(string & fileName, string & extensions);
void showingFileName(string & fileName, string & extensions);
void itemNumbers(string & numberInput);
void addNumberToMemory(string listNumber[], int & numberSize, string numberInput);
void printNumber(string listNumber[], int & numberSize);
void enter(string & enterKey);
void saveToFile(string list[], string listNumber[], int & size);
void inputToFind(string & inputForFind);
int find(string listNumber[], int & numberSize, string inputForFind);
void itemStored(int & itemSize);
string removeItem(string list[], int & size);
string removeNumber(string listNumber[], int & numberSize);

int main() {
  menu();
}

void menu() {
  int size;
  int numberSize;
  string itemInput;
  string numberInput;
  string inputForFind;
  string inputMenu;
  string list[100];
  string listNumber[100];
  do {
    itemStored(size);
    endLine();
    cout << "1) Add an item to memory" << endl;
    cout << "2) Search memory for an item" << endl;
    cout << "3) List what's in memory" << endl;
    cout << "4) Save to a file" << endl;
    cout << "5) Read in from a file" << endl;
    endLine();
    cout << "0) Exit Program" << endl;
    endLine();
    optionInputMenu(inputMenu);
    if (inputMenu == "0") {
      exit(1);
    } else if (inputMenu == "1") {
      while (itemInput != "RETURN" || itemInput == "RETURN") {
        addingItem(itemInput);
        itemNumbers(numberInput);
        if (numberInput != "RETURN" || itemInput != "RETURN") {
          addItemToMemory(list, size, itemInput);
        }
        if (numberInput != "RETURN" && itemInput != "RETURN") {
          addNumberToMemory(listNumber, numberSize,
            numberInput);
        } else if (numberInput == "RETURN" || itemInput == "RETURN") {
          break;
        }
      }

    } else if (inputMenu == "2") {
      endLine();
      inputToFind(inputForFind);
      if (find(listNumber, numberSize, inputForFind) != -1) {
        cout << list[find(listNumber, numberSize, inputForFind)] << endl;
      } else {
        cout << "Not found!" << endl;
      }

    } else if (inputMenu == "3") {
      endLine();
      cout << "This is the item array." << endl;
      printList(list, size);
      cout << "This is the number array." << endl;
      printNumber(listNumber, numberSize);
    } else if (inputMenu == "4") {
      endLine();
      saveToFile(list, listNumber, size);
    } else if (inputMenu == "5") {
      openFile(list, listNumber, size, numberSize);
    }

  } while (!getInput(inputMenu));
}
bool getInput(string inputMenu) {
  if (inputMenu != "0") {
    endLine();
    cout << " " << endl;
    return 0;
  }
}

void addItemToMemory(string list[], int & size, string itemInput) {
  list[size++] = itemInput;
}

void addNumberToMemory(string listNumber[], int & numberSize, string numberInput) {
  listNumber[numberSize++] = numberInput;
}

void printList(string list[], int & size) {
  int arrayCount = 0;
  for (int i = 0; i < size; i++) {
    cout << "[" << i << "]" << list[i] << endl;
    arrayCount++;
    if (arrayCount % 15 == 0) {
      endLine();
      enterKey();
    }
  }
  if (list[0] == "") {
    cout << "Nothing is here" << endl;
  }
}

void printNumber(string listNumber[], int & numberSize) {
  int numberArrayCount = 0;
  for (int i = 0; i < numberSize; i++) {
    cout << "[" << i << "]" << listNumber[i] << endl;
    numberArrayCount++;
    if (numberArrayCount % 15 == 0) {
      endLine();
      enterKey();
    }
  }
  if (listNumber[0] == "") {
    cout << "Nothing is here" << endl;
  }
}
void saveToFile(string list[], string listNumber[], int & size) {
  ofstream outputFile;
  string fileName, itemInput, numberInput, extensions;
  inputForFileName(fileName);
  extensionsForFileName(extensions);
  writingFileName(fileName, extensions);
  outputFile.open(fileName, ios::app);
  for (int i = 0; i < size; i++) {
    outputFile << list[i] << endl;
    outputFile << listNumber[i] << endl;
  }
  outputFile.close();
}
void openFile(string list[], string listNumber[], int & size, int & numberSize) {
  ifstream inputFile;
  string fileName, inputForCheckList, extensions;
  string outputConsole, enterKey;
  int lineCount = 0;
  endLine();
  inputForFileName(fileName);
  extensionsForFileName(extensions);
  showingFileName(fileName, extensions);
  inputFile.open(fileName);
  if (inputFile.fail()) {
    cerr << "404 error" << endl;
    endLine();
    menu();
  }
  endLine();
  enter(enterKey);
  removeItem(list, size);
  removeNumber(listNumber, numberSize);
  for (int i = 0; i < 1000; i++) {
    getline(inputFile, outputConsole);
    cout << outputConsole << endl;
    if (i % 2 == 0 && outputConsole != "") {
      addItemToMemory(list, size, outputConsole);
    } else if (i % 2 != 0 && outputConsole != "") {
      addNumberToMemory(listNumber, numberSize,
        outputConsole);
    }
    lineCount++;
    if (lineCount % 10 == 0) {
      endLine();
      enter(enterKey);
    }
    if (inputFile.eof()) {
      break;
    }
  }
  inputFile.close();
}
int find(string listNumber[], int & numberSize, string inputForFind) {
  for (int i = 0; i < numberSize; i++) {
    if (listNumber[i] == inputForFind) {
      return i;
    }
  }
  return -1;
}
string removeNumber(string listNumber[], int & numberSize) {
  while (numberSize != 0) {
    numberSize--;
  }
  return listNumber[numberSize];
}
string removeItem(string list[], int & size) {
  while (size != 0) {
    size--;
  }
  return list[size];
}
void writingFileName(string & fileName, string & extensions) {
  ofstream outputFile;
  fileName = fileName + extensions;
}
void showingFileName(string & fileName, string & extensions) {
  ifstream inputFile;
  fileName = fileName + extensions;
}
void endLine() {
  cout << endl;
}
void inputForFileName(string & fileName) {
  cout << "Enter file name of the checklist: ";
  getline(cin, fileName);
}
void extensionsForFileName(string & extensions) {
  cout << "Enter extensions for file name: ";
  getline(cin, extensions);
}
void optionInputMenu(string & inputMenu) {
  cout << "Enter choice:";
  getline(cin, inputMenu);
}
void addingItem(string & itemInput) {
  cout << "Enter descriptions/RETURN when finished:";
  getline(cin, itemInput);
}
void inputToFind(string & inputForFind) {
  cout << "Enter inventory number to find:";
  getline(cin, inputForFind);
}
void enterKey() {
  string enter;
  cout << "Press Enter to continue" << endl;
  getline(cin, enter);
}
void itemNumbers(string & numberInput) {
  cout << "Enter iDnumbers to input/RETURN when finished:";
  getline(cin, numberInput);
}
void enter(string & enterKey) {
  cout << "Press enter to check for items" << endl;
  getline(cin, enterKey);
}
void itemStored(int & size) {
  cout << size << " items stored in memory" << endl;
}