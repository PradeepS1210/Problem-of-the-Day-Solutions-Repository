/*
Asked in Directi, Tech Mahindra, Deloitte
Problem of the Day: Stephen Balls
Problem Description: https://medium.com/@pradeepsooryavanshee1210/stephen-balls-unstop-solution-bfa15392815d
*/

import java.util.HashSet;
import java.util.Scanner;

public class Main
{

public
    static int countBalls(String balls, String playScreen)
    {
        HashSet<Character> set = new HashSet<>();
        int total = 0;

        for (int index = 0; index < balls.length(); index++)
        {
            set.add(balls.charAt(index));
        }

        for (int index = 0; index < playScreen.length(); index++)
        {
            if (set.contains(playScreen.charAt(index)))
            {
                total++;
            }
        }
        return total;
    }

public
    static void main(String[] args)
    {
        Scanner scanner = new Scanner(System.in);
        String balls = scanner.nextLine();
        String playScreen = scanner.nextLine();
        int count = countBalls(balls, playScreen);
        System.out.println(count);
        scanner.close();
    }
}