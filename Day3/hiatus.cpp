#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    set<int> year;
    map<int, vector<int>> mp;
    int n, m; cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int a, b; cin >> a >> b;
        mp[a].push_back(b);
        year.insert(a);
    }

    for (auto &kv : mp) {
        auto &v = kv.second;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }

    int minye = *year.begin();
    int minmo = mp[minye].front();
    int mxye  = *year.rbegin();
    int mxmo  = mp[mxye].back();

    while (m--) {
        int x, y; cin >> x >> y;

        if (x < minye || (x == minye && y < minmo)) {
            cout << "-1 -1 ";
            continue;
        }
        if (x > mxye || (x == mxye && y > mxmo)) {
            cout << mxye << " " << mxmo << " ";
            continue;
        }

        auto it_up = year.upper_bound(x); 
        if (it_up == year.begin()) {     
            cout << "-1 -1 ";
            continue;
        }
        auto it_prev = prev(it_up);      
        int k = *it_prev;

        if (k == x) {
            auto &v = mp[k];
            auto mit = upper_bound(v.begin(), v.end(), y); 
            if (mit == v.begin()) {
                if (it_prev == year.begin()) {
                    cout << "-1 -1 ";
                } else {
                    int pk = *prev(it_prev);
                    cout << pk << " " << mp[pk].back() << " ";
                }
            } else {
                int prevm = *prev(mit);  
                if (prevm == y) {
                    cout << "0 0 ";
                } else {
                    cout << k << " " << prevm << " ";
                }
            }
        } else {
            cout << k << " " << mp[k].back() << " ";
        }
    }
    return 0;
}
