#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "functions.h"

using namespace std;

int main() {
    string line;
    vector<string> favGames;

    ifstream readFile("favGames.txt"); 
    if(readFile.is_open()) {
      while(getline(readFile, line)) {
         favGames.push_back(line); 
      }
    } else {
      cout << "File not found!\n";
    }
  readFile.close();


  
  cout << "Hello there, video game lover!\n";
  cout << "Video games sure are nifty, right?\n\n";
  cout << "Here's some of my favorite games\n";
  cout << "(conveniently stored in a neat little list):\n";
  cout << "1. Dragon Age: Origins\n";
  cout << "2. Fallout: New Vegas\n";
  cout << "3. Baldur's Gate 3\n\n";
  cout << "What's that? You want a neat little list too?\n";
  cout << "Well let's make it!\n\n";

  do{
    cout << "What would you like to do?\n";
    cout << "Press 1 to Add a game to your neat little list\n"; 
    cout << "Press 2 to Edit a game on your neat little list\n";
    cout << "Press 3 to Delete a game from your neat little list\n";
    cout << "Press 4 to View your neat little list\n";
    cout << "Press 5 to End this conversation\n";
    string num;
    getline(cin, num);

    //add
    if(num == "1"){
       AddGames(favGames);
    }

    //edit
    if(num == "2"){
      EditGames(favGames);
    }

    //delete
    if(num == "3"){
      DeleteGames(favGames);  
    }

    //view
    if(num == "4"){
      DisplayGames(favGames);
    }

    //end
    if(num == "5"){
      EndProgram(favGames);
      break;
    }

      }while(true);
    }