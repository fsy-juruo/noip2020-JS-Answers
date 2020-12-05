#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
typedef long long ll;
int n,m;
int a[55][405],sz[55];
int ax[1000005],ay[1000005],len;
void func(int x,int y){
//	cerr<<x<<" "<<y<<endl;
	len++;ax[len]=x;ay[len]=y;
	assert(sz[x]>0);
	assert(sz[y]<m);
	sz[y]++;
	a[y][sz[y]]=a[x][sz[x]];
	sz[x]--;
//	for(int i=1;i<=n+1;i++){
//		for(int j=1;j<=sz[i];j++)cerr<<a[i][j]<<" ";cerr<<endl;
//	}
//	cerr<<"---------"<<endl;
}
void solve(int x){
//	cerr<<"solve"<<x<<endl;
	int c=a[x][1];
	int to=1;
	while(to<sz[x]&&a[x][to+1]==c)to++;
	while(sz[x]>to){
		for(int i=x+1;i<=n+1;i++){
			if(sz[i]<m){
				func(x,i);
				break;
			}
		}
	}
	for(int i=x+1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(sz[j]<m){
				if(a[n+1][sz[n+1]]==c)func(n+1,x);
				else func(n+1,j);
			}
		}
		int tot=0;
		for(int j=1;j<=sz[i];j++)if(a[i][j]==c)tot++;
		if(!tot)continue;
		int cnt1=0,cnt2=0,cnt3=0;
//		cerr<<i<<" "<<sz[x]<<" "<<sz[i]<<" "<<sz[n+1]<<" "<<m-tot<<endl;
		while(sz[n+1]>m-tot)func(n+1,x),cnt1++;
		while(sz[n+1]<m-tot){
			if(a[i][sz[i]]==c){
				func(i,x);tot--;
			}else func(i,n+1);
		}
//		cerr<<i<<" "<<sz[x]<<" "<<sz[i]<<" "<<sz[n+1]<<" "<<m-tot<<endl;
		for(int j=sz[i];j>=1;j--){
//			if(x==24)cerr<<(a[i][j]==c)<<" "<<sz[x]<<" "<<sz[n+1]<<endl;
			if(a[i][j]==c)func(i,n+1),cnt3++;
			else func(i,x),cnt2++;
		}
//		cerr<<"end"<<endl;
		while(cnt2--)func(x,i);
//		cerr<<"here"<<" "<<cnt1<<" "<<cnt3<<endl;
		for(int j=1;j<=cnt1;j++)func(x,i);
		for(int j=1;j<=cnt3;j++)func(n+1,x);
		for(int j=1;j<=cnt1;j++)func(i,n+1);
//		cerr<<sz[i]<<" "<<sz[n+1]<<endl;
		while(sz[i]<m){
			if(a[n+1][sz[n+1]]==c)func(n+1,x);
			else func(n+1,i);
		}
	}
	int pos=x+1;
	while(sz[n+1]){
		while(sz[pos]==m)pos++;
		if(a[n+1][sz[n+1]]==c)func(n+1,x);
		else func(n+1,pos);
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
		sz[i]=m;
	}
	sz[n+1]=0;
	for(int i=1;i<n;i++){
		for(int j=i;j<=n;j++){
			while(sz[j]<m)func(n+1,j);
		}
		solve(i);
//		cerr<<"End"<<endl;
	}
	/*
	for(int j=1;j<=n;j++){
		while(sz[j]<m)func(n+1,j);
	}
	*/
//	for(int i=1;i<=n+1;i++){
//		for(int j=1;j<=sz[i];j++)cerr<<a[i][j]<<" ";cerr<<endl;
//	}
	printf("%d\n",len);
	for(int i=1;i<=len;i++){
		printf("%d %d\n",ax[i],ay[i]);
	}
	return 0;
}
