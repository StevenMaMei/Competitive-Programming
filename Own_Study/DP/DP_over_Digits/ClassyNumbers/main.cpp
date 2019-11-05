#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
typedef long long ll;
using namespace std;

ll memo[20][3][4];

ll solve(string num, int dig, bool flag, int rem){
    if(memo[dig][flag][rem]!= -1)
        return memo[dig][flag][rem];
    if(dig == num.size())
        return 1;
    ll r=0;
    int top=0;
    if(flag)
        top = 9;
    else
        top= num[dig]-'0';
    if(rem == 0)
        top = 0;

    for(int i =0; i<= top; i++){
        if(i== top && !flag){
            r+=solve(num,dig+1,false,rem-(i>0));
        }else{
            r+=solve(num, dig+1,true, rem-(i>0));
        }
    }

    return memo[dig][flag][rem]=r;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifdef LOCAL
      freopen("input.txt", "r", stdin);

    #else
      #define endl '\n'
    #endif
    int cas; cin>>cas;
    for(int i =0; i<cas;i++ ){
    ll y,x; cin>>x>>y;
    x--;
    string a = to_string(y);
    memset(memo,-1,sizeof(memo));
    int b = solve(a,0,0,3);
    string c = to_string(x);
    memset(memo,-1,sizeof(memo));
    int d= solve(c,0,0,3);
    cout<< b -d<<"\n";

    }
}
