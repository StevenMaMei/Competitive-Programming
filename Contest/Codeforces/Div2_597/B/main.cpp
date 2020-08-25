#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())

using namespace std;


int main(){FIN;
    int t; cin>>t;
    while(t--){
        int n,a,b,c; cin>>n>>a>>b>>c;
        string s; cin>>s;
        vector<int> cnt(3);
        fore(i,0,n){
            if(s[i]=='R')cnt[0]++;
            else if(s[i]== 'P')cnt[1]++;
            else if(s[i]=='S')cnt[2]++;
        }
        int wins =0;
        wins += min(b,cnt[0]);
        wins += min(c,cnt[1]);
        wins += min(a,cnt[2]);

        if(wins >= int(ceil( double(n)/2.0 ) )){
            cout<<"YES\n";
            cnt[0]=a;cnt[1]=b; cnt[2]=c;
            vector<bool> visited(n);
            fore(i,0,n){
                if(s[i]=='R' && cnt[1]>0){
                    s[i] ='P';
                    cnt[1]--;
                    visited[i]=true;
                }else if(s[i]=='P' && cnt[2]>0){
                    s[i]='S';
                    cnt[2]--;
                    visited[i]=true;
                }else if(s[i]=='S' && cnt[0]>0){
                    s[i]='R';
                    cnt[0]--;
                    visited[i]=true;
                }
            }
            fore(i,0,n){
                if(!visited[i]){
                    fore(j,0,3){
                        if(cnt[j]>0){
                            if(j==0){
                                s[i]='R';
                            }else if(j==1){
                                s[i]='P';
                            }else{
                                s[i]='S';
                            }
                            cnt[j]--;
                            break;
                        }
                    }
                }
            }
            cout<<s<<"\n";
        }else{
            cout<<"NO\n";
        }


    }
    return 0;
}
