#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> vec[35]; 
int vst[1010];
int ans = INT_MAX;

void recur(int cur, int cnt, int k) {
    if (cnt == n) {
        ans = min(ans, k);
        return;
    }
    
    if (cur == m || k >= ans) {
        return;
    }
    for (int x : vec[cur]) {
        if (vst[x] == 0) {
            cnt++;
        }
        vst[x]++; 
    }
    

    recur(cur + 1, cnt , k + 1);


    for (int x : vec[cur]) {
        vst[x]--;
        if (vst[x] == 0) {
            cnt--;
        }
    }

   
    recur(cur + 1, cnt, k);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n >> m;
    
    
    for (int i = 0; i < m; i++) {
        int k; cin >> k;
        while (k--) {
            int d; cin >> d;
            vec[i].push_back(d);
        }
    }
    
    
    recur(0, 0, 0);
    
    cout << ans;
}