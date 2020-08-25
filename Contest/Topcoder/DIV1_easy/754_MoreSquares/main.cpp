#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define sz(s) int(s.size())
#define x real
#define y imag

using namespace std;
typedef int ftype;
typedef complex<int> point;
struct lex_compare {
    bool operator() (const point& a, const point &b) const {
        return make_pair(a.x(), a.y()) < make_pair(b.x(), b.y());
    }
};

class MoreSquares{
    public:  int countLocations(int N, int SX, int SY, vector <int> Xprefix, vector <int> Yprefix){
        vector<int> X(N), Y(N);
        int L = sz(Xprefix);
        for(int i = 0; i < L; i++) {
            X[i] = Xprefix[i];
            Y[i] = Yprefix[i];
        }
        for(int i = L; i < N; i++) {
            X[i] = ( X[i-1] * 47 + 42 ) % SX;
            Y[i] = ( Y[i-1] * 47 + 42 ) % SY;
        }
        set<point,lex_compare> S;
        for(int i = 0; i<N ;i++){
            S.insert(point(X[i],Y[i]));
        }
        set<point,lex_compare> T;
        for(auto it : S){
            for(auto jt: S){
                if(it != jt){
                    point dir = jt-it;

                    if( (dir.x()&1) != (dir.y()&1) )continue;

                    point kt = it+(dir + point(0,1)*dir)/2;
                    point lt = it+(dir - point(0,1)*dir)/2;
                    cout<<lt.x()<<" "<<lt.y()<<"\n";
                    if(S.count(kt) && !S.count(lt)){
                        T.insert(lt);
                    }
                }
            }
        }
        return sz(T);
    };
};

int main(){FIN;
    MoreSquares s;
    vector<int> x={3, 0, 2},y={0, 1, 2};
    cout<<s.countLocations(3,100,100,x,y);
    return 0;
}
