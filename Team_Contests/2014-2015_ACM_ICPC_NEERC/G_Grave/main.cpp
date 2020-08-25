#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())

using namespace std;

typedef long long int ll;
typedef vector<int> vi;
typedef pair<int, int> ii;


int main(){FIN;
freopen("grave.in","r",stdin);
	freopen("grave.out","w",stdout);
    int x1,y1,x2,y2,x3,y3,x4,y4;
    cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
    int w,h; cin>>w>>h;
    int a,b;

    a= abs(x1-x3),b= abs(y2-y1);
    if(w<=a && h <=b){
        cout<<"Yes\n";
        return 0;
    }

    a= abs(x1-x2),b= abs(y2-y4);
    if(w<=a && h <=b){
        cout<<"Yes\n";
        return 0;
    }

    a= abs(x1-x2),b= abs(y1-y3);
    if(w<=a && h <=b){
        cout<<"Yes\n";
        return 0;
    }

    a= abs(x4-x2),b= abs(y1-y2);
    if(w<=a && h <=b){
        cout<<"Yes\n";
        return 0;
    }

    cout<<"No\n";
    return 0;
}
