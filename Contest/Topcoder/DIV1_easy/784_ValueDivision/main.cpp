#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;


class ValueDivision{
    public:vector<int> getArray(vector<int> A){
        int n = sz(A);
        int lastMax=1e9+5;
        while(true){
            int currMax=1, lastPos=1;
            fore(i,0,n){
                if(A[i]< lastMax && A[i]>=currMax){
                    currMax=A[i];
                    lastPos=i;
                }
            }
            if(currMax==1)break;
            fore(i,0,lastPos){
                if(A[i]==currMax){
                    A[i]--;
                }
            }
            lastMax=currMax;
        }
        return A;
    };
};
