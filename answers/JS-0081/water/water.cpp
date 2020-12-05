#include<bits/stdc++.h>
using namespace std;

int n,m;
int mp[100001][5];
int wat[100001],tail,head=1;
struct fs{
	int fz;
	int fm;
	fs(){
		fm=1;
		fz=1;
	}
}ll[100001];
int miny(int p,int q){
	if(p%q==0)
	return q;
	else
	return miny(q,p%q);
}
fs yf(fs a){
	int cs=miny(a.fm,a.fz);
	fs res;
	res.fm=a.fm/cs;
	res.fz=a.fz/cs;
	return res;
}
fs fsys(fs a,fs b,int fh){
	fs res;
	if(fh==0){
		res.fm=a.fm*b.fm;
		res.fz=a.fm*b.fz+a.fz*b.fm;
	}
	else if(fh==1){
		res.fm=a.fm*b.fm;
		res.fz=-a.fm*b.fz+a.fz*b.fm;
	}
	else if(fh==2){
		res.fm=a.fm*b.fm;
		res.fz=b.fz*a.fz;
	}
	else if(fh==3){
		res.fm=a.fm*b.fz;
		res.fz=a.fz*b.fm;
	}
	res=yf(res);
	return res;
}
void dfs(int wat[]){
	int k=head;
	while(k<=tail){
		if(wat[k]==0){
		k++;
		continue;
		}
		fs l,un;
		un.fm=1;
		un.fz=0;
		while(mp[k][un.fz]!=0&&un.fz<5){
		wat[tail++]=mp[k][un.fz];
		un.fz++;
		}
		if(un.fz==0){
			wat[k]=0;
			k++;
			continue;
		}
		l=fsys(ll[k],un,3);
		wat[k]=0;
		ll[k].fz=0;
		un.fz--;
		while(un.fz>=0){
			ll[mp[k][un.fz]]=fsys(ll[mp[k][un.fz]],l,0);
			un.fz--;
		}
		k++;
	}
	while(wat[head++]==0){
		if(head==tail)
		return;
	}
	
	dfs(wat);
}
int main(){

freopen("water.in","r",stdin);
freopen("water.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%d",&k);
		for(int o=0;o<k;o++){
			scanf("%d",&mp[i][o]);
			ll[mp[i][o]].fz=0;
		}
	}
	int k=1;
	for(int i=1;i<=n&&k<=m;i++){
		if(ll[i].fz==1){
			wat[k++]=i;
			tail++;
		}
	}
	dfs(wat);
	for(int i=1;i<=n;i++){
		if(ll[i].fz!=0)
		printf("%d %d\n",ll[i].fz,ll[i].fm);
	}
return 0;
}


