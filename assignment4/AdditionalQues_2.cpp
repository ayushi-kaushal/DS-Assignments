#include <iostream>
#include <queue>

using namespace std;

void sortQueue(queue<int> &q) {
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int min_val = q.front();

        for (int j = 0; j < n; j++) {
            int x = q.front();
            q.pop();

            if (j < n - i && x < min_val) {
                min_val = x;
            }
            q.push(x);
        }

        int count = 0;
        bool minPlaced = false;
        int size = q.size();
        while (count < size) {
            int x = q.front();
            q.pop();

            if (x == min_val && !minPlaced) {
                q.push(x);
                minPlaced = true;
            } else {
                q.push(x);
            }
            count++;
        }
    }
}

int main() {
    queue<int> q;
    int arr[] = {11, 5, 4, 21};
    for (int x : arr) q.push(x);

    sortQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
