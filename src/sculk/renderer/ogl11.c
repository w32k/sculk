#include <sculk.h>
#include <extern/gladogl11.h>

// shitty opengl 1.1 renderer
// nothing serious, just to mess around and learn :^)
// ill make a serious vulkan/wgpu/whatever renderer later on when i learn a bit more about 3d rendering

GraphicsAPI SculkReturnGraphicsAPI(){
    return GAPI_OPENGL;
}


SCStatus SculkCreateRenderer(_IN_ void* initialData){
    gladLoadGLLoader((GLADloadproc)initialData);
    float ar = 800 / 600;
    glViewport(0, 0, 800.0, 600.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glOrtho(0.0, 800.0, 600.0, 0.0, 0.0, 0.0);
    //glTranslatef(0.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);
    return SCSTATUS_SUCCESS;
}


SCStatus SculkFlushBuffers(){
    glFlush();
    return SCSTATUS_SUCCESS;
}

SCStatus SculkClearColor(_IN_ SculkColor color){
    glClearColor(color.r / 255.0f, color.g / 255.0f, color.b / 255.0f, color.a / 255.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    return SCSTATUS_SUCCESS;
}

// STUB, TODO: implement
SCStatus SculkBeginDrawing(){
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    SculkGetEvents();
    return SCSTATUS_SUCCESS;
}

SCStatus SculkEndDrawing(){
    SculkFlushBuffers();
    SculkSwapBuffers();
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    return SCSTATUS_SUCCESS;
}

// STUB, TODO: implement
SCStatus SculkBegin3D(_IN_ SculkCamera* camera){
   // glLoadIdentity();
   // glMatrixMode(GL_MODELVIEW);
    glTranslatef(0.0, 0.0, 0.0);
    return SCSTATUS_SUCCESS;
}

// STUB, TODO: implement
SCStatus SculkEnd3D(){
    return SCSTATUS_SUCCESS;
}

SCStatus SculkTestTriangle(){
    float triangle[] = {
        0.5f, -0.5f,
        -0.5f, -0.5f,
        0.0f, 0.5f,
    };
    float colors[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0
    };


    glVertexPointer(2, GL_FLOAT, 0, triangle);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_TRIANGLES, 0,  ARR_LEN(triangle) / 2);
    return SCSTATUS_SUCCESS;
}

SCStatus SculkTestRect(){
    const float quad[] = {
        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f,
        0.5f, 0.5f
    };
    const float colors[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0
    };

    glVertexPointer(2, GL_FLOAT, 0, quad);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_QUADS, 0,  ARR_LEN(quad) / 2);

    return SCSTATUS_SUCCESS;
}

SCStatus SculkTestCube(_IN_ float rotation){
    glRotatef(rotation, 1.0, 1.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    const float quad[] = {
        // front
        0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, 0.5f,
        -0.5f, 0.5f, 0.5f,
        0.5f, 0.5f, 0.5f,

        // back
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,

        // bottom
        0.5f, -0.5f, 0.5f,
        0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, -0.5f, 0.5f,

        // top
        -0.5f, 0.5f, 0.5f,
        -0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, 0.5f,


        // left
        -0.5f, -0.5f, 0.5f,
        -0.5f, -0.5f, -0.5f,
        -0.5f, 0.5f, -0.5f,
        -0.5f, 0.5f, 0.5f,


        // right
        0.5f, -0.5f, 0.5f,
        0.5f, -0.5f, -0.5f,
        0.5f, 0.5f, -0.5f,
        0.5f, 0.5f, 0.5f

    };
    const float colors[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0,

        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0,

        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0,

        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0,

        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0,

        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0
    };

    glVertexPointer(3, GL_FLOAT, 0, quad);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_QUADS, 0, ARR_LEN(quad) / 3);

    return SCSTATUS_SUCCESS;
}

SCStatus SculkDestroyRenderer(){

    return SCSTATUS_SUCCESS;
}
