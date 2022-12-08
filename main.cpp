#include <iostream>
#include <math.h>
#define inf 100000
using namespace std;
struct Edges {
    int u, v, w;
};
int e;

//алгоритм Беллмана-Форда
void bellman_ford(Edges edge[], int n, int start, int end) {
    int i, j, d[n];
    int **s = new int*[2];
    for (int i = 0; i < 2; i++) {
        s[i] = new int[n];
    }
    
    for (int j = 0; j < n; j++) {
        s[0][j] = j;
        s[1][j] = start;
    }
    
    for (i = 0; i < n; i++) {
        d[i] = inf;
    }
    d[start] = 0;
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < e; j++) {
            if (d[edge[j].v] + edge[j].w < d[edge[j].u]) {
                d[edge[j].u] = d[edge[j].v] + edge[j].w;
                s[1][edge[j].u] = edge[j].v;
            }
        }
    }
    
    // if (d[i] == inf) {
    //     cout << endl << start + 1 << "->" << end + 1 << " = " << "Not";
    // } else {
    //     int ptr = s[1][end], sch[n] = {-1}, j = 0;
    //     while (ptr != start) {
    //         sch[j] = ptr;
    //         ptr = s[1][ptr];
    //         j++;
    //     }
    //     cout << endl << start + 1 << "->";
    //     for (int k = j - 1; k >= 0; k--) {
    //         cout << sch[k] + 1 << "->";
    //     }
    //     cout << end + 1 << " = " << d[end];
    // }
    
    for (int i = 0; i < n; i++) {
        if (d[i] == inf) {
            cout << endl << start + 1 << "->" << i + 1 << " = " << "Not";
        } else {
            int ptr = s[1][i], sch[n] = {-1}, j = 0;
            while (ptr != start) {
                sch[j] = ptr;
                ptr = s[1][ptr];
                j++;
            }
            cout << endl << start + 1 << "->";
            for (int k = j - 1; k >= 0; k--) {
                cout << sch[k] + 1 << "->";
            }
            cout << i + 1 << " = " << d[i];
        }
    }
}
//главная функция
int main() {
    setlocale(LC_ALL, "Rus");
    int n, w, start, end = 0;
    e = 0;
    cout << "Количество вершин > ";
    cin >> n;
    Edges edge[(int)pow(n, 2)];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            edge[e].v = i;
            edge[e].u = j;
        
            if (i != j) {
                int check = 1;
                for(int k = 0; k < e; k++) {
                    if (edge[k].v == j && edge[k].u == i) {
                        edge[e].w = edge[k].w;
                        check = 0;
                    }
                }
                if(check) {
                    cout << "Вес " << i + 1 << "->" << j + 1 << " > ";
                    w = rand() % 10 - 11; cout << w << endl;
                    //cin >> w;
                    if (w != 0) {
                        edge[e].w = w;
                    }
                }
            } else {
                edge[e].w = 0;
            }
        
            e++;
        }
    }
    cout << "Стартовая вершина > ";
    cin >> start;
    // cout << "Конечная вершина > ";
    // cin >> end;
    bellman_ford(edge, n, start - 1, end);
}
