# include<iostream>
# include<vector>
using namespace std;

// Merge Sort
// Time Complexity:
// Best Case:    O(n log n)
// Average Case: O(n log n)
// Worst Case:   O(n log n)
//
// Space Complexity:
// O(n) auxiliary space


// ---------- OUTPUT --------------
// Unsorted Array
// 12 11 13 5 6 7 
// Sorted Array after Merge Sort
// 5 6 7 11 12 13 
// -------------------------------------------------
// Unsorted Array
// 38 27 43 3 9 82 10 
// Sorted Array after Merge Sort
// 3 9 10 27 38 43 82 

void MergeStep(vector<int>& A, int l,int mid, int r){
    int i = l;
    int j = mid + 1;

    vector<int> temp(r - l + 1);
    int index = 0;
    while(i <= mid && j <= r){
        if(A[i] < A[j])temp[index++] = A[i++];
        else temp[index++] = A[j++];
    }
    while(i <= mid){
        temp[index++] = A[i++];
    }
    while(j <= r){
        temp[index++] = A[j++];
    }

    for(int i = 0; i <= r - l; i++){
        A[l + i] = temp[i];
    }
}

void MergeSort(vector<int>& A, int l, int r){
    if(l >= r)return;
    int mid = l + (r - l)/2;

    MergeSort(A, l, mid);
    MergeSort(A, mid + 1, r);
    MergeStep(A, l, mid, r);
    
}

int main(){
    vector<int> A = {12, 11, 13, 5, 6, 7};

    cout << "Unsorted Array" << endl;
    for(int val : A){
        cout << val << " ";
    }
    cout << endl;

    MergeSort(A, 0, A.size() - 1);



    cout << "Sorted Array after Merge Sort" << endl;
    for(int val : A){
        cout << val << " ";
    }
    cout << endl;
    
    cout << "-------------------------------------------------" << endl;

    vector<int> B = {38, 27, 43, 3, 9, 82, 10};

    cout << "Unsorted Array" << endl;
    for(int val : B){
        cout << val << " ";
    }
    cout << endl;

    MergeSort(B, 0, B.size() - 1);



    cout << "Sorted Array after Merge Sort" << endl;
    for(int val : B){
        cout << val << " ";
    }
    cout << endl;

    return 0;