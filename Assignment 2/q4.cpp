/*Input:
N = 5
Jobs = [J1, J2, J3, J4, J5]
deadline = [2, 1, 2, 1, 3]
profit = [100, 19, 27, 25, 15]
Output:
Selected Jobs: [J1, J3, J5]
Maximum Profit = 142*/

#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

void AlgorithmJS(int n, vector<string> job_names, vector<int> deadline, vector<int> profit) {
    // an index array to help sort the parallel arrays
    vector<int> idx(n);
    
    for(int i = 0; i < n; i++) {
        idx[i] = i;
    }

    sort(idx.begin(), idx.end(), [&](int i, int j) {
        return profit[i] > profit[j];
    });

    vector<int> d(n + 1);
    vector<int> p(n + 1);
    vector<string> names(n + 1);

    for (int i = 0; i < n; i++) {
        d[i + 1] = deadline[idx[i]];
        p[i + 1] = profit[idx[i]];
        names[i + 1] = job_names[idx[i]];
    }

    vector<int> J(n + 1); // indices of selected jobs
    d[0] = 0;   
    J[0] = 0;   
    J[1] = 1;   // include the first job (highest profit)
    int k = 1;  // Number of jobs selected so far

    for (int i = 2; i <= n; i++) {
        int r = k;

        while ((d[J[r]] > d[i]) && (d[J[r]] != r)) {
            r = r - 1;
        }

        if ((d[J[r]] <= d[i]) && (d[i] > r)) {
            
            for (int q = k; q >= (r + 1); q--) {
                J[q + 1] = J[q];
            }
          
            J[r + 1] = i;
            k = k + 1;
        }
    }

    cout << "Selected Jobs: [";
    int totalProfit = 0;
    for (int i = 1; i <= k; i++) {
        cout << names[J[i]];
        totalProfit += p[J[i]];
        if (i < k) cout << ", ";
    }
    cout << "]" << endl;
    cout << "Maximum Profit = " << totalProfit << endl;
}

int main() {
    int N = 5;
    vector<string> jobs = {"J1", "J2", "J3", "J4", "J5"};
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit = {100, 19, 27, 25, 15};

    AlgorithmJS(N, jobs, deadline, profit);

    return 0;
}
