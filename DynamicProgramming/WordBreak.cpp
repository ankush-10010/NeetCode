#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_set>
#include<queue>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(),wordDict.end());
        int n = s.size();
        vector<bool>dp(n+1,false);
        dp[0] = true;
        for(int i=1;i<n+1;i++){
            for(int j=0;j<i;j++){
                if(dp[j] == true && dict.count(s.substr(j,i-j))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};