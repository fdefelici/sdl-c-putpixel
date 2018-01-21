#include <gfx.h>
#define SDL_MAIN_HANDLED

void gfx_init(gfx_context_t *ctx, int winWidth, int winHeight) {
    SDL_Init(SDL_INIT_VIDEO);
    ctx->window = SDL_CreateWindow("A Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, winWidth, winHeight, 0);
    if (!ctx->window) { fprintf("Error creating window\n"); gfx_destroy(ctx); return; }
    ctx->renderer = SDL_CreateRenderer(ctx->window, -1, SDL_RENDERER_ACCELERATED);
    if (!ctx->renderer) { fprintf("Error creating renderer\n"); gfx_destroy(ctx); return; }
    ctx->surface = SDL_CreateRGBSurface(0, winWidth, winHeight,32,0,0,0,0);     //Per non scrivere direttamente dentro al renderer
    if (!ctx->surface) { fprintf("Error creating surface\n"); ; gfx_destroy(ctx); return; }
}

void gfx_destroy(gfx_context_t *ctx) {
    if (ctx->surface) SDL_FreeSurface(ctx->surface);
    if (ctx->renderer) SDL_DestroyRenderer(ctx->renderer);
    if (ctx->window) SDL_DestroyWindow(ctx->window);
    SDL_Quit();
}

/* Al momento non serve.
void gfx_clear(gfx_context_t *ctx) {
    SDL_RenderClear(ctx->renderer);
    SDL_FillRect(ctx->surface, NULL, 0x000000); //BLACK COLOR as 32 int
}
*/

void gfx_putpixel(gfx_context_t *ctx, int x, int y, gfx_color_t color) {
    if (x < 0 && x >= ctx->surface->w) return;
    if (y < 0 && y >= ctx->surface->h) return;
    
    //Pixels Color Matrix
    unsigned char* pixels = (unsigned char*)ctx->surface->pixels;
    int width = ctx->surface->w;
    pixels[4 * (y * width + x) + 0] = color.b;  //0 = BLUE
    pixels[4 * (y * width + x) + 1] = color.g;  //1 = GREEN
    pixels[4 * (y * width + x) + 2] = color.r;  //2 = RED
    pixels[4 * (y * width + x) + 3] = 1;        //3 = ALPHA
}

void gfx_update(gfx_context_t *ctx) {
    SDL_Rect dstRect;
    dstRect.x = 0;
    dstRect.y = 0;
    dstRect.w = ctx->surface->w;
    dstRect.h = ctx->surface->h;

    SDL_Texture *text = SDL_CreateTextureFromSurface(ctx->renderer, ctx->surface);
    SDL_RenderCopy(ctx->renderer, text, NULL, &dstRect);    
    SDL_DestroyTexture(text);

    SDL_RenderPresent(ctx->renderer);
    
    //Scrivendo sulla texture non ho bisogno di fare il clear del renderer.
    SDL_FillRect(ctx->surface, NULL, 0x000000); //BLACK COLOR as 32 int
}

