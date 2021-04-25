## Exercise 1:

### Scenario 1:

0. Associativity: 1 (Venus won't let you change this, why?)
   1. there is only one cache line

![image-20210425164331022](image-20210425164331022.png)

1. What combination of parameters is producing the hit rate you observe? (Hint: Your answer should be the process of your calculation.)

   1. hit rate=0, cache data will be replace before next loop to use it
2. What is our hit rate if we increase Rep Count arbitrarily? Why?

   1. still 0

3. How could we modify our program parameters to maximize our hit rate?

   1. array size=32

   

### Scenario 2:

1. What combination of parameters is producing the hit rate you observe? (Hint: Your answer should be the process of your calculation.)

   1. Hit rate=0.75	size=256, go through once, block size=16, 256/16=16, so 16 times load block, Compulsory miss=16

      times of word loop=32, each loop need to read and write, 32*2=64, so accesses 64 times

      cache can exactly be filled with all data it needed (cache size=256)

   ![image-20210425165205749](image-20210425165205749.png)

2. What happens to our hit rate as Rep Count goes to infinity? Why?

   1. 1, since cache can exactly be filled with all data it needed, and compulsory miss will be ignore

3. Suppose we have a program that uses a very large array and during each Rep, we apply a different operator to the elements of our array (e.g. if Rep Count = 1024, we apply 1024 different operations to each of the array elements). How can we restructure our program to achieve a hit rate like that achieved in this scenario? (Assume that the number of operations we apply to each element is very large and that the result for each element can be computed independently of the other elements.) What is this technique called?

   1. Cache Blocking Techniques

   2. ![image-20210425171121304](image-20210425171121304.png)

      之前是对于每一个body1，我把所有body2算一遍。现在是对于每一个body1，我先把body2分成、比如、10份，先把第一份body2全部算一遍，再对于每个body1，把第二份body2都算一遍。划分得当的话，每一份body2可以全部被存在cache里，对于每个body1算的时候，都是hit的。否则，全部过一遍body2的话，下一个循环开头用到的body2又被flush掉了。

   3. 程序改法：还没想，暂时先跳过，不过和上面的程序差不多，尽量划分成block，一次把整个block都算完

### Scenario 3:

1. Run the simulation a few times. Every time, set a different seed value (bottom of the cache window). Note that the hit rate is non-deterministic. What is the range of its hit rate? Why is this the case? ("The cache eviction is random" is not a sufficient answer)
     1. Five experiments: 0.3125，0.25，0.1875，0.4375，0.375，so the range is approximately between 0.1875-0.4375，and theoretically range is between 0 (always flush one block resulting miss every time)-0.5 (the same as LRU)
     2. 这里的random应该是cache就算还没满，也是随便找一个flush掉，所以会出现cache还没满但是把有数据的cache给flush掉的情况——待确认？

2. Which Cache parameter can you modify in order to get a constant hit rate? Record the parameter and its value (and be prepared to show your TA a few runs of the simulation). How does this parameter allow us to get a constant hit rate? And explain why the constant hit rate value is that value.
     1. We can modify random to LRU, and hit rate is 0.5——the first loop is compulsory miss, and the second loop is a all-hit loop.

## Exercise 2:

![image-20210425204149844](image-20210425204149844.png)

1. 