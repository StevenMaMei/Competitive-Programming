#include <bits/stdc++.h>
#define ff first
#define ss second
#define fore(i,a,b) for(int i=a,colchin=b;i<colchin;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
int gcd(int a,int b){return a?gcd(b%a,a):b;}
int values[1005];
int parent[1005];
int n;
int maxDivisor(int num){
	fore(i,2,num+1){
		if(num%i==0){
			return num/i;
		}
	}
	return 1;
}
int minDivisor(int num){
    int mn= num;
	for(int i = 2; i*i<= num;i++){
        if(num%i==0){
            mn = min(i, num/i);
        }
	}
	return num;
}
int main(){FIN;
	/*
	freopen("divisibility-tree.in","r",stdin);
	freopen("divisibility-tree.out","w",stdout);
	*/
	cin >> n;
	fore(i,0,n){
		int p,a;
		cin >> p >> a;
		values[i]=a;
		if(p!=-1){
			p--;
			parent[i]=p;
		}else{
			parent[i]=p;
		}
	}
	for(int u=n-1;u>0;u--){
		if(values[parent[u]]==-1){
			values[parent[u]]=values[u];
		}else{
			values[parent[u]]=gcd(values[parent[u]],values[u]);
		}
	}
	for(int u=n-1;u>0;u--){
		if(values[parent[u]]==values[u]){
			if(parent[u]==0){
				values[parent[u]]=1;
			}else{
				if(values[parent[u]]==values[parent[parent[u]]]){
					int md=minDivisor(values[parent[u]]);
					values[parent[u]]/=md;
					values[parent[parent[u]]]/=md;
				}else if(values[parent[parent[u]]]<values[parent[u]]){
					int factor=values[parent[u]]/values[parent[parent[u]]];
					int md=minDivisor(factor);
					values[parent[u]]/=max(md,factor);
				}
			}
			/*values[parent[u]]=maxDivisor(values[parent[u]]);
			if(values[parent[u]]==values[u]){
				fore(i,0,n){
					if(i==n-1)cout << values[i]<<"\n";
					else cout << values[i]<<" ";
				}
				exit(0);
			}*/
		}
	}
	for(int u=n-1;u>0;u--){
		if(values[u]<=values[parent[u]]){
			fore(i,0,n){
				if(i==n-1)cout << "-1"<<"\n";
				else cout << "-1"<<" ";
			}
			exit(0);
		}
	}
	fore(i,0,n){
		if(i==n-1)cout << values[i]<<"\n";
		else cout << values[i]<<" ";
	}
    return 0;
}
