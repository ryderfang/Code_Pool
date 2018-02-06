/**
 *  Author: recker
 */
#include <algorithm>
#include <assert.h>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <time.h>
#include <utility>
#include <vector>
using namespace std;
#pragma warning(disable:4996)

namespace {
typedef long long LL;
typedef unsigned long long uLL;

#define EPS        1e-9
#define INF        1000000007
#define MAXINT     2147483647
#define MAXUINT    0xffffffff
#define FEQ(a, b)  (a - b) < EPS

auto StrToL = [](const string& val) {
  string ret = val;
  transform(val.begin(), val.end(), ret.begin(), ::tolower);
  return ret;
};

auto StrCaseCmp = [](const string& a, const string& b) {
  string ta = StrToL(a);
  string tb = StrToL(b);
  return ta < tb;
};

#define MAXNUM     20001
} // namespace

struct Team {
  int point = 0;
  int wins  = 0;
  int goal_diff = 0;
  int goal_scored = 0;
  int games = 0;
  string team_name;
  int ties = 0;
  int losses = 0;
  int goal_against = 0;
};

int main() {
  int N;
  cin >> N;
  getchar();
  while (N--) {
    string tourna_name;
    getline(cin, tourna_name);

    int T, G;
    string name;
    vector<Team> teams;
    cin >> T;
    getchar();
    teams.clear();
    teams.resize(T);
    for (int i = 0; i < T; ++i) {
      getline(cin, teams[i].team_name);
    }
    
    string game;
    cin >> G;
    getchar();
    for (int i = 0; i < G; ++i) {
      getline(cin, game);

      size_t pos1 = game.find_first_of('#');
      Team& team1 = *find_if(teams.begin(), teams.end(),
          [=](const Team& a) {
            return a.team_name == game.substr(0, pos1);
          }
      );

      size_t pos2 = game.find_last_of('#');
      Team& team2 = *find_if(teams.begin(), teams.end(),
          [=](const Team& a) {
            return a.team_name == game.substr(pos2 + 1);
          }
      );
      
      int goal1, goal2;
      sscanf(game.substr(pos1 + 1, pos2 - pos1).c_str(), "%d@%d#", &goal1, &goal2);

      team1.games++;
      team1.goal_scored += goal1;
      team1.goal_against += goal2;
      team1.goal_diff = team1.goal_scored - team1.goal_against;

      team2.games++;      
      team2.goal_scored += goal2;
      team2.goal_against += goal1;
      team2.goal_diff = team2.goal_scored - team2.goal_against;

      if (goal1 > goal2) {
        team1.wins++;
        team1.point += 3;
        team2.losses++;
      } else if (goal1 == goal2) {
        team1.ties++;
        team1.point++;
        team2.ties++;
        team2.point++;
      } else {
        team1.losses++;
        team2.wins++;
        team2.point += 3;
      }
    }

    sort(teams.begin(), teams.end(), 
        [](const Team& a, const Team& b) {
          if (a.point != b.point) 
            return a.point > b.point;
          if (a.wins != b.wins) 
            return a.wins > b.wins;
          if (a.goal_diff != b.goal_diff) 
            return a.goal_diff > b.goal_diff;
          if (a.goal_scored != b.goal_scored) 
            return a.goal_scored > b.goal_scored;
          if (a.games != b.games) 
            return a.games < b.games;
          return StrCaseCmp(a.team_name, b.team_name);
        }
    );

    cout << tourna_name << endl;
    for (int i = 0; i < T; ++i) {
      cout << i + 1 << ") " << teams[i].team_name << " " << teams[i].point << "p, "
           << teams[i].games << "g (" << teams[i].wins << "-" << teams[i].ties << "-"
           << teams[i].losses << "), " << teams[i].goal_diff << "gd (" << teams[i].goal_scored
           << "-" << teams[i].goal_against << ")" << endl;
      //printf("%d) ", i + 1);
      //cout << teams[i].team_name;
      //printf(" %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", teams[i].point, teams[i].games, 
      //    teams[i].wins, teams[i].ties, teams[i].losses, teams[i].goal_diff, 
      //    teams[i].goal_scored, teams[i].goal_against);
    }
    if (N) cout << endl;
  }

  return 0;
}
