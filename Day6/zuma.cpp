#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    list<int> beads;
    int n,k,v;cin>>n>>k>>v;
    for(int i = 0;i<n;i++){
        int c;cin>>c;
        beads.push_back(c);
    }
    auto it= beads.begin();
    advance(it,k);
    auto cur_it = beads.insert(it,v);
    while(true){
        if(beads.empty()) break;
        int color = *cur_it;
        auto st = cur_it;
        auto en = cur_it;
        while(st!=beads.begin()&&*st==*prev(st)){
            st = prev(st);
        }
        while(next(en)!=beads.end()&&*en==*next(en)){
            en = next(en);
        }
        int cnt = distance(st,en)+1;
        if(cnt>=3){
            bool at_start = (st == beads.begin());
            bool at_en = (next(en) == beads.end());
            auto right = beads.erase(st,next(en));
            if(beads.empty()) break;
            if(at_start||at_en) break;
            else{
                auto left = prev(right);
                if(*right==*left){
                    cur_it = right;
                    continue;
                }
                else break;
            }
        }
        else break;
    }
    for(auto x:beads){
        cout<<x<<" ";
    }
}