#include <sculk.h>
#include <extern/glad.h>

// shitty opengl 1.1 renderer
// nothing serious, just to mess around :^) (ill make a serious vulkan/wgpu/whatever renderer later on)

GraphicsAPI SculkReturnGraphicsAPI(){
    return GAPI_OPENGL;
}


SCStatus SculkCreateRenderer(_IN_ void* initialData){
    gladLoadGLLoader((GLADloadproc)initialData);
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
    glDrawArrays(GL_TRIANGLES, 0, 6);
    return SCSTATUS_SUCCESS;
}

SCStatus SculkTestRect(){
    float quad[] = {
        0.5f, -0.5f,
        -0.5f, -0.5f,
        -0.5f, 0.5f,
        0.5f, 0.5f
    };
    float colors[] = {
        1.0, 0.0, 0.0,
        0.0, 1.0, 0.0,
        0.0, 0.0, 1.0,
        1.0, 0.0, 1.0
    };

    glVertexPointer(2, GL_FLOAT, 0, quad);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glDrawArrays(GL_QUADS, 0, 8);

    return SCSTATUS_SUCCESS;
}

SCStatus SculkDestroyRenderer(){

    return SCSTATUS_SUCCESS;
}
