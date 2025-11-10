#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> pq;
    map<string,int> mp;
    int n,m;cin>>n>>m;
    for(int i = 0;i<n;i++){
        string str;
        cin>>str;
        mp[str]++;
    }
    for(auto x:mp){
        pq.push(x.second);
    }
    int mn = INT_MAX;
    while(!pq.empty()&&m!=0){
        //cout<<pq.top()<<endl;
        mn = min(pq.top(),mn);
        pq.pop();
        m--;
    }
    cout<<mn;


}