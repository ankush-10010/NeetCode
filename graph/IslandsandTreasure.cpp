#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int rows= grid.size();
        int cols=grid[0].size();

        queue<pair<int,int>> q;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto [x,y]= q.front();
            vector<pair<int,int>> paths;
            paths.push_back({x+1,y}); 
            paths.push_back({x-1,y}); 
            paths.push_back({x,y+1}); 
            paths.push_back({x,y-1}); 
            q.pop();
            for(auto path : paths){
                int nx=path.first;
                int ny=path.second;
                if(nx<0 || ny<0 || nx>= rows || ny>= cols){
                    continue;
                }
                if((grid[nx][ny]) != INT_MAX){
                    continue;
                }
                grid[nx][ny]=grid[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
};
