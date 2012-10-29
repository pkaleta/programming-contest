/*
ID: piotrek4
LANG: C++
PROG: maze1
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <queue>
#include <cstring>

using namespace std;


ifstream fin("maze1.in");
ofstream fout("maze1.out");

const int MAX_H = 105;
const int MAX_W = 40;
const int INF = 1<<20;

vector<string> maze;
int w, h;
vector<int> edges[MAX_H*MAX_W];
bool isexit[MAX_H*MAX_W];


int bfs(int v) {
    int dist[MAX_H*MAX_W];
    queue<int> q;

    memset(dist, 0, sizeof(dist));
    q.push(v);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < edges[u].size(); ++i) {
            int w = edges[u][i];
            if (dist[w] == 0) {
                dist[w] = dist[u]+1;
                if (isexit[w]) return dist[w];
                else q.push(w);
            }
        }
    }
}


int main() {
    int ret = 0;
    char c;
    string s;
    fin >> w >> h;

    getline(fin, s);
    for (int i = 0; i < 2*h+1; ++i) {
        getline(fin, s);
        maze.push_back(s);
    }

    int v = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            int x = 2*j+1;
            int y = 2*i+1;
            if (maze[y-1][x] == ' ') {
                if (y-1 == 0) isexit[v] = true;
                else edges[v].push_back(v-w);
            }
            if (maze[y+1][x] == ' ') {
                if (y+1 == 2*h) isexit[v] = true;
                else edges[v].push_back(v+w);
            }
            if (maze[y][x-1] == ' ') {
                if (x-1 == 0) isexit[v] = true;
                else edges[v].push_back(v-1);
            }
            if (maze[y][x+1] == ' ') {
                if (x+1 == 2*w) isexit[v] = true;
                else edges[v].push_back(v+1);
            }
            ++v;
        }
    }

    for (int i = 0; i < v; ++i) ret = max(ret, bfs(i));

    fout << ret+1 << endl;

    return 0;
}
