# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

// Time Complexity (Quick Sort):
// Best Case:    O(n log n)
// Average Case: O(n log n)
// Worst Case:   O(n^2)
//
// Space Complexity:
// Best/Average Case: O(log n)  // recursion stack
// Worst Case:        O(n)


// ---------- OUTPUT --------------
// Unsorted Array
// 4 2 6 9 2 
// Sorted Array after Quick Sort
// 2 2 4 6 9 

int Partition(vector<int>& A, int p, int r){
    int x = A[r];

    int i = p - 1;

    for(int j = i + 1; j < r; j++){
        if(A[j] <= x){
            i = i + 1;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);
    return i + 1;
}

void QuickSort(vector<int>& A, int l, int r){
    
    if(l < r){
    int q = Partition(A, l, r);

    QuickSort(A, l, q - 1);
    QuickSort(A, q + 1, r);
    }
}
int main(){
    vector<int> A = { 4, 2, 6, 9, 2 };
    cout << "Unsorted Array" << endl;
    for(int val : A){
        cout << val << " ";
    }
    cout << endl;

    QuickSort(A, 0, A.size() - 1);



    cout << "Sorted Array after Quick Sort" << endl;
    for(int val : A){
        cout << val << " ";
    }
    cout << endl;

    return 0;