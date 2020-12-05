#include <bits/stdc++.h>
#define ll long long
using namespace std;
namespace cfz_akioi{
	template <typename T> inline void rd(T &x){
		x=0;int f=1;char c=getchar();
		for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
		for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+c-'0';
		x*=f;
	}
	struct node{
		int Fa_top;
		int Son_top;
		vector <ll> Fa;
		vector <ll> Son;
	};
	int n,m;
	node a[100010];
	int d;
	ll k;
	vector <ll> Outline;
	ll Gcd_ll(ll x,ll y){  //最大公约数
		if(x<y)swap(x,y); 
		int z=x%y;
		while(z){
			x=y;
			y=z;
			z=x%y;
		}
		return y;
	}
	ll Ggd_ll(ll x,ll y){  //最小公倍数 
		return x*y/Gcd_ll(x,y);
	}
	ll Plus_fen_ret_x,Plus_fen_ret_y;
	void Plus_fen(ll x1,ll y1,ll x2,ll y2){  //分数加法 
		ll ans_x=x1*y2+x2*y1;
		ll ans_y=y1*y2;
		ll t=Gcd_ll(ans_x,ans_y);
		ans_x/=t;
		ans_y/=t;
		Plus_fen_ret_x=ans_x;
		Plus_fen_ret_y=ans_y;
		return ;
	}
	int ans_fun_x,ans_fun_y;
	int fun_x,fun_y;
	void fun(ll dep,ll dishu,bool pd){
		if(a[dep].Fa_top==0){
			if(dep>m)return ;
			if(dep<=m){
				Plus_fen(fun_x,fun_y,1,max(a[dep].Son_top,1)*dishu);
				fun_x=Plus_fen_ret_x;
				fun_y=Plus_fen_ret_y;
				return ;
			}
		}
		for(int i=0;i<a[dep].Fa_top;i++){
			fun(a[dep].Fa[i],dishu*max(a[dep].Son_top,1),false);
		}
		if(pd==true){
			ans_fun_x=fun_x;
			ans_fun_y=fun_y;
			return ;
		}
	}
}
using namespace cfz_akioi;
int main(){
	freopen("water.in","r",stdin);
	freopen("water.out","w",stdout);
	rd(n);
	rd(m);
//	Plus_fen(n,m,1,3);
//	cout<<Plus_fen_ret_x<<" "<<Plus_fen_ret_y<<endl;
//	cout<<Gcd_ll(n,m)<<endl;
	for(ll i=1;i<=n;i++){
		rd(d);
		a[i].Son_top=d;
		if(d==0){
			Outline.push_back(i);
		}
		while(d--){
			rd(k);
			a[i].Son.push_back(k);
			a[k].Fa.push_back(i);
			a[k].Fa_top++;
		}
	}
	for(int i=0;i<Outline.size();i++){
		ans_fun_x=0;
		fun_x=0;
		ans_fun_y=1;
		fun_y=1;
		fun(Outline[i],1,true);
		cout<<ans_fun_x<<" "<<ans_fun_y<<endl;
	}
	return 0;
}
