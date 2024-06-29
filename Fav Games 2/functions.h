#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string line;
vector<string> favGames;

//add
void AddGames(vector<string>& games) {
cout << "What game should we add to the list?\n";
  string input;
  getline(cin, input);

  favGames.push_back(input);
}

//edit
void EditGames(vector<string>& games){
bool foundGame = false;
    while(foundGame != true) {
    cout << "What game do you wish to change?\n";
    string input;
    getline(cin, input);

    for(int i = 0; i < favGames.size(); i++){
        cout << "We found the game!\n";
        foundGame = true;
        cout << "What is the new game?\n";
        string input;
        getline(cin, input);
        favGames[i] = input;
        cout << "Changed game to " << favGames[i] << "!\n";
        break;
    }

    if(!foundGame){
        cout << "That game was not found in the list.\n";
        break;
    }
    }
}

//delete
void DeleteGames(vector<string>& games){
bool foundGame = false;
  while(foundGame != true) {
    cout << "What game do you wish to delete?\n";
    string input;
    getline(cin, input);

    for(int i = 0; i < favGames.size(); i++){
      cout << "We found the game!\n";
      foundGame = true;
      favGames.erase(favGames.begin());
      cout << "That game has been deleted!\n";
      break;
    }

    if(!foundGame){
      cout << "That game was not found in the list.\n";
      break;
    }
  }
}

//view
void DisplayGames(const vector<string>& games) {
cout << "Here are your favorite games:\n";
  for(int i = 0; i < favGames.size(); i++) {
    cout << favGames[i] << "\n";
  }

sort(favGames.begin(), favGames.end());
cout << "Here are our sorted games!\n";
    for(int i = 0; i < favGames.size(); i++) {
      cout << favGames[i] << "\n";
    }
}

//end
void EndProgram(const vector<string>& games){
cout << "Would you like to save your list(press 1) or erase(press 2)?\n";
ofstream writeFile("favGames.txt");
string answer;
getline(cin, answer);
if(answer == "1") {
    if(writeFile.is_open()) {
    for(int i = 0; i < favGames.size(); i++) {
      writeFile << favGames[i] << "\n";
    }
  }
  writeFile.close();
  cout << "Successfully saved to file!\n";
    cout << "It was nice learning about your favorite games!\n";
}

if(answer == "2"){
    favGames.clear();
    writeFile.open("favGames.txt");
    if(writeFile.is_open()) {
        writeFile << " ";
    }
    writeFile.close();
cout << "Your file has been erased!\n";
cout << "It was nice learning about your favorite games!\n";
}
}