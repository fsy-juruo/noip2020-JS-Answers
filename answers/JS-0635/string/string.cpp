#include<cstdio>
#include<cstring>
using namespace std;
int T,n,i,j,k,str[1000001],maxh[1000001],jiq[1000001],jih[1000001],gs[27],ans;
char r[1000001];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans=0;
		for(i=1;i<=n;i++)
		jiq[i]=0;
		for(i=1;i<=n;i++)
		jih[i]=0;
		for(i=1;i<=n;i++)
		maxh[i]=0;
		scanf("%s",&r);
		n=strlen(r);
		for(i=0;i<=n-1;i++)str[i]=r[i]-'a'+1;
//		for(i=1;i<=n;i++)printf("%d ",str[i]);
//		printf("\n");
		for(i=1;i<=26;i++)
		gs[i]=0;
		for(i=0;i<=n-1;i++){
			jiq[i]=jiq[i-1];
			gs[str[i]]++;
			if(gs[str[i]]%2==1)jiq[i]++;
			else jiq[i]--;
		}
		for(i=1;i<=26;i++)
		gs[i]=0;
		for(i=n-1;i>=0;i--){
			jih[i]=jih[i+1];
			gs[str[i]]++;
			if(gs[str[i]]%2==1)jih[i]++;
			else jih[i]--;
		}
		for(i=0;i<=n-1;i++){
		for(j=i+1;j<=n-1;j++)
			if(str[j%(i+1)]!=str[j])break;
			if(j>n-1)j=n-1;
			maxh[i]=j/(i+1);
		}
		//main part
		for(i=1;i<=n-2;i++)
		for(j=0;j<=i-1;j++)
		for(k=1;k<=maxh[i];k++)
		if(jiq[j]<=jih[(i+1)*k]){
			ans++;
		}
		printf("%d\n",ans);	
/*		for(i=0;i<=n-1;i++)
		printf("%d ",jiq[i]);
		printf("\n");
		for(i=0;i<=n-1;i++)
		printf("%d ",maxh[i]);
		printf("\n");*/
	}
	return 0;
}/*
A:0~j
b:j+1~i
c:i*gs+1~n
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
