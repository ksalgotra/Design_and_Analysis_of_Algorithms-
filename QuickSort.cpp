# include<iostream>
# include<vector>
# include<algorithm>
using namespace std;

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
    vector<int> A = {45, 23, 7, 26, 56, 78};
    cout << "Unsorted Array" << endl;
    for(int val : A){
        cout << val << " ";
    }
    cout << endl;

    QuickSort(A, 0, A.size() - 1);



    cout << "Sorted Array" << endl;
    for(int val : A){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}