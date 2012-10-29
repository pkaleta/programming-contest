#include <cstdio>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

const long long MAX_CLIENTS = 100005;

long long k[3] = {0, 0, 0};
long long t[3] = {0, 0, 0};
long long n;

class Cmp
{
    public:
        Cmp() {}
        bool operator() (const vector<long long>& ev1, const vector<long long>& ev2) const {
            if (ev1[0] == ev2[0]) {
                return ev1[1] > ev2[1];
            }
            return (ev1[0] > ev2[0]);
        }
};

long long timeIn[MAX_CLIENTS];
long long timeOut[MAX_CLIENTS];
priority_queue<vector<long long>, vector<vector<long long> >, Cmp> eventQ;
queue<long long> winQ[3];
long long freeWin[3] = {0, 0, 0};

int main() {
    for (int i = 0; i < 3; ++i) {
        cin >> k[i];
    }
    for (int i = 0; i < 3; ++i) {
        cin >> t[i];
    }

    for (int i = 0; i < 3; ++i) {
        freeWin[i] += k[i];
    }

    cin >> n;

    long long entry;
    for (int i = 0; i < n; ++i) {
        cin >> entry;
        timeIn[i] = entry;
        vector<long long> ev;
        ev.push_back(entry);
        ev.push_back(2);
        ev.push_back(i);
//        printf("kolejkuje %d %d %d\n", ev[0], ev[1], ev[2]);
        eventQ.push(ev);
    }

    while (!eventQ.empty()) {
        vector<long long> ev = eventQ.top();
        eventQ.pop();
//        printf("**************%d %d %d\n", ev[0], ev[1], ev[2]);

        if (ev[1] == 1) { // zwolnienie okna
//            printf("zwolnienie kolejki %d przez osobe %d\n", ev[2], ev[3]);
            long long time = ev[0];
            int winType = ev[2];
            int cliNr = ev[3];

            if (winType == 2) {
                timeOut[cliNr] = time;
//                printf("doliczam czas\n");
            } else {
                int nWinType = winType + 1;
                if (freeWin[nWinType] > 0) {
//                    printf("osoba %d staje do kolejki %d, wyjdzie o %d\n", cliNr, nWinType, time+t[nWinType]);
                    vector<long long> ev;
                    ev.push_back(time + t[nWinType]);
                    ev.push_back(1);
                    ev.push_back(nWinType);
                    ev.push_back(cliNr);
                    eventQ.push(ev);
                    freeWin[nWinType]--;
                } else {
//                    printf("osoba %d czeka do kolejki %d\n", cliNr, nWinType);
                    winQ[nWinType].push(cliNr);
                }
            }

            if (winQ[winType].empty()) {
//                printf("kolejka %d zostaje wolna\n", winType);
                freeWin[winType]++;
            } else {
                cliNr = winQ[winType].front();
//                printf("whodzi osoba %d\n", cliNr);
                winQ[winType].pop();
                vector<long long> ev;
                ev.push_back(time+t[winType]);
                ev.push_back(1);
                ev.push_back(winType);
                ev.push_back(cliNr);
                eventQ.push(ev);
            }
        } else { // przyjscie klienta
            long long time = ev[0];
            long long cliNr = ev[2];
            if (freeWin[0] > 0) {
//                printf("osoba %d podchodzi do okienka %d\n", cliNr, 0);
                freeWin[0]--;
                vector<long long> ev;
                ev.push_back(time + t[0]);
                ev.push_back(1);
                ev.push_back(0);
                ev.push_back(cliNr);
                eventQ.push(ev);
            } else {
//                printf("osoba %d czeka przed okienkiem %d\n", cliNr, 0);
                winQ[0].push(cliNr);
            }
        }
    }

    long long res = timeOut[0] - timeIn[0];
    long long tmp;
    for (int i = 1; i < n; ++i) {
        tmp = timeOut[i] - timeIn[i];
        if (tmp > res)
            res = tmp;
    }
    cout << res << endl;

    return 0;
}
