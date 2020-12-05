//GZZ±£””
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int ans,T,len;
char a[1048600];
void init(){
	ans=0;
	memset(a,0,sizeof(a));		
}
int calc(int x,int y){
	int times[30]={0};int num=0;
	for(int i=x;i<=y;i++)times[a[i]-'a'+1]++;
	for(int i=1;i<=26;i++)if(times[i]&1==1)num++;
	return num;
}
bool same(int l,int r,int x){
	for(int i=l,ii=x;i<=r;i++,ii++){
		if(a[i]!=a[ii])return 0;
	}
	return 1;
}
int check(int x,int y){
	int numa=calc(1,x);
	int ans=0;
	for(int k=0;k<len;k++){
		if((k+1)*y+1>len)break;
		if(!same(1,y,k*y+1))return ans;
		if(calc((k+1)*y+1,len)<numa)continue;
		ans++;
	}
	return ans;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		init();
		cin>>a+1;
		len=strlen(a+1);
		for(int i=1;i<len-1;i++){
			for(int j=i+1;j<len;j++){
				ans+=check(i,j);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
