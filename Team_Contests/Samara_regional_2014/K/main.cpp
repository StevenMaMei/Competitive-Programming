#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,thxicesi=b; i<thxicesi;i++)
#define FIN ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0)

using namespace std;
#define oper min
#define NEUT INF
#define oper max
struct STree { // segment tree for min over integers
	vector<int> st;int n;
	STree(int n): st(4*n+5,0), n(n) {}
	void init(int k, int s, int e, int *a){
		if(s+1==e){st[k]=a[s];return;}
		int m=(s+e)/2;
		init(2*k,s,m,a);init(2*k+1,m,e,a);
		st[k]=oper(st[2*k],st[2*k+1]);
	}
	int query(int k, int s, int e, int v){
		if(st[k]<=v)return -1;
		if(s+1 == e)return s;
		int m=(s+e)/2;
		if(st[2*k]>v){
            return query(2*k,s,m,v);
		}else{
            return query(2*k+1,m,e,v);

		}
	}
	void init(int *a){init(1,0,n,a);}
	int query(int v){return query(1,0,n,v);}
};
int aa[100005],bb[100005];
int main()
{FIN;
    int n; cin>>n;
    STree a(n),b(n);

    fore(i,0,n)cin>>aa[i];
    fore(i,0,n)cin>>bb[i];
    a.init(aa);b.init(bb);
    int q;cin>>q;
    vector<int> sa(q),sb(q);
    fore(i,0,q) cin>>sa[i];
    fore(i,0,q) cin>> sb[i];
    fore(i,0,q){
        int pos1 = a.query(sa[i]),pos2 = b.query(sb[i]);
        if(pos1 == -1 && pos2 == -1){
            cout<<"Draw\n";
        }else if(pos1 == -1 && pos2 != -1){
            cout<<"Constantine\n";
        }else if(pos1 != -1 && pos2==-1){
            cout<<"Mike\n";
        }else{
            if(pos1<pos2){
                cout<<"Mike\n";
            }else if(pos1>pos2){
                cout<<"Constantine\n";
            }else{
                cout<<"Draw\n";
            }
        }

    }
    return 0;
}
