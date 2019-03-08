#include "userlib/syscall.h"
#include "userlib/libnachos.h"

SemId sem1;
SemId sem2;

VoidNoArgFunctionPtr testSem1(){
    P(sem1);
    n_printf("test de wait sem1\n");
    V(sem2);
    n_printf("fin wait sem1\n");
    return 0;
}

VoidNoArgFunctionPtr testSem2(){
    V(sem1);
    n_printf("test wait sem2\n");
    P(sem2);
    n_printf("fin wait sem2\n");
    return 0;
}



int main()
{
    n_printf("** ** ** Bonjour le monde ** ** **\n");

    sem1 = SemCreate((char *) "sem1", 1);
    sem2 = SemCreate((char *) "sem2", 1);
    threadCreate((char *) "proccess1", (VoidNoArgFunctionPtr)&testSem1);
    threadCreate((char *) "proccess2", (VoidNoArgFunctionPtr)&testSem2);

    return 0;
}