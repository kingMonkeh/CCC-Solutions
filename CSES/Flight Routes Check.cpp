#include <bits/stdc++.h>

#define int long long
#define vi std::vector<int>

/*

*/

std::vector<std::vector<vi>> graph;
vi reachable;

void dfs (int cur, int mode){

	reachable[cur] = true;

	for (auto& adj: graph[cur][mode]){
		if (!reachable[adj]){
			dfs(adj, mode);
		}
	}

}

signed main (){

	int n, m;
	std::cin >> n >> m;

	graph.resize(n + 1, std::vector<vi> (2));
	//graph[node][0] --> forward edges
	//graph[node][1] --> backward edges
	reachable.resize(n + 1, false);
	for (int i = 0; i < m; i++){
		int a, b;
		std::cin >> a >> b;
		graph[a][0].push_back(b);
		graph[b][1].push_back(a);
	}

	dfs (1, 0);

	for (int i = 1; i <= n; i++){
		if (!reachable[i]){
			std::cout << "NO\n" << 1 << ' ' << i;
			return 0;
		}
	}

	for (int i = 1; i <= n; i++) reachable[i] = false;

	dfs (1, 1);

	for (int i = 1; i <= n; i++){
		if (!reachable[i]){
			std::cout << "NO\n" << i << ' ' << 1;
			return 0;
		}
	}

	std::cout << "YES";

	return 0;

}