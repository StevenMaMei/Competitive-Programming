#include <bits/stdc++.h>

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define fore(i,low,n) for(int i=low;i<n;i++)

using namespace std;
const int NN = 10000;
int W,K;
double D;
double A;
double d;
vector<double> p1;
vector<double> q1;
vector<double> p2;
vector<double> q2;
double f1(double x){
    double sp=0;
    double sq=0;
    double pw=1;
    for(int i =0; i < p1.size(); i++){
        sp+= pw*p1[i];
        sq+= pw*q1[i];
        pw= pw*x;
    }
    double res = sp/sq;
    return max(d,res);
}
double f2(double x){
    double sp=0;
    double sq=0;
    double pw= 1;
    for(int i =0; i < p2.size(); i++){
        sp+= pw*p2[i];
        sq+= pw*q2[i];
        pw*= x;
    }
    double res = sp/sq;
    return max(d,res);
}
double simpson_integration(double a, double b, int who){
    double h = (b-a)/ NN;
    double s=0;
    if(who == 1){

        s = f1(a) + f1(b);
        for (int i = 1; i <= NN - 1; ++i) {
            double x = a + h * i;
            s += f1(x) * ((i & 1) ? 4 : 2);
        }
        s *= h / 3;
    }else{
        s = f2(a) + f2(b);
        for (int i = 1; i <= NN - 1; ++i) {
            double x = a + h * i;
            s += f2(x) * ((i & 1) ? 4 : 2);
        }
        s *= h / 3;
    }
    return s;
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
    while(cin>> W>>D>>A>>K){
        p1.clear(); p1.resize(K+1);
        p2.clear(); p2.resize(K+1);
        q1.clear(); q1.resize(K+1);
        q2.clear(); q2.resize(K+1);
        for(int i = 0; i < K+1; i++){
            double r ; cin>> r;
            p1[i]=r;
        }
        for(int i = 0; i < K+1; i++){
            double r ; cin>> r;
            q1[i]=r;
        }
        for(int i = 0; i < K+1; i++){
            double r ; cin>> r;
            p2[i]=r;;
        }
        for(int i = 0; i < K+1; i++){
            double r ; cin>> r;
            q2[i]= r;
        }
        int it =100;
        double l =0;
        double r = D;
        while(it){
            d= (l+r)/2.0*-1.0;
            int res= (-simpson_integration(0,(double)W,2))-(-simpson_integration(0,(double)W,1));

            if(res<A){
                l=d*-1;
            }else {
                r=d*-1;
            }
            it--;
        }

        cout<<fixed<<setprecision(5) <<(-d)<<endl;
    }
    return 0;
}
