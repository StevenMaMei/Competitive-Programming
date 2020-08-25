#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
using namespace std;

int main()
{FIN;
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> a(n);
        fore(i,0,n){
            cin>>a[i];
        }
        int steps = 0;
        int totA= 0,totB=0,i=0,j=n-1,lastA=0,lastB=0;
        while(i<=j){
            int pA = 0;
//            cout<<i<<" "<<j<<"\n";
            bool stepA=false;
            while(pA<=lastB && i <=j){
                stepA = true;
                pA += a[i];
                i++;
            }
            totA+= pA; lastA=pA;
            int pB= 0;
            bool stepB= false;
            while(pB<=lastA && i<=j){
                stepB = true;
                pB+= a[j];
                j--;
            }
            totB+= pB; lastB = pB;
            if(stepA) steps++;
            if(stepB) steps++;
        }
        cout<<steps<<" "<<totA<<" "<<totB<<"\n";

    }
    return 0;
}
