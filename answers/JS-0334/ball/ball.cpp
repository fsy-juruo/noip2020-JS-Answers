#include <bits/stdc++.h>
using namespace std;

int n,m,a[60][410],cnt[60];

inline int getint()
{
	int r=0,flag=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		r=r*10+ch-'0';
		ch=getchar();
	}
	return r*flag;
}

inline void func(int x,int y)
{
	cnt[x]--;cnt[y]++;
	a[y][cnt[y]]=a[x][cnt[x]+1];
	a[x][cnt[x]+1]=0;
}

signed main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=getint();m=getint();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) a[i][j]=getint();
		cnt[i]=m;
	}
	vector<pair<int,int> > v;
	for(int i=1;i<=n-1;i++){
		int now=n+2-i;
		for(int j=1;j<now-1;j++){
			int nxt=j+1;
			bool flag=true;
			while(flag){
				flag=false;
				for(int k=cnt[j];k>=1;k--) if(a[j][k]==i){
					int tot=cnt[j];
					for(int l=tot;l>=k;l--){
						v.push_back(make_pair(j,now));func(j,now);
					}
					for(int l=tot;l>k;l--){
						v.push_back(make_pair(nxt,j));func(nxt,j);
					}
					v.push_back(make_pair(now,j));func(now,j);
					for(int l=tot;l>k;l--){
						v.push_back(make_pair(now,nxt));func(now,nxt);
					}
					v.push_back(make_pair(j,now));func(j,now);
					flag=true;
					break;
				}
			}
			for(int k=cnt[now];k>=1;k--){
				v.push_back(make_pair(now,j));func(now,j);
			}
		}
		for(int j=1;j<=now-1;j++){
			for(int k=cnt[j];k>=1;k--){
				if(a[j][k]!=i) break;
				v.push_back(make_pair(j,now));func(j,now);
			}
		}
		for(int j=cnt[now-1];j>=1;j--){
			if(a[now-1][j]==i){
				v.push_back(make_pair(now-1,now));func(now-1,now);
			}
			else{
				for(int l=1;l<now-1;l++){
					if(cnt[l]<m){
						v.push_back(make_pair(now-1,l));func(now-1,l);
						break;
					}
				}
			}
		}
	}
	printf("%d\n",v.size());
	for(int i=0;i<v.size();i++) printf("%d %d\n",v[i].first,v[i].second);
	return 0;
}
