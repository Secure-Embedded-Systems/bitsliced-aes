
#include <string.h>
#include "bs.h"
#include "../app.h"

#if (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) ||\
        defined(__amd64__) || defined(__amd32__)|| defined(__amd16__)
#define bs2le(x) (x)
#define bs2be(x) (x)
#elif (defined(__BYTE_ORDER__) && __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__) ||\
            (defined(__sparc__))
#define bs2le(x) __builtin_bswap_wordsize(x)
#define bs2be(x) __builtin_bswap_wordsize(x)
#else
#error "endianness not supported"
#endif

word_t rands[256]= 
{(word_t)0xf3ccc0ccf3cf03c0ULL, (word_t)0xcc0cccc33ccc3f30ULL, (word_t)0x330cc0f3ccc33cffULL, (word_t)0xccf0f3fcfcff33f0ULL, (word_t)0x3f3ff0c3c03033cULL, (word_t)0x300333c030ccfULL, 
(word_t)0x3f03c00fcfc3fffULL, (word_t)0xc3f3cc300cf00c3cULL, (word_t)0xfc33fffc0ff30cfULL, (word_t)0xf33f30fccc3c0ff0ULL, (word_t)0xff33c0303330c330ULL, (word_t)0x3030c3000033fc03ULL, 
(word_t)0xf333fcc30c0fcf03ULL, (word_t)0xf3333cff03fc3f03ULL, (word_t)0x3cc0cfc0cf0ff3fcULL, (word_t)0xff3f3c00f0cc00c3ULL, (word_t)0xf033c3fc03ff300fULL, (word_t)0x330c3ccff330f0f3ULL, 
(word_t)0xfc3c0fc303c3000ULL, (word_t)0xc330ffccf033ffc3ULL, (word_t)0xfcf00fcc3c3ff00fULL, (word_t)0xf0c3cf0c3cfcf0c0ULL, (word_t)0x3fccff303cf3c300ULL, (word_t)0xf0f3c3cf0f0f303fULL, 
(word_t)0x3fc30fc03330ff0cULL, (word_t)0x3300f33c0000f00fULL, (word_t)0xf0033f0f300ff33cULL, (word_t)0x3fc0cc033f0f0f0cULL, (word_t)0x3fc3c00f03f3cf30ULL, (word_t)0xf0f0fc0f3fffffc3ULL, 
(word_t)0xcf0033cff3ff303fULL, (word_t)0xc3fc30f3cf03f3ffULL, (word_t)0x30cfcc00fcccf30fULL, (word_t)0x3f0c0cc00f0cf0c0ULL, (word_t)0xff303ff03fccc3ccULL, (word_t)0x333cf0cc3f0c03f0ULL, 
(word_t)0xf3ccf0fc0f33c0cfULL, (word_t)0xc33f3c0c030ffc0fULL, (word_t)0xc0f00cfcff300fffULL, (word_t)0xccff0303f3c030ffULL, (word_t)0x3f3300c3cfccf3fULL, (word_t)0xfc0c030ff03c0f33ULL, 
(word_t)0x30c3c33c03fcfcf3ULL, (word_t)0x30330fc0300ff0ULL, (word_t)0xcfcf3fc033c0f30ULL, (word_t)0xcf0f3c33c0cc030cULL, (word_t)0xc3f00f33cff3c030ULL, (word_t)0xcfcc0fc0fcc00033ULL, 
(word_t)0x3fcf0ffcf30c0fULL, (word_t)0xf03f3ff0f3033c0cULL, (word_t)0x3f33fff0cf0c03ccULL, (word_t)0xccc3c030cffcc0cULL, (word_t)0xcc3ccc0003cccfULL, (word_t)0xf0cccc0f00f30f03ULL, 
(word_t)0xfccf3cc3fc3cf3cfULL, (word_t)0xfc0f3cf00f3f333fULL, (word_t)0xcfc000ccff0c3c0cULL, (word_t)0xf3300fff0ffc00fULL, (word_t)0xc0033cc03f0c3fccULL, (word_t)0x3fcc3003cc3cccULL, 
(word_t)0xcf033c0cc0cfff3fULL, (word_t)0xf0f00f3fcff003ccULL, (word_t)0xcf00f3ff3c3cfffcULL, (word_t)0x300f3fc03fcf033cULL, (word_t)0xc3f0c0cf0c3cf0c3ULL, (word_t)0xfc30cffffcff300cULL, 
(word_t)0x3f03f00c30c0f33ULL, (word_t)0xccfcf30f3ff0003cULL, (word_t)0xc00c33300c0fcffULL, (word_t)0xcf30ccf300ff3ff0ULL, (word_t)0x3f3f3f3f3ffc3003ULL, (word_t)0xf0f00f0ccc3fc3ULL, 
(word_t)0xfccfcf30f3330f0ULL, (word_t)0xf3c3cf333ff0ffffULL, (word_t)0xfc33f3fff3f303f0ULL, (word_t)0xf0fc3cf3cf0ff033ULL, (word_t)0xc0fcc0cfcf0ff0fcULL, (word_t)0xccff3c3f30f00cc3ULL, 
(word_t)0xcfff00c33f30f3f0ULL, (word_t)0x3f00c3f3fccff0ULL, (word_t)0x3cf3f3cff3ff303fULL, (word_t)0xc0c030cf0cff00ULL, (word_t)0xf3f3000cc030300fULL, (word_t)0xf0fcc030c3c33f3cULL, 
(word_t)0xc00030033f00c3cULL, (word_t)0xfcfcf3ff0c30303fULL, (word_t)0xf33c30000f03f3f3ULL, (word_t)0x3cff3c3ff30fc300ULL, (word_t)0xf0f30f0c0f3cf003ULL, (word_t)0x3cf3c3f300330cf3ULL, 
(word_t)0xfcfc00333ffc33ccULL, (word_t)0x3cfcfc303c33c33cULL, (word_t)0x3f3fc3c0fc0c33cULL, (word_t)0xc0ffc0cf330cf3cfULL, (word_t)0xf0c30333fcf03fc0ULL, (word_t)0xccc03f03033fcc3ULL, 
(word_t)0xc3f3c3ff0f03f03cULL, (word_t)0xf0330cf00c000cf0ULL, (word_t)0xff00fcf0f33ccc00ULL, (word_t)0xc3c3c0003f3cc33fULL, (word_t)0xf3fcfc3ccfffcc03ULL, (word_t)0xf0cffc3fc3300f0fULL, 
(word_t)0xc3c0cfcff03330cfULL, (word_t)0xf3f00f3300c0c03ULL, (word_t)0xf300c0f0fff30f0cULL, (word_t)0x3c0ff00c00cccff3ULL, (word_t)0xcccc03f0f3cf30fULL, (word_t)0xf033f33cf0c3f3cULL, 
(word_t)0xffff00cccf333f0fULL, (word_t)0x3f0f0cf3cfff3c3fULL, (word_t)0xc0fcc3cfcf33cc0ULL, (word_t)0x33f0ccc3000c00c3ULL, (word_t)0xc3cccffcc0cf03fcULL, (word_t)0x30c33c33c0c3f00ULL, 
(word_t)0xc3cc00cc00030cccULL, (word_t)0x3c0f33cf0c00f00ULL, (word_t)0xc00f3003030fcc0ULL, (word_t)0xf030c0f0f330f3cfULL, (word_t)0xcc00c0f3cc30000ULL, (word_t)0xc0f3ccc00cc0c3cULL, 
(word_t)0xfff03cff3300003fULL, (word_t)0xcfcccc0030fcf03cULL, (word_t)0x3f0c33ff33f3ffcULL, (word_t)0x3ffffffcf3f0cf0cULL, (word_t)0xf333003003c30f3cULL, (word_t)0xfffcc00fc303cf30ULL, 
(word_t)0xc0cf0c00c000fc0cULL, (word_t)0x3cfffcff3c30c3ffULL, (word_t)0x3ff3c00300030c00ULL, (word_t)0x30ffff0f0ccfff3cULL, (word_t)0x33c03cf3c003f033ULL, (word_t)0x33c3fc3003303c03ULL, 
(word_t)0x3cff0f0c33fcfc30ULL, (word_t)0x3330333cf0c0ccf0ULL, (word_t)0xcffc0c3f0ffffc03ULL, (word_t)0x3003c3cc0303cccULL, (word_t)0x3fffccccf3033f00ULL, (word_t)0xc3c033030fcfccf0ULL, 
(word_t)0xc3ff30fff3f3c3ULL, (word_t)0x33c3f0f3fcf030f3ULL, (word_t)0x3c0c3fffcf3033ULL, (word_t)0xf0f3ffc33ccc0fcfULL, (word_t)0xcfcc3fc003cfccc3ULL, (word_t)0xc3cfcfff0fcc003cULL, 
(word_t)0xcc0cc0cccc3f330fULL, (word_t)0x3fc30cf0ffcfcc33ULL, (word_t)0x3f0c0fcf300fcc33ULL, (word_t)0xcc00c3ff0330ffcfULL, (word_t)0x303ff333ff33f0ccULL, (word_t)0xc30f3000c0cf3303ULL, 
(word_t)0x33f3330fcc3fc0f3ULL, (word_t)0x300f3fcc3ccff0f0ULL, (word_t)0xf33f0cc00fccc030ULL, (word_t)0xcf33c0f0f0ff00cULL, (word_t)0xf0f3c0fcf03c33fcULL, (word_t)0xcc3c030c0c000ULL, 
(word_t)0xc3ffcc333f3f0f00ULL, (word_t)0xffff33ffc00f3cf3ULL, (word_t)0xf0f00f0003ff0c00ULL, (word_t)0xc3fc3000c0ff30ccULL, (word_t)0xff03c0f033c00c03ULL, (word_t)0xc3fc00ff3cfccccULL, 
(word_t)0x3c30cc00cffc330cULL, (word_t)0xcf330c0cc00f3c30ULL, (word_t)0xcf0f03f0c3c003f0ULL, (word_t)0xc003f00f3cf00033ULL, (word_t)0x3c0ffc0fff030c33ULL, (word_t)0xcc0c0ccc03f3fULL, 
(word_t)0xf3cffcc0c0ffc0ccULL, (word_t)0xf03c0f0ffff30c03ULL, (word_t)0xc3c0fffc30ff0ffULL, (word_t)0xf0f0f3cc3f330fccULL, (word_t)0xc3c0c00f0f33f30ULL, (word_t)0xcf0f3c33000ffULL, 
(word_t)0xc30fc300ff333c03ULL, (word_t)0xc0f333fc0c30cc3ULL, (word_t)0xc0cc0fff0330c033ULL, (word_t)0xf00f3fcf0cf0fcfULL, (word_t)0xfc03f030300f3ffULL, (word_t)0xcfc333fc00f0cfffULL, 
(word_t)0x3fcf0ff0ff30c330ULL, (word_t)0xccfc0000fcccf330ULL, (word_t)0xcf0ff3ffc03c0fccULL, (word_t)0xc3cfff33ffc3033cULL, (word_t)0xc3fc3c3cc003fc0ULL, (word_t)0xcf0ccf333c3f3cfULL, 
(word_t)0xf33cffcffc00003fULL, (word_t)0xf0ff30303f3c333ULL, (word_t)0xfcc033ccf33f3300ULL, (word_t)0xf0cfccffcffcc030ULL, (word_t)0xfccc0333f00c3fffULL, (word_t)0xc0cfc3303ff30300ULL, 
(word_t)0xcf00f3f3330f30cULL, (word_t)0x3fccc030cc3cc0f0ULL, (word_t)0xccf0c3fc0c3c33ULL, (word_t)0xc00cf00cc03cfcccULL, (word_t)0x30c000cf0c3ccfULL, (word_t)0xc3f30033ffccc33ULL, 
(word_t)0x3ff00cf0033ccc3cULL, (word_t)0x3f300cfc33f333cfULL, (word_t)0xffcfc0f30fcccc0ULL, (word_t)0xcf003303cf00ff3cULL, (word_t)0x33f3f333c3333ffULL, (word_t)0xffcf00f0fc0c03ULL, 
(word_t)0xc0c0ffcc33ff0f33ULL, (word_t)0x3c30ffc0c3ccf330ULL, (word_t)0xfc33cc30ccfc0033ULL, (word_t)0xfcc33cfccf00333fULL, (word_t)0xcc000330ff00fc00ULL, (word_t)0xccff30f03cf3f033ULL, 
(word_t)0xf03000fcc30ccc3ULL, (word_t)0xcc0cf0cc003ffccULL, (word_t)0xcc030fc0cf0c03f0ULL, (word_t)0xf030c3f0f0fc03f3ULL, (word_t)0xffc03f3cfff3f0c3ULL, (word_t)0xcccc3f3ff30330c0ULL, 
(word_t)0x30003cccccc03f0ULL, (word_t)0x33cf0303f030fc3ULL, (word_t)0xfccc0c0c30cf3cccULL, (word_t)0xcffc3ccf3f0c3c0cULL, (word_t)0xfff3c0fc03cc0c3cULL, (word_t)0xccc03ff00fcf0cfULL, 
(word_t)0xcccc3ccf0cf0fc0cULL, (word_t)0xcf00000c0fffffcULL, (word_t)0x3c00ffc030f030c0ULL, (word_t)0xccc0003f3f3f0033ULL, (word_t)0xfc3c0c000033300cULL, (word_t)0xc0300f33f3f3cccULL, 
(word_t)0xfc3c3300cfff003cULL, (word_t)0x33f33033000c300ULL, (word_t)0xff0c3fc300fc3c03ULL, (word_t)0xcf0f33330c0f3c3fULL, (word_t)0xffcff00cccc0f0f0ULL, (word_t)0x3c3fccc0c3ff3cfULL, 
(word_t)0xf3ff30fc0cf3c3f0ULL, (word_t)0xccf0c00030f0fccULL, (word_t)0xccccc0f0fcc0000ULL, (word_t)0xff030c00ccc303f3ULL, (word_t)0x3cc003030f303f30ULL, (word_t)0x3c0f3cff030ff0ffULL, 
(word_t)0xccf3ccffffcfcfccULL, (word_t)0xf0f03f3f0c3fffcULL, (word_t)0x30c0f0f33fccf0ULL, (word_t)0x3ffcfccf0c3330ccULL, (word_t)0xcf3f3cfc33330f00ULL, (word_t)0x30cc3f333c0f0ffULL, 
(word_t)0xc003fccff0cc333fULL, (word_t)0x333fc00f0ccccccfULL, (word_t)0xc3f3333cf300fULL, (word_t)0xcc0300f3f3f0c30cULL, (word_t)0xc33c0303f3003cf3ULL, (word_t)0x330003ffcfccf0cULL
}
;


uint8_t bitswap[256] = {
    0x0, 0x2, 0x1, 0x3, 0x8, 0xa, 0x9, 0xb, 0x4, 0x6, 0x5, 0x7, 0xc, 0xe, 0xd, 0xf, 
    0x20, 0x22, 0x21, 0x23, 0x28, 0x2a, 0x29, 0x2b, 0x24, 0x26, 0x25, 0x27, 0x2c, 0x2e, 0x2d, 0x2f, 
    0x10, 0x12, 0x11, 0x13, 0x18, 0x1a, 0x19, 0x1b, 0x14, 0x16, 0x15, 0x17, 0x1c, 0x1e, 0x1d, 0x1f, 
    0x30, 0x32, 0x31, 0x33, 0x38, 0x3a, 0x39, 0x3b, 0x34, 0x36, 0x35, 0x37, 0x3c, 0x3e, 0x3d, 0x3f, 
    0x80, 0x82, 0x81, 0x83, 0x88, 0x8a, 0x89, 0x8b, 0x84, 0x86, 0x85, 0x87, 0x8c, 0x8e, 0x8d, 0x8f, 
    0xa0, 0xa2, 0xa1, 0xa3, 0xa8, 0xaa, 0xa9, 0xab, 0xa4, 0xa6, 0xa5, 0xa7, 0xac, 0xae, 0xad, 0xaf, 
    0x90, 0x92, 0x91, 0x93, 0x98, 0x9a, 0x99, 0x9b, 0x94, 0x96, 0x95, 0x97, 0x9c, 0x9e, 0x9d, 0x9f, 
    0xb0, 0xb2, 0xb1, 0xb3, 0xb8, 0xba, 0xb9, 0xbb, 0xb4, 0xb6, 0xb5, 0xb7, 0xbc, 0xbe, 0xbd, 0xbf, 
    0x40, 0x42, 0x41, 0x43, 0x48, 0x4a, 0x49, 0x4b, 0x44, 0x46, 0x45, 0x47, 0x4c, 0x4e, 0x4d, 0x4f, 
    0x60, 0x62, 0x61, 0x63, 0x68, 0x6a, 0x69, 0x6b, 0x64, 0x66, 0x65, 0x67, 0x6c, 0x6e, 0x6d, 0x6f, 
    0x50, 0x52, 0x51, 0x53, 0x58, 0x5a, 0x59, 0x5b, 0x54, 0x56, 0x55, 0x57, 0x5c, 0x5e, 0x5d, 0x5f, 
    0x70, 0x72, 0x71, 0x73, 0x78, 0x7a, 0x79, 0x7b, 0x74, 0x76, 0x75, 0x77, 0x7c, 0x7e, 0x7d, 0x7f, 
    0xc0, 0xc2, 0xc1, 0xc3, 0xc8, 0xca, 0xc9, 0xcb, 0xc4, 0xc6, 0xc5, 0xc7, 0xcc, 0xce, 0xcd, 0xcf, 
    0xe0, 0xe2, 0xe1, 0xe3, 0xe8, 0xea, 0xe9, 0xeb, 0xe4, 0xe6, 0xe5, 0xe7, 0xec, 0xee, 0xed, 0xef, 
    0xd0, 0xd2, 0xd1, 0xd3, 0xd8, 0xda, 0xd9, 0xdb, 0xd4, 0xd6, 0xd5, 0xd7, 0xdc, 0xde, 0xdd, 0xdf, 
    0xf0, 0xf2, 0xf1, 0xf3, 0xf8, 0xfa, 0xf9, 0xfb, 0xf4, 0xf6, 0xf5, 0xf7, 0xfc, 0xfe, 0xfd, 0xff
};


#define bs_applymask(x,y) bs_addroundkey(x,y)

void bs_addroundkey(word_t * B, word_t * rk)
{
    int i;
    for (i = 0; i < BLOCK_SIZE; i++)
        B[i] ^= rk[i];
}

void bs_apply_sbox(word_t * input)
{
    int i;
    for(i=0; i < BLOCK_SIZE; i+=8)
    {
        bs_sbox(input+i);
    }
}

void bs_apply_sbox_rev(word_t * input)
{

    int i;
    for(i=0; i < BLOCK_SIZE; i+=8)
    {
        bs_sbox_rev(input+i);
    }
}

/*July 2011*/
/*Straight-line program for AES s box*/

/*Input is U[0], U[1],...,U[7]*/
/*Output is S[0], S[1],...,S[7]*/
// http://cs-www.cs.yale.edu/homes/peralta/CircuitStuff/CMT.html
void bs_sbox_rev(word_t U[8])
{
    word_t W[8];
    word_t
        T1,T2,T3,T4,T5,T6,T8,
        T9,T10,T13,T14,T15,T16,
        T17,T18,T19,T20,T22,T23,T24,
        T25, T26, T27;

    word_t
        M1,M2,M3,M4,M5,M6,M7,M8,
        M9,M10,M11,M12,M13,M14,M15,
        M16,M17,M18,M19,M20,M21,M22,
        M23,M24,M25,M26,M27,M28,M29,
        M30,M31,M32,M33,M34,M35,M36,
        M37,M38,M39,M40,M41,M42,M43,
        M44,M45,M46,M47,M48,M49,M50,
        M51,M52,M53,M54,M55,M56,M57,
        M58,M59,M60,M61,M62,M63;

    word_t
        P0,P1,P2,P3,P4,P5,P6,P7,P8,
        P9,P10,P11,P12,P13,P14,
        P15,P16,P17,P18,P19,P20,
        P21,P22,P23,P24,P25,P26,
        P27,P28,P29;

    word_t Y5,
        R5, R13, R17, R18, R19;


    T23 = U[7] ^ U[4];
    T22 = ~(U[6] ^ U[4]);
    T2 = ~(U[7] ^ U[6]);
    T1 = U[4] ^ U[3];
    T24 = ~(U[3] ^ U[0]);
    R5 = U[1] ^ U[0];
    T8 = ~(U[6] ^ T23);
    T19 = T22 ^ R5;
    T9 = ~(U[0] ^ T1);
    T10 = T2 ^ T24;
    T13 = T2 ^ R5;
    T3 = T1 ^ R5;
    T25 = ~(U[5] ^ T1);
    R13 = U[6] ^ U[1];
    T17 = ~(U[5] ^ T19);
    T20 = T24 ^ R13;
    T4 = U[3] ^ T8;
    R17 = ~(U[5] ^ U[2]);
    R18 = ~(U[2] ^ U[1]);
    R19 = ~(U[5] ^ U[3]);
    Y5 = U[7] ^ R17;
    T6 = T22 ^ R17;
    T16 = R13 ^ R19;
    T27 = T1 ^ R18;
    T15 = T10 ^ T27;
    T14 = T10 ^ R18;
    T26 = T3 ^ T16;
    M1 = T13 & T6;
    M2 = T23 & T8;
    M3 = T14 ^ M1;
    M4 = T19 & Y5;
    M5 = M4 ^ M1;
    M6 = T3 & T16;
    M7 = T22 & T9;
    M8 = T26 ^ M6;
    M9 = T20 & T17;
    M10 = M9 ^ M6;
    M11 = T1 & T15;
    M12 = T4 & T27;
    M13 = M12 ^ M11;
    M14 = T2 & T10;
    M15 = M14 ^ M11;
    M16 = M3 ^ M2;
    M17 = M5 ^ T24;
    M18 = M8 ^ M7;
    M19 = M10 ^ M15;
    M20 = M16 ^ M13;
    M21 = M17 ^ M15;
    M22 = M18 ^ M13;
    M23 = M19 ^ T25;
    M24 = M22 ^ M23;
    M25 = M22 & M20;
    M26 = M21 ^ M25;
    M27 = M20 ^ M21;
    M28 = M23 ^ M25;
    M29 = M28 & M27;
    M30 = M26 & M24;
    M31 = M20 & M23;
    M32 = M27 & M31;
    M33 = M27 ^ M25;
    M34 = M21 & M22;
    M35 = M24 & M34;
    M36 = M24 ^ M25;
    M37 = M21 ^ M29;
    M38 = M32 ^ M33;
    M39 = M23 ^ M30;
    M40 = M35 ^ M36;
    M41 = M38 ^ M40;
    M42 = M37 ^ M39;
    M43 = M37 ^ M38;
    M44 = M39 ^ M40;
    M45 = M42 ^ M41;
    M46 = M44 & T6;
    M47 = M40 & T8;
    M48 = M39 & Y5;
    M49 = M43 & T16;
    M50 = M38 & T9;
    M51 = M37 & T17;
    M52 = M42 & T15;
    M53 = M45 & T27;
    M54 = M41 & T10;
    M55 = M44 & T13;
    M56 = M40 & T23;
    M57 = M39 & T19;
    M58 = M43 & T3;
    M59 = M38 & T22;
    M60 = M37 & T20;
    M61 = M42 & T1;
    M62 = M45 & T4;
    M63 = M41 & T2;
    P0 = M52 ^ M61;
    P1 = M58 ^ M59;
    P2 = M54 ^ M62;
    P3 = M47 ^ M50;
    P4 = M48 ^ M56;
    P5 = M46 ^ M51;
    P6 = M49 ^ M60;
    P7 = P0 ^ P1;
    P8 = M50 ^ M53;
    P9 = M55 ^ M63;
    P10 = M57 ^ P4;
    P11 = P0 ^ P3;
    P12 = M46 ^ M48;
    P13 = M49 ^ M51;
    P14 = M49 ^ M62;
    P15 = M54 ^ M59;
    P16 = M57 ^ M61;
    P17 = M58 ^ P2;
    P18 = M63 ^ P5;
    P19 = P2 ^ P3;
    P20 = P4 ^ P6;
    P22 = P2 ^ P7;
    P23 = P7 ^ P8;
    P24 = P5 ^ P7;
    P25 = P6 ^ P10;
    P26 = P9 ^ P11;
    P27 = P10 ^ P18;
    P28 = P11 ^ P25;
    P29 = P15 ^ P20;
    U[7] = P13 ^ P22;
    U[6] = P26 ^ P29;
    U[5] = P17 ^ P28;
    U[4] = P12 ^ P22;
    U[3] = P23 ^ P27;
    U[2] = P19 ^ P24;
    U[1] = P14 ^ P23;
    U[0] = P9 ^ P16;
}

static int rand_indx = 0;

static word_t SAND(word_t p, word_t q)
{
    word_t r1 = (rands[((rand_indx++) & 0xff)]);
    word_t n1 = p & q;

    word_t qswap = bitswap[(uint8_t)q]
#if WORD_SIZE > 8
                   | ((word_t)bitswap[(uint8_t)(q>>8)] << 8)
#endif
#if WORD_SIZE > 16
                   | ((word_t)bitswap[(uint8_t)(q>>16)] << 16)
                   | ((word_t)bitswap[(uint8_t)(q>>24)] << 24)
#endif
#if WORD_SIZE > 32
                   | ((word_t)bitswap[(uint8_t)(q>>32)] << 32)
                   | ((word_t)bitswap[(uint8_t)(q>>40)] << 40)
                   | ((word_t)bitswap[(uint8_t)(q>>48)] << 48)
                   | ((word_t)bitswap[(uint8_t)(q>>56)] << 56)
#endif
    ;
    word_t n3 = p & qswap;
    word_t n4 = r1 ^ n1;
    word_t z = n3 ^ n4;

    return z;
}

void bs_sbox(word_t U[8])
{
    word_t S[8];
    word_t
        T1,T2,T3,T4,T5,T6,T7,T8,
        T9,T10,T11,T12,T13,T14,T15,T16,
        T17,T18,T19,T20,T21,T22,T23,T24,
        T25, T26, T27;


    word_t
        M1,M2,M3,M4,M5,M6,M7,M8,
        M9,M10,M11,M12,M13,M14,M15,
        M16,M17,M18,M19,M20,M21,M22,
        M23,M24,M25,M26,M27,M28,M29,
        M30,M31,M32,M33,M34,M35,M36,
        M37,M38,M39,M40,M41,M42,M43,
        M44,M45,M46,M47,M48,M49,M50,
        M51,M52,M53,M54,M55,M56,M57,
        M58,M59,M60,M61,M62,M63;

    word_t
        L0,L1,L2,L3,L4,L5,L6,L7,L8,
        L9,L10,L11,L12,L13,L14,
        L15,L16,L17,L18,L19,L20,
        L21,L22,L23,L24,L25,L26,
        L27,L28,L29;



    T1 = U[7] ^ U[4];
    T2 = U[7] ^ U[2];
    T3 = U[7] ^ U[1];
    T4 = U[4] ^ U[2];
    T5 = U[3] ^ U[1];
    T6 = T1 ^ T5;
    T7 = U[6] ^ U[5];
    T8 = U[0] ^ T6;
    T9 = U[0] ^ T7;
    T10 = T6 ^ T7;
    T11 = U[6] ^ U[2];
    T12 = U[5] ^ U[2];
    T13 = T3 ^ T4;
    T14 = T6 ^ T11;
    T15 = T5 ^ T11;
    T16 = T5 ^ T12;
    T17 = T9 ^ T16;
    T18 = U[4] ^ U[0];
    T19 = T7 ^ T18;
    T20 = T1 ^ T19;
    T21 = U[1] ^ U[0];
    T22 = T7 ^ T21;
    T23 = T2 ^ T22;
    T24 = T2 ^ T10;
    T25 = T20 ^ T17;
    T26 = T3 ^ T16;
    T27 = T1 ^ T12;

    /*M1 = T13 & T6;*/
    M1 = SAND(T13,T6);

    /*M2 = T23 & T8;*/
    M2 = SAND(T23,T8);

    M3 = T14 ^ M1;

    /*M4 = T19 & U[0];*/
    M4 = SAND(T19,U[0]);

    M5 = M4 ^ M1;

    /*M6 = T3 & T16;*/
    M6 = SAND(T3,T16);
    /*M7 = T22 & T9;*/
    M7 = SAND(T22,T9);
    
    M8 = T26 ^ M6;

    /*M9 = T20 & T17;*/
    M9 = SAND(T20,T17);

    M10 = M9 ^ M6;

    /*M11 = T1 & T15;*/
    M11 = SAND(T1,T15);
    /*M12 = T4 & T27;*/
    M12 = SAND(T4,T27);

    M13 = M12 ^ M11;

    /*M14 = T2 & T10;*/
    M14 = SAND(T2,T10);

    M15 = M14 ^ M11;
    M16 = M3 ^ M2;
    M17 = M5 ^ T24;
    M18 = M8 ^ M7;
    M19 = M10 ^ M15;
    M20 = M16 ^ M13;
    M21 = M17 ^ M15;
    M22 = M18 ^ M13;
    M23 = M19 ^ T25;
    M24 = M22 ^ M23;

    /*M25 = M22 & M20;*/
    M25 = SAND(M22,M20);
    
    M26 = M21 ^ M25;
    M27 = M20 ^ M21;
    M28 = M23 ^ M25;

    /*M29 = M28 & M27;*/
    M29 = SAND(M28,M27);
    /*M30 = M26 & M24;*/
    M30 = SAND(M26,M24);
    /*M31 = M20 & M23;*/
    M31 = SAND(M20,M23);
    /*M32 = M27 & M31;*/
    M32 = SAND(M27,M31);

    M33 = M27 ^ M25;

    /*M34 = M21 & M22;*/
    M34 = SAND(M21,M22);
    /*M35 = M24 & M34;*/
    M35 = SAND(M24,M34);

    M36 = M24 ^ M25;
    M37 = M21 ^ M29;
    M38 = M32 ^ M33;
    M39 = M23 ^ M30;
    M40 = M35 ^ M36;
    M41 = M38 ^ M40;
    M42 = M37 ^ M39;
    M43 = M37 ^ M38;
    M44 = M39 ^ M40;
    M45 = M42 ^ M41;

    /*M46 = M44 & T6;*/
    M46 = SAND(M44,T6);
    /*M47 = M40 & T8;*/
    M47 = SAND(M40,T8);
    /*M48 = M39 & U[0];*/
    M48 = SAND(M39,U[0]);
    /*M49 = M43 & T16;*/
    M49 = SAND(M43,T16);
    /*M50 = M38 & T9;*/
    M50 = SAND(M38,T9);
    /*M51 = M37 & T17;*/
    M51 = SAND(M37,T17);
    /*M52 = M42 & T15;*/
    M52 = SAND(M42,T15);
    /*M53 = M45 & T27;*/
    M53 = SAND(M45,T27);
    /*M54 = M41 & T10;*/
    M54 = SAND(M41,T10);
    /*M55 = M44 & T13;*/
    M55 = SAND(M44,T13);
    /*M56 = M40 & T23;*/
    M56 = SAND(M40,T23);
    /*M57 = M39 & T19;*/
    M57 = SAND(M39,T19);
    /*M58 = M43 & T3;*/
    M58 = SAND(M43,T3);
    /*M59 = M38 & T22;*/
    M59 = SAND(M38,T22);
    /*M60 = M37 & T20;*/
    M60 = SAND(M37,T20);
    /*M61 = M42 & T1;*/
    M61 = SAND(M42,T1);
    /*M62 = M45 & T4;*/
    M62 = SAND(M45,T4);
    /*M63 = M41 & T2;*/
    M63 = SAND(M41,T2);

    L0 = M61 ^ M62;
    L1 = M50 ^ M56;
    L2 = M46 ^ M48;
    L3 = M47 ^ M55;
    L4 = M54 ^ M58;
    L5 = M49 ^ M61;
    L6 = M62 ^ L5;
    L7 = M46 ^ L3;
    L8 = M51 ^ M59;
    L9 = M52 ^ M53;
    L10 = M53 ^ L4;
    L11 = M60 ^ L2;
    L12 = M48 ^ M51;
    L13 = M50 ^ L0;
    L14 = M52 ^ M61;
    L15 = M55 ^ L1;
    L16 = M56 ^ L0;
    L17 = M57 ^ L1;
    L18 = M58 ^ L8;
    L19 = M63 ^ L4;
    L20 = L0 ^ L1;
    L21 = L1 ^ L7;
    L22 = L3 ^ L12;
    L23 = L18 ^ L2;
    L24 = L15 ^ L9;
    L25 = L6 ^ L10;
    L26 = L7 ^ L9;
    L27 = L8 ^ L10;
    L28 = L11 ^ L14;
    L29 = L11 ^ L17;
    U[7] = L6 ^ L24;
    /*U[6] = ~(L16 ^ L26);*/
    U[6] = 0x55555555 ^ (L16 ^ L26);
    /*U[5] = ~(L19 ^ L28);*/
    U[5] = 0x55555555 ^ (L19 ^ L28);
    U[4] = L6 ^ L21;
    U[3] = L20 ^ L22;
    U[2] = L25 ^ L29;
    /*U[1] = ~(L13 ^ L27);*/
    U[1] = 0x55555555 ^ (L13 ^ L27);
    /*U[0] = ~(L6 ^ L23);*/
    U[0] = 0x55555555 ^ (L6 ^ L23);
}

void bs_transpose(word_t * blocks)
{
    word_t transpose[BLOCK_SIZE];
    memset(transpose, 0, sizeof(transpose));
    bs_transpose_dst(transpose,blocks);
    memmove(blocks,transpose,sizeof(transpose));
}


// returns the slice from end of pipeline
// dst is WORD_SIZE blocks size
// block is 128 bit block 
/*#define BS_DATA_ROUNDS2 ((BS_DATA_ROUNDS)*3-1)*/
void bs_get_slice(word_t * src, word_t * block, int BS_DATA_ROUNDS2)
{
#ifndef UNROLL_TRANSPOSE
    int i;
    for (i = 0; i < BLOCK_SIZE; i++)
    {
        word_t bit = (src[i] & (ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2);
        /*block[i] = bit >> (BS_DATA_ROUNDS-1);*/
        block[i/WORD_SIZE] ^=  (bit << (i % WORD_SIZE));
    }
#else
    block[0 /WORD_SIZE] ^= ((src[0 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (0 % WORD_SIZE);
    block[1 /WORD_SIZE] ^= ((src[1 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (1 % WORD_SIZE);
    block[2 /WORD_SIZE] ^= ((src[2 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (2 % WORD_SIZE);
    block[3 /WORD_SIZE] ^= ((src[3 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (3 % WORD_SIZE);
    block[4 /WORD_SIZE] ^= ((src[4 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (4 % WORD_SIZE);
    block[5 /WORD_SIZE] ^= ((src[5 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (5 % WORD_SIZE);
    block[6 /WORD_SIZE] ^= ((src[6 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (6 % WORD_SIZE);
    block[7 /WORD_SIZE] ^= ((src[7 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (7 % WORD_SIZE);
    block[8 /WORD_SIZE] ^= ((src[8 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (8 % WORD_SIZE);
    block[9 /WORD_SIZE] ^= ((src[9 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (9 % WORD_SIZE);
    block[10/WORD_SIZE] ^= ((src[10] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (10% WORD_SIZE);
    block[11/WORD_SIZE] ^= ((src[11] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (11% WORD_SIZE);
    block[12/WORD_SIZE] ^= ((src[12] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (12% WORD_SIZE);
    block[13/WORD_SIZE] ^= ((src[13] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (13% WORD_SIZE);
    block[14/WORD_SIZE] ^= ((src[14] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (14% WORD_SIZE);
    block[15/WORD_SIZE] ^= ((src[15] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (15% WORD_SIZE);
    block[16/WORD_SIZE] ^= ((src[16] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (16% WORD_SIZE);
    block[17/WORD_SIZE] ^= ((src[17] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (17% WORD_SIZE);
    block[18/WORD_SIZE] ^= ((src[18] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (18% WORD_SIZE);
    block[19/WORD_SIZE] ^= ((src[19] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (19% WORD_SIZE);
    block[20/WORD_SIZE] ^= ((src[20] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (20% WORD_SIZE);
    block[21/WORD_SIZE] ^= ((src[21] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (21% WORD_SIZE);
    block[22/WORD_SIZE] ^= ((src[22] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (22% WORD_SIZE);
    block[23/WORD_SIZE] ^= ((src[23] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (23% WORD_SIZE);
    block[24/WORD_SIZE] ^= ((src[24] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (24% WORD_SIZE);
    block[25/WORD_SIZE] ^= ((src[25] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (25% WORD_SIZE);
    block[26/WORD_SIZE] ^= ((src[26] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (26% WORD_SIZE);
    block[27/WORD_SIZE] ^= ((src[27] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (27% WORD_SIZE);
    block[28/WORD_SIZE] ^= ((src[28] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (28% WORD_SIZE);
    block[29/WORD_SIZE] ^= ((src[29] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (29% WORD_SIZE);
    block[30/WORD_SIZE] ^= ((src[30] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (30% WORD_SIZE);
    block[31/WORD_SIZE] ^= ((src[31] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (31% WORD_SIZE);
    block[32/WORD_SIZE] ^= ((src[32] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (32% WORD_SIZE);
    block[33/WORD_SIZE] ^= ((src[33] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (33% WORD_SIZE);
    block[34/WORD_SIZE] ^= ((src[34] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (34% WORD_SIZE);
    block[35/WORD_SIZE] ^= ((src[35] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (35% WORD_SIZE);
    block[36/WORD_SIZE] ^= ((src[36] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (36% WORD_SIZE);
    block[37/WORD_SIZE] ^= ((src[37] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (37% WORD_SIZE);
    block[38/WORD_SIZE] ^= ((src[38] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (38% WORD_SIZE);
    block[39/WORD_SIZE] ^= ((src[39] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (39% WORD_SIZE);
    block[40/WORD_SIZE] ^= ((src[40] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (40% WORD_SIZE);
    block[41/WORD_SIZE] ^= ((src[41] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (41% WORD_SIZE);
    block[42/WORD_SIZE] ^= ((src[42] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (42% WORD_SIZE);
    block[43/WORD_SIZE] ^= ((src[43] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (43% WORD_SIZE);
    block[44/WORD_SIZE] ^= ((src[44] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (44% WORD_SIZE);
    block[45/WORD_SIZE] ^= ((src[45] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (45% WORD_SIZE);
    block[46/WORD_SIZE] ^= ((src[46] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (46% WORD_SIZE);
    block[47/WORD_SIZE] ^= ((src[47] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (47% WORD_SIZE);
    block[48/WORD_SIZE] ^= ((src[48] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (48% WORD_SIZE);
    block[49/WORD_SIZE] ^= ((src[49] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (49% WORD_SIZE);
    block[50/WORD_SIZE] ^= ((src[50] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (50% WORD_SIZE);
    block[51/WORD_SIZE] ^= ((src[51] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (51% WORD_SIZE);
    block[52/WORD_SIZE] ^= ((src[52] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (52% WORD_SIZE);
    block[53/WORD_SIZE] ^= ((src[53] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (53% WORD_SIZE);
    block[54/WORD_SIZE] ^= ((src[54] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (54% WORD_SIZE);
    block[55/WORD_SIZE] ^= ((src[55] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (55% WORD_SIZE);
    block[56/WORD_SIZE] ^= ((src[56] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (56% WORD_SIZE);
    block[57/WORD_SIZE] ^= ((src[57] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (57% WORD_SIZE);
    block[58/WORD_SIZE] ^= ((src[58] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (58% WORD_SIZE);
    block[59/WORD_SIZE] ^= ((src[59] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (59% WORD_SIZE);
    block[60/WORD_SIZE] ^= ((src[60] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (60% WORD_SIZE);
    block[61/WORD_SIZE] ^= ((src[61] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (61% WORD_SIZE);
    block[62/WORD_SIZE] ^= ((src[62] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (62% WORD_SIZE);
    block[63/WORD_SIZE] ^= ((src[63] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (63% WORD_SIZE);
    block[64 /WORD_SIZE] ^= ((src[64 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (64 % WORD_SIZE);
    block[65 /WORD_SIZE] ^= ((src[65 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (65 % WORD_SIZE);
    block[66 /WORD_SIZE] ^= ((src[66 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (66 % WORD_SIZE);
    block[67 /WORD_SIZE] ^= ((src[67 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (67 % WORD_SIZE);
    block[68 /WORD_SIZE] ^= ((src[68 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (68 % WORD_SIZE);
    block[69 /WORD_SIZE] ^= ((src[69 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (69 % WORD_SIZE);
    block[70 /WORD_SIZE] ^= ((src[70 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (70 % WORD_SIZE);
    block[71 /WORD_SIZE] ^= ((src[71 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (71 % WORD_SIZE);
    block[72 /WORD_SIZE] ^= ((src[72 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (72 % WORD_SIZE);
    block[73 /WORD_SIZE] ^= ((src[73 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (73 % WORD_SIZE);
    block[74 /WORD_SIZE] ^= ((src[74 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (74 % WORD_SIZE);
    block[75 /WORD_SIZE] ^= ((src[75 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (75 % WORD_SIZE);
    block[76 /WORD_SIZE] ^= ((src[76 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (76 % WORD_SIZE);
    block[77 /WORD_SIZE] ^= ((src[77 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (77 % WORD_SIZE);
    block[78 /WORD_SIZE] ^= ((src[78 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (78 % WORD_SIZE);
    block[79 /WORD_SIZE] ^= ((src[79 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (79 % WORD_SIZE);
    block[80 /WORD_SIZE] ^= ((src[80 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (80 % WORD_SIZE);
    block[81 /WORD_SIZE] ^= ((src[81 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (81 % WORD_SIZE);
    block[82 /WORD_SIZE] ^= ((src[82 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (82 % WORD_SIZE);
    block[83 /WORD_SIZE] ^= ((src[83 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (83 % WORD_SIZE);
    block[84 /WORD_SIZE] ^= ((src[84 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (84 % WORD_SIZE);
    block[85 /WORD_SIZE] ^= ((src[85 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (85 % WORD_SIZE);
    block[86 /WORD_SIZE] ^= ((src[86 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (86 % WORD_SIZE);
    block[87 /WORD_SIZE] ^= ((src[87 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (87 % WORD_SIZE);
    block[88 /WORD_SIZE] ^= ((src[88 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (88 % WORD_SIZE);
    block[89 /WORD_SIZE] ^= ((src[89 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (89 % WORD_SIZE);
    block[90 /WORD_SIZE] ^= ((src[90 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (90 % WORD_SIZE);
    block[91 /WORD_SIZE] ^= ((src[91 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (91 % WORD_SIZE);
    block[92 /WORD_SIZE] ^= ((src[92 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (92 % WORD_SIZE);
    block[93 /WORD_SIZE] ^= ((src[93 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (93 % WORD_SIZE);
    block[94 /WORD_SIZE] ^= ((src[94 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (94 % WORD_SIZE);
    block[95 /WORD_SIZE] ^= ((src[95 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (95 % WORD_SIZE);
    block[96 /WORD_SIZE] ^= ((src[96 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (96 % WORD_SIZE);
    block[97 /WORD_SIZE] ^= ((src[97 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (97 % WORD_SIZE);
    block[98 /WORD_SIZE] ^= ((src[98 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (98 % WORD_SIZE);
    block[99 /WORD_SIZE] ^= ((src[99 ] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (99 % WORD_SIZE);
    block[100/WORD_SIZE] ^= ((src[100] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (100% WORD_SIZE);
    block[101/WORD_SIZE] ^= ((src[101] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (101% WORD_SIZE);
    block[102/WORD_SIZE] ^= ((src[102] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (102% WORD_SIZE);
    block[103/WORD_SIZE] ^= ((src[103] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (103% WORD_SIZE);
    block[104/WORD_SIZE] ^= ((src[104] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (104% WORD_SIZE);
    block[105/WORD_SIZE] ^= ((src[105] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (105% WORD_SIZE);
    block[106/WORD_SIZE] ^= ((src[106] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (106% WORD_SIZE);
    block[107/WORD_SIZE] ^= ((src[107] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (107% WORD_SIZE);
    block[108/WORD_SIZE] ^= ((src[108] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (108% WORD_SIZE);
    block[109/WORD_SIZE] ^= ((src[109] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (109% WORD_SIZE);
    block[110/WORD_SIZE] ^= ((src[110] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (110% WORD_SIZE);
    block[111/WORD_SIZE] ^= ((src[111] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (111% WORD_SIZE);
    block[112/WORD_SIZE] ^= ((src[112] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (112% WORD_SIZE);
    block[113/WORD_SIZE] ^= ((src[113] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (113% WORD_SIZE);
    block[114/WORD_SIZE] ^= ((src[114] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (114% WORD_SIZE);
    block[115/WORD_SIZE] ^= ((src[115] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (115% WORD_SIZE);
    block[116/WORD_SIZE] ^= ((src[116] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (116% WORD_SIZE);
    block[117/WORD_SIZE] ^= ((src[117] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (117% WORD_SIZE);
    block[118/WORD_SIZE] ^= ((src[118] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (118% WORD_SIZE);
    block[119/WORD_SIZE] ^= ((src[119] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (119% WORD_SIZE);
    block[120/WORD_SIZE] ^= ((src[120] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (120% WORD_SIZE);
    block[121/WORD_SIZE] ^= ((src[121] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (121% WORD_SIZE);
    block[122/WORD_SIZE] ^= ((src[122] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (122% WORD_SIZE);
    block[123/WORD_SIZE] ^= ((src[123] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (123% WORD_SIZE);
    block[124/WORD_SIZE] ^= ((src[124] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (124% WORD_SIZE);
    block[125/WORD_SIZE] ^= ((src[125] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (125% WORD_SIZE);
    block[126/WORD_SIZE] ^= ((src[126] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (126% WORD_SIZE);
    block[127/WORD_SIZE] ^= ((src[127] & ( ONE << (BS_DATA_ROUNDS2))) >> (BS_DATA_ROUNDS2)) << (127% WORD_SIZE);
#endif

}

void bs_add_slice(word_t * dst, word_t * block)
{

#ifndef UNROLL_TRANSPOSE
    int i;
    if (block != NULL)
    {
        word_t cmask = ~(1<<0);
        for (i = 0; i < BLOCK_SIZE; i++)
        {
            dst[i] <<= 1;
            dst[i] &= cmask;
            int shift = i % WORD_SIZE;
            dst[i] |= ((block[i / WORD_SIZE] & (ONE << shift)) >> shift) << 0;
        }
    }
    else
    {
        for (i = 0; i < BLOCK_SIZE; i++)
        {
            dst[i] <<= 1;
        }
    }
#endif
#ifdef UNROLL_TRANSPOSE
    int i;
    word_t cmask = ~(1<<0);
    for (i = 0; i < BLOCK_SIZE; i++)
    {
        dst[i] <<= 1;
        dst[i] &= cmask;
    }

    if (block == NULL)
        return;

#define UNROLLED_ADD_SLICE(j)\
    dst[j] |= ((block[j / WORD_SIZE] & (ONE << (j % WORD_SIZE))) >> (j % WORD_SIZE)) << 0;

    UNROLLED_ADD_SLICE(0  );
    UNROLLED_ADD_SLICE(1  );
    UNROLLED_ADD_SLICE(2  );
    UNROLLED_ADD_SLICE(3  );
    UNROLLED_ADD_SLICE(4  );
    UNROLLED_ADD_SLICE(5  );
    UNROLLED_ADD_SLICE(6  );
    UNROLLED_ADD_SLICE(7  );
    UNROLLED_ADD_SLICE(8  );
    UNROLLED_ADD_SLICE(9  );
    UNROLLED_ADD_SLICE(10 );
    UNROLLED_ADD_SLICE(11 );
    UNROLLED_ADD_SLICE(12 );
    UNROLLED_ADD_SLICE(13 );
    UNROLLED_ADD_SLICE(14 );
    UNROLLED_ADD_SLICE(15 );
    UNROLLED_ADD_SLICE(16 );
    UNROLLED_ADD_SLICE(17 );
    UNROLLED_ADD_SLICE(18 );
    UNROLLED_ADD_SLICE(19 );
    UNROLLED_ADD_SLICE(20 );
    UNROLLED_ADD_SLICE(21 );
    UNROLLED_ADD_SLICE(22 );
    UNROLLED_ADD_SLICE(23 );
    UNROLLED_ADD_SLICE(24 );
    UNROLLED_ADD_SLICE(25 );
    UNROLLED_ADD_SLICE(26 );
    UNROLLED_ADD_SLICE(27 );
    UNROLLED_ADD_SLICE(28 );
    UNROLLED_ADD_SLICE(29 );
    UNROLLED_ADD_SLICE(30 );
    UNROLLED_ADD_SLICE(31 );
    UNROLLED_ADD_SLICE(32 );
    UNROLLED_ADD_SLICE(33 );
    UNROLLED_ADD_SLICE(34 );
    UNROLLED_ADD_SLICE(35 );
    UNROLLED_ADD_SLICE(36 );
    UNROLLED_ADD_SLICE(37 );
    UNROLLED_ADD_SLICE(38 );
    UNROLLED_ADD_SLICE(39 );
    UNROLLED_ADD_SLICE(40 );
    UNROLLED_ADD_SLICE(41 );
    UNROLLED_ADD_SLICE(42 );
    UNROLLED_ADD_SLICE(43 );
    UNROLLED_ADD_SLICE(44 );
    UNROLLED_ADD_SLICE(45 );
    UNROLLED_ADD_SLICE(46 );
    UNROLLED_ADD_SLICE(47 );
    UNROLLED_ADD_SLICE(48 );
    UNROLLED_ADD_SLICE(49 );
    UNROLLED_ADD_SLICE(50 );
    UNROLLED_ADD_SLICE(51 );
    UNROLLED_ADD_SLICE(52 );
    UNROLLED_ADD_SLICE(53 );
    UNROLLED_ADD_SLICE(54 );
    UNROLLED_ADD_SLICE(55 );
    UNROLLED_ADD_SLICE(56 );
    UNROLLED_ADD_SLICE(57 );
    UNROLLED_ADD_SLICE(58 );
    UNROLLED_ADD_SLICE(59 );
    UNROLLED_ADD_SLICE(60 );
    UNROLLED_ADD_SLICE(61 );
    UNROLLED_ADD_SLICE(62 );
    UNROLLED_ADD_SLICE(63 );
    UNROLLED_ADD_SLICE(64 );
    UNROLLED_ADD_SLICE(65 );
    UNROLLED_ADD_SLICE(66 );
    UNROLLED_ADD_SLICE(67 );
    UNROLLED_ADD_SLICE(68 );
    UNROLLED_ADD_SLICE(69 );
    UNROLLED_ADD_SLICE(70 );
    UNROLLED_ADD_SLICE(71 );
    UNROLLED_ADD_SLICE(72 );
    UNROLLED_ADD_SLICE(73 );
    UNROLLED_ADD_SLICE(74 );
    UNROLLED_ADD_SLICE(75 );
    UNROLLED_ADD_SLICE(76 );
    UNROLLED_ADD_SLICE(77 );
    UNROLLED_ADD_SLICE(78 );
    UNROLLED_ADD_SLICE(79 );
    UNROLLED_ADD_SLICE(80 );
    UNROLLED_ADD_SLICE(81 );
    UNROLLED_ADD_SLICE(82 );
    UNROLLED_ADD_SLICE(83 );
    UNROLLED_ADD_SLICE(84 );
    UNROLLED_ADD_SLICE(85 );
    UNROLLED_ADD_SLICE(86 );
    UNROLLED_ADD_SLICE(87 );
    UNROLLED_ADD_SLICE(88 );
    UNROLLED_ADD_SLICE(89 );
    UNROLLED_ADD_SLICE(90 );
    UNROLLED_ADD_SLICE(91 );
    UNROLLED_ADD_SLICE(92 );
    UNROLLED_ADD_SLICE(93 );
    UNROLLED_ADD_SLICE(94 );
    UNROLLED_ADD_SLICE(95 );
    UNROLLED_ADD_SLICE(96 );
    UNROLLED_ADD_SLICE(97 );
    UNROLLED_ADD_SLICE(98 );
    UNROLLED_ADD_SLICE(99 );
    UNROLLED_ADD_SLICE(100);
    UNROLLED_ADD_SLICE(101);
    UNROLLED_ADD_SLICE(102);
    UNROLLED_ADD_SLICE(103);
    UNROLLED_ADD_SLICE(104);
    UNROLLED_ADD_SLICE(105);
    UNROLLED_ADD_SLICE(106);
    UNROLLED_ADD_SLICE(107);
    UNROLLED_ADD_SLICE(108);
    UNROLLED_ADD_SLICE(109);
    UNROLLED_ADD_SLICE(110);
    UNROLLED_ADD_SLICE(111);
    UNROLLED_ADD_SLICE(112);
    UNROLLED_ADD_SLICE(113);
    UNROLLED_ADD_SLICE(114);
    UNROLLED_ADD_SLICE(115);
    UNROLLED_ADD_SLICE(116);
    UNROLLED_ADD_SLICE(117);
    UNROLLED_ADD_SLICE(118);
    UNROLLED_ADD_SLICE(119);
    UNROLLED_ADD_SLICE(120);
    UNROLLED_ADD_SLICE(121);
    UNROLLED_ADD_SLICE(122);
    UNROLLED_ADD_SLICE(123);
    UNROLLED_ADD_SLICE(124);
    UNROLLED_ADD_SLICE(125);
    UNROLLED_ADD_SLICE(126);
    UNROLLED_ADD_SLICE(127);

#endif
}

void bs_transpose_dst(word_t * transpose, word_t * blocks)
{
    int i,k;
    word_t w;
    for(k=0; k < WORD_SIZE; k++)
    {
        int bitpos = ONE << k;
        for (i=0; i < WORDS_PER_BLOCK; i++)
        {
            w = bs2le(blocks[k * WORDS_PER_BLOCK + i]);
            int offset = i << MUL_SHIFT;

#ifndef UNROLL_TRANSPOSE
            int j;
            for(j=0; j < WORD_SIZE; j++)
            {
                // TODO make const time
                transpose[offset + j] |= (w & (ONE << j)) ? bitpos : 0;
            }
#else

            transpose[(offset)+ 0 ] |= (w & (ONE << 0 )) ? (bitpos) : 0;
            transpose[(offset)+ 1 ] |= (w & (ONE << 1 )) ? (bitpos) : 0;
            transpose[(offset)+ 2 ] |= (w & (ONE << 2 )) ? (bitpos) : 0;
            transpose[(offset)+ 3 ] |= (w & (ONE << 3 )) ? (bitpos) : 0;
            transpose[(offset)+ 4 ] |= (w & (ONE << 4 )) ? (bitpos) : 0;
            transpose[(offset)+ 5 ] |= (w & (ONE << 5 )) ? (bitpos) : 0;
            transpose[(offset)+ 6 ] |= (w & (ONE << 6 )) ? (bitpos) : 0;
            transpose[(offset)+ 7 ] |= (w & (ONE << 7 )) ? (bitpos) : 0;
#if WORD_SIZE > 8
            transpose[(offset)+ 8 ] |= (w & (ONE << 8 )) ? (bitpos) : 0;
            transpose[(offset)+ 9 ] |= (w & (ONE << 9 )) ? (bitpos) : 0;
            transpose[(offset)+ 10] |= (w & (ONE << 10)) ? (bitpos) : 0;
            transpose[(offset)+ 11] |= (w & (ONE << 11)) ? (bitpos) : 0;
            transpose[(offset)+ 12] |= (w & (ONE << 12)) ? (bitpos) : 0;
            transpose[(offset)+ 13] |= (w & (ONE << 13)) ? (bitpos) : 0;
            transpose[(offset)+ 14] |= (w & (ONE << 14)) ? (bitpos) : 0;
            transpose[(offset)+ 15] |= (w & (ONE << 15)) ? (bitpos) : 0;
#endif
#if WORD_SIZE > 16
            transpose[(offset)+ 16] |= (w & (ONE << 16)) ? (bitpos) : 0;
            transpose[(offset)+ 17] |= (w & (ONE << 17)) ? (bitpos) : 0;
            transpose[(offset)+ 18] |= (w & (ONE << 18)) ? (bitpos) : 0;
            transpose[(offset)+ 19] |= (w & (ONE << 19)) ? (bitpos) : 0;
            transpose[(offset)+ 20] |= (w & (ONE << 20)) ? (bitpos) : 0;
            transpose[(offset)+ 21] |= (w & (ONE << 21)) ? (bitpos) : 0;
            transpose[(offset)+ 22] |= (w & (ONE << 22)) ? (bitpos) : 0;
            transpose[(offset)+ 23] |= (w & (ONE << 23)) ? (bitpos) : 0;
            transpose[(offset)+ 24] |= (w & (ONE << 24)) ? (bitpos) : 0;
            transpose[(offset)+ 25] |= (w & (ONE << 25)) ? (bitpos) : 0;
            transpose[(offset)+ 26] |= (w & (ONE << 26)) ? (bitpos) : 0;
            transpose[(offset)+ 27] |= (w & (ONE << 27)) ? (bitpos) : 0;
            transpose[(offset)+ 28] |= (w & (ONE << 28)) ? (bitpos) : 0;
            transpose[(offset)+ 29] |= (w & (ONE << 29)) ? (bitpos) : 0;
            transpose[(offset)+ 30] |= (w & (ONE << 30)) ? (bitpos) : 0;
            transpose[(offset)+ 31] |= (w & (ONE << 31)) ? (bitpos) : 0;
#endif
#if WORD_SIZE > 32
            transpose[(offset)+ 32] |= (w & (ONE << 32)) ? (bitpos) : 0;
            transpose[(offset)+ 33] |= (w & (ONE << 33)) ? (bitpos) : 0;
            transpose[(offset)+ 34] |= (w & (ONE << 34)) ? (bitpos) : 0;
            transpose[(offset)+ 35] |= (w & (ONE << 35)) ? (bitpos) : 0;
            transpose[(offset)+ 36] |= (w & (ONE << 36)) ? (bitpos) : 0;
            transpose[(offset)+ 37] |= (w & (ONE << 37)) ? (bitpos) : 0;
            transpose[(offset)+ 38] |= (w & (ONE << 38)) ? (bitpos) : 0;
            transpose[(offset)+ 39] |= (w & (ONE << 39)) ? (bitpos) : 0;
            transpose[(offset)+ 40] |= (w & (ONE << 40)) ? (bitpos) : 0;
            transpose[(offset)+ 41] |= (w & (ONE << 41)) ? (bitpos) : 0;
            transpose[(offset)+ 42] |= (w & (ONE << 42)) ? (bitpos) : 0;
            transpose[(offset)+ 43] |= (w & (ONE << 43)) ? (bitpos) : 0;
            transpose[(offset)+ 44] |= (w & (ONE << 44)) ? (bitpos) : 0;
            transpose[(offset)+ 45] |= (w & (ONE << 45)) ? (bitpos) : 0;
            transpose[(offset)+ 46] |= (w & (ONE << 46)) ? (bitpos) : 0;
            transpose[(offset)+ 47] |= (w & (ONE << 47)) ? (bitpos) : 0;
            transpose[(offset)+ 48] |= (w & (ONE << 48)) ? (bitpos) : 0;
            transpose[(offset)+ 49] |= (w & (ONE << 49)) ? (bitpos) : 0;
            transpose[(offset)+ 50] |= (w & (ONE << 50)) ? (bitpos) : 0;
            transpose[(offset)+ 51] |= (w & (ONE << 51)) ? (bitpos) : 0;
            transpose[(offset)+ 52] |= (w & (ONE << 52)) ? (bitpos) : 0;
            transpose[(offset)+ 53] |= (w & (ONE << 53)) ? (bitpos) : 0;
            transpose[(offset)+ 54] |= (w & (ONE << 54)) ? (bitpos) : 0;
            transpose[(offset)+ 55] |= (w & (ONE << 55)) ? (bitpos) : 0;
            transpose[(offset)+ 56] |= (w & (ONE << 56)) ? (bitpos) : 0;
            transpose[(offset)+ 57] |= (w & (ONE << 57)) ? (bitpos) : 0;
            transpose[(offset)+ 58] |= (w & (ONE << 58)) ? (bitpos) : 0;
            transpose[(offset)+ 59] |= (w & (ONE << 59)) ? (bitpos) : 0;
            transpose[(offset)+ 60] |= (w & (ONE << 60)) ? (bitpos) : 0;
            transpose[(offset)+ 61] |= (w & (ONE << 61)) ? (bitpos) : 0;
            transpose[(offset)+ 62] |= (w & (ONE << 62)) ? (bitpos) : 0;
            transpose[(offset)+ 63] |= (w & (ONE << 63)) ? (bitpos) : 0;
#endif
#endif
                // constant time:
                //transpose[(i<<MUL_SHIFT)+ j] |= (((int64_t)((w & (ONE << j)) << (WORD_SIZE-1-j)))>>(WORD_SIZE-1)) & (ONE<<k);
        }
    }
}

void bs_transpose_rev(word_t * blocks)
{
    int i,k;
    word_t w;
    word_t transpose[BLOCK_SIZE];
    memset(transpose, 0, sizeof(transpose));
    for(k=0; k < BLOCK_SIZE; k++)
    {
        w = blocks[k];
        word_t bitpos = bs2be(ONE << (k % WORD_SIZE));
        word_t offset = k / WORD_SIZE;
#ifndef UNROLL_TRANSPOSE
        int j;
        for(j=0; j < WORD_SIZE; j++)
        {
            word_t bit = (w & (ONE << j)) ? (ONE << (k % WORD_SIZE)) : 0;
            transpose[j * WORDS_PER_BLOCK + (offset)] |= bit;
        }
#else
        transpose[0  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 0 )) ? bitpos : 0;
        transpose[1  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 1 )) ? bitpos : 0;
        transpose[2  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 2 )) ? bitpos : 0;
        transpose[3  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 3 )) ? bitpos : 0;
        transpose[4  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 4 )) ? bitpos : 0;
        transpose[5  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 5 )) ? bitpos : 0;
        transpose[6  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 6 )) ? bitpos : 0;
        transpose[7  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 7 )) ? bitpos : 0;
#if WORD_SIZE > 8
        transpose[8  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 8 )) ? bitpos : 0;
        transpose[9  * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 9 )) ? bitpos : 0;
        transpose[10 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 10)) ? bitpos : 0;
        transpose[11 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 11)) ? bitpos : 0;
        transpose[12 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 12)) ? bitpos : 0;
        transpose[13 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 13)) ? bitpos : 0;
        transpose[14 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 14)) ? bitpos : 0;
        transpose[15 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 15)) ? bitpos : 0;
#endif
#if WORD_SIZE > 16
        transpose[16 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 16)) ? bitpos : 0;
        transpose[17 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 17)) ? bitpos : 0;
        transpose[18 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 18)) ? bitpos : 0;
        transpose[19 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 19)) ? bitpos : 0;
        transpose[20 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 20)) ? bitpos : 0;
        transpose[21 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 21)) ? bitpos : 0;
        transpose[22 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 22)) ? bitpos : 0;
        transpose[23 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 23)) ? bitpos : 0;
        transpose[24 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 24)) ? bitpos : 0;
        transpose[25 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 25)) ? bitpos : 0;
        transpose[26 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 26)) ? bitpos : 0;
        transpose[27 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 27)) ? bitpos : 0;
        transpose[28 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 28)) ? bitpos : 0;
        transpose[29 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 29)) ? bitpos : 0;
        transpose[30 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 30)) ? bitpos : 0;
        transpose[31 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 31)) ? bitpos : 0;
#endif
#if WORD_SIZE > 32
        transpose[32 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 32)) ? bitpos : 0;
        transpose[33 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 33)) ? bitpos : 0;
        transpose[34 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 34)) ? bitpos : 0;
        transpose[35 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 35)) ? bitpos : 0;
        transpose[36 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 36)) ? bitpos : 0;
        transpose[37 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 37)) ? bitpos : 0;
        transpose[38 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 38)) ? bitpos : 0;
        transpose[39 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 39)) ? bitpos : 0;
        transpose[40 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 40)) ? bitpos : 0;
        transpose[41 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 41)) ? bitpos : 0;
        transpose[42 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 42)) ? bitpos : 0;
        transpose[43 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 43)) ? bitpos : 0;
        transpose[44 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 44)) ? bitpos : 0;
        transpose[45 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 45)) ? bitpos : 0;
        transpose[46 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 46)) ? bitpos : 0;
        transpose[47 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 47)) ? bitpos : 0;
        transpose[48 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 48)) ? bitpos : 0;
        transpose[49 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 49)) ? bitpos : 0;
        transpose[50 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 50)) ? bitpos : 0;
        transpose[51 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 51)) ? bitpos : 0;
        transpose[52 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 52)) ? bitpos : 0;
        transpose[53 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 53)) ? bitpos : 0;
        transpose[54 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 54)) ? bitpos : 0;
        transpose[55 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 55)) ? bitpos : 0;
        transpose[56 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 56)) ? bitpos : 0;
        transpose[57 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 57)) ? bitpos : 0;
        transpose[58 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 58)) ? bitpos : 0;
        transpose[59 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 59)) ? bitpos : 0;
        transpose[60 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 60)) ? bitpos : 0;
        transpose[61 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 61)) ? bitpos : 0;
        transpose[62 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 62)) ? bitpos : 0;
        transpose[63 * WORDS_PER_BLOCK + (offset )] |= (w & (ONE << 63)) ? bitpos : 0;
#endif
#endif
    }
    memmove(blocks,transpose,sizeof(transpose));
}


#define R0          0
#define R1          8
#define R2          16
#define R3          24

#define B0          0
#define B1          32
#define B2          64
#define B3          96

#define R0_shift        (BLOCK_SIZE/4)*0
#define R1_shift        (BLOCK_SIZE/4)*1
#define R2_shift        (BLOCK_SIZE/4)*2
#define R3_shift        (BLOCK_SIZE/4)*3
#define B_MOD           (BLOCK_SIZE)


void bs_shiftrows(word_t * B)
{
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;
    word_t * Br0 = B + 0;
    word_t * Br1 = B + 32;
    word_t * Br2 = B + 64;
    word_t * Br3 = B + 96;
    uint8_t offsetr0 = 0;
    uint8_t offsetr1 = 32;
    uint8_t offsetr2 = 64;
    uint8_t offsetr3 = 96;


    int i;
    for(i=0; i<4; i++)
    {
        Bp[B0 + 0] = Br0[0];
        Bp[B0 + 1] = Br0[1];
        Bp[B0 + 2] = Br0[2];
        Bp[B0 + 3] = Br0[3];
        Bp[B0 + 4] = Br0[4];
        Bp[B0 + 5] = Br0[5];
        Bp[B0 + 6] = Br0[6];
        Bp[B0 + 7] = Br0[7];
        Bp[B1 + 0] = Br1[0];
        Bp[B1 + 1] = Br1[1];
        Bp[B1 + 2] = Br1[2];
        Bp[B1 + 3] = Br1[3];
        Bp[B1 + 4] = Br1[4];
        Bp[B1 + 5] = Br1[5];
        Bp[B1 + 6] = Br1[6];
        Bp[B1 + 7] = Br1[7];
        Bp[B2 + 0] = Br2[0];
        Bp[B2 + 1] = Br2[1];
        Bp[B2 + 2] = Br2[2];
        Bp[B2 + 3] = Br2[3];
        Bp[B2 + 4] = Br2[4];
        Bp[B2 + 5] = Br2[5];
        Bp[B2 + 6] = Br2[6];
        Bp[B2 + 7] = Br2[7];
        Bp[B3 + 0] = Br3[0];
        Bp[B3 + 1] = Br3[1];
        Bp[B3 + 2] = Br3[2];
        Bp[B3 + 3] = Br3[3];
        Bp[B3 + 4] = Br3[4];
        Bp[B3 + 5] = Br3[5];
        Bp[B3 + 6] = Br3[6];
        Bp[B3 + 7] = Br3[7];

        offsetr0 = (offsetr0 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr1 = (offsetr1 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr2 = (offsetr2 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr3 = (offsetr3 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;

        Br0 = B + offsetr0;
        Br1 = B + offsetr1;
        Br2 = B + offsetr2;
        Br3 = B + offsetr3;

        Bp += 8;
    }
    memmove(B,Bp_space,sizeof(Bp_space));
}


void bs_shiftrows_rev(word_t * B)
{
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;
    word_t * Br0 = Bp + 0;
    word_t * Br1 = Bp + 32;
    word_t * Br2 = Bp + 64;
    word_t * Br3 = Bp + 96;
    uint8_t offsetr0 = 0;
    uint8_t offsetr1 = 32;
    uint8_t offsetr2 = 64;
    uint8_t offsetr3 = 96;


    int i;
    for(i=0; i<4; i++)
    {
        Br0[0] = B[B0 + 0];
        Br0[1] = B[B0 + 1];
        Br0[2] = B[B0 + 2];
        Br0[3] = B[B0 + 3];
        Br0[4] = B[B0 + 4];
        Br0[5] = B[B0 + 5];
        Br0[6] = B[B0 + 6];
        Br0[7] = B[B0 + 7];
        Br1[0] = B[B1 + 0];
        Br1[1] = B[B1 + 1];
        Br1[2] = B[B1 + 2];
        Br1[3] = B[B1 + 3];
        Br1[4] = B[B1 + 4];
        Br1[5] = B[B1 + 5];
        Br1[6] = B[B1 + 6];
        Br1[7] = B[B1 + 7];
        Br2[0] = B[B2 + 0];
        Br2[1] = B[B2 + 1];
        Br2[2] = B[B2 + 2];
        Br2[3] = B[B2 + 3];
        Br2[4] = B[B2 + 4];
        Br2[5] = B[B2 + 5];
        Br2[6] = B[B2 + 6];
        Br2[7] = B[B2 + 7];
        Br3[0] = B[B3 + 0];
        Br3[1] = B[B3 + 1];
        Br3[2] = B[B3 + 2];
        Br3[3] = B[B3 + 3];
        Br3[4] = B[B3 + 4];
        Br3[5] = B[B3 + 5];
        Br3[6] = B[B3 + 6];
        Br3[7] = B[B3 + 7];

        offsetr0 = (offsetr0 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr1 = (offsetr1 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr2 = (offsetr2 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;
        offsetr3 = (offsetr3 + BLOCK_SIZE/16 + BLOCK_SIZE/4) & 0x7f;

        Br0 = Bp + offsetr0;
        Br1 = Bp + offsetr1;
        Br2 = Bp + offsetr2;
        Br3 = Bp + offsetr3;

        B += 8;
    }
    memmove(B - 8 * 4,Bp_space,sizeof(Bp_space));
}


#define A0  0
#define A1  8
#define A2  16
#define A3  24

// Does shift rows and mix columns in same step
void bs_shiftmix(word_t * B)
{
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;

    word_t * Br0 = B + 0;
    word_t * Br1 = B + 32;
    word_t * Br2 = B + 64;
    word_t * Br3 = B + 96;

    uint8_t offsetr0 = 0;
    uint8_t offsetr1 = 32;
    uint8_t offsetr2 = 64;
    uint8_t offsetr3 = 96;

        Br0 = B + offsetr0;
        Br1 = B + offsetr1;
        Br2 = B + offsetr2;
        Br3 = B + offsetr3;


    int i;
    for (i = 0; i < 4; i++)
    {
        // B0
        //            2*A0        2*A1              A1           A2           A3
        word_t of =Br0[R0+7]^ Br1[R1+7];
        Bp[A0+0] =                         Br1[R1+0] ^ Br2[R2+0] ^ Br3[R3+0] ^ of;
        Bp[A0+1] = Br0[R0+0] ^ Br1[R1+0] ^ Br1[R1+1] ^ Br2[R2+1] ^ Br3[R3+1] ^ of;
        Bp[A0+2] = Br0[R0+1] ^ Br1[R1+1] ^ Br1[R1+2] ^ Br2[R2+2] ^ Br3[R3+2];
        Bp[A0+3] = Br0[R0+2] ^ Br1[R1+2] ^ Br1[R1+3] ^ Br2[R2+3] ^ Br3[R3+3] ^ of;
        Bp[A0+4] = Br0[R0+3] ^ Br1[R1+3] ^ Br1[R1+4] ^ Br2[R2+4] ^ Br3[R3+4] ^ of;
        Bp[A0+5] = Br0[R0+4] ^ Br1[R1+4] ^ Br1[R1+5] ^ Br2[R2+5] ^ Br3[R3+5];
        Bp[A0+6] = Br0[R0+5] ^ Br1[R1+5] ^ Br1[R1+6] ^ Br2[R2+6] ^ Br3[R3+6];
        Bp[A0+7] = Br0[R0+6] ^ Br1[R1+6] ^ Br1[R1+7] ^ Br2[R2+7] ^ Br3[R3+7];

        //            A0            2*A1        2*A2        A2       A3
        of = Br1[R1+7] ^ Br2[R2+7];
        Bp[A1+0] = Br0[R0+0]                         ^ Br2[R2+0] ^ Br3[R3+0] ^ of;
        Bp[A1+1] = Br0[R0+1] ^ Br1[R1+0] ^ Br2[R2+0] ^ Br2[R2+1] ^ Br3[R3+1] ^ of;
        Bp[A1+2] = Br0[R0+2] ^ Br1[R1+1] ^ Br2[R2+1] ^ Br2[R2+2] ^ Br3[R3+2];
        Bp[A1+3] = Br0[R0+3] ^ Br1[R1+2] ^ Br2[R2+2] ^ Br2[R2+3] ^ Br3[R3+3] ^ of;
        Bp[A1+4] = Br0[R0+4] ^ Br1[R1+3] ^ Br2[R2+3] ^ Br2[R2+4] ^ Br3[R3+4] ^ of;
        Bp[A1+5] = Br0[R0+5] ^ Br1[R1+4] ^ Br2[R2+4] ^ Br2[R2+5] ^ Br3[R3+5];
        Bp[A1+6] = Br0[R0+6] ^ Br1[R1+5] ^ Br2[R2+5] ^ Br2[R2+6] ^ Br3[R3+6];
        Bp[A1+7] = Br0[R0+7] ^ Br1[R1+6] ^ Br2[R2+6] ^ Br2[R2+7] ^ Br3[R3+7];

        //            A0             A1      2*A2        2*A3         A3
        of = Br2[R2+7] ^ Br3[R3+7];
        Bp[A2+0] = Br0[R0+0] ^ Br1[R1+0]                         ^ Br3[R3+0] ^ of;
        Bp[A2+1] = Br0[R0+1] ^ Br1[R1+1] ^ Br2[R2+0] ^ Br3[R3+0] ^ Br3[R3+1] ^ of;
        Bp[A2+2] = Br0[R0+2] ^ Br1[R1+2] ^ Br2[R2+1] ^ Br3[R3+1] ^ Br3[R3+2];
        Bp[A2+3] = Br0[R0+3] ^ Br1[R1+3] ^ Br2[R2+2] ^ Br3[R3+2] ^ Br3[R3+3] ^ of;
        Bp[A2+4] = Br0[R0+4] ^ Br1[R1+4] ^ Br2[R2+3] ^ Br3[R3+3] ^ Br3[R3+4] ^ of;
        Bp[A2+5] = Br0[R0+5] ^ Br1[R1+5] ^ Br2[R2+4] ^ Br3[R3+4] ^ Br3[R3+5];
        Bp[A2+6] = Br0[R0+6] ^ Br1[R1+6] ^ Br2[R2+5] ^ Br3[R3+5] ^ Br3[R3+6];
        Bp[A2+7] = Br0[R0+7] ^ Br1[R1+7] ^ Br2[R2+6] ^ Br3[R3+6] ^ Br3[R3+7];

        //             A0          2*A0           A1       A2      2*A3
        of = Br0[R0+7] ^ Br3[R3+7];
        Bp[A3+0] = Br0[R0+0] ^             Br1[R1+0] ^ Br2[R2+0]             ^ of;
        Bp[A3+1] = Br0[R0+1] ^ Br0[R0+0] ^ Br1[R1+1] ^ Br2[R2+1] ^ Br3[R3+0] ^ of;
        Bp[A3+2] = Br0[R0+2] ^ Br0[R0+1] ^ Br1[R1+2] ^ Br2[R2+2] ^ Br3[R3+1];
        Bp[A3+3] = Br0[R0+3] ^ Br0[R0+2] ^ Br1[R1+3] ^ Br2[R2+3] ^ Br3[R3+2] ^ of;
        Bp[A3+4] = Br0[R0+4] ^ Br0[R0+3] ^ Br1[R1+4] ^ Br2[R2+4] ^ Br3[R3+3] ^ of;
        Bp[A3+5] = Br0[R0+5] ^ Br0[R0+4] ^ Br1[R1+5] ^ Br2[R2+5] ^ Br3[R3+4];
        Bp[A3+6] = Br0[R0+6] ^ Br0[R0+5] ^ Br1[R1+6] ^ Br2[R2+6] ^ Br3[R3+5];
        Bp[A3+7] = Br0[R0+7] ^ Br0[R0+6] ^ Br1[R1+7] ^ Br2[R2+7] ^ Br3[R3+6];

        Bp += BLOCK_SIZE/4;

        offsetr0 = (offsetr0 + BLOCK_SIZE/4) & 0x7f;
        offsetr1 = (offsetr1 + BLOCK_SIZE/4) & 0x7f;
        offsetr2 = (offsetr2 + BLOCK_SIZE/4) & 0x7f;
        offsetr3 = (offsetr3 + BLOCK_SIZE/4) & 0x7f;

        Br0 = B + offsetr0;
        Br1 = B + offsetr1;
        Br2 = B + offsetr2;
        Br3 = B + offsetr3;
    }

    memmove(B,Bp_space,sizeof(Bp_space));
}

void bs_mixcolumns(word_t * B)
{
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;

    int i;

    /*for ( i = 0; i < BLOCK_SIZE; i++)*/
    /*{*/
        /*Bp_space[i] = B[i] & (~BS_DATA_MASK);*/
    /*}*/

    // to understand this, see
    // https://en.wikipedia.org/wiki/Rijndael_mix_columns
    
    for (i = 0; i < 4; i++)
    {
    //  of = A0 ^ A1;
    //  A0 = A0 ^ (0x1b & ((signed char)of>>7));

    //// 2 * A0
    //  A0 = A0 ^ (A0 << 1)

    //// + 3 * A1
    //  A0 = A0 ^ (A1)
    //  A0 = A0 ^ (A1<<1)

    //// + A2 + A3
    //  A0 = A0 ^ (A2)
    //  A0 = A0 ^ (A3)
    //          A0.7    A1.7
    word_t of = B[A0+7] ^ B[A1+7];

    //          2*A0     2*A1          A1      A2           A3
    Bp[A0+0] = ((                    B[A1+0] ^ B[A2+0] ^ B[A3+0] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A0+0]);
    Bp[A0+1] = ((B[A0+0] ^ B[A1+0] ^ B[A1+1] ^ B[A2+1] ^ B[A3+1] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A0+1]);
    Bp[A0+2] = ((B[A0+1] ^ B[A1+1] ^ B[A1+2] ^ B[A2+2] ^ B[A3+2]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A0+2]);
    Bp[A0+3] = ((B[A0+2] ^ B[A1+2] ^ B[A1+3] ^ B[A2+3] ^ B[A3+3] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A0+3]);
    Bp[A0+4] = ((B[A0+3] ^ B[A1+3] ^ B[A1+4] ^ B[A2+4] ^ B[A3+4] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A0+4]);
    Bp[A0+5] = ((B[A0+4] ^ B[A1+4] ^ B[A1+5] ^ B[A2+5] ^ B[A3+5]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A0+5]);
    Bp[A0+6] = ((B[A0+5] ^ B[A1+5] ^ B[A1+6] ^ B[A2+6] ^ B[A3+6]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A0+6]);
    Bp[A0+7] = ((B[A0+6] ^ B[A1+6] ^ B[A1+7] ^ B[A2+7] ^ B[A3+7]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A0+7]);



    //  of = A1 ^ A2
    //  A1 = A1 ^ (0x1b & ((signed char)of>>7));

    //// A0
    //  A1 = A1 ^ (A0)

    //// + 2 * A1
    //  A1 = A1 ^ (A1 << 1)

    //// + 3 * A2
    //  A1 = A1 ^ (A2)
    //  A1 = A1 ^ (A2<<1)

    //// + A3
    //  A1 = A1 ^ (A3)

    of = B[A1+7] ^ B[A2+7];

    //          A0      2*A1        2*A2      A2        A3
    Bp[A1+0] = ((B[A0+0]                     ^ B[A2+0] ^ B[A3+0] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A1+0]);
    Bp[A1+1] = ((B[A0+1] ^ B[A1+0] ^ B[A2+0] ^ B[A2+1] ^ B[A3+1] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A1+1]);
    Bp[A1+2] = ((B[A0+2] ^ B[A1+1] ^ B[A2+1] ^ B[A2+2] ^ B[A3+2]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A1+2]);
    Bp[A1+3] = ((B[A0+3] ^ B[A1+2] ^ B[A2+2] ^ B[A2+3] ^ B[A3+3] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A1+3]);
    Bp[A1+4] = ((B[A0+4] ^ B[A1+3] ^ B[A2+3] ^ B[A2+4] ^ B[A3+4] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A1+4]);
    Bp[A1+5] = ((B[A0+5] ^ B[A1+4] ^ B[A2+4] ^ B[A2+5] ^ B[A3+5]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A1+5]);
    Bp[A1+6] = ((B[A0+6] ^ B[A1+5] ^ B[A2+5] ^ B[A2+6] ^ B[A3+6]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A1+6]);
    Bp[A1+7] = ((B[A0+7] ^ B[A1+6] ^ B[A2+6] ^ B[A2+7] ^ B[A3+7]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A1+7]);
    

    //  of = A2 ^ A3
    //  A2 = A2 ^ (0x1b & ((signed char)of>>7));

    //// A0 + A1
    //  A2 = A2 ^ (A0)
    //  A2 = A2 ^ (A1)

    //// + 2 * A2
    //  A2 = A2 ^ (A2 << 1)

    //// + 3 * A3
    //  A2 = A2 ^ (A3)
    //  A2 = A2 ^ (A3<<1)


    of = B[A2+7] ^ B[A3+7];

    //          A0      A1          2*A2       2*A3         A3
    Bp[A2+0] = ((B[A0+0] ^ B[A1+0]                     ^ B[A3+0] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A2+0]);
    Bp[A2+1] = ((B[A0+1] ^ B[A1+1] ^ B[A2+0] ^ B[A3+0] ^ B[A3+1] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A2+1]);
    Bp[A2+2] = ((B[A0+2] ^ B[A1+2] ^ B[A2+1] ^ B[A3+1] ^ B[A3+2]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A2+2]);
    Bp[A2+3] = ((B[A0+3] ^ B[A1+3] ^ B[A2+2] ^ B[A3+2] ^ B[A3+3] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A2+3]);
    Bp[A2+4] = ((B[A0+4] ^ B[A1+4] ^ B[A2+3] ^ B[A3+3] ^ B[A3+4] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A2+4]);
    Bp[A2+5] = ((B[A0+5] ^ B[A1+5] ^ B[A2+4] ^ B[A3+4] ^ B[A3+5]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A2+5]);
    Bp[A2+6] = ((B[A0+6] ^ B[A1+6] ^ B[A2+5] ^ B[A3+5] ^ B[A3+6]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A2+6]);
    Bp[A2+7] = ((B[A0+7] ^ B[A1+7] ^ B[A2+6] ^ B[A3+6] ^ B[A3+7]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A2+7]);
    

    //  A3 = A0 ^ A332
    //  A3 = A3 ^ (0x1b & ((signed char)of>>7));

    //// 3 * A0
    //  A3 = A3 ^ (A0)
    //  A3 = A3 ^ (A0 << 1)

    //// + A1 + A2
    //  A3 = A3 ^ A1
    //  A3 = A3 ^ A2

    //// + 2 * A3
    //  A3 = A3 ^ (A3<<1)

    of = B[A0+7] ^ B[A3+7];

    //        2*A0       A0         A1         A2       2*A3
    Bp[A3+0] = ((B[A0+0] ^           B[A1+0] ^ B[A2+0]           ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A3+0]);
    Bp[A3+1] = ((B[A0+1] ^ B[A0+0] ^ B[A1+1] ^ B[A2+1] ^ B[A3+0] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A3+1]);
    Bp[A3+2] = ((B[A0+2] ^ B[A0+1] ^ B[A1+2] ^ B[A2+2] ^ B[A3+1]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A3+2]);
    Bp[A3+3] = ((B[A0+3] ^ B[A0+2] ^ B[A1+3] ^ B[A2+3] ^ B[A3+2] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A3+3]);
    Bp[A3+4] = ((B[A0+4] ^ B[A0+3] ^ B[A1+4] ^ B[A2+4] ^ B[A3+3] ^ of) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A3+4]);
    Bp[A3+5] = ((B[A0+5] ^ B[A0+4] ^ B[A1+5] ^ B[A2+5] ^ B[A3+4]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A3+5]);
    Bp[A3+6] = ((B[A0+6] ^ B[A0+5] ^ B[A1+6] ^ B[A2+6] ^ B[A3+5]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A3+6]);
    Bp[A3+7] = ((B[A0+7] ^ B[A0+6] ^ B[A1+7] ^ B[A2+7] ^ B[A3+6]     ) & BS_DATA_MASK) | ((~BS_DATA_MASK)&B[A3+7]);
    

    //
    Bp += BLOCK_SIZE/4;
    B  += BLOCK_SIZE/4;
    }

    memmove(B - BLOCK_SIZE,Bp - BLOCK_SIZE,sizeof(Bp_space));
}

void bs_mixcolumns_old(word_t * B)
{
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;
    // to understand this, see
    // https://en.wikipedia.org/wiki/Rijndael_mix_columns
    
    int i = 0;
    for (; i < 4; i++)
    {
    //  of = A0 ^ A1;
    //  A0 = A0 ^ (0x1b & ((signed char)of>>7));

    //// 2 * A0
    //  A0 = A0 ^ (A0 << 1)

    //// + 3 * A1
    //  A0 = A0 ^ (A1)
    //  A0 = A0 ^ (A1<<1)

    //// + A2 + A3
    //  A0 = A0 ^ (A2)
    //  A0 = A0 ^ (A3)
    //          A0.7    A1.7
    word_t of = B[A0+7] ^ B[A1+7];

    //          2*A0     2*A1          A1      A2           A3
    Bp[A0+0] =                     B[A1+0] ^ B[A2+0] ^ B[A3+0] ^ of;
    Bp[A0+1] = B[A0+0] ^ B[A1+0] ^ B[A1+1] ^ B[A2+1] ^ B[A3+1] ^ of;
    Bp[A0+2] = B[A0+1] ^ B[A1+1] ^ B[A1+2] ^ B[A2+2] ^ B[A3+2];
    Bp[A0+3] = B[A0+2] ^ B[A1+2] ^ B[A1+3] ^ B[A2+3] ^ B[A3+3] ^ of;
    Bp[A0+4] = B[A0+3] ^ B[A1+3] ^ B[A1+4] ^ B[A2+4] ^ B[A3+4] ^ of;
    Bp[A0+5] = B[A0+4] ^ B[A1+4] ^ B[A1+5] ^ B[A2+5] ^ B[A3+5];
    Bp[A0+6] = B[A0+5] ^ B[A1+5] ^ B[A1+6] ^ B[A2+6] ^ B[A3+6];
    Bp[A0+7] = B[A0+6] ^ B[A1+6] ^ B[A1+7] ^ B[A2+7] ^ B[A3+7];



    //  of = A1 ^ A2
    //  A1 = A1 ^ (0x1b & ((signed char)of>>7));

    //// A0
    //  A1 = A1 ^ (A0)

    //// + 2 * A1
    //  A1 = A1 ^ (A1 << 1)

    //// + 3 * A2
    //  A1 = A1 ^ (A2)
    //  A1 = A1 ^ (A2<<1)

    //// + A3
    //  A1 = A1 ^ (A3)

    of = B[A1+7] ^ B[A2+7];

    //          A0      2*A1        2*A2      A2        A3
    Bp[A1+0] = B[A0+0]                     ^ B[A2+0] ^ B[A3+0] ^ of;
    Bp[A1+1] = B[A0+1] ^ B[A1+0] ^ B[A2+0] ^ B[A2+1] ^ B[A3+1] ^ of;
    Bp[A1+2] = B[A0+2] ^ B[A1+1] ^ B[A2+1] ^ B[A2+2] ^ B[A3+2];
    Bp[A1+3] = B[A0+3] ^ B[A1+2] ^ B[A2+2] ^ B[A2+3] ^ B[A3+3] ^ of;
    Bp[A1+4] = B[A0+4] ^ B[A1+3] ^ B[A2+3] ^ B[A2+4] ^ B[A3+4] ^ of;
    Bp[A1+5] = B[A0+5] ^ B[A1+4] ^ B[A2+4] ^ B[A2+5] ^ B[A3+5];
    Bp[A1+6] = B[A0+6] ^ B[A1+5] ^ B[A2+5] ^ B[A2+6] ^ B[A3+6];
    Bp[A1+7] = B[A0+7] ^ B[A1+6] ^ B[A2+6] ^ B[A2+7] ^ B[A3+7];
    

    //  of = A2 ^ A3
    //  A2 = A2 ^ (0x1b & ((signed char)of>>7));

    //// A0 + A1
    //  A2 = A2 ^ (A0)
    //  A2 = A2 ^ (A1)

    //// + 2 * A2
    //  A2 = A2 ^ (A2 << 1)

    //// + 3 * A3
    //  A2 = A2 ^ (A3)
    //  A2 = A2 ^ (A3<<1)


    of = B[A2+7] ^ B[A3+7];

    //          A0      A1          2*A2       2*A3         A3
    Bp[A2+0] = B[A0+0] ^ B[A1+0]                     ^ B[A3+0] ^ of;
    Bp[A2+1] = B[A0+1] ^ B[A1+1] ^ B[A2+0] ^ B[A3+0] ^ B[A3+1] ^ of;
    Bp[A2+2] = B[A0+2] ^ B[A1+2] ^ B[A2+1] ^ B[A3+1] ^ B[A3+2];
    Bp[A2+3] = B[A0+3] ^ B[A1+3] ^ B[A2+2] ^ B[A3+2] ^ B[A3+3] ^ of;
    Bp[A2+4] = B[A0+4] ^ B[A1+4] ^ B[A2+3] ^ B[A3+3] ^ B[A3+4] ^ of;
    Bp[A2+5] = B[A0+5] ^ B[A1+5] ^ B[A2+4] ^ B[A3+4] ^ B[A3+5];
    Bp[A2+6] = B[A0+6] ^ B[A1+6] ^ B[A2+5] ^ B[A3+5] ^ B[A3+6];
    Bp[A2+7] = B[A0+7] ^ B[A1+7] ^ B[A2+6] ^ B[A3+6] ^ B[A3+7];
    

    //  A3 = A0 ^ A3
    //  A3 = A3 ^ (0x1b & ((signed char)of>>7));

    //// 3 * A0
    //  A3 = A3 ^ (A0)
    //  A3 = A3 ^ (A0 << 1)

    //// + A1 + A2
    //  A3 = A3 ^ A1
    //  A3 = A3 ^ A2

    //// + 2 * A3
    //  A3 = A3 ^ (A3<<1)

    of = B[A0+7] ^ B[A3+7];

    //        2*A0       A0         A1         A2       2*A3
    Bp[A3+0] = B[A0+0] ^           B[A1+0] ^ B[A2+0]           ^ of;
    Bp[A3+1] = B[A0+1] ^ B[A0+0] ^ B[A1+1] ^ B[A2+1] ^ B[A3+0] ^ of;
    Bp[A3+2] = B[A0+2] ^ B[A0+1] ^ B[A1+2] ^ B[A2+2] ^ B[A3+1];
    Bp[A3+3] = B[A0+3] ^ B[A0+2] ^ B[A1+3] ^ B[A2+3] ^ B[A3+2] ^ of;
    Bp[A3+4] = B[A0+4] ^ B[A0+3] ^ B[A1+4] ^ B[A2+4] ^ B[A3+3] ^ of;
    Bp[A3+5] = B[A0+5] ^ B[A0+4] ^ B[A1+5] ^ B[A2+5] ^ B[A3+4];
    Bp[A3+6] = B[A0+6] ^ B[A0+5] ^ B[A1+6] ^ B[A2+6] ^ B[A3+5];
    Bp[A3+7] = B[A0+7] ^ B[A0+6] ^ B[A1+7] ^ B[A2+7] ^ B[A3+6];
    

    //
    Bp += BLOCK_SIZE/4;
    B  += BLOCK_SIZE/4;
    }


    memmove(B - BLOCK_SIZE,Bp - BLOCK_SIZE,sizeof(Bp_space));
}

void bs_mixcolumns_rev(word_t * B)
{
    // to understand this, see
    // https://en.wikipedia.org/wiki/Rijndael_mix_columns
    // TODO combine with shiftrows for performance on decryption
    word_t Bp_space[BLOCK_SIZE];
    word_t * Bp = Bp_space;

 
    int i = 0;
    for (; i < BLOCK_SIZE / 4; i += BLOCK_SIZE / 16)
    {

    //// state[i][0] = A0*0x0e + A1*0x0b + A2*0x0d + A3*0x09
    // overflow:
                    /* A0 * 0b1110             */   /* A1 * 0b1011     */   /* A2 * 0b1101   */   /* A3 * 0b1001 */
    word_t of0 = (  (B[A0+7] ^ B[A0+6] ^ B[A0+5]) ^ (B[A1 + 7] ^ B[A1+5]) ^ (B[A2+6] ^ B[A2+5]) ^ ( B[A3+5] ));       // 2 bit
    word_t of1 = (            (B[A0+7] ^ B[A0+6]) ^ (            B[A1+6]) ^ (B[A2+7] ^ B[A2+6]) ^ ( B[A3+6] ));       // 3 bit
    word_t of2 = (                      (B[A0+7]) ^ (            B[A1+7]) ^ (          B[A2+7]) ^ ( B[A3+7] ));       // 4 bit

    // inverse:
    //          1110      1011    1101      1001
    // A0 = A0 * 14 + A1 * 11 + A2 * 13 + A3 * 9
    // A0 = A0 * (2+4+8) + A1 * (1+2+8) + A2 * (1+4+8) + A3 * (1+8)

    //         (2*A0   +  4*A0   + 8*A0 )  + (8*A1   +  2*A1   +   A1  ) + ( A2    +   4*A2  +  8*A2 ) + (  A3   + 8*A3)
    Bp[A0+0] =                                                   B[A1+0] ^ B[A2+0]                     ^ B[A3+0]           ^ of0;
    Bp[A0+1] = B[A0+0]                               ^ B[A1+0] ^ B[A1+1] ^ B[A2+1]                     ^ B[A3+1]           ^ of0 ^ of1;
    Bp[A0+2] = B[A0+1] ^ B[A0+0]                     ^ B[A1+1] ^ B[A1+2] ^ B[A2+2] ^ B[A2+0]           ^ B[A3+2]                 ^ of1 ^ of2;
    Bp[A0+3] = B[A0+2] ^ B[A0+1] ^ B[A0+0] ^ B[A1+0] ^ B[A1+2] ^ B[A1+3] ^ B[A2+3] ^ B[A2+1] ^ B[A2+0] ^ B[A3+3] ^ B[A3+0] ^ of0       ^ of2;
    Bp[A0+4] = B[A0+3] ^ B[A0+2] ^ B[A0+1] ^ B[A1+1] ^ B[A1+3] ^ B[A1+4] ^ B[A2+4] ^ B[A2+2] ^ B[A2+1] ^ B[A3+4] ^ B[A3+1] ^ of0 ^ of1;
    Bp[A0+5] = B[A0+4] ^ B[A0+3] ^ B[A0+2] ^ B[A1+2] ^ B[A1+4] ^ B[A1+5] ^ B[A2+5] ^ B[A2+3] ^ B[A2+2] ^ B[A3+5] ^ B[A3+2]       ^ of1 ^ of2;
    Bp[A0+6] = B[A0+5] ^ B[A0+4] ^ B[A0+3] ^ B[A1+3] ^ B[A1+5] ^ B[A1+6] ^ B[A2+6] ^ B[A2+4] ^ B[A2+3] ^ B[A3+6] ^ B[A3+3]             ^ of2;
    Bp[A0+7] = B[A0+6] ^ B[A0+5] ^ B[A0+4] ^ B[A1+4] ^ B[A1+6] ^ B[A1+7] ^ B[A2+7] ^ B[A2+5] ^ B[A2+4] ^ B[A3+7] ^ B[A3+4];



    //// state[i][1] = A0*0x09 + A1*0xe + A2*0x0b + A3*0x0d
    // overflow:
          /* A0 * 0b1001 */   /* A1 * 0b1110             */ /* A2 * 0b101  1     */   /* A3 * 0b1101 */
    of0 = (  (B[A0+5]) ^      (B[A1+7] ^ B[A1+6] ^ B[A1+5]) ^ (B[A2 + 7] ^ B[A2+5]) ^ (B[A3+6] ^ B[A3+5]));       // 2 bit
    of1 = (  (B[A0+6]) ^                (B[A1+7] ^ B[A1+6]) ^ (            B[A2+6]) ^ (B[A3+7] ^ B[A3+6]));       // 3 bit
    of2 = (  (B[A0+7]) ^                          (B[A1+7]) ^ (            B[A2+7]) ^ (          B[A3+7]));       // 4 bit

    // inverse:
    //          1001      1110    1011      1101
    // A1 = A0 * 9 + A1 * 14 + A2 * 11 + A3 * 13
    // A1 = A0 * (1+8) + A1 * (2+4+8) + A2 * (1+2+8) + A3 * (1+4+8)

    //         (1*A0   +  8*A0 ) +(2*A1    +  4*A1   +  8*A1 ) + (1*A2   +  2*A2   +  8*A2 ) + (1*A3   +   4*A3  +  8*A3)
    Bp[A1+0] = B[A0+0] ^                                         B[A2+0] ^                     B[A3+0]                     ^ of0;
    Bp[A1+1] = B[A0+1] ^           B[A1+0]                     ^ B[A2+1] ^ B[A2+0] ^           B[A3+1]                     ^ of0 ^ of1;
    Bp[A1+2] = B[A0+2] ^           B[A1+1] ^ B[A1+0]           ^ B[A2+2] ^ B[A2+1] ^           B[A3+2] ^ B[A3+0]                 ^ of1 ^ of2;
    Bp[A1+3] = B[A0+3] ^ B[A0+0] ^ B[A1+2] ^ B[A1+1] ^ B[A1+0] ^ B[A2+3] ^ B[A2+2] ^ B[A2+0] ^ B[A3+3] ^ B[A3+1] ^ B[A3+0] ^ of0       ^ of2;
    Bp[A1+4] = B[A0+4] ^ B[A0+1] ^ B[A1+3] ^ B[A1+2] ^ B[A1+1] ^ B[A2+4] ^ B[A2+3] ^ B[A2+1] ^ B[A3+4] ^ B[A3+2] ^ B[A3+1] ^ of0 ^ of1;
    Bp[A1+5] = B[A0+5] ^ B[A0+2] ^ B[A1+4] ^ B[A1+3] ^ B[A1+2] ^ B[A2+5] ^ B[A2+4] ^ B[A2+2] ^ B[A3+5] ^ B[A3+3] ^ B[A3+2]       ^ of1 ^ of2;
    Bp[A1+6] = B[A0+6] ^ B[A0+3] ^ B[A1+5] ^ B[A1+4] ^ B[A1+3] ^ B[A2+6] ^ B[A2+5] ^ B[A2+3] ^ B[A3+6] ^ B[A3+4] ^ B[A3+3]             ^ of2;
    Bp[A1+7] = B[A0+7] ^ B[A0+4] ^ B[A1+6] ^ B[A1+5] ^ B[A1+4] ^ B[A2+7] ^ B[A2+6] ^ B[A2+4] ^ B[A3+7] ^ B[A3+5] ^ B[A3+4];


    //// state[i][2] = A0*0x0d + A1*0x09 + A2*0x0e + A3*0x0b
    // overflow:
          /* A1 * 0b1001 */  /* A2 * 0b1110              */ /* A3 * 0b1011      */   /* A0 * 0b1101 */
    of0 = (  (B[A1+5]) ^      (B[A2+7] ^ B[A2+6] ^ B[A2+5]) ^ (B[A3 + 7] ^ B[A3+5]) ^ (B[A0+6] ^ B[A0+5]));       // 2 bit
    of1 = (  (B[A1+6]) ^                (B[A2+7] ^ B[A2+6]) ^ (            B[A3+6]) ^ (B[A0+7] ^ B[A0+6]));       // 3 bit
    of2 = (  (B[A1+7]) ^                          (B[A2+7]) ^ (            B[A3+7]) ^ (          B[A0+7]));       // 4 bit

    // inverse:
    //          1001      1110    1011      1101
    // A2 = A1 * 9 + A2 * 14 + A3 * 11 + A0 * 13
    // A2 = A1 * (1+8) + A2 * (2+4+8) + A3 * (1+2+8) + A0 * (1+4+8)

    //         (1*A1   +  8*A1) + ( 2*A2   +  4*A2   +  8*A2)  + (1*A3      2*A2   +  8*A2) +  (1*A0   +   4*A0  +  8*A0)
    Bp[A2+0] = B[A1+0] ^                                         B[A3+0] ^                     B[A0+0]                     ^ of0;
    Bp[A2+1] = B[A1+1] ^           B[A2+0]                     ^ B[A3+1] ^ B[A3+0] ^           B[A0+1]                     ^ of0 ^ of1;
    Bp[A2+2] = B[A1+2] ^           B[A2+1] ^ B[A2+0]           ^ B[A3+2] ^ B[A3+1] ^           B[A0+2] ^ B[A0+0]                 ^ of1 ^ of2;
    Bp[A2+3] = B[A1+3] ^ B[A1+0] ^ B[A2+2] ^ B[A2+1] ^ B[A2+0] ^ B[A3+3] ^ B[A3+2] ^ B[A3+0] ^ B[A0+3] ^ B[A0+1] ^ B[A0+0] ^ of0       ^ of2;
    Bp[A2+4] = B[A1+4] ^ B[A1+1] ^ B[A2+3] ^ B[A2+2] ^ B[A2+1] ^ B[A3+4] ^ B[A3+3] ^ B[A3+1] ^ B[A0+4] ^ B[A0+2] ^ B[A0+1] ^ of0 ^ of1;
    Bp[A2+5] = B[A1+5] ^ B[A1+2] ^ B[A2+4] ^ B[A2+3] ^ B[A2+2] ^ B[A3+5] ^ B[A3+4] ^ B[A3+2] ^ B[A0+5] ^ B[A0+3] ^ B[A0+2]       ^ of1 ^ of2;
    Bp[A2+6] = B[A1+6] ^ B[A1+3] ^ B[A2+5] ^ B[A2+4] ^ B[A2+3] ^ B[A3+6] ^ B[A3+5] ^ B[A3+3] ^ B[A0+6] ^ B[A0+4] ^ B[A0+3]             ^ of2;
    Bp[A2+7] = B[A1+7] ^ B[A1+4] ^ B[A2+6] ^ B[A2+5] ^ B[A2+4] ^ B[A3+7] ^ B[A3+6] ^ B[A3+4] ^ B[A0+7] ^ B[A0+5] ^ B[A0+4];



    //// state[i][3] = A0*0x0b + A1*0x0d + A2*0x09 + A3*0x0e
    // overflow:
           /* A2 * 0b1001 */  /* A3 * 0b1110             */ /* A0 * 0b1011     */     /* A1 * 0b1101 */
    of0 = (  (B[A2+5]) ^      (B[A3+7] ^ B[A3+6] ^ B[A3+5]) ^ (B[A0 + 7] ^ B[A0+5]) ^ (B[A1+6] ^ B[A1+5]));       // 2 bit
    of1 = (  (B[A2+6]) ^                (B[A3+7] ^ B[A3+6]) ^ (            B[A0+6]) ^ (B[A1+7] ^ B[A1+6]));       // 3 bit
    of2 = (  (B[A2+7]) ^                          (B[A3+7]) ^ (            B[A0+7]) ^ (          B[A1+7]));       // 4 bit

    // inverse:
    //          1001      1110    1011      1101
    // A2 = A2 * 9 + A3 * 14 + A0 * 11 + A1 * 13
    // A2 = A2 * (1+8) + A3 * (2+4+8) + A0 * (1+2+8) + A1 * (1+4+8)

    //         (1*A2   +  8*A2) + ( 2*A3   +  4*A3   +  8*A3)  + (1*A0      2*A0   +  8*A0) +  (1*A1   +   4*A1  +  8*A1)
    Bp[A3+0] = B[A2+0] ^                                         B[A0+0] ^                     B[A1+0]                     ^ of0;
    Bp[A3+1] = B[A2+1] ^           B[A3+0]                     ^ B[A0+1] ^ B[A0+0] ^           B[A1+1]                     ^ of0 ^ of1;
    Bp[A3+2] = B[A2+2] ^           B[A3+1] ^ B[A3+0]           ^ B[A0+2] ^ B[A0+1] ^           B[A1+2] ^ B[A1+0]                 ^ of1 ^ of2;
    Bp[A3+3] = B[A2+3] ^ B[A2+0] ^ B[A3+2] ^ B[A3+1] ^ B[A3+0] ^ B[A0+3] ^ B[A0+2] ^ B[A0+0] ^ B[A1+3] ^ B[A1+1] ^ B[A1+0] ^ of0       ^ of2;
    Bp[A3+4] = B[A2+4] ^ B[A2+1] ^ B[A3+3] ^ B[A3+2] ^ B[A3+1] ^ B[A0+4] ^ B[A0+3] ^ B[A0+1] ^ B[A1+4] ^ B[A1+2] ^ B[A1+1] ^ of0 ^ of1;
    Bp[A3+5] = B[A2+5] ^ B[A2+2] ^ B[A3+4] ^ B[A3+3] ^ B[A3+2] ^ B[A0+5] ^ B[A0+4] ^ B[A0+2] ^ B[A1+5] ^ B[A1+3] ^ B[A1+2]       ^ of1 ^ of2;
    Bp[A3+6] = B[A2+6] ^ B[A2+3] ^ B[A3+5] ^ B[A3+4] ^ B[A3+3] ^ B[A0+6] ^ B[A0+5] ^ B[A0+3] ^ B[A1+6] ^ B[A1+4] ^ B[A1+3]             ^ of2;
    Bp[A3+7] = B[A2+7] ^ B[A2+4] ^ B[A3+6] ^ B[A3+5] ^ B[A3+4] ^ B[A0+7] ^ B[A0+6] ^ B[A0+4] ^ B[A1+7] ^ B[A1+5] ^ B[A1+4];

    Bp += BLOCK_SIZE/4;
    B  += BLOCK_SIZE/4;
    }

    memmove(B - BLOCK_SIZE, Bp - BLOCK_SIZE,sizeof(Bp_space));

}

void bs_expand_key(word_t (* rk)[BLOCK_SIZE], uint8_t * _key)
{
    // TODO integrate this better
    uint8_t key[KEY_SCHEDULE_SIZE];
    memmove(key,_key,BLOCK_SIZE/8);
    expand_key(key);

    int i, j = 0, k;
    for (i = 0; i < KEY_SCHEDULE_SIZE; i += (BLOCK_SIZE/8))
    {
        for (k = 0; k < WORD_SIZE; k += 2)
        {

            memmove(rk[j] + k * WORDS_PER_BLOCK, key + i, BLOCK_SIZE / 8);
            memset(rk[j] + (k+1) * WORDS_PER_BLOCK, 0, BLOCK_SIZE / 8);
        }
        bs_transpose(rk[j]);
        j++;
    }

}

void bs_cipher(word_t state[BLOCK_SIZE], word_t (* rk)[BLOCK_SIZE])
{
    int round;
    bs_transpose(state);

    bs_addroundkey(state,rk[0]);

    for (round = 1; round < 10; round++)
    {
        bs_apply_sbox(state);
        
        /*bs_shiftrows(state);*/
        /*bs_mixcolumns(state);*/

        bs_shiftmix(state);
        bs_addroundkey(state,rk[round]);
    }

    bs_apply_sbox(state);
    bs_shiftrows(state);
    bs_addroundkey(state,rk[10]);

    bs_transpose_rev(state);
}

void bs_cipher_rev(word_t state[BLOCK_SIZE], word_t (* rk)[BLOCK_SIZE])
{
    int round;
    bs_transpose(state);


    bs_addroundkey(state,rk[10]);
    for (round = 9; round > 0; round--)
    {
        bs_shiftrows_rev(state);
        bs_apply_sbox_rev(state);
        bs_addroundkey(state,rk[round]);
        bs_mixcolumns_rev(state);
    }
    bs_shiftrows_rev(state);
    bs_apply_sbox_rev(state);
    bs_addroundkey(state,rk[0]);

    bs_transpose_rev(state);
}



