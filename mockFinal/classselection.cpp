#include<bits/stdc++.h>
using namespace std;
int st[100001];
int en[100001];
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;cin>>n;
    int cnt = 1;
    for(int i = 0;i<n;i++) cin>>st[i];
    for(int i = 0;i<n;i++) cin>>en[i];
    vector<pair<int, int>> v(n);
    for(int i=0; i<n; i++) {
        v[i] = {en[i], st[i]}; 
    }
    sort(v.begin(),v.end());
    int fi = v[0].first;
    for(int i = 1;i<n;i++){
        if(v[i].second<fi) continue;
        else{
            cnt++;
            fi = v[i].first;
        }
    }
    cout<<cnt;
}