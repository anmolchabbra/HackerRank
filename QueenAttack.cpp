#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the queensAttack function below.
int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    bool **array = new bool*[n];
    for (int i = 0; i < n; i++) {
        array[i] = new bool[n];
        for (int j = 0; j < n; j++) {
            array[i][j] = false;
        }
    }
    for (int i = 0; i < k; i++) {
        int a = obstacles[i][0];
        int b = obstacles[i][1];
        array[n - a][b - 1] = true;
    }
    int xQueen = n - r_q;
    int yQueen = c_q - 1;
    int squares = 0;
    // left
    int xl = xQueen;
    int yl = yQueen;
    while (yl >= 0 && !array[xl][yl]) {
        squares++;
        yl--;
    }
    //right
    int xr = xQueen;
    int yr = yQueen;
    while (yr < n && !array[xr][yr]) {
        squares++;
        yr++;
    }

    //bottam
    int xb = xQueen;
    int yb = yQueen;
    while (xb < n && !array[xb][yb]) {
        squares++;
        xb++;
    }

    //bottam left
    int xbl = xQueen;
    int ybl = yQueen;
    while (xbl < n &&  ybl >= 0 && !array[xbl][ybl]) {
        squares++;
        xbl++;
        ybl--;
    }

    //bottom right
    int xbr = xQueen;
    int ybr = yQueen;
    while (xbr < n  && ybr < n && !array[xbr][ybr]) {
        squares++;
        xbr++;
        ybr++;
    }
    
    //top left
    int xtl = xQueen;
    int ytl = yQueen;
    while (xtl >= 0 && ytl >= 0 && !array[xtl][ytl]) {
        squares++;
        xtl--;
        ytl--;
    }

    //top right
    int xtr = xQueen;
    int ytr = yQueen;
    while (xtr >= 0 && ytr < n && !array[xtr][ytr]) {
        squares++;
        xtr--;
        ytr++;
    }

    //top
    int xt = xQueen;
    int yt = yQueen;
    while (xt >= 0 && !array[xt][yt]) {
        squares++;
        xt--;
    }
    return squares - 8;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nk_temp;
    getline(cin, nk_temp);

    vector<string> nk = split_string(nk_temp);

    int n = stoi(nk[0]);

    int k = stoi(nk[1]);

    string r_qC_q_temp;
    getline(cin, r_qC_q_temp);

    vector<string> r_qC_q = split_string(r_qC_q_temp);

    int r_q = stoi(r_qC_q[0]);

    int c_q = stoi(r_qC_q[1]);

    vector<vector<int>> obstacles(k);
    for (int i = 0; i < k; i++) {
        obstacles[i].resize(2);

        for (int j = 0; j < 2; j++) {
            cin >> obstacles[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = queensAttack(n, k, r_q, c_q, obstacles);

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
