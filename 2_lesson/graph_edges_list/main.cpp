#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

struct Graph{
    unsigned int N = 0;
    vector <int> vertices;
    vector <vector<int>> edges;
};

void add_vertice(Graph * graph, int value, vector<vector<int>> edges){
    graph->vertices.push_back(value);
    for (int i = 0; i < edges.size(); i++){
        graph->edges.push_back(edges[i]);
    }
    graph->N++;
}

void print_graph(Graph * graph){
    for (int i = 0; i < graph->N; i++){
        cout << graph->vertices[i] << ": ";
        for (int j = 0; j < graph->edges.size(); j++){
            if (graph->edges[j][0] == graph->vertices[i]){
                cout << graph->edges[j][1] << ' ';
            }
            else if (graph->edges[j][1] == graph->vertices[i]){
                cout << graph->edges[j][0] << ' ';
            }
        }
        cout << endl;
    }
}


vector<vector<int> > findAllCycles(Graph * graph)
{
    vector< vector<int> > cycles;

    function<void(vector<int>)> findNewCycles = [&](vector<int> sub_path)
    {
        auto visisted = [](int v, const vector<int> & path ){
            return find(path.begin(),path.end(),v) != path.end();
        };

        auto rotate_to_smallest = []( vector<int> path ){
            rotate(path.begin(), min_element(path.begin(), path.end()), path.end());
            return path;
        };

        auto invert = [&](vector<int> path){
            reverse(path.begin(),path.end());
            return rotate_to_smallest(path);
        };

        auto isNew = [&cycles]( const vector<int> & path ){
            return find(cycles.begin(), cycles.end(), path) == cycles.end();
        };

        int start_node = sub_path[0];
        int next_node;

        // visit each edge and each node of each edge
        for(auto edge : graph->edges)
        {
            if((edge[0] == start_node) || (edge[1] == start_node))
            {
                int node1 = edge[0], node2 = edge[1];

                if(node1 == start_node)
                    next_node = node2;
                else
                    next_node = node1;

                if( !visisted(next_node, sub_path) )
                {
                    // neighbor node not on path yet
                    vector<int> sub;
                    sub.push_back(next_node);
                    sub.insert(sub.end(), sub_path.begin(), sub_path.end());
                    findNewCycles(sub);
                }
                else if( sub_path.size() > 2 && next_node == sub_path.back() )
                {
                    // cycle found
                    auto p = rotate_to_smallest(sub_path);
                    auto inv = invert(p);

                    if( isNew(p) && isNew(inv) )
                        cycles.push_back( p );
                }
            }
        }
    };

    for(auto edge : graph->edges)
    {
        findNewCycles(vector<int>(1,edge[0]));
        findNewCycles(vector<int>(1,edge[1]));
    }

    return cycles;
}


int main() {
    Graph my_graph;

    vector<vector<int>> edges(0);

    add_vertice(&my_graph, 1, edges);

    edges = {{1, 2}};
    add_vertice(&my_graph, 2, edges);

    edges = {{1, 3}, {2, 3}};
    add_vertice(&my_graph, 3, edges);

    edges = {{1, 4}, {3, 4}};
    add_vertice(&my_graph, 4, edges);

    print_graph(&my_graph);

    vector<vector<int>> cycles = findAllCycles(&my_graph);

    cout << "Cycles: " << endl;
    for(int i = 0; i < cycles.size(); i++){
        for(int j = 0; j < cycles[i].size(); j++){
            cout << cycles[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}