// Last updated: 4/24/2026, 10:08:58 PM
class Solution {
public:
    int kthFactor(int n, int k) {
    if(n==1){
        return 1;
    }

    vector<int>list;

    int sqroot=sqrt(n);

    for(int i=1;i<=sqroot;i++){
        if(n%i==0){
            if(i==n/i){
                list.push_back(i); 
            }
            else{
            list.push_back(i);
            list.push_back(n/i);
            }
        }

    }
    
    sort(list.begin(),list.end());
    
        if(k>list.size()){
            return -1;
        }
        else return list[k-1];

    }
};