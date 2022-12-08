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
    int **s = new int*[n];
    for (int i = 0; i < n; i++) {
        s[i] = new int[n];
        s[i][start] = 1;
        s[i][i] = 2;
    }
    
    for (i = 0; i < n; i++) {
        d[i] = inf;
    }
    d[start] = 0;
    
    /*for (int i = 0; i < e; i++) {
    cout « edge[i].v + 1 « "->" « edge[i].u + 1 « " = " « edge[i].w « endl;
    }*/
    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < e; j++) {
            if (d[edge[j].v] + edge[j].w < d[edge[j].u]) {
                d[edge[j].u] = d[edge[j].v] + edge[j].w;
                s[edge[j].u][edge[j].v] = s[edge[j].u][edge[j].u];
                s[edge[j].u][edge[j].u]++;
            }
        }
    }
    
    if (d[end] == inf) {
        cout << endl << start + 1 << "->" << i + 1 << " = " << "Not";
    } else {
        int c = 1;
        for (int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if (j == c) cout << s[end][j] << "->";
                c++;
            }
        }
    }
}
//главная функция
int main() {
    setlocale(LC_ALL, "Rus");
    int n, w, start, end;
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
                    w = rand() % 10 + 1; cout << w << endl;
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
    cout << "Конечная вершина > ";
    cin >> end;
    bellman_ford(edge, n, start - 1, end - 1);
}
