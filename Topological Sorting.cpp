#include<bits/stdc++.h>
using namespace std;

int main(){
    int nv, na;
    cin >> nv >> na;

    vector<vector<int>> adj(nv);
    vector<int> dep(nv, 0);

    for(int i = 0; i < na; i++){
        int f, t;
        cin >> f >> t;
        adj[f-1].push_back(t-1);
        dep[t-1]++;
    }

    vector<int> ordem;
    priority_queue<int, vector<int>, greater<int>> q;

    for(int i = 0; i < nv; i++) if(dep[i] == 0) q.push(i);

    while(!q.empty()){
        int curr = q.top();
        q.pop();
        ordem.push_back(curr);

        for(int to : adj[curr]){
            dep[to]--;
            if(dep[to] == 0) q.push(to);

        }
    }

    if(ordem.size() != nv){
        cout<< "Sandro fails.";
    } else{
    for(int i = 0; i < nv; i++)
    {
        cout << ordem[0]+1 << " ";
        ordem.erase(ordem.begin());
    }
    }

    return 0;
}