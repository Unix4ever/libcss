/*
 * This file is part of LibCSS.
 * Licensed under the MIT License,
 *                http://www.opensource.org/licenses/mit-license.php
 * Copyright 2008 John-Mark Bell <jmb@netsurf-browser.org>
 */

#ifndef css_css__parse_propstrings_h_
#define css_css__parse_propstrings_h_

#include "utils/utils.h"

enum {
	/* Universal selector */
	UNIVERSAL,

	/* Common tokens */
	COLON, COMMA, SEMICOLON, OPEN_CURLY_BRACE, CLOSE_CURLY_BRACE,
	ZERO_VALUE,

	/* At-rules */
	CHARSET, LIBCSS_IMPORT, MEDIA, NAMESPACE, FONT_FACE, PAGE,

	/* Media types */
	AURAL, BRAILLE, EMBOSSED, HANDHELD, PRINT, PROJECTION,
	SCREEN, SPEECH, TTY, TV, ALL,

	/* Pseudo classes */
	FIRST_CHILD, LINK, VISITED, HOVER, ACTIVE, FOCUS, LANG,
	/* LEFT, RIGHT, -- already in properties */ FIRST,
	ROOT, NTH_CHILD, NTH_LAST_CHILD, NTH_OF_TYPE, NTH_LAST_OF_TYPE,
	LAST_CHILD, FIRST_OF_TYPE, LAST_OF_TYPE, ONLY_CHILD,
	ONLY_OF_TYPE, EMPTY, TARGET, ENABLED, DISABLED, CHECKED, NOT,

	/* Pseudo elements */
	FIRST_LINE, FIRST_LETTER, BEFORE, AFTER,

	/* Properties */
	FIRST_PROP,

	ALIGN_CONTENT = FIRST_PROP, ALIGN_ITEMS, ALIGN_SELF, AZIMUTH,
	BACKGROUND, BACKGROUND_ATTACHMENT, BACKGROUND_COLOR, BACKGROUND_IMAGE,
	BACKGROUND_POSITION, BACKGROUND_REPEAT, BORDER, BORDER_BOTTOM,
	BORDER_BOTTOM_COLOR, BORDER_BOTTOM_STYLE, BORDER_BOTTOM_WIDTH,
	BORDER_COLLAPSE, BORDER_COLOR, BORDER_LEFT, BORDER_LEFT_COLOR,
	BORDER_LEFT_STYLE, BORDER_LEFT_WIDTH, BORDER_RIGHT, BORDER_RIGHT_COLOR,
	BORDER_RIGHT_STYLE, BORDER_RIGHT_WIDTH, BORDER_SPACING,
	BORDER_STYLE, BORDER_TOP, BORDER_TOP_COLOR, BORDER_TOP_STYLE,
	BORDER_TOP_WIDTH, BORDER_WIDTH, BOTTOM, BOX_SIZING, BREAK_AFTER,
	BREAK_BEFORE, BREAK_INSIDE, CAPTION_SIDE, CLEAR, CLIP, COLOR, COLUMNS,
	COLUMN_COUNT, COLUMN_FILL, COLUMN_GAP, COLUMN_RULE, COLUMN_RULE_COLOR,
	COLUMN_RULE_STYLE, COLUMN_RULE_WIDTH, COLUMN_SPAN, COLUMN_WIDTH,
	CONTENT, COUNTER_INCREMENT, COUNTER_RESET, CUE, CUE_AFTER, CUE_BEFORE,
	CURSOR, DIRECTION, DISPLAY, ELEVATION, EMPTY_CELLS, FLEX, FLEX_BASIS,
	FLEX_DIRECTION, FLEX_FLOW, FLEX_GROW, FLEX_SHRINK, FLEX_WRAP,
	LIBCSS_FLOAT, FONT, FONT_FAMILY, FONT_SIZE, FONT_STYLE, FONT_VARIANT,
	FONT_WEIGHT, HEIGHT, JUSTIFY_CONTENT, LEFT, LETTER_SPACING, LINE_HEIGHT,
	LIST_STYLE, LIST_STYLE_IMAGE, LIST_STYLE_POSITION, LIST_STYLE_TYPE,
	MARGIN, MARGIN_BOTTOM, MARGIN_LEFT, MARGIN_RIGHT, MARGIN_TOP,
	MAX_HEIGHT, MAX_WIDTH, MIN_HEIGHT, MIN_WIDTH, OPACITY, ORDER, ORPHANS,
	OUTLINE, OUTLINE_COLOR, OUTLINE_STYLE, OUTLINE_WIDTH, OVERFLOW,
	OVERFLOW_X, OVERFLOW_Y, PADDING, PADDING_BOTTOM, PADDING_LEFT,
	PADDING_RIGHT, PADDING_TOP, PAGE_BREAK_AFTER, PAGE_BREAK_BEFORE,
	PAGE_BREAK_INSIDE, PAUSE, PAUSE_AFTER, PAUSE_BEFORE, PITCH_RANGE, PITCH,
	PLAY_DURING, POSITION, QUOTES, RICHNESS, RIGHT, SPEAK_HEADER,
	SPEAK_NUMERAL, SPEAK_PUNCTUATION, SPEAK, SPEECH_RATE, STRESS,
	TABLE_LAYOUT, TEXT_ALIGN, TEXT_DECORATION, TEXT_INDENT, TEXT_TRANSFORM,
	TOP, UNICODE_BIDI, VERTICAL_ALIGN, VISIBILITY, VOICE_FAMILY, VOLUME,
	WHITE_SPACE, WIDOWS, WIDTH, WORD_SPACING, WRITING_MODE, Z_INDEX,

	LAST_PROP = Z_INDEX,

	/* Other keywords */
	INHERIT, IMPORTANT, NONE, BOTH, FIXED, SCROLL, TRANSPARENT,
	NO_REPEAT, REPEAT_X, REPEAT_Y, REPEAT, HIDDEN, DOTTED, DASHED,
	SOLID, LIBCSS_DOUBLE, GROOVE, RIDGE, INSET, OUTSET, THIN, MEDIUM, THICK,
	COLLAPSE, SEPARATE, AUTO, LTR, RTL, INLINE, BLOCK, LIST_ITEM, RUN_IN,
	INLINE_BLOCK, TABLE, INLINE_TABLE, TABLE_ROW_GROUP, TABLE_HEADER_GROUP,
	TABLE_FOOTER_GROUP, TABLE_ROW, TABLE_COLUMN_GROUP, TABLE_COLUMN,
	TABLE_CELL, TABLE_CAPTION, BELOW, LEVEL, ABOVE, HIGHER, LOWER,
	SHOW, HIDE, XX_SMALL, X_SMALL, SMALL, LARGE, X_LARGE, XX_LARGE,
	LARGER, SMALLER, NORMAL, ITALIC, OBLIQUE, SMALL_CAPS, BOLD, BOLDER,
	LIGHTER, INSIDE, OUTSIDE, DISC, CIRCLE, SQUARE, DECIMAL,
	DECIMAL_LEADING_ZERO, LOWER_ROMAN, UPPER_ROMAN, LOWER_GREEK,
	LOWER_LATIN, UPPER_LATIN, ARMENIAN, GEORGIAN, LOWER_ALPHA, UPPER_ALPHA,
	INVERT, VISIBLE, ALWAYS, AVOID, X_LOW, LOW, HIGH, X_HIGH, LIBCSS_STATIC,
	RELATIVE, ABSOLUTE, ONCE, DIGITS, CONTINUOUS, CODE, SPELL_OUT, X_SLOW,
	SLOW, FAST, X_FAST, FASTER, SLOWER, CENTER, JUSTIFY, CAPITALIZE,
	UPPERCASE, LOWERCASE, EMBED, BIDI_OVERRIDE, BASELINE, SUB, SUPER,
	TEXT_TOP, MIDDLE, TEXT_BOTTOM, SILENT, X_SOFT, SOFT, LOUD, X_LOUD,
	PRE, NOWRAP, PRE_WRAP, PRE_LINE, LEFTWARDS, RIGHTWARDS, LEFT_SIDE,
	FAR_LEFT, CENTER_LEFT, CENTER_RIGHT, FAR_RIGHT, RIGHT_SIDE, BEHIND,
	RECT, OPEN_QUOTE, CLOSE_QUOTE, NO_OPEN_QUOTE, NO_CLOSE_QUOTE, ATTR,
	COUNTER, COUNTERS, CROSSHAIR, DEFAULT, POINTER, MOVE, E_RESIZE,
	NE_RESIZE, NW_RESIZE, N_RESIZE, SE_RESIZE, SW_RESIZE, S_RESIZE,
	W_RESIZE, LIBCSS_TEXT, WAIT, HELP, PROGRESS, SERIF, SANS_SERIF, CURSIVE,
	FANTASY, MONOSPACE, MALE, FEMALE, CHILD, MIX, UNDERLINE, OVERLINE,
	LINE_THROUGH, BLINK, RGB, RGBA, HSL, HSLA, LIBCSS_LEFT, LIBCSS_CENTER,
	LIBCSS_RIGHT, CURRENTCOLOR, ODD, EVEN, SRC, LOCAL, INITIAL,
	FORMAT, WOFF, TRUETYPE, OPENTYPE, EMBEDDED_OPENTYPE, SVG, COLUMN,
	AVOID_PAGE, AVOID_COLUMN, BALANCE, HORIZONTAL_TB, VERTICAL_RL,
	VERTICAL_LR, CONTENT_BOX, BORDER_BOX, STRETCH, INLINE_FLEX, FLEX_START,
	FLEX_END, SPACE_BETWEEN, SPACE_AROUND, SPACE_EVENLY, ROW, ROW_REVERSE,
	COLUMN_REVERSE, WRAP_STRING, WRAP_REVERSE, AND, OR, ONLY, INFINITE, UNICODE_RANGE,

	/* Named colours */
	FIRST_COLOUR,

	ALICEBLUE = FIRST_COLOUR, ANTIQUEWHITE, AQUA, AQUAMARINE, AZURE,
	BEIGE, BISQUE, BLACK, BLANCHEDALMOND, BLUE, BLUEVIOLET, BROWN,
	BURLYWOOD, CADETBLUE, CHARTREUSE, CHOCOLATE, CORAL, CORNFLOWERBLUE,
	CORNSILK, CRIMSON, CYAN, DARKBLUE, DARKCYAN, DARKGOLDENROD, DARKGRAY,
	DARKGREEN, DARKGREY, DARKKHAKI, DARKMAGENTA, DARKOLIVEGREEN, DARKORANGE,
	DARKORCHID, DARKRED, DARKSALMON, DARKSEAGREEN, DARKSLATEBLUE,
	DARKSLATEGRAY, DARKSLATEGREY, DARKTURQUOISE, DARKVIOLET, DEEPPINK,
	DEEPSKYBLUE, DIMGRAY, DIMGREY, DODGERBLUE, FELDSPAR, FIREBRICK,
	FLORALWHITE, FORESTGREEN, FUCHSIA, GAINSBORO, GHOSTWHITE, GOLD,
	GOLDENROD, GRAY, GREEN, GREENYELLOW, GREY, HONEYDEW, HOTPINK,
	INDIANRED, INDIGO, IVORY, KHAKI, LAVENDER, LAVENDERBLUSH, LAWNGREEN,
	LEMONCHIFFON, LIGHTBLUE, LIGHTCORAL, LIGHTCYAN, LIGHTGOLDENRODYELLOW,
	LIGHTGRAY, LIGHTGREEN, LIGHTGREY, LIGHTPINK, LIGHTSALMON, LIGHTSEAGREEN,
	LIGHTSKYBLUE, LIGHTSLATEBLUE, LIGHTSLATEGRAY, LIGHTSLATEGREY,
	LIGHTSTEELBLUE, LIGHTYELLOW, LIME, LIMEGREEN, LINEN, MAGENTA, MAROON,
	MEDIUMAQUAMARINE, MEDIUMBLUE, MEDIUMORCHID, MEDIUMPURPLE,
	MEDIUMSEAGREEN, MEDIUMSLATEBLUE, MEDIUMSPRINGGREEN, MEDIUMTURQUOISE,
	MEDIUMVIOLETRED, MIDNIGHTBLUE, MINTCREAM, MISTYROSE, MOCCASIN,
	NAVAJOWHITE, NAVY, OLDLACE, OLIVE, OLIVEDRAB, ORANGE, ORANGERED,
	ORCHID, PALEGOLDENROD, PALEGREEN, PALETURQUOISE, PALEVIOLETRED,
	PAPAYAWHIP, PEACHPUFF, PERU, PINK, PLUM, POWDERBLUE, PURPLE, RED,
	ROSYBROWN, ROYALBLUE, SADDLEBROWN, SALMON, SANDYBROWN, SEAGREEN,
	SEASHELL, SIENNA, SILVER, SKYBLUE, SLATEBLUE, SLATEGRAY, SLATEGREY,
	SNOW, SPRINGGREEN, STEELBLUE, TAN, TEAL, THISTLE, TOMATO, TURQUOISE,
	VIOLET, VIOLETRED, WHEAT, WHITE, WHITESMOKE, YELLOW, YELLOWGREEN,

	LAST_COLOUR = YELLOWGREEN,

	LAST_KNOWN
};

css_error css__propstrings_get(lwc_string ***strings);
void css__propstrings_unref(void);

#endif
