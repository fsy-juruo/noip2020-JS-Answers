#include<bits/stdc++.h>
#define r register
using namespace std;
string s;
char cha;
int t,aq[1001][27],ans,k,len;
bool flag;
inline void work(){
	for(r int i=0;i<len;i++)
		aq[i][s[i]-'a']=1;
	for(r int i=1;i<len;i++)
		for(r int j=0;j<26;j++)
			aq[i][j]+=aq[i-1][j];
}
bool check(r int A,r int C){
	int numa=0,numc=0;
	for(r int i=0;i<26;i++)
		if(aq[A][i]&1)
			numa++;
	for(r int i=0;i<26;i++)
		if((aq[len-1][i]-aq[C][i])&1)
			numc++;
	if(numa<=numc) return 1;
	return 0;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	scanf("%d",&t);
	while(t--){
		cin>>s; cha=getchar(); len=s.size();
		work(); 
		ans=0;
		for(r int i=0;i<len-2;i++)
			for(r int j=i+1;j<len-1;j++){
				if(check(i,j)) ans++;
				k=0; 
				while(flag){
					k++;
					if((j+1)*(k+1)>=len) break;
					for(r int x=(j+1)*k;x<=(j+1)*(k+1)-1;x++)
						if(s[x]!=s[x-(j+1)]){
						flag=1; break;
					}
					if(!flag&&check(i,(j+1)*(k+1))) ans++;													
				}
			}
		cout<<ans<<endl;
		for(r int i=0;i<len;i++)
			for(r int j=0;j<26;j++)
				aq[i][j]=0;
	}
	return 0;
}
