class NumMatrix {
    vector<vector<int>>* row;
    vector<vector<int>>* dp;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        row = new vector<vector<int>>(r,vector<int>(c));
        dp = new vector<vector<int>>(r,vector<int>(c));
        for(int i=0; i<r; i++)
        {
            int sum = 0;
            for(int j=0; j<c; j++)
            {
                sum += matrix[i][j];
                (*row)[i][j] = sum;
            }
        }
        for(int j=0; j<c; j++)
        {
            int sum = 0;
            for(int i=0; i<r; i++)
            {
                sum += (*row)[i][j];
                (*dp)[i][j] = sum;
            }
        }
        // for(int i=0; i<r; i++)
        // (*row)[i].clear();
        // delete[] row;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int a1=0, a2=0, a3=0, a4=0;
        a1 = (*dp)[row2][col2];
        if(row1>0&&col1>0)
        a2 = (*dp)[row1-1][col1-1];
        if(col1>0)
        a3 = (*dp)[row2][col1-1];
        if(row1>0)
        a4 = (*dp)[row1-1][col2];
        return a1 + a2 - a3 - a4;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */