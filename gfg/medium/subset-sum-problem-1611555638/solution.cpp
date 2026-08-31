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