#include <sculk.h>


i32 main(){

    SCStatus status = SculkCreateWindow("SCULK", 800, 600);
    if(status != SCSTATUS_SUCCESS){
        DEBUG_FAIL("status returned %d\n", status);
        return -1;
    }
    float i = 0;
    while(SculkShouldClose() != SCSTATUS_SHOULD_CLOSE){
        i+=0.000001;
        SculkBeginDrawing();
        SculkClearColor(RGBA(0, 0, 0, 255));
        //SculkTestTriangle();
        //SculkTestRect();
        SculkBegin3D(NULL); // NULL for now bc we dont actually use the camera lol
        SculkTestCube(i);
        SculkEnd3D();
        SculkEndDrawing();
    }
    SculkCloseWindow();
    return 0;
}
