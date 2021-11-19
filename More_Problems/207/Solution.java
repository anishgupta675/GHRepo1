// Course Schedule

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, List<Integer>> graph = new HashMap<>();
        for (int i = 0; i < numCourses; i++) {
            List<Integer> adjacencyList = new ArrayList<>();
            graph.put(i, adjacencyList);
        }
        for (int[] prerequisite : prerequisites) {
            graph.get(prerequisite[1]).add(prerequisite[0]);
        }
        boolean[] hasBeenProcessed = new boolean[numCourses];
        boolean[] inPath = new boolean[numCourses];
        for (int i = 0; i < numCourses; i++) {
            if (isCyclic(i, graph, inPath, hasBeenProcessed)) {
                return false;
            }
        }
        return true;
    }
    
    public boolean isCyclic(int node, Map<Integer, List<Integer>> graph, boolean[] inPath, boolean[] hasBeenProcessed) {
        if (hasBeenProcessed[node]) {
            return false;
        }
        if (inPath[node]) {
            return true;
        } else {
            inPath[node] = true;
            for (int neighbor : graph.get(node)) {
                if (isCyclic(neighbor, graph, inPath, hasBeenProcessed)) {
                    return true;
                }
            }
            hasBeenProcessed[node] = true;
            inPath[node] = false;
            return false;
        }
    }

    public static void main(String[] args) throws IOException {}
}
