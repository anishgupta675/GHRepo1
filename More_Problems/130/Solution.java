// Surrounded Regions

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public void solve(char[][] board) {
        for (int i = 0; i < board.length; i++) {
            if (board[i][0] == 'O')
                dfs(board, i, 0);
            if (board[i][board[i].length - 1] == 'O')
                dfs(board, i , board[i].length - 1);
        }
        
        for (int j = 1; j < board[0].length - 1; j++) {
            if (board[0][j] == 'O')
                dfs(board, 0, j);
            if (board[board.length - 1][j] == 'O')
                dfs(board, board.length - 1, j);
        }
        
        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[i].length; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                
                if (board[i][j] == 'C') {
                    board[i][j] = 'O';
                }
            }
        }
        
    }
    
    private void dfs(char[][] board, int i, int j) {
        if (i <0 || j < 0 || i >= board.length || j >= board[i].length || 
            board[i][j] == 'X' || board[i][j] == 'C')
           return;
        
        board[i][j] = 'C';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    public static void main(String[] args) throws IOException {}
}
