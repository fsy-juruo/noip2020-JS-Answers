#include<bits/stdc++.h>
#define ll long long
using namespace std;
int odd[1005];
int alph[30];
int alpf[1005][30];
string op[1005];

ll Op(string x,ll v){
	ll cnt=0;
	int len=x.size();
	for(int i=0;i<(len-1);i++)
		if(odd[i]<=v) cnt++;	
	//ababab
	bool flag;
	for(int i=2;i<len;i++){
		if(len%i==0){
			flag=1;
			for(int j=0;j<len;j++){
				if(x[j]!=x[j%i]){
					flag=0;
					break;	
				}
			}
			if(flag==1) cnt+=Op(op[i-1],v);
		}
	}
	
	return cnt;
}


ll Operation(string x){
	int len=x.size();
	ll cnt=0;
	op[0]=""+x[0];
	alpf[0][x[0]-'a'+1]++;
	odd[0]=1;
	for(int i=1;i<len;i++){
		op[i]=op[i-1]+x[i];
		for(int j=1;j<=26;j++) alpf[i][j]=alpf[i-1][j];
		alpf[i][x[i]-'a'+1]++;
		odd[i]=odd[i-1];
		if(alpf[i][x[i]-'a'+1]%2==0) odd[i]--;
		else odd[i]++;
		
		int a[30];
		int v=0;
		for(int j=1;j<=26;j++){
			a[j]=alph[j]-alpf[i][j];
			if(a[j]%2==1) v++;	
		}
		
		cnt+=Op(op[i],v);
	}
	return cnt;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	for(int i=1;i<=T;i++){
		string x;
		ll number=0;
		cin>>x;
		int len=x.size();
		memset(alpf,sizeof(alpf),0);
		for(int j=0;j<len;j++){
			alph[x[j]-'a'+1]++;	
			if(alph[x[j]-'a'+1]==1) number++;
		}
		if(number==1){
			cout<<len*len<<endl;
		}
		else cout<<Operation(x)<<endl;
	}
	return 0;
}
