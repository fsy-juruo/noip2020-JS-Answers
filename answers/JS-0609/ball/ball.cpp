#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
const int maxn=100001;
int n,m,pan[52][401],cnt=1;
long long ans=0;
struct move {
	int bef, aft;
} mg[maxn];
inline long long read() {
	int f=1, x=0;
	char ch;
	do {
		ch=getchar();
		if(ch=='-')f=-1;
	} while(ch<'0'||ch>'9');
	do {
		x=x*10+ch-'0';
		ch=getchar();
	} while(ch>='0'&&ch<='9');
	return f*x;
}
inline void work(int x) {
	for(int i=1; i<=m-cnt; i++) {
		mg[++ans].bef =1;
		mg[++ans].aft =3;
	}
	for(int i=1; i<=m-x; i++) {
		mg[++ans].bef =2;
		mg[ans].aft =1;
	}
	mg[++ans].bef=2;
	mg[ans].aft =3;
	for(int i=1; i<=m-x; i++) {
		mg[++ans].bef =1;
		mg[ans].aft =2;
	}
	mg[++ans].bef=3;
	mg[ans].aft =1;
	for(int i=1; i<=m-cnt-1; i++) {
		mg[++ans].bef =3;
		mg[ans].aft =1;
	}
	mg[++ans].bef=3;
	mg[ans].aft =2;
}
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	n=read();
	m=read();
	if(n==2) {
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				pan[i][j]=read();
		while(cnt<n) {
			for(int i=1; i<m; i++) {
				{
					if(pan[1][cnt]==pan[2][i])
						work(i);
				}
			}
			cnt+=2;
		}
	}
	ans=ans%(mod);
	cout<<ans<<'\n';
	for(int i=1; i<=ans; i++)
		cout<<mg[i].bef<<" "<<mg[i].aft<<'\n';
	return 0;
}
