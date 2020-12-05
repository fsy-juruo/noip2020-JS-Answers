#include<bits/stdc++.h>
#define N 500010
#define ll long long
#define mod 1000000007 
#define DEBUG printf("vzyx and tqzer AK!\n")

//goodbye,OI.
using namespace std;

inline ll read() {
	ll w=1,x=0;
	char ch=0;
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return w*x;
}

int n,k,c[N],d[N];
ll w[N];

namespace subtask1{
	bool vh[10][10][10][10][10][10];
	void work() {
		ll cnt=0;
		bool flag=true;
		if(k==1) {
			for(int i=1;i<=w[1];i++) {
				int pos=i,day=0;
				memset(vh,false,sizeof(vh));
				while(1) {
					cnt++;
					if(cnt>=mod) cnt%=mod;
					day++;
					if(day==n+1) day=1;
					pos+=d[day];
					if(vh[day][pos][0][0][0][0]) {
						flag=false;
						break;
					}
					vh[day][pos][0][0][0][0]=true;
					if(pos==0||pos==w[1]+1) break;
				}
				if(!flag) break;
			}
			if(flag) printf("%lld\n",cnt);
			else printf("-1\n");
		}
		else if(k==2) {
			for(int i=1;i<=w[1];i++) 
			for(int j=1;j<=w[2];j++) {
				int pos[2],day=0;
				memset(vh,false,sizeof(vh));
				pos[0]=i,pos[1]=j;
				while(1) {
					cnt++;
					if(cnt>=mod) cnt%=mod;
					day++;
					if(day==n+1) day=1;
					pos[c[day]-1]+=d[day];
					if(vh[day][pos[0]][pos[1]][0][0][0]) {
						flag=false;
						break;
					}
					vh[day][pos[0]][pos[1]][0][0][0]=true;
					if(pos[0]==0||pos[0]==w[1]+1||pos[1]==0||pos[1]==w[2]+1) break;
				}
				if(!flag) break;
			}
			if(flag) printf("%lld\n",cnt);
			else printf("-1\n");
		}
		else if(k==3) {
			for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
			for(int k=1;k<=w[3];k++) {
				int pos[3],day=0;
				memset(vh,false,sizeof(vh));
				pos[0]=i,pos[1]=j,pos[2]=k;
				while(1) {
					cnt++;
					if(cnt>=mod) cnt%=mod;
					day++;
					if(day==n+1) day=1;
					pos[c[day]-1]+=d[day];
					if(vh[day][pos[0]][pos[1]][pos[2]][0][0]) {
						flag=false;
						break;
					}
					vh[day][pos[0]][pos[1]][pos[2]][0][0]=true;
					if(pos[0]==0||pos[0]==w[1]+1||pos[1]==0||pos[1]==w[2]+1||pos[2]==0||pos[2]==w[3]+1) break;
				}
			}
			if(flag) printf("%lld\n",cnt);
			else printf("-1\n");
		}
		else if(k==4) {
			for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
			for(int k=1;k<=w[3];k++)
			for(int a=1;a<=w[4];a++) {
				int pos[4],day=0;
				memset(vh,false,sizeof(vh));
				pos[0]=i,pos[1]=j,pos[2]=k,pos[3]=a;
				while(1) {
					cnt++;
					if(cnt>=mod) cnt%=mod;
					day++;
					if(day==n+1) day=1;
					pos[c[day]-1]+=d[day];
					if(vh[day][pos[0]][pos[1]][pos[2]][pos[3]][0]) {
						flag=false;
						break;
					}
					vh[day][pos[0]][pos[1]][pos[2]][pos[3]][0]=true;
					if(pos[0]==0||pos[0]==w[1]+1||pos[1]==0||pos[1]==w[2]+1||pos[2]==0||pos[2]==w[3]+1||pos[3]==0||pos[3]==w[4]+1) break;
				}
			}
			if(flag) printf("%lld\n",cnt);
			else printf("-1\n");
		}
		else if(k==5) {
			for(int i=1;i<=w[1];i++)
			for(int j=1;j<=w[2];j++)
			for(int k=1;k<=w[3];k++)
			for(int a=1;i<=w[4];a++)
			for(int b=1;b<=w[5];b++) {
				int pos[5],day=0;
				memset(vh,false,sizeof(vh));
				pos[0]=i,pos[1]=j,pos[2]=k,pos[3]=a,pos[4]=b;
				while(1) {
					cnt++;
					if(cnt>=mod) cnt%=mod;
					day++;
					if(day==n+1) day=1;
					pos[c[day]-1]+=d[day];
					if(vh[day][pos[0]][pos[1]][pos[2]][pos[3]][pos[4]]) {
						flag=false;
						break;
					}
					vh[day][pos[0]][pos[1]][pos[2]][pos[3]][pos[4]]=true;
					if(pos[0]==0||pos[0]==w[1]+1||pos[1]==0||pos[1]==w[2]+1||pos[2]==0||pos[2]==w[3]+1||pos[3]==0||pos[3]==w[4]+1||pos[4]==0||pos[4]==w[5]+1) break;
				}
			}
			if(flag) printf("%lld\n",cnt);
			else printf("-1\n");
		}
	}
}

int main() {
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n=read(),k=read();
	for(int i=1;i<=k;i++) w[i]=read();
	for(int i=1;i<=n;i++) c[i]=read(),d[i]=read();
	
	if(k==1) {
		ll cnt1=0;
		int now=1,day=0;
		while(1) {
			cnt1++;
			if(cnt1>=mod) cnt1%=mod;
			day++;
			if(day==n+1) day=1;
			now+=d[day];
			if(now==0||now==w[1]+1) break;
		}
		ll cnt2=0;
		now=w[1],day=0;
		while(1) {
			cnt2++;
			if(cnt2>=mod) cnt2%=mod;
			day++;
			if(day==n+1) day=1;
			now+=d[day];
			if(now==0||now==w[1]+1) break;
		}
		ll ans=((cnt1+cnt2)*w[1])/2;
		printf("%lld\n",ans);
	}
	else if(n<=5) subtask1::work();
	else if(k>3&&n>=100000) printf("-1\n");
	
	return 0;
}
