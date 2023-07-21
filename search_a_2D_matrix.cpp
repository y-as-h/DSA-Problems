class Solution {
bool matrixSearch(vector<vector<int>>& matrix, int target){
    int L = 0;
    int R = matrix[0].size()-1;
    int U = 0;
    int B = matrix.size()-1;
    
    while(L <= R && U <= B){
        int rMID = L + (R - L)/2;
        int cMID = U + (B - U)/2;

        if(matrix[cMID][rMID] == target){
            return true;
        }
        if(target <= matrix[cMID][R] && target >= matrix[cMID][L]){
            if(matrix[cMID][rMID] > target){
                R = rMID-1;
            }
            else{
                L = rMID+1;
            }
        }
        else if(target > matrix[cMID][R]){
            U = cMID+1;
        }
        else{
            B = cMID-1;
        }
    }

    return false;
}
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return matrixSearch(matrix, target);
    }
};

////Another Approach
// start from top right corner and check for the target value
// if the value of matrix is less than target -> move down
// else if the value of matrix is greater than target -> move left
