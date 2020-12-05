#include<bits/stdc++.h>
using namespace std;
int n,m;
struct Node{
	int x,y;
}ma[55][55];
int cnt[55];
int c[55];
bool cmp(Node a,Node b){
	return a.y>b.y;
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			int p;
			scanf("%d",&p);
			cnt[p]++;
			ma[p][cnt[p]].x=i;
			ma[p][cnt[p]].y=j;
		}
	}
	for(int i=1;i<=n;i++){
		sort(ma[i]+1,ma[i]+m+1,cmp);
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			cout<<ma[i][j].x<<" "<<ma[i][j].y<<endl;
//		}
//	}
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}
