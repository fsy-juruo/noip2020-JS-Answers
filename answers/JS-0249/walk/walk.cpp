#include<bits/stdc++.h>
using namespace std;
typedef long long ak;
#define im (ak)666666666666666
#define F(i,j,k) for(int i=j;i<=k;i++)
#define G(i,j,k) for(int i=j;i>=k;i--)
ak n,k,ans=0,a[1111111],cur[1111111],wei[1111111],sz[1111111],posi[1111111],d[1111111],zuo[1111111],you[1111111],mov,mx=0,mn=0,mxstep=0,mnstep=0,jie,pl;//way[i]:the dimension to operate on in ith order
void play(){
	F(i,1,n)cur[i]=posi[i];
	F(i,1,im){
		F(j,1,n){
			cur[wei[j]]+=d[j];ans++;
			if(cur[wei[j]]<1||cur[wei[j]]>sz[wei[j]])
				return;
		}
		int f=0;F(i,1,k)if(cur[i]!=posi[i])f=1;
		if(!f){cout<<"-1\n";exit(0);}
	}
}
void dfs(int dep){
	if(dep>k)play();
	F(i,1,sz[dep])posi[dep]=i,dfs(dep+1);
}
bool cxk(ak bu){
	if(!bu)return 1;
	ak now=pl+bu*mov-mov;if(now<1||now>jie)return 0;
	return now+mx<=jie&&now+mn>0;
}
ak bz(ak k,ak p){
	return p?(cxk(k+p)?bz(k+p,p<<1):bz(k,p>>1)):k;
}
bool cxk2(ak bu){
	if(pl+you[bu]>jie||pl+zuo[bu]<1)return 0;
	return 1;
}
ak bz2(ak k,ak p){
	return p?(cxk2(k+p)?bz2(k+p,p<<1):bz2(k,p>>1)):k;
}
void play1(){
	ak sz,cur=0;cin>>sz;F(i,1,n)cin>>a[i]>>a[i];
	F(i,1,n){
		cur+=a[i];if(cur>mx)mx=cur,mxstep=i;
		if(cur<mn)mn=cur,mnstep=i;
		you[i]=max(mx,you[i-1]);
		zuo[i]=min(mn,zuo[i-1]);
	}
	if(!cur){
		int f=0;F(i,1,n)if(i+mx<=sz||i+mn>0)f=1;
		if(f){cout<<"-1\n";exit(0);}
	}
	mov=cur;
	F(i,1,sz){
		jie=sz;pl=i;ak bs=bz(0,1);ans+=n*bs;
		cur=i+bs*mov;pl=cur;ans+=bz2(0,1)+1;
		
		
//		cout<<n*bs+bz2(0,1)<<"\n";
		
		
	}
	cout<<ans<<"\n";exit(0);
}
int main(){
	#ifndef lpcak
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	#endif
	
	ios::sync_with_stdio(0);
	cin>>n>>k;
	if(k>1&&n<=100){
		F(i,1,k)cin>>sz[i];F(i,1,n)cin>>wei[i]>>d[i];
		dfs(1);cout<<ans<<"\n";return 0;
	}
	if(k==1)play1();if(n>100)cout<<"-1\n";
	return 0;
}
/*

3 2
3 3
1 1
2 -1
1 1

5 4
6 8 6 5
3 1
2 1
1 1
2 1
2 -1

4 2
8 8
1 1
2 1
2 -1
1 -1

5 1
10
1 1
1 1
1 1
1 -1
1 -1

4 1
10
1 -1
1 -1
1 1
1 1

6 1
20
1 1
1 1
1 1
1 -1
1 1
1 -1

*/
