#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

class SolutionN {
public:
    int findMin(vector<int> &nums) {
        int start=0;
        int cut;
        int end=nums.size()-1;
        int min_num=INT_MAX;
        for(int i=end;i>=0;i--){
            if(nums[i]>min_num){
                cut=i;
            }
            if(nums[i]<min_num){
                min_num=min(min_num,nums[i]);
            }
        }
        int ans;
        ans=min(nums[start], min_num);
        return ans;
    }
};


class SolutionlogN {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } 
            else {
                high = mid;
            }
        }

        return nums[low];
    }
};
