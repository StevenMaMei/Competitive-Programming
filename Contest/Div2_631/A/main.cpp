#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define fore(i,a,b) for(int i=a,thxicesi=b; i< thxicesi;i++)
using namespace std;
bool picked[205];
int main()
{
    int t; cin>>t;
    while(t--){
        memset(picked,0,sizeof(picked));
        int n,x; cin>>n>>x;
        fore(i,0,n){
            int a; cin>>a;
            picked[a]= true;
        }
        queue<int> q;
        fore(i,1,205){
            if(!picked[i]){q.push(i);}
        }
        while(x--){
            q.pop();
        }

        cout<<q.front()-1<<endl;

    }
    return 0;
}
