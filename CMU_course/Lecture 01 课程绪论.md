## Lecture 01 课程绪论

Abstraction is good  But don't forget reality

#### 数据类型

在 int 类型中
$$
40000*40000->1600000000
$$

$$
50000*50000 -> ?
$$



在 folat 类型中
$$
(1e20+-1e20)+3.14->3.14
$$

$$
1e20+(-1e20+3.14)->0
$$

为了妥协，int 类型中会出现溢出，float 会出现舍入



#### 机器级别编程

c 语言是如何变成机器语言的。汇编语言

####  内存系统

内存并非无限的，以下代码会出 bug，与内存的分布与访问有关，c和c++不会做任何边界检测，所以很容易出现非法的代码。 

```c
#include <stdio.h>
typedef struct {
    int a[2];
    double d;
} struct_t;

double fun (int i){
    volatile struct_t s;
    s.d=3.14;
    s.a[i]=1073741824;
    return s.d; 
}
 int main(){
     printf("%f",fun(6));
 }
```

内存性能例子

```c
void copyij(int src[2048][2048],int dst[2048][2048]){
	int i,j;
	for (i=0;i<2048;i++){
        for (j=0;j<2048;j++){
            dst[i][j]=src[i][j];
        }
    }	   
}
```

```c
void copyij(int src[2048][2048],int dst[2048][2048]){
	int i,j;
	for (j=0;j<2048;j++){
		for (i=0;i<2048;i++){
            dst[i][j]=src[i][j];
        }
    }	   
}
```

由于有限遍历的行列不同，前者性能在某些机器上会比后者快 20 倍。