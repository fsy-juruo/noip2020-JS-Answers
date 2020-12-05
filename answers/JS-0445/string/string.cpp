#include<bits/stdc++.h>
using namespace std;
char ch[1048580];
int len;
int numf[1048580],numb[1048580];
void init(){
	int times[1026];
	memset(times,0,sizeof(times));
	for(int i=1;i<=len;i++){
		times[ch[i]]++;
		if(times[ch[i]]%2)
			numf[i]=numf[i-1]-1;
		else
			numf[i]=numf[i-1]+1;
	}
	for(int i=len;i>=1;i--){
		times[ch[i]]++;
		if(times[ch[i]]%2)
			numb[i]=numb[i+1]-1;
		else
			numb[i]=numb[i+1]+1;
	}
}
int ans;
void SolveA(){
	for(int k=len;k>=3;k--){
		for(int part=1;part<=k;part++){
			if((len-k)%part!=0)
				continue;
			int plen=(len-k)/part,flag=1;
			for(int i=1;i<part;i++){
				for(int j=1;j<=plen;j++){
					if(ch[part*(i-1)])
				}
			}
		}
	}
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int TT=1;TT<=T;TT++){
		memset(ch,0,sizeof(ch));
		memset(numf,0,sizeof(numf));
		memset(numb,0,sizeof(numb));
		scanf("%s",ch);
		len=strlen(ch);
		for(int i=1;i<=len;i++)
			if(ch[i]!=ch[1])
				goto NotSame;
		if(n%2==0){
			 ;
		}
		NotSame:;
		init();
		if(len<=1000){
			SolveA();
			printf("%d",ans);
			continue;
		}
	}
	return 0;
}
