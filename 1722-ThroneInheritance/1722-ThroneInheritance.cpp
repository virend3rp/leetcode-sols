// Last updated: 4/24/2026, 10:08:38 PM
class ThroneInheritance {
private:
    unordered_map<string, vector<string>> kingdom; // adjacency list
    unordered_set<string> dead;
    string king;

public:
    ThroneInheritance(string kingName) {
        king = kingName;
    }
    
    void birth(string parentName, string childName) {
        kingdom[parentName].push_back(childName);
    }
    
    void death(string name) {
        dead.insert(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> order;
        dfs(king, order);
        return order;
    }

private:
    void dfs(const string& name, vector<string>& order) {
        if (dead.find(name) == dead.end()) {
            order.push_back(name);
        }
        for (const string& child : kingdom[name]) {
            dfs(child, order);
        }
    }
};
