#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=(1<<20)+10;
int T,n,cnt[30],a[N],b[N],c[N],f[N],ans;
char st[N];
void Add(int x,int y){
	for(;x<=n;x+=x&(-x)) c[x]+=y;
}
LL Ask(int x){
	int sum=0;
	for(;x;x-=x&(-x)) sum+=c[x];
	return sum;
}
int xun[N];
void Find(int m){
	memset(xun,0,sizeof(xun));
	int k=2;
	while(k<=m){//循环节长度 
		int t=1,i=0,j=k-1;
		while(st[i]==st[j]&&j<n&&m%k==0){
			i++,j++;
			if(i==k){
				i=0,t++;
			}
		}
		if(t*k==m&&t>1){
			xun[++xun[0]]=k;
		}
		for(int ii=1;i<=m;++i){
			for(int jj=1;jj<=xun[0];++jj){
				if(xun[jj]%2==0&&i%xun[jj]==0){
					for(int kk=2;kk<=i%xun[jj];++kk)
						Add(a[ii]+1,1);
				}
			}
		}
		k=k+1;
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		scanf("%s",st);
		n=strlen(st);
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		memset(f,0,sizeof(f));
		for(int i=0;i<n;++i){//a: 1~i  多少个奇数 
			int j=st[i]-'a'+1;
			if(cnt[j]%2==1) a[i+1]=a[i]-1,cnt[j]+=1;
			else a[i+1]=a[i]+1,cnt[j]+=1;
		}
		memset(cnt,0,sizeof(cnt));
		for(int i=n-1;i>=0;--i){//b: i~n  多少个奇数  
			int j=st[i]-'a'+1;
			if(cnt[j]%2==1) b[i+1]=b[i+2]-1,cnt[j]+=1;
			else b[i+1]=b[i+2]+1,cnt[j]+=1;
		}
		for(int i=1;i+2<=n;++i){//f[i] 1~i中a[j] 比 b[i+2]大的个数 
			Add(a[i]+1,1);
			Find(i+1);
			ans+=Ask(b[i+2]+1);
		}
		 
		cout<<ans<<endl;
	}
	return 0;
}

