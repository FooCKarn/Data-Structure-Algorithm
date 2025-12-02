#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int f,w,n; cin>>f>>w>>n;
    vector<int> v;
    for(int i = 0;i<f;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    int cur = v[0];
    int cnt = 1;
    for(int i = 1;i<f;i++){
        if(v[i]> cur + (2*w)){
            cnt++;
            cur = v[i];
        }
    }
    cout<<cnt;

}