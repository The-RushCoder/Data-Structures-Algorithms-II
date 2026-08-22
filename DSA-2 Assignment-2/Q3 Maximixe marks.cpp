#include<bits/stdc++.h>
using namespace std;

struct Item {
    int mark;
    int time;
};

bool compareItems(const Item& a, const Item& b) {
    // Sort in non-increasing order of mark-to-time ratio
    return (double)a.mark / a.time > (double)b.mark / b.time;
}

int knapsack01(int total_Time, const vector<Item>& items) {
    int n = items.size();
    vector<vector<int>> dp(n + 1, vector<int>(total_Time + 1, 0));


    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= total_Time; ++w) {
            if (items[i - 1].time <= w) {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].mark + dp[i - 1][w - items[i - 1].time]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][total_Time];
}
int main() {
    int num_of_ques, total_Time;
    cout << "Enter the number of Questions: ";
    cin >> num_of_ques;

    cout << "Enter the Total Time: ";
    cin >> total_Time;

    vector<Item> items(num_of_ques);

    cout << "Enter the mark and solving time of each questions:" << endl;
    for (int i = 0; i < num_of_ques; ++i) {
        cin >> items[i].mark;
    }
    for (int i = 0; i < num_of_ques; ++i) {
        cin >> items[i].time;
    }


    sort(items.begin(), items.end(), compareItems);
    
    items[0].mark = items[0].mark *2;

    int maxValue = knapsack01(total_Time, items);

    cout << "Maximum number of marks Jam can acheive: " << maxValue << endl;

    return 0;

}

/*
Trail-1
3
10
1 2 3
4 3 4
*/