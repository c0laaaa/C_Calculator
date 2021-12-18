# C_Calaulator

## 初始版本
一个简单的逆波兰表达式的计算器，目前只支持非负数的四则运算

比如要计算(10.23 + 12.234) * 32.123 / 12.12 - 5.8

运行calculator可执行程序，然后输入
10.23 12.234 + 32.123 * 12.12 / 5.8 -

然后可以得出结果

~~~ shell
$ ./calculator 
10.23 12.234 + 32.123 * 12.12 / 5.8 -
53.738867
~~~

## 第二版
增加了对于负数的支持

比如，现在可以计算(-10.23 + -12.234) * -32.123 / 12.12 - -5.8
运行calculator可执行程序，然后输入
-10.23 -12.234 + -32.123 * 12.12 / -5.8 -

然后可以得出结果

~~~ shell
$ ./calculator 
-10.23 -12.234 + -32.123 * 12.12 / -5.8 -
65.338867
~~~