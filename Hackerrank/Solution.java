package Hackerrank;

import java.util.Scanner;

public class Solution {
    static boolean isAnagram(String a, String b) {
        // Complete the function
        int H[] = new int[26];

        for (int i = 0; i < 26; i++) {
            H[i] = 0;
        }

        if (a.length() != b.length())
            return false;

        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) >= 97 && a.charAt(i) <= 122)
                H[a.charAt(i) - 97]++;

            else if (a.charAt(i) >= 65 && a.charAt(i) <= 90)
                H[a.charAt(i) - 65]++;

        }
        for (int i = 0; i < b.length(); i++) {
            if (b.charAt(i) >= 97 && b.charAt(i) <= 122)
                H[b.charAt(i) - 97]--;

            else if (b.charAt(i) >= 65 && b.charAt(i) <= 90)
                H[b.charAt(i) - 65]--;

        }

        for (int i = 0; i < a.length(); i++) {
            if (H[i] != 0) {
                return false;
            }
        }

        return true;

    }

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        // System.out.println("Enter 1st string");
        String a = scan.next();
        // System.out.println("Enter 2nd string");
        String b = scan.next();
        scan.close();
        boolean ret = isAnagram(a, b);
        System.out.println((ret) ? "Anagrams" : "Not Anagrams");
    }
}
