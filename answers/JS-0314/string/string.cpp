#include<bits/stdc++.h>
using namespace std;
int t,l,ans;
int ca[30],cc[30];
int tota,totb,tot,bx;
int sta[10000],stz[10000];
string s;
void  check(int x,int y){

	bool f=0;
	int k=0,kca=0,kcb=0,kcc=0;
	for(int i=1;i<=26;i++){
		if(ca[i]&1){
			kca++;
		}
	}
	while(!f){
		k++;
		if(k==1){
			kcc=0;
			if(x+y+1<=l){
			
			for(int i=x+y+1;i<=l;i++){
				cc[(int)s[i]-96]++;
			}
			for(int i=1;i<=26;i++){
				if(cc[i]&1){
					kcc++;
				}
				cc[i]=0;
			}
			if(kcc>=kca) ans++;
		}
		}
		else{
			tot=0;
			if((x+y+1)*(k)<=l){
			for(int i=(x+y+1)*(k-1);i<=l;i++){
				tot++;
				if(tot>x+y+1) break;
				bx=(int)s[i]-96;
				if(bx!=stz[tot]) {
					f=1;
					break;
				}
			}
			if(!f){
				kcc=0;
					for(int i=(x+y+1)*k;i<=l;i++){
				cc[(int)s[i]-96]++;
			}
			for(int i=1;i<=26;i++){
				if(cc[i]&1){
					kcc++;
				}
				cc[i]=0;
			}
			if(kcc>=kca) ans++;
			}
		}
		else f=1;
		}
	}
}
/*void dfs(int u,int k){
	if(u>l&&k==3){
		if(check()){
			ans++;
		}
		return;
	}
	if(u>l) return;
	if(k<2){
	if(!k)
	for(int i=u;i<=l;i++){
		tota++;
		sta[tota]=(int)s[i]-96;
		ca[(int)s[i]-96]++;
		dfs(i+1,k+1);
	}
	else{
		totb=0;
		for(int i=u;i<=l;i++){
		stb[++totb]=(int)s[i]-96;
		cb[(int)s[i]-96]++;
		dfs(i+1,k+1);
	}
	}
}
else{
	if(k==2){
		
	}
}
}*/
int main(){

freopen("string.in","r",stdin);
freopen("string.out","w",stdout);
scanf("%d",&t);
while(t--){
	cin>>s;
	ans=0;
	l=s.size()-1;
//	dfs(0,0);
	for(int i=0;i<=l;i++){
		sta[i+1]=(int)s[i]-96;
		stz[i+1]=(int)s[i]-96;
		ca[(int)s[i]-96]++;
		totb=0;
		for(int j=i+1;j<=l;j++){
			totb++;
			stz[j+1]=(int)s[j]-96;
			//cb[(int)s[j]-96]++;
			//stb[totb]=(int)s[j]-96;
			check(i,totb);
		}
	}
	for(int i=1;i<=26;i++){
		cc[i]=ca[i]=0;
	}
	totb=0;
	printf("%d\n",ans);
}
return 0;
}

