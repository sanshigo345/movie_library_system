#include <iostream>
#include <fstream>
#include <vector>
#include "LibrarySystem.h"

using namespace std;

ofstream outputFile; // global variable for output file

/*
 * main method read commands file and calls necessary methods from library system
 */

int main(int argc, char* argv[]) {
    outputFile.open(argv[2]);

    LibrarySystem system;

    outputFile << "===Movie Library System===\n";

    // Getting Commands
    ifstream CommandsFile(argv[1]);
    string command;
    string delimiter = "\t";
    vector<string> allCommands;
    allCommands.push_back("x");
    int whileloopcntr = 1;
    while (getline(CommandsFile, command)) {
        size_t pos = 0;
        string token;
        int arrayCounter = 0;
        string commandArr[4];
        while ((pos = command.find(delimiter)) != string::npos) {
            token = command.substr(0, pos);
            commandArr[arrayCounter] = token;
            command.erase(0, pos + delimiter.length());
            arrayCounter++;
        }
        commandArr[arrayCounter] = command;
        allCommands.push_back(commandArr[0]);
        // Getting Commands

        // Parsing Commands
        if (commandArr[0] == "addUser") {
            if (commandArr[0] != allCommands[whileloopcntr-1]) {
                outputFile << "\n===addUser() method test===\n";
                system.addUser(stoi(commandArr[1]), commandArr[2]);
            } else {
                system.addUser(stoi(commandArr[1]), commandArr[2]);
            }
        } else if (commandArr[0] == "addMovie") {
            if (commandArr[0] != allCommands[whileloopcntr-1]) {
                outputFile << "\n===addMovie() method test===\n";
                system.addMovie(stoi(commandArr[1]), commandArr[2], stoi(commandArr[3]));
            } else {
                system.addMovie(stoi(commandArr[1]), commandArr[2], stoi(commandArr[3]));
            }
        } else if (commandArr[0] == "showAllMovie") {
            if (commandArr[0] != allCommands[whileloopcntr-1]) {
                outputFile << "\n===showAllMovie() method test===\nMovie id - Movie name - Year - Status\n";
                system.ShowAllMovies();
            } else {
                system.ShowAllMovies();
            }
        } else if (commandArr[0] == "checkoutMovie") {
            if (commandArr[0] != allCommands[whileloopcntr-1]) {
                outputFile << "\n===checkoutMovie() method test===\n";
                system.checkOutMovie(stoi(commandArr[1]), stoi(commandArr[2]));
            } else {
                system.checkOutMovie(stoi(commandArr[1]), stoi(commandArr[2]));
            }
        } else if (commandArr[0] == "showMovie") {
            if (commandArr[0] != allCommands[whileloopcntr-1]) {
                outputFile << "\n===showMovie() method test===\n";
                system.showMovie(stoi(commandArr[1]));
            } else {
                system.showMovie(stoi(commandArr[1]));
            }
        } else if (commandArr[0] == "showUser") {
            if (commandArr[0] != allCommands[whileloopcntr-1]) {
                outputFile << "\n===showUser() method test===\n";
                system.showUser(stoi(commandArr[1]));
            } else {
                system.showUser(stoi(commandArr[1]));
            }
        } else if (commandArr[0] == "deleteMovie") {
            if (commandArr[0] != allCommands[whileloopcntr-1]) {
                outputFile << "\n===deleteMovie() method test===\n";
                system.deleteMovie(stoi(commandArr[1]));
            } else {
                system.deleteMovie(stoi(commandArr[1]));
            }
        } else if (commandArr[0] == "returnMovie") {
            if (commandArr[0] != allCommands[whileloopcntr-1]) {
                outputFile << "\n===returnMovie() method test===\n";
                system.returnMovie(stoi(commandArr[1]));
            } else {
                system.returnMovie(stoi(commandArr[1]));
            }
        } else if (commandArr[0] == "deleteUser") {
            if (commandArr[0] != allCommands[whileloopcntr - 1]) {
                outputFile << "\n===deleteUser() method test===\n";
                system.deleteUser(stoi(commandArr[1]));
            } else {
                system.deleteUser(stoi(commandArr[1]));
            }
        }
        whileloopcntr++;
    }
    CommandsFile.close();
    outputFile.close();
    return 0;
}