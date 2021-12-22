#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

#if 0
class Solution {
public:
    unordered_set<int> whiteset;
    unordered_set<int> grayset;
    unordered_set<int> blackset;

    bool result;

    void dfs(int s, vector<int> adj[])
    {
        // is s exist in whiteset?
        auto it = whiteset.find(s);
        if (it != whiteset.end())
        {
            int elem = *it;
            grayset.insert(elem);
            whiteset.erase(elem);
            // you are checking for all neighbours
            for (int i = 0; i < adj[elem].size(); ++i)
            {
                dfs(adj[elem][i], adj);
            }

            blackset.insert(elem);
            grayset.erase(elem);
        }

        it = grayset.find(s);
        if (it != grayset.end())
        {
            result = true;
            return;
        }
    }

    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // populate whiteset with all the vertex
        for (int i = 0; i < V; ++i)
            whiteset.insert(i);

        result = false;

        while (whiteset.empty() == false)
        { // repeat until your whiteset becomes empty
            auto it = whiteset.begin();
            dfs(*it, adj);
            if (result)
                return true;
        }
        return result;
    }
};

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[10001];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

#endif // 0

