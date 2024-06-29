#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(NULL));
    
    cout << "You are a young adventurer\n";
    cout << "seeking riches and fame far beyond\n";
    cout << "what your small village could provide.\n\n"; 
    cout << "You have heard rumors of a mysterious monster\n";
    cout << "that lives in the forest outside your village.\n\n"; 
    cout << "After days of traveling,\n";
    cout << "you have found the monster's lair\n";
    cout << "and stand before him.\n";
    cout << "You can see his large pile\n";
    cout << "of gold across the room.\n\n";

    char answerYN = 'y';

    int health = 30;
    int gold = 0;

while(health > 0) {
    cout << "Do you wish to attack the monster?\n";
    cout << "Y or N?\n";
    cin >> answerYN;

if(answerYN == 'y') {
    cout << "\nYou attack the monster\n";
    cout << "with a mighty swing of your sword!\n\n";

    int playerAttack = rand() % 6 + 1;
    int monsterAttack = rand() % 6 + 1;
    
    if(playerAttack > monsterAttack) {
    cout << "The monster falls to the ground\n";
    cout << "and you are able to swipe some gold!\n";

    gold += rand () % 6 + 1;
    
    cout << "You've got "<<gold<<" gold!\n\n";
    }

    if(monsterAttack >= playerAttack) {
    cout << "Unfortunately, the monster\n";
    cout << "gets the better of you.\n";
    cout << "You take damage.\n";

    health -= rand () % 6 + 1;
    
    cout << "You have "<<health<<" health points remaining.\n\n";
    }

    if(health <= 0){
    cout<< "You fought valiantly, but to no avail.\n";
    cout << "Your village will find you body\n";
    cout << "along with your "<<gold<<" gold.\n";

    return 0;
    
}else if(answerYN == 'n'){
   if(health > 0) {
    cout << "You return home to your village\n";
    cout << "with a grand story to tell!\n\n";

    if(gold == 0 && health == 30) {
        cout << "You are a coward,\n";
        cout << "but maybe if was for the best.\n";

        return 0;
    }
       
    if(gold > 0 && health < 30) {
        cout << "You're a little worse for wear,\n";
        cout << "but at least you made some riches!\n";
        cout << "You have "<<gold<<" gold!\n";

        return 0;
    }

    if(gold == 0 && health < 30) {
        cout << "You are injured,\n";
        cout << "with little good coming from your adventure.\n";

        return 0;
    }

    if(gold > 0 && health == 30) {
        cout << "You're pockets are a little heavier now.\n";
        cout << "You have "<<gold<<" gold!\n";

        return 0;
    }
       
}
}
}
}
}