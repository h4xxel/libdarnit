#ifndef		__VIDEO_OGL_H__
#define		__VIDEO_OGL_H__



/* DO NOT INCLUDE THIS FILE MANUALLY, THAT IS HANDLED BY render.h */

#define COLOURDEPTH_RED_SIZE  		5
#define COLOURDEPTH_GREEN_SIZE 		6
#define COLOURDEPTH_BLUE_SIZE 		5
#define COLOURDEPTH_DEPTH_SIZE		16



#include	<SDL/SDL.h>
#include	<SDL/SDL_opengl.h>


typedef struct {
	SDL_Surface			*screen;
	FADE_STRUCT			fade;
	float				swgran;
	float				shgran;
	unsigned int			w;
	unsigned int			h;
	unsigned int			camx;
	unsigned int			camy;
	unsigned int			time;
	int				offset_x;
	int				offset_y;
	float				tint_r;
	float				tint_g;
	float				tint_b;
	float				tint_a;
	int				blend;
} VIDEO;

unsigned int videoAddTextureRGBA4(void *data, unsigned int w, unsigned int h);
unsigned int videoAddTextureRGB5A1(void *data, unsigned int w, unsigned int h);
unsigned int videoAddTextureA8(void *data, unsigned int w, unsigned int h);
int videoInit(const char *wtitle, int screenw, int screenh, int fullscreen);
int videoLoop();
void videoSwapBuffers();
void videoClearScreen();
unsigned int videoAddTexture(void *data, unsigned int w, unsigned int h);
void videoRemoveTexture(unsigned int texture);
void videoDestroy();

#endif
