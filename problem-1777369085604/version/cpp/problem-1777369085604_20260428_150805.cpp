// Last updated: 4/28/2026, 3:08:05 PM
1class Solution {
2public:
3    void reverseArray(vector<int>& row){
4        int start=0;
5        int end=row.size()-1;
6        while(start<end){
7            swap(row[start],row[end]);
8            start++;
9            end--;
10        }
11    }
12    void invertArray(vector<int>& row){
13        for(int i=0;i<row.size();i++){
14            row[i]=!row[i];
15        }
16    }
17    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
18        for(int i=0;i<image.size();i++){
19            reverseArray(image[i]);
20            invertArray(image[i]);
21        }
22        return image;
23    }
24};