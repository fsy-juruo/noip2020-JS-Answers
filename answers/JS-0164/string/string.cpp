#include<bits/stdc++.h>
using namespace std;
template<typename T>inline void read(T&x){
	long long f=1;x=0;char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	x*=f;
}
template<typename T>inline void write(T x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9)write(x/10);
	putchar(x%10+48);
}
template<typename T>inline void writeln(T x){
	write(x);
	putchar('\n');
}
const long long P=1e9+7;
long long h[2000000];
long long elec[30],xhj[2000000];
long long Ja[2000000],elea[30],ja=0,jc=0,ans=0,C;
long long qpow(long long a,long long b){
	long long res=1,base=a;
	while(b){
		if(b&1)res=res*base%P;
		base=base*base%P;
		b>>=1;
	}
	return res;
}
long long query(long long l,long long r){
	l++;r++;
	return (h[r]-h[l-1]*qpow(26,r-l+1)%P+P)%P;
}
void doit(long long len){
	if(xhj[len]+1<C)return;
	
	for(long long i=0;i<len-1;i++){
		if(Ja[i]<=jc){
			ans++;
//			cout<<i<<' '<<C<<endl;
		}
	}
}
void baoli(string st){
	for(long long i=0;i<=st.size();i++)h[i]=xhj[i]=0;
	for(long long i=0;i<st.size();i++){
		h[i+1]=(h[i]*26%P-'a'+st[i])%P;
	}
	
	for(long long len=2;len<=st.size();len++){
		long long H=query(0,len-1);
		xhj[len]=len-1;
		for(long long l=len;l+len-1<st.size();l+=len){
			long long r=l+len-1;
			long long tmp=query(l,r);
			if(tmp!=H){
				break;
			}else{
				xhj[len]=r;
			}
		}
	}
	
	memset(elea,0,sizeof(elea));
	ja=0;
	for(long long A=0;A<st.size();A++){
		long long tmp=st[A]-'a'+1;
		if(elea[tmp]&1){
			ja--;
		}else{
			ja++;
		}
		elea[tmp]++;
		Ja[A]=ja;
	}
	
	memset(elec,0,sizeof(elec));
	jc=0;ans=0;
	for(C=st.size()-1;C>=2;C--){
		long long tmp=st[C]-'a'+1;
		if(elec[tmp]&1){
			jc--;
		}else{
			jc++;
		}
		elec[tmp]++;
		
		//start from C-1
		for(long long len=2;len*len<=C;len++){
			if(C%len==0){
				doit(len);
				if(len*len!=C)doit(C/len);
			}
		}
		doit(C);
	}
	writeln(ans);
}
void pianit(int len){
	if(jc){
		ans+=len-1;
	}else{
		ans+=(len-1)/2;
	}
}
void pianfen(string st){
	jc=0;ans=0;
	for(C=st.size()-1;C>=2;C--){
		jc=1-jc;
		for(int len=2;len*len<=C;len++){
			if(C%len==0){
				pianit(len);
				if(len*len!=C)pianit(C/len);
			}
		}
		pianit(C);
	}
	writeln(ans);
}
bool ok(string st){
	char ch=st[0];
	for(int i=1;i<st.size();i++){
		if(st[i]!=ch)return false;
	}
	return true;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);

	long long T;
	read(T);
	while(T--){
		string st;
		cin>>st;
		if(st.size()<=1000)baoli(st);
		else if(ok(st))pianfen(st);
		else baoli(st);
	}
	return 0;
}
/*
3
nnrnnr
zzzaab
mmlmmlo

14
a
aa
aaa
aaaa
aaaaa
aaaaaa
aaaaaaa
aaaaaaaa
aaaaaaaaa
aaaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaaa
aaaaaaaaaaaaa
aaaaaaaaaaaaaa

7
a
aaa
aaaaa
aaaaaaa
aaaaaaaaa
aaaaaaaaaaa
aaaaaaaaaaaaa

*/

