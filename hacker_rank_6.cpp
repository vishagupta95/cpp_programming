/*
A friend of Alex has gifted a movie collection, and Alex is excited to watch them all as quickly as possible. 
The duration of the movies is given in array durations[n], where n is the number of movies, and each movie duration 
lies between 1.01 and 3.00 units of time (up to two decimal places). Every day, Alex wants to spend no more than 3.00 units of time watching
 the movies but also wants to complete the movies in the least number of days possible. Alex does not leave a movie in between. 
That is, if Alex has picked up a movie, Alex watches the complete movie on the same day. Find the minimum number of days needed to watch all the movies.*/

#include<bits/stdc++.h>

using namespace std;

struct Movie {

  int timeBegin, duration, timeEnd;

  bool operator<(const Movie& another) const {

     return timeEnd < another.timeEnd;

  }

};

struct Festival {

  int count;

  vector<Movie> movies;

};

Festival* initialize(int timeBegin[], int duration[], int count) {

  Festival* filmFestival = new Festival;

  filmFestival->count = count;

  for (int i = 0; i < count; i++) {

     Movie temp;

     temp.timeBegin = timeBegin[i];

     temp.duration = duration[i];

     temp.timeEnd = timeBegin[i] + duration[i];

     filmFestival->movies.push_back(temp);

  }

  return filmFestival;

}

int solve(Festival* fest) {

  int res = 0;

  sort(fest->movies.begin(), fest->movies.end());

  int timeEnd = -1;

  for (int i = 0; i < fest->count; i++) {

     if (fest->movies[i].timeBegin >= timeEnd) {

        res++;

           timeEnd = fest->movies[i].timeEnd;

     }

  }

  return res;

}

int main(int argc, char *argv[]) {

int timeBegin[] = {1, 3, 0, 5, 5, 8, 8};

int duration[] = {3, 2, 2, 4, 3, 2, 3};

Festival * fest;

fest = initialize(timeBegin,duration, 7);

cout << solve(fest) << endl;

return 0;

}
