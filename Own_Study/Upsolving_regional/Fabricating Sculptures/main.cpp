    #include <bits/stdc++.h>

    #define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
typedef long long int ll;
ll sumaParcialA;
ll sumaParcialB;
ll dp[5005][5005];
bool bre=false;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);
    #else
      #define endl '\n'
    #endif

    ll s, b; cin>> s>> b;

    b-= s;
    ll mod= 7+1e9;
    for(int i =1;i<=s;i++){
        dp[0][i] = 1;
    }
    for(int i =1; i<= b; i++){
        sumaParcialA= 0;
        sumaParcialB=0;
        for(int j = 1; j <= s; j++){
            ll mi= (long long int)min(i,j);
            if(i>=j){
                ll op1=dp[i-mi][mi];
                sumaParcialA+=op1;
                sumaParcialA%=mod;
                op1*= mi;
                op1%=mod;
                sumaParcialB+=op1;
                sumaParcialB%=mod;
            }
            //sumaParcialA*(j+1)-sumaParcialB
            ll compB = (sumaParcialA*(j+1)-sumaParcialB)%mod;
            dp[i][j]= compB;
        }
    }
    cout<<dp[b][s]<<endl;
    return 0;
}
