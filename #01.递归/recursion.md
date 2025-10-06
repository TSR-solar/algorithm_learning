# 递归
## 1. 阶乘函数
返回n的阶乘。

`fac.cpp`

## 2. 斐波那契数列
返回斐波那契数列的第n个数。注意：第0个数和第1个数均为1。

`fib.cpp`

## 3. 全排列
产生数组元素的所有全排列。

第一行输入1个数，代表数组元素个数n。  
第二行输入n个数，代表数组的元素。

`perm.cpp`

输入：
```
4
1 2 3 4
```

输出：
```
1 2 3 4
1 2 4 3
1 3 2 4
1 3 4 2
1 4 3 2
1 4 2 3
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 3 1
2 4 1 3
3 2 1 4
3 2 4 1
3 1 2 4
3 1 4 2
3 4 1 2
3 4 2 1
4 2 3 1
4 2 1 3
4 3 2 1
4 3 1 2
4 1 3 2
4 1 2 3
```

## 4. 汉诺塔
完成n个盘子的汉诺塔问题。

`Hanoi.cpp`

输入：
```
4
```

输出：
```
move 1 from 1 to 2
move 2 from 1 to 3
move 1 from 2 to 3
move 3 from 1 to 2
move 1 from 3 to 1
move 2 from 3 to 2
move 1 from 1 to 2
move 4 from 1 to 3
move 1 from 2 to 3
move 1 from 2 to 3
move 2 from 2 to 1
move 1 from 3 to 1
move 3 from 2 to 3
move 1 from 2 to 3
move 2 from 2 to 1
move 1 from 3 to 1
move 1 from 2 to 3
move 2 from 2 to 1
move 1 from 2 to 3
move 2 from 2 to 1
move 1 from 3 to 1
move 3 from 2 to 3
move 1 from 1 to 2
move 2 from 1 to 3
move 1 from 2 to 3
Total: 15
```

## 5. n皇后
把n个皇后放在n*n的棋盘上。要求同行、同列、同斜线最多只能有1个皇后。

`queen.cpp`

输入：
```
6
```

输出：
```
solution 1: 
0 1 0 0 0 0 
0 0 0 1 0 0 
0 0 0 0 0 1 
1 0 0 0 0 0 
0 0 1 0 0 0 
0 0 0 0 1 0 

solution 2:
0 0 1 0 0 0
0 0 0 0 0 1
0 1 0 0 0 0
0 0 0 0 1 0
1 0 0 0 0 0
0 0 0 1 0 0

solution 3:
0 0 0 1 0 0
1 0 0 0 0 0
0 0 0 0 1 0
0 1 0 0 0 0
0 0 0 0 0 1
0 0 1 0 0 0

solution 4:
0 0 0 0 1 0
0 0 1 0 0 0
1 0 0 0 0 0
0 0 0 0 0 1
0 0 0 1 0 0
0 1 0 0 0 0
```

## 6. 归并排序
`MergeSort.cpp`

### 问题求解
1. 不停二分，直到没法再分
2. 对相邻两个数组进行归并，合成大的有序数组
3. 不停合并，直到没法再合

## 7. 快速排序
`QuickSort.cpp`

### 问题求解
1. 以最中间的数作为“旗”
2. 两头搜索，把小于旗的数放到左边，大于旗的数放到右边
3. 当两头相碰时，旗左边应该都<=它，右边都>=它
4. 旗将大数组隔开成俩小数组，对俩小数组进行快速排序。
5. 直到数组大小为1。

## 8. 