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
typedef long long ll;
//bool comp(pair<ii,int> a, pair<ii,int> b){
//
//    return a.ff.ss*b.ff.ff < b.ff.ss*a.ff.ff;
//}
bool comp(pair<ii,int> a, pair<ii,int> b){

    return (a.ff.ff*a.ff.ss )- (b.ff.ff*b.ff.ss )< (a.ff.ss+b.ff.ss)*(a.ff.ff-b.ff.ff);
}

ii dp[105][1005];
ll calcEt(int tmx, int last, vector<pair<ii,int>> &problems){
    vector<int> ans;

    while(tmx){
        tmx -= problems[last].ff.ss;
        ans.pb(last);
        last = dp[last][tmx].ss;
    }
    ll toR= 0;
    ll acum=0;
    for(int i = sz(ans)-1; i>=0;i--){
        acum += problems[ans[i]].ff.ss;
        toR+= acum* problems[ans[i]].ff.ff;
    }
    return toR;
}
int main(){FIN;
    int N,tmax; cin>>N>>tmax;
    fore(i,0,105)fore(j,0,1005){
        dp[i][j]={-1,-1};
    }
    fore(i,0,105){
        dp[i][0]={0,i};
    }
    vector<pair<ii,int>> problems(N);

    fore(i,0,N){
        int t,p; cin>>t>>p;


        problems[i]={{p,t},i};
    }
        sort(problems.begin(),problems.end(),comp);
//    reverse(problems.begin(),problems.end());
    fore(i,0,N){
        fore(j,1,tmax+1){
            if(dp[i+1][j].ff < dp[i][j].ff)
                dp[i+1][j]=dp[i][j];
        }
        fore(j,0,tmax+1){
            if(dp[i][j].ff != -1 && j+problems[i].ff.ss <=tmax){
                if(dp[i][j].ff +problems[i].ff.ff> dp[i+1][j+problems[i].ff.ss].ff){
                    dp[i+1][j+problems[i].ff.ss] ={dp[i][j].ff +problems[i].ff.ff,i};
                }else if(dp[i][j].ff +problems[i].ff.ff== dp[i+1][j+problems[i].ff.ss].ff){
                    ii last= dp[i+1][j+problems[i].ff.ss];
                    int etlast = calcEt(j+problems[i].ff.ss,last.ss,problems);
                    dp[i+1][j+problems[i].ff.ss] ={dp[i][j].ff +problems[i].ff.ff,i};
                    if(etlast< calcEt(j+problems[i].ff.ss,i,problems)){
                        dp[i+1][j+problems[i].ff.ss] =last;
                    }
                }
            }
        }
    }
    int tmx=-1,pmx=-1,last=-1,prob=1e9;
    ll et = 1e18;
    fore(i,0,tmax+1){

        if(dp[N][i].ff>pmx ){
            pmx=dp[N][i].ff;
            tmx=i;
            last =dp[N][i].ss;
            prob=problems[dp[N][i].ss].ff.ff;
            et = calcEt(tmx,last,problems);
        }else if(dp[N][i].ff == pmx ){
            if(et> calcEt(i,dp[N][i].ss,problems)){
                pmx=dp[N][i].ff;
                tmx=i;
                last =dp[N][i].ss;
                prob=problems[dp[N][i].ss].ff.ff;
                et = calcEt(tmx,last,problems);
            }
        }
    }
//    cout<<"jejej "<<pmx<<"\n";
    vector<int> ans;

    while(tmx){
        tmx -= problems[last].ff.ss;
        ans.pb(problems[last].ss);
        last = dp[last][tmx].ss;
    }
    reverse(ans.begin(),ans.end());
    cout<<sz(ans)<<"\n";
    fore(i,0,sz(ans)){
        cout<<ans[i]+1<<" ";
    }
    cout<<"\n";
    return 0;
}
