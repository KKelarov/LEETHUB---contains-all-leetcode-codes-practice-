class Solution {
public:
    int solve(vector<vector<int>>& obstacleGrid,int& m,int& n,int i,int j,vector<vector<int>>&v)
    {
        if(i==m-1 and j==n-1)
            return 1;
        if(i>m-1 || j>n-1)
            return 0;
        if(obstacleGrid[i][j]==1)
            return 0;
        if(v[i][j]!=-1)
            return v[i][j];
        return v[i][j]=solve(obstacleGrid,m,n,i+1,j,v)+solve(obstacleGrid,m,n,i,j+1,v);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<long long int>>v(m+1,vector<long long int>(n+1,0));
        if(obstacleGrid[m-1][n-1]==1 || obstacleGrid[0][0]==1)
            return 0;
        v[m-1][n-1]=1;
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(i==m-1 and j==n-1)
                    continue;
                if(obstacleGrid[i][j]==0)
                    v[i][j]=v[i+1][j]+v[i][j+1];
            }
        }
        return v[0][0];
    }
};