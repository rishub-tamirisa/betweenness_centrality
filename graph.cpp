#include "graph.h"

//O(1)
void Graph::insertVertex(int key) {
    if (adj_list.find(key) == adj_list.end()) {
        adj_list[key] = new Vertex(key);
    }
}

//O(max(deg(v1), deg(v2))) ~ O(1)
void Graph::insertEdge(int k1, int k2, int w) {
    if (adj_list.find(k1) != adj_list.end() && adj_list.find(k2) != adj_list.end()) {
        Vertex* v = adj_list[k1];
        Vertex* v2 = adj_list[k2];
        if (adj_list[k2]->degree <= adj_list[k1]->degree) {
            v = adj_list[k2];
            v2 = adj_list[k1];
        }
        for (auto edge : v->edges) {
            if (edge->v1 == v2 || edge->v2 == v2) {
                return; // edge already exists
            }
        }

        Edge* edge = new Edge(adj_list[k1], adj_list[k2], w);
        edge_list.push_back(edge);
        adj_list[k1]->edges.push_front(edge);
        adj_list[k1]->degree++;
        adj_list[k2]->edges.push_front(edge);
        adj_list[k2]->degree++;
    }
}

//O(1)
std::list<Graph::Edge*> Graph::incidentEdges(int key) {
    return adj_list[key]->edges;
}

//O(max(deg(v1), deg(v2))) ~ O(1)
bool Graph::areAdjacent(int k1, int k2) {
    if (adj_list.find(k1) != adj_list.end() && adj_list.find(k2) != adj_list.end()) {
        Vertex* v1 = adj_list[k1];
        Vertex* v2 = adj_list[k2];
        Vertex* v = v2;
        if (v1->degree <= v2->degree) {
            v = v1;
        }
        for(auto edge : v->edges) {
            if ((edge->v1 == v1 && edge->v2 == v2) || (edge->v1 == v2 && edge->v2 == v1)) {
                return true;
            }
        }
    }
    return false;
}

std::vector<int> Graph::BFS(int root, int target) {
    std::queue<int> q;
    std::unordered_map<int, int> path;
    q.push(root);
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        if (front == target) {
            break;
        }
        for (auto edge : adj_list[front]->edges) {
            int neighbor = edge->v1->ID == front ? edge->v2->ID : edge->v1->ID;
            if (path.find(neighbor) == path.end()) {
                q.push(neighbor);
                path[neighbor] = front;
            } 
        }
    }
    std::vector<int> result;
    while (target != root) {
        result.push_back(target);
        target = path[target];
    }
    result.push_back(root);
    std::reverse(result.begin(), result.end());
    return result;
}

void Graph::Brandes_BFS_helper(int s, std::unordered_map<int,std::vector<int>>& pred, 
                                        std::unordered_map<int, int>& sigma, std::stack<int>& stack){
    std::unordered_map<int,int> dist;
    std::queue<int> q; 
    // sigma[std::to_string(s) + "_" + std::to_string(s)] = 1;
    
    for (auto n : adj_list) {
        dist[n.first] = -1;
    }
    q.push(s);
    dist[s] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        stack.push(v);
        for (auto edge : adj_list[v]->edges) {
            int w = edge->v1->ID == v ? edge->v2->ID : edge->v1->ID;
            if (dist[w] == -1) {
                dist[w] = dist[v] + 1;
                q.push(w);
                
            }
            if (dist[w] == dist[v] + 1) {
                pred[w].push_back(v);
                sigma[w] = sigma[w] + sigma[v];

            }
        }
    }
}

std::vector<std::pair<int, double>> Graph::betweenness_centrality() {
    std::map<int, double> CB;
    std::unordered_map<int,std::vector<int>> pred;
    std::unordered_map<int, int> sigma;
    std::unordered_map<int, int> delta;
    for (auto m : adj_list) {
        CB[m.first] = 0;
    }
    for (auto n : adj_list) {
        int s = n.first;
        pred.clear();
        std::stack<int> stack;
        for (auto m : adj_list) {
            delta[m.first] = 0;
            sigma[m.first] = 0;
        }
        sigma[s] = 1;
        // std::cout << "-------------------" << std::endl;
        Brandes_BFS_helper(s, pred, sigma, stack);
        while(!stack.empty()) {
            int w = stack.top();
            stack.pop();
            
            for (auto v : pred[w]) {
                // std::cout << delta[v] << " " << v << std::endl;
                delta[v] = delta[v] + 
                ((double) sigma[v] / (double) sigma[w]) * (1 + delta[w]);
                // std::cout << sigma[std::to_string(s) + "_" + std::to_string(v)] / (double) sigma[std::to_string(s) + "_" + std::to_string(w)] << std::endl;
                
            }
            if (w != s) {
                CB[w] = CB[w] + delta[w];
            }
        }
        // sigma.clear();
    }
    std::vector<std::pair<int, double>> results;
    for (auto& n : CB) {
        results.push_back(n);
    }
    std::sort(results.begin(), results.end(), [ ]( const std::pair<int, double>& first, const std::pair<int, double>& second ) {
        return first.second > second.second;
    });
    return results;
}

Graph Graph::connected_subgraph(int root, int size, bool write) {
    
    std::queue<int> q;
    Graph g;
    std::ofstream ofs("connected_size_" + std::to_string(size)); 
    std::unordered_map<int, int> visited;
    q.push(root);
    int counter = 1;
    while (!q.empty()) {
        int front = q.front();
        q.pop();
        
        for (auto edge : adj_list[front]->edges) {
            int neighbor = edge->v1->ID == front ? edge->v2->ID : edge->v1->ID;
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                g.insertVertex(front);
                g.insertVertex(neighbor);
                g.insertEdge(front, neighbor, 1);
                if (write)
                    ofs << front << " " << neighbor << "\n";
                counter++;
                if (counter == size) {
                    return g;
                }
                visited[neighbor]++;
                
            } 
        }
    }
    if (write) 
        ofs.close();
    return g;
}

//O(V+E)
Graph::~Graph() {
    for (Edge* edge : edge_list) {
        delete edge;
    }
    for (auto v : adj_list) {
        delete v.second;
    }
}

