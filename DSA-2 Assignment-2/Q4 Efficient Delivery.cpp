#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

struct Order {
    int from, to, weight, profit;
};

struct Edge {
    int to, weight;
};

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> graph(N + 1);
    for (int i = 0; i < M; ++i) {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        graph[X].push_back({Y, Z});
        graph[Y].push_back({X, Z});
    }

    int K;
    cin >> K;
    vector<Order> orders(K);
    for (int i = 0; i < K; ++i) {
        cin >> orders[i].from >> orders[i].to >> orders[i].weight >> orders[i].profit;
    }

    int S, D, W;
    cin >> S >> D >> W;

    vector<vector<vector<pair<int, int>>>> dp(K + 1, vector<vector<pair<int, int>>>(N + 1, vector<pair<int, int>>(W + 1, {-INF, -1})));

    dp[0][S][0] = {0, -1};

    for (int k = 1; k <= K; ++k) {
        for (int v = 1; v <= N; ++v) {
            for (int w = 0; w <= W; ++w) {
                for (const Edge& edge : graph[v]) {
                    int u = edge.to;
                    int dist = edge.weight;

                    if (w >= orders[k - 1].weight && dp[k - 1][u][w - orders[k - 1].weight].first + orders[k - 1].profit > dp[k][v][w].first) {
                        dp[k][v][w] = {dp[k - 1][u][w - orders[k - 1].weight].first + orders[k - 1].profit, u};
                    }
                }
            }
        }
    }

    int max_profit = 0;
    int last_order = -1;
    int current_junction = -1;
    int current_weight = -1;

    for (int w = 0; w <= W; ++w) {
        for (int k = K; k >= 0; --k) {
            for (int v = 1; v <= N; ++v) {
                if (dp[k][v][w].first > max_profit) {
                    max_profit = dp[k][v][w].first;
                    last_order = k;
                    current_junction = v;
                    current_weight = w;
                }
            }
        }
    }

    if (max_profit == 0) {
        cout << "0\n0\n";
        return 0;
    }

    vector<pair<int, int>> operations;

    while (last_order > 0) {
        int prev_junction = dp[last_order][current_junction][current_weight].second;
        if (prev_junction == -1) {
            current_weight = W;
        } else {
            operations.push_back({1, last_order});
            current_weight -= orders[last_order - 1].weight;
        }
        operations.push_back({0, prev_junction});
        current_junction = prev_junction;
        last_order--;
    }

    reverse(operations.begin(), operations.end());

    cout << max_profit << endl;
    cout << operations.size() << endl;

    for (const auto& op : operations) {
        cout << op.first << " " << op.second << endl;
    }

    return 0;
}

