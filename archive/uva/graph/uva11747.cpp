#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

const double EP=1e-6;

class UnionFind {
    private:
        vi p, rank, setSize;
        int numSets;
    public:

        UnionFind(int N) { setSize.assign(N, 1); numSets = N; rank.assign(N, 0); p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }

        //findSet with path compression
        int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }

        bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

        void unionSet(int i, int j) {
            if (isSameSet(i, j)) return;
            numSets--; int x = findSet(i), y = findSet(j);
            // rank is used to keep the tree short
            if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
            else                   { p[x] = y; setSize[y] += setSize[x]; if (rank[x] == rank[y]) rank[y]++; }
        }

        int numDisjointSets() { return numSets; }

        int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int n,m;
vi res;
priority_queue<pair<int, pii> > pq;

int main(){

    cin>>n>>m;
    while (n!=0){

        pq = priority_queue<pair<int, pii> >();
        res.clear();
        for (int i=0; i<m; i++){
            int v1,v2,w;
            cin>>v1>>v2>>w;
            pq.push(pair<int, pii>(-w, pii(v1,v2)));
        }

        UnionFind uf = UnionFind(n);

        while (!pq.empty()){
            pair<int, pii> cur = pq.top();
            pii p = cur.second;
            pq.pop();

            if (uf.isSameSet(p.first, p.second)){
                res.push_back(-cur.first);
            }
            else {
                uf.unionSet(p.first, p.second);
            }
        }

        if (res.size() == 0) cout<<"forest"<<endl;
        else {
            for (int i=0; i<res.size()-1; i++){
                cout<<res[i]<<" ";
            }
            cout<<res[res.size()-1]<<endl;
        }

        cin>>n>>m;
    }
}




















