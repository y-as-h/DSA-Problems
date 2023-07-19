class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int il;
        if(n%2 == 0)    il = n/2;
        else    il = n/2 + 1;
        for(int i = 0; i < il; ++i){
            for(int j = i; j < n-1-i; ++j){
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n-1-j][i];
                matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
                matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
                matrix[j][n-1-i] = temp;
                // int temp = *tl; // tl == topLeft
                // *tl = *bl;      // bl == bottomLeft
                // *bl = *br;      // br == bottomRight
                // *br = *tr;      // tr == topRight
                // *tr = temp;


                //// Another Approach
                // transpose the matrix and then reverse every row
                
            }
        }
    }
};
