// Last updated: 4/24/2026, 10:11:58 PM
class Solution {
    int dfs(int x, int y,int val,vector<vector<int>>& grid,int& m, int& n){
        if(x<0 || x>=m ||y<0 ||y>=n || grid[x][y]==0 ){
            return 0;;
        }
       grid[x][y]=0;
       int cnt=1;
        cnt+=dfs(x,y+1,val+1,grid,m,n);
        cnt+=dfs(x+1,y,val+1,grid,m,n);
        cnt+=dfs(x,y-1,val+1,grid,m,n);
        cnt+=dfs(x-1,y,val+1,grid,m,n);
        return cnt;
        
    }
public:
    int ans=0;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                  ans=max(ans,dfs(i,j,1,grid,m,n));
                }
            }
        }
        return ans;
    }
};