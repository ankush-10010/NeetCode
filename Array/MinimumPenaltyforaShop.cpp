#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;
class SolutionBetter {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;
        for(char c : customers){
            if(c == 'Y'){
                penalty++;
            }
        }

        //now we have penalty for the 0th index
        int minPenalty = INT_MAX;
        minPenalty = min(minPenalty , penalty);
        int ans = 0;
        for(int i=0 ; i<customers.size() ; i++){
            if(customers[i] == 'Y'){
                penalty --;
            }else{
                penalty++;
            }

            if(penalty < minPenalty){
                minPenalty = min(minPenalty , penalty);
                ans = i+1;
            }
        }
        return ans;
    }
};


class Solution {
public:
    int bestClosingTime(string customers) {
        if(customers.size()==0){
            return 0;
        }

        int n = customers.size();

        vector<int> hours(n+1,0);
        for(int i=0;i<n+1;i++){
            for(int j=0;j<n;j++){
                if(j>=i){
                    if(customers[j] == 'Y'){
                        hours[i] += 1;
                    }
                }else{
                    if(customers[j] == 'N'){
                        hours[i] += 1;
                    }
                }
                
            }
        }
        // we have the hours matrix , now we have to find the smallest
        // index for closing with minn penalty

        // one thing we can do is to sort then find the first element using for loop
        int ans = 0;
        vector<int> hours_sort = hours;
        sort(hours_sort.begin(),hours_sort.end());
        for(int i=0;i<hours.size();i++){
            if(hours[i] == hours_sort[0]){
                ans = i;
                break;
            }
        }
        return ans;
    }
}; //this is O(n^2) , not a very good TC , wont get accepted at LC



