#ifndef GRAPH_H
#define GRAPH_H

#include <bits/stdc++.h>

class Graph {
private:
    int N;
public:
    Graph(int);

    bool canSwap(std::vector <std::vector <int>>, int, int);
    bool existsCycle(std::vector <std::vector <int>>, int, int);
    bool existsEdge(std::vector <std::vector <int>>, int, int);

    std::vector <std::vector <int>> addEdge(std::vector <std::vector <int>>, int, int);
    std::vector <std::vector <int>> swapRelation(std::vector <std::vector <int>>, int, int);
    std::vector <std::vector <int>> inverseGraph(std::vector <std::vector <int>>);
    std::vector <int> getChildrens(std::vector <std::vector <int>>, int A);

    void getTopologicalSort(std::vector <std::vector <int>>, std::stack <int> &, std::vector <bool> &, int);

    bool getSwap(std::vector <std::vector <int>>, int, int);
    void getCommander(std::vector <std::vector <int>>, std::vector<int>, int);
    void getMeeting(std::vector <std::vector <int>>);

    ~Graph();
};

#endif /* GRAPH_H */
