#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

string symbols[] = {"Cherry", "Lemon", "Bell", "Seven", "Bar"};

string getRandomSymbol() {
    int index = rand() % 5;
    return symbols[index];
}


void spinReels(string &s1, string &s2, string &s3) {
    s1 = getRandomSymbol();
    s2 = getRandomSymbol();
    s3 = getRandomSymbol();
    cout << "\n" << s1 << " | " << s2 << " | " << s3 << endl;
}


int calculateWinnings(string s1, string s2, string s3) {
    if (s1 == s2 && s2 == s3) {
        cout << "JACKPOT! You win 50 coins!" << endl;
        return 50;
    } else if (s1 == s2 || s1 == s3 || s2 == s3) {
        cout << "Nice! You win 20 coins!" << endl;
        return 20;
    } else {
        cout << "No match. You lose." << endl;
        return 0;
    }
}

int main() 
{
    srand(time(0)); 
    int coins = 100;
    char choice;

    cout << "Welcome to SPIN THE WHEEL !" << endl;
    cout << "You start with 100 coins. Each spin costs 10 coins." << endl;

    do {
        if (coins < 10) {
            cout << "\n Not enough coins to spin! Game over!" << endl;
            break;
        }

        cout << "\nPress 's' to spin or 'q' to quit: ";
        cin >> choice;

        if (choice == 's' || choice == 'S') 
        {
            coins -= 10; 

            string s1, s2, s3;
            spinReels(s1, s2, s3);
            int win = calculateWinnings(s1, s2, s3);
            coins += win;

            cout << "Coins left: " << coins << endl;
        } 
        
        else if (choice == 'q' || choice == 'Q') 
        {
            cout << "Thanks for playing! You ended with " << coins << " coins.\n";
            break;
        }

        else 
        {
            cout << "Invalid input. Please press 's' to spin or 'q' to quit." << endl;
        }

    } while (true);

    return 0;
}
