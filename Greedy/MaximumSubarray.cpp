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
    int maxSubArray(vector<int>& nums) {
        int best = nums[0];
        int curr = nums[0];
        for(int i=1;i<nums.size();i++){
            curr = max(nums[i] + curr , nums[i]);
            best = max(curr,best);
        }
        return best;
    }
};
    