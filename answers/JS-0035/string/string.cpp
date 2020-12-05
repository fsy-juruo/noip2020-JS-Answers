#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			w=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		ret=ret*10+ch-'0';
		ch=getchar();
	}
	return ret*w;
}
void print(int x){
	if(x<0){
		x=-x;
		putchar('-');
	}
	if(x>=10){
		print(x/10);
		putchar('0'+x%10);
	}
	if(x<=9){
		putchar('0'+x);
	}
}
int T;
string s;
map<char,int> sum[1005];
map<char,bool> vis;
int getdiff(int l,int r){
	for(char j='a';j<='z';j++){
		vis[j]=false;
	}
	int cnt=0;
	for(int j=l;j<=r;j++){
		if(!vis[s[j]]&&(sum[r][s[j]]-sum[l-1][s[j]])%2==1){
			vis[s[j]]=true;
			cnt++;
		}
	}
	return cnt;
}
int getsans(int x,int op){
	int ret=0;
	for(int i=3;i<=x;i++){
		if(x%i==0){
			if(op==1){
				ret+=(i-1)/2;
			}else{
				ret+=i/2;
			}
		}
	}
	return ret;
}
int getans(int i,int len,int diff){
//	printf("getans(i:%d,len:%d,diff:%d)\n",i,len,diff);
	int ret=0;
	if(i==len){
		for(int j=i-1;j>=1;j--){
			if(getdiff(1,j)<=diff){
				ret++;
			}
		}
//		printf("return:%d\n",ret);
		return ret;
	}
	string tmp=s.substr(1,i);
	for(int j=i+1;j+i-1<=len;j+=i){
		if(tmp!=s.substr(j,i)){
//			printf("return:0\n");
			return 0;
		}
		ret++;
	}
	for(int j=i;j>=2;j--){
		if(i%j==0){
			ret+=getans(j,i,diff);
		}
	}
//	printf("return:%d\n",ret);
	return ret;
}
int solve(int len,int diff){
//	printf("solve(len:%d,diff:%d)\n",len,diff);
	int ret=0;
	for(int i=len;i>=2;i--){
		if(len%i==0){
			ret+=getans(i,len,diff);
		}
	}
	return ret;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	T=read();
	while(T--){
		int ans=0;
		cin>>s;
		if(s.size()>1000){
			int len=s.size();
			for(int i=2;i<=len;i+=2){
				ans+=getsans(len-i,1);
			}
			for(int i=1;i<=len;i+=2){
				ans+=getsans(len-i,1)+getsans(len-i,2);
			}
			print(ans);
			putchar('\n');
		}
		s=' '+s;
		int len=s.size();
		len--;
		for(char i='a';i<='z';i++){
			sum[0][i]=0;
		}
		for(int i=1;i<=len;i++){
			for(char j='a';j<='z';j++){
				sum[i][j]=sum[i-1][j];
			}
			sum[i][s[i]]=sum[i-1][s[i]]+1;
		}
		for(int i=1;i<=len;i++){
			ans+=solve(len-i,getdiff(len-i+1,len));
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}
