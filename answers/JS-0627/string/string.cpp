#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int cnt[1100],cnts[1100],mus[1100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>T;
	while(T){
		T--;
		int ans=0;
		memset(cnt,0,sizeof(cnt));
		memset(cnts,0,sizeof(cnts));
		memset(mus,0,sizeof(mus));
		cin>>s;
		for(int i=0;i<s.size();++i){
			cnts[s[i]]++;
			if(cnts[s[i]]%2==1)
			mus[i]=mus[i-1]+1;
			else 
			mus[i]=mus[i-1]-1;
			//cout<<mus[i]<<" ";
		}
		char c[11000];
		int mu=0;
		for(int i=0;i<s.size()-2;++i){
			int k=s.size()-i-1;
			int cn[11000],num=0;
			c[i]=s[k];
			cnt[c[i]]++;
			if(cnt[c[i]]%2==1)
			mu++;
			if(cnt[c[i]]%2==0)
			mu--;
			//cout<<mu<<"|";
			//cout<<k<<" ";
			for(int j=2;j*j<k;++j){
				if(k%j==0) {
					num++;
					cn[num]=j;
					if(k/j!=j){
					num++;
					cn[num]=k/j;
					}
				}
				
			}
			
			for(int j=1;j<=num;++j){
			bool flag=true;
			for(int oi=0;oi<cn[j];++oi){
				for(int o=2;o<=k/cn[j];++o){
				if(s[cn[j]*(o-1)+oi]!=s[oi]){
					flag=false;
					break;
				}
			}	
			if(!flag) break;
			}
		//	cout<<ans<<endl;
			if(flag){
				for(int p=0;p<cn[j]-1;++p){
					if(mus[p]<=mu){
					//cout<<cn[j]<<"|"<<p<<" ";
					ans++;	
				}
				}	
			}
			}
			//cout<<ans<<endl;
			for(int j=0;j<k-1;++j){
				if(mus[j]<=mu) {
				//cout<<j<<" ";
				ans++;	
				}
			}
			//cout<<ans<<endl;
		}
		cout<<ans<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
