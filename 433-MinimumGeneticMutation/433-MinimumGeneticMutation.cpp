// Last updated: 4/24/2026, 10:13:04 PM
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<pair<string,int>> q;
        q.push({startGene,0});
        unordered_set <string> st(bank.begin(),bank.end());
        st.erase(startGene);
        char choice[]={'A','C','G','T'};
        while(!q.empty()){
            string gene=q.front().first;
            int mutation=q.front().second;
            q.pop();
            if(gene==endGene){return mutation;}
            for(int i=0;i<gene.size();i++){
                char original=gene[i];
                for(int j=0;j<4;j++){
                    gene[i]=choice[j];
                    if(st.find(gene)!= st.end()){
                        st.erase(gene);
                        q.push({gene,mutation+1});
                    }
                }
                gene[i]=original;
            }
        }
        return -1;      
    }
};