#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(long long int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;

int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<char> seq(n-1);
        fore(i,0,n-1){
            cin>>seq[i];
        }
        int last = 0;
        int m = n;
        vector<int> ans(n);
        fore(i,0,n){
            if(i == n -1 || seq[i]=='>'){
                for(int j = i; j>=last;j--){
                    ans[j]=m--;
                }
                last = i+1;
            }
        }
        fore(i,0,n){
            cout<<ans[i]<<(i+1==n?"\n":" ");
        }
        ans.clear(); ans.resize(n);
        last = 0;
        m=1;
        fore(i,0,n){
            if(i == n -1 || seq[i]=='<'){
                for(int j = i; j>=last;j--){
                    ans[j]=m++;
                }
                last = i+1;
            }
        }
        fore(i,0,n){
            cout<<ans[i]<<(i+1==n?"\n":" ");
        }
    }
    return 0;
}
