#include<bits/stdc++.h>
using namespace std;

bool xiaoyu(string a,string b){
	int i=0;
	while(b[i]=='0'&&i<b.size()) i++;
	b=b.substr(i);
	i=0;
	while(a[i]=='0'&&i<a.size()) i++;
	a=a.substr(i);
	if(a.size()<b.size()) return true;
	if(a.size()>b.size()) return false;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i]) return a[i]<b[i];
	return false;
}
bool dayu(string a,string b){
	int i=0;
	while(b[i]=='0'&&i<b.size()) i++;
	b=b.substr(i);
	i=0;
	while(a[i]=='0'&&i<a.size()) i++;
	a=a.substr(i);
	if(a.size()>b.size()) return true;
	if(a.size()<b.size()) return false;
	for(int i=0;i<a.size();i++)
		if(a[i]!=b[i]) return a[i]>b[i];
	return false;
}
string jia(string a,string b){
	if(a.size()<b.size())do{
		string t=a; a=b; b=t;
	}while(0);
	bool jw=0;
	for(int i=1;i<=b.size();i++){
		a[a.size()-i]+=b[b.size()-i]-'0'+jw;
		jw=(a[a.size()-i]-'0')/10;
		a[a.size()-i]=(a[a.size()-i]-'0')%10+'0';
	}
	if(b.size()==a.size()&&jw) a='1'+a;
	else if(jw) for(int i=1;a[a.size()-b.size()-i]=='9';i++){
		a[a.size()-b.size()-i]='0';
		if(a[a.size()-b.size()-i-1]!='9'){
			a[a.size()-b.size()-i-1]++; break;
		}
		if(b.size()+i==a.size()){
			a='1'+a; break;
		}
	}
	return a;
}
string cheng(string a,string b){
	char c[a.size()+b.size()+1];
	for(int i=0;i<a.size()+b.size();i++) c[i]='0';
	c[a.size()+b.size()]=0;
	for(int i=0;i<a.size();i++)
		for(int j=0;j<b.size();j++){
			c[a.size()+b.size()-i-j-1]+=
				(a[a.size()-i-1]-'0')*(b[b.size()-j-1]-'0');
			for(int k=0;c[a.size()+b.size()-i-j-k-1]>'9';k++){
				c[a.size()+b.size()-i-j-k-2]+=
					(c[a.size()+b.size()-i-j-k-1]-'0')/10;
				c[a.size()+b.size()-i-j-k-1]= '0'+
					(c[a.size()+b.size()-i-j-k-1]-'0')%10;
			}
		}
	string ans=c;
	int i=0;
	while(ans[i]=='0'&&i<ans.size()) i++;
	ans=ans.substr(i);
	return ans;
}
string cheng(string a,short b){//0<=b<=9
	string c="0";
	if(b==0) return c;
	c[0]=b+'0';
	return cheng(a,c);
}
string chu(string a,string b){
	string c=a;
	int h=b.size()-1,ic=0;
	while(dayu(a,b)){
		short at=(a[h-b.size()+1]-'0')/(b[0]-'0');//imagine ans is at
		while(xiaoyu(cheng(b,at),a.substr(0,h+1))) at++;
		while(dayu(cheng(b,at),a.substr(0,h+1))) at--;
		c[ic++]=at;
		string t=cheng(b,at);
		for(int i=0;i<t.size();i++){
			a[h-i]-=t[t.size()-i-1]-'0';
			if(a[h-i]<'0'){
				a[h-i]+=10; a[h-i-1]--;
			}
			if(i+1==t.size()){while(a[h-i-1]<'0'){
				a[h-i-1]+=10; a[h-i-2]--; i--;
			}break;}
		}
		h++;
	}
	return c;
}
string mo(string a,string b){
	int h=b.size()-1;
	while(dayu(a,b)){
		short at=(a[h-b.size()+1]-'0')/(b[0]-'0');//imagine ans is at
		while(xiaoyu(cheng(b,at),a.substr(0,h+1))) at++;
		while(dayu(cheng(b,at),a.substr(0,h+1))) at--;
		string t=cheng(b,at);
		for(int i=0;i<t.size();i++){
			a[h-i]-=t[t.size()-i-1]-'0';
			if(a[h-i]<'0'){
				a[h-i]+=10; a[h-i-1]--;
			}
			if(i+1==t.size()){while(a[h-i-1]<'0'){
				a[h-i-1]+=10; a[h-i-2]--; i--;
			}break;}
		}
		h++;
	}
	int i=0;
	while(a[i]=='0'&&i<a.size()) i++;
	a=a.substr(i);
	return a;
}

string gcd(string a,string b){
	string t=mo(b,a);
	if(t[0]=='0') return a;
	return gcd(t,a);
}

class fs{
	public:
		fs(){
			fz="0";
			fm="1";
		}
		string fz;
		string fm;
		void add(fs x){
			x.fz=jia(cheng(fz,x.fm),cheng(fm,x.fz));
			fm=cheng(fm,x.fm);
			fz=x.fz;
		}
		void yf(){
			string g=gcd(fz,fm);
			fz=chu(fz,g); fm=chu(fm,g);
//			if(fz<0&&fm<0){
//				fz=-fz; fm=-fm;
//			}
		}
};

int n,m;
short d[100001];
int a[100001][6];
fs p[100001];

void run(int x){//run the point #x
	if(d[x]==0||p[x].fz=="0") return;
	fs t=p[x];
	t.fm=cheng(t.fm,d[x]);
//	cout<<x<<"=>";
//	for(int i=0;i<d[x];i++) cout<<a[x][i]<<',';
//	cout<<'\b'<<'\t'<<t.fz<<' '<<t.fm;
	for(int i=0;i<d[x];i++){
		p[a[x][i]].add(t);
		run(a[x][i]);
	}
	p[x].fz="0";
	p[x].fm="1";
}

int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>d[i];
		for(int j=0;j<d[i];j++){
			cin>>a[i][j];
			a[i][j]--;
		}
	}
	for(int i=0;i<m;i++) p[i].fz="1";
	for(int i=0;i<m;i++) run(i);
	for(int i=0;i<n;i++){
		if(!d[i]){
			for(int j=0;j<p[i].fz.size();j++) cout<<p[i].fz[j];
			cout<<' ';
			for(int j=0;j<p[i].fm.size();j++) cout<<p[i].fm[j];
			cout<<'\n';
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
