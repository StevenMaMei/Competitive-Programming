#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;

typedef pair<int,int> ii;
typedef tuple<int,int,int> iii;

struct piece{
    vector<ii> sides;
    int points = 0;
    int pos;
};

vector<int> res2;
map<ii,vector<int>> piecesBySide;
vector<piece> pieces;
vector<bool> visited;
set<ii> externSides;
void dfs(int cp ){
    piece currPiece = pieces[cp];
    if(visited[cp]) return;
    visited[cp] = true;
    int cant = 0;
    for(auto p : currPiece.sides){
        if(externSides.count(p) >0){
            cant++;
        }
    }
    bool added = false;
    if(cant >2){
      res2.pb(cp+1);
      added = true;
    }
    for(auto p : currPiece.sides){
        externSides.insert(p);
        for(int cc : piecesBySide[p] ){
            dfs(cc);
        }
    }
    if( !added)res2.pb(cp+1);


}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
     freopen("input.txt","r",stdin);
    #else
     #define endl '\n'
    #endif // LOCAL
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        res2.clear();
        piecesBySide.clear();
        pieces.clear();
        externSides.clear();
        visited.clear();

        visited.resize(n);
        pieces.resize(n-2);
        map<ii,int> cnt;

        fore(i,0,n-2){
            vector<int> tern(3);
            vector<ii> pairs;
            cin>>tern[0]>>tern[1]>>tern[2];
            fore(j,0,3){
                fore(k,j+1,3){
                    int a = tern[j], b = tern[k];
                    if(a>b) swap(a,b);
                    piecesBySide[{a,b}].pb(i);
                    pairs.pb({a,b});
                    if(cnt.find({a,b})!= cnt.end()){
                        cnt[{a,b}]++;
                    }else{
                        cnt[{a,b}]=1;
                    }
                }
            }
            pieces[i].sides = pairs;
            pieces[i].pos = i+1;
        }
        vector<vector<int>> res1(n+1,vector<int>());
        for(auto p: cnt){
           // cout<<p.ff.ff<<" "<<p.ff.ss<<endl;;
            if(p.ss == 1) {
                res1[p.ff.ff].pb(p.ff.ss);
                res1[p.ff.ss].pb(p.ff.ff);
            }
        }
        bool picked[n+1];
        memset(picked,0,sizeof(picked));
        stack<int> que;
        vector<int> prin1;
        que.push(1);
        while(que.size()){
            int curr = que.top();
            que.pop();

            if(!picked[curr]){
                prin1.pb(curr);
                picked[curr] = true;
                for(int i : res1[curr]){
                    que.push(i);
                }
            }
        }

        int len = prin1.size();
        fore(i,0,len){
            if(i>0){
                int a = prin1[i],b= prin1[i-1];
                if(a>b)swap(a,b);
                externSides.insert({a,b});
            }
            if(i+1 == len){
                cout<<prin1[i]<<endl;
            }else{
                cout<<prin1[i]<<" ";
            }
        }
        int fir = 0;
        for(int i = 0; i< pieces.size(); i++ ){
            int cant = 0;
            for(auto p: pieces[i].sides){
                if(externSides.count(p)>0) cant++;
            }
            if(cant >=2){
                for(auto p: pieces[i].sides){
                    externSides.insert(p);
                }
                fir = i;
                break;
            }
        }
        dfs(fir);
        len = res2.size();
        fore(i,0,len){
            if(i+1 == len){
                cout<<res2[i]<<endl;
            }else{
                cout<<res2[i]<<" ";
            }
        }
    }
    return 0;
}
