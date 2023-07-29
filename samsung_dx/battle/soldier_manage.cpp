#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <map>
#include <set>
#include <vector>
using namespace std;

#define CMD_INIT 1
#define CMD_HIRE 2
#define CMD_FIRE 3
#define CMD_UPDATE_SOLDIER 4
#define CMD_UPDATE_TEAM 5
#define CMD_BEST_SOLDIER 6

struct Soldier {
	int mId;
	int mTeam;
	int mScore; 

	bool operator < (Soldier currSoldier) {
		return mId < currSoldier.mId;	
	}
};

// mid와 mTeam을 매핑해준다.
map<int, int> midToMteam;

// storage[i][j]
// i: mTeam
// j: mScore
set<int> storage[6][6];


void init() {
		for(int i = 1; i <= 5; i++) {
 			for(int j = 1; j <= 5; j++) {
         	storage[i][j].clear();   
        }
    }
    midToMteam.clear();		
}

void hire(int mID, int mTeam, int mScore)
{
	Soldier hiredSoldier;
	hiredSoldier.mId = mID;
	hiredSoldier.mTeam = mTeam;
	hiredSoldier.mScore = mScore;
	storage[mID][mScore].insert(mID);
	midToMteam[mID] = mTeam;
}

void fire(int mID)
{
	int currTeam = midToMteam[mID];
	for(int i = 1; i <= 5; i++) {
		auto loc = storage[currTeam][i].find(mID);
		if(loc == storage[currTeam][i].end()) continue;
		storage[currTeam][i].erase(loc);
	}
	midToMteam.erase(mID);
}

void updateSoldier(int mID, int mScore)
{
	int currTeam = midToMteam[mID];
	for(int i = 1; i <= 5; i++) {
		auto loc = storage[currTeam][i].find(mID);
		if(loc == storage[currTeam][i].end()) continue;
		storage[currTeam][i].erase(mID);
		storage[currTeam][mScore].insert(mID);
		break;
	}
}

void updateTeam(int mTeam, int mChangeScore)
{
	if(mChangeScore == 0) {
		return;
	} else if (mChangeScore > 0) {
		for(int i = 5; i >= 1; i--) {
			int currState = i + mChangeScore > 5 ? 5 : i + mChangeScore; 

			vector<int> tmp;

			int min_ = min(i, currState);
			int max_ = max(i, currState);

			for(auto i: storage[mTeam][min_]) {
				tmp.push_back(i);
			}

			for(int i = 0; i < tmp.size(); i++) {
				auto findValue = storage[mTeam][min_].find(tmp[i]);
				storage[mTeam][min_].erase(*findValue);
				storage[mTeam][max_].insert(*findValue);
			}

			if(i != min_) {
				auto tmp = storage[mTeam][currState];
				storage[mTeam][currState] = storage[mTeam][i];
				storage[mTeam][i] = tmp;
			}
		}			
	} else {
		for(int i = 1; i <= 5; i++) {
			int currState = i + mChangeScore < 1 ? 1 : i + mChangeScore;
			vector<int> tmp1;

			int min_ = min(i, currState);
			int max_ = max(i, currState);

			for(auto i: storage[mTeam][min_]) {
				tmp1.push_back(i);
			}

			for(int i = 0; i < tmp1.size(); i++) {
				auto findValue = storage[mTeam][min_].find(tmp1[i]);
				storage[mTeam][min_].erase(*findValue);
				storage[mTeam][max_].insert(*findValue);
			}

			if(i != max_) {
				auto tmp = storage[mTeam][currState];
				storage[mTeam][currState] = storage[mTeam][i];
				storage[mTeam][i] = tmp;
			}
		}	
	}
}

int bestSoldier(int mTeam)
{
		int max_ = -1;
		for(int i = 1; i <= 5; i++) {
			if(storage[mTeam][i].size() == 0) continue; 
			max_ = max(max_, *storage[mTeam][i].rbegin());
		}
    return max_;
}

static bool run()
{
    int numQuery;

    int mID, mTeam, mScore, mChangeScore;

    int userAns, ans;

    bool isCorrect = false;

    scanf("%d", &numQuery);

    for (int i = 0; i < numQuery; ++i)
    {
        int cmd;
        scanf("%d", &cmd);
        switch (cmd)
        {
        case CMD_INIT:
            init();
            isCorrect = true;
            break;
        case CMD_HIRE:
            scanf("%d %d %d", &mID, &mTeam, &mScore);
            hire(mID, mTeam, mScore);
            break;
        case CMD_FIRE:
            scanf("%d", &mID);
            fire(mID);
            break;
        case CMD_UPDATE_SOLDIER:
            scanf("%d %d", &mID, &mScore);
            updateSoldier(mID, mScore);
            break;
        case CMD_UPDATE_TEAM:
            scanf("%d %d", &mTeam, &mChangeScore);
            updateTeam(mTeam, mChangeScore);
            break;
        case CMD_BEST_SOLDIER:
            scanf("%d", &mTeam);
            userAns = bestSoldier(mTeam);
            scanf("%d", &ans);
            if (userAns != ans)
            {
                isCorrect = false;
            }
            break;
        default:
            isCorrect = false;
            break;
        }
    }

    return isCorrect;
}

int main()
{
    setbuf(stdout, NULL);
    freopen("sample_25_input.txt", "r", stdin);

    int T, MARK;
    scanf("%d %d", &T, &MARK);

    for (int tc = 1; tc <= T; tc++)
    {
        int score = run() ? MARK : 0;
        printf("#%d %d\n", tc, score);
    }

    return 0;
}
