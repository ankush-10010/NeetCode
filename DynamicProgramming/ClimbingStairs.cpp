#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
using namespace std;

class Solution{
public:
    int climbStairsRec(int n){
        if(n==0 || n==1){
            return 1;
        }

        return climbStairsRec(n-1) + climbStairsRec(n-2);
    }

    int climbStairsHelperMemo(int n , vector<int>& dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n]=climbStairsHelperMemo(n-1,dp) + climbStairsHelperMemo(n-2,dp);
        return dp[n];
    }
    int climbStairsMemo(int n){
        vector<int> dp(n+1,-1);
        return climbStairsHelperMemo(n,dp);
    }

    int countWaysTab(int n){
        vector<int> dp(n+1,0);
        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=n;i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};