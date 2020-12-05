#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m,s,l;
struct P{
	unsigned long long fm,fz,d;
}a[100005];
vector <int> v[100005];
void yuefen(){
	for(int i=1;i<=n;i++){
		if(!a[i].d){
			unsigned long long k=a[i].fz,l=a[i].fm,tmp;
			if(k==l)a[i].fz=a[i].fm=1;
			else{
				while(1){
					if(k>l){
						tmp=k-l;
						if(l%tmp==0){
							a[i].fz=a[i].fz/tmp;
							a[i].fm=a[i].fm/tmp;
							break;
						}
						else k=l,l=tmp;
					}
					else if(k<l){
						tmp=l-k;
						if(l%tmp==0){
							a[i].fz=a[i].fz/tmp;
							a[i].fm=a[i].fm/tmp;
							break;
						}
						else k=l,l=tmp;
					}
					else{
						a[i].fz=a[i].fm=1;
						break;
					}
				}	
			}
		}
	}
	return;
}
void add(int x){
	unsigned long long k=v[x].size();
	for(int i=0;i<v[x].size();i++){
		unsigned long long dm=a[v[x][i]].fm;
		a[v[x][i]].fm=a[x].fm*k*dm;
		a[v[x][i]].fz=a[v[x][i]].fz*a[x].fm*k+dm*a[x].fz;
	}
	if(a[x].d) a[x].fz=0;
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		a[i].fm=1;
		a[i].fz=0;
		a[i].d=1;
	}
	for(int i=1;i<=m;i++)a[i].fz=1;
	for(int i=1;i<=n;i++){
		scanf("%d",&l);
		if(l==0)a[i].d=0;
		else{
			for(int j=1;j<=l;j++){
				scanf("%d",&s);
				v[i].push_back(s);
			}	
		}
	}
	for(int i=1;i<=n;i++)if(a[i].d)add(i);
	yuefen();
	for(int i=1;i<=n;i++)if(!a[i].d)cout<<a[i].fz<<" "<<a[i].fm<<endl;
	return 0;
}
