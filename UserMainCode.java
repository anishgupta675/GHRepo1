// import java.util.*;

// public class UserMainCode {
//     private static final Scanner sc = new Scanner(System.in);
//     private static UserMainCode umc = new UserMainCode();
//     private static int findPin(int input1, int input2, int input3, int input4) {
//         boolean flag = true;
//         int odd_pos = 0, even_pos = 0;
//         while(input1 > 0 || input2 > 0 || input3 > 0) {
//             if(flag) odd_pos+= (input1 % 10) + (input2 % 10) + (input3 % 10);
//             else even_pos+= (input1 % 10) + (input2 % 10) + (input3 % 10);
//             input1/= 10;
//             input2/= 10;
//             input3/= 10;
//             flag^= true;
//         }
//         return (input4 % 2 == 0) ? (even_pos - odd_pos) : (odd_pos - even_pos);
//     }
//     public static void main(String[] args) throws Exception {
//         int input1 = sc.nextInt(), input2 = sc.nextInt(), input3 = sc.nextInt(), input4 = sc.nextInt();
//         System.out.println(umc.findPin(input1, input2, input3, input4));
//     }
// }

import java.util.*;

public class UserMainCode {
    private static final Scanner sc = new Scanner(System.in);
    private static UserMainCode umc = new UserMainCode();
    private static int findRepArray(int[] input1, int input2) {
        int first_element = 0;
        HashSet<Integer> hs = new HashSet<Integer>();
        for(int i = 0; i < input2; i++) {
            if(input1[i] > 0) {
                if(first_element == 0) first_element = input1[i];
                if(hs.contains(input1[i])) return input1[i];
                hs.add(input1[i]);
            }
        }
        return first_element;
    }
    public static void main(String[] args) throws Exception {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i = 0; i < n; i++) arr[i] = sc.nextInt();
        System.out.println(umc.findRepArray(arr, n));
    }
}