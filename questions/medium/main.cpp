#include <iostream>
#include <vector>

using namespace std;

struct Graph{
    unsigned int N = 0;
    vector <int> vertices;
    vector <vector<int>> incidence_list;
};

void add_vertice(Graph * graph, int value, vector <int> edges){
    for (int i = 0; i < graph->N; i++){
        for (int j = 0; j < edges.size(); j++){
            if (graph->vertices[i] == edges[j]){
                graph->incidence_list[i].push_back(value);
            }
        }
    }
    graph->vertices.push_back(value);
    graph->incidence_list.push_back(edges);
    graph->N++;
}

void print_graph(Graph * graph){
    for (int i = 0; i < graph->N; i++){
        cout << graph->vertices[i] << ": ";
        for (int j = 0; j < graph->incidence_list[i].size(); j++){
            cout << graph->incidence_list[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(Graph* graph, int* colors, int vertice, int prev_vertice, vector<int> cycle){
    colors[vertice] = 1;
    cycle.push_back(vertice);
    for(int j = 0; j < graph->incidence_list[vertice].size(); j++){
        if (colors[graph->incidence_list[vertice][j]] == 0){
            dfs(graph, colors, graph->incidence_list[vertice][j], vertice);
        }
        if ((colors[graph->incidence_list[vertice][j]] == 1) && (graph->incidence_list[vertice][j] != prev_vertice)){
            cout << vertice;
        }
    }
}

void cycles(Graph * graph){
    int colors[graph->N];
    for (int i = 0; i < graph->N; i++){
        colors[i] = 0;
    }

    vector<int> new_cycle(0);
    dfs(graph, colors, 0, 0, &new_cycle);
}

int main() {
    Graph my_graph;

    vector <int> adj_vertices(0);
    add_vertice(&my_graph, 0, adj_vertices);

    adj_vertices = {0};
    add_vertice(&my_graph, 1, adj_vertices);

    adj_vertices = {0, 1};
    add_vertice(&my_graph, 2, adj_vertices);

    print_graph(&my_graph);

    cycles(&my_graph);

    return 0;
}