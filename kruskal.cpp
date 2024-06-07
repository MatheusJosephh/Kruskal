#include <bits/stdc++.h>
using namespace std;

struct Aresta {
    int u, v;
    double peso;
};

bool compararArestas(const Aresta& a, const Aresta& b) {
    return a.peso < b.peso;
}

int encontrar(int v, vector<int>& g) {
    if (g[v] == v)
        return v;
    return g[v] = encontrar(g[v], g);
}

void unirConjuntos(int u, int v, vector<int>& g) {
    u = encontrar(u, g);
    v = encontrar(v, g);
    if (u != v)
        g[v] = u;
}

void kruskal(vector<Aresta>& arestas, int n) {
    vector<int> g(n);
    for (int i = 0; i < n; ++i)
        g[i] = i;

    sort(arestas.begin(), arestas.end(), compararArestas);

    vector<Aresta> agm;
    for (const Aresta& a : arestas) {
        if (encontrar(a.u, g) != encontrar(a.v, g)) {
            agm.push_back(a);
            unirConjuntos(a.u, a.v, g);
        }
    }

    cout << "Árvore Geradora Mínima:" << endl;
    for (const Aresta& a : agm) {
        cout << a.u << " - " << a.v << " (peso: " << a.peso << ")" << endl;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Aresta> arestas(m);
    for (int i = 0; i < m; ++i) {
        cin >> arestas[i].u >> arestas[i].v >> arestas[i].peso;
    }

    kruskal(arestas, n);
    return 0;
}