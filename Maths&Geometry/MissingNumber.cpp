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
    int missingNumber(vector<int>& nums) {
        int x = nums.size();  
        for (int i = 0; i < nums.size(); i++) {
            x ^= i;
            x ^= nums[i];
        }
        return x;
    }
};


class SolutionWorseTC {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            if((nums[i]^(i)) != 0){
                return i;
            }
        }
        return nums.size();
    }
};
