#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int T,n,Z[2001000],mas[2001000],sum[30],CN,BN;
ll res;
char s[2001000];
int COUNT(int ip){
	int ret=0;
	while(ip)ret+=ip&1,ip>>=1;
	return ret;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%s",s),n=strlen(s),memset(sum,0,sizeof(sum)),res=CN=BN=0;
		mas[0]=1<<(s[0]-'a');
		for(int i=1;i<n;i++)mas[i]=mas[i-1]^(1<<(s[i]-'a'));
		CN=COUNT(mas[n-1]);
		int Centre=-1,Rpos=-1;
		for(int i=1;i<n;i++){
			if(i<=Rpos)Z[i]=min(Z[i-Centre],Rpos-i+1);
			else Z[i]=0;
			while(i+Z[i]<n&&s[Z[i]]==s[i+Z[i]])Z[i]++;
			if(i+Z[i]>Rpos)Centre=i,Rpos=i+Z[i]-1;
		}
//		for(int i=1;i<n;i++)printf("%d ",Z[i]);puts("");
		for(int i=1;i<n;i++){
			int C1=mas[n-1]^mas[i-1];
			C1=COUNT(C1);
			int tot=min(Z[i],n-i-1)/i+1;
			int N1=(tot+1)>>1,N2=(tot)>>1;
//			printf("%d:%d %d\n",tot,N1,N2);
			for(int j=0;j<=C1;j++)res+=1ll*sum[j]*N1;
			sum[COUNT(mas[i-1])]++;
			res+=1ll*BN*N2;
			if(COUNT(mas[i-1])<=CN)BN++;
		}
		printf("%lld\n",res);
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

5
kkkkkkkkkkkkkkkkkkkk
lllllllllllllrrlllrr
cccccccccccccxcxxxcc
ccccccccccccccaababa
ggggggggggggggbaabab
*/
