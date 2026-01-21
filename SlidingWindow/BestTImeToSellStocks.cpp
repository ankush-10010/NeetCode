#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
#include<queue>
#include<string>
using namespace std;


class Solution { //O(N)
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices){
            minPrice = min(price,minPrice); // this will give us the minimum price that we can buy the stocks for 
            maxProfit = max(maxProfit,price-minPrice);
        }

        return maxProfit;
    }
};


class SolutionWorseTC { //O(n^2)
public:
    int maxProfit(vector<int>& prices) {
        vector<int> temp2(prices.size(),0);

        int n = prices.size();
        int leftptr = 0;
        
        while(leftptr <= n-1){  
            int rightptr = n-1;
            while(leftptr<rightptr){
                if(prices[leftptr] < prices[rightptr]){
                temp2[leftptr] = max(prices[rightptr]-prices[leftptr] , temp2[leftptr]);
                }else{
                    temp2[leftptr] = max(0,temp2[leftptr]);
                }
                rightptr--;
            }
            leftptr++;
        }
        sort(temp2.begin(),temp2.end());
        return temp2[n-1];
    }
};
