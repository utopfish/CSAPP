#include <stdio.h>
typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len){
    int i;
    for (i =0;i<len;i++){
        printf(" %.2x",start[i]);
    }
    printf("\n");
}
void show_int(int x){
    show_bytes ((byte_pointer) &x,sizeof(int));
}
void show_float(float x){
    show_bytes((byte_pointer) &x, sizeof(float));
}
 void show_poniter(void *x){
     show_bytes((byte_pointer) &x,sizeof(void *));
 }

 void test_show_bytes(int val){
     int ival= val;
     float fval=(float)val;
     int *pval=&ival;
     show_int(ival);
     show_float(fval);
     show_poniter(pval);
 }
 int main(){
     int val=0x12345678;
     test_show_bytes(val);
 }
 // 当前mingw上的使用大端法来对有效字节进行排序。