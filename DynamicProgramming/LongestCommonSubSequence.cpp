#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
using namespace std;

int lcsRec(string str1,string str2){
    if(str1.size() == 0 || str2.size() == 0){
        return 0;
    }
    
    int n= str1.size();
    int m= str2.size();

    if(str1[n-1] == str2[m-1]){
        return 1 + lcsRec(str1.substr(0,n-1),str2.substr(0,m-1));
    }else{
        int ans1 = lcsRec(str1.substr(0,n-1),str2);
        int ans2 = lcsRec(str2.substr(0,m-1),str1);
        return max(ans1,ans2);
    }
}

int lcsMem(int i,int j,string &text1, string &text2,vector<vector<int>>& dp){
    if(i==0 || j == 0){
        return 0;
    }

    int n= text1.size();
    int m= text2.size();
    
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    if(text1[i-1] == text2[j-1]){
        return dp[i][j] = 1 + lcsMem(i-1,j-1,text1,text2,dp);
    }else{
        return dp[i][j] = max(lcsMem(i-1 , j, text1, text2,dp),
                                lcsMem(i,j-1,text1,text2,dp));
    }
}   

int main(){
    string str1="abcdge";
    string str2="abedg";
    int n= str1.size();
    int m= str2.size();
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , -1));
    cout<<lcsMem(n,m,str1,str2,dp); //lcd abdg , 4 will be the answer
    return 0;
}