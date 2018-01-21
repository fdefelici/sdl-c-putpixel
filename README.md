"Put Pixel" implementation using SDL library and C

NOTE: Instead of write pixels directly on SDL Renderer, an intermediate Surface has been used and in the end copied in the renderer.

''API''
* gfx_init: initialize SDL context and window
* gfx_destroy: clear SDL context and free memory
* gfx_putpixel: draw a pixel (on a surface) given position and color 
* gfx_update: blit to the screen

''PROJECT ORGANIZATION''
* src/  : contains gfx api
* test/ : contain a simple program drawing pixels