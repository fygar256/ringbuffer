#include <stdio.h>

#define BUFFSIZE (20)
int widx=0,ridx=0;
int buffer[BUFFSIZE];
int bufferfull=0;

int put_data(int data) {
    if (bufferfull) return(-1); // BUFFER FULL
    buffer[widx]=data;
    widx=(widx+1)%BUFFSIZE;
    if (widx==ridx) bufferfull=1;
    return 1;
}

int get_data() {
    int data;
    if ((ridx==widx) && (bufferfull==0)) return(-1); // BUFFER EMPTY
    bufferfull=0;
    data=buffer[ridx];
    ridx=((ridx+1)%BUFFSIZE);
    return data;
}






int test()
{
  int data;

// test for normal use
  printf("*** test for normal use ****\n");

  for(int i=0;i<10;i++) {
    data=i;
    put_data(data);
    printf("データ書き込み data=%d \n",data);
    }

  printf("widx=%d ridx=%d\n",widx,ridx);

  for(int i=0;i<10;i++)
    printf("データ読み出し data=%d \n",get_data());


// test for buffer over
  printf("*** buffer over test ****\n");

  // write
  for(int i=0;i<BUFFSIZE+5;i++) {

    data=i;

    printf("試行=%d bufferにデータを書き込み widx=%d ridx=%d data=%d ",i,widx,ridx,data);

    if (put_data(i)==-1)
      printf("BUFFER FULL\n");
    else
      printf("成功\n");
    }

  // read
  for(int i=0;i<BUFFSIZE+5;i++) {
    printf("試行=%d buffer から data を取得 widx=%d ridx=%d ",i,widx,ridx);
    data=get_data();

    if (data==-1)
      printf("BUFFER EMPTY\n");
    else 
      printf("成功　取得データ data=%d\n",data);
    }
}

int main() {
  test();
}
