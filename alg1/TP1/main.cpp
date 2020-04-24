#include <bits/stdc++.h>
#include "graph.h"

int main(int argc, char const *argv[]) {
    if (argc != 2) {
        std::cerr << "Ops.. o número de argumentos passados está incorreto =/" << std::endl;
        return 1;
    }

    std::ifstream entrada = std::ifstream(std::string(argv[1]));
    int N, M, I;
    
    entrada >> N >> M >> I;

    /* Get students age */
    std::vector <int> stud_ages; stud_ages.push_back(0);
    int age;
    for (int i = 0; i < N; i++) {
        entrada >> age;
        stud_ages.push_back(age);
    }

    /* Create graph with edges */
    int x, y;
    Graph graph = Graph(N+1);
    std::vector <std::vector <int>> g(N+1);
    for (int i = 0; i < M; i++) {
        entrada >> x >> y;
        g = graph.addEdge(g, x, y);
    }

    /* Read and answer each command */
    char command; 
    for (int i = 0; i < I; i++) {
        entrada >> command;
        if (command == 'C') {
            int E;
            entrada >> E;
            graph.getCommander(g, stud_ages, E);
        } 
        else if (command == 'S') {
            int A, B;
            entrada >> A >> B;
            if (graph.getSwap(g, A, B)) {
                std::cout << "S T" << std::endl;
                /* Checagem se a aresta que vamos inverter vai de A->B ou de B->A */
                if (graph.existsEdge(g, A, B))
                    g = graph.swapRelation(g, A, B);
                else
                    g = graph.swapRelation(g, B, A);                    
            }
            else {
                std::cout << "S N" << std::endl;   
            }
        } 
        else if (command == 'M') {
            graph.getMeeting(g);
        }
        else {
            std::cout << "O commando '" << command << "' não é válido. =/";
        }
    }
    return 0;
}
