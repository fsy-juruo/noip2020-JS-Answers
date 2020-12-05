#include<bits/stdc++.h>
#define filename "ball"
#define reg register
#define ll long long
#define il inline

using namespace std;

template <typename T> void fi(T &x) {
	T f = 1, c = getchar(); x = 0;
	while(!isdigit(c)) {if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)) {x = x * 10 + c - '0'; c = getchar();}
	x *= f;
}

int n, m;
int a[52][410], len[52];
int lxcnt[51], mk[51];
int cor[51], corcnt[51];
int stpa[520010], stpb[520010], stp;
int mk1, mk2, mk3[2], mk4[2];

int main() {
	freopen(filename".in", "r", stdin);
	freopen(filename".out", "w", stdout);
	fi(n); fi(m);
	for(reg int i = 1; i <= n; ++ i ) {
		mk[i] = 1;
		lxcnt[i] = 0;
		len[i] = m;
		for(reg int j = 1; j <= m; ++ j ) {
			fi(a[i][j]);
			if(a[i][j] == a[i][1] && mk[i]) {
				++ lxcnt[i];
			}
			else {
				mk[i] = 0;
			}
		}
		mk[i] = 1;
		if(corcnt[a[i][1]] < lxcnt[i]) {
			corcnt[a[i][1]] = lxcnt[i];
			cor[a[i][1]] = i;
			mk[i] = 0;
		}
	}
	for(reg int i = 1; i <= n; ++ i ) {
		if(corcnt[i] == 0) {
			for(reg int j = 1; j <= n; ++ j ) {
				if(mk[j]) {
					cor[i] = j;
					mk[j] = 0;
				}
			}
		}
	}
	for(reg int i = 1; i <= n; ++ i ) {
		while(len[cor[i]] > corcnt[i]) {
			for(reg int j = 1; j <= n + 1; ++ j ) {
				if(j == cor[i]) continue;
				if(len[j] == m) continue;
				if(len[cor[i]] == corcnt[i]) break;
				stp ++;
				stpa[stp] = cor[i];
				stpb[stp] = j;
				++ len[j];
				a[j][len[j]] = a[cor[i]][len[cor[i]]];
				a[cor[i]][len[cor[i]]] = 0;
				-- len[cor[i]];
			}
		}
		for(reg int j = 1; len[cor[i]] != m; j = j % (n + 1) + 1 ) {
			if(j == cor[i]) continue;
			mk1 = 0;
			for(reg int k = 1; k <= len[j]; ++ k ) {
				if(a[j][k] == i) {
					mk1 = k;
					break;
				}
			}
			if(!mk1) continue;
			while(len[j] >= mk1) {
				if(a[j][len[j]] == i) {
					stp ++;
					stpa[stp] = j;
					stpb[stp] = cor[i];
					++ len[cor[i]];
					a[cor[i]][len[cor[i]]] = i;
					a[j][len[j]] = 0;
					-- len[j];
					continue;
				}
				mk2 = 1;
				for(reg int k = 1; k <= n + 1; ++ k ) {
					if(k == cor[i]) continue;
					if(k == j) continue;
					if(len[k] == m) continue;
					if(a[j][len[j]] == i) continue;
					if(len[j] == mk1 - 1) break;
					mk2 = 0;
					stp ++;
					stpa[stp] = j;
					stpb[stp] = k;
					++ len[k];
					a[k][len[k]] = a[j][len[j]];
					a[j][len[j]] = 0;
					-- len[j];
				}
				if(mk2) {
//					for(reg int k = 1; k <= n + 1; ++ k ) {
//						if(k == cor[i]) continue;
//						if(k == j) continue;
//						mk3[1] = k;
//						mk3[2] = (len[j] - mk1) / 2;
//						while(len[k] != m - mk3[2]) {
//							stp ++;
//							stpa[stp] = k;
//							stpb[stp] = cor[i];
//							++ len[cor[i]];
//							a[cor[i]][len[cor[i]]] = a[k][len[k]];
//							a[k][len[k]] = 0;
//							-- len[k];
//						}
//					}
//					for(reg int k = mk3[1] + 1; k <= n + 1; ++ k ) {
//						if(k == cor[i]) continue;
//						if(k == j) continue;
//						mk4[1] = k;
//						mk4[2] = (len[j] - mk1) - mk3[2];
//						while(len[k] != m - mk4[2]) {
//							stp ++;
//							stpa[stp] = k;
//							stpb[stp] = cor[i];
//							++ len[cor[i]];
//							a[cor[i]][len[cor[i]]] = a[k][len[k]];
//							a[k][len[k]] = 0;
//							-- len[k];
//						}
//					}
//					while(len[j] >= mk1) {
//						if(a[j][len[j]] == i) {
//							stp ++;
//							stpa[stp] = j;
//							stpb[stp] = mk3[1];
//							++ len[mk3[1]];
//							a[mk3[1]][len[mk3[1]]] = i;
//							a[j][len[j]] = 0;
//							-- len[j];
//							continue;
//						}
//						else {
//							stp ++;
//							stpa[stp] = j;
//							stpb[stp] = mk4[1];
//							++ len[mk4[1]];
//							a[mk4[1]][len[mk4[1]]] = i;
//							a[j][len[j]] = 0;
//							-- len[j];
//							continue;
//						}
//					}
					break;
					
				}
			}
		}
	}
	printf("%d\n", stp);
	for(reg int i = 1; i <= stp; ++ i ) {
		printf("%d %d\n", stpa[i], stpb[i]);
	}
	return 0;
}


