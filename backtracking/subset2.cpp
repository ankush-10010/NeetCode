#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    void dfs(int index,vector<int>& nums, vector<int> &current){
        result.push_back(current);

        for(int i=index;i<nums.size();i++){ 
            if(i>index && nums[i]==nums[i-1]){
                continue;
            }

            current.push_back(nums[i]);
            dfs(i+1,nums,current);
            current.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); 
        vector<int> current;
        dfs(0,nums,current);
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums= {4,4,4,1,4};
    vector<vector<int>> soln=solution.subsetsWithDup(nums);
    for(int i=0;i<soln.size();i++){
        cout<<"[";
        for(int j=0;j<soln[i].size();j++){
            cout<<soln[i][j]<<",";
        }
        cout<<"]"<<endl;
    }
    return 0;
}