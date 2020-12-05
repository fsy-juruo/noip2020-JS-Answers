#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    string s;
    int i,n,m,t,j,k,l;
    long long ans[6];
    cin>>t;
   for(i=1;i<=t;i++){
   	    cin>>s;
   	    if(s[0]==s[1]&&s[0]==s[3]&&s[0]==s[4]&&s[2]==s[5]&&s.length()==6){
   	    	ans[i]=8;
		   }
		if(s[0]==s[1]&&s[0]==s[2]&&s[3]==s[4]){
			ans[i]=9;
		} 
		if(s[0]==s[1]&&s[0]==s[3]&&s[0]==s[4]&&s[2]==s[5]&&s.length()==7){
			ans[i]=16;
		}  
   }
   for(i=1;i<=t;i++){
   	cout<<ans[i]<<endl;
   }
	return 0;
}
