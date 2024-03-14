#include <iostream>

#include <ctime>

#include <cstdlib>

#include <iomanip>

using namespace std;


void welcome();
void project();
bool question();
int rollDice();
void addParts(int diceValue, int & numOfWheel, int & numOfAxle, int & numOfTorso, int & numOfPlunger, int & numOfHead, int & numOfAntenna, int & numOfPowerCells);
void getKeyPress();
bool robot(int & numOfHeel, int & numOfAxle, int & numOfTorso, int & numOfPlunger, int & numOfHead, int & numOfAntenna, int & numOfPowerCells, int & quantityOfRobot, int & timesOfRoll);
void initializeRobot(int & numOfWheel, int & numOfAxle, int & numOfTorso, int & numOfPlunger, int & numOfHead, int & numOfAntenna, int & numOfPowerCells, int & quantityOfRobot);
void initializeDice(int & firstOfDice, int & secondOfDice, int & thirdOfDice, int & fourthOfDice, int & fifthOfDice, int & sixthOfDice, int & seventhOfDice, int & timesOfRoll);
void printResults(int numOfWheel, int numOfAxle, int numOfTorso, int numOfPlunger, int numOfHead, int numOfAntenna, int numOfPowerCells);
void addDice(int diceValue, int & firstOfDice, int & secondOfDice, int & thirdOfDice, int & fourthOfDice, int & fifthOfDice, int & sixthOfDice, int & seventhOfDice, int & timesOfRoll);
void printDice(int firstOfDice, int secondOfDice, int thirdOfDice, int fourthOfDice, int fifthOfDice, int sixthOfDice, int seventhOfDice, int timesOfRoll);
void printRobotResults(int quantityOfRobot, int timesOfRoll);
void buildANewRobot(string & newRobot);
int main() {
  srand(time(0));
  welcome();
  project();
  while (!question()) {
    project();
  }
}

void welcome() {
  cout << "Welcome for using Robot Manufacture Program by Using Dice" << endl;
}

void project() {
  int diceValue;
  int numOfWheel, numOfAxle, numOfTorso, numOfPlunger, numOfHead, numOfAntenna, numOfPowerCells, quantityOfRobot;
  int firstOfDice, secondOfDice, thirdOfDice, fourthOfDice, fifthOfDice, sixthOfDice, seventhOfDice, timesOfRoll;
  initializeRobot(numOfWheel, numOfAxle, numOfTorso, numOfPlunger, numOfHead, numOfAntenna, numOfPowerCells, quantityOfRobot);
  initializeDice(firstOfDice, secondOfDice, thirdOfDice, fourthOfDice, fifthOfDice, sixthOfDice, seventhOfDice, timesOfRoll);
  while (!robot(numOfWheel, numOfAxle, numOfTorso, numOfPlunger, numOfHead, numOfAntenna, numOfPowerCells, quantityOfRobot, timesOfRoll)) {
    cout << endl;
    getKeyPress();
    diceValue = rollDice();
    addDice(diceValue, firstOfDice, secondOfDice, thirdOfDice, fourthOfDice, fifthOfDice, sixthOfDice, seventhOfDice, timesOfRoll);
    printDice(firstOfDice, secondOfDice, thirdOfDice, fourthOfDice, fifthOfDice, sixthOfDice, seventhOfDice, timesOfRoll);
    cout << endl;
    addParts(diceValue, numOfWheel, numOfAxle, numOfTorso, numOfPlunger, numOfHead, numOfAntenna, numOfPowerCells);
    printResults(numOfWheel, numOfAxle, numOfTorso, numOfPlunger, numOfHead, numOfAntenna, numOfPowerCells);

  }

}

bool question() {
  string newRobot;
  while (newRobot != "Y" & newRobot != "N") {
    buildANewRobot(newRobot);
    cout << "Invalid option, please try again." << endl;
  }
  if (newRobot == "Y") {
    return 0;
  } else if (newRobot == "N") {
    exit(1);
  }

}
int rollDice() {
  int diceValue;
  cout << "Robot Message:Dices" << endl;
  diceValue = rand() % 7 + 1;
  cout << endl;
  cout << "Dice Value:" << diceValue << endl;
  cout << endl;
  return diceValue;
}
void addDice(int diceValue, int & firstOfDice, int & secondOfDice, int & thirdOfDice, int & fourthOfDice, int & fifthOfDice, int & sixthOfDice, int & seventhOfDice, int & timesOfRoll) {
  if (diceValue == 1) {
    firstOfDice++;
  }
  if (diceValue == 2) {
    secondOfDice++;
  }
  if (diceValue == 3) {
    thirdOfDice++;
  }
  if (diceValue == 4) {
    fourthOfDice++;
  }
  if (diceValue == 5) {
    fifthOfDice++;
  }
  if (diceValue == 6) {
    sixthOfDice++;
  }
  if (diceValue == 7) {
    seventhOfDice++;
  }

  if (diceValue == 1 || diceValue == 2 || diceValue == 3 || diceValue == 4 || diceValue == 5 | diceValue == 6 || diceValue == 7) {
    timesOfRoll++;
  }

}
void addParts(int diceValue, int & numOfWheel, int & numOfAxle, int & numOfTorso, int & numOfPlunger, int & numOfHead, int & numOfAntenna, int & numOfPowerCells) {
  cout << "Robot Message:Parts" << endl;
  if (diceValue == 1 && numOfWheel !=3) {
    numOfWheel++;
    cout << endl;
    cout << "Added Wheel" << endl;
    cout << endl;

  }
  if (diceValue == 2 && numOfWheel < 1) {
    cout << endl;
    cout << "Cannot add Axle, not enough wheel." << endl;
    cout << endl;
  }

  if (numOfWheel == 1 || numOfWheel == 2 || numOfWheel == 3) {
    if (diceValue == 2 && numOfAxle != 3 || numOfAxle < numOfWheel) {
      numOfAxle++;
      cout << endl;
      cout << "Added Axle" << endl;
      cout << endl;
    }
  }
  if (diceValue == 3 && numOfAxle < 3) {
    cout << endl;
    cout << "Cannot add Torso, not enough Axles." << endl;
    cout << endl;
  }
  if (numOfAxle == 3) {
    if (diceValue == 3 && numOfTorso != 1) {
      numOfTorso++;
      cout << endl;
      cout << "Added Torso" << endl;
      cout << endl;
    }
  }

  if (diceValue == 4 && numOfTorso < 1) {
    cout << endl;
    cout << "Cannot add Plunger, not enough Torso." << endl;
    cout << endl;
  }
  if (diceValue == 5 && numOfTorso < 1) {
    cout << endl;
    cout << "Cannot add Head, not enough Torso." << endl;
    cout << endl;
  }
  if (diceValue == 7 && numOfTorso < 1) {
    cout << endl;
    cout << "Cannot add PowerCells, not enough Torso." << endl;
    cout << endl;

  }

  if (numOfTorso == 1) {
    if (diceValue == 4 && numOfPlunger != 1) {
      numOfPlunger++;
      cout << endl;
      cout << "Added Plunger" << endl;
      cout << endl;
    }
    if (diceValue == 5 && numOfHead != 1) {
      numOfHead++;
      cout << endl;
      cout << "Added Head" << endl;
      cout << endl;
    }
    if (diceValue == 7 && numOfPowerCells != 4) {
      numOfPowerCells++;
      cout << endl;
      cout << "Added PowerCells" << endl;
      cout << endl;
    }
  }
  if (diceValue == 6 && numOfHead < 1) {
    cout << endl;
    cout << "Cannot add Antenna, not enough Head." << endl;
    cout << endl;
  }
  if (numOfHead == 1) {
    if (diceValue == 6 && numOfAntenna != 2) {
      numOfAntenna++;
      cout << endl;
      cout << "Added Antenna" << endl;
      cout << endl;
    }

  }
  if (diceValue == 1 && numOfWheel == 3) {
    cout << endl;
    cout << "Cannot add Wheel again, limit reached." << endl;
    cout << endl;
  }
  if (diceValue == 2 && numOfAxle == 3) {
    cout << endl;
    cout << "Cannot add Axle again, limit reached." << endl;
    cout << endl;
  }
  if (diceValue == 3 && numOfTorso == 1) {
    cout << endl;
    cout << "Cannot add Torso again, limit reached." << endl;
    cout << endl;
  }
  if (diceValue == 4 && numOfPlunger == 1) {
    cout << endl;
    cout << "Cannot add Plunger again, limit reached." << endl;
    cout << endl;
  }
  if (diceValue == 5 && numOfHead == 1) {
    cout << endl;
    cout << "Cannot add Head again, limit reached." << endl;
    cout << endl;
  }
  if (diceValue == 6 && numOfAntenna == 2) {
    cout << endl;
    cout << "Cannot add Antenna again, limit reached." << endl;
    cout << endl;
  }
  if (diceValue == 7 && numOfPowerCells == 4) {
    cout << endl;
    cout << "Cannot add PowerCells again, limit reached." << endl;
    cout << endl;

  }

}
bool robot(int & numOfWheel, int & numOfAxle, int & numOfTorso, int & numOfPlunger, int & numOfHead, int & numOfAntenna, int & numOfPowerCells, int & quantityOfRobot, int & timesOfRoll) {
  if (numOfWheel == 3 && numOfAxle == 3 && numOfTorso == 1 && numOfPlunger == 1 && numOfHead == 1 && numOfAntenna == 2 && numOfPowerCells == 4) {
    quantityOfRobot++;
    cout << endl;
    printRobotResults(quantityOfRobot, timesOfRoll);
    cout << endl;
    return 1;
  }
  return 0;
}
void initializeRobot(int & numOfWheel, int & numOfAxle, int & numOfTorso, int & numOfPlunger, int & numOfHead, int & numOfAntenna, int & numOfPowerCells, int & quantityOfRobot) {
  numOfWheel = 0;
  numOfAxle = 0;
  numOfTorso = 0;
  numOfPlunger = 0;
  numOfHead = 0;
  numOfAntenna = 0;
  numOfPowerCells = 0;
  quantityOfRobot = 0;
}
void initializeDice(int & firstOfDice, int & secondOfDice, int & thirdOfDice, int & fourthOfDice, int & fifthOfDice, int & sixthOfDice, int & seventhOfDice, int & timesOfRoll) {
  firstOfDice = 0;
  secondOfDice = 0;
  thirdOfDice = 0;
  fourthOfDice = 0;
  fifthOfDice = 0;
  sixthOfDice = 0;
  seventhOfDice = 0;
  timesOfRoll = 0;
}
void printResults(int numOfWheel, int numOfAxle, int numOfTorso, int numOfPlunger, int numOfHead, int numOfAntenna, int numOfPowerCells) {
  cout << "Number of Wheels: " << numOfWheel << endl;
  cout << "Number of Axles: " << numOfAxle << endl;
  cout << "Number of Torso: " << numOfTorso << endl;
  cout << "Number of Plunger: " << numOfPlunger << endl;
  cout << "Number of Head: " << numOfHead << endl;
  cout << "Number of Antennas: " << numOfAntenna << endl;
  cout << "Number of PowerCells: " << numOfPowerCells << endl;
}

void printDice(int firstOfDice, int secondOfDice, int thirdOfDice, int fourthOfDice, int fifthOfDice, int sixthOfDice, int seventhOfDice, int timesOfRoll) {
  cout << "Appearences of 1 in Dice Rolls: " << firstOfDice << endl;
  cout << "Appearences of 2 in Dice Rolls: " << secondOfDice << endl;
  cout << "Appearences of 3 in Dice Rolls: " << thirdOfDice << endl;
  cout << "Appearences of 4 in Dice Rolls: " << fourthOfDice << endl;
  cout << "Appearences of 5 in Dice Rolls: " << fifthOfDice << endl;
  cout << "Appearences of 6 in Dice Rolls: " << sixthOfDice << endl;
  cout << "Appearences of 7 in Dice Rolls: " << seventhOfDice << endl;
  cout << "Total rolls of Dice Rolls: " << timesOfRoll << endl;
}
void buildANewRobot(string & newRobot) {
  cout << "Press Y to buid a new robot or N to exit the program:";
  getline(cin, newRobot);
}
void getKeyPress() {
  string key;
  cout << "Press enter to roll dice" << endl;
  getline(cin, key);
}
void printRobotResults(int quantityOfRobot, int timesOfRoll) {
  cout << "Robot Message:Robot numbers:" << endl;
  cout << "You made " << " 1 " << " Robot" << " using " << timesOfRoll << " times of rolls." << endl;
  cout << "You already made " << quantityOfRobot << " robot using this program." << endl;
}