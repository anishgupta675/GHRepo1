import java.util.*;
import java.lang.*;

class Solution {
    public int[] kthSmallestPrimeFraction(int[] arr, int k) {
        double low = 0.0, high = 1.0;
        while(low < high) {
            int j = 1, total_smaller_fractions = 0, numerator_index = 0, denominator_index = 0;
            double max_fraction = 0.0, mid = (low + high) / 2.0;
            for(int i = 0; i < arr.length - 1; i++) {
                while(j < arr.length && arr[i] >= mid * arr[j]) j++;
                total_smaller_fractions+= arr.length - j;
                if(j == arr.length) break;
                if(max_fraction < (double)arr[i] / arr[j]) {
                    numerator_index = i;
                    denominator_index = j;
                    max_fraction = (double)arr[i] / arr[j];
                }
            }
            if(total_smaller_fractions == k) return new int[]{ arr[numerator_index], arr[denominator_index] };
            else if(total_smaller_fractions > k) high = mid;
            else low = mid;
        }
        return new int[]{};
    }
    public static void main(String[] args) throws Exception {}
}