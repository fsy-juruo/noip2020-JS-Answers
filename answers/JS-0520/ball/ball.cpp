#include <bits/stdc++.h>

using namespace std;

int n, m;
int box[60][410], top[60];
pair<int, int> mve[820010];
int ball[410];

bool ok(void) {
    memset(ball, 0, sizeof(ball));
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= top[i]; ++j) {
            if (ball[box[i][j]] != 0 && ball[box[i][j]] != i) {
                return 0;
            }
            ball[box[i][j]] = i;
        }
    }
    return 1;
}

void dfs(int step, int maxi) {
    if (ok()) {
        printf("%d\n", step - 1);
        for (int i = 1; i < step; ++i) {
            printf("%d %d\n", mve[i].first, mve[i].second);
        }
        exit(0);
    }
    if (step > maxi) {
        return;
    }
    for (int i = 1; i <= n + 1; ++i) {
        for (int j = 1; j <= n + 1; ++j) {
            if (j != i && top[i] != 0 && top[j] != m) {
                ++top[j];
                box[j][top[j]] = box[i][top[i]];
                --top[i];
                mve[step] = make_pair(i, j);
                dfs(step + 1, maxi);
                ++top[i];
                box[i][top[i]] = box[j][top[j]];
                --top[j];
            }
        }
    }
}

int main(void) {
	freopen("ball.in", "r", stdin);
	freopen("ball.out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &box[i][j]);
        }
        top[i] = m;
    }

    if (ok()) {
        puts("0");
        return 0;
    }

    for (int i = 1; ; i = i * 7 / 5 + 1) {
        dfs(1, i);
    }

	return 0;
}

