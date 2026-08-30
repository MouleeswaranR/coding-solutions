# 0 - 1 Knapsack Problem

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given two arrays,  **val[]**  and  **wt[]**, where each element represents the value and weight of an item respectively, and an integer  **W**  representing the maximum capacity of the knapsack (the total weight it can hold).

Put the items into the knapsack such that the total value obtained is maximum without exceeding the capacity W.

 **Note:** You can either include an item completely or exclude it entirely — fractional selection of items is not allowed. Each item is available only once.

 **Examples :** 

```
Input: W = 4, val[] = [1, 2, 3], wt[] = [4, 5, 1]
Output: 3
Explanation: Choose the last item, which weighs 1 unit and has a value of 3.
```

```
Input: W = 3, val[] = [1, 2, 3], wt[] = [4, 5, 6] 
Output: 0
Explanation: Every item has a weight exceeding the knapsack's capacity (3).
```

```
Input: W = 5, val[] = [10, 40, 30, 50], wt[] = [5, 4, 2, 3] 
Output: 80
Explanation: Choose the third item (value 30, weight 2) and the last item (value 50, weight 3) for a total value of 80.
```

 **Constraints:** 
1 ≤ val.size() = wt.size() ≤ 103
1 ≤ W ≤ 103
1 ≤ val[i] ≤ 103
1 ≤ wt[i] ≤ 103

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-30T16:17:37.867Z  

```cpp
class Solution {
  public:
  int n;
  int memo[1001][1001];
  
  public:
    int solve(int index,vector<int>& val,vector<int>& wt,int weight){
        if(index>=n||weight==0)return 0;
        
        if(memo[index][weight]!=-1)return memo[index][weight];
        int take=0,not_take=0;
        
        if(wt[index]<=weight){
            take=val[index]+solve(index+1,val,wt,weight-wt[index]);
        }
        not_take=solve(index+1,val,wt,weight);
        
        return memo[index][weight]=max(take,not_take);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        n=val.size();
        memset(memo,-1,sizeof(memo));
       return solve(0,val,wt,W);
        
    }
};
```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1)