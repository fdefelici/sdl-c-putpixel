#ifndef GFX_HEADER
#define GFX_HEADER

#include <SDL.h>

typedef struct {
	float deltaTime;
    float fps;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *surface;
} gfx_context_t;

typedef struct {
	unsigned char r;
    unsigned char g;
    unsigned char b;
} gfx_color_t;

void gfx_init(gfx_context_t *, int, int);
void gfx_destroy(gfx_context_t *);
void gfx_update(gfx_context_t *);
/* void gfx_clear(gfx_context_t *); */
void gfx_putpixel(gfx_context_t *context, int x, int y, gfx_color_t color);

#endif