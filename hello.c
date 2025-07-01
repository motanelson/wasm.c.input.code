// Copyright 2011 The Emscripten Authors.  All rights reserved.
// Emscripten is available under two separate licenses, the MIT license and the
// University of Illinois/NCSA Open Source License.  Both these licenses can be
// found in the LICENSE file.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include <math.h>

#include <emscripten.h>
char *Prompt(char *c){
    char buffer[4096]="prompt(\"";
    
    strcat(buffer,c);
    strcat(buffer,"\")");
    return emscripten_run_script_string(buffer);
        
}
void kernel_main(){
    printf("%s\n",Prompt("you name please?..."));
}

int main() {
    
    kernel_main();
        
    return 0;
}
