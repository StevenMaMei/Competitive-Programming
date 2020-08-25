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

class RainForecast{
    double predictRain(int ilkoProb, vector<int> deliverProbs){
        double a= 1.0;
        fore(i,0,sz(deliverProbs)){
            double p = deliverProbs[i] /100.0;
            a = a*p + (1-a)*(1-p);
        }
        a = max(a,1-a);
        double r  = ilkoProb/100.0;
        r = max(r, 1-r);
        return r*a + (1-r)(1-a);
    }
};
