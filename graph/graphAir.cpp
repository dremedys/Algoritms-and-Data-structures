#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;
//Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.
//If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order 
//input [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
//output ["JFK", "MUC", "LHR", "SFO", "SJC"]
//algo:First keep going forward until you get stuck. That's a good main path already.
// Remaining tickets form cycles which are found on the way back and get merged into that main path. 
//By writing down the path backwards when retreating from recursion, merging the cycles into the main path is easy - 
//the end part of the path has already been written, the start part of the path hasn't been written yet,
// so just write down the cycle now and then keep backwards-writing the path.
vector<string> findItinerary(vector<pair<string, string>> tickets) {
    for (auto ticket : tickets)
        targets[ticket.first].insert(ticket.second);
    visit("JFK");
    return vector<string>(route.rbegin(), route.rend());
}

map<string, multiset<string>> targets;
vector<string> route;

void visit(string airport) {
    while (targets[airport].size()) { //while it has targets
        string next = *targets[airport].begin(); //take a first end
        targets[airport].erase(targets[airport].begin()); //delete it
        visit(next);   // recursive
    }
    route.push_back(airport);
}