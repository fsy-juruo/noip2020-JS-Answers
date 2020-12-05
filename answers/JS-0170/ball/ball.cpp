#include<bits/stdc++.h>
using namespace std;
int n,m,a[55][405],s[55][55],h[55],ts,th,tw,k,ans[820005][2],hash[55];
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		h[i]=m;
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}		
	while(1){
		for(int i=1;i<=n;i++){
			bool ok=false;
			if(h[i]!=0)for(int j=1;j<=m;j++){
				if(a[i][j]!=a[i][j-1]){
					s[i][a[i][j-1]]=0;
					ok=true;
				}
				s[i][a[i][j]]++;
			}
			if(ok==false&&h[i]==m)hash[i]=1;
		}
		int maxs=0,maxs2=0;
		for(int i=1;i<=n+1;i++){
			if(h[i]==0)th=i;
			else if(s[i][a[i][m]]>maxs){
				maxs=s[i][a[i][m]];
				ts=i;
			}
		}
		for(int i=1;i<=maxs;i++){
			a[th][i]=a[ts][m-i+1];
			a[ts][m-i+1]=0;
			k++;
			ans[k][0]=ts;
			ans[k][1]=th;
		}
		h[ts]=h[ts]-maxs;
		h[th]=h[th]+maxs;
		s[th][a[th][1]]=maxs;
		for(int i=1;i<=m-maxs;i++){
			if(a[ts][i]!=a[s][i-1])s[ts][a[ts][i-1]]=0;
			s[ts][a[ts][i]]++;
		}
		for(int i=1;i<=n;i++)
			if(i!=ts&&i!=th&&hash[i]==0)tw=i;
		int top=m;
		for(int i=1;i<=n;i++){
			if(i!=tw){
				if(a[i][h[i]]==a[tw][top]&&h[i]<){
					if(maxs2<s[i][a[i][h[i]]]){
						maxs2=s[i][a[i][h[i]]];
						ts=i;
					}
				}
			}
		}
		if(maxs2==0)for(int i=1;i<=n;i++)if(i!=tw&&)
	}
	return 0;
}
