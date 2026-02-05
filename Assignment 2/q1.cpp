/*You are given N activities, each having a start time and a finish time. A single person (or machine) can perform only
one activity at a time. Two activities are said to be compatible if the start time of one activity is greater than or equal
to the finish time of the other activity. Write a program using greedy strategy to select the maximum number of non-
overlapping activities that can be performed by the person.*/

/*Input:
N = 6
start = [1, 3, 0, 5, 8, 5]
finish = [2, 4, 6, 7, 9, 9]
Output:
Maximum number of activities = 4
Selected activities: (1, 2), (3, 4), (5, 7), (8, 9)*/

#include <iostream>
#include <vector>
#include <algorithm> // Required for sort

using namespace std;

void solveActivitySelection(vector<int> start, vector<int> finish) {
    int n = start.size();
    
    // Store as pair<finish, start> to utilize default sorting by first element (finish time)
    vector<pair<int, int>> activities;
    for (int i = 0; i < n; i++) {
        activities.push_back({finish[i], start[i]});
    }

    // Sort by finish time
    sort(activities.begin(), activities.end());

    vector<pair<int, int>> selected;
    

    selected.push_back({activities[0].second, activities[0].first});
    int lastFinished = activities[0].first;

    for(int i = 1; i < n; i++) {
        // If current activity start time >= last selected activity finish time
        if(activities[i].second >= lastFinished) {
            selected.push_back({activities[i].second, activities[i].first});
            lastFinished = activities[i].first;
        }
    }


    cout << "Maximum number of activities = " << selected.size() << endl;
    cout << "Selected activities: ";
    for (size_t i = 0; i < selected.size(); i++) {
        cout << "(" << selected[i].first << ", " << selected[i].second << ")";
        if (i != selected.size() - 1) cout << ", ";
    }
    cout << endl;
}

int main() {
    vector<int> st = {1, 3, 0, 5, 8, 5};
    vector<int> fi = {2, 4, 6, 7, 9, 9};
    solveActivitySelection(st, fi);
    return 0;
}
