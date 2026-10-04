#include <sculk.h>
#include <extern/glad.h>



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
    return SCSTATUS_SUCCESS;
}

// STUB, TODO: implement
SCStatus SculkEndDrawing(){
    SculkFlushBuffers();
    SculkSwapBuffers();
    return SCSTATUS_SUCCESS;
}

SCStatus SculkTestTriangle(){
    glBegin(GL_TRIANGLES);

    glColor3d(1.0, 0.0, 0.0);
    glVertex3d(0.5f, -0.5f, 0.0f);

    glColor3d(0.0, 1.0, 0.0);
    glVertex3d(-0.5f, -0.5f, 0.0f);

    glColor3d(0.0, 0.0, 1.0);
    glVertex3d(0.0f, 0.5f, 0.0f);

    glEnd();
    return SCSTATUS_SUCCESS;
}

SCStatus SculkDestroyRenderer(){
    return SCSTATUS_SUCCESS;
}
