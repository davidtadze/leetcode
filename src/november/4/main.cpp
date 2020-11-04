#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>

std::tuple<std::vector<int>, std::vector<int>> 
  calc_bfs(int n, int node, const std::vector<std::vector<int>>& edges);

auto main() -> int {
  int n = 4;
  std::vector<std::vector<int>> edges{{1, 0}, {1, 2}, {1, 3}};

  std::vector<int> mht;

  std::vector<int> bfs = std::get<0>(calc_bfs(n, 0, edges));
  int left = bfs.back();

  std::tuple<std::vector<int>, std::vector<int>>  
    bfs_parent = calc_bfs(n, left, edges);
  bfs = std::get<0>(bfs_parent);
  int right = bfs.back();

  std::vector<int> parent = std::get<1>(bfs_parent);

  std::vector<int> d{right};
  int cur_node = right;
  while (cur_node != left) {
    cur_node = parent[cur_node];
    d.push_back(cur_node);
  }


  if (d.size() % 2 == 1) {
    size_t mid = d.size() / 2;
    mht.push_back(d.at(mid)); 
  } else {
    size_t mid = d.size() / 2;
    mht.push_back(d.at(mid - 1));
    mht.push_back(d.at(mid)); 
  }

  for (auto const& node : mht) {
    std::cout << node << std::endl;
  }

  return 0;
}

std::tuple<std::vector<int>, std::vector<int>> 
  calc_bfs(int n, int node, const std::vector<std::vector<int>>& edges) {
  std::queue<int> q;
  q.push(node);

  std::vector<int> bfs;

  std::vector<bool> visited(n);
  std::vector<int> parent(n);

  while(!q.empty()) {
    int first = q.front();
    q.pop();

    bfs.push_back(first);
    visited[first] = true;

    for (auto edge : edges) {
      if(edge[0] == first && !visited[edge[1]]) {
        parent[edge[1]] = edge[0];
        q.push(edge[1]);
      } else if (edge[1] == first && !visited[edge[0]]) {
        parent[edge[0]] = edge[1];
        q.push(edge[0]);
      }
    }
  }

  return std::make_tuple(bfs, parent);
}