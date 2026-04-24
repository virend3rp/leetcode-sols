// Last updated: 4/24/2026, 10:12:55 PM
class Solution {
public:
    string frequencySort(string s) {
        cout<<s.size()<<"\n";
        priority_queue<pair<int,char>>pq;
        map<char,int>mp;
        for(auto i : s){
            mp[i]++;
        }
        for(auto i : mp){
            pq.push({i.second,i.first});
        }
        string ans="";
        while(!pq.empty()){
            pair<int,char>atif = pq.top();
            pq.pop();
            ans.append(atif.first,atif.second);
        }

        return ans;
    }
};