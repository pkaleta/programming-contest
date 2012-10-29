/*
ID: piotrek4
LANG: C++
PROG: namenum
*/

#include <cstdio>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

int main() {
    string s;
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");
    ifstream dict("dict.txt");
    vector<char> k[10];
    char c = 'A';
    for (int i = 2; i <= 9; ++i) {
        k[i] = vector<char>();
        for (int j = 0; j < 3; ++j) {
            k[i].push_back(c);
            ++c;
            if (c == 'Q')
                ++c;
        }
    }

    map<string, bool> d;

    while (getline(dict, s)) {
        stringstream ss;
        for (int i = 0; i < s.size()-1; ++i) {
            ss << s[i];
            d[ss.str()] = d[ss.str()] || false;
//            cout << ss.str() << endl;
        }
        d[s] = d[s] || true;
//        cout << s << endl;
    }

    fin >> s;

    vector<string> strings1;
    vector<string> strings2;
    vector<string>* a = &strings1;
    vector<string>* b = &strings2;
    vector<string>* tmp;
    a->push_back("");

    for (int i = 0; i < s.size(); ++i) {
        b = new vector<string>();
        int num = s[i]-'0';
//        cout << "********" << num << endl;

        for (int j = 0; j < a->size(); ++j) {
            for (int l = 0; l < k[num].size(); ++l) {
                stringstream ss;
                ss << (*a)[j] << k[num][l];
//                cout << ss.str();
                if (d.find(ss.str()) != d.end()) {
//                    cout << "*";
                    b->push_back(ss.str());
                }
//                cout << endl;
            }
        }
        tmp = a;
        a = b;
        b = tmp;
    }

    vector<string> strings = *a;
    vector<string> names;
    for (int i = 0; i < strings.size(); ++i) {
//        cout << strings[i] << d[strings[i]] << endl;
        if (d.find(strings[i]) != d.end() && d[strings[i]] == true) {
            names.push_back(strings[i]);
        }
    }
    if (names.size() == 0) {
        fout << "NONE" << endl;
    } else {
        sort(names.begin(), names.end());
        for (int i = 0; i < names.size(); ++i) {
            fout << names[i] << endl;
        }
    }

    return 0;
}
