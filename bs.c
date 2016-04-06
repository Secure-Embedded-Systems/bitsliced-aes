
#include "bs.h"

/*July 2011*/
/*Straight-line program for AES s box*/

/*Input is U[0], U[1],...,U[7]*/
/*Output is S[0], S[1],...,S[7]*/
// http://cs-www.cs.yale.edu/homes/peralta/CircuitStuff/CMT.html
void bs_sbox_rev(word_t W[8], word_t U[8])
{
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


    T23 = U[0] ^ U[3];
    T22 = ~(U[1] ^ U[3]);
    T2 = ~(U[0] ^ U[1]);
    T1 = U[3] ^ U[4];
    T24 = ~(U[4] ^ U[7]);
    R5 = U[6] ^ U[7];
    T8 = ~(U[1] ^ T23);
    T19 = T22 ^ R5;
    T9 = ~(U[7] ^ T1);
    T10 = T2 ^ T24;
    T13 = T2 ^ R5;
    T3 = T1 ^ R5;
    T25 = ~(U[2] ^ T1);
    R13 = U[1] ^ U[6];
    T17 = ~(U[2] ^ T19);
    T20 = T24 ^ R13;
    T4 = U[4] ^ T8;
    R17 = ~(U[2] ^ U[5]);
    R18 = ~(U[5] ^ U[6]);
    R19 = ~(U[2] ^ U[4]);
    Y5 = U[0] ^ R17;
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
    W[0] = P13 ^ P22;
    W[1] = P26 ^ P29;
    W[2] = P17 ^ P28;
    W[3] = P12 ^ P22;
    W[4] = P23 ^ P27;
    W[5] = P19 ^ P24;
    W[6] = P14 ^ P23;
    W[7] = P9 ^ P16;


}

void bs_sbox(word_t S[8], word_t U[8])
{

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

    T1 = U[0] ^ U[3];
        T2 = U[0] ^ U[5];
        T3 = U[0] ^ U[6];
        T4 = U[3] ^ U[5];
        T5 = U[4] ^ U[6];
        T6 = T1 ^ T5;
        T7 = U[1] ^ U[2];
        T8 = U[7] ^ T6;
        T9 = U[7] ^ T7;
        T10 = T6 ^ T7;
        T11 = U[1] ^ U[5];
        T12 = U[2] ^ U[5];
        T13 = T3 ^ T4;
        T14 = T6 ^ T11;
        T15 = T5 ^ T11;
        T16 = T5 ^ T12;
        T17 = T9 ^ T16;
        T18 = U[3] ^ U[7];
        T19 = T7 ^ T18;
        T20 = T1 ^ T19;
        T21 = U[6] ^ U[7];
        T22 = T7 ^ T21;
        T23 = T2 ^ T22;
        T24 = T2 ^ T10;
        T25 = T20 ^ T17;
        T26 = T3 ^ T16;
        T27 = T1 ^ T12;
        M1 = T13 & T6;
        M2 = T23 & T8;
        M3 = T14 ^ M1;
        M4 = T19 & U[7];
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
        M48 = M39 & U[7];
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
        S[0] = L6 ^ L24;
        S[1] = ~(L16 ^ L26);
        S[2] = ~(L19 ^ L28);
        S[3] = L6 ^ L21;
        S[4] = L20 ^ L22;
        S[5] = L25 ^ L29;
        S[6] = ~(L13 ^ L27);
        S[7] = ~(L6 ^ L23);
}

// transpose a block
// TODO do it in place
void bs_transpose(word_t * transpose, word_t * blocks)
{
    int i,j,k;
    word_t w;
    for(k=0; k < WORD_SIZE; k++)
    {
        for (i=0; i < WORDS_PER_BLOCK; i++)
        {
            w = blocks[k * WORDS_PER_BLOCK + i];
            for(j=0; j < WORD_SIZE; j++)
            {
                // TODO make const time
                transpose[i*WORD_SIZE + j] |= (w & (ONE << j)) ? (ONE<<k) : 0;
            }
        }
    }
}

void bs_transpose_rev(word_t * transpose, word_t * blocks)
{
    int i,j,k;
    word_t w;
    for(k=0; k < BLOCK_SIZE; k++)
    {
        w = blocks[k];
        for(j=0; j < WORD_SIZE; j++)
        {
            word_t bit = (w & (ONE << j)) ? (ONE << (k % WORD_SIZE)) : 0;
            transpose[j * 2 + (k >= WORD_SIZE)] |= bit;
        }
    }
}


#define B0          0
#define B1          32
#define B2          64
#define B3          96

#define B0_shift        (BLOCK_SIZE/16)*0
#define B1_shift        (BLOCK_SIZE/16)*1
#define B2_shift        (BLOCK_SIZE/16)*2
#define B3_shift        (BLOCK_SIZE/16)*3
#define B_MOD           (BLOCK_SIZE/4)


void bs_shiftrows(word_t * Bp, word_t * B)
{
    // Row 0
    Bp[B0 + 0] = B[B0 + (0 + B0_shift) % B_MOD];
    Bp[B0 + 1] = B[B0 + (1 + B0_shift) % B_MOD];
    Bp[B0 + 2] = B[B0 + (2 + B0_shift) % B_MOD];
    Bp[B0 + 3] = B[B0 + (3 + B0_shift) % B_MOD];
    Bp[B0 + 4] = B[B0 + (4 + B0_shift) % B_MOD];
    Bp[B0 + 5] = B[B0 + (5 + B0_shift) % B_MOD];
    Bp[B0 + 6] = B[B0 + (6 + B0_shift) % B_MOD];
    Bp[B0 + 7] = B[B0 + (7 + B0_shift) % B_MOD];
    Bp[B0 + 8] = B[B0 + (8 + B0_shift) % B_MOD];
    Bp[B0 + 9] = B[B0 + (9 + B0_shift) % B_MOD];
    Bp[B0 + 10] = B[B0 + (10 + B0_shift) % B_MOD];
    Bp[B0 + 11] = B[B0 + (11 + B0_shift) % B_MOD];
    Bp[B0 + 12] = B[B0 + (12 + B0_shift) % B_MOD];
    Bp[B0 + 13] = B[B0 + (13 + B0_shift) % B_MOD];
    Bp[B0 + 14] = B[B0 + (14 + B0_shift) % B_MOD];
    Bp[B0 + 15] = B[B0 + (15 + B0_shift) % B_MOD];
    Bp[B0 + 16] = B[B0 + (16 + B0_shift) % B_MOD];
    Bp[B0 + 17] = B[B0 + (17 + B0_shift) % B_MOD];
    Bp[B0 + 18] = B[B0 + (18 + B0_shift) % B_MOD];
    Bp[B0 + 19] = B[B0 + (19 + B0_shift) % B_MOD];
    Bp[B0 + 20] = B[B0 + (20 + B0_shift) % B_MOD];
    Bp[B0 + 21] = B[B0 + (21 + B0_shift) % B_MOD];
    Bp[B0 + 22] = B[B0 + (22 + B0_shift) % B_MOD];
    Bp[B0 + 23] = B[B0 + (23 + B0_shift) % B_MOD];
    Bp[B0 + 24] = B[B0 + (24 + B0_shift) % B_MOD];
    Bp[B0 + 25] = B[B0 + (25 + B0_shift) % B_MOD];
    Bp[B0 + 26] = B[B0 + (26 + B0_shift) % B_MOD];
    Bp[B0 + 27] = B[B0 + (27 + B0_shift) % B_MOD];
    Bp[B0 + 28] = B[B0 + (28 + B0_shift) % B_MOD];
    Bp[B0 + 29] = B[B0 + (29 + B0_shift) % B_MOD];
    Bp[B0 + 30] = B[B0 + (30 + B0_shift) % B_MOD];
    Bp[B0 + 31] = B[B0 + (31 + B0_shift) % B_MOD];

    // Row 1
    Bp[B1 + 0] = B[B1 + (0 + B1_shift) % B_MOD];
    Bp[B1 + 1] = B[B1 + (1 + B1_shift) % B_MOD];
    Bp[B1 + 2] = B[B1 + (2 + B1_shift) % B_MOD];
    Bp[B1 + 3] = B[B1 + (3 + B1_shift) % B_MOD];
    Bp[B1 + 4] = B[B1 + (4 + B1_shift) % B_MOD];
    Bp[B1 + 5] = B[B1 + (5 + B1_shift) % B_MOD];
    Bp[B1 + 6] = B[B1 + (6 + B1_shift) % B_MOD];
    Bp[B1 + 7] = B[B1 + (7 + B1_shift) % B_MOD];
    Bp[B1 + 8] = B[B1 + (8 + B1_shift) % B_MOD];
    Bp[B1 + 9] = B[B1 + (9 + B1_shift) % B_MOD];
    Bp[B1 + 10] = B[B1 + (10 + B1_shift) % B_MOD];
    Bp[B1 + 11] = B[B1 + (11 + B1_shift) % B_MOD];
    Bp[B1 + 12] = B[B1 + (12 + B1_shift) % B_MOD];
    Bp[B1 + 13] = B[B1 + (13 + B1_shift) % B_MOD];
    Bp[B1 + 14] = B[B1 + (14 + B1_shift) % B_MOD];
    Bp[B1 + 15] = B[B1 + (15 + B1_shift) % B_MOD];
    Bp[B1 + 16] = B[B1 + (16 + B1_shift) % B_MOD];
    Bp[B1 + 17] = B[B1 + (17 + B1_shift) % B_MOD];
    Bp[B1 + 18] = B[B1 + (18 + B1_shift) % B_MOD];
    Bp[B1 + 19] = B[B1 + (19 + B1_shift) % B_MOD];
    Bp[B1 + 20] = B[B1 + (20 + B1_shift) % B_MOD];
    Bp[B1 + 21] = B[B1 + (21 + B1_shift) % B_MOD];
    Bp[B1 + 22] = B[B1 + (22 + B1_shift) % B_MOD];
    Bp[B1 + 23] = B[B1 + (23 + B1_shift) % B_MOD];
    Bp[B1 + 24] = B[B1 + (24 + B1_shift) % B_MOD];
    Bp[B1 + 25] = B[B1 + (25 + B1_shift) % B_MOD];
    Bp[B1 + 26] = B[B1 + (26 + B1_shift) % B_MOD];
    Bp[B1 + 27] = B[B1 + (27 + B1_shift) % B_MOD];
    Bp[B1 + 28] = B[B1 + (28 + B1_shift) % B_MOD];
    Bp[B1 + 29] = B[B1 + (29 + B1_shift) % B_MOD];
    Bp[B1 + 30] = B[B1 + (30 + B1_shift) % B_MOD];
    Bp[B1 + 31] = B[B1 + (31 + B1_shift) % B_MOD];

    // Row 2
    Bp[B2 + 0] = B[B2 + (0 + B2_shift) % B_MOD];
    Bp[B2 + 1] = B[B2 + (1 + B2_shift) % B_MOD];
    Bp[B2 + 2] = B[B2 + (2 + B2_shift) % B_MOD];
    Bp[B2 + 3] = B[B2 + (3 + B2_shift) % B_MOD];
    Bp[B2 + 4] = B[B2 + (4 + B2_shift) % B_MOD];
    Bp[B2 + 5] = B[B2 + (5 + B2_shift) % B_MOD];
    Bp[B2 + 6] = B[B2 + (6 + B2_shift) % B_MOD];
    Bp[B2 + 7] = B[B2 + (7 + B2_shift) % B_MOD];
    Bp[B2 + 8] = B[B2 + (8 + B2_shift) % B_MOD];
    Bp[B2 + 9] = B[B2 + (9 + B2_shift) % B_MOD];
    Bp[B2 + 10] = B[B2 + (10 + B2_shift) % B_MOD];
    Bp[B2 + 11] = B[B2 + (11 + B2_shift) % B_MOD];
    Bp[B2 + 12] = B[B2 + (12 + B2_shift) % B_MOD];
    Bp[B2 + 13] = B[B2 + (13 + B2_shift) % B_MOD];
    Bp[B2 + 14] = B[B2 + (14 + B2_shift) % B_MOD];
    Bp[B2 + 15] = B[B2 + (15 + B2_shift) % B_MOD];
    Bp[B2 + 16] = B[B2 + (16 + B2_shift) % B_MOD];
    Bp[B2 + 17] = B[B2 + (17 + B2_shift) % B_MOD];
    Bp[B2 + 18] = B[B2 + (18 + B2_shift) % B_MOD];
    Bp[B2 + 19] = B[B2 + (19 + B2_shift) % B_MOD];
    Bp[B2 + 20] = B[B2 + (20 + B2_shift) % B_MOD];
    Bp[B2 + 21] = B[B2 + (21 + B2_shift) % B_MOD];
    Bp[B2 + 22] = B[B2 + (22 + B2_shift) % B_MOD];
    Bp[B2 + 23] = B[B2 + (23 + B2_shift) % B_MOD];
    Bp[B2 + 24] = B[B2 + (24 + B2_shift) % B_MOD];
    Bp[B2 + 25] = B[B2 + (25 + B2_shift) % B_MOD];
    Bp[B2 + 26] = B[B2 + (26 + B2_shift) % B_MOD];
    Bp[B2 + 27] = B[B2 + (27 + B2_shift) % B_MOD];
    Bp[B2 + 28] = B[B2 + (28 + B2_shift) % B_MOD];
    Bp[B2 + 29] = B[B2 + (29 + B2_shift) % B_MOD];
    Bp[B2 + 30] = B[B2 + (30 + B2_shift) % B_MOD];
    Bp[B2 + 31] = B[B2 + (31 + B2_shift) % B_MOD];

    // Row 3
    Bp[B3 + 0] = B[B3 + (0 + B3_shift) % B_MOD];
    Bp[B3 + 1] = B[B3 + (1 + B3_shift) % B_MOD];
    Bp[B3 + 2] = B[B3 + (2 + B3_shift) % B_MOD];
    Bp[B3 + 3] = B[B3 + (3 + B3_shift) % B_MOD];
    Bp[B3 + 4] = B[B3 + (4 + B3_shift) % B_MOD];
    Bp[B3 + 5] = B[B3 + (5 + B3_shift) % B_MOD];
    Bp[B3 + 6] = B[B3 + (6 + B3_shift) % B_MOD];
    Bp[B3 + 7] = B[B3 + (7 + B3_shift) % B_MOD];
    Bp[B3 + 8] = B[B3 + (8 + B3_shift) % B_MOD];
    Bp[B3 + 9] = B[B3 + (9 + B3_shift) % B_MOD];
    Bp[B3 + 10] = B[B3 + (10 + B3_shift) % B_MOD];
    Bp[B3 + 11] = B[B3 + (11 + B3_shift) % B_MOD];
    Bp[B3 + 12] = B[B3 + (12 + B3_shift) % B_MOD];
    Bp[B3 + 13] = B[B3 + (13 + B3_shift) % B_MOD];
    Bp[B3 + 14] = B[B3 + (14 + B3_shift) % B_MOD];
    Bp[B3 + 15] = B[B3 + (15 + B3_shift) % B_MOD];
    Bp[B3 + 16] = B[B3 + (16 + B3_shift) % B_MOD];
    Bp[B3 + 17] = B[B3 + (17 + B3_shift) % B_MOD];
    Bp[B3 + 18] = B[B3 + (18 + B3_shift) % B_MOD];
    Bp[B3 + 19] = B[B3 + (19 + B3_shift) % B_MOD];
    Bp[B3 + 20] = B[B3 + (20 + B3_shift) % B_MOD];
    Bp[B3 + 21] = B[B3 + (21 + B3_shift) % B_MOD];
    Bp[B3 + 22] = B[B3 + (22 + B3_shift) % B_MOD];
    Bp[B3 + 23] = B[B3 + (23 + B3_shift) % B_MOD];
    Bp[B3 + 24] = B[B3 + (24 + B3_shift) % B_MOD];
    Bp[B3 + 25] = B[B3 + (25 + B3_shift) % B_MOD];
    Bp[B3 + 26] = B[B3 + (26 + B3_shift) % B_MOD];
    Bp[B3 + 27] = B[B3 + (27 + B3_shift) % B_MOD];
    Bp[B3 + 28] = B[B3 + (28 + B3_shift) % B_MOD];
    Bp[B3 + 29] = B[B3 + (29 + B3_shift) % B_MOD];
    Bp[B3 + 30] = B[B3 + (30 + B3_shift) % B_MOD];
    Bp[B3 + 31] = B[B3 + (31 + B3_shift) % B_MOD];

}

void bs_shiftrows_rev(word_t * Bp, word_t * B)
{
    // Row 0
    Bp[B0 + (0 + B0_shift) % B_MOD] = B[B0 + 0];
    Bp[B0 + (1 + B0_shift) % B_MOD] = B[B0 + 1];
    Bp[B0 + (2 + B0_shift) % B_MOD] = B[B0 + 2];
    Bp[B0 + (3 + B0_shift) % B_MOD] = B[B0 + 3];
    Bp[B0 + (4 + B0_shift) % B_MOD] = B[B0 + 4];
    Bp[B0 + (5 + B0_shift) % B_MOD] = B[B0 + 5];
    Bp[B0 + (6 + B0_shift) % B_MOD] = B[B0 + 6];
    Bp[B0 + (7 + B0_shift) % B_MOD] = B[B0 + 7];
    Bp[B0 + (8 + B0_shift) % B_MOD] = B[B0 + 8];
    Bp[B0 + (9 + B0_shift) % B_MOD] = B[B0 + 9];
    Bp[B0 + (10 + B0_shift) % B_MOD] = B[B0 + 10];
    Bp[B0 + (11 + B0_shift) % B_MOD] = B[B0 + 11];
    Bp[B0 + (12 + B0_shift) % B_MOD] = B[B0 + 12];
    Bp[B0 + (13 + B0_shift) % B_MOD] = B[B0 + 13];
    Bp[B0 + (14 + B0_shift) % B_MOD] = B[B0 + 14];
    Bp[B0 + (15 + B0_shift) % B_MOD] = B[B0 + 15];
    Bp[B0 + (16 + B0_shift) % B_MOD] = B[B0 + 16];
    Bp[B0 + (17 + B0_shift) % B_MOD] = B[B0 + 17];
    Bp[B0 + (18 + B0_shift) % B_MOD] = B[B0 + 18];
    Bp[B0 + (19 + B0_shift) % B_MOD] = B[B0 + 19];
    Bp[B0 + (20 + B0_shift) % B_MOD] = B[B0 + 20];
    Bp[B0 + (21 + B0_shift) % B_MOD] = B[B0 + 21];
    Bp[B0 + (22 + B0_shift) % B_MOD] = B[B0 + 22];
    Bp[B0 + (23 + B0_shift) % B_MOD] = B[B0 + 23];
    Bp[B0 + (24 + B0_shift) % B_MOD] = B[B0 + 24];
    Bp[B0 + (25 + B0_shift) % B_MOD] = B[B0 + 25];
    Bp[B0 + (26 + B0_shift) % B_MOD] = B[B0 + 26];
    Bp[B0 + (27 + B0_shift) % B_MOD] = B[B0 + 27];
    Bp[B0 + (28 + B0_shift) % B_MOD] = B[B0 + 28];
    Bp[B0 + (29 + B0_shift) % B_MOD] = B[B0 + 29];
    Bp[B0 + (30 + B0_shift) % B_MOD] = B[B0 + 30];
    Bp[B0 + (31 + B0_shift) % B_MOD] = B[B0 + 31];

    // Row 1
    Bp[B1 + (0 + B1_shift) % B_MOD] = B[B1 + 0];
    Bp[B1 + (1 + B1_shift) % B_MOD] = B[B1 + 1];
    Bp[B1 + (2 + B1_shift) % B_MOD] = B[B1 + 2];
    Bp[B1 + (3 + B1_shift) % B_MOD] = B[B1 + 3];
    Bp[B1 + (4 + B1_shift) % B_MOD] = B[B1 + 4];
    Bp[B1 + (5 + B1_shift) % B_MOD] = B[B1 + 5];
    Bp[B1 + (6 + B1_shift) % B_MOD] = B[B1 + 6];
    Bp[B1 + (7 + B1_shift) % B_MOD] = B[B1 + 7];
    Bp[B1 + (8 + B1_shift) % B_MOD] = B[B1 + 8];
    Bp[B1 + (9 + B1_shift) % B_MOD] = B[B1 + 9];
    Bp[B1 + (10 + B1_shift) % B_MOD] = B[B1 + 10];
    Bp[B1 + (11 + B1_shift) % B_MOD] = B[B1 + 11];
    Bp[B1 + (12 + B1_shift) % B_MOD] = B[B1 + 12];
    Bp[B1 + (13 + B1_shift) % B_MOD] = B[B1 + 13];
    Bp[B1 + (14 + B1_shift) % B_MOD] = B[B1 + 14];
    Bp[B1 + (15 + B1_shift) % B_MOD] = B[B1 + 15];
    Bp[B1 + (16 + B1_shift) % B_MOD] = B[B1 + 16];
    Bp[B1 + (17 + B1_shift) % B_MOD] = B[B1 + 17];
    Bp[B1 + (18 + B1_shift) % B_MOD] = B[B1 + 18];
    Bp[B1 + (19 + B1_shift) % B_MOD] = B[B1 + 19];
    Bp[B1 + (20 + B1_shift) % B_MOD] = B[B1 + 20];
    Bp[B1 + (21 + B1_shift) % B_MOD] = B[B1 + 21];
    Bp[B1 + (22 + B1_shift) % B_MOD] = B[B1 + 22];
    Bp[B1 + (23 + B1_shift) % B_MOD] = B[B1 + 23];
    Bp[B1 + (24 + B1_shift) % B_MOD] = B[B1 + 24];
    Bp[B1 + (25 + B1_shift) % B_MOD] = B[B1 + 25];
    Bp[B1 + (26 + B1_shift) % B_MOD] = B[B1 + 26];
    Bp[B1 + (27 + B1_shift) % B_MOD] = B[B1 + 27];
    Bp[B1 + (28 + B1_shift) % B_MOD] = B[B1 + 28];
    Bp[B1 + (29 + B1_shift) % B_MOD] = B[B1 + 29];
    Bp[B1 + (30 + B1_shift) % B_MOD] = B[B1 + 30];
    Bp[B1 + (31 + B1_shift) % B_MOD] = B[B1 + 31];
    
    // Row 2
    Bp[B2 + (0 + B2_shift) % B_MOD] = B[B2 + 0];
    Bp[B2 + (1 + B2_shift) % B_MOD] = B[B2 + 1];
    Bp[B2 + (2 + B2_shift) % B_MOD] = B[B2 + 2];
    Bp[B2 + (3 + B2_shift) % B_MOD] = B[B2 + 3];
    Bp[B2 + (4 + B2_shift) % B_MOD] = B[B2 + 4];
    Bp[B2 + (5 + B2_shift) % B_MOD] = B[B2 + 5];
    Bp[B2 + (6 + B2_shift) % B_MOD] = B[B2 + 6];
    Bp[B2 + (7 + B2_shift) % B_MOD] = B[B2 + 7];
    Bp[B2 + (8 + B2_shift) % B_MOD] = B[B2 + 8];
    Bp[B2 + (9 + B2_shift) % B_MOD] = B[B2 + 9];
    Bp[B2 + (10 + B2_shift) % B_MOD] = B[B2 + 10];
    Bp[B2 + (11 + B2_shift) % B_MOD] = B[B2 + 11];
    Bp[B2 + (12 + B2_shift) % B_MOD] = B[B2 + 12];
    Bp[B2 + (13 + B2_shift) % B_MOD] = B[B2 + 13];
    Bp[B2 + (14 + B2_shift) % B_MOD] = B[B2 + 14];
    Bp[B2 + (15 + B2_shift) % B_MOD] = B[B2 + 15];
    Bp[B2 + (16 + B2_shift) % B_MOD] = B[B2 + 16];
    Bp[B2 + (17 + B2_shift) % B_MOD] = B[B2 + 17];
    Bp[B2 + (18 + B2_shift) % B_MOD] = B[B2 + 18];
    Bp[B2 + (19 + B2_shift) % B_MOD] = B[B2 + 19];
    Bp[B2 + (20 + B2_shift) % B_MOD] = B[B2 + 20];
    Bp[B2 + (21 + B2_shift) % B_MOD] = B[B2 + 21];
    Bp[B2 + (22 + B2_shift) % B_MOD] = B[B2 + 22];
    Bp[B2 + (23 + B2_shift) % B_MOD] = B[B2 + 23];
    Bp[B2 + (24 + B2_shift) % B_MOD] = B[B2 + 24];
    Bp[B2 + (25 + B2_shift) % B_MOD] = B[B2 + 25];
    Bp[B2 + (26 + B2_shift) % B_MOD] = B[B2 + 26];
    Bp[B2 + (27 + B2_shift) % B_MOD] = B[B2 + 27];
    Bp[B2 + (28 + B2_shift) % B_MOD] = B[B2 + 28];
    Bp[B2 + (29 + B2_shift) % B_MOD] = B[B2 + 29];
    Bp[B2 + (30 + B2_shift) % B_MOD] = B[B2 + 30];
    Bp[B2 + (31 + B2_shift) % B_MOD] = B[B2 + 31];


    // Row 3
    Bp[B3 + (0 + B3_shift) % B_MOD] = B[B3 + 0];
    Bp[B3 + (1 + B3_shift) % B_MOD] = B[B3 + 1];
    Bp[B3 + (2 + B3_shift) % B_MOD] = B[B3 + 2];
    Bp[B3 + (3 + B3_shift) % B_MOD] = B[B3 + 3];
    Bp[B3 + (4 + B3_shift) % B_MOD] = B[B3 + 4];
    Bp[B3 + (5 + B3_shift) % B_MOD] = B[B3 + 5];
    Bp[B3 + (6 + B3_shift) % B_MOD] = B[B3 + 6];
    Bp[B3 + (7 + B3_shift) % B_MOD] = B[B3 + 7];
    Bp[B3 + (8 + B3_shift) % B_MOD] = B[B3 + 8];
    Bp[B3 + (9 + B3_shift) % B_MOD] = B[B3 + 9];
    Bp[B3 + (10 + B3_shift) % B_MOD] = B[B3 + 10];
    Bp[B3 + (11 + B3_shift) % B_MOD] = B[B3 + 11];
    Bp[B3 + (12 + B3_shift) % B_MOD] = B[B3 + 12];
    Bp[B3 + (13 + B3_shift) % B_MOD] = B[B3 + 13];
    Bp[B3 + (14 + B3_shift) % B_MOD] = B[B3 + 14];
    Bp[B3 + (15 + B3_shift) % B_MOD] = B[B3 + 15];
    Bp[B3 + (16 + B3_shift) % B_MOD] = B[B3 + 16];
    Bp[B3 + (17 + B3_shift) % B_MOD] = B[B3 + 17];
    Bp[B3 + (18 + B3_shift) % B_MOD] = B[B3 + 18];
    Bp[B3 + (19 + B3_shift) % B_MOD] = B[B3 + 19];
    Bp[B3 + (20 + B3_shift) % B_MOD] = B[B3 + 20];
    Bp[B3 + (21 + B3_shift) % B_MOD] = B[B3 + 21];
    Bp[B3 + (22 + B3_shift) % B_MOD] = B[B3 + 22];
    Bp[B3 + (23 + B3_shift) % B_MOD] = B[B3 + 23];
    Bp[B3 + (24 + B3_shift) % B_MOD] = B[B3 + 24];
    Bp[B3 + (25 + B3_shift) % B_MOD] = B[B3 + 25];
    Bp[B3 + (26 + B3_shift) % B_MOD] = B[B3 + 26];
    Bp[B3 + (27 + B3_shift) % B_MOD] = B[B3 + 27];
    Bp[B3 + (28 + B3_shift) % B_MOD] = B[B3 + 28];
    Bp[B3 + (29 + B3_shift) % B_MOD] = B[B3 + 29];
    Bp[B3 + (30 + B3_shift) % B_MOD] = B[B3 + 30];
    Bp[B3 + (31 + B3_shift) % B_MOD] = B[B3 + 31];
}



#define A0  0
#define A1  8
#define A2  16
#define A3  24


void bs_mixcolumns(word_t* Bp, word_t * B)
{
    // to understand this, you MUST understand
    // https://en.wikipedia.org/wiki/Rijndael_mix_columns
    // first.
    
    int i = 0;
    for (; i < BLOCK_SIZE / 4; i += BLOCK_SIZE / 16)
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


}

void bs_mixcolumns_rev(word_t * Bp, word_t * B)
{
    // to understand this, you MUST understand
    // https://en.wikipedia.org/wiki/Rijndael_mix_columns
    // first.
 
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


}





