#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <emscripten.h>
int count=0;
int play=1;
int x=0;
int y=0;
int z=0;
char *Prompt(char *c){
    char buffer[4096]="prompt(\"";
    
    strcat(buffer,c);
    strcat(buffer,"\")");
    return emscripten_run_script_string(buffer);
        
}


void kernel_main(){
     if (play){
         if(count==0)x=atoi(Prompt("please enter x?..."));
         if(count==1)y=atoi(Prompt("please enter y?..."));
         if(count==2)z=atoi(Prompt("please enter z?..."));
         if(count==3)printf("x*y*z=%d\n",x*y*z);
         if(count==4)play=0;
         count++;
     }
}

int main() {
    emscripten_set_main_loop(kernel_main,1,0);
    return 0;
}