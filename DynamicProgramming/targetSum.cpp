#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
using namespace std;

int targetSum(vector<int> &nums , int target){
    int n= nums.size();
    vector<vector<int>> dp(n+1 , vector<int>(target+1,0)) ;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<target+1;j++){
            if(nums[i-1] <= j){
                dp[i][j] = max((nums[i-1] + dp[i-1][j-nums[i-1]]) , (dp[i-1][j]));
            }else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    //for printing the tabulation
    for(int i=0;i<n+1;i++){
        for(int j=0;j<target+1;j++){
            cout<<dp[i][j]<<"\t";
        }
        cout<<endl;
    }
    return dp[n][target]==target;
}


int main(){
    vector<int> nums = {4, 2, 7, 1, 3};
    int target = 10;

    cout<<targetSum(nums,target) << endl;

}