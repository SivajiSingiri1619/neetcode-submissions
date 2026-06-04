class NumMatrix {
public:
    vector<vector<int>> pref;
    NumMatrix(vector<vector<int>>& matrix) {
         int m = matrix.size() , n = matrix[0].size();
         pref.resize(m,vector<int>(n));
         pref[0][0] = matrix[0][0];
         for(int c=1;c<n;c++) pref[0][c] = pref[0][c-1] + matrix[0][c];
         for(int r=1;r<m;r++) pref[r][0] = pref[r-1][0] + matrix[r][0];

         for(int r=1;r<m;r++){
              for(int c=1;c<n;c++){
                  pref[r][c] = (pref[r-1][c] + pref[r][c-1] + matrix[r][c]) - pref[r-1][c-1];
              }
         }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
         int tot = pref[row2][col2];
          tot -= pref[row1][col1];
          
         if(row1 != 0) {
            tot -= pref[row1-1][col2];
            tot += pref[row1-1][col1];
         }


         if(col1 != 0){
             tot -= pref[row2][col1-1];
             tot += pref[row1][col1-1];
         }
         if(row1 == 0 || col1 == 0){
            if(row1 == 0 && col1 == 0) tot += pref[row1][col1];
            else if(row1 == 0) tot += (pref[row1][col1] - pref[row1][col1-1]);
            else tot += (pref[row1][col1] - pref[row1-1][col1]);
         }
         else{
               tot += ((pref[row1][col1] + pref[row1-1][col1-1]) - (pref[row1-1][col1] + pref[row1][col1-1]));
         }
         
       
         return tot;     
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */