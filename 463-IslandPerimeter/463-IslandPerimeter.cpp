// Last updated: 4/24/2026, 10:12:50 PM
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int peri=0;
        int rows = grid.size();
        int col = grid[0].size();

        for(int i=0; i<rows; i++){
            for(int j=0; j<col; j++){
                if(grid[i][j]==1){
                    peri+=4;

                if(i>0 && grid[i-1][j]==1) peri -=2;

                if(j>0 && grid[i][j-1]==1) peri -=2;
                }
            }
        }
      return peri;
    }
};