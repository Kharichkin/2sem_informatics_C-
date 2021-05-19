#include <iostream>
#include <vector>

using namespace std;

struct Tree;

struct Node{
    int value;
    Tree * left = nullptr;
    Tree * right = nullptr;
};

struct Tree{
    Node * root = nullptr;
    unsigned int number = 0;
};

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

void dfs(Graph* graph, int* colors, int vertice, Graph* tree){
    colors[vertice] = 1;
    vector <int> adj_vertices(0);

    for(int j = 0; j < graph->incidence_list[vertice].size(); j++){
        if (colors[graph->incidence_list[vertice][j]] == 0){
            adj_vertices.push_back(graph->incidence_list[vertice][j]);
            dfs(graph, colors, graph->incidence_list[vertice][j], tree);
        }
    }

    add_vertice(tree, vertice, adj_vertices);
}

Graph make_tree(Graph * graph){
    Graph* tree = new Graph;

    int colors[graph->N];
    for (int i = 0; i < graph->N; i++){
        colors[i] = 0;
    }

    dfs(graph, colors, 0, tree);

    return *tree;
}

int main() {
    Graph my_graph;

    vector <int> adj_vertices(0);
    add_vertice(&my_graph, 0, adj_vertices);

    adj_vertices = {0};
    add_vertice(&my_graph, 1, adj_vertices);

    adj_vertices = {0, 1};
    add_vertice(&my_graph, 2, adj_vertices);

    adj_vertices = {0, 1, 2};
    add_vertice(&my_graph, 3, adj_vertices);

    cout << "Graph: " << endl;
    print_graph(&my_graph);

    Graph tree;
    tree = make_tree(&my_graph);

    cout << "Tree: " << endl;
    print_graph(&tree);

    return 0;
}