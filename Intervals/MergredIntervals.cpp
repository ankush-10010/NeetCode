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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0){
            return {};
        }
        int n= intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);

        for(int i=1;i<n;i++){
            auto& lastElement = result.back();
            auto& currentElement = intervals[i];

            if(lastElement[1] >= currentElement[0]){
                lastElement[1] = max(lastElement[1],currentElement[1]);
            }else{
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};