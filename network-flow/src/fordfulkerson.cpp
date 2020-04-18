#include "fordfulkerson.hpp"

int FordFulkerson::dfs(int i, std::vector<int> &visited, std::vector<int>& parent)
{
	visited[i] = 1;
	std::map<int, int> adj = residual[i];
	int ret;
	if (i == t)
		ret = 1;
	else
		ret = 0;

	for (auto &y: adj)
	{
		int j = y.first;
		if (!visited[j])
		{
			parent[j] = i;
			visited[j] = 1;
			ret |= dfs(j, visited, parent);
		}
	}

	return ret;
}

void FordFulkerson::calculate_flows()
{
    std::vector<int> visited (n + 1), parent(n + 1);
	while (dfs(s, visited, parent))
	{
		// udpate res and f
		int bottleneck = (int)1e8;

		for (int nd = t; nd != s; nd = parent[nd])
			bottleneck = std::min(bottleneck, residual[parent[nd]][nd]);

		// for (int nd = t; nd != s; nd = parent[nd])
		// 	std::cout << nd << " ";
		// std::cout << "\n";

		for (int nd = t; nd != s; nd = parent[nd])
		{
			// pair<int, int> edge = {parent[nd], nd};
			if (graph[parent[nd]].count(nd))
			{
				// forward edge
				flow[parent[nd]][nd] += bottleneck;
			}
			else
			{
				// backward edge
				flow[nd][parent[nd]] -= bottleneck;
				if (!flow[nd][parent[nd]])
					flow[nd].erase(parent[nd]);
			}

			// update residual graph
			residual[nd][parent[nd]] += bottleneck;
			residual[parent[nd]][nd] -= bottleneck;
			if (!residual[parent[nd]][nd])
				residual[parent[nd]].erase(nd);
		}
		fill(parent.begin(), parent.end(), 0);
		fill(visited.begin(), visited.end(), 0);
		visited[s] = 1;
	}
}

int FordFulkerson::get_max_flow()
{
    int f = 0;
	for (auto &i: flow[s])
		f += i.second;
	return f;
}

int FordFulkerson::get_min_st_cut()
{
	std::set<int> a, b;
	std::queue<int> q;
	std::vector<int> visited (n + 1);
	q.push(s);
	visited[s] = 1;

	while (!q.empty())
	{
		int nd = q.front();
		a.insert(nd);
		q.pop();
		for (auto &i: residual[nd])
		{
			if (!visited[i.first])
			{
				q.push(i.first);
				visited[i.first] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++)
		if (!visited[i])
			b.insert(i);

	int mincut = 0;

	// for (int nd: a)
	// 	std::cout << nd << " ";
	// std::cout << "\n";
	// for (int nd: b)
	// 	std::cout << nd << " ";
	// std::cout << "\n";

	for (int nd: a)
	{
		for (auto &i: graph[nd])
		{
			if (b.count(i.first))
			{
				mincut += i.second;
			}
		}
	}

	return mincut;
}