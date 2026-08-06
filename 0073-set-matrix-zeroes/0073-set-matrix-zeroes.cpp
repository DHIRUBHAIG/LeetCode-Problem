class Solution {
public:
void markrow(int j,vector<vector<int>>&matrix){
    for(int i=0;i<matrix[0].size();i++){
        if(matrix[j][i]!=0){
            matrix[j][i]=-11;

        }
        
    }
}
void markcol(int j,vector<vector<int>>&matrix){
    for(int i=0;i<matrix.size();i++){
        if(matrix[i][j]!=0){
             matrix[i][j]=-11;

        }
       
    }
}
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    markcol(j,matrix);
                    markrow(i,matrix);
                }
            }
        }

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0 || matrix[i][j]==-11){
                    matrix[i][j]=0;
                }
            }
        }


      }
};