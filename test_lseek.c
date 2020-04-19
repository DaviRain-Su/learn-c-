#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    if(lseek(STDIN_FILENO, 0, SEEK_CUR) == -1){
        printf("cannnot seek\n");
    }else{
        printf("seek ok\n");
    }
    exit(0);
}