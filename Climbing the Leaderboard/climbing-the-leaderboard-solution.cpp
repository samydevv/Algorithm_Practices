#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'climbingLeaderboard' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY ranked
 *  2. INTEGER_ARRAY player
 */
int binarySearch(vector<int> ranked,int key){
    int MSR=ranked.size()-1,MSL=0;
    while (MSL<=MSR){
        int MID= MSL+((MSR-MSL)/2);
        if (ranked[MID]==key)
            return MID;
        else if (ranked[MID]<key && key < ranked[MID-1])
            return MID;
        else if (ranked[MID]>key && key >= ranked[MID+1])
            return MID+1;
        else if (ranked[MID]>key)
            MSL=  MID+1;
        else if (ranked[MID]<key)
            MSR = MID-1;
    }
    return -1;
}
vector<int> climbingLeaderboard(vector<int> ranked, vector<int> player) {
    int r = ranked.size(),p = player.size();
    vector<int> index_rank(r),answer(p);
    index_rank[0]=1;
    for (int i =1; i<r; i++){
        if(ranked[i]==ranked[i-1]){
            index_rank[i]=index_rank[i-1];
        }else if(ranked[i]!=ranked[i-1]){
            index_rank[i]=index_rank[i-1]+1;
        }
    }
    for (int i =0; i<p ; i++){
        if (player[i]>ranked[0])
            answer[i]=1;
        else if (player[i]<ranked[r-1])
            answer[i]=index_rank[r-1]+1;
        else
            answer[i]=index_rank[binarySearch(ranked,player[i])];
    }
    return answer;
}

int main()
{
    string ranked_count_temp;
    getline(cin, ranked_count_temp);

    int ranked_count = stoi(ltrim(rtrim(ranked_count_temp)));

    string ranked_temp_temp;
    getline(cin, ranked_temp_temp);

    vector<string> ranked_temp = split(rtrim(ranked_temp_temp));

    vector<int> ranked(ranked_count);

    for (int i = 0; i < ranked_count; i++) {
        int ranked_item = stoi(ranked_temp[i]);

        ranked[i] = ranked_item;
    }

    string player_count_temp;
    getline(cin, player_count_temp);

    int player_count = stoi(ltrim(rtrim(player_count_temp)));

    string player_temp_temp;
    getline(cin, player_temp_temp);

    vector<string> player_temp = split(rtrim(player_temp_temp));

    vector<int> player(player_count);

    for (int i = 0; i < player_count; i++) {
        int player_item = stoi(player_temp[i]);

        player[i] = player_item;
    }

    vector<int> result = climbingLeaderboard(ranked, player);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
