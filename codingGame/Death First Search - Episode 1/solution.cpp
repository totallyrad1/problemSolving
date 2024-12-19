#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stack>
# define all(x) begin(x), end(x)
# define rall(x) rbegin(x), rend(x)
using namespace std;

struct Links{
    int index;
    map<int, Links*> cons;

    Links(int n){
        this->index = n;
    }
    void addConnection(int num, Links *node){
        if(cons.find(num) == cons.end()){
            cons.insert({num, node});
        }
    }
    void removeConnections(int num){
        if(cons.find(num) != cons.end()){
            cons.erase(num);
        }
    }
    stack<int> recGetPath(int goal, Links *node, vector<int> &visited){
        if(find(all(visited), node->index) != visited.end())
            return stack<int> ();
        
        stack<int> path;

        path.push(node->index);
        visited.push_back(node->index);
        if(node->index == goal)
            return path;
        for(auto &con: node->cons){
            stack<int> subPath = recGetPath(goal, con.second, visited);

            if(!subPath.empty()){
                stack<int> rsubPath;
                while(!subPath.empty()){
                    rsubPath.push(subPath.top());
                    subPath.pop();
                }
                while(!rsubPath.empty()){
                    path.push(rsubPath.top());
                    rsubPath.pop();
                }
                return path;
            }
        }
        return stack<int> ();
    }
    vector<stack<int>> getPaths(vector<int> gatewayIndexs){
        vector<stack<int>> paths;
        stack<int> path;
        vector<int> visited;
        for(auto &ind: gatewayIndexs){
            visited.clear();
            path = recGetPath(ind, this, visited);
            if(!path.empty())
                    paths.push_back(path);
            for(auto &con : cons){
                visited.clear();
                path = recGetPath(ind, con.second, visited);
                if(!path.empty())
                    paths.push_back(path);
            }
        }
        return paths;
    }
    pair<int, int> getShortestPath(vector<stack<int>> paths, vector<int> gatewayIndexs){
        int lowestStackSize = 2147483647;
        pair<int, int> result;
        for(auto &path: paths){
            if(find(gatewayIndexs.begin(), gatewayIndexs.end(), path.top()) != gatewayIndexs.end() && path.size() == 1){
                return {this->index, path.top()};
            }
            else if(find(gatewayIndexs.begin(), gatewayIndexs.end(), path.top()) != gatewayIndexs.end()){
                if(lowestStackSize > path.size() && path.size() >= 2){
                    lowestStackSize = path.size();
                    int n1, n2;
                    n1 = path.top();
                    path.pop();
                    n2 = path.top();
                    result = {n1,n2};
                }
            }
        }
        return result;
    }
};

void makeLinks(map<int, Links*> &links, vector<pair<int,int>> cons){
    for(auto &con: cons){
        map<int, Links*>::iterator it = links.find(con.first);
        if(it == links.end()){
            map<int, Links*>::iterator it1 = links.find(con.second);
            if(it1 == links.end()){ 
                links.insert({con.first, new Links(con.first)});
                links.insert({con.second, new Links(con.second)});
                links[con.first]->addConnection(con.second, links[con.second]);
                links[con.second]->addConnection(con.first, links[con.first]);
            }else{
                links.insert({con.first, new Links(con.first)});
                links[con.first]->addConnection(con.second, links[con.second]);
                links[con.second]->addConnection(con.first, links[con.first]);
            }
        }else{
            map<int, Links*>::iterator it1 = links.find(con.second);
            if(it1 == links.end()){
                links.insert({con.second, new Links(con.second)});
                links[con.first]->addConnection(con.second, links[con.second]);
                links[con.second]->addConnection(con.first, links[con.first]);
            }else{
                links[con.first]->addConnection(con.second, links[con.second]);
                links[con.second]->addConnection(con.first, links[con.first]);
            }
        }
    }
}

void printLinks(map<int, Links*> &links) {
    for (auto &link : links) {
        cerr << "Node " << link.first << " (Index: " << link.second->index << ") connections: ";
        if (link.second->cons.empty()) {
            cerr << "None";
        } else {
            for (auto &connection : link.second->cons) {
                cerr << connection.first << " ";
            }
        }
        cerr << endl;
    }
}

void printPossiblePaths(const vector<stack<int>>& possiblePaths) {
    // Iterate over each stack in the vector of possiblePaths
    cerr << "possible paths size " << possiblePaths.size() << endl;
    for (int i = 0; i < possiblePaths.size(); ++i) {
        cerr << "Path " << i + 1 << ": ";
        
        // Print each element in the stack (since it's a stack, we'll need to pop to print from bottom to top)
        stack<int> temp = possiblePaths[i]; // Create a temporary copy of the stack
        vector<int> pathElements; // To store the elements in order
        
        // Pop the elements from the stack and store them in pathElements
        while (!temp.empty()) {
            pathElements.push_back(temp.top());
            temp.pop();
        }

        // Print the elements in reverse order (from top to bottom of the stack)
        for (int j = pathElements.size() - 1; j >= 0; --j) {
            cerr << pathElements[j];
            if (j > 0) cerr << " -> "; // Print an arrow between nodes
        }

        cerr << endl;
    }
}

int main()
{
    int n; // the total number of nodes in the level, including the gateways
    int l; // the number of links
    int e; // the number of exit gateways
    cin >> n >> l >> e; cin.ignore();
    vector<pair<int,int>> cons;
    vector<int> gatewayIndexs;
    for (int i = 0; i < l; i++) {
        int n1; // N1 and N2 defines a link between these nodes
        int n2;
        cin >> n1 >> n2; cin.ignore();
        cons.push_back({n1, n2});
    }
    for (int i = 0; i < e; i++) {
        int ei; // the index of a gateway node
        cin >> ei; cin.ignore();
        gatewayIndexs.push_back(ei);
    }
    
    map<int, Links*> links;
    makeLinks(links, cons);
    printLinks(links);
    // game loop
    while (1) {
        int si; // The index of the node on which the Bobnet agent is positioned this turn
        cin >> si; cin.ignore();
        cerr << si << endl;
        map<int, Links*>::iterator it = links.find(si);
        for(auto &p: gatewayIndexs){
            cerr << "index of gate" <<p << endl;
        }
        if(it != links.end()){
            vector<stack<int>> possiblePaths = it->second->getPaths(gatewayIndexs);
            printPossiblePaths(possiblePaths);
            pair<int, int> path = it->second->getShortestPath(possiblePaths, gatewayIndexs);
            links[path.first]->removeConnections(path.second);
            links[path.second]->removeConnections(path.first);
            cout << path.first << " " << path.second << endl;
        }

    }
}