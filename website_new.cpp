/// Source : https://leetcode.com/problems/analyse-user-website-visit-pattern/ 1152
/*
 * Given a log website where each request entry conatins time, customerid, page visited. Find the top 3 page sequence visitied.
 *
 * If we have two customers and we log customer a visting page a ->b ->c -> d -> e and customer b visting e ,b,c,d,a
 * then top 3 page sequence is bcd.
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


Based on the above, my solution is here

to use a new class VisitRecord to gather all the information together, sort them with timestamps
analyze each users behavior, use dfs solution to get different 3 websites sequences
to put all user visiting sequences into a map and count the maximum visiting times.
take all the records that meet maximum visiting times and sort them lexicographically.
return the first record.
or
*/

/*
 * @lc app=leetcode id=1152 lang=cpp
 *
 * [1152] Analyze User Website Visit Pattern
 */

// @lc code=start
class Solution {
public:
    // joe: {1: "home", 2: "about", 3: "career"}
    unordered_map<string, map<int, string>> m;
    unordered_map<string, int> count;
    vector<string> mostVisitedPattern(vector<string>& username, vector<int>& timestamp, vector<string>& website) {
        // Store all the activities in the map
        for(int i = 0; i < username.size(); i ++) {
            m[username[i]].insert({timestamp[i], website[i]});
        }

        // Count all the  3 sequences
        for(auto e : m) {
            auto seq = e.second;
            unordered_set<string> visited;
            for(auto it = seq.begin(); it != seq.end(); it ++)
                for(auto it1 = next(it); it1 != seq.end(); it1 ++)
                    for(auto it2 = next(it1); it2 != seq.end(); it2 ++) {
                        string key = it->second + '$' + it1->second + '#' + it2->second;
                        visited.insert(key);
                    }
            for(auto vis : visited)
                count[vis] ++;
        }

        // get the maximum sequence with the most count
        string resStr = "";
        int curMax = 0;
        for(auto cnt : count) {
            if(cnt.second >= curMax) {
                if(resStr == "") {
                    resStr = cnt.first;
                }
                else
                    resStr = cnt.second > curMax ? cnt.first : min(resStr, cnt.first);

                curMax = cnt.second;
            }
        }

        auto split1 = resStr.find('$');
        auto split2 = resStr.find('#');

        return {resStr.substr(0, split1), resStr.substr(split1+1, split2 - split1 - 1), resStr.substr(split2+1)};
    }
};
// @lc code=end

