#include<iostream>
#include<vector>
#include<queue>
#include<stack>
using namespace std;

class Graph{
    public:
        vector<vector<int> > adj_mat;
        
        Graph(int n){
            adj_mat = vector<vector<int> >(n, vector<int>(n, 0));
        }
    
    void add_edge(int u, int v){
        if (u < adj_mat.size() && v < adj_mat.size()) {
            adj_mat[u][v] = 1;
            adj_mat[v][u] = 1;
        }
    }
    
    void bfs(int source){
        queue<int> q;
        vector<bool> visited(adj_mat.size(), false);
        q.push(source);
        visited[source] = true;
        
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            cout << temp << " ";
            
            for(int i = 0; i < adj_mat.size(); i++){
                if(adj_mat[temp][i] == 1 && !visited[i]){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    
    void dfs(int source){
        stack<int> s;
        s.push(source);
        vector<bool> visited(adj_mat.size(), false);
        visited[source] = true;
        
        while(!s.empty()){
            int temp = s.top();
            s.pop();
            cout << temp << " ";
            
            for(int i = 0; i < adj_mat.size(); i++){
                if(adj_mat[temp][i] == 1 && !visited[i]){
                    s.push(i);
                    visited[i] = true;
                }
            }
        }
    }
    
    void print_adj_mat(){
        int n = adj_mat.size();
        for(int i = 0; i < n; i++){
            cout << i << ": ";
            for(int j = 0; j < n; j++){
                cout << adj_mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    bool cycle(){
    	stack<int>s;
    	vector<bool>visited(adj_mat.size(), false);
    	vector<int>parent(adj_mat.size(),-1);
    	s.push(0);
    	parent[0] = 1;
    	while(!s.empty()){
    		int temp = s.top();
    		visited[temp] = true;
    		s.pop();
    		for(int i = 0; i < adj_mat.size(); i++){
                if(adj_mat[temp][i] == 1 && !visited[i]){
                    s.push(i);
                    visited[i] = true;
                    if(parent[i] == -1){
                    	parent[i] = temp;
					}
					else{
						return true;
					}
                }
            }
		}
		return false;
	}
};

int main(){
    int size = 6;
    Graph g1(size);
    g1.add_edge(0, 1);
    g1.add_edge(1, 2);
    g1.add_edge(2, 4);
    g1.add_edge(1, 3);
    g1.add_edge(3, 5);
    g1.print_adj_mat();
    return 0;
}

