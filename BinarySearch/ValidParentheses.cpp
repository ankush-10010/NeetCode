#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> str;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(ch=='(' || ch=='{' || ch=='['){
                str.push(ch);
            }else{
                if(str.empty()){
                    return false;
                }
                if((ch==')' && str.top()=='(') ||
                    (ch=='}' && str.top()=='{') ||
                    (ch==']' && str.top()=='[')){
                        str.pop();
                    }
                else{
                    return false;
                }
            }
        }
        return str.empty();
    }
};
