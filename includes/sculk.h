#ifndef SCULK_H_INCLUDED
#define SCULK_H_INCLUDED









#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define _OUT_
#define _IN_

typedef uint8_t u8;
typedef int8_t i8;

typedef uint16_t u16;
typedef int16_t i16;

typedef uint32_t u32;
typedef int32_t i32;

typedef uint64_t u64;
typedef int64_t i64;



typedef float f32;
typedef double f64;
#ifndef TRUE
#define TRUE (1)
#endif
#ifndef FALSE
#define FALSE (0)
#endif
#ifndef NULL
#define NULL ((void*)0)
#endif

typedef uintptr_t uptr;
typedef intptr_t iptr;
typedef size_t usize;
typedef size_t isize;





#define BBCALLOC(amount, size) calloc(amount, size)
#define BBMALLOC(amount) malloc(amount)
#define BBFREE(address) free(address)

#define DEBUG_FAIL(message, ...) printf("[FAIL] (%s:%d): " message, __FILE__, __LINE__, ##__VA_ARGS__)
#define DEBUG_PASS(message, ...) printf("[PASS] (%s:%d): " message, __FILE__, __LINE__, ##__VA_ARGS__)
#define DEBUG_WARNING(message, ...) printf("[WARNING] (%s:%d): " message, __FILE__, __LINE__, ##__VA_ARGS__)
#define DEBUG_INFO(message, ...) printf("[INFO] (%s:%d): " message, __FILE__, __LINE__, ##__VA_ARGS__)

#define ARR_LEN(x) (sizeof(x) / sizeof(x[0]))

typedef enum _SCStatus {
    SCSTATUS_SUCCESS,
    SCSTATUS_FAILED,
    SCSTATUS_WOULD_BLOCK,
    SCSTATUS_OUT_OF_MEMORY,
    SCSTATUS_COULDNT_CREATE_SOCKET,
    SCSTATUS_IP_CONV_FAILED,
    SCSTATUS_CONNECTION_FAILED,
    SCSTATUS_FAILED_TO_READ,
    SCSTATUS_CANT_CREATE_BYTEBUF,
    SCSTATUS_CANT_DECOMPRESS_PACKET,
    SCSTATUS_NOT_IMPLEMENTED,
    SCSTATUS_CANT_SEND,
    SCSTATUS_POSITION_OVERFLOW,
    SCSTATUS_CONNECTION_ENDED,
    SCSTATUS_COULDNT_CHECK,
    SCSTATUS_NO_EVENT_AVALIABLE,
    SCSTATUS_CANT_WRITE_INTO_BYTEBUF,
    SCSTATUS_BUFFER_OVERFLOW,
    SCSTATUS_CANT_START_WINDOWING_PLATFORM,
    SCSTATUS_CANT_CREATE_WINDOW,
    SCSTATUS_CANT_CREATE_GRAPHICS_CONTEXT,
    SCSTATUS_CANT_SETUP_GRAPHICS_API,
    SCSTATUS_CANT_SETUP_WSA,
    SCSTATUS_INVALID_PARAMETER,
    SCSTATUS_SHOULD_CLOSE,
    SCSTATUS_NOT_INITIALIZED,
    SCSTATUS_ALREADY_INITIALIZED
} SCStatus;

typedef enum _WindowAPI {
    WINAPI_RGFW,
    WINAPI_SDL3,
    WINAPI_GLFW,
    WINAPI_WIN32,
    WINAPI_X11
} WindowAPI;

typedef enum _GraphicsAPI {
    GAPI_OPENGL,
    GAPI_VULKAN,
    GAPI_DX11,
    GAPI_NONE
} GraphicsAPI;

typedef struct _SculkColor {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} SculkColor;


#define RGBA(r, g, b, a) ((SculkColor){r, g, b, a})


SCStatus SculkCreateWindow(_IN_ const char* title, _IN_ i32 width, _IN_ i32 height);
SCStatus SculkShouldClose();
SCStatus SculkGetEvents();
SCStatus SculkSwapBuffers();
SCStatus SculkCloseWindow();

GraphicsAPI SculkReturnGraphicsAPI();
SCStatus SculkCreateRenderer(_IN_ void* initialData);
SCStatus SculkClearColor(_IN_ SculkColor color);
SCStatus SculkBeginDrawing();
SCStatus SculkEndDrawing();
SCStatus SculkTestTriangle();
// do not call this
SCStatus SculkDestroyRenderer();










#endif
