#include <bits/stdc++.h>
using namespace std;

int N, W, X, Y;
double Probability_X, Probability_Y;

double calculateProfit(int position, int currentWeight) {
    if (currentWeight >= W) return 1.0;
    if (position == 0) return 0.0;

    double profit_with_X = Probability_X * calculateProfit(position - 1, currentWeight + X) + (1 - Probability_X) * calculateProfit(position - 1, currentWeight);
    double profit_with_Y = Probability_Y * calculateProfit(position - 1, currentWeight + Y) + (1 - Probability_Y) * calculateProfit(position - 1, currentWeight);

    return max(profit_with_X, profit_with_Y);
}

int main() {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> X >> Y >> N >> W >> Probability_X >> Probability_Y;

        Probability_X /= 100.0;
        Probability_Y /= 100.0;

        double result = calculateProfit(N, 0) * 100.0;
        cout << setprecision(6) << fixed << result << endl;
    }

    return 0;
}
