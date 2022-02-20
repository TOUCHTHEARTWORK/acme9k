/******************
 * acme9k1 config *
 ******************/

/**********
 * colors *
 **********/

/* when column is empty */
#define COLOR_EMPTY 0x222222FF

/* tag & body colors: bg, hilight, border, text, hilighted text */
#define COLOR_TAG_BG 0x000000FF
#define COLOR_TAG_HI 0x1F9b92FF
#define COLOR_TAG_BD 0x797979FF
#define COLOR_TAG_TX 0xC9C9C9FF
#define COLOR_TAG_HT 0x000000FF

#define COLOR_BODY_BG 0x000F19FF
#define COLOR_BODY_HI 0x1F9B92FF
#define COLOR_BODY_BD 0x797979FF
#define COLOR_BODY_TX 0x93A1A1FF
#define COLOR_BODY_HT 0x000000FF

/* button colors: dirty file (mod) indicator and column handles */

#define COLOR_BTN_MD 0x1F9B92FF
#define COLOR_BTN_CO 0x586E75FF

/* button 2 and 3 selection colors */

#define COLOR_B2_HI 0x797979FF
#define COLOR_B3_HI 0x002B36FF

/*********
 * fonts *
 *********/

/* can use either x fonts via fontsrv or p9p fonts */

#define PRIMARY_FONT "/mnt/font/SauceCodeProNerdFontComplete-Regular/9a/font"
#define SECONDARY_FONT "/lib/font/bit/lucm/unicode.9.font"


/********
 * misc *
 ********/

/* 0 = focus follows mouse, 1 = click to focus; -b flag will invert this */

#define CLICKFOCUS_DEFAULT 0

/* 0 = literal tabs, 1 = tabs to spaces; -i flag will invert this */

#define TABSTOSPACES_DEFAULT 0

/* 0 = no auto indent, 1 = autoindent; -a flag will invert this */

#define AUTOINDENT_DEFAULT 0
