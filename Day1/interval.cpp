#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio();
    cin.tie(0);
    int n,m,k;cin>>n>>m>>k;
    vector<int> v;
    for(int i = 0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    while(m--){
        int t;cin>>t;
        auto it_st = lower_bound(v.begin(),v.end(),t-k) ;
        auto it_en = upper_bound(v.begin(),v.end(),t+k) ;
        cout<< distance(it_st,it_en)<<" ";
    }
}