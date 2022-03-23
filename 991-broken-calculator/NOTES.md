if you are not able to solve in forward direction then try to solve backwards
​
Use The Logic That We Move From Target To StartValue
​
Target -> startvalue
Minimize The Steps
Why it's right
Actually, what we do is:
If Y is even, Y = Y / 2
If Y is odd, Y = (Y + 1) / 2
​
We reduce Y with least possible operations, until it's smaller than X.
​
And we know that, we won't do Y + 1 twice in a row.
Becasue we will always end with an operation Y / 2.
​
2N times Y + 1 and once Y / 2 needs 2N + 1 operations.
Once Y / 2 first and N times Y + 1 will end up with same result, but needs only N + 1 operations.