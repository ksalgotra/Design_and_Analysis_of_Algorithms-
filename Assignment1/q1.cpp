# include<iostream>
# include<vector>
using namespace std;

// ---------- OUTPUT --------------
// Element Found at index :5
int BinarySearch(vector<int>& A, int st, int end, int target){
    
    if(st > end)return -1;

    int mid = st + (end - st)/2;

    if(A[mid] == target)return mid;
    else if(A[mid] < target) return BinarySearch(A, mid + 1, end, target);
    else return BinarySearch(A, st, mid - 1, target);


}

int main(){
    vector<int> A = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int ans = BinarySearch(A, 0, A.size() - 1, 23);
    ans != -1 ? cout << "Element Found at index :" << ans << endl : cout << "Element not found in arr" << endl;
    return 0;
}