#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,m,start;cin>>n>>m>>start;
    const int mxD = 100010;
    vector<pair<int,int>> change(n);
    vector<int> store(mxD);
    for(int i = 0;i<n;i++){
        cin>>change[i].first>>change[i].second;
    }
    sort(change.begin(),change.end());
    store[0] = start;
    int cur = 0;
    for(int i = 1;i<mxD;i++){
        if(cur<n&&i==change[cur].first){
            start = change[cur].second;
            cur++;
        }
        store[i] = start + store[i-1];
    }
    while(m--){
        int P,x;
        cin>>P>>x;
        auto T1 = lower_bound(store.begin(),store.end(),P) - store.begin();
        if(T1<=x){
            cout<<T1<<' ';
            continue;
        }
        P+=store[x];
        auto T2 = lower_bound(store.begin()+x+1,store.end(),P) - store.begin();
        cout<<T2<<' ';

    }
}