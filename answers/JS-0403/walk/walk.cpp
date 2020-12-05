#include <cstdio>
#include <algorithm>

using std::max;

int const N=5e5+5,K=12;
int n,k;

struct Vector{
	int v[K];

	void operator +=(Vector & b){
		for(int i = 0;i < k;++i){
			this->v[i]+=b.v[i];
		}
	}
};

Vector steps[N];
Vector ss[N];

Vector mx;

Vector pos;
Vector w;

Vector tot;

int ci,di;

void special1(){
	for(int i = 0;i < n;++i){
		ss[i].v[0]=steps[i].v[0];
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	
	scanf("%d%d",&n,&k);

	for(int i = 0;i < k;++i){
		scanf("%d",w.v+i);
	}

	for(int i = 0;i < n;++i){
		scanf("%d%d",&ci,&di);
		steps[i].v[ci] = di;
		tot.v[ci]+=di;
	}
	
	bool flag = 1;

	for(int i = 0;i < k;++i){
		if(tot.v[i]){
			flag = 0;
			break;
		}
	}

	if(flag){
		printf("%d\n",-1);
		return 0;
	}

	if(k==1) special1();

	return 0;
}
