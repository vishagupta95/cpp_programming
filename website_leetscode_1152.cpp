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

/*
 *Time Complexity: O(n^3)
 * Space Complexity: O(n^3)
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

solution

Create a class Struct. Each object of type Struct contains a username, a timestamp and a website. The objects of type Struct are comparable using timestamp. 
Create an array of type Struct to store all the elements created from the three input arrays. Then sort the array of type Struct in ascending order.

Loop over the array of type Struct and obtain all the websites visited by each user in ascending order. 
For each user, obtain the websites and generate all possible 3-sequences, and update the counts of each 3-sequence. Note that since the target is 
to find the 3-sequence visited by the largest number of users, for each user, a 3-sequence can be counted at most once. After all users 3-sequences are visited, 
obtain the 3-sequence with the maximum count and is the lexicographically smallest, and return the 3-sequence.


 */


class Struct implements Comparable<Struct> {
    String username;
    int timestamp;
    String website;

    public Struct(String username, int timestamp, String website) {
        this.username = username;
        this.timestamp = timestamp;
        this.website = website;
    }

    public int compareTo(Struct struct2) {
        if (this.timestamp != struct2.timestamp)
            return this.timestamp - struct2.timestamp;
        else
            return this.username.compareTo(struct2.username);
    }
}



class Solution {
    public List<String> mostVisitedPattern(String[] username, int[] timestamp, String[] website) {
        int length = username.length;
        Struct[] array = new Struct[length];
        for (int i = 0; i < length; i++)
            array[i] = new Struct(username[i], timestamp[i], website[i]);
        Arrays.sort(array);
        Map<String, List<String>> userVisitsMap = new HashMap<String, List<String>>();
        for (int i = 0; i < length; i++) {
            Struct struct = array[i];
            String curUser = struct.username;
            String curWebsite = struct.website;
            List<String> list = userVisitsMap.getOrDefault(curUser, new ArrayList<String>());
            list.add(curWebsite);
            userVisitsMap.put(curUser, list);
        }
        int maxCount = 0;
        Map<String, Integer> countMap = new HashMap<String, Integer>();
        Map<String, List<String>> strListMap = new HashMap<String, List<String>>();
        Set<String> set = userVisitsMap.keySet();
        for (String user : set) {
            Set<String> sequenceSet = new HashSet<String>();
            List<String> list = userVisitsMap.getOrDefault(user, new ArrayList<String>());
            int size = list.size();
            if (size >= 3) {
                for (int i = 0; i < size - 2; i++) {
                    String website1 = list.get(i);
                    for (int j = i + 1; j < size - 1; j++) {
                        String website2 = list.get(j);
                        for (int k = j + 1; k < size; k++) {
                            String website3 = list.get(k);
                            List<String> sequence = new ArrayList<String>();
                            sequence.add(website1);
                            sequence.add(website2);
                            sequence.add(website3);
                            String sequenceStr = sequence.toString();
                            if (sequenceSet.add(sequenceStr)) {
                                int count = countMap.getOrDefault(sequenceStr, 0) + 1;
                                maxCount = Math.max(maxCount, count);
                                countMap.put(sequenceStr, count);
                                strListMap.put(sequenceStr, sequence);
                            }
                        }
                    }
                }
            }
        }
        List<List<String>> candidates = new ArrayList<List<String>>();
        Set<String> sequenceSet = countMap.keySet();
        for (String sequenceStr : sequenceSet) {
            int count = countMap.getOrDefault(sequenceStr, 0);
            if (count == maxCount)
                candidates.add(strListMap.get(sequenceStr));
        }
        Collections.sort(candidates, new Comparator<List<String>>() {
            public int compare(List<String> sequence1, List<String> sequence2) {
                return sequence1.toString().compareTo(sequence2.toString());
            }
        });
        return candidates.get(0);
    }
}

