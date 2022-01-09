#include <stdlib.h>
#include <stdio.h> //for testing
#include "Community.h"
size_t at(size_t width, size_t _row, size_t _col){
    return _row * width + _col;
}
Community* community(size_t row, size_t col){
    Community* location = malloc(row * col * sizeof(Community));
    for(size_t R = 0; R < row; R++){
        for(size_t C = 0; C < col; C++){
            location[ at(col,R,C) ].number = R*col+C;
            location[ at(col,R,C) ].up = (R!=0) ? &location[ at(col,R-1,C) ] : NULL;
            location[ at(col,R,C) ].down = (R!=row-1) ? &location[ at(col,R+1,C) ] : NULL;
            location[ at(col,R,C) ].left = (C!=0) ? &location[ at(col,R,C-1) ] : NULL;
            location[ at(col,R,C) ].right = (C!=col-1) ? &location[ at(col,R,C+1) ] : NULL;
        }
    }
    return location;
}
void del_community(Community* location){
    free(location);
}
void see_community(Community* location, size_t row, size_t col){
    for(size_t C = 0; C < col; C++){
        putchar('.');
        if(C!=col-1) putchar(' ');
    }
    putchar('\n');
    for(size_t R = 0; R < row; R++){
        for(size_t C = 0; C < col; C++){
            printf("%d",location[ at(col,R,C) ].number);
            if(C!=col-1) putchar(' ');
        }
        putchar('\n');
    }
    for(size_t C = 0; C < col; C++){
        putchar('.');
        if(C!=col-1) putchar(' ');
    }
    putchar('\n');
}