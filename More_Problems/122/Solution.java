// Best Time to Buy and Sell Stock II

import java.io.*;
import java.util.*;
import java.lang.*;
import java.math.*;
import java.text.*;
import java.security.*;

public class Solution {
    public int maxProfit(int[] prices) {
        int profit = 0;
        for(int i = 0; i < prices.length - 1; i++)
            if(prices[i + 1] > prices[i]) profit+= prices[i + 1] - prices[i];
        return profit;
    }
    public static void main(String[] args) throws IOException {}
}
