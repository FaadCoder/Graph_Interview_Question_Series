class Solution {
unordered_map<string,priority_queue<string,vector<string>,greater<string>>> graph;
vector<string> result;
void dfs(string src="JFK")
{
    auto & pq = graph[src];
    while(!pq.empty())
    {
        string next_vertex = pq.top();
        pq.pop();
        dfs(next_vertex);
    }
    result.push_back(src);
}

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        graph.clear();
        result.clear();
        for(vector<string> &ticket:tickets)
        {
            graph[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(result.begin(),result.end());
        return result;
    }
};
