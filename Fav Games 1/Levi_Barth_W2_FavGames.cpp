#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  //introduction
  cout << "Hello there, video game lover!\n";
  cout << "Video games sure are nifty, right?\n\n";
  cout << "Here's some of my favorite games\n";
  cout << "(conveniently stored in a neat little list):\n";
  cout << "1. Dragon Age: Origins\n";
  cout << "2. Fallout: New Vegas\n";
  cout << "3. Baldur's Gate 3\n\n";
  cout << "What's that? You want a neat little list too?\n";
  cout << "Well let's make it!\n\n";

  vector<string> favGames;
  char input;
  string game;
  
  do{
    cout << "What would you like to do?\n";
    cout << "Press 1 to Add a game to your neat little list\n"; 
    cout << "Press 2 to Edit a game on your neat little list\n";
    cout << "Press 3 to Delete a game from your neat little list\n";
    cout << "Press 4 to View your neat little list\n";
    cout << "Press 5 to End this conversation\n";
    cin >> input;

    //add
    if(input == '1'){
      cout << "What game would you like to add?\n";
      cin >> game;
      favGames.push_back(game);
    }

    //edit
    if(input == '2'){
      bool foundGame = false;
      while(foundGame != true) {
        cout << "What game do you wish to change?\n";
        char input;
        cin >> input;

        for(int i = 0; i < favGames.size(); i++){
          cout << "We found the game!\n";
          foundGame = true;
          cout << "What is the new game?\n";
          cin >> input;
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
    if(input == '3'){
      bool foundGame = false;
      while(foundGame != true) {
        cout << "What game do you wish to delete?\n";
        char input;
        cin >> input;

        for(int i = 0; i < favGames.size(); i++){
          cout << "We found the game!\n";
          foundGame = true;
          favGames.erase(favGames.begin() + (input - '0' - 1));
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
    if(input == '4'){
      cout << "Here's your list:\n";
      
      for(int i = 0; i < favGames.size(); i++) {
        favGames[i].insert(0, to_string(i + 1) + ". ");
        cout << favGames[i] << "\n";
      }

      sort(favGames.begin(), favGames.end());
      cout << "Here are our sorted games!\n";
      for(int i = 0; i < favGames.size(); i++) {
        cout << favGames[i] << "\n";
      }
      
    }

    //end
    if(input == '5'){
      cout << "It was nice learning about your favorite games!\n";
      break;
    }
    
  }while(true);
}