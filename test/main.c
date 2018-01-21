#include <gfx.h>

int main(int argc, char *argv[]) {

    gfx_context_t ctx;
    gfx_init(&ctx, 300, 300);

    while (1) {
        SDL_Event e;
        if (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                break;
            }
        }

        gfx_color_t red = {255, 0, 0};
        gfx_putpixel(&ctx, 10, 10, red);
        gfx_putpixel(&ctx, 11, 10, red);
        gfx_putpixel(&ctx, 12, 10, red);
        gfx_putpixel(&ctx, 13, 10, red);
        gfx_putpixel(&ctx, 10, 11, red);
        gfx_putpixel(&ctx, 11, 11, red);
        gfx_putpixel(&ctx, 12, 11, red);
        gfx_putpixel(&ctx, 13, 11, red);
        
        gfx_color_t green = {0, 255, 255};
        gfx_putpixel(&ctx, 10, 20, green);
        gfx_putpixel(&ctx, 11, 20, green);
        gfx_putpixel(&ctx, 12, 20, green);
        gfx_putpixel(&ctx, 13, 20, green);
        gfx_putpixel(&ctx, 10, 21, green);
        gfx_putpixel(&ctx, 11, 21, green);
        gfx_putpixel(&ctx, 12, 21, green);
        gfx_putpixel(&ctx, 13, 21, green);
        
        gfx_update(&ctx);

    }

    gfx_destroy(&ctx);

    return 0;
}
