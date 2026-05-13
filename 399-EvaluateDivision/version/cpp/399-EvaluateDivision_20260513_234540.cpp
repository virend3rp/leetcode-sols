// Last updated: 5/13/2026, 11:45:40 PM
1class Solution {
2public:
3  unordered_map<string, unordered_map<string, double>> g;
4
5  double find_path(const string& start, const string& end, unordered_set<string>& visited) {
6    if (start == end)
7        return 1.0;
8    for (auto t : g[start]) {
9      auto intermed = t.first;
10      auto val = t.second;
11      if (visited.contains(intermed))
12        continue;
13      visited.insert(start);
14      const auto r = find_path(intermed, end, visited);
15      if (r != -1.0)
16        return val * r;
17    }
18    return -1.0;
19  }
20
21  vector<double> calcEquation(vector<vector<string>>& e,
22                              vector<double>& v,
23                              vector<vector<string>>& qs) {
24    vector<double> result;
25    for (int i = 0; i < e.size(); i++) {
26      g[e[i][0]][e[i][1]] = v[i];
27      g[e[i][1]][e[i][0]] = 1 / v[i];
28    }
29
30    for (auto& q : qs) {
31      if (!g.contains(q[0]) || !g.contains(q[1])) {
32        result.push_back(-1.0);
33        continue;
34      }
35
36      unordered_set<string> visited;
37      result.push_back(find_path(q[0], q[1], visited));
38    }
39
40    return result;
41  }
42
43};