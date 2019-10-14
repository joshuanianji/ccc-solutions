#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int x;
    int yt;
    int yb;
    int t;
    bool start;
} event;

typedef struct {
    int y;
    int t;
    bool start;
} subevent;

bool comp_ev(event &a, event &b) {
    return a.x < b.x;
}
bool comp_sev(subevent &a, subevent &b) {
    return a.y < b.y;
}

int main() {
    int n, thresh;
    cin >> n;
    cin >> thresh;

    vector<event> events;
    for (int i = 0; i < n; i++) {
        int xl, yt, xr, yb, t;
        cin >> xl >> yt >> xr >> yb >> t;
        event b = { .x = xl, .yt = yt, .yb = yb, .t = t, true};
        event e = { .x = xr, .yt = yt, .yb = yb, .t = t, false};
        events.push_back(b);
        events.push_back(e);
    }

    sort(events.begin(), events.end(), comp_ev);

    int prevx = events[0].x;
    long total = 0;
    vector<subevent> subevs;

    for (event &e : events) {
        if (e.x > prevx) {
            int diff = e.x - prevx;
            if (subevs.size() == 0) {
                continue;
            }
            int prevy = subevs[0].y;
            int curr_t = 0;
            long over_threshold = 0;
            for (subevent &se : subevs) {
                if (se.y > prevy) {
                    int ydiff = se.y - prevy;
                    if (curr_t >= thresh) {
                        over_threshold += ydiff;
                    }
                }
                curr_t += se.t * (se.start ? 1 : -1);
                prevy = se.y;
            }

            total += over_threshold * diff;
        }

        if (e.start) {
            subevent sb = { .y = e.yt, .t=e.t, true };
            subevent se = { .y = e.yb, .t=e.t, false };
            subevs.push_back(sb);
            subevs.push_back(se);
        } else {
            int dela;
            for (int j = 0; j < subevs.size(); j++) {
                if (subevs[j].y == e.yt) dela = j;
                if (subevs[j].y == e.yb) {
                    subevs.erase(subevs.begin() + j);
                    subevs.erase(subevs.begin() + dela);
                    break;
                }
            }
        }

        prevx = e.x;
        sort(subevs.begin(), subevs.end(), comp_sev);
    }

    cout << total << endl;
}
