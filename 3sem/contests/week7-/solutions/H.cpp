//
// Created by aleksei on 17.10.17.
//

#include <iostream>
using namespace std;

class Graf{
public:
    int n;
    int** M;

    Graf(int noV, int noE){
        n = noV;
        M = new int*[noV];
        for(int i=0; i<noV; i++){
            M[i] = new int[noV];
        }

        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                M[i][j]=0;

        int v1, v2;
        for (int i=0; i<noE; i++){
            cin >> v1 >> v2;
            M[v1][v2] = M[v2][v1] = 1;
        }
    }

    void print(){
        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                cout << M[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    void del(){
        for (int i=0; i<n; i++)
            delete[] M[i];
        delete []M;
    }
};

void goDeep(Graf& G, int v, bool* visited, int& k){
    visited[v] = 1;
    for(int i=0; i<G.n; i++){
        if(G.M[v][i]==1 && visited[i]==0)
            goDeep(G, i, visited, k);
    }
}

int main(){
    int noV, noE;
    cin >> noV >> noE;
    Graf G = Graf(noV, noE);
    bool visited[noV];
    for (int i=0; i<noV; i++)
        visited[i]=0;
    int k = 0;
    goDeep(G, 0, visited, k);
    cout << k;
    int res = 0;
    for(int j = 0; j < noV; j++) {
        if(!visited[noV-j]) res++;
    }
    if(res == 1) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    G.del();
    return 0;
}
