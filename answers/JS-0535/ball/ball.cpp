#include<bits/stdc++.h>
#define F(i,a,b) for (int i=a;i<=b;i++)
#define DF(i,a,b) for (int i=a;i>=b;i--)
#define ms(a,b) memset(a,b,sizeof a)
#define LL long long
#define pb push_back
#define SZ(x) (int)x.size()-1
using namespace std;
inline int read(){
	int w=1,c=0; char ch=getchar();
	for (;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for (;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int N=55,M=404;
struct node{
	int x,y;
}ans[N*N*M];
int cnt;
int n,m,a[N][M],tp[N],num[N][N],col[N];
void move(int x,int y){
//	cout<<x<<" -> "<<y<<" "<<tp[x]<<" "<<tp[y]<<"\n";
	int o=a[x][tp[x]];
	tp[x]--;
	num[x][o]--;
	num[y][o]++;
	tp[y]++;
	a[y][tp[y]]=o;
	if (tp[x]<0 || tp[y]>m){
		puts("ERROR");
		exit(0);
	}
	ans[++cnt]=(node){x,y};
}
int rcol[N],len[N];
void work(int x){
//	cout<<x<<" "<<len[x]<<" "<<col[x]<<"   fuck \n";
//	int gg=num[x][col[x]]-len[x];
	F(i,1,n){
		if (i!=col[x]){
			F(j,1,num[x][i]){
				move(rcol[i],n+1);
			}
		}
	}
	F(i,1,m-len[x]){
		int tar=a[x][tp[x]];
		tar=rcol[tar];
		if (tar==x) move(x,n+1);
		else move(x,tar);
	}
	F(i,1,m-len[x]){
		move(n+1,x);
	}
	F(i,1,n){
		while (a[i][len[i]+1]==col[i]) len[i]++;
	}
}
int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read(); m=read();
	F(i,1,n){
		F(j,1,m){
			a[i][j]=read();
			tp[i]=j;
			num[i][a[i][j]]++;
		}
	}
	F(i,1,n){
		int mxp=0;
		F(j,1,n){
			if (col[j]) continue;
			if (num[j][i]>num[mxp][i]) mxp=j;
		}
		col[mxp]=i;
		rcol[i]=mxp;
		len[mxp]=0;
		while (a[mxp][len[mxp]+1]==i) len[mxp]++;
	}
	while (1){
		int pos=1,milen=len[1];
		for (int i=2;i<=n;i++){
			if (num[i][col[i]]-len[i]>num[pos][col[pos]]-len[pos]) pos=i;
			else{
				if (num[i][col[i]]-len[i]==num[pos][col[pos]]-len[pos] && len[pos]>len[i])
				pos=i;
			}
			milen=min(milen,len[i]);
		}
		if (milen==m) break;
		work(pos);
	}
	cout<<cnt<<"\n";
	F(i,1,cnt){
		cout<<ans[i].x<<" "<<ans[i].y<<"\n"; 
	}
//	F(i,1,n){
//		F(j,1,m){
////			cout<<a[i][j]<<" ";
//			assert(a[i][j]==col[i]);
//		}
////		cout<<"\n"; 
//	}
	return 0;
}
/*
2 3
1 1 2
2 1 2
*/
