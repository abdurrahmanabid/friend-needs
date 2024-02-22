#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an item
struct Item {
    int weight;
    int value;
};

// Function to solve the knapsack problem using a greedy approach
int knapsackGreedy(const vector<Item>& items, int capacity) {
    // Sort items by their value-to-weight ratio in non-increasing order
    vector<pair<double, int>> ratios;
    for (int i = 0; i < items.size(); ++i) {
        ratios.push_back({static_cast<double>(items[i].value) / items[i].weight, i});
    }
    sort(ratios.rbegin(), ratios.rend());

    // Greedily select items based on their value-to-weight ratio
    int totalValue = 0;
    for (int i = 0; i < ratios.size(); ++i) {
        int index = ratios[i].second;
        if (items[index].weight <= capacity) {
            totalValue += items[index].value;
            capacity -= items[index].weight;
        }
    }

    return totalValue;
}

int main() {
    int numItems;
    cout << "Enter the number of items: ";
    cin >> numItems;

    // Input items' weights and values
    vector<Item> items(numItems);
    cout << "Enter the weights and values of each item:\n";
    for (int i = 0; i < numItems; ++i) {
        cout << "Item " << i + 1 << " weight: ";
        cin >> items[i].weight;
        cout << "Item " << i + 1 << " value: ";
        cin >> items[i].value;
    }

    int capacity;
    cout << "Enter the knapsack capacity: ";
    cin >> capacity;

    // Solve the knapsack problem using the greedy approach
    int maxValue = knapsackGreedy(items, capacity);

    // Output the maximum value that can be obtained
    cout << "Maximum value that can be obtained: " << maxValue << endl;

    return 0;
}
