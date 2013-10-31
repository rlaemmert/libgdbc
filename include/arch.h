/*! \file */
#ifndef ARCH_H
#define ARCH_H

/*!
 * This struct defines a generic
 * register view
 */
typedef struct registers_t {
	char name[32]; /*! The Name of the current register */
	uint64_t offset; /*! Offset in the data block */
	uint64_t size;	/*! Size of the register */
	uint64_t value; /*! Saves the value of the register */
} registers_t;


static registers_t x86_64[] = {
	{"rax",		0,		8,	0},
	{"rbx",		8,		8,	0},
	{"rcx",		16,		8,	0},
	{"rdx",		24,		8,	0},
	{"rsi",		32,		8,	0},
	{"rdi",		40,		8,	0},
	{"rbp",		48,		8,	0},
	{"rsp",		56,		8,	0},
	{"r8",		64,		8,	0},
	{"r9",		72,		8,	0},
	{"r10",		80,		8,	0},
	{"r11",		88,		8,	0},
	{"r12",		96,		8,	0},
	{"r13",		104,	8,	0},
	{"r14",		112,	8,	0},
	{"r15",		120,	8,	0},
	{"rip",		128,	8,	0},
	{"eflags",136,	4,	0},
	{"cs",		140,	4,	0},
	{"ss",		144,	4,	0},
	{"ds",		148,	4,	0},
	{"es",		152,	4,	0},
	{"fs",		156,	4,	0},
	{"gs",		160,	4,	0},
	{"st0",		164,	10,	0},
	{"st1",		174,	10,	0},
	{"st2",		184,	10,	0},
	{"st3",		194,	10,	0},
	{"st4",		204,	10,	0},
	{"st5",		214,	10,	0},
	{"st6",		224,	10,	0},
	{"st7",		234,	10,	0},
	{"fctrl",	244,	4,	0},
	{"fstat",	248,	4,	0},
	{"ftag",	252,	4,	0},
	{"fiseg",	256,	4,	0},
	{"fioff",	260,	4,	0},
	{"foseg",	264,	4,	0},
	{"fooff",	268,	4,	0},
	{"fop",		272,	4,	0},
	{"xmm0",	276,	16,	0},
	{"xmm1",	292,	16,	0},
	{"xmm2",	308,	16,	0},
	{"xmm3",	324,	16,	0},
	{"xmm4",	340,	16,	0},
	{"xmm5",	356,	16,	0},
	{"xmm6",	372,	16,	0},
	{"xmm7",	388,	16,	0},
	{"xmm8",	404,	16,	0},
	{"xmm9",	420,	16,	0},
	{"xmm10",	436,	16,	0},
	{"xmm11",	452,	16,	0},
	{"xmm12",	468,	16,	0},
	{"xmm13",	484,	16,	0},
	{"xmm14",	500,	16,	0},
	{"xmm15",	516,	16,	0},
	{"mxcsr",	532,	4,	0},
	{"", 0, 0, 0}
};


static registers_t x86_32[] = {
	{"eax",	0,	4,	0},
	{"ecx",	4,	4,	0},
	{"edx",	8,	4,	0},
	{"ebx",	12,	4,	0},
	{"esp",	16,	4,	0},
	{"ebp",	20,	4,	0},
	{"esi",	24,	4,	0},
	{"edi",	28,	4,	0},
	{"eip",	32,	4,	0},
	{"eflags",	36,	4,	0},
	{"cs",	40,	4,	0},
	{"ss",	44,	4,	0},
	{"ds",	48,	4,	0},
	{"es",	52,	4,	0},
	{"fs",	56,	4,	0},
	{"gs",	60,	4,	0},
	{"st0",	64,	10,	0},
	{"st1",	74,	10,	0},
	{"st2",	84,	10,	0},
	{"st3",	94,	10,	0},
	{"st4",	104,	10,	0},
	{"st5",	114,	10,	0},
	{"st6",	124,	10,	0},
	{"st7",	134,	10,	0},
	{"fctrl",	144,	4,	0},
	{"fstat",	148,	4,	0},
	{"ftag",	152,	4,	0},
	{"fiseg",	156,	4,	0},
	{"fioff",	160,	4,	0},
	{"foseg",	164,	4,	0},
	{"fooff",	168,	4,	0},
	{"fop",	172,	4,	0},
	{"xmm0",	176,	16,	0},
	{"xmm1",	192,	16,	0},
	{"xmm2",	208,	16,	0},
	{"xmm3",	224,	16,	0},
	{"xmm4",	240,	16,	0},
	{"xmm5",	256,	16,	0},
	{"xmm6",	272,	16,	0},
	{"xmm7",	288,	16,	0},
	{"mxcsr",	304,	4,	0},
	{"",	0,	0,	0}
};


#endif
