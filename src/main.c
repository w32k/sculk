#include <sculk.h>


i32 main(){

    SCStatus status = SculkCreateWindow("SCULK", 800, 600);
    if(status != SCSTATUS_SUCCESS){
        DEBUG_FAIL("status returned %d\n", status);
        return -1;
    }
    while(SculkShouldClose() != SCSTATUS_SHOULD_CLOSE){
        SculkBeginDrawing();
        SculkClearColor(RGBA(0, 0, 0, 255));
        //SculkTestTriangle();
        SculkTestRect();
        SculkEndDrawing();
    }
    SculkCloseWindow();
    return 0;
}
