/// Source : https://leetcode.com/problems/analyse-user-website-visit-pattern/ 1152
/*
 * Given a log website where each request entry conatins time, customerid, page visited. Find the top 3 page sequence visitied.
 *
 * If we have two customers and we log customer a visting page a ->b ->c -> d -> e and customer b visting e ,b,c,d,a
 * then top 3 page sequence is bcd.
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>

using namespace std;


/// State Memory
/// for every 3-sequence, record its user
///
/// Time Complexity: O(n^3)
/// Space Complexity: O(n^3)
/*
 *
 *
 *
 * We are given some website visits: the user with name username[i] visited the website website[i] at time timestamp[i].
 *
 * A 3-sequence is a list of websites of length 3 sorted in ascending order by the time of their visits.  (The websites in a 3-sequence 
 * are not necessarily distinct.)
 *
 * Find the 3-sequence visited by the largest number of users. If there is more than one solution, return the i
 * lexicographically smallest such 3-sequence.
 *
 *  
ername = ["joe","joe","joe","james","james","james","james","mary","mary","mary"], timestamp = [1,2,3,4,5,6,7,8,9,10], website = ["home","about","career","home","cart","maps","home","home","about","career"]
Output: ["home","about","career"]
Explanation: 
The tuples in this example are:
["joe", 1, "home"]
["joe", 2, "about"]
["joe", 3, "career"]
["james", 4, "home"]
["james", 5, "cart"]
["james", 6, "maps"]
["james", 7, "home"]
["mary", 8, "home"]
["mary", 9, "about"]
["mary", 10, "career"]
The 3-sequence ("home", "about", "career") was visited at least once by 2 users.
The 3-sequence ("home", "cart", "maps") was visited at least once by 1 user.
The 3-sequence ("home", "cart", "home") was visited at least once by 1 user.
The 3-sequence ("home", "maps", "home") was visited at least once by 1 user.
The 3-sequence ("cart", "maps", "home") was visited at least once by 1 user.*
 *

build a list of url/timestamps per user
sort each list by timestamp
iterate over each list
for each 3 URL sequence, create or increment a counter
find the highest count in the URL sequence count list

foreach(entry in parsedLog)
{
    users[entry.user].urls.add(entry.time, entry.url)
}

foreach(user in users)
{
    user.urls.sort()
    for(i = 0; i < user.urls.length - 2; i++)
    {
        key = createKey(user.urls[i], user.urls[i+1], user.urls[i+2]
        sequenceCounts.incrementOrCreate(key);
    }
}

sequenceCounts.sortDesc()
largestCountKey = sequenceCounts[0]
topUrlSequence = parseKey(largestCountkey)


 */
class Solution {

public:
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {

        set<string> website_set(website.begin(), website.end());

        unordered_map<string, set<pair<int, string>>> history;
        for(int i = 0; i < username.size(); i ++)
            history[username[i]].insert(make_pair(timestamp[i], website[i]));

        unordered_map<string, unordered_map<string, unordered_map<string, unordered_set<string>>>> count;
        for(const pair<string, set<pair<int, string>>>& p: history){
            vector<string> v;
            for(const pair<int, string>& e: p.second)
                v.push_back(e.second);
            for(int i = 0; i < v.size(); i ++)
                for(int j = i + 1; j < v.size(); j ++)
                    for(int k = j + 1; k < v.size(); k ++)
                        count[v[i]][v[j]][v[k]].insert(p.first);
        }

        int best = -1;
        vector<string> res;
        for(const string& a: website_set)
            for(const string& b: website_set)
                for(const string& c: website_set)
                    if((int)count[a][b][c].size() > best){
                        best = count[a][b][c].size();
                        res = {a, b, c};
                    }

        return res;
    }
};


void print_vec(const vector<string>& vec){

    for(const string& e: vec) cout << e << " "; cout << endl;
}

int main() {

    vector<string> username1 = {"joe","joe","joe","james","james","james","james","mary","mary","mary"};
    vector<int> timestamp1 = {1,2,3,4,5,6,7,8,9,10};
    vector<string> website1 = {"home","about","career","home","cart","maps","home","home","about","career"};
    print_vec(Solution().mostVisitedPattern(username1, timestamp1, website1));
    // home about career

    vector<string> username2 = {"h","eiy","cq","h","cq","txldsscx","cq","txldsscx","h","cq","cq"};
    vector<int> timestamp2 = {527896567,334462937,517687281,134127993,859112386,159548699,51100299,444082139,926837079,317455832,411747930};
    vector<string> website2 = {"hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","hibympufi","yljmntrclw","hibympufi","yljmntrclw"};
    print_vec(Solution().mostVisitedPattern(username2, timestamp2, website2));
    // "hibympufi","hibympufi","yljmntrclw"

    return 0;
}
