#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[55][402];
int co[55]={0};
int fob[55];
int oda[55];
bool used[55]={false};
int col[55]={0};
vector<pair<int,int> > steps;
bool cmp(int x,int y){
	return co[x]>co[y];
}
void mv(int x,int y){
	steps.push_back(make_pair(x,y));
	a[y][fob[y]+1]=a[x][fob[x]];
	a[x][fob[x]]=0;
	fob[x]--;
	fob[y]++;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		bool flag=true;
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			if(j==1){
				co[i]=1;
				continue;
			}
			if(a[i][j]==a[i][j-1]&&flag){
				co[i]++;
			}
			else flag=false;
		}
		fob[i]=m;
		oda[i]=i;
	}
	fob[n+1]=0;
	oda[n+1]=n+1;
	co[n+1]=0;
	sort(oda+1,oda+n+2,cmp);
	for(int i=1;i<=n;i++){
		if(!used[a[i][1]]){
			used[a[i][1]]=true;
			col[i]=a[i][1];
		}
	}
	int p=1;
	for(int i=1;i<=n;i++){
		if(col[i]) continue;
		while(used[p]) p++;
		col[i]=p;
		co[i]=0;
	}
	for(int i=1;i<=n;i++){
		while(fob[i]>=co[i]){
			int j=1;
			while(fob[j]==m||j==i) j++;
			mv(i,j);
		}
		int j=0;
		while(fob[i]<m){
			for(int x=1;x<=n+1;x++){
				if(fob[x]>j&&a[x][fob[x]-j]==col[i]){
					for(int y=x;y>x-j;y--){
						int xx=1;
						while(fob[xx]==m||xx==x) xx++;
						mv(x,xx);
					}
					while(a[x][fob[x]]==col[i]){
						mv(x,i);
					}
				}
			}
			j++;
		}
	}
	printf("%d\n",(int)steps.size());
	for(int i=0;i<(int)steps.size();i++){
		printf("%d %d\n",steps[i].first,steps[i].second);
	}
}

