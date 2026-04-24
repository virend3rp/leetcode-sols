// Last updated: 4/24/2026, 10:11:31 PM
class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int>mp;
        for(auto x:cpdomains){
            int i=x.find(" ");
            int n=stoi(x.substr(0,i));
            string str=x.substr(i+1);
            for(int i=0;i<str.size();i++){
                if(str[i]=='.') mp[str.substr(i+1)]+=n;
            }
            mp[str]+=n;
        }
        vector<string>ans;
        for(auto x:mp){
            ans.push_back(to_string(x.second)+" "+x.first);
        }
        return ans;
    }
};