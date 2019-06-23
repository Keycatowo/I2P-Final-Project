#include <stdio.h>
#include <stdlib.h>
#include "head_files.h"


void show_err_msg(int msg){
    printf("Error code: %d\n",msg);
    fprintf(stderr,"unexpected msg: %d",msg);
    game_destroy();
    exit(9);
}
