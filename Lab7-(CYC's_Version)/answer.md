ex1：
10+45<10+60

10+60+45+10=125ns
Frequency: 1s/125ns = 8MHz

clk2q mul add setup

ex2：
10+60+10=80
10+45+10=65
new time=80ns
Frequency: 1s/80ns = 12.5MHz



Bubble is to ensure that the output of the first computation is ready to be an input to the second. But in this case, there are just two stages, and we can only overlap one stage. Therefore, Though the adder will use the result in previous adder, it would always be ready before the next addition.
