/* $Id$ */

#ifndef SPRITECACHE_H
#define SPRITECACHE_H

typedef struct Sprite {
	byte info;
	byte height;
	uint16 width;
	int16 x_offs;
	int16 y_offs;
	byte data[VARARRAY_SIZE];
} Sprite;

const void *GetRawSprite(SpriteID sprite);

static inline const Sprite *GetSprite(SpriteID sprite)
{
	return GetRawSprite(sprite);
}

static inline const byte *GetNonSprite(SpriteID sprite)
{
	return GetRawSprite(sprite);
}

void GfxInitSpriteMem(void);
void IncreaseSpriteLRU(void);

bool LoadNextSprite(int load_index, byte file_index);
void DupSprite(SpriteID old, SpriteID new);
void SkipSprites(uint count);

#endif
