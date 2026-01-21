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
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        bool firstRowZero = false;
        bool firstColZero = false;

        for(int j=0;j<col;j++){
            if(matrix[0][j] == 0){
                firstRowZero = true;
                break;
            }
        }

        for(int i=0;i<row;i++){
            if(matrix[i][0] == 0){
                firstColZero = true;
                break;
            }
        }

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j] == 0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(firstRowZero){
            for(int j=0;j<col;j++){
                matrix[0][j] = 0;
            }
        }
        if(firstColZero){
            for(int i=0;i<row;i++){
                matrix[i][0] = 0;
            }
        }
    }
};


class SolutionWorseSC {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        // vector<vector<bool>> isZero(row,vector<bool>(col,false));
        vector<bool> rowZero(row,false);
        vector<bool> colZero(col,false);
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j] == 0){
                    // isZero[i][j] = true; // matrix[i][] = 0, matrix[][j] = 0
                    rowZero[i]=true;
                    colZero[j]=true;
                }
            }
        }
        for(int i=0;i<col;i++){
            if(colZero[i]){
                for(int k=0;k<row;k++){
                    matrix[k][i]=0;
                }
            }
        }
        for(int i=0;i<row;i++){
            if(rowZero[i]){
                for(int k=0;k<col;k++){
                    matrix[i][k]=0;
                }
            }
        }
    }
};
