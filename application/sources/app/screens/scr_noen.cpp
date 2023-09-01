#include "scr_noen.h"

#define NUM_SNOW		(15)
#define LOGO_HEIGHT		(4)
#define LOGO_WIDTH		(4)

static const unsigned char PROGMEM logo_merry_chrismast[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x00,
	0x00, 0xe0, 0x19, 0x9e, 0x79, 0xf3, 0x61, 0xec, 0xff, 0x3c, 0xf7, 0xd9, 0x8e, 0x3c, 0x0e, 0x00,
	0x00, 0x60, 0x19, 0x9e, 0x79, 0xf3, 0x63, 0xec, 0xff, 0x3d, 0xf7, 0xdd, 0x9f, 0x7c, 0x06, 0x00,
	0x00, 0x00, 0x1f, 0x98, 0x79, 0xb3, 0x63, 0x8c, 0xdb, 0x19, 0xc1, 0x9f, 0x9f, 0x70, 0x00, 0x00,
	0x00, 0x00, 0x1f, 0x9e, 0x79, 0xf3, 0x63, 0x8f, 0xdf, 0x19, 0xf1, 0x9f, 0x9b, 0x7c, 0x00, 0x00,
	0x00, 0x60, 0x1f, 0x9e, 0x7d, 0xfb, 0xc3, 0x8f, 0xdf, 0x98, 0xf1, 0x9f, 0x9f, 0x3c, 0x06, 0x00,
	0x00, 0xa0, 0x19, 0x98, 0x6d, 0x99, 0xc3, 0x8c, 0xd9, 0x98, 0x31, 0x99, 0x9f, 0x0c, 0x0a, 0x00,
	0x01, 0xb0, 0x19, 0x9e, 0x6d, 0x99, 0x83, 0xec, 0xd9, 0xbd, 0xf1, 0x99, 0x9b, 0x7c, 0x1b, 0x00,
	0x03, 0xf8, 0x19, 0x9e, 0x6d, 0x99, 0x81, 0xec, 0xd9, 0xbd, 0xf1, 0x99, 0x9b, 0x7c, 0x3f, 0x80,
	0x01, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00,
	0x01, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1b, 0x00,
	0x03, 0xe8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3e, 0x80,
	0x06, 0x6c, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x66, 0xc0,
	0x0f, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xf0,
	0x03, 0xbc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3b, 0xc0,
	0x03, 0x9c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x39, 0xc0,
	0x07, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xe0,
	0x0c, 0xe7, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xce, 0x70,
	0x3c, 0xf7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xcf, 0x78,
	0x3f, 0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0xf8,
	0x01, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x19, 0x80,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
	0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
	0x00, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	// 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x83, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x81, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x01, 0xc0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x01, 0xc0, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x03, 0xe0, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x03, 0xe0, 0x00, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x07, 0xf0, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x1f, 0xfc, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xfe, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf8, 0x3c, 0x1e, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x78, 0x0f, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x60, 0x03, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x80, 0x03, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xe0, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x0f, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0x01, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xf9, 0x7f, 0xff, 0xf7, 0xfe, 0x7f, 0xe7, 0xff, 0xff, 0xbf, 0xff, 0xff, 
    // 0xff, 0xff, 0xe1, 0xff, 0xf0, 0xff, 0xf3, 0xb3, 0xfe, 0xff, 0xe7, 0xfe, 0x1f, 0x38, 0x7f, 0xff, 
    // 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xf3, 0x33, 0xff, 0xff, 0xe7, 0xfc, 0x0f, 0x30, 0x7f, 0xff, 
    // 0xff, 0xff, 0x9e, 0x6e, 0xf9, 0xf3, 0xf2, 0x72, 0x78, 0xfc, 0xe4, 0xff, 0x8f, 0x77, 0x3f, 0xff, 
    // 0xff, 0xff, 0x9e, 0x66, 0x60, 0x61, 0xf0, 0xf0, 0x30, 0x60, 0x60, 0x7f, 0x9e, 0x73, 0x3f, 0xff, 
    // 0xff, 0xff, 0xbe, 0x66, 0x66, 0x47, 0xf0, 0xf3, 0x3e, 0x66, 0x66, 0x7f, 0x9e, 0x70, 0x3f, 0xff, 
    // 0xff, 0xff, 0x9e, 0x66, 0x6e, 0x4f, 0xf2, 0x73, 0x30, 0x67, 0x66, 0x7f, 0x3e, 0xfd, 0x3f, 0xff, 
    // 0xff, 0xff, 0x9c, 0x66, 0x66, 0x4f, 0xf2, 0x33, 0x32, 0x67, 0x66, 0x7e, 0x7c, 0xff, 0x7f, 0xff, 
    // 0xff, 0xff, 0x80, 0xe0, 0x60, 0x61, 0xf3, 0x33, 0x30, 0x67, 0x66, 0x7c, 0x0c, 0xf0, 0x7f, 0xff, 
    // 0xff, 0xff, 0xe0, 0x72, 0xf1, 0xf3, 0xfb, 0xb7, 0xb9, 0x67, 0x67, 0x7c, 0x0d, 0xf8, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    // 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

static const unsigned char PROGMEM snow_icon [] = {
	0x10, 0x54, 0x28, 0xe6, 0x38, 0x54, 0x10
};

int8_t f;
static int8_t icons[NUM_SNOW][3];

static void view_scr_noen();

view_dynamic_t dyn_view_item_merry_christmas = {
	{
		.item_type = ITEM_TYPE_DYNAMIC,
	},
	view_scr_noen
};

view_screen_t scr_noen = {
	&dyn_view_item_merry_christmas,
	ITEM_NULL,
	ITEM_NULL,

	.focus_item = 0,
};

void view_scr_noen() {
	view_render.clear();
	view_render.drawBitmap(0,0,logo_merry_chrismast, 128, 64, 1);
	for(f = 0; f < NUM_SNOW; f++) {
		view_render.drawBitmap( icons[f][XPOS],icons[f][YPOS], snow_icon, 7, 7, WHITE);
	}
	view_render.update();
}

void scr_noen_handle(ak_msg_t* msg) {
	switch (msg->sig) {
	case SCREEN_ENTRY: {
		APP_DBG_SIG("SCREEN_ENTRY\n");
		for(f = 0; f < NUM_SNOW; f++) {
			icons[f][XPOS] = random(1 - LOGO_WIDTH, view_render.width());
			icons[f][YPOS] = -LOGO_HEIGHT;
			icons[f][DELTAY] = random(1, 6);
		}

		timer_set(AC_TASK_DISPLAY_ID, \
				  AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE, \
				  AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE_INTERAL, \
				  TIMER_PERIODIC);

		BUZZER_PlayTones(tones_merryChrismast);

		timer_set(AC_TASK_DISPLAY_ID, \
				  AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SLEEP, \
				  AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SLEEP_INTERVAL, \
				  TIMER_ONE_SHOT);
	}
		break;

	case AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE: {
		for(int i = 0; i < 5; i++) {
			for(f=0; f< NUM_SNOW; f++) {
				icons[f][YPOS] += icons[f][DELTAY];
				if (icons[f][XPOS] >= view_render.width()) {
					icons[f][XPOS] = random(1 - LOGO_WIDTH, view_render.width());
					icons[f][YPOS] = -LOGO_HEIGHT;
					icons[f][DELTAY] = random(1, 6);
				}
			}
		}
	}
		break;

	case AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SLEEP: {
		APP_DBG_SIG("AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SLEEP\n");
		SCREEN_TRAN(scr_idle_handle, &scr_idle);
	}
		break;

	case AC_DISPLAY_BUTON_MODE_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTON_MODE_RELEASED\n");
		timer_remove_attr(AC_TASK_DISPLAY_ID, AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE);
		SCREEN_TRAN(scr_idle_handle, &scr_idle);
	}
		break;

	case AC_DISPLAY_BUTON_UP_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTON_UP_RELEASED\n");
		timer_remove_attr(AC_TASK_DISPLAY_ID, AC_DISPLAY_SHOW_MERRY_CHRISTMAS_SNOW_MOVING_UPDATE);
		SCREEN_TRAN(scr_idle_handle, &scr_idle);
	}
		break;

	case AC_DISPLAY_BUTON_DOWN_RELEASED: {
		APP_DBG_SIG("AC_DISPLAY_BUTON_DOWN_RELEASED\n");
		BUZZER_PlayTones(tones_merryChrismast);
	}
		break;

	default:
		break;
	}
}
