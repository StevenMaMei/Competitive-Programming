#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

class ChangeDistances{
    int toggle(char c){
        int to = (c-'0');
        if(to == 1){
            to =0;
        }else{
            to =1;
        }
        return to;
    }
    public: vector <string> findGraph(vector <string> g){
        for(int i = 0; i<sz(g); i++){
            for(int j = 0; j< sz(g[0]);j++){
                if(i!= j){
                    int rep= toggle(g[i][j]);
                    char c= char('0'+rep);
                    g[i][j]=c;
                }
            }
        }
        return g;
    };
};
int main(){FIN;
    return 0;
}
