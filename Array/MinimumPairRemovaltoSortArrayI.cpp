#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;
class Solution {
public:
    bool isnonDecreasing(vector<int>& nums){
        for(int i=1;i<nums.size();i++){
            if(nums[i-1] > nums[i]){
                return false;
            }
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(),sortedNums.end());
        if(sortedNums == nums){
            return 0;
        }
        
        
        int count = 0;
        while(!isnonDecreasing(nums)){
            int minSum = INT_MAX;
            int nx = -1;
            int ny = -1;
            for(int i=0;i<nums.size()-1;i++){
                int currSum = nums[i] + nums[i+1];
                if(currSum < minSum){
                    minSum = min(minSum,currSum);
                    nx = i;
                    ny = i+1;
                }
            }
            nums[nx] = minSum;
            nums.erase(nums.begin() + ny);
            count++;
        }
        return count;
    }
};