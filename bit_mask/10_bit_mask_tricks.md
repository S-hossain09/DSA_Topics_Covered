# Bitwise Tricks

**Bitwise operations are much faster than normal arithmatic operation.**

## 1. To check if its even or not :

**By using modular operator :**
if (num % 2 == 0) it is even 
if (num % 2 != 0) it is odd.

**By using bitwise :**
If **x = 9**,Then the binary representation of 9 is : **1001**.

If **x = 10**,Then the binary representation of 10 is: **1010**

In binary every even number has 0 at the end and every odd number has 1 at the end.

**To check in coding:** 
just do this **(num & 1)** , it will return the least bit. 

### Code example:

```cpp
int main() 
{
    int x = 9;
    int y = 10;


    cout << "If the least bit is 1, it is odd\n";

    cout << "If the least bit is 0, it is even\n";

    cout << endl;

    cout << "x returns: " << (x&1) << endl;

    cout << "y returns: " << (y&1) << endl;

    return 0;
}
```

## 2. If a number is a power of 2:

In binary there will be a **single bit which is 1**. and that will represent if a number is a power of two.

suppose x = 1000.
which is 8. 8 is a 2 power of 3. And there are only one 1 in the binary representation of 8.

**To check in coding :**

We need to check if the X & (X - 1) returns 0 or not. **If it returns 0 then X is a 2 power of something**

If it returns **something > 0** then it **is not a 2 power of something.**

for example : x = 8;

In binary : x = 1000.
x - 1 = 0111.

now 
    1000
  & 0111

return 0. So we can understand x is a 2 power of something.

### Code example:

```cpp
int main() 
{
  int x = 8;

  cout << "if x is a 2 power of somehting it will return : 0" << endl;
  cout << "Else it will return > 0" << endl;

  int result = x&(x-1);

  cout << endl;
  cout << "x returns : " << result << endl;

  return 0;
}
```

**It has an edge case:**
If x = 0 it retruns 0 as well. 

So if we encounter x = 0, we will say x is not equal 0 and otherwise use the formula.

## 3. Playing with the kth bit:

**i. Check if the kth bit is set :**
Means that if the kth bit is 1 or not . if it is 1 it is set. else not set.

To check if the kth bit is set or not , we need to do this :
suppose we want to check the 3rd bit is 1 or not .

```
x = 10010011100
    00000001000
```

we will only set the 3rd bit 1 and eveything else 0 , by this when we use & operator with it , it will return 1 if its set and 0 if its not .

**How to do :**
we need to do x & (1 << kth bit) .

**ii. Toggle the kth bit :**
Toggling the kth bit means it will return 1 if x != k. 

suppose toggling the 2nd bit:

```
means 
x = 100100
    000100

    100000 -- result
```

**How to do :**
We need to do x ^ (1<< k):

by doing this we will simply toggle the kth bit.

**iii. Set/Unsetting the kth bit:**

**Setting the kth bit:**
Set the kth bit means to turn it to 1 from 0.

We can do this with OR operator and setting the kth bit to 1 and rest 0

Supose we want set the first bit.

```
x = 100100
    000010

    100110 -- result
```

**How to do :**
We need to x || (1<< k).

Similarly unsetting the kth bit:

**Unsetting the kth bit:**
Unset the kth bit means to turn it to 0 from 1.

We can do this with AND operator and setting the kth bit to 0 and rest 1

Supose we want set the second bit.

```
x = 100100
    111011

    100000 -- result
```

**How to do :**
We need to x & not(1<< k). By not means:
suppose 8 = 1000 not 8 means = 0111

## 4 Multiplying/Dividing number by 2 to power k:

suppose we have a number x = 5. Now we want **Multiply x with 2** once and make it 10.

The binary representation of x is 101. if we left shift x once . it will becomoe 1010 , which is 10. So if we **left shift** when need **to multiply** by the number times of 2 . we easily get the multiplication.

Now suppose we have a number x = 5, but we want to divide 5 / 2 . The binary representation of x is 101. If we right shift then it becomes 10. which is 2. So if we **right shift** when need **to divide** by the number times of 2 . we easily get the division.

**How to do:**

# For Multiplication :

X = 5. 
But we want to multiply 5 with 4. So we will left shift x twice because (4 = 2 to 2).
then we will get 

**Like this :** ```x<<2```.

# For Division :

X = 20. 
But we want to divide 5 with 8. So we will left shift x twice because (8 = 2 to power 3).
then we will get 

**Like this :** ```x<<3```.

## 5 Find out x % 2 power k

## 6 Swapping 2 numbers X and Y without a temporary variable

Suppose we have two values x = 5 and y = 2.
Now we want to swap it without third variable.
We can do this with XOR operator. 

**In XOR operator :**
1 != 0 means 1
else 0

**How to do:**
We can do this by : 

```cpp
x = x^y;   // {x = x ^ y ... y = y
y = x^y;   // {x = x ^ y... y = x ^ y ^ y = x
// this cancel outs the y. as it is same.
x = x^y;   // {x = x ^ y ^ x = y... y = x
// this cancel outs the x. as it is same.
```

## 7 Property

Number of set bits in A = x 
and the number of set bits in B = y
and the number of bit sin (A+B) = Z

then 
z is even if x + y is even.
z is odd if x + y is odd.