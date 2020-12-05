#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int t;
	cin>>t;
	for(int hh=1;hh<=t;hh++){
		string s;
		cin>>s;
		if(0){
			
		}else{
			int ans=0;
			for(int i=1;i<s.size();i++){
				int k=i+1;
				for(int j=1;j<=sqrt(k)+1;j++){
					if(k%j==0){
						if((s.size()-i)%2==0){
							ans+=j-1;
							ans+=k/j-1;
						}else{
							ans+=(j-1)%2;
							ans+=(k/j-1)%2;
							cout<<1111<<endl;
						}
					}
				}
			}
			cout<<ans<<endl;
		}
	}
}
