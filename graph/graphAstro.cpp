#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
bool used[100000];
queue<int> q;
vector<int> g[100000];
int n;
vector<int> bfs(int t) {
    vector<int> c;
    q.push(t);
    used[t] = true;
    while (!q.empty()) {
        int v = q.front();
        c.push_back(v);
        for (size_t i = 0; i < g[v].size(); i++) {
            int u = g[v][i];
            if (used[u] == false) {
                used[u] = true;
                q.push(u);
            }
        }
        q.pop();
    }
    return c;
}
// Complete the journeyToMoon function below.
int journeyToMoon(int n, vector<vector<int>> astronaut) {
    vector< vector<int> > lol;
    for(size_t i = 0 ; i < astronaut.size() ;i++){
        g[astronaut[i][0]].push_back(astronaut[i][1]);
        g[astronaut[i][1]].push_back(astronaut[i][0]);
    }
    for(int i = 0 ; i < n ; i++){
        if(!used[i]){
            lol.push_back(bfs(i));
        }
    }
    int cnt = 0;
    for(size_t i = 0 ; i < lol.size() ;i++){
        int x =lol[i].size();
        cnt += ( x* (n-x));
    }
    return cnt/2;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string np_temp;
    getline(cin, np_temp);

    vector<string> np = split_string(np_temp);

    int n = stoi(np[0]);

    int p = stoi(np[1]);

    vector<vector<int>> astronaut(p);
    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> astronaut[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
