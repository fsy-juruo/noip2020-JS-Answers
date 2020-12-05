#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int n,surp[N],prep[N],numm[30],si;
ll anss[10];
string s;

ll pid(){
	ll summ=0;
	for(int i=si-1;i>=2;i--){
		for(int j=2;j<=i;j++){
			if(i%j==0){
				int fla=0;
				for(int k=j+1;k<=i;k++){
					if(s[k-1]!=s[k-1-j]){
						fla=1;
						break;
					}
				}
				if(fla==0){
					for(int k=0;k<j-1;k++){
						if(surp[k]<=prep[i]) summ++;
					}
				}
			}
		}
	}
	return summ;
}

int main(){
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s;
		si=s.length();
		/*int fla1=0;
		for(int j=0;j<si;j++){
			if(s[j]!=s[0]){
				fla1=1;
				break;
			}
		}
		if(fla1==0){
		    ll suu=0;		
			for(int j=2;j<=si;j++){
				for(int k=2;k<=j;k++){
					if(j%k==0){
						if((si-j)%2==1) suu+=k-1;
						else suu+=(k-1)/2;
					}
				}
			}
			anss[i]=suu;
			continue;
		}*/
		memset(numm,0,sizeof numm);
		memset(surp,0,sizeof surp);
		memset(prep,0,sizeof prep);
		surp[0]=1;
		numm[int(s[0])-int('a')+1]=1;
		for(int j=1;j<si;j++){
			numm[int(s[j])-int('a')+1]++;
			if(numm[int(s[j])-int('a')+1]%2==1) surp[j]=surp[j-1]+1;
			else surp[j]=surp[j-1]-1;
		}
		memset(numm,0,sizeof numm);
		prep[si-1]=1;
		numm[int(s[si-1])-int('a')+1]=1;
		for(int j=si-2;j>=0;j--){
			numm[int(s[j])-int('a')+1]++;
			if(numm[int(s[j])-int('a')+1]%2==1) prep[j]=prep[j+1]+1;
			else prep[j]=prep[j+1]-1;
		}
		anss[i]=pid();
	}
	for(int i=1;i<=n;i++) cout<<anss[i]<<endl;
	return 0;
}
