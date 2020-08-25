#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;
typedef pair<int,int> ii;
ii solve(string s){
    vector<int> mp(1000005);
    int currlen = 0;
    int sum=0;
    int continousneg=0;
    fore(i,0,sz(s)){
        if(s[i]=='('){
            sum++;
            continousneg=0;
        }else{
            sum--;
            continousneg++;
//            if(sum>0){
//                mp[continousneg*2]++;
//            }
        }
        currlen++;
        if(sum<0){
            currlen=0;
            sum=0;
        }
        if(sum==0 &&currlen >0){
            mp[currlen]++;
        }
    }

    int mxlen=0;
    fore(i,0,sz(mp)){
        if(mp[i]){
            mxlen=i;
        }
    }
    return {mxlen,mp[mxlen]};
}
ii solve2(string s){
    vector<int> mp(1000005);
    int currlen = 0;
    int sum=0;
    int continousneg=0;
    for(int i=sz(s)-1;i>=0;i--){
        if(s[i]==')'){
            sum++;
            continousneg=0;
        }else{
            sum--;
//            continousneg++;
//            if(sum>0){
//                mp[continousneg*2]++;
//            }
        }
        currlen++;
        if(sum<0){
            currlen=0;
            sum=0;
        }
        if(sum==0 &&currlen >0){
            mp[currlen]++;
        }
    }

    int mxlen=0;
    fore(i,0,sz(mp)){
        if(mp[i]){
            mxlen=i;
        }
    }
    return {mxlen,mp[mxlen]};
}
int main()
{FIN;
    string s; cin>>s;

    ii p = solve(s);

    ii p2= solve2(s);
    int mxlen=0, frec=0;
    if(p.ff >p2.ff){
        mxlen=p.ff;
        frec=p.ss;
        if(mxlen== 0)frec =1;
    }else if(p.ff<p2.ff){
        mxlen=p2.ff;
        frec=p2.ss;
        if(mxlen== 0)frec =1;
    }else{
        mxlen=p2.ff;
        frec=max(p.ss,p2.ss);
        if(mxlen== 0)frec =1;
    }
    cout<<mxlen<<" "<<frec<<"\n";
    return 0;
}
