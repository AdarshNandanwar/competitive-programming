#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// Complete the andProduct function below.
long andProduct(long a, long b) {

    bool zero = false;
    typedef unsigned int ui;
    for (int i = 31; i >= 0; i--)
    {
        if(zero || (a&((ui)1<<i)) != (b&((ui)1<<i))){
            zero = true;
            a &= ((((long long)1<<32)-1)^((ui)1<<i));
        } else {
            continue;
        }
    }
    
    return a;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int n_itr = 0; n_itr < n; n_itr++) {
        string ab_temp;
        getline(cin, ab_temp);

        vector<string> ab = split_string(ab_temp);

        long a = stol(ab[0]);

        long b = stol(ab[1]);

        long result = andProduct(a, b);

        fout << result << "\n";
        cout << result << "\n";
    }

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
