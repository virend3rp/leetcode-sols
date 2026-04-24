// Last updated: 4/24/2026, 10:05:02 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int xr=0, n=grid.size(),ctr=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                xr = xr ^ grid[i][j] ^ ctr;
                ctr++;
            }
        }
        cout<<xr<<endl;
        int b=0;
        while(true){
            if((xr>>b & 1)==1) break;
            else b++;
        }
        cout<<b<<endl;
        int x1=0, x2=0;
        ctr=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if((grid[i][j]>>b & 1)==1) x1 = x1 ^ grid[i][j];
                else x2 = x2^grid[i][j];

                if((ctr>>b & 1)==1) x1 = x1 ^ ctr;
                else x2 = x2^ctr;
                ctr++;
            }
        }
        int c1=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==x1) c1++;
            }
        }
        if(c1==2) return {x1,x2};
        else return {x2,x1};
    }
};