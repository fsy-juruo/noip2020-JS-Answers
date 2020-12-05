#include<cstdio>
const int N = 1e5+7;
int n, k, w[10], loc[15][5], step[10][2], d[10][2];
long long ans;

bool vaild(int a, int b){
	return (a > 0 && a <= w[b]);
}

void work1(){
	for(int i = 1; i <= w[1]; ++i){
		int nowx = i, lasx = 0;
		for(int q = 1;; ++q){
			if(lasx == nowx && q == 1) {ans = -1; return;}
			++ans;
			if(step[q][0] == 1){
				nowx += step[q][1];
				if(!vaild(nowx, 1)) break;
			}
			if(q == n) q = 0;
		}
	}
}
void work2(){
	for(int i = 1; i <= w[1]; ++i){
		for(int j = 1; j <= w[2]; ++j){
			int nowx = i, nowy = j, lasx = 0, lasy = 0;
			for(int q = 1;; ++q){
				if(q == 1 && lasx == nowx && lasy == nowy){ans = -1; return;}
				++ans, lasx = nowx, lasy = nowy;
				if(step[q][0] == 1){
					nowx += step[q][1];
					if(!vaild(nowx, 1)) break;
				}
				if(step[q][0] == 2){
					nowy += step[q][1];
					if(!vaild(nowy, 2)) break;
				}
				if(q == n) q = 0;
			}
		}
	}
}
void work3(){
	for(int i = 1; i <= w[1]; ++i){
		for(int j = 1; j <= w[2]; ++j){
			for(int p = 1; p <= w[3]; ++p){
				int nowx = i, nowy = j, nowz = p;
				int lasx = 0, lasy = 0, lasz = 0;
				for(int q = 1;; ++q){
					if(q == 1 && lasx == nowx && lasy == nowy && lasz == nowz){ans = -1; return;}
					++ans, lasx = nowx, lasy = nowy, lasz = nowz;
					if(step[q][0] == 1){
						nowx += step[q][1];
						if(!vaild(nowx, 1)) break;
					}
					if(step[q][0] == 2){
						nowy += step[q][1];
						if(!vaild(nowy, 2)) break;
					}
					if(step[q][0] == 3){
						nowz += step[q][1];
						if(!vaild(nowz, 3)) break;
					}
					if(q == n) q = 0;
				}
			}
		}
	}
}
int main(){
	freopen("walk.in", "r", stdin);
	freopen("walk.out", "w", stdout);
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= k; ++i) scanf("%d", &w[i]);
	for(int i = 1; i <= n; ++i){
		scanf("%d%d", &step[i][0], &step[i][1]);
		if(step[i][1] > 0) d[step[i][0]][0] += step[i][1];
		else d[step[i][0]][1] += step[i][1];
	}
	if(k == 1) work1();
	else if(k == 2) work2();
	else if(k == 3) work3();
	else ans = -1;
	printf("%lld\n", ans);
	return 0;
}
