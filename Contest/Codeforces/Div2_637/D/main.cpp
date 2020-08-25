#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thx=b;i<thx;i++)
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

using namespace std;
string digits[10]={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

int main()
{FIN;
    int n,k; cin>>n>>k;
    vector<vector<int>> countK(n,vector<int>(10));
    fore(i,0,n){
        string s; cin>>s;
        fore(d,0,10){
            fore(j,0,7){
                char x= digits[d][j], y= s[j];
                if(y=='1' && x =='0'){
                    countK[i][d]=-1;
                    break;
                }
                if(y=='0' && x =='1'){
                    countK[i][d]++;
                }
            }
        }
    }
    vector<vector<int>> dp(n+1,vector<int>(k+1));

    dp[n][0] = 1;
    for(int i =n;i>0;i--){
        fore(j,0,k+1){
            if(dp[i][j]){
                fore(d,0,10){
                    if(countK[i-1][d]!= -1 && j+countK[i-1][d]<=k){
                        dp[i-1][j+countK[i-1][d]]= 1;
                    }
                }
            }
        }
    }
    if(dp[0][k]==0){
        cout<<"-1\n";
        return 0;
    }
    fore(i,0,n){
        for(int d=9; d>=0;d--){
            if(countK[i][d]!= -1 && countK[i][d] <= k&& dp[i+1][k-countK[i][d]]){
                cout<<d;
                k -= countK[i][d];
                break;
            }
        }
    }
    cout<<"\n";
    return 0;
}
