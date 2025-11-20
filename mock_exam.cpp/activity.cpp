#include<bits/stdc++.h>
using namespace std;
map<string,set<string>> events;
map<string,string> students;
stack<pair<int,pair<string,string>>> history;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;cin>>n;
    while(n--){
        string s;cin>>s;
        if(s=="UNDO"){
            if(history.empty()) continue;
            int idx = history.top().first;
            string tmp_e = history.top().second.first;
            string tmp_n = history.top().second.second;
            if(idx == 0) history.pop();
            if(idx == 1){
                events[tmp_e].erase(tmp_n);
                students.erase(tmp_n);
                history.pop();
            }
            if(idx == 2){
                events[tmp_e].insert(tmp_n);
                students[tmp_n] = tmp_e;
                history.pop();
            }
         }
        else{
            string e;cin>>e;
            if(s=="ADDEVENT"){
                if(events.find(e)==events.end()){
                    events[e] = set<string>();
                }
            }
            else if(s=="REGISTER"){
                string name; cin>>name;
                if (events.find(e) == events.end()) {
                events[e] = set<string>();
                }
                if(students.find(name)==students.end()){
                    events[e].insert(name);
                    students[name] = e;

                    history.push({1,{e,name}});
                }
                else{
                    history.push({0,{e,name}});
                }
            }
            else if(s=="CANCEL"){
                string name;cin>>name;
                if(events.find(e) != events.end()&&students.find(name)!=students.end()){
                    if(students[name]==e){
                        events[e].erase(name);
                        students.erase(name);
                        history.push({2,{e,name}});
                    }
                    else{
                        history.push({0,{e,name}});
                    }
                }
                else{
                        history.push({0,{e,name}});
                }
            }
            else if(s=="SHOW"){
                auto it = events.find(e);
                if(it==events.end()||it->second.empty()) cout<<"\n";
                else{
                    for(auto x:events[e]){
                        cout<<x<<" ";
                    }
                    cout<<"\n";
                    }
                }
            }
        }
}
