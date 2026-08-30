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