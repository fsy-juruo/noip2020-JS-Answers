#include<bits/stdc++.h>
using namespace std;
const int N=22010;
int n,m;
struct{
	int p;
	int q;
	int d;
}w[N];
void yf(int a){
	int i=2;
	while(i<=w[a].p&&i<=w[a].q){
		if(w[a].p%i==0&&w[a].q%i==0){
			w[a].p/=i;
			w[a].q/=i;
		}
		else i++;
	}
	if(w[a].p==0)w[a].q=1;
}
void ja(int e,int s,int d){
	int t=w[s].q*d;
	int k=w[e].q;
	int l=w[s].p*k;
	w[e].q*=t;
	w[e].p*=t;
	w[e].p+=l;
	yf(e);
}

int ne[N][N],x;
void add(int a,int b){
	ne[a][++x]=b;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		w[i].p=1;
	}
	for(int i=1;i<=n;i++){
		w[i].q=1;
		int d;
		cin>>d;
		w[i].d=d;
		x=0;
		for(int j=1;j<=d;j++){
			int a;
			cin>>a;
			add(i,a);
		}
		ne[i][0]=x;
	}
	bool flag=1;
	while(flag){
		for(int i=1;i<=n;i++){
			int v=w[i].d;
			if(w[i].d!=0&&w[i].d!=-1&&w[i].p!=0){
				for(int j=1;j<=ne[i][0];j++){
					ja(ne[i][j],i,v);
				}
				w[i].p=0;
				w[i].q=1;
			}
		}
		for(int i=1;i<=n;i++){
			if(w[i].d!=0&&w[i].p!=0){
				flag=1;
				break;
			}
			flag=0;
		}
	}
	
	for(int i=1;i<=n;i++){
		if(w[i].d==0)cout<<w[i].p<<" "<<w[i].q<<endl;
	}
	return 0;
}
