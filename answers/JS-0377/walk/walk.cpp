#include<bits/stdc++.h>
using namespace std;
int n,k;
long long w[10];
int c[500001],d[500001];
int g[10],mx[10],mn[10];
int x[10];
long long ans;
int now[10][500001];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<k;i++)
	cin>>w[i];
	for(int i=0;i<n;i++){
		cin>>c[i]>>d[i];
		c[i]--;
		now[c[i]][i]+=d[i];
		if(i)
		for(int j=0;j<k;j++)
		now[j][i]=now[j][i-1];
		now[c[i]][i]+=d[i];
		if(now[c[i]][i]>now[c[i]][mx[c[i]]])
		mx[c[i]]=i;
		if(now[c[i]][i]<now[c[i]][mn[c[i]]])
		mn[c[i]]=i;	
	}
	bool f=true;
	for(int i=0;i<k;i++){
		if(now[i][n-1]!=0)
		f=false;
		if(abs(now[i][mn[i]])<w[i]/2+1&&now[i][mx[i]]<w[i]/2+1){
			f=f;
		}else
		f=false;
	}
	if(f==true){
		cout<<-1;
		return 0;
	}
	return 0;
}

