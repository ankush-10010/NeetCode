#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
using namespace std;

class TimeMap {
public:
    unordered_map<string , vector<pair<int,string>>> map;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        map[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        if(map.count(key)==0){
            return "";
        }
        string ans="";
        vector<pair<int,string>> &vec=map[key];
        int low=0;
        int high=vec.size()-1;
        while(low<=high){
            int mid=low + (high-low)/2;
            if(vec[mid].first<=timestamp){
                ans=vec[mid].second;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};