#include <sculk.h>
#include <sculk\window.h>
#include <sculk\renderer.h>


i32 main(){

    SCStatus status = SculkWinCreateWindow("SCULK", 800, 600);
    if(status != SCSTATUS_SUCCESS){
        DEBUG_FAIL("status returned %d\n", status);
        return -1;
    }
    while(SculkWinShouldClose() != SCSTATUS_SHOULD_CLOSE){
        SculkWinGetEvents();
        SculkBeginDrawing();
        SculkClearColor(RGBA(0, 0, 0, 255));
        SculkTestTriangle();
        SculkBeginDrawing();
        SculkWinSwapBuffers();
    }
    SculkWinCloseWindow();
    return 0;
}
