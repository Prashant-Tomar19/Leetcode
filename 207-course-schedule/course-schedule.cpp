

class Solution {
public:


bool can=true;
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        can = true;
        vector<vector<int>> adj(numCourses);
        vector<int>visited(numCourses);
        for(int i=0; i<prerequisites.size(); i++){
            int temp=prerequisites[i][1];
            adj[temp].push_back(prerequisites[i][0]);
        }
        for(int i=0; i<numCourses; i++){
            if(visited[i]==0){
                dfs(i,adj,visited);
                if(!can) return false;
            }
        }
        return can;
    }
    void dfs(int node,vector<vector<int>> &adj,vector<int> &visited){
         if(visited[node]==2) return;
        if(visited[node]==1){
            can=false;
            return ;
        }
        visited[node]=1;
        if(adj[node].size()==0) {
            visited[node]=2;
            return ;}
        for(int i=0; i<adj[node].size(); i++){
           if(can==false){return;} 
            dfs(adj[node][i],adj,visited);
        }
        visited[node]=2;
    }
};