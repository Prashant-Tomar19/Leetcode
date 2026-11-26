class Solution {
public:

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<int>visited(n,0);
        dfs(0,rooms,visited);
        for(int i=0; i<rooms.size(); i++){
            if(visited[i]==0){
                return false;
            }
        }
        return true;
    }
    void dfs(int node,vector<vector<int>>& rooms,vector<int> &visited){
        if(visited[node]==1) return;
        visited[node]=1;
        for(int i=0; i<rooms[node].size(); i++){
            if(visited[rooms[node][i]]!=1){
                dfs(rooms[node][i],rooms,visited);
            }
        }
    }
};