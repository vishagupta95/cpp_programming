
/* https://blog.csdn.net/qq_41879343/article/details/104436388 */
/* https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/practice-problems/algorithm/find-the-cycles */

/*input

5 4
1 2
3 4
5 4
3 5

ouput
1

Connected blocks traversed by dfs or bfs mark
If all points of a connected block have degree 2, then it is a ring


*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define endl '\n'
const int MAXN = 2e5+5;
vector<int> v[MAXN];
bool vis[MAXN],flag;

void dfs(int x)
{
    if(vis[x]) return;
    vis[x]=true;
    if(v[x].size()!=2) flag=true;
    for(int y:v[x]) dfs(y);
}

int main()
{
    SIS;
    int n,m,x,y,ans=0;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        flag=false;
        dfs(i);
        if(!flag) ans++;
    }
    cout << ans << endl;
    return 0;
}
