
/*Given the arrival and departure times of all trains reaching a railway station on the same day, write a program to
determine the minimum number of platforms required so that no train has to wait for a platform. For each train, the
arrival time is always different from its departure time, but the arrival time of one train may be equal to the departure
time of another train. At any given instant, a single platform cannot be used simultaneously for the departure of one
train and the arrival of another train; therefore, in such cases, separate platforms must be allocated.*/

/*Input:
Train = [T1, T2, T3, T4, T5]
AT = [09:00, 09:10, 09:20, 11:00, 11:20]
DT = [09:40, 12:00, 09:50, 11:30, 11:40]
Output:
Minimum number of platforms required = 3*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int min_number_of_platforms(vector<string> train, vector<int> at, vector<int> dt) {
    int n = at.size();
    sort(at.begin(), at.end()); 
    sort(dt.begin(), dt.end()); 
    

    int i = 0;
    int j = 0; 
    
    int max_platforms = 0;
    int platforms = 0;

    while (i < n && j < n) {
        
        if (at[i] <= dt[j]) { 
            platforms++;
            i++; 
        } 
        else { 
            // Train departs
            platforms--;
            j++;
        }
        max_platforms = max(platforms, max_platforms);
    }

    return max_platforms;
}

int main() {
    vector<string> train = {"T1", "T2", "T3", "T4", "T5"};
    vector<int> at = {900, 910, 920, 1100, 1120};
    vector<int> dt = {940, 1200, 950, 1130, 1140};

    cout << "Minimum number of platforms required = " << min_number_of_platforms(train, at, dt) << endl;
    return 0;
}
