#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution{
public:
    void dfs(int row, int col, int n, int m,vector<vector<int>>& image ,vector<vector<bool>>& vis, int newColor, int oldColor){

        vis[row][col]=true;
        image[row][col]=newColor;

        if(row-1>=0 && !vis[row-1][col] && image[row-1][col] == oldColor){
            dfs(row-1,col,n,m,image,vis,newColor,oldColor);
        }
        if(row+1<n && !vis[row+1][col] && image[row+1][col] == oldColor){
            dfs(row+1,col,n,m,image,vis,newColor,oldColor);
        }
        if(col+1<m && !vis[row][col+1] && image[row][col+1] == oldColor){
            dfs(row,col+1,n,m,image,vis,newColor,oldColor);
        }
        if(col-1<=0 && !vis[row][col-1] && image[row][col-1] == oldColor){
            dfs(row,col-1,n,m,image,vis,newColor,oldColor);
        }

        
    }
    vector<vector<int>> floodfill(vector<vector<int>>& image,int sr,int sc,int newColor){
        int n=image.size();
        int m=image[0].size();

        vector<vector<bool>> vis(n,vector<bool>(m,false));
        dfs(sr,sc,n,m,image,vis,newColor,image[sr][sc]);

        return image;
    }
};

class Solution2{
public:
    void dfs(int row, int col, int n, int m,vector<vector<int>>& image , int newColor, int oldColor){
        if(row<0 || col <0 || row>=n || col>=m || image[row][col]!=oldColor){
            return;
        }
        image[row][col]=newColor;
        dfs(row - 1, col, n, m, image, newColor, oldColor); 
        dfs(row + 1, col, n, m, image, newColor, oldColor); 
        dfs(row, col + 1, n, m, image, newColor, oldColor); 
        dfs(row, col - 1, n, m, image, newColor, oldColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr,int sc,int newColor){
        int oldColor= image[sr][sc];
        if(oldColor!=newColor){
            int n=image.size();
            int m=image[0].size();
            dfs(sr,sc,n,m,image,newColor,oldColor);
        }
        return image;
    }
};