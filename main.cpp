#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int c, n, m, l;

int first[100100], nxt[100100], to[100100];
bool vis[100100];

int sum,h;
int e;

void add(int u, int v) {
	to[e] = v;
	nxt[e] = first[u];
	first[u] = e++;
}
void dfs(int s) {
	vis[s] = true;
	for (int i = first[s];~i;i = nxt[i]) {
		int v = to[i];
		if (!vis[v]) {
			dfs(v);
		}
	}
}

int main() {
	cin >> c;

	for (int i = 0;i < c;i++) {
		memset(vis, false, sizeof(vis));
		memset(first, -1, sizeof(first));
		cin >> n >> m >> l;
		int d1, d2;
		
		for (int i = 0;i < m;i++) {
			cin >> d1 >> d2;
			add(d1, d2);
		}
		sum = 0;
		
		for (int i = 0;i < l;i++) {
			cin >> h;
			dfs(h);
		}
		for (int i = 1;i <= n;i++) {
			if (vis[i])
				sum++;
		}
		cout << sum << endl;
	}
	
	return 0;
}
