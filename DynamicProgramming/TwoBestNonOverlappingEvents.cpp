#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n= events.size();

        sort(events.begin(),events.end(),[](const vector<int>& a,const vector<int>& b){
            return a[1]<b[1];
        });

        vector<int> dp(n+1);
        dp[0] = 0;
        dp[1] = events[0][2];
        for(int i=2;i<n+1;i++){
            dp[i] = max(dp[i-1] , events[i-1][2]);
        }
        int ans = dp[n]; // taking only one element

        for(int i=0;i<n;i++){
            int start = events[i][0];
            int value = events[i][2];

            int l=0;
            int r=i-1;
            int best = -1;

            
            while(l <= r){
                int mid = (l+r)/2;
                if(events[mid][1] < start){
                    best = mid;
                    l = mid + 1;
                }else{
                    r = mid - 1;
                }
            }
            if(best != -1){
                ans = max(ans,value + dp[best+1]);
            }
        }
        return ans;

    }
};