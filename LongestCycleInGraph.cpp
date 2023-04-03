
//Link - https://leetcode.com/problems/longest-cycle-in-a-graph/description/

#include <bits/stdc++.h>
using namespace std;

// Approach 1

class Solution
{
public:
    int longestCycle(vector<int> &edges)
    {
        int n = edges.size();

        // create indegree array
        vector<int> indegree(n);

        // create a visited array
        vector<bool> visited(n, false);

        for (auto i : edges)
        {
            if (i != -1)
            {
                indegree[i]++;
            }
        }

        // Kahn's algorithm starts.
        // create a queue for the bfs traversal
        queue<int> q;

        // push all vectices with zero indegree into queue
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        while (!q.empty())
        {
            int front = q.front();
            q.pop();

            visited[front] = true;

            int neighbor = edges[front];

            if (neighbor != -1)
            {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0)
                {
                    q.push(neighbor);
                }
            }
        }
        // Kahn's algorithm ends.

        int result = -1;

        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                int neighbor = edges[i];

                int count = 1;
                visited[i] = true;

                // iterate in the cycle
                while (neighbor != i)
                {
                    visited[neighbor] = true;
                    count++;
                    neighbor = edges[neighbor];
                }

                result = max(result, count);
            }
        }

        return result;
    }
};


//Appeoach - 2

class Solution
{
public:
    int result = -1; // to store the longest cycle length
    void dfs(int src, vector<int> &edges, vector<bool> &visited, vector<bool> &recurStack, vector<int> &count)
    {
        // if there is an edge from src node
        if (src != -1)
        {
            visited[src] = true;
            recurStack[src] = true;
            int dest = edges[src]; // finding the destination node
            if (dest != -1 && !visited[dest])
            {
                // if it is possible to move to destination node
                // means cycle is not yet found
                // update the count of destination node in the count array
                count[dest] = count[src] + 1;
                // also make dfs call to dest node
                dfs(dest, edges, visited, recurStack, count);
            }
            else if (dest != -1 && recurStack[dest] == true)
            {
                // cycle found at the destination node
                // update the result
                result = max(result, count[src] - count[dest] + 1);
            }

            // before returing from current recursion call
            //  make src node false in recurStack Array
            recurStack[src] = false;
        }
    }
    int longestCycle(vector<int> &edges)
    {

        // here we are not required to create adjacency list
        //  because we can easily extract u and v from edges array
        int n = edges.size();
        // create visited and recurrStack vector
        vector<bool> visited(n, false);
        vector<bool> recurStack(n, false);
        // create count array to store the count of the node being visited in the cycle
        //  initialize all node as 1
        vector<int>
            count(n, 1);

        // before dfs
        for (int i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                dfs(i, edges, visited, recurStack, count);
            }
        }
        return result;
    }
};