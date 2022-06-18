# Count of strings that can be formed using a, b and c under given constraints
## Easy 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a length n, count the number of strings of length n that can be made using ‘a’, ‘b’ and ‘c’ with at-most one ‘b’ and two ‘c’s allowed.</span></p>

<p><strong><span style="font-size:18px">Example 1:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 1</span>
<span style="font-size:18px"><strong>Output:</strong> 3
<strong>Explanation:</strong> Possible strings are: "a",
"b" and "c"</span>
</pre>

<p><strong><span style="font-size:18px">Example 2:</span></strong></p>

<pre><span style="font-size:18px"><strong>Input:</strong> n = 3
<strong>Output:</strong> 19
<strong>Explanation:</strong> Number of strings with 3 
occurrances of a: 1
2-a and 1-b: 3
2-a and 1-c: 3
1-a, 1-b and 1-c: 6
1-a and 2-c: 3
1-b and 2-c: 3
So, total number of strings of length 3
is 1 + 3 + 3 + 6 + 3 + 3 = 19
</span></pre>

<p><span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>countStr</strong><strong>()</strong>&nbsp;which takes the <strong>n</strong></span><span style="font-size:18px"><strong> </strong>as inputs and returns the answer.<br>
<br>
<strong>Expected Time Complexity:</strong>&nbsp;O(1)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(1)<br>
<br>
<strong>Constraints:</strong><br>
1 ≤ n ≤ 10<sup>5</sup></span></p>
 <p></p>
            </div>