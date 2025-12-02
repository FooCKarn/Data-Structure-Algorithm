#include<bits/stdc++.h>
using namespace std;


vector<int> targets;     
bool found[20005];        
bool target_exists[20005]; 
int max_limit = 0;        
int found_count = 0;     
int total_targets = 8;    

bool visited[25]; 
vector<pair<int, int>> graph[25];


void update_max_limit() {
 
    int new_max = 0;
    for (int k : targets) {
        if (!found[k]) {
            new_max = max(new_max, k);
        }
    }
    max_limit = new_max;
}

void dfs(int u, int current_w) {
   
    if (found_count == total_targets) return; 

 
    if (target_exists[current_w]) {
        if (!found[current_w]) {
            found[current_w] = true;
            found_count++;
            
            update_max_limit(); 
        }
    }

    if (current_w > max_limit) return;

    visited[u] = true;

    for (auto& x : graph[u]) {
        int v = x.first;
        int w = x.second;
        
        if (!visited[v] && current_w + w <= max_limit) {
            dfs(v, current_w + w);
            if (found_count == total_targets) return;
        }
    }

    visited[u] = false; 
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n, m; 
    cin >> n >> m;

    for(int i = 0; i < 8; i++) {
        int k; cin >> k;
        targets.push_back(k);
        target_exists[k] = true;
    }
    
    update_max_limit(); 
    
    for(int i = 0; i < m; i++){
        int u, v, w; 
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    for(int st = 0; st < n; st++){
        dfs(st, 0);
        if (found_count == total_targets) break; 
    }
    
    for(int k : targets){
        cout << (found[k] ? "YES\n" : "NO\n");
    }
    
    return 0;
}