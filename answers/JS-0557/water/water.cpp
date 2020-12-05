#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001][1001],cn[1001],ou[1001],cnt;
struct N{
	int fz,fm;
	bool last;
}v[1001];
void gbs(int x){
	for(int i=2;i<=v[x].fz,i<=v[x].fm;i++)
		if(v[x].fz%i==0&&v[x].fm%i==0){
			v[x].fz/=i,v[x].fm/=i;
			gbs(x);
		}	
}
void add(int j,int t){
	if(!v[t].fz){
		v[t].fz=v[j].fz;v[t].fm=v[j].fm*cn[j];
	}
	else{
		v[t].fz=v[t].fz*v[j].fm*cn[j]+v[j].fz*v[t].fm;
		v[t].fm*=v[j].fm*cn[j];
	}
	gbs(t);
}
void search(int j){
	int t;
	for(t=m+1;t<=n;t++){
		if(a[j][t])	if(v[t].last)	add(j,t);
					else{
					v[t].fz=1;
		 			v[t].fm=v[j].fm*cn[j];
					search(t);
			 		}		
	}
}
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	int x,d;
	for(int i=1;i<=n;i++){
		cin>>d;
		if(d==0){
			ou[++cnt]=i;v[i].last=1;	
		}	
		else while(d--){
			cin>>x;
			a[i][x]=1;
			cn[i]++;		
		}		
	}	
	
	for(int i=1;i<=m;i++){
		v[i].fz=1;v[i].fm=1;
		for(int j=m+1;j<=n;j++){
			if(a[i][j]==1) 
			if(v[j].last) add(i,j);
			else {
				v[j].fz=1,v[j].fm=cn[i];
				search(j);
			}
		}	
	}
	for(int i=1;i<=cnt;i++)
	cout<<v[ou[i]].fz<<" "<<v[ou[i]].fm<<endl;
	return 0;                 
}
