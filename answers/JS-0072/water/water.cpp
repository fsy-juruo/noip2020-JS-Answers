#include<bits/stdc++.h>
#define N 100010
#define ll long long
using namespace std;
int n,m,a[N],u,v,fla=0,ru[N],pd[N];
vector<int> ve[N],sta;
ll ap[N],aq[N];
queue<int> q;

ll gcd(ll aa,ll bb){
	if(bb==0) return aa;
	return gcd(bb,aa%bb);
}

void addi(int xu,int yv){
	ll gad=aq[xu]*aq[yv],al,bl,fin;
	gad/=gcd(aq[xu],aq[yv]);
	al=gad/aq[xu];
	bl=gad/aq[yv];
	aq[xu]*=al;
	ap[xu]*=al;
	ap[xu]+=bl*ap[yv];
	fin=gcd(ap[xu],aq[xu]);
	ap[xu]/=fin;
	aq[xu]/=fin;
}

int main(){
	
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	memset(ru,0,sizeof ru);
	memset(pd,0,sizeof pd);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		aq[i]=1;
		ap[i]=0;
		scanf("%d",&a[i]);
		for(int j=0;j<a[i];j++){
			scanf("%d",&v);
			ve[i].push_back(v);
			ru[v]++;
		}
	}	
	for(int i=1;i<=n;i++){
		if(ru[i]==0){
			sta.push_back(i);
			q.push(i);
			ap[i]=1;
		}
	}
	while(!q.empty()){
		while(pd[q.front()]==1) q.pop();
		int dur=q.front();
		q.pop();
		pd[dur]=1;
		if(a[dur]!=0) aq[dur]*=a[dur];
		for(int i=0;i<a[dur];i++){
			ru[ve[dur][i]]--;
			addi(ve[dur][i],dur);
			if(ru[ve[dur][i]]==0) q.push(ve[dur][i]);
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			cout<<ap[i]<<' '<<aq[i]<<endl;
		}
	}
	return 0;
}
