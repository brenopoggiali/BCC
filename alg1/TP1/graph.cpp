#include "graph.h"

Graph::Graph(int n) {
    this->N = n;
}

bool Graph::canSwap(std::vector <std::vector <int>> g, int A, int B) {
    g = swapRelation(g, A, B);
    if (existsCycle(g, A, B)) {
        g = swapRelation(g, B, A);
        return false;
    }
    return true;
}

bool Graph::existsCycle(std::vector <std::vector <int>> g, int A, int B) {
    int count = 0;
    std::vector <int> dist(this->N, 0);
    std::vector <int> result;

    for (int i = 0; i < this->N; i++) 
        for(int j : g[i]) dist[j]++;

    std::priority_queue <int> pq;
    for (int i = 0; i < this->N; i++) 
        if (dist[i] == 0) pq.push(i);

    while(!pq.empty()) {
        int top = pq.top(); pq.pop();
        result.push_back(top);
        std::vector<int>::iterator aux;
        for (aux = g[top].begin(); aux != g[top].end(); aux++)
            if(--dist[*aux] == 0) 
                pq.push(*aux);
        count++;
    }
    
    if(count != this->N) 
        return true;
    
    return false;
}

bool Graph::existsEdge(std::vector <std::vector <int>> g, int A, int B) {
    bool answer = false;
    for (int j : g[A]) {
        if (j == B) {
            answer = true;
            break;
        }
    }
    return answer;
}

std::vector <std::vector <int>> Graph::addEdge(std::vector <std::vector <int>> g, int A, int B) {
    g[A].push_back(B);
    return g;
}

std::vector <std::vector <int>> Graph::swapRelation(std::vector <std::vector <int>> g,int A, int B) {
    int position = 0;
    for (int i : g[A]) {
        if(i == B) 
            break;
        position++;
    }
    g[A].erase(g[A].begin()+position);
    g[B].push_back(A);
    return g;
}

std::vector <std::vector <int>> Graph::inverseGraph(std::vector <std::vector <int>> g) {
    std::vector <std::vector <int>> inv_graph(this->N);
    for (int i = 0; i < this->N; i++)
        for (int j : g[i])
            inv_graph[j].push_back(i);
    return inv_graph;
}

std::vector <int> Graph::getChildrens(std::vector <std::vector <int>> g, int A) {
    std::vector <int> childrens;
    std::priority_queue <int> pq;
    pq.push(A);
    while (!pq.empty()) {
        int top = pq.top(); pq.pop();
        for (int i : g[top]) {
            pq.push(i);
            childrens.push_back(i);
        }
    }
    return childrens;    
}

void Graph::getTopologicalSort(std::vector <std::vector <int>> g, std::stack <int> &pilha, std::vector <bool> &visited, int A) {
    visited[A] = true;
    std::vector<int>::iterator aux;
    for (aux = g[A].begin(); aux != g[A].end(); aux++)
        if (!visited[*aux])
            getTopologicalSort(g, pilha, visited, *aux);
    pilha.push(A);
}

bool Graph::getSwap(std::vector <std::vector <int>>  g, int A, int B) {
    bool can_swap = false;
    if (existsEdge(g, A, B))
        can_swap = canSwap(g, A, B);
    else if (existsEdge(g, B, A))
        can_swap = canSwap(g, B, A);
    
    return can_swap;
}

void Graph::getCommander(std::vector <std::vector <int>>  g, std::vector<int> ages, int A) {
    std::vector <std::vector <int>> inv_graph = inverseGraph(g);
    if (inv_graph[A].empty())
        std::cout << "C *" << std::endl;
    else {
        int youngest = 101;
        std::vector <int> childs = getChildrens(inv_graph, A);
        for (int i : childs)
            if (ages[i] < youngest) 
                youngest = ages[i];
        std::cout << "C " << youngest << std::endl;
    }
}

void Graph::getMeeting(std::vector <std::vector<int>> g) {
    std::stack <int> pilha;
    std::vector<bool> visited(this->N, false);

    for (int i = 0; i < this->N; i++) {
        if (visited[i] == false)
            getTopologicalSort(g, pilha, visited, i);        
    }

    std::cout << "M ";
    while(!pilha.empty()) {
        if (pilha.top() != 0)
            std::cout << pilha.top() << " "; 
        pilha.pop();
    }
    std::cout << std::endl;
}

Graph::~Graph() {
}
