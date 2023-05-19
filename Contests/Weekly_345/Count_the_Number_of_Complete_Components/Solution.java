import java.util.*;

class Solution {
    private void dfs(int i, ArrayList<Integer>[] gr, int[] vis, ArrayList<Integer> comp) {
        if(vis[i] != 0) return;
        vis[i] = 1;
        comp.add(i);
        for(int j : gr[i]) if(vis[j] == 0) dfs(j, gr, vis, comp);
    }
    @SuppressWarnings("unchecked")
    public int countCompleteComponents(int n, int[][] edges) {
        ArrayList<Integer>[] gr = new ArrayList[n];
        for(int i = 0; i < n; i++) gr[i] = new ArrayList<Integer>();
        for(int[] i : edges) {
            gr[i[0]].add(i[1]);
            gr[i[1]].add(i[0]);
        }
        int[] vis = new int[n];
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 1) continue;
            ArrayList<Integer> comp = new ArrayList<Integer>();
            dfs(i, gr, vis, comp);
            int ed = 0;
            for(int v : comp) ed+= gr[v].size();
            int cs = comp.size();
            if(ed == (cs * (cs - 1))) ans++;
        }
        return ans;
    }
    public static void main(String[] args) throws Exception {}
}