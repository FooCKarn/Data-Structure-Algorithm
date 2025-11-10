#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,a; cin>>n>>a;
    vector<int> v;
    queue<int> q;
    q.push(a);
    while(!q.empty()){
        int k = q.front(); q.pop();
        v.push_back(k);
        int l = 2*k+1;
        int r = 2*k+2;
        if(l<n){
            q.push(l);
        }
        if(r<n){
            q.push(r);
        }
    }
    cout<<v.size()<<endl;
    for(auto x:v) cout<<x<<" ";
}