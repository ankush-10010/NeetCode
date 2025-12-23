#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
using namespace std;

int catalanRec(int n){
    if(n==0 || n==1){
        return 1;
    }

    
    int ans =0;
    for(int i=0;i<n;i++){
        ans += catalanRec(i)*catalanRec(n-i-1);
    }

    return ans;
}

int catalanMem(int n , vector<int> &dp){ //O(n^2)
    if(n==0 || n==1){
        return 1;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }
    
    int ans =0;
    for(int i=0;i<n;i++){
        ans += catalanRec(i)*catalanRec(n-i-1);
    }

    return dp[n] = ans;

}

int catalanTab(int n){
    if(n==0 || n==1){
        return 1;
    }
    vector<int> dp(n+1,0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i=2;i<n+1;i++){
        for(int j=0;j<i;i++){
            dp[i] += dp[j]*dp[i-j-1];
        }
    }
     
    return dp[n];
}

int main(){
    int n;
    
}