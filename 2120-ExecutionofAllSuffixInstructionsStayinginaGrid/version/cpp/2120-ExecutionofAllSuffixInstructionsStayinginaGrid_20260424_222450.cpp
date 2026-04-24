// Last updated: 4/24/2026, 10:24:50 PM
1class Solution {
2public:
3    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
4        int m = s.size();
5        vector<int> answer(m);
6        
7        for(int i = 0; i < m; i++){
8            int row = startPos[0], col = startPos[1];
9            int count = 0;
10            for(int j = i; j < m; j++){
11                char ch = s[j];
12                if(ch == 'L') col--;
13                else if(ch == 'R') col++;
14                else if(ch == 'U') row--;
15                else row++;
16                
17                if(row < 0 || row >= n || col < 0 || col >= n) break;
18                count++;
19            }
20            answer[i] = count;
21        }
22        return answer;
23    }
24};