#include<bits/stdc++.h>
using namespace std;
int t,cntc,ans;
bool odda[128],oddc[128];
string s;			
string AB;
bool ok(int end){
	for(int i=0;i<=end;i+=AB.size())
		if(s.substr(i,AB.size())!=AB)
			return 0;
	return 1;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>s;
		ans=0;
		cntc=0;
		memset(oddc,0,sizeof(oddc));
		for(int i=s.size()-1;i>=2;i--){
			if(oddc[s[i]])
				cntc--;
			else
				cntc++;
			oddc[s[i]]^=1;
			for(int j=1;j*j<=i;j++)
				if(i%j==0){
					AB=s.substr(i-j,j);
					if(AB.size()>1&&ok(i-AB.size())){						
						memset(odda,0,sizeof(odda));
						int cnta=0;
						for(int k=0;k<AB.size()-1;k++){
							if(odda[s[k]])
								cnta--;
							else
								cnta++;
							odda[s[k]]^=1;		
							if(cnta<=cntc)		
								ans++;				
						}				
					}
					if(j*j!=i){
						int jj=i/j;
						AB=s.substr(i-jj,jj);					
						if(AB.size()>1&&ok(i-AB.size())){
							memset(odda,0,sizeof(odda));
							int cnta=0;
							for(int k=0;k<AB.size()-1;k++){
								if(odda[s[k]])
									cnta--;
								else
									cnta++;
								odda[s[k]]^=1;		
								if(cnta<=cntc)		
									ans++;			
							}				
						}						
					}
				}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

