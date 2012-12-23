#include "darnit.h"


TILEMAP_ENTRY *tilemapNew(int invs_div, void *tilesheet, unsigned int mask, int w, int h) {
	TILEMAP_ENTRY *tilemap;
	int i;

	if ((tilemap = malloc(sizeof(TILEMAP_ENTRY))) == NULL)
		return NULL;
	if ((tilemap->data = malloc(sizeof(unsigned int) * w * h)) == NULL) {
		free(tilemap);
		return NULL;
	}
	
	for (i = 0; i < w * h; i++)
		tilemap->data[i] = 0;

	#ifndef DARNIT_HEADLESS
	if ((tilemap->render = renderTilemapCreate(w, h, tilemap->data, 0, 0, invs_div, tilesheet, mask)) == NULL) {
		free(tilemap->data);
		free(tilemap);
		return NULL;
	}
	#endif

	tilemap->w = w;
	tilemap->h = h;

	return tilemap;
}


TILEMAP_ENTRY *tilemapLoad(const char *fname, int invs_div, void *tilesheet, unsigned int mask) {
	IMGLOAD_DATA data;
	TILEMAP_ENTRY *tilemap;
	int i;
	unsigned int tmp;

	if ((tilemap = malloc(sizeof(TILEMAP_ENTRY))) == NULL)
		return NULL;

	data = imgloadLoad(fname);
	tilemap->w = data.w;
	tilemap->h = data.h;
	tilemap->data = data.img_data;

	if (tilemap->data == NULL) {
		free(tilemap);
		return NULL;
	}

	for (i = 0; i < tilemap->w * tilemap->h; i++) {
		tmp = (tilemap->data[i] & 0xF0) >> 4;
		tmp |= (tilemap->data[i] & 0xF000) >> 8;
		tmp |= (tilemap->data[i] & 0xF00000) >> 12;
		tmp |= (tilemap->data[i] & 0xF0000000) >> 16;
		tilemap->data[i] = tmp;
	}

	#ifndef DARNIT_HEADLESS
	tilemap->render = renderTilemapCreate(tilemap->w, tilemap->h, tilemap->data, 0, 0, invs_div, tilesheet, mask);
	#endif

	return tilemap;
}



void *tilemapFree(TILEMAP_ENTRY *tm) {
	if (tm == NULL) return NULL;
	free(tm->data);

	#ifndef DARNIT_HEADLESS
	renderTilemapFree(tm->render);
	#endif

	free(tm);

	return NULL;
}
