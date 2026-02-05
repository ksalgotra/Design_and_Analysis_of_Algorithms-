/*Q3: You are given N items, where each item has a value and a weight. You are also given a knapsack with a maximum
capacity W. Unlike the 0/1 Knapsack problem, you are allowed to take fractions of an item. Write a program to
maximize the total value in the knapsack without exceeding its capacity.*/

/*Input:
N = 3
value = [100, 60, 120]
weight = [20, 10, 40]
W = 50
Output:
Maximum value = 220*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

double fractional_knapsack(int n, vector<int> value, vector<int> weight, int capacity) {
    // store {ratio, index} pairs.
    // ratio(r) = value / weight
    vector<pair<double, int>> items;

    for (int i = 0; i < n; i++) {
        double r = (double)value[i] / weight[i];
        items.push_back({r, i});
    }


    sort(items.rbegin(), items.rend());

    double totalValue = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        int idx = items[i].second;
        
        int itemWeight = weight[idx];
        int itemValue = value[idx];

        if (currentWeight + itemWeight <= capacity) {
            currentWeight += itemWeight;
            totalValue += itemValue;
        } 
 
        else {
            int remaining = capacity - currentWeight;
            totalValue += itemValue * ((double)remaining / itemWeight);
            break; // full
        }
    }

    return totalValue;
}

int main() {
    int N = 3;
    vector<int> value = {100, 60, 120};
    vector<int> weight = {20, 10, 40};
    int W = 50;

    cout << "Maximum value = " << fractional_knapsack(N, value, weight, W) << endl;
    return 0;
}
