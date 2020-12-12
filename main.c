#include <stdio.h>
#include <stdlib.h>

enum STATE{
    LEFT,LEFT_PLUS,LEFT_TIMES,PLUS_RIGHT,TIMES_RIGHT
}state;


unsigned int memory = 0;
unsigned int input = 0;

int main()
{
    char buf[120];
    state = LEFT;
   fgets(buf, 120,stdin);

    printf("Hello world!\n");
    return 0;
}
void digit(int n){
    input = 10*input + n;
    if(state == LEFT_PLUS){
       state = PLUS_RIGHT;

    }else{
        if(state == LEFT_TIMES){
            state = TIMES_RIGHT;
        }

    }

}
void plus(){
    if(state == LEFT){
        memory = input;
    }else{
        if(state == PLUS_RIGHT){
                memory = memory + input;

        }else{
            if(state == TIMES_RIGHT){
                memory = memory * input;

            }
        }
    }
    input = 0;
    state = LEFT_PLUS;

}
void times(){
    if(state == LEFT){
        memory = input;
    }else{
        if(state == PLUS_RIGHT){
                memory = memory + input;

        }else{
            if(state == TIMES_RIGHT){
                memory = memory * input;

            }
        }
    }
    input = 0;
    state = LEFT_TIMES;

}
void reset(){
    state = LEFT;
    memory = 0;
    input = 0;
}

