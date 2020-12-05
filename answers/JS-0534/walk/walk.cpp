#include<bits/stdc++.h>
//rp++
using namespace std;
struct op{
	int pos;
	int d;
}aop;
vector<op> ops;
int w[11];
int p[11];
int n,m;
string step="0";
string ps(string a,string b){
	string ans;
	int i=0,jinwei=0;
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	while(i<a.size()&&i<b.size()){
		ans.push_back(((a[i]-'0')+(b[i]-'0')+jinwei)%10+'0');
		jinwei=((a[i]-'0')+(b[i]-'0')+jinwei)/10;
		i++;
	}
	while(i<a.size()){
		ans.push_back(((a[i]-'0')+jinwei)%10+'0');
		jinwei=((a[i]-'0')+jinwei)/10;
		i++;
	}
	while(i<b.size()){
		ans.push_back(((b[i]-'0')+jinwei)%10+'0');
		jinwei=((b[i]-'0')+jinwei)/10;
		i++;
	}
	if(jinwei) ans.push_back(jinwei+'0');
	reverse(ans.begin(),ans.end());
	return ans;
}
void print(string s){
	for(int i=0;i<s.size();i++)
		printf("%c",s[i]);	
}
bool check(){
	int e[11]={0};
	for(int i=0;i<ops.size();i++)
		e[ops[i].pos]+=ops[i].d;
	for(int i=0;i<11;i++)
		if(e[i]) return true;
	return false;	
}
bool out(){
	for(int i=0;i<11;i++)
		if(p[i]>w[i]||p[i]<0) return true;
	return false;
}
void dfs(int k){
	if(k==m){	
		while(!out()){
			for(int i=0;i<ops.size();i++){
				p[ops[i].pos]+=ops[i].d;
				step=ps(step,"1");
				if(out()) break;
			}
		}
		return;	
	}
	else{
		for(int i=1;i<=w[k];i++){
			p[k]=i;
			dfs(k+1);
		}	
	}
}
int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
		scanf("%d",w+i);
	for(int i=0;i<n;i++){
		scanf("%d%d",&aop.pos,&aop.d);
		aop.pos--;
		ops.push_back(aop);
	}
	if(!check())
		printf("-1");
	else{
		dfs(0);
		print(step);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

