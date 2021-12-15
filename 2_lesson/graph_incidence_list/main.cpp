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

int main() {
    Graph my_graph;

    vector <int> adj_vertices(0);

    add_vertice(&my_graph, 1, adj_vertices);

    adj_vertices.push_back(1);
    add_vertice(&my_graph, 2, adj_vertices);

    print_graph(&my_graph);

    return 0;
}
