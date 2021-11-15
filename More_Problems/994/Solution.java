// Rotting Oranges

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public int orangesRotting(int[][] grid) {
		if (grid.length == 0 || grid[0].length == 0)
			return -1;
		int counter = -1;

		int m = grid.length;
		int n = grid[0].length;
		boolean isthereanyones = false;
		while (true) {
			boolean changedany = false;
            // keep a tracker to see if the cell is already rotten in this minute iteration
			boolean[] tracker = new boolean[m * n];
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					if (grid[i][j] == 0 ) { 
						continue;
					}
                    if(grid[i][j] == 1){
                        isthereanyones = true;
                        continue;
                    }
					if (tracker[(n*(i%m))+(j%n)] == true) {
						continue;
					}
					boolean temp = rotadjascent(grid, i, j, m, n, tracker);
					if (changedany || temp) {
						changedany = true;
					}
				}
			}
            
			//System.out.println(Arrays.deepToString(grid));
			if (changedany && counter == -1) {
				counter = 1;
			} else if (changedany) {
				counter++;
			} 
            if (counter == -1 && isthereanyones == false) {
                return 0;
            }
			if (changedany == false) {
				break;
			}
		}
        
        for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (grid[i][j] == 1) {
					return -1;
				}

			}
		}
		return counter;
	}

	private boolean rotadjascent(int[][] grid, int i, int j, int m, int n, boolean[] tracker) {
		boolean changed = false;
		if (i - 1 >= 0 && grid[i - 1][j] == 1) {
			grid[i - 1][j] = grid[i][j];
			changed = true;
			tracker[(n * ((i - 1) % m)) + (j % n)] = true;
		}
		if (i + 1 < m && grid[i + 1][j] == 1) {
			grid[i + 1][j] = grid[i][j];
			changed = true;
			tracker[(n * ((i + 1) % m)) + (j % n)] = true;
		}
		if (j - 1 >= 0 && grid[i][j - 1] == 1) {
			grid[i][j - 1] = grid[i][j];
			changed = true;
			tracker[(n * (i % m)) + ((j - 1) % n)] = true;
		}
		if (j + 1 < n && grid[i][j + 1] == 1) {
			grid[i][j + 1] = grid[i][j];
			changed = true;
			tracker[(n * (i % m)) + ((j + 1) % n)] = true;
		}
		return changed;
	}

	public static void main(String[] args) throws IOException {}
}
