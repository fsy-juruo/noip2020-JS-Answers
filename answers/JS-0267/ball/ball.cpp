#include <bits/stdc++.h>
using namespace std;
#define MAXX 110000
int n,m;

struct node{
	int l,r;
};

void fen_10(){
	stack<int> a,b,c;
	node ans[MAXX];
	int v;
	int cnt=0;
	for(int j=1;j<=m;j++){
		cin>>v;
		a.push(v);		
	}
	for(int j=1;j<=m;j++){
		cin>>v;
		b.push(v);		
	}
	while(c.size()!=m&&!b.empty()){
		while(!a.empty()&&a.top()==1&&b.size()<m){
			b.push(a.top());
			a.pop();
			ans[++cnt].l=1;
			ans[cnt].r=2;			
			
		}
		while(!a.empty()&&a.top()==2&&c.size()<m){
			c.push(a.top());
			a.pop();
			ans[++cnt].l=1;
			ans[cnt].r=3;			
		}
		while(!b.empty()&&b.top()==1&&a.size()<m){
			a.push(b.top());
			b.pop();
			ans[++cnt].l=2;
			ans[cnt].r=1;
		}
		while(!b.empty()&&b.top()==2&&c.size()<m){
			c.push(b.top());
			b.pop();
			ans[++cnt].l=2;
			ans[cnt].r=3;			
		}
	/*cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<ans[i].l<<" "<<ans[i].r<<endl;
	system("pause");*/
	}
	/*while(!b.empty()){
		if(b.top()==1){
			a.push(b.top());
			b.pop();
			ans[++cnt].l=2;
			ans[cnt].r=1;
		}
		else{
			c.push(b.top());
			b.pop();
			ans[++cnt].l=2;
			ans[cnt].r=3;			
		}
	}
	while(!a.empty()){

	}*/
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<ans[i].l<<" "<<ans[i].r<<endl;
}

int main(){
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	cin>>n>>m;
	if(n==1){
		cout<<0<<endl;
	}
	else if(n==2){
		fen_10();
	}
	else 
		cout<<0<<endl;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
