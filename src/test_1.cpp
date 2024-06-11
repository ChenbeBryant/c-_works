#include <iostream>
#include "log.h"
void programA_FunA1() { printf("I'am ProgramA_FunA1 and be called..\n"); }

void programA_FunA2() { printf("I'am ProgramA_FunA2 and be called..\n"); }

void programB_FunB1(void (*callback)()) {
  printf("I'am programB_FunB1 and be called..\n");
  callback();
}

int main(int argc, char **argv) {
  programA_FunA1();

  programB_FunB1(programA_FunA2);

  OutputDebugString("输出调试信息car123");

  return 1 ;
}

public List <int []> getthem (){
  List <int []> list1  = new ArrayList<int []>;
}