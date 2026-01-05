#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;

class MedianFinder {
    priority_queue<int> left; // max heap
    priority_queue<int, vector<int>, greater<int>> right; // min heap

public:
    MedianFinder() {}

    void addNum(int num) {
        // Step 1: insert into correct heap
        if (left.empty() || num <= left.top()) {
            left.push(num);
        } else {
            right.push(num);
        }

        // Step 2: rebalance
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        } else if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {
        if (left.size() == right.size()) {
            return (left.top() + right.top()) / 2.0;
        }
        return left.top(); // left always holds the extra element
    }
};


class MedianFindernlogn {
    priority_queue<int,vector<int>,greater<int>>pq; //min heap
public:
    MedianFindernlogn() {
        
    }
    
    void addNum(int num) {  
        pq.push(num);
    }
    
    double findMedian() {
        vector<int> result;
        while(!pq.empty()){
            result.push_back(pq.top());
            pq.pop();
        }
        int n = result.size();
        int temp1 = result[(n+1)/2 - 1];
        int temp2 = result[(n+2)/2 - 1];
        for(int r : result){
            pq.push(r);
        }
        return (temp1+temp2)/2.0;
    }
};
