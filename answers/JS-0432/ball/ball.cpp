#include<bits/stdc++.h>
using namespace std;
stack<int > s[1010];
int opt[100010][2],n,m,tmp=1;
bool pd()
{
	stack<int > q;
	int flag=0;
	for(int i = 1 ; i <= n+1 ; i++ )
	{
		if(s[i].empty()) continue;
		while(!q.empty()) q.pop();		
		int ys=s[i].top();
		q.push(s[i].top());
		s[i].pop();
		int j=2;
		for(j = 2 ; j <= m ; j++ )
		{
			if(s[i].empty()){
				flag=1;
				break;
			}
			if(s[i].top()!=ys){
				flag=1;
				break;
			}
			else{
				q.push(s[i].top());
				s[i].pop();
			}
		}
		for(int t = 1 ; t < j ; t++ )
		{
			s[i].push(q.top());
			q.pop();
		}
	}
	if(flag==1){
		return false;
	}
	else{
		return true;
	}
}
bool dfs(int dep,int fa1,int fa2)
{
	if(dep>30) return false;
	if(pd()){
//		cout<<tmp<<endl;
		return true;
	}
	for(int i = 1 ; i <= n+1 ; i++ )
	{
		if(s[i].empty()) continue;
		for(int j = 1 ; j <= n+1 ; j++ )
		{
			if(s[j].size()>=m) continue;
			if(i==j) continue;
			if(i==fa2&&j==fa1) continue;
			if(i==fa2) continue;
//			if(i==fa1) continue;
			tmp++;
			opt[tmp][0]=i;
			opt[tmp][1]=j;
			s[j].push(s[i].top());
			s[i].pop();
			if(dfs(dep+1,i,j)){
				return true;
			}
			else
			{
				tmp--;
				s[i].push(s[j].top());
				s[j].pop();
			}
		}
	}
	return false;
}
bool dfss1(int dep,int fa1,int fa2)
{
	if(dep>400) return false;
	if(pd()){
//		cout<<tmp<<endl;
		return true;
	}
	for(int i = 1 ; i <= n+1 ; i++ )
	{
		if(s[i].empty()) continue;
		for(int j = 1 ; j <= n+1 ; j++ )
		{
			if(s[j].size()>=m) continue;
			if(i==j) continue;
			if(i==fa2&&j==fa1) continue;
			if(i==fa2) continue;
//			if(i==fa1) continue;
			tmp++;
			opt[tmp][0]=i;
			opt[tmp][1]=j;
			s[j].push(s[i].top());
			s[i].pop();
			if(dfs(dep+1,i,j)){
				return true;
			}
			else
			{
				tmp--;
				s[i].push(s[j].top());
				s[j].pop();
			}
		}
	}
	return false;
}
int main()
{
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1 ; i <= n ; i++ )
	{
		for(int j = 1 ; j <= m ; j++ )
		{
			int x;
			scanf("%d",&x);
			s[i].push(x);
		}
	}
	int k=n+1;
	int flag=0;
	for(int i = 1 ; i <= n && flag==0 ; i++ )
	{
		if(!s[i].empty()){
			tmp=1;
			opt[tmp][0]=i;
			opt[tmp][1]=k;
			s[k].push(s[i].top());
			s[i].pop();
			if(dfs(1,i,k)){
				flag=1;
				break;
			}
			else{
				if(dfss1(1,i,k)){
					flag=1;
					break;
				}
			}				
		}
		if(flag==1){
			break;
		}
	}
/*	for(int i = 1 ; i <= n+1 ; i++ )
	{
		if(s[i].empty()) continue;	
		cout<<i<<' ';	
		for(int j = 1 ; j <= m ; j++ )
		{
			if(s[i].empty()) break;
 			cout<<s[j].top()<<' ';
 			s[j].pop();
		}
	}*/
	printf("%d\n",tmp);
	for(int i = 1 ; i <= tmp ; i++ )
	{
		printf("%d %d\n",opt[i][0],opt[i][1]);
	}
	return 0;
}
