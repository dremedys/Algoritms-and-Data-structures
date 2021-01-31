#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//here are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
//Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
bool canFinish(int n, vector<vector<int>>& pre) { //DFS
    vector<vector<int>> adj(n, vector<int>());  //make adj leist
    vector<int> degree(n, 0);  //degree[i] is number of prereq of i th subject
    for (auto &p: pre) {  
        adj[p[1]].push_back(p[0]); //p[1] is prereq of p[0]   p[1] ---> p[0]   prereq of subject --> subject
        degree[p[0]]++;  //then ++ prereq number
    }
    queue<int> q;

    for (int i = 0; i < n; i++)
        if (degree[i] == 0) 
            q.push(i);  //if we have subj that doesnt have prereq
    while (!q.empty()) { //while queue is not empty AHAHAAHAHA
        int curr = q.front(); 
        q.pop();
        n--;
        for (auto next: adj[curr])
            if (--degree[next] == 0) q.push(next);
    }
    return n == 0;
}