# Subset Sum Problem

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given an array of positive integers  **arr[]**  and a value  **sum**, determine if there is a subset of arr[] with sum equal to given sum. 

 **Examples:** 

```
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
Output: true 
Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

```

```
Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
Output: false
Explanation: There is no subset with target sum 30.
```

```
Input: arr[] = [1, 2, 3], sum = 6
Output: true
Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
```

 **Constraints:** 
1 ≤ arr.size() ≤ 200
1 ≤ arr[i] ≤ 200
1 ≤ sum ≤ 104

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-31T15:47:27.137Z  

```cpp
class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=arr.size();
        
        vector<bool> prev(sum+1,false),curr(sum+1,false);
        
        prev[0]=true;
        curr[0]=true;
        
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                
                bool skip=prev[j];
                
                bool notSkip=false;
                if(arr[i-1]<=j){
                    notSkip=prev[j-arr[i-1]];
                }
                
                curr[j]=skip||notSkip;
            }
            prev=curr;
        }
        return prev[sum];
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1)