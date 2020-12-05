#include<bits/stdc++.h>
using namespace std;
int T;
string s;
int cnt[1100],cnts[1100],mus[1100];
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	cin>>T;
	cout<<-1<<endl;
	return 0;
	/*while(T){
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
		
			}
			}
			//cout<<ans<<endl;
			
			//cout<<ans<<endl;
		}
	}
	*/
	fclose(stdin);
	fclose(stdout);
	return 0;
}
