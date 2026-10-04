#define RGFW_OPENGL
#define RGFW_IMPLEMENTATION
#include <extern/rgfw.h>
#include <sculk.h>


static bool rgfwInit = FALSE;

static RGFW_window* window = NULL;
static GraphicsAPI gApi;

static inline SCStatus SculkInit(){
    gApi = SculkReturnGraphicsAPI();
    if(rgfwInit != TRUE){
        RGFW_init();
        // if(result != 0){
        //     return SCSTATUS_CANT_START_WINDOWING_PLATFORM;
        // }
    }
    return SCSTATUS_SUCCESS;
}

SCStatus SculkCreateWindow(_IN_ const char* title, _IN_ i32 width, _IN_ i32 height){
    if(window != NULL){
        return SCSTATUS_ALREADY_INITIALIZED;
    }
    SCStatus status = SculkInit();
    if(status != SCSTATUS_SUCCESS) return status;
    // TODO: add flags as arguments for CreateWindow
    i32 flags = RGFW_windowCenter | RGFW_windowNoResize;
    switch(gApi){
        case GAPI_OPENGL:{
            flags |= RGFW_windowOpenGL;
            break;
        }
        default:{
            break;
        }
    }
    window = RGFW_createWindow(title, 0, 0, width, height, flags);
    if(window == NULL){
        return SCSTATUS_CANT_CREATE_WINDOW;
    }
    switch(gApi){
        case GAPI_OPENGL:{
            SculkCreateRenderer((void*)RGFW_getProcAddress_OpenGL);
            RGFW_window_makeCurrentContext_OpenGL(window);
            break;
        }
        default:{
            DEBUG_WARNING("no graphics backend set!\n");
            break;
        }
    }
    return SCSTATUS_SUCCESS;
}

SCStatus SculkShouldClose(){
    if(window == NULL){
        return SCSTATUS_NOT_INITIALIZED;
    }
    if(RGFW_window_shouldClose(window) != RGFW_FALSE){
        return SCSTATUS_SHOULD_CLOSE;
    } else return SCSTATUS_SUCCESS;
}

// stub (kind of)
// TODO: get the events and put them somewhere in the window struct
SCStatus SculkGetEvents(){
    RGFW_event event;
    RGFW_window_checkEvent(window, &event);
    return SCSTATUS_SUCCESS;
}

SCStatus SculkSwapBuffers(){
    RGFW_window_swapBuffers_OpenGL(window);
    return SCSTATUS_SUCCESS;
}

SCStatus SculkCloseWindow(){
    if(window == NULL){
        return SCSTATUS_INVALID_PARAMETER;
    }
    SculkDestroyRenderer();
    RGFW_window_close(window);
    RGFW_deinit();
    return SCSTATUS_SUCCESS;
}
