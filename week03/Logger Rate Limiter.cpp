#include <bits/stdc++.h>
using namespace std;

class Logger {
   public:
    unordered_map<string, int> limiter;
    Logger() {
        limiter.clear();
    }

    bool shouldPrintMessage(int timestamp, string message) {
        if (limiter.count(message) and timestamp < limiter[message])
            return false;

        limiter[message] += timestamp + 10;
        return true;
    }
};

int main() {
    Logger logger;
    vector<pair<int, string>> msg = {
        {1, "foo"},
        {2, "bar"},
        {3, "foo"},
        {8, "bar"},
        {10, "foo"},
        {11, "foo"}};
    for (int i = 0; i < msg.size(); i++)
        cout << logger.shouldPrintMessage(msg[i].first, msg[i].second) << endl;

    return 0;
}