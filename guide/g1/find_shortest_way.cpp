#include"scene.h"
#include<vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include<iostream>
#include <climits>
#define MAX_NUM 100
#define INF 
//vector<vector<int>> mymap(MAX_NUM, vector<int>(MAX_NUM));
typedef struct each_site {
    bool toilet;
    int distance = -1;
    string name;
};
vector<each_site> csv_read2();
vector<vector<int>> mymap;
int my_map[30][30] = {
{0, 150, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, 300, -1, -1, -1},
{ 150,0,220,-1,-1,-1,-1,-1,-1,-1,-1,-1,180,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,200,0,142,-1,-1,-1,-1,-1,-1,-1,-1,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,142,0,150,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,150,0,170,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,170,0,165,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,165,0,120,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
/*8*/
{ -1,-1,-1,-1,-1,-1,120,0,230,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,176 },
{ -1,-1,-1,-1,-1,-1,-1,230,0,150,195,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,90 },
{ -1,-1,-1,-1,-1,-1,-1,-1,150,0,115,236,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
/*11*/
{ -1,-1,-1,-1,-1,-1,-1,-1,150,115,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,236,-1,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,265,-1,-1 },
{ -1,180,50,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,110,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
/*14*/
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,110,0,113,243,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,113,0,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,243,-1,0,200,203,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
/*17*/
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,200,0,100,-1,-1,-1,-1,-1,-1,-1,-1,-1,274,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,203,100,0,123,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,123,0,210,200,-1,-1,265,-1,-1,-1,-1,-1,-1 },
/*20*/
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,210,0,65,187,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,200,65,0,-1,-1,-1,-1,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,187,0,167,-1,-1,-1,-1,-1,-1,-1 },
/*23*/
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,167,0,-1,-1,-1,-1,-1,179,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,265,-1,-1,-1,-1,0,200,-1,-1,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,200,0,360,-1,-1,-1,-1 },
/*26*/
{ -1,164,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,360,0,210,-1,-1,-1 },
{ 300,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,210,0,-1,-1,-1 },
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,265,-1,-1,-1,-1,274,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0,-1,-1 },
/*29*/
{ -1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,179,-1,-1,-1,-1,-1,0,-1 },
{ -1,-1,-1,-1,-1,-1,-1,176,90,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,0 }
};
void init_map() {
	for (int i = 0; i < 30; i++) {
		vector<int> tmp;
		for (int j = 0; j < 30; j++) {
			tmp.push_back(my_map[i][j]);
		}
		mymap.push_back(tmp);
	}
}
vector<int> dijkstra(int n, const vector<vector<each_site>>& graph, int start, vector<int>& previous) {
    vector<int> dist(n, INT_MAX);    
    vector<bool> visited(n, false); 
    dist[start] = 0; 

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0, start });  
    fill(previous.begin(), previous.end(), -1);

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue;
        visited[u] = true;


        for (int v = 0; v < n; ++v) {
            if (!visited[v] && graph[u][v].distance != -1 && dist[u] + graph[u][v].distance < dist[v]) {
                dist[v] = dist[u] + graph[u][v].distance;
                pq.push({ dist[v], v });
                previous[v] = u; 
            }
        }
    }

    return dist;
}

vector<int> getPath(int start, int end, const vector<int>& previous) {
    vector<int> path;
    for (int at = end; at != -1; at = previous[at]) {
        path.push_back(at);
    }
    reverse(path.begin(), path.end());
    return path;
}


int calculateShortestPath(int n, vector<vector<each_site>>& graph, int start, int end, const vector<int>& mustVisit) {
    vector<int> totalPath;
    int totalCost = 0;
    vector<int> previous(n, -1);

   
    int prevNode = start;
    for (int i = 0; i < mustVisit.size(); ++i) {
        vector<int> dist = dijkstra(n, graph, prevNode, previous);
        if (dist[mustVisit[i]] == INT_MAX) {
            cout << "无法到达必经点！" << endl;
            return -1;
        }
        totalCost += dist[mustVisit[i]];  
        vector<int> path = getPath(prevNode, mustVisit[i], previous);
        if (i > 0) path.erase(path.begin()); 
        totalPath.insert(totalPath.end(), path.begin(), path.end());  
        prevNode = mustVisit[i];
    }
    vector<int> dist = dijkstra(n, graph, prevNode, previous);
    if (dist[end] == INT_MAX) {
        cout << "无法到达终点！" << endl;
        return -1;
    }
    totalCost += dist[end]; 
    vector<int> path = getPath(prevNode, end, previous); 
    path.erase(path.begin());  
    totalPath.insert(totalPath.end(), path.begin(), path.end()); 


    cout << "最短路径经过的点：";
    if (graph[totalPath[0]][totalPath[0]].name != graph[start][start].name) cout << graph[start][start].name << "->";
    for (int i = 0; i < totalPath.size();i++) {
        cout << graph[totalPath[i]][totalPath[i]].name;
        if (i < totalPath.size() - 1) cout << "->";
    }
    cout << endl;

    return totalCost;
}
void check_menu() {
    int n=mymap.size(), start, end, m;

    
    vector<each_site> sdata = csv_read2();

    vector<vector<each_site>> graph(n, vector<each_site>(n));
    for (int i = 0; i < n; ++i) {
        graph[i][i].name = sdata[i].name;
        graph[i][i].toilet = sdata[i].toilet;
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j].distance = mymap[i][j];
        }
    }

    int mustVisitCount;
    cout << "请输入起点和终点:" << endl;
    cin >> start >> end;

    cout << "请输入必须经过的点数:" << endl;
    cin >> mustVisitCount;

    vector<int> mustVisit(mustVisitCount);
    cout << "请输入必须经过的点:" << endl;
    for (int i = 0; i < mustVisitCount; ++i) {
        cin >> mustVisit[i];
    }
    int result = calculateShortestPath(n, graph, start, end, mustVisit);
    if (result != -1) {
        cout << "最短用时: " << result << endl;
    }

    system("pause");
}