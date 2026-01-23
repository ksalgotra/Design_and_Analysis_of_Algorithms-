# include<iostream>
using namespace std;


// MAXIMUM SUBARRAY SUM
// Time Complexity:
// Best Case:    O(n log n)
// Average Case: O(n log n)
// Worst Case:   O(n log n)
//
// Space Complexity:
// O(log n)  // recursion stack

// ----------- OUTPUT ----------------
// Maximum Contiguous Subarray Sum is : 7

int MaxSubarraySum(vector<int>& A, int l, int r){
    if(l == r)return A[l];

    int maxLeftSum = 0, maxRightSum = 0;
    int Sum = 0;
    int mid = (l + r)/2;

    for(int i = mid; i >= l; i--){
        Sum += A[i];
        maxLeftSum = max(Sum, maxLeftSum);
    }
    Sum = 0;
    for(int i = mid + 1; i <= r; i++){
        Sum += A[i];
        maxRightSum = max(Sum, maxRightSum);
    }
    int CrossSum = maxLeftSum + maxRightSum; 
    int leftSum = MaxSubarraySum(A, l, mid);
    int rightSum = MaxSubarraySum(A, mid + 1, r);

    return CrossSum > leftSum ? 
                                CrossSum > rightSum ?  CrossSum : rightSum :
                                leftSum > rightSum ? leftSum : rightSum;
}

// KADANE'S ALGORITHM
// Time Complexity:
// Best Case:    O(n)
// Average Case: O(n)
// Worst Case:   O(n)
//
// Space Complexity:
// O(1)


int KadanesAlgo(vector<int>& A, int l, int r){
    int CurrSum = 0;
    int maxSum = INT_MIN;

    for(int i = l; i <= r; i++){
        CurrSum = max(A[i], CurrSum + A[i]);
        maxSum = max(CurrSum, maxSum);
    }

    return maxSum;
}

int main(){
    vector<int> A = {-2, -5, 6, -2, -3, 1, 5, -6};

    cout << "Maximum Contiguous Subarray Sum is : " << MaxSubarraySum(A, 0, A.size() - 1) << endl;
    cout << "Maximum Contiguous Subarray Sum is : " << KadanesAlgo(A, 0, A.size() - 1) << endl;
    return 0;
}