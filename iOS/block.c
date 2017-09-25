#include <stdio.h>

int main(){
    void (^blk)(void) = ^(){printf("This is a block.");};
    blk();
    return 0;
}
