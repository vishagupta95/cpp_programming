/*

Output: true 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0. So it is possible.

Input: 2, [[1, 0], [0, 1]] 
Output: false 
Explanation: There are a total of 2 tasks to pick. To pick task 1 you should have finished task 0, and to pick task 0 you should also have finished task 1. So it is impossible.

Input: 3, [[1, 0], [2, 1], [3, 2]] 
Output: true 
Explanation: There are a total of 3 tasks to pick. To pick tasks 1 you should have finished task 0, and to pick task 2 you should have finished task 1 and to pick task 3 you should have finished task 2. So it is possible.


We can consider this problem as a graph (related to topological sorting) problem. All tasks are nodes of the graph and if task u is a prerequisite of task v, we will add a directed edge from node u to node v. Now, this problem is equivalent to detecting a cycle in the graph represented by prerequisites. If there is a cycle in the graph, then it is not possible to finish all tasks (because in that case there is no any topological order of tasks). Both BFS and DFS can be used to solve it.

Since pair is inconvenient for the implementation of graph algorithms, we first transform it to a graph. If task u is a prerequisite of task v, we will add a directed edge from node u to node v.
public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
          int[] indegree = new int[numCourses];
          Map<Integer, List<Integer>> map = new HashMap<>();

          for(int i=0; i < prerequisites.length; i++){
                int p = prerequisites[i][1];
                int q = prerequisites[i][0];
                if(map.containsKey(p)){
                    map.get(p).add(q);
                }else{
                    List<Integer> list = new ArrayList<>();
                    list.add(q);
                    map.put(p, list);
                }

                indegree[q]++;

          }
          //each course in this queue has no dependency on other courses.
          Queue<Integer> queue = new LinkedList<>();

          for(int i=0; i<numCourses; i++){
              if(indegree[i] == 0) queue.offer(i);
          }
          int res = 0;
          while(!queue.isEmpty()){
              int c = queue.poll();
              res++;

              if(map.containsKey(c)){
                  List<Integer> dep = map.get(c);
                  for(int cc : dep){
                      indegree[cc]--;
                      if(indegree[cc] == 0) queue.offer(cc);
                  }
              }
          }

          return res == numCourses;
    }
}
