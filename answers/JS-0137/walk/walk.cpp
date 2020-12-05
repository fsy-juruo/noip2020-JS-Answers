#include<bits/stdc++.h>
using namespace std;
const int base=1000000007;
int n,k,w[20],cnt,plu[11],l[11][500010],r[11][500010],c[500010],d[500010];
int fgoleft[11][500010],fgoright[11][500010];
bool key,vis[11];
int weishuchuli(int q,int i){
	int ans=0;
	int lnow=i;
	int rnow=w[q]-i+1;
	while(lnow>l[q][n]&&rnow>r[q][n]){
		lnow-=l[q][n];
		rnow-=r[q][n];
		ans+=n;
	}
	int tmp1=base;
	if(fgoleft[q][lnow]!=0) tmp1=fgoleft[q][lnow];
	int tmp2=base;
	if(fgoright[q][rnow]!=0) tmp2=fgoright[q][rnow];
	ans+=min(tmp1,tmp2);
	return ans%base;
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d%d",&c[i],&d[i]);
	}
	for(int i=1;i<=n;i++){
		plu[c[i]]+=d[i];
		for(int j=1;j<=k;j++){
			int kkk=0;
			if(plu[j]<0) kkk=abs(plu[j]);
			l[j][i]=max(l[j][i-1],kkk);
			r[j][i]=max(r[j][i-1],plu[j]);
			if(plu[j]>0){
				fgoright[j][0]=i-1;
			}
			if(plu[j]<0){
				fgoleft[j][0]=i-1;
			}
			if((!fgoleft[j][l[j][i]])&&l[j][i]!=0) fgoleft[j][l[j][i]]=i;
			if((!fgoright[j][r[j][i]])&&r[j][i]!=0) fgoright[j][r[j][i]]=i;
		}
	}
	//for(int i=1;i<=k;i++){
		//cout<<l[i][n]<<' '<<r[i][n]<<endl;
	//}
	for(int i=1;i<=k;i++){
		if(plu[i]!=0){
			key=true;
			break;
		}
	}
	if(!key){
		for(int i=1;i<=k;i++){
			if(l[i][n]+r[i][n]+1>w[i]){
				vis[i]=true;
				key=true;
			}
		}
	}
	if(!key){
		cout<<-1<<endl;
		return 0;
	}
	if(k==1){
		for(int i=1;i<=w[1];i++){
			cnt+=weishuchuli(1,i);
			cnt%=base;
		}
		printf("%d\n",cnt);
		return 0;
	}
	if(k==2){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				int tmp=base;
				if(!(plu[1]==0&&(!vis[1]))) tmp=min(tmp,weishuchuli(1,i));
				if(!(plu[2]==0&&(!vis[2]))) tmp=min(tmp,weishuchuli(2,j));
				cnt+=tmp;
				cnt%=base;
			}
		}
		printf("%d\n",cnt);
		return 0;
	}
	if(k==3){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int u=1;u<=w[3];u++){
					int tmp=base;
						if(!(plu[1]==0&&(!vis[1]))) tmp=min(tmp,weishuchuli(1,i));
						if(!(plu[2]==0&&(!vis[2]))) tmp=min(tmp,weishuchuli(2,j));
						if(!(plu[3]==0&&(!vis[3]))) tmp=min(tmp,weishuchuli(3,u));
						cnt+=tmp;
					    cnt%=base;
				}
			}
		}
		printf("%d\n",cnt);
		return 0;
	}
	if(k==4){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int u=1;u<=w[3];u++){
					for(int v=1;v<=w[4];v++){
						int tmp=base;
						if(!(plu[1]==0&&(!vis[1]))) tmp=min(tmp,weishuchuli(1,i));
						if(!(plu[2]==0&&(!vis[2]))) tmp=min(tmp,weishuchuli(2,j));
						if(!(plu[3]==0&&(!vis[3]))) tmp=min(tmp,weishuchuli(3,u));
						if(!(plu[4]==0&&(!vis[4]))) tmp=min(tmp,weishuchuli(4,v));
						cnt+=tmp;
					    cnt%=base;
					}
				}
			}
		}
		printf("%d\n",cnt);
		return 0;
	}
	if(k==5){
		for(int i=1;i<=w[1];i++){
			for(int j=1;j<=w[2];j++){
				for(int u=1;u<=w[3];u++){
					for(int v=1;v<=w[4];v++){
						for(int y=1;y<=w[5];y++){
							int tmp=base;
						if(!(plu[1]==0&&(!vis[1]))) tmp=min(tmp,weishuchuli(1,i));
						if(!(plu[2]==0&&(!vis[2]))) tmp=min(tmp,weishuchuli(2,j));
						if(!(plu[3]==0&&(!vis[3]))) tmp=min(tmp,weishuchuli(3,u));
						if(!(plu[4]==0&&(!vis[4]))) tmp=min(tmp,weishuchuli(4,v));
						if(!(plu[5]==0&&(!vis[5]))) tmp=min(tmp,weishuchuli(5,y));
						cnt+=tmp;
					    cnt%=base;
						}
					}
				}
			}
		}
		printf("%d\n",cnt);
		return 0;
	}
	cout<<-1<<endl;
	return 0;
}

