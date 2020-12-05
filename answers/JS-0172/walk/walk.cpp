#include<bits/stdc++.h>
using namespace std;

const int maxn=500005,mod=1000000007;
int n,k;
int w[15];
int c[maxn],d[maxn];
int maxchange[15],minchange[15],prochange[maxn];//¼Ó¼õ
int nowp[15],nowpp[15];
int cnt=0;

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=k;i++)  cin>>w[i];
	for(int i=1;i<=n;i++)  cin>>c[i]>>d[i];
	for(int i=1;i<=n;i++){
		prochange[c[i]]+=d[i];
		if(prochange[c[i]]>maxchange[c[i]])  maxchange[c[i]]=prochange[c[i]];
		else if(prochange[c[i]]<minchange[c[i]])  minchange[c[i]]=prochange[c[i]];
	}
	bool f=0;
	for(int i=1;i<=k;i++)
		if(prochange[i]!=0){
			f=1;
			break;
		}
	if(f==0){
		for(int i=1;i<=k;i++){
			int tmpchange=maxchange[i]+(-minchange[i]);
			if(tmpchange>=w[i]){
				cout<<-1;
				return 0;
			}
		}
	}
	
	for(int i=1;i<=12;i++)  nowp[i]=1;
	while(nowp[k+1]==1){
		for(int i=1;i<=k;i++)  nowpp[i]=nowp[i];
		while(1){
			bool f=0;
			for(int i=1;i<=n;i++){
				nowpp[c[i]]+=d[i];
				cnt=(cnt+1)%mod;
				if(nowpp[c[i]]<=0 || nowpp[c[i]]>w[c[i]]){
					f=1;
					break;
				}
			}
			if(f)  break;
		}
		
		int j=1;
		while(1){
			if(nowp[j]==w[j]){
				nowp[j]=1;
				j++;
			}
			else break;
		}
		nowp[j]++;
	}
	
	cout<<cnt<<endl;
	
	return 0;
}
