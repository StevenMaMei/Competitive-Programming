#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;
typedef pair<int,int>ii;

int main(){FIN;
    int n; cin>>n;
    vector<ii> cards(n);
    fore(i,0,n){
        int a,b; cin>>a>>b;
        cards[i]={b,a};
    }
    sort(cards.begin(),cards.end(),greater<ii>());
    int turns = cards[0].ff;
    int score = cards[0].ss;
    int indx =1;
    while(turns && indx<n){
        turns--;
        score += cards[indx].ss;
        turns+= cards[indx].ff;
        indx++;
    }
    cout<<score<<"\n";
    return 0;
}
