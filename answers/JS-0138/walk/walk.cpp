#include<bits/stdc++.h>
using namespace std;
int a[11],wis[11],try1,wi[11],ni[500001][2],ans,bu[11];
int panbi(int k){
	for(int i=1;i<=k;i++)
		if(a[i]!=wis[i])
			return 0;
	return 1;
}
void xiug(int k)
{
	for(int i=k;i>=1;i++){
		wis[i]++;
		if(wis[i]==wi[i])
		{
			if(i-1==0) {
				try1=1;
				break;
			}
			wis[i-1]++;
			wis[i]=0;
		}
		else if(i==k)
			break;
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	int n,k,ak=0,ks=1;
	memset(wis,1,sizeof(wis));
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&wi[i]);
	for(int i=1;i<=n;i++)
		scanf("%d%d",&ni[i][0],&ni[i][1]);
	while(ks&&!try1){
		for(int i=1;i<=k;i++)
			a[i]=wis[i];
		int i=1;
		while((a[ni[i][0]]+ni[i][1]<=wi[ni[i][0]])&&(a[ni[i][0]]+ni[i][1]>=1)) {
			ans++;
			a[ni[i][0]]+=ni[i][1];
			if(i==n&&panbi(k)) {
				ks=0;
				ak=1;
				break;
			}
			if(i==n) i=0;
			i++;
		}
		ans++;
		xiug(k);
	}
	if(ak) printf("-1\n");
	else printf("%d\n",ans);
	return 0;
}
