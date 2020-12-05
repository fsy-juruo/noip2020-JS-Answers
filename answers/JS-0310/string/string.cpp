#include<bits/stdc++.h>
using namespace std;

int t,f[1010],p[1010][1010],vh[30],ans=0;
string st;
char ch[1010];

void pre(){
	f[0]=1;
	int n=st.size();
	for(int i=1;i<n;++i){
		memset(vh,0,sizeof(vh));
		for(int j=0;j<=i;++j){
			vh[int(st[j]-'a'+1)]++;
		}
		for(int j=1;j<=26;++j){
			if(vh[j]%2==1)
				f[i]++;
		}
	}
}

void pre2(int sumc){
	string ss="";
	int n=st.size();
	for(int i=0;i<n-sumc;++i){
		ss=ss+st[i];
		int len=ss.size();
		if((n-sumc)%len!=0||len==1){
			p[sumc][len]=1;
			continue;
		}
		for(int j=0;j<1010;++j)
			ch[j]=' ';
		for(int j=0;j<len;++j)
			ch[j]=st[j];
		for(int j=len;j<n-sumc;++j)
			if(st[j]!=ch[j%len]){
				p[sumc][len]=1;
				break;
			}
	}
}

int find_lim(int pos){
	int sum=0;
	int n=st.size();
	memset(vh,0,sizeof(vh));
	for(int i=pos;i<n;++i)
		vh[st[i]-'a'+1]++;
	for(int i=1;i<=26;++i)
		if(vh[i]%2==1)
			sum++;
	return sum;
}

int get_ans(int pos,int num){
	int sum=0;
	int n=st.size();
	int lim=find_lim(pos);
	for(int i=1;i<=n-num;++i)
		if(p[num][i]==0)
			for(int j=0;j<i-1;++j)
				if(f[j]<=lim)
					sum++;
	return sum;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;++i){
		memset(p,0,sizeof(p));
		memset(f,0,sizeof(f));
		ans=0;
		cin>>st;
		int n=st.size();
		for(int j=n-1;j>=0;--j){
			pre2(n-j);
			ans+=get_ans(j,n-j);
		}
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
