#include<bits/stdc++.h>
using namespace std;
#define N 1100006
#define ull unsigned long long
#define ll long long
int Fc[N],v[30],Fa[N];
char c[N];int l;
int T;
ll ans;
const ull base=131;
ull a[N],p[N];
void workf(){
	ans=0;
	memset(v,0,sizeof v);
	scanf("%s",c);
	l=strlen(c);
	for(int i=l-1;i>1;i--){
		if((v[c[i]-'a']^=1)==1)
		Fc[i]=Fc[i+1]+1;
		else Fc[i]=Fc[i+1]-1;
	}
	memset(v,0,sizeof v);
	Fa[0]=1;v[c[1]-'a']^=1;
	for(int i=1;i<l-1;i++){
		if((v[c[i]-'a']^=1)==1)Fa[i]=Fa[i-1]+1;
		else Fa[i]=Fa[i-1]-1;
	}
	memset(a,0,sizeof a);	
}



int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		workf();
//		a[0]=c[0]-'a'+1;
//		p[0]=1;
//		for(int i=1;i<l;i++){
//			a[i]=a[i-1]*base+c[i]-'a'+1;
//			p[i]=p[i-1]*base;
//		}
		for(int i=1;i<l-1;i++)  //0~i is ab
		{
			for(int k=0;k<i;k++)
				if(Fa[k]<=Fc[i+1])
					ans++;
			int len=i+1;
			for(int j=i+1;j+len<l-1;j+=len){
				int flg=1;
				for(int x=0;x<=i;x++){
					if(c[x]!=c[j+x]){
						flg=0;
						break;
					}
				}

				if(flg){
					for(int k=0;k<i;k++){
					if(Fa[k]<=Fc[j+len])
						ans++;
					}
				}	
				else break;		
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
