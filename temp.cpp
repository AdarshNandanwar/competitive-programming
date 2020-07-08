#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

ll n;

void solve(){
    n =5;
    map<int, list<int>::iterator> m;
    list<int> ll;
    for(int i=1; i<=n; i++){
        ll.push_front(i);
        m[i] = ll.begin();
    }

    for(auto i:ll){
        cout<<i<<" ";
    } cout<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<*(i.second)<<endl;
    }

    cout<<endl;

    auto it = ll.begin();
    it = next(it);
    ll.insert(it, 6);
    m[6] = prev(it);

    for(auto i:ll){
        cout<<i<<" ";
    } cout<<endl;

    for(auto i:m){
        cout<<i.first<<" "<<*(i.second)<<endl;
    }

    cout<<endl;

}
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t=1;
    while(t--){
        solve();
    }
    return 0;
}