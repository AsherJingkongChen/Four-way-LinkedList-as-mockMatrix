#include <stdio.h>
#include "./lib/Community.h"
#define ROW 6
#define COL 9
int main(){
    Community* acom = community(ROW, COL);
    see_community(acom, ROW, COL);
    printf("%d\n",(acom[ at(COL,0,0) ].down->up)==&acom[ at(COL,0,0) ]);
    del_community(acom);
    return 0;
}