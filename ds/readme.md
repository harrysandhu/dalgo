## stack


------
1. Nearest greater to left.
2. ""       ""     to right.  :: standard -> "next largest element"
3. ""      smaller to left. :: standard -> "next smallest element"
4. ""       ""     to right.
-----
    |
    |
    |
    |
-----    
5. Stock span problem 
6. Maximum area of histogram
    |
    |
    |
----
7. Max area of Rectangle in binary matrix. 

- other concepts
----

8. Rain water trapping
9. Implementing a min stack
   - extra space
   - no extra space

10. Implmenting stack using heap
11. the celebrity problem
12. longest valid parenthesis
13. iterative TOH


------
## Identification
1. array -> high prob for stack. 
    * (if you feel like sorting -> heap)
2. BF. 0(n^2)
 - Simple O(n2)
 ```
    for(int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)

    i -> 0 --> n
    j -> 0 --> n j++
    
    OR 
    j -> n ---> 0 j--
  ```

- Dependent O(n2)
    - j loop(second) depends on i loop, -> use stack. 
    ```
        for(int i = 0; i > n; i++)
            for(int j = 0; j < i; j++)

       i -> 0 --> n

       BUT IN THIS CASE.

       0---i---n
       
       j -> 0 to i j++ 
       j -> i to 0 j--
       j -> i to n j++
       j -> n to i j--

        
    ```
- if : j = fxn(i):
### in this case use STACK!!








