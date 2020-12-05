#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,P=1e9+7;
int n,k,x[N],y[N],w[11],d[11];
map<int,int> m[11];
long long ans;
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)scanf("%d",&w[i]);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&x[i],&y[i]);
		d[x[i]]+=y[i];
		if(!m[x[i]].count(d[x[i]]))
			m[x[i]][d[x[i]]]=i;
	}
	bool flag=0;
	for(int i=1;i<=k;i++)if(d[i]||(n>=w[i]&&!m[i].count(w[i]))){
		flag=1;
		break;
	}
	if(!flag){
		printf("-1");
		return 0;
	}
	if(n<=100){
		int pos[6],poss[6];
		if(k==1){
			for(pos[1]=1;pos[1]<=w[1];pos[1]++){
				flag=0;
				for(int i=1;i<=k;i++)poss[i]=pos[i];
				while(1){
					for(int i=1;i<=n;i++){
						poss[x[i]]+=y[i];
						ans++;
						if(poss[x[i]]>w[x[i]]||poss[x[i]]<=0){
							flag=1;
							break;
						}
					}
					if(flag)break;
				}
			}
		}
		else if(k==2){
			for(pos[1]=1;pos[1]<=w[1];pos[1]++)for(pos[2]=1;pos[2]<=w[2];pos[2]++){
				flag=0;
				for(int i=1;i<=k;i++)poss[i]=pos[i];
				while(1){
					for(int i=1;i<=n;i++){
						poss[x[i]]+=y[i];
						ans++;
						if(poss[x[i]]>w[x[i]]||poss[x[i]]<=0){
							flag=1;
							break;
						}
					}
					if(flag)break;
				}
			}
		}
		else if(k==3){
			for(pos[1]=1;pos[1]<=w[1];pos[1]++)for(pos[2]=1;pos[2]<=w[2];pos[2]++)for(pos[3]=1;pos[3]<=w[3];pos[3]++){
				flag=0;
				for(int i=1;i<=k;i++)poss[i]=pos[i];
				while(1){
					for(int i=1;i<=n;i++){
						poss[x[i]]+=y[i];
						ans++;
						if(poss[x[i]]>w[x[i]]||poss[x[i]]<=0){
							flag=1;
							break;
						}
					}
					if(flag)break;
				}
			}
		}
		else if(k==4){
			for(pos[1]=1;pos[1]<=w[1];pos[1]++)for(pos[2]=1;pos[2]<=w[2];pos[2]++)for(pos[3]=1;pos[3]<=w[3];pos[3]++)for(pos[4]=1;pos[4]<=w[4];pos[4]++){
				flag=0;
				for(int i=1;i<=k;i++)poss[i]=pos[i];
				while(1){
					for(int i=1;i<=n;i++){
						poss[x[i]]+=y[i];
						ans++;
						if(poss[x[i]]>w[x[i]]||poss[x[i]]<=0){
							flag=1;
							break;
						}
					}
					if(flag)break;
				}
			}
		}
		else if(k==5){
			for(pos[1]=1;pos[1]<=w[1];pos[1]++)for(pos[2]=1;pos[2]<=w[2];pos[2]++)for(pos[3]=1;pos[3]<=w[3];pos[3]++)for(pos[4]=1;pos[4]<=w[4];pos[4]++)for(pos[5]=1;pos[5]<=w[5];pos[5]++){
				flag=0;
				for(int i=1;i<=k;i++)poss[i]=pos[i];
				while(1){
					for(int i=1;i<=n;i++){
						poss[x[i]]+=y[i];
						ans++;
						if(poss[x[i]]>w[x[i]]||poss[x[i]]<=0){
							flag=1;
							break;
						}
					}
					if(flag)break;
				}
			}
		}
		printf("%lld",ans%P);
	}
	else if(n<=1e5){
		if(k==1){
			for(int i=1;i<=w[1];i++){
				if(m[1].count(-i)){
					if(m[1].count(w[1]-i+1)){
						ans+=min(m[1][-i],m[1][w[1]-i+1])%P;
					}
					else ans+=m[1][-i]%P;
				}
				else if(m[1].count(w[1]-i+1))ans+=m[1][w[1]-i+1]%P;
				else{
					int l=1,r=w[1]/abs(d[1])+1,mid,pos,res;
					while(l<=r){
						mid=(l+r)/2;
						pos=i+d[1]*mid;
						if(pos>w[1]||pos<=0)r--;
						else if(m[1].count(-pos)||m[1].count(w[1]-pos+1)){
							res=pos;
							l=mid+1;
						}
						else r=mid-1;
					}
					ans+=abs(res-i)/abs(d[1])*n%P;
					if(m[1].count(-res)){
						if(m[1].count(w[1]-res+1)){
							ans+=min(m[1][-res],m[1][w[1]-res+1])%P;
						}
						else ans+=m[1][-res]%P;
					}
					else if(m[1].count(w[1]-res+1))ans+=m[1][w[1]-res+1]%P;
					ans%=P;
				}
			}
			printf("%lld",ans%P);
		}
		else printf("-1");
	}
	else{
		printf("-1");
	}
	return 0;
}
