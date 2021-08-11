#include <bits/stdc++.h>
#define task "SERIEA"

using namespace std;

ifstream fi(task ".inp");
ofstream fo(task ".out");

map<string, int> m;
int c = 0;

class team {
public:
	string name;
	int match, score, win, lost, draw, goal, goalLost;
public:
	team() : match(0), score(0), win(0), lost(0), draw(0), goal(0), goalLost(0) {
		fi >> name;
		m[name] = c++;
	};
	friend ofstream& operator << (ofstream & os, team & t) {
		os << t.name << " " << t.match << " " << t.score << " ";
		os << t.win << " " << t.lost << " " << t.draw << " ";
		os << t.goal << " " << t.goalLost << " " << t.goal - t.goalLost << endl;
		return os;
	}
	void update(int goal, int goalLost) {
		this->goal += goal;
		this->goalLost += goalLost;
		if (goal > goalLost) {
			win++;
			score += 3;
		}
		else if (goal < goalLost) {
			lost++;
		}
		else {
			score++;
			draw++;
		}
		this -> match++;
	}
	int wl() {
		return goal - goalLost;
	}
	friend bool operator < (team & l, team& t) {
		if (l.score != t.score) return l.score > t.score;
		if (l.wl() != t.wl()) return l.wl() > t.wl();
		if (l.goal != t.goal) return l.goal > t.goal;
		return l.name < t.name;
	}

};

int main() {
	int n;
	fi >> n;
	vector<team>a(n);
	string t1, t2;
	int k, q;
	while(fi >> t1 >> t2 >> k >> q){
		a[m[t1]].update(k, q);
 		a[m[t2]].update(q, k);
	}
	sort(a.begin(), a.end());
	for (auto i : a) {
		fo << i;
	}
	return 0;
}


