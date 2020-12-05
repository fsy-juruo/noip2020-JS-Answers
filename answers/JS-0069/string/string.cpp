#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f*=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x*=10;
		x+=ch-'0';
		ch=getchar();
	}
	return x*f;
}
int ans=0;
bool sam(int l1,int r1,int l2,int r2,string st){
	for(int i=l1;i<=r1;i++)if(st[i]!=st[l2-l1+i])return 0;
	return 1;
}
int f[110];
int num(string st,int l,int r){
	memset(f,0,sizeof(f));
	for(int i=l;i<=r;i++){
		f[st[i]-'a'+1]++;
	}
	int c=0;
	for(int i=1;i<=110;i++){
		if(f[i]%2==1)c++;
	}
	return c;
}
int check(int l1,int l2,string st){
	int n=st.size()-1;
	int rt=0;
	int xel=num(st,1,l1);
	for(int i=0;i<=n;i+=l2){
		if(sam(i+1,i+l1,1,l1,st)&&sam(i+l1+1,i+l2,l1+1,l2,st)){
			int kel=num(st,i+l2+1,n);
			if(xel<=kel&&i+l2+1<=n){
				rt++;
			}
		}else{
			break;
		}
	}
	return rt;
} 
void dfs(string st){
	for(int i=1;i<st.size();i++)for(int j=i+1;j<st.size();j++)ans+=check(i,j,st);
}
int check1(int l1,int l2,string st){
	int n=st.size()-1;
	int rt=0;
	int xel=l1%2;
	for(int i=0;i<=n;i+=l2){
		int kel=(n-i-l2)%2;
		if(xel<=kel&&i+l2+1<=n)rt++;
	}
	return rt;
} 
void work(string st){
	for(int i=1;i<st.size();i++)for(int j=i+1;j<st.size();j++)ans+=check1(i,j,st);
} 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T;
	cin>>T;
	
	while(T--){
		string st;
		cin>>st;
		
		if(st.size()<=2){
			cout<<0<<endl;
			continue;
		}
		
		//subtask1
		st=' '+st;
		if(st.size()<=100){
			dfs(st);
			cout<<ans<<endl;
			ans=0;
			continue;
		}
		
		bool flg=1;
		for(int i=2;i<st.size();i++)if(st[i]!=st[i-1])flg=0;
		if(flg){
			work(st);
			cout<<ans<<endl;
			ans=0;
			continue;
		}
	}	
	return 0;
}
