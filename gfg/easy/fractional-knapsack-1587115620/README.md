# Fractional Knapsack

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

Given two arrays,  **val[]** and  **wt[]** , representing the values and weights of items, and an integer capacity representing the maximum weight a knapsack can hold, determine the maximum total value that can be achieved by putting items in the knapsack. You are allowed to break items into fractions if necessary.
Return the maximum value as a double, rounded to 6 decimal places.

 **Examples :** 

```
Input: val[] = [60, 100, 120], wt[] = [10, 20, 30], capacity = 50
Output: 240.000000
Explanation: By taking items of weight 10 and 20 kg and 2/3 fraction of 30 kg. Hence total price will be 60+100+(2/3)(120) = 240

```

```
Input: val[] = [500], wt[] = [30], capacity = 10
Output: 166.670000
Explanation: Since the item’s weight exceeds capacity, we take a fraction 10/30 
```

 **Constraints:** 
1 ≤ val.size = wt.size ≤ 105
1 ≤ capacity ≤ 109
1 ≤ val[i], wt[i] ≤ 104

## Solution

**Language:** C++  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-08-30T15:44:09.791Z  

```cpp
class Solution {
    //Time: O(nlogn)for sorting
    
    //Space: 0(2N)
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n=val.size();
        
        vector<pair<int,int>> vec(n);
        
        
        for(int i=0;i<n;i++){
            vec[i]={val[i],wt[i]};
        }
        
        
        auto lambda=[](pair<int,int>& p1,pair<int,int>& p2){
            return (1.0*p1.first)/p1.second > (1.0*p2.first)/p2.second;
        };
        
        sort(begin(vec),end(vec),lambda);
        
        double result=0.0;
        
        for(int i=0;i<n;i++){
            if(vec[i].second<=capacity){
                result+=vec[i].first;
                capacity-=vec[i].second;
            }else{
                result+=(capacity*(1.0*vec[i].first/vec[i].second));
                break;
            }
        }
        
        return result;
    }
};

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1)