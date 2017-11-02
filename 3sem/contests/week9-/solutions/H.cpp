//
// Created by aleksei on 02.11.17.
//


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<vector<int>, vector<int>> dijkstra(vector < vector < pair<int,int> > > g, int s) { // Граф считывать через readGraphWithWeights
    const int INF = 1000000000;
    unsigned long n = g.size();
    vector<int> d (n, INF),  p (n);
    d[s] = 0;
    vector<char> u (n); // ????????????
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j = 0; j < g[v].size(); ++j) {
            int to = g[v][j].first, len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    return pair<vector<int>, vector<int>>(d, p);
}

vector<int> recoverPath(int finish, int start, vector<int> &parents){
    vector<int> path;
    for (int v=finish; v!=start; v=parents[v])
        path.push_back (v);
    path.push_back (start);
    reverse (path.begin(), path.end());
    return path;
}

int main() {
    unsigned long numVertex, numEdge;
    cin >> numVertex;
    cin >> numEdge;

    //int from, to;
    //cin >> from >> to;
    int from = 0;

    vector < vector < pair<int,int> > > Graph (numVertex);
    int a, b, weight;
    for (int i = 0; i < numEdge; ++i){
        cin >> a;
        cin >> b;
        //cin >> weight;
        weight = 1;
        pair<int,int> A = {b, weight};
        pair<int,int> B = {a, weight};
        Graph[a].emplace_back(A);
        Graph[b].emplace_back(B);
    }

    pair<vector<int>, vector<int>> res_paths = dijkstra(Graph, from);
    //vector<int> path = recoverPath(to, from, res_paths.second);
    vector<int> weights = res_paths.first;
    for(int i : weights) {
        cout << i << "\n";
    }
    return 0;
}