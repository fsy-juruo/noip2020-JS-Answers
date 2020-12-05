#include <bits/stdc++.h>

using namespace std;

const int MOD=1e9+7;

int n,k,ans;
int w[15],fact[15],maxfact[15],minfact[15],walkd[500005],walkw[500005],now[15];

bool ok(){
	for (int i=1;i<=k;i++){
		if(now[i]+maxfact[i]>w[i] || now[i]+minfact[i]<1){
			return false;
		}
	}
	return true;
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d %d",&n,&k);
	for (int i=1;i<=k;i++){
		scanf("%d ",&w[i]);
	}
	for (int i=1;i<=n;i++){// how to walk
		//int x;int y;
		scanf("%d %d",&walkd[i],&walkw[i]);
		fact[walkd[i]]+=walkw[i];
		maxfact[walkd[i]]=max(maxfact[walkd[i]],fact[walkd[i]]);
		minfact[walkd[i]]=min(minfact[walkd[i]],fact[walkd[i]]);
	}//if -1
	//for (int i=1;i<=k;i++){
	//	cout << fact[i] << " " << maxfact[i] << " " << minfact[i] << endl;
	//}
	//return 0;
	int f=-1;
	for (int i=1;i<=k;i++){
		if(fact[i]!=0){
			f=1;
			break;
		}
		if(maxfact[i]>=w[i] || -minfact[i]>=w[i]){
			f=1;
			break;
		}
	}
	if(f==-1){
		printf("-1");
		return 0;
	}//
	if(k==1){
		for (int i=1;i<=w[1];i++){//i-
			now[1]=i;
			while(ok()){
				ans+=n;
				now[1]+=fact[1];
				ans%=MOD;
			}
			for (int i=1;i<=n;i++){
				if(now[1]+walkw[i]<1 || now[1]+walkw[i]>w[1]){
					ans++;
					break;
				}else{
					now[1]+=walkw[i];
					ans++;
				}
			}
		}
	}
	if(k==2){
		for (int w1=1;w1<=w[1];w1++){
			for (int w2=1;w2<=w[2];w2++){
				now[1]=w1;
				now[2]=w2;
				while(ok()){
					ans+=n;
					ans%=MOD;
					cout << ans << endl;
					now[1]+=fact[1];
					now[2]+=fact[2];
				}
				for (int i=1;i<=n;i++){
					if(now[walkd[i]]+walkw[i]>w[i] || now[walkd[i]]+walkw[i]<1){
						ans++;
						break;		
					}else{
						ans++;
						now[walkd[i]]+=walkw[i];
					}
				}
				//cout << w1 << " " << w2 << " " << ans << endl;
			}
		}
	}
	if(k==3){
		for (int w1=1;w1<=w[1];w1++){
			for (int w2=1;w2<=w[2];w2++){
				for (int w3=1;w3<=w[3];w3++){
					now[1]=w1;
					now[2]=w2;
					now[3]=w3;
					while(ok()){
						ans+=n;
						ans%=MOD;
						now[1]+=fact[1];
						now[2]+=fact[2];
						now[3]+=fact[3];
					}
					for (int i=1;i<=n;i++){
						if(now[walkd[i]]+walkw[i]>w[i] || now[walkd[i]]+walkw[i]<1){
							ans++;
							break;
						}else{
							now[walkd[i]]+=walkw[i];
							ans++;
						}
					}
				}
			}
		}
	}
	if(k==4){
		for (int w1=1;w1<=w[1];w1++){
			for (int w2=1;w2<=w[2];w2++){
				for (int w3=1;w3<=w[3];w3++){
					for (int w4=1;w4<=w[4];w4++){
						now[1]=w1;
						now[2]=w2;
						now[3]=w3;
						now[4]=w4;
						while(ok()){
							ans+=n;
							ans%=MOD;
							now[1]+=fact[1];
							now[2]+=fact[2];
							now[3]+=fact[3];
							now[4]+=fact[4];
						}
						for (int i=1;i<=n;i++){
							if(now[walkd[i]]+walkw[i]>w[i] || now[walkd[i]]+walkw[i]<1){
								ans++;
								break;
							}else{
								now[walkd[i]]+=walkw[i];
								ans++;
							}
						}
					}
				}
			}
		}
	}
	if(k==5){
		for (int w1=1;w1<=w[1];w1++){
			for (int w2=1;w2<=w[2];w2++){
				for (int w3=1;w3<=w[3];w3++){
					for (int w4=1;w4<=w[4];w4++){
						for (int w5=1;w5<=w[5];w5++){
							now[1]=w1;
							now[2]=w2;
							now[3]=w3;
							now[4]=w4;
							now[5]=w5;
							while(ok()){
								ans+=n;
								ans%=MOD;
								now[1]+=fact[1];
								now[2]+=fact[2];
								now[3]+=fact[3];
								now[4]+=fact[4];
								now[5]+=fact[5];
							}
							for (int i=1;i<=n;i++){
								if(now[walkd[i]]+walkw[i]>w[i] || now[walkd[i]]+walkw[i]<1){
									ans++;
									break;
								}else{
									now[walkd[i]]+=walkd[i];
									ans++;
								}
							}
						}
					}
				}
			}
		}
	}
	printf("%d",ans);
	return 0;
} 
