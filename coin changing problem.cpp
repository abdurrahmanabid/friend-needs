#include <iostream>

using namespace std;

int main() {
    int amount;
    cout << "Enter the amount in tk: ";
    cin >> amount;

    int numCoins = 0;
    int coinsUsed[3] = {0}; // Array to store the quantities of each coin used

    // Start with the highest denomination coin (5 tk)
    coinsUsed[0] = amount / 5;
    numCoins += coinsUsed[0];
    amount %= 5;

    // Use the next highest denomination coin (2 tk)
    coinsUsed[1] = amount / 2;
    numCoins += coinsUsed[1];
    amount %= 2;

    // Use the lowest denomination coin (1 tk)
    coinsUsed[2] = amount;
    numCoins += coinsUsed[2];

    cout << "Minimum number of coins needed: " << numCoins << endl;

    // Output the quantities of each coin used
    cout << "Coins used:\n";
    cout << "5 tk coins: " << coinsUsed[0] << endl;
    cout << "2 tk coins: " << coinsUsed[1] << endl;
    cout << "1 tk coins: " << coinsUsed[2] << endl;

    return 0;
}
