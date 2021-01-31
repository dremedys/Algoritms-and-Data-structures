import java.util.*;
//given an array of temperatures, for each of them print how many days to wait until warmer temperature
class Solution1 {
    public int[] dailyTemperatures(int[] T) {
        int[] ans = new int[T.length]; //create an array to keep ans for each day
        Stack<Integer> stack = new Stack();
        for (int i = T.length - 1; i >= 0; --i) { //start working from the ned
            while (!stack.isEmpty() && T[i] >= T[stack.peek()]) { //delete worser guys it has no meaning guys
                stack.pop(); 
            } //while stack has element
            ans[i] = stack.isEmpty() ? 0 : stack.peek() - i;  //if there no better one 0 , aitpese sony alagoindar
            stack.push(i);
        }
        return ans;
    }
}