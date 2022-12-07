#include <climits>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int numCities, tradeRoutes, cityA, cityB, routeCost;
	scanf("%d", &numCities);
	scanf("%d", &tradeRoutes);

	vector<pair<int, int>> graph[numCities];

	for (int i = 0; i < tradeRoutes; ++i)
	{
		scanf("%d %d %d", &cityA, &cityB, &routeCost);

		graph[cityA - 1].push_back(make_pair(cityB, routeCost));
		graph[cityB - 1].push_back(make_pair(cityA, routeCost));
	}

	// Number of cities with pencils
	int pencilCityCount;
	scanf("%d", &pencilCityCount);

	int pencilCost[numCities];
	fill_n(pencilCost, numCities, -1);

	// Set cost of pencils at each town
	for (int x = 0; x < pencilCityCount; ++x)
	{
		int z, p;
		scanf("%d %d", &z, &p);
		pencilCost[z - 1] = p;
	}

	// Get destination (D)
	int destination;
	scanf("%d", &destination);
	
	// Array of costs (distances) from destination to each city
  int costs[numCities];
  fill_n(costs, numCities, INT_MAX);

	// Create queue
  auto comparator = [&](int& a, int& b){return costs[a - 1] > costs[b - 1];};
	priority_queue<int, vector<int>, decltype(comparator)> queue(comparator);

	bool visited[numCities];
	fill_n(visited, numCities, false);

	costs[destination - 1] = 0;
	queue.push(destination); // Add destination

	// Continue while queue is not empty
	while (!queue.empty())
	{
		// Get top node and pop queue
		int node = queue.top();
		int cost = costs[node - 1];
		queue.pop(); // Pop queue

		// Iterate through each connection of the current node
		for (auto& connection : graph[node - 1])
		{
			// Get other node n and calculate possible new cost
			int other = connection.first;
			int tempCost = connection.second + cost;

			// Replace cost if there is a lower cost
			if (tempCost < costs[other - 1] && !visited[other - 1])
			{
				costs[other - 1] = tempCost;
				queue.push(other);
			}
		}

        // Set current visited to true
		visited[node-1] = true; 
	}

	int minCost = INT_MAX; // Start at max value
	for (int i = 0; i < numCities; ++i)
	{
		if (pencilCost[i] == -1) continue; // No pencil available
		int possibleCost = costs[i] + pencilCost[i];
		if (possibleCost < minCost)
		{
			minCost = possibleCost;
		}
	}
  
  // Print minimum cost found
	if(minCost == INT_MAX)
  {
    printf("-1\n");
  }
	else
  {
    printf("%d\n", minCost);
  }

	return 0;
}
