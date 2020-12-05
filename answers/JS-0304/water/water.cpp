#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(!b)
		return a;
	return gcd(b,a%b);
}

int n,m,k=1;
int enter[100001][6],exi[100001];
bool b[100001];
int d[100001];
int water[100001]; //·ÖÄ¸ 
int fwater[100001]; //·Ö×Ó 
int g,num;
void solve(int x){
	if(d[x]==0){
		return;
	}
	for(int i=1;i<=d[x];i++){
		if(water[enter[x][i]]==0){
			water[enter[x][i]]+=water[x]*d[x];
			fwater[enter[x][i]]=1;
		}
		else if(water[enter[x][i]]!=water[x]*d[x]){
			fwater[enter[x][i]]=fwater[x]*d[x]+water[x];
			water[enter[x][i]]=water[x]*d[x];
			g=gcd(fwater[enter[x][i]],water[enter[x][i]]);
			fwater[enter[x][i]]/=g;
			water[enter[x][i]]/=g;
		}
		else if(water[enter[x][i]]==water[x]*d[x]){
			fwater[enter[x][i]]=2;
			water[enter[x][i]]=water[x]*d[x];
			g=gcd(fwater[enter[x][i]],water[enter[x][i]]);
			fwater[enter[x][i]]/=g;
			water[enter[x][i]]/=g;
		}
//		cout<<enter[x][i]<<" "<<fwater[enter[x][i]]<<" "<<water[enter[x][i]]<<'\n';
//		cout<<enter[x][i]<<" ";
		solve(enter[x][i]);
//		if(x!=1){
//			fwater[x]=0;
//			water[x]=0;
//		}
//		cout<<'\n';
	
	}
	fwater[x]=0;
	water[x]=0;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
		if(d[i]==0)
			exi[++num]=i;
		for(int j=1;j<=d[i];j++){
			cin>>enter[i][j];
			b[enter[i][j]]=true;
		}
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			fwater[i]=1;
			water[i]=1;
			solve(i);
		}
	}
	for(int i=1;i<=num;i++)
		cout<<fwater[exi[i]]<<" "<<water[exi[i]]<<'\n';
	return 0;
}
/*
5 1
3 2 3 5
2 4 5
2 5 4
0 
0
*/
