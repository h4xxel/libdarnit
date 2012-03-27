#ifndef __INPUT_H__
#define	__INPUT_H__


#define		KEY_LEFT		0x1
#define		KEY_RIGHT		0x2
#define		KEY_UP			0x4
#define		KEY_DOWN		0x8
#define		KEY_X			0x10
#define		KEY_Y			0x20
#define		KEY_A			0x40
#define		KEY_B			0x80
#define		KEY_START		0x100
#define		KEY_SELECT		0x200
#define		KEY_L			0x400
#define		KEY_R			0x800


#define		BUTTON_ACCEPT		KEY_B
#define		BUTTON_CANCEL		KEY_A


typedef struct {
	SDL_Event			event;
	unsigned int			key;
	unsigned int			keypending;
	unsigned int			upper;
	unsigned int			lastkey;
} INPUT;


void inputPoll(void *handle);
void inputInit(void *handle);
unsigned int inputASCIIPop(void *handle);

#endif
