#include"site.h"
#include<vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <set>
#include <unordered_set>
#include<iostream>
#include <climits>
#include<conio.h>
#include<windows.h>
#include"menu.h"
#define MAX_NUM 100
#define INF 
//vector<vector<int>> mymap(MAX_NUM, vector<int>(MAX_NUM));
typedef struct each_site {
    bool toilet;
    int distance = -1;
    string name;
    bool isopen;
};
vector<each_site> csv_read_site();
vector<vector<int>> csv_read_map();
vector<vector<int>> mymap;
void init_map() {
    mymap = csv_read_map();  
}
vector<each_site> sdata;
vector<vector<each_site>> graph;
void init_basic_map() {
    vector<each_site> sdata1 = csv_read_site();
    vector<vector<each_site>> graph1(mymap.size(), vector<each_site>(mymap.size()));
    sdata = sdata1;
    graph = graph1;
    for (int i = 0; i < mymap.size(); ++i) {
        graph[i][i].name = sdata[i].name;
        graph[i][i].toilet = sdata[i].toilet;
        graph[i][i].isopen = sdata[i].isopen;
    }

    for (int i = 0; i < mymap.size(); ++i) {
        for (int j = 0; j < mymap.size(); ++j) {
            graph[i][j].distance = mymap[i][j];
           
        }
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
            if (!visited[v] && graph[u][v].distance != -1 && dist[u] + graph[u][v].distance < dist[v] && graph[v][v].isopen==1) {
                dist[v] = dist[u] + graph[u][v].distance;
                pq.push({ dist[v], v });
                previous[v] = u; 
            }
        }
    }
    return dist;
}
void prim(const vector<vector<each_site>>& graph, int start) {
    vector<int> visit(graph.size(), 0);
    visit[start] = 1;
    vector<each_site> sval(graph.size());
    vector<each_site> spre(graph.size());
    int min_lo = -1, min_prop = 0;
    for (int i = 0; i < graph.size(); i++) {
        sval[i].distance = graph[start][i].distance;
        spre[i].distance = start;
        spre[i].name= graph[start][start].name;
    }
    spre[start].name = graph[start][start].name;
    for (int i = 0; i < graph.size() - 1; i++) {
        int min_val = 999999;
        for (int j = 0; j < graph.size(); j++) {
            if (sval[j].distance != -1 && visit[j] != 1) {
                if (sval[j].distance < min_val) {
                    min_val = sval[j].distance;
                    min_lo = j;
                }
            }
        }
        visit[min_lo] = 1;
        min_prop += min_val;
        for (int k = 0; k < graph.size(); k++) {
            if ((graph[min_lo][k].distance < sval[k].distance && graph[min_lo][k].distance != -1) || (graph[min_lo][k].distance != -1 && sval[k].distance == -1)) {
                if (graph[min_lo][k].distance != 0) sval[k].distance = graph[min_lo][k].distance;
                if (k != min_lo) {
                    spre[k].distance = min_lo;
                    spre[k].name = graph[min_lo][min_lo].name;
                }
            }
        }
        cout << spre[min_lo].name << "->" << graph[min_lo][min_lo].name << endl;
    }
    cout << min_prop <<"米"<< endl;
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
            system("cls");
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
    if (graph[totalPath[0]][totalPath[0]].name != graph[start][start].name) cout << graph[start][start].name << "->";
    for (int i = 0; i < totalPath.size();i++) {
        cout << graph[totalPath[i]][totalPath[i]].name;
        if (i < totalPath.size() - 1) cout << "->";
    }
    cout << endl;

    return totalCost;
}
struct toilet_rank {
    string path;
    int distance;
};
toilet_rank calculateShortestPath_toilet(int n, vector<vector<each_site>>& graph, int start, int end, const vector<int>& mustVisit) {
    vector<int> totalPath;
    int totalCost = 0;
    vector<int> previous(n, -1);
    int prevNode = start;
    for (int i = 0; i < mustVisit.size(); ++i) {
        vector<int> dist = dijkstra(n, graph, prevNode, previous);
        if (dist[mustVisit[i]] == INT_MAX) {
            cout << "无法到达必经点！" << endl;
            return {};
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
        return {};
    }
    totalCost += dist[end];
    vector<int> path = getPath(prevNode, end, previous);
    path.erase(path.begin());
    totalPath.insert(totalPath.end(), path.begin(), path.end());
    string toilet_path;
    if (graph[totalPath[0]][totalPath[0]].name != graph[start][start].name) toilet_path =graph[start][start].name +"->";
    for (int i = 0; i < totalPath.size(); i++) {
        toilet_path += graph[totalPath[i]][totalPath[i]].name;
        if (i < totalPath.size() - 1) toilet_path += "->";
    }
    toilet_rank tmp;
    tmp.distance = totalCost;
    tmp.path = toilet_path;
    return tmp;
}
void search_routine() {
    int n=mymap.size(), start, end, m;
    system("cls");
    int mustVisitCount;
    for (int i = 0; i < graph.size(); i++) {
        cout << i << "  " << graph[i][i].name << endl;
    }

    cout << "请输入当前所在位置的编号:" << endl;
    cin >> start;
    if (start<0 || start>graph.size()-1) {
        cout << "不存在" << endl;
        system("pause");
        return;
    }
    cout << "请输入目的地的编号:" << endl;
    cin >> end;
    if (end<0 || end>graph.size()-1) {
        cout << "不存在" << endl;
        system("pause");
        return;
    }
	if (start == end) {
		cout << "已经在目的地" << endl;
		system("pause");
		return;
	}
    cout << "请输入要途径的园区个数（没有，请输入0）:" << endl;
    cin >> mustVisitCount;
    if (mustVisitCount<0 || mustVisitCount>graph.size()-1) {
        cout << "输入错误" << endl;
        system("pause");
        return;
    }
    vector<int> mustVisit(mustVisitCount);
	cout << "请依次输入要途径的园区编号:" << endl;
    for (int i = 0; i < mustVisitCount; ++i) {
        cin >> mustVisit[i];
        if (mustVisit[i]<0 || mustVisit[i]>graph.size() - 1) {
            cout << "不存在" << endl;
            system("pause");
            return;
        }
    }
    int result = calculateShortestPath(n, graph, start, end, mustVisit);
    if (result != -1) {
        cout << "最短距离约：: " << result << "m"<<endl;
    }
    system("pause");
    system("cls");
}
void search_toilet() {
    for (int i = 0; i < graph.size(); i++) {
        cout << i << "  " << graph[i][i].name << endl;
    }
    cout << "---------------------" << endl;
    cout << "请输入当前所在位置" << endl;
    int n = graph.size(), start, m;
    cin >> start;
    if (start<0 || start>graph.size() - 1) {
        cout << "不存在" << endl;
        system("pause");
        return;
    }
    if (start > graph.size() - 1 && start < 0) return;
    if (graph[start][start].toilet == 1) {
        cout << "当前园区配备卫生间" << endl;
        system("pause");
        system("cls");
        return;
    }
    int min_num = 99999;
    vector<toilet_rank> px;
    for (int i = 0; i < graph.size(); i++) {
        if (graph[i][i].toilet == 1) {
            toilet_rank result = calculateShortestPath_toilet(n, graph, start, i, {});
            px.push_back(result);
        }
    }
    for (int i = 0; i < px.size() - 1; i++) {
        for (int j = 0; j < px.size() - i - 1; j++) {
            if (px[j].distance > px[j + 1].distance) swap(px[j], px[j + 1]);
        }
    }
    int time = 0;
    for (auto i : px) {
		if (time == 3) break;
        time++;
        cout << i.path << " ||| " << i.distance << "m" << endl;
    }
    system("pause");
    system("cls");

}
void findway_menu() {
    system("cls");
   
    cout << "下面是推荐路线" << endl << endl;
    vector<int> mustVisit(6);
    mustVisit = { 11,4,12,13,16 };
   
    int choice = -1;
    while (choice != 3) {
        system("cls");
        cout << "下面是推荐路线" << endl << endl;
        //最小生成树算法
        prim(graph,27);
        /*int result = calculateShortestPath(graph.size(), graph, 27, 27, mustVisit);
        if (result != -1) {
            cout << endl << "最短距离约：: " << result << "m" << endl << endl;
        }*/
        int opt = 1;
        system_menu.find_short_way_menu(opt);
        while (1) {
            if (_kbhit()) {
                int v = _getch();
                if (v == 72) {
                    if (opt != 1) opt--;
                    system("cls");
                    cout << "下面是推荐路线" << endl << endl;
                    prim(graph, 27);
                   
                    system_menu.find_short_way_menu(opt);
                }
                else if (v == 80) {
                    if (opt != 3) opt++;
                    system("cls");
                    cout << "下面是推荐路线" << endl << endl;
                    prim(graph, 27);
                    system_menu.find_short_way_menu(opt);
                }
                else if (v == 13) {
                    choice = opt;
                    break;
                }
                else continue;
            }
        }
        switch (choice) {
        case 1: {
            search_routine();
            break;
        }
        case 2: {
            search_toilet();
            break;
        }
        case 3: {
            return;
            break;
        }
        }
    }
}