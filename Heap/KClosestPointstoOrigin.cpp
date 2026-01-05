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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto cmp = [](const vector<int>& a, const vector<int>& b){
            int da = a[0]*a[0] + a[1]*a[1];
            int db = b[0]*b[0] + b[1]*b[1];
            return da < db; // as this will return true when da less than db 
            //so in pq (a,b) a has less priority if the comparator returns true so lesser dist will have less priority so it will give max heap
        };

        priority_queue<vector<int>,vector<vector<int>>,decltype(cmp)> pq(cmp);
        for(auto &point : points){
            pq.push(point);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>> result ;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        return result;
    }
};