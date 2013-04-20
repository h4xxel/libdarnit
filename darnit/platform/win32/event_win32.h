/*
Copyright (c) 2013 Steven Arnow
'event_win32.h' - This file is part of libdarnit_tpw

This software is provided 'as-is', without any express or implied
warranty. In no event will the authors be held liable for any damages
arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

	1. The origin of this software must not be misrepresented; you must not
	claim that you wrote the original software. If you use this software
	in a product, an acknowledgment in the product documentation would be
	appreciated but is not required.

	2. Altered source versions must be plainly marked as such, and must not be
	misrepresented as being the original software.

	3. This notice may not be removed or altered from any source
	distribution.
*/

#ifndef __TPW_WIN32_EVENT_H__
#define	__TPW_WIN32_EVENT_H__

static unsigned short vk_translate[256] = {
	[0x00] = 0,
	[0x01] = 0,
	[0x02] = 0,
	[0x03] = 0,
	[0x04] = 0,
	[0x05] = 0,
	[0x06] = 0,
	[0x07] = 0,
	[0x08] = 8,
	[0x09] = 9,
	[0x0A] = 0,
	[0x0B] = 0,
	[0x0C] = 12,
	[0x0D] = 13,
	[0x0E] = 19,
	[0x0F] = 0,
	[0x10] = 0,
	[0x11] = 0,
	[0x12] = 0,
	[0x13] = 0,
	[0x14] = 301,
	[0x15] = 0,
	[0x16] = 0,
	[0x17] = 0,
	[0x18] = 0,
	[0x19] = 0,
	[0x1A] = 0,
	[0x1B] = 27,
	[0x1C] = 0,
	[0x1D] = 0,
	[0x1E] = 0,
	[0x1F] = 0,
	[0x20] = 32,
	[0x21] = 280,
	[0x22] = 281,
	[0x23] = 279,
	[0x24] = 278,
	[0x25] = 276,
	[0x26] = 273,
	[0x27] = 275,
	[0x28] = 274,
	[0x29] = 0,
	[0x2A] = 0,
	[0x2B] = 0,
	[0x2C] = 0,
	[0x2D] = 277,
	[0x2E] = 127,
	[0x2F] = 0,
	[0x30] = 48,
	[0x31] = 49,
	[0x32] = 50,
	[0x33] = 51,
	[0x34] = 52,
	[0x35] = 53,
	[0x36] = 54,
	[0x37] = 55,
	[0x38] = 56,
	[0x39] = 57,
	[0x3A] = 0,
	[0x3B] = 0,
	[0x3C] = 0,
	[0x3D] = 0,
	[0x3E] = 0,
	[0x3F] = 0,
	[0x40] = 0,
	[0x41] = 97,
	[0x42] = 98,
	[0x43] = 99,
	[0x44] = 100,
	[0x45] = 101,
	[0x46] = 102,
	[0x47] = 103,
	[0x48] = 104,
	[0x49] = 105,
	[0x4A] = 106,
	[0x4B] = 107,
	[0x4C] = 108,
	[0x4D] = 109,
	[0x4E] = 110,
	[0x4F] = 111,
	[0x50] = 112,
	[0x51] = 113,
	[0x52] = 114,
	[0x53] = 115,
	[0x54] = 116,
	[0x55] = 117,
	[0x56] = 118,
	[0x57] = 119,
	[0x58] = 120,
	[0x59] = 121,
	[0x5A] = 122,
	[0x5B] = 310,
	[0x5C] = 309,
	[0x5D] = 0,
	[0x5E] = 0,
	[0x5F] = 256,
	[0x60] = 257,
	[0x61] = 258,
	[0x62] = 259,
	[0x63] = 260,
	[0x64] = 261,
	[0x65] = 262,
	[0x66] = 263,
	[0x67] = 264,
	[0x68] = 265,
	[0x69] = 266,
	[0x6A] = 268,
	[0x6B] = 270,
	[0x6C] = 271,
	[0x6D] = 269,
	[0x6E] = 266,
	[0x6F] = 267,
	[0x70] = 282,
	[0x71] = 283,
	[0x72] = 284,
	[0x73] = 285,
	[0x74] = 286,
	[0x75] = 287,
	[0x76] = 288,
	[0x77] = 289,
	[0x78] = 290,
	[0x79] = 291,
	[0x7A] = 292,
	[0x7B] = 293,
	[0x7C] = 0,
	[0x7D] = 0,
	[0x7E] = 0,
	[0x7F] = 0,
	[0x80] = 0,
	[0x81] = 0,
	[0x82] = 0,
	[0x83] = 0,
	[0x84] = 0,
	[0x85] = 0,
	[0x86] = 0,
	[0x87] = 0,
	[0x88] = 0,
	[0x89] = 0,
	[0x8A] = 0,
	[0x8B] = 0,
	[0x8C] = 0,
	[0x8D] = 0,
	[0x8E] = 0,
	[0x8F] = 0,
	[0x90] = 300,
	[0x91] = 302,
	[0x92] = 0,
	[0x93] = 0,
	[0x94] = 0,
	[0x95] = 0,
	[0x96] = 0,
	[0x97] = 0,
	[0x98] = 0,
	[0x99] = 0,
	[0x9A] = 0,
	[0x9B] = 0,
	[0x9C] = 0,
	[0x9D] = 0,
	[0x9E] = 0,
	[0x9F] = 0,
	[0xA0] = 304,
	[0xA1] = 303,
	[0xA2] = 306,
	[0xA3] = 305,
	[0xA4] = 308,
	[0xA5] = 307,
	[0xA6] = 0,
	[0xA7] = 0,
	[0xA8] = 0,
	[0xA9] = 0,
	[0xAA] = 0,
	[0xAB] = 0,
	[0xAC] = 0,
	[0xAD] = 0,
	[0xAE] = 0,
	[0xAF] = 0,
	[0xB0] = 0,
	[0xB1] = 0,
	[0xB2] = 0,
	[0xB3] = 0,
	[0xB4] = 0,
	[0xB5] = 0,
	[0xB6] = 0,
	[0xB7] = 0,
	[0xB8] = 0,
	[0xB9] = 0,
	[0xBA] = 0,
	[0xBB] = 0,
	[0xBC] = 0,
	[0xBD] = 0,
	[0xBE] = 0,
	[0xBF] = 0,
	[0xC0] = 0,
	[0xC1] = 0,
	[0xC2] = 0,
	[0xC3] = 0,
	[0xC4] = 0,
	[0xC5] = 0,
	[0xC6] = 0,
	[0xC7] = 0,
	[0xC8] = 0,
	[0xC9] = 0,
	[0xCA] = 0,
	[0xCB] = 0,
	[0xCC] = 0,
	[0xCD] = 0,
	[0xCE] = 0,
	[0xCF] = 0,
	[0xD0] = 0,
	[0xD1] = 0,
	[0xD2] = 0,
	[0xD3] = 0,
	[0xD4] = 0,
	[0xD5] = 0,
	[0xD6] = 0,
	[0xD7] = 0,
	[0xD8] = 0,
	[0xD9] = 0,
	[0xDA] = 0,
	[0xDB] = 0,
	[0xDC] = 0,
	[0xDD] = 0,
	[0xDE] = 0,
	[0xDF] = 0,
	[0xE0] = 0,
	[0xE1] = 0,
	[0xE2] = 0,
	[0xE3] = 0,
	[0xE4] = 0,
	[0xE5] = 0,
	[0xE6] = 0,
	[0xE7] = 0,
	[0xE8] = 0,
	[0xE9] = 0,
	[0xEA] = 0,
	[0xEB] = 0,
	[0xEC] = 0,
	[0xED] = 0,
	[0xEE] = 0,
	[0xEF] = 0,
	[0xF0] = 0,
	[0xF1] = 0,
	[0xF2] = 0,
	[0xF3] = 0,
	[0xF4] = 0,
	[0xF5] = 0,
	[0xF6] = 0,
	[0xF7] = 0,
	[0xF8] = 0,
	[0xF9] = 0,
	[0xFA] = 0,
	[0xFB] = 0,
	[0xFC] = 0,
	[0xFD] = 0,
	[0xFE] = 0,
	[0xFF] = 0,
};


#endif

