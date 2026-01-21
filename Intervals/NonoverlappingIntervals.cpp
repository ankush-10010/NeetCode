#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        int prevEnd = intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(start >= prevEnd){
                prevEnd = end;
            }else{
                result++;
                prevEnd = min(prevEnd,end);
            }
        }
        return result;
    }
};