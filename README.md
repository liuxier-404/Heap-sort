# Heap-sort
大二数据结构-堆排序  
很基础的一道堆排序的题，回忆一下堆排序的特点：  
1.不稳定性  
2.空间复杂度是O(1)  
3.时间复杂度为O(N*LgN)  
具体操作：（以大顶堆为例）  
1；先把所有数据存储到数组里，然后选择最大的一个非叶子节点  
2：选择其叶子节点最大的数与之交换  
3；从右到左，从上到下调整，如果交换数据后发现叶子节点比其本身的叶子节点大，递归调整该叶子节点  
4：调整完成后，根节点就是最大值，然后交换根节点和最后一个叶节点的值，数组长度减一，继续调整堆，知道数组长度变为1  
![image](https://github.com/liuxier-404/Heap-sort/blob/master/1.jpg)  
