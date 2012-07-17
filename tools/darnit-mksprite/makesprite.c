#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "sprite.h"


int main(int argc, char **argv) {
	SPRITE_ENTRY se;
	FILE *in, *out;
	unsigned int i, j;
	char c, buf[512];

	if (argc < 3) {
		fprintf(stderr, "Usage: %s <input> <output>\n", argv[0]);
		return -1;
	}
	
	if ((in = fopen(argv[1], "r")) == NULL) {
		fprintf(stderr, "Unable to open %s\n", argv[1]);
		return -1;
	}

	if ((out = fopen(argv[2], "w+")) == NULL) {
		fprintf(stderr, "Unable to open %s\n", argv[5]);
		return -1;
	}

	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			se.spr[i].tile[j].time = 50;
			se.spr[i].tile[j].tile = 0;
		}
		se.spr[i].tiles = 0;
	}

	fscanf(in, "%s %i %i\n", se.tilesheet, &se.wsq, &se.hsq);
	
	se.header = 0x00FF10EF;
	se.dir = 0;
	se.frame = 0;
	se.time = 0;
	se.tleft = 0;
	se.animate = 0;
	se.used = 1;

	j = i = 0;

	while (!feof(in)) {
		c = fgetc(in);
		switch (c) {
			case 'D':
				fgets(buf, 512, in);
				j = 0;
				break;
			case 'T':
				fscanf(in, "%i %i\n", &se.spr[i].tile[j].time, &se.spr[i].tile[j].tile);
				j++;
				break;
			case 'E':
				se.spr[i].tiles = j;
				fgets(buf, 512, in);
				j = 0;
				i++;
				break;
			case '\n':
				break;
			default:
				fgets(buf, 512, in);
				break;
		}
	}

	fwrite(&se, sizeof(SPRITE_ENTRY), 1, out);

	return 0;
}