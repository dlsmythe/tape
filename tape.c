#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <progname.h>

int rawflag = 0;
int hexflag = 0;

char *asctab_00[] = /* 00 nul */
  {
    "",            // 00
    "  nul",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_01[] = /* 01 soh */
  {
    "",            // 00
    "  soh",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_02[] = /* 02 stx */
  {
    "",            // 00
    "  stx",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_03[] = /* 03 etx */
  {
    "",            // 00
    "  etx",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_04[] = /* 04 eot */
  {
    "",            // 00
    "  eot",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_05[] = /* 05 enq */
  {
    "",            // 00
    "  enq",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_06[] = /* 06 ack */
  {
    "",            // 00
    "  ack",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_07[] = /* 07 bel */
  {
    "",            // 00
    "  bel",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_08[] = /* 08 bs */
  {
    "",            // 00
    "  bs",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_09[] = /* 09 ht */
  {
    "",            // 00
    "  ht",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_0a[] = /* 0a lf */
  {
    "",            // 00
    "  lf",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_0b[] = /* 0b vt */
  {
    "",            // 00
    "  vt",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_0c[] = /* 0c ff */
  {
    "",            // 00
    "  ff",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_0d[] = /* 0d cr */
  {
    "",            // 00
    "  cr",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_0e[] = /* 0e so */
  {
    "",            // 00
    "  so",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_0f[] = /* 0f si */
  {
    "",            // 00
    "  si",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_10[] = /* 10 dle */
  {
    "",            // 00
    "  dle",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_11[] = /* 11 dc1 */
  {
    "",            // 00
    "  dc1",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_12[] = /* 12 dc2 */
  {
    "",            // 00
    "  dc2",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_13[] = /* 13 dc3 */
  {
    "",            // 00
    "  dc3",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_14[] = /* 14 dc4 */
  {
    "",            // 00
    "  dc4",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_15[] = /* 15 nak */
  {
    "",            // 00
    "  nak",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_16[] = /* 16 syn */
  {
    "",            // 00
    "  syn",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_17[] = /* 17 etb */
  {
    "",            // 00
    "  etb",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_18[] = /* 18 can */
  {
    "",            // 00
    "  can",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_19[] = /* 19 em */
  {
    "",            // 00
    "  em",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_1a[] = /* 1a sub */
  {
    "",            // 00
    "  sub",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_1b[] = /* 1b esc */
  {
    "",            // 00
    "  esc",       // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_1c[] = /* 1c fs */
  {
    "",            // 00
    "  fs",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_1d[] = /* 1d gs */
  {
    "",            // 00
    "  gs",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_1e[] = /* 1e rs */
  {
    "",            // 00
    "  rs",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_1f[] = /* 1f us */
  {
    "",            // 00
    "  us",        // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_20[] = /* 20 ' '*/
  {
    "",            // 00
    "",            // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_21[] = /* 21 '!'*/
  {
    "       ",     // 00
    "       ",     // 00
    "* *****",     // be
    "       ",     // 00
    "       ",     // 00
    NULL
  };

char *asctab_22[] = /* 22 '"'*/
  {
    "",            // 00
    NULL
  };

char *asctab_23[] = /* 23 '#'*/
  {
    "",            // 00
    NULL
  };

char *asctab_24[] = /* 24 '$'*/
  {
    "",            // 00
    NULL
  };

char *asctab_25[] = /* 25 '%'*/
  {
    "",            // 00
    NULL
  };

char *asctab_26[] = /* 26 '&'*/
  {
    "",            // 00
    NULL
  };

char *asctab_27[] = /* 27 '''*/
  {
    "",            // 00
    "      *",     // 02
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_28[] = /* 28 '('*/
  {
    "",            // 00
    "",            // 00
    " *****",      // 7c
    "*     *",     // 82
    NULL
  };

char *asctab_29[] = /* 29 ')'*/
  {
    "*     *",     // 82
    " *****",      // 7c
    "",            // 00
    NULL
  };

char *asctab_2a[] = /* 2a '*'*/
  {
    "",            // 00
    "",            // 00
    "   *",        // 10
    "",            // 00
    NULL
  };

char *asctab_2b[] = /* 2b '+'*/
  {
    "",            // 00
    "   *",        // 10
    "  ***",       // 38
    "   *",        // 10
    "",            // 00
    NULL
  };

char *asctab_2c[] = /* 2c ','*/
  {
    "*",           // 80
    " *",          // 40
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_2d[] = /* 2d '-'*/
  {
    "",            // 00
    "   *",        // 10
    "   *",        // 10
    "",            // 00
    NULL
  };

char *asctab_2e[] = /* 2e '.'*/
  {
    "*",           // 80
    "",            // 00
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_2f[] = /* 2f '/'*/
  {
    "*",           // 80
    "  *",         // 20
    "    *",       // 08
    "      *",     // 02
    NULL
  };

char *asctab_30[] = /* 30 '0'*/
  {
    "",            // 00
    NULL
  };

char *asctab_31[] = /* 31 '1'*/
  {
    "",            // 00
    NULL
  };

char *asctab_32[] = /* 32 '2'*/
  {
    "",            // 00
    NULL
  };

char *asctab_33[] = /* 33 '3'*/
  {
    "",            // 00
    NULL
  };

char *asctab_34[] = /* 34 '4'*/
  {
    "",            // 00
    NULL
  };

char *asctab_35[] = /* 35 '5'*/
  {
    "",            // 00
    NULL
  };

char *asctab_36[] = /* 36 '6'*/
  {
    "",            // 00
    NULL
  };

char *asctab_37[] = /* 37 '7'*/
  {
    "",            // 00
    NULL
  };

char *asctab_38[] = /* 38 '8'*/
  {
    "",            // 00
    NULL
  };

char *asctab_39[] = /* 39 '9'*/
  {
    "",            // 00
    NULL
  };

char *asctab_3a[] = /* 3a ':'*/
  {
    "",            // 00
    NULL
  };

char *asctab_3b[] = /* 3b ';'*char */
  {
    "",            // 00
    NULL
  };

char *asctab_3c[] = /* 3c '<'*/
  {
    "",            // 00
    NULL
  };

char *asctab_3d[] = /* 3d '='*/
  {
    "",            // 00
    NULL
  };

char *asctab_3e[] = /* 3e '>'*/
  {
    "",            // 00
    NULL
  };

char *asctab_3f[] = /* 3f '?'*/
  {
    "",            // 00
    NULL
  };

char *asctab_40[] = /* 40 '@'*/
  {
    "",            // 00
    NULL
  };

char *asctab_41[] = /* 41 'A'*/
  {
    "*****",       // f8
    "   * *",      // 14
    "   *  *",     // 12
    "   * *",      // 14
    "*****",       // f8
    NULL
  };

char *asctab_42[] = /* 42 'B'*/
  {
    "*******",     // fe
    "*  *  *",     // 92
    "*  *  *",     // 92
    " ** **",      // 6c
    NULL
  };

char *asctab_43[] = /* 43 'C'*/
  {
    " ***** ",     // 7c
    "*     *",     // 82
    "*     *",     // 82
    " *   *",      // 44

    NULL
  };

char *asctab_44[] = /* 44 'D'*/
  {
    "*******",     // fe
    "*     *",     // 82
    "*     *",     // 82
    " *****",      // 7c
    NULL
  };

char *asctab_45[] = /* 45 'E'*/
  {
    "*******",     // fe
    "*  *  *",     // 92
    "*  *  *",     // 92
    "*  *  *",     // 92
    NULL
  };

char *asctab_46[] = /* 46 'F'*/
  {
    "*******",     // fe
    "   *  *",     // 12
    "   *  *",     // 12
    "   *  *",     // 12
    NULL
  };

char *asctab_47[] = /* 47 'G'*/
  {
    " *****",      // 7c
    "*     *",     // 82
    "*  *  *",     // 92
    " **  *",      // 64
    NULL
  };

char *asctab_48[] = /* 48 'H'*/
  {
    "*******",     // fe
    "   *",        // 10
    "   *",        // 10
    "*******",     // fe
    NULL
  };

char *asctab_49[] = /* 49 'I'*/
  {
    "*     *",     // 82
    "*******",     // fe
    "*     *",     // 82
    "",            // 00
    NULL
  };

char *asctab_4a[] = /* 4a 'J'*/
  {
    " *",          // 40
    "*",           // 80
    "*",           // 80
    " ******",     // 7e
    NULL
  };

char *asctab_4b[] = /* 4b 'K'*/
  {
    "*******",     // fe
    "   *",        // 10
    " *   *",      // 44
    "*     *",     // 82
    NULL
  };

char *asctab_4c[] = /* 4c 'L'*/
  {
    "*******",     // fe
    "*",           // 80
    "*",           // 80
    "*",           // 80
    NULL
  };

char *asctab_4d[] = /* 4d 'M'*/
  {
    "*******",     // fe
    "   * ",       // 10
    "*",           // 80
    "   * ",       // 10
    "*******",     // fe
    NULL
  };

char *asctab_4e[] = /* 4e 'N'*/
  {
    "*******",     // fe
    "    *",       // 08
    "  *",         // 20
    "*******",     // fe
    NULL
  };

char *asctab_4f[] = /* 4f 'O'*/
  {
    " *****",      // 7c
    "*     *",     // 82
    "*     *",     // 82
    " *****",      // 7c
    NULL
  };

char *asctab_50[] = /* 50 'P'*/
  {
    "*******",     // fe
    "   *  *",     // 12
    "    **",      // 0c
    "",            // 00
    NULL
  };

char *asctab_51[] = /* 51 'Q'*/
  {
    " *****",      // 7c
    "*     *",     // 82
    "**    *",     // c2
    "* ****",      // bc
    NULL
  };

char *asctab_52[] = /* 52 'R'*/
  {
    "*******",     // fe
    "   *  *",     // 12
    "  * **",      // 2c
    "*",           // 80
    NULL
  };

char *asctab_53[] = /* 53 'S'*/
  {
    " *  **",      // 4c
    "*  *  *",     // 92
    " **  *",      // 64
    "",            // 00
    NULL
  };

char *asctab_54[] = /* 54 'T'*/
  {
    "      *",     // 02
    "      *",     // 02
    "*******",     // fe
    "      *",     // 02
    "      *",     // 02
    NULL
  };

char *asctab_55[] = /* 55 'U'*/
  {
    " ******",     // 7e
    "*",           // 80
    "*",           // 80
    " ******",     // 7e
    NULL
  };

char *asctab_56[] = /* 56 'V'*/
  {
    "  *****",     // 3e
    " *",          // 40
    "*",           // 80
    " *",          // 40
    "  *****",     // 3e
    NULL
  };

char *asctab_57[] = /* 57 'W'*/
  {
    "    ***",     // 0e
    "***",         // e0
    " *",          // 40
    "***",         // e0
    "    ***",     // 0e
    NULL
  };

char *asctab_58[] = /* 58 'X'*/
  {
    "*     *",     // 82
    " *   *",      // 44
    "   *",        // 10
    " *   *",      // 44
    "*     *",     // 82
    NULL
  };

char *asctab_59[] = /* 59 'Y'*/
  {
    "      *",     // 02
    "     *",      // 04
    "*****",       // f8
    "     *",      // 04
    "      *",     // 02
    NULL
  };

char *asctab_5a[] = /* 5a 'Z'*/
  {
    "*     *",     // 82
    "* *   *",     // a2
    "*   * *",     // 8a
    "*     *",     // 82
    NULL
  };

char *asctab_5b[] = /* 5b '['*/
  {
    "",            // 00
    "",            // 00
    "*******",     // fe
    "*     *",     // 82
    NULL
  };

char *asctab_5c[] = /* 5c '\'*/
  {
    "      *",     // 02
    "    *",       // 08
    "  *",         // 20
    "*",           // 80
    NULL
  };

char *asctab_5d[] = /* 5d ']'*/
  {
    "*     *",     // 82
    "*******",     // fe
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_5e[] = /* 5e '^'*/
  {
    "",            // 00
    "     *",      // 04
    "      *",     // 02
    "     *",      // 04
    "",            // 00
    NULL
  };

char *asctab_5f[] = /* 5f '_'*/
  {
    "",            // 00
    "*",           // 80
    "*",           // 80
    "",            // 00
    NULL
  };

char *asctab_60[] = /* 60 '`'*/
  {
    "      *",     // 02
    "     *",      // 04
    NULL
  };

char *asctab_61[] = /* 61 'a'*/
  {
    " ***",        // 70
    "*   *",       // 88
    "*****",       // f8
    NULL
  };

char *asctab_62[] = /* 62 'b'*/
  {
    "*******",     // fe
    " ***",        // 70
    "*   *",       // 88
    " ***",        // 70
    NULL
  };

char *asctab_63[] = /* 63 'c'*/
  {
    " ***",        // 70
    "*   *",       // 88
    " * *",        // 50
    NULL
  };

char *asctab_64[] = /* 64 'd'*/
  {
    " ***",        // 70
    "*   *",       // 88
    " ***",        // 70
    "*******",     // fe
    NULL
  };

char *asctab_65[] = /* 65 'e'*/
  {
    " ****",       // 78
    "*  * *",      // 94
    " * **",       // 58
    NULL
  };

char *asctab_66[] = /* 66 'f'*/
  {
    "  *",         // 20
    "******",      // fc
    "  *   *",     // 22
    "     *",      // 04
    NULL
  };

char *asctab_67[] = /* 67 'g'*/
  {
    "*   **",      // 8c
    "*  *  *",     // 92
    " *****",      // 7c
    NULL
  };

char *asctab_68[] = /* 68 'h'*/
  {
    "*******",     // fe
    "   *",        // 10
    "***",         // e0
    NULL
  };

char *asctab_69[] = /* 69 'i'*/
  {
    "*** *",       // e8
    NULL
  };

char *asctab_6a[] = /* 6a 'j'*/
  {
    " *",          // 40
    "*",           // 80
    " ***** *",    // 7d
    NULL
  };

char *asctab_6b[] = /* 6b 'k'*/
  {
    "*******",     // fe
    " **",         // 60
    "*  *",        // 90
    NULL
  };

char *asctab_6c[] = /* 6c 'l'*/
  {
    "*******",     // fe
    NULL
  };

char *asctab_6d[] = /* 6d 'm'*/
  {
    "**",          // c0
    "  *",         // 20
    " *",          // 40
    "  *",         // 20
    "**",          // c0
    NULL
  };

char *asctab_6e[] = /* 6e 'n'*/
  {
    "****",        // f0
    "    *",       // 08
    "****",        // f0
    NULL
  };

char *asctab_6f[] = /* 6f 'o'*/
  {
    " **",         // 60
    "*  *",        // 90
    " **",         // 60
    NULL
  };

char *asctab_70[] = /* 70 'p'*/
  {
    "*****",       // f8
    "  *  *",      // 24
    "   **",       // 18
    NULL
  };

char *asctab_71[] = /* 71 'q'*/
  {
    "   **",       // 18
    "  *  *",      // 24
    "*****",       // f8
    NULL
  };

char *asctab_72[] = /* 72 'r'*/
  {
    "***",         // e0
    "   *",        // 10
    "  *",         // 20
    NULL
  };

char *asctab_73[] = /* 73 's'*/
  {
    "*  **",       // 98
    "* *  *",      // a4
    " *  *",       // 48
    NULL
  };

char *asctab_74[] = /* 74 't'*/
  {
    "   *",        // 10
    "*****",       // f8
    "   *",        // 10
    NULL
  };

char *asctab_75[] = /* 75 'u'*/
  {
    "****",        // f0
    "*",           // 80
    "****",        // f0
    NULL
  };

char *asctab_76[] = /* 76 'v'*/
  {
    " ***",        // 70
    "*",           // 80
    " ***",        // 70
    NULL
  };

char *asctab_77[] = /* 77 'w'*/
  {
    " ***",        // 70
    "*",           // 80
    " *",          // 40
    "*",           // 80
    " ***",        // 70
    NULL
  };

char *asctab_78[] = /* 78 'x'*/
  {
    "*   *",       // 88
    " * *"         // 50
    "  *"          // 20
    " * *"         // 50
    "*   *",       // 88
    NULL
  };

char *asctab_79[] = /* 79 'y'*/
  {
    "*  **",       // 98
    "* *",         // a0
    " ****",       // 78
    NULL
  };

char *asctab_7a[] = /* 7a 'z'*/
  {
    "*   *",       // 88
    "* * *",       // a8
    "*  **",       // 98
    NULL
  };

char *asctab_7b[] = /* 7b '{'*/
  {
    "",            // 00
    "   *",        // 10
    "**   **",     // c6
    "*     *",     // 82
    NULL
  };

char *asctab_7c[] = /* 7c '|'*/
  {
    "",            // 00
    "",            // 00
    "*******",     // fe
    "",            // 00
    "",            // 00
    NULL
  };

char *asctab_7d[] = /* 7d '}'*/
  {
    "*     *",     // 82
    "**   **",     // c6
    "   *",        // 10
    "",            // 00
    NULL
  };

char *asctab_7e[] = /* 7e '~'*/
  {
    "",            // 00
    "  *",         // 20
    "    *",       // 08
    "  *",         // 20
    "   *",        // 10
    "",            // 00
    NULL
  };

char *asctab_7f[] = /* 7f del */
  {
    "",            // 00
    "DEL",         // 00
    "",            // 00
    "",            // 00
    NULL
  };
char **asctab[128] = {
asctab_00,
asctab_01,
asctab_02,
asctab_03,
asctab_04,
asctab_05,
asctab_06,
asctab_07,
asctab_08,
asctab_09,
asctab_0a,
asctab_0b,
asctab_0c,
asctab_0d,
asctab_0e,
asctab_0f,
asctab_10,
asctab_11,
asctab_12,
asctab_13,
asctab_14,
asctab_15,
asctab_16,
asctab_17,
asctab_18,
asctab_19,
asctab_1a,
asctab_1b,
asctab_1c,
asctab_1d,
asctab_1e,
asctab_1f,
asctab_20,
asctab_21,
asctab_22,
asctab_23,
asctab_24,
asctab_25,
asctab_26,
asctab_27,
asctab_28,
asctab_29,
asctab_2a,
asctab_2b,
asctab_2c,
asctab_2d,
asctab_2e,
asctab_2f,
asctab_30,
asctab_31,
asctab_32,
asctab_33,
asctab_34,
asctab_35,
asctab_36,
asctab_37,
asctab_38,
asctab_39,
asctab_3a,
asctab_3b,
asctab_3c,
asctab_3d,
asctab_3e,
asctab_3f,
asctab_40,
asctab_41,
asctab_42,
asctab_43,
asctab_44,
asctab_45,
asctab_46,
asctab_47,
asctab_48,
asctab_49,
asctab_4a,
asctab_4b,
asctab_4c,
asctab_4d,
asctab_4e,
asctab_4f,
asctab_50,
asctab_51,
asctab_52,
asctab_53,
asctab_54,
asctab_55,
asctab_56,
asctab_57,
asctab_58,
asctab_59,
asctab_5a,
asctab_5b,
asctab_5c,
asctab_5d,
asctab_5e,
asctab_5f,
asctab_60,
asctab_61,
asctab_62,
asctab_63,
asctab_64,
asctab_65,
asctab_66,
asctab_67,
asctab_68,
asctab_69,
asctab_6a,
asctab_6b,
asctab_6c,
asctab_6d,
asctab_6e,
asctab_6f,
asctab_70,
asctab_71,
asctab_72,
asctab_73,
asctab_74,
asctab_75,
asctab_76,
asctab_77,
asctab_78,
asctab_79,
asctab_7a,
asctab_7b,
asctab_7c,
asctab_7d,
asctab_7e,
asctab_7f
};

unsigned char charof(char *str)
{
  unsigned char result = 0;
  int i;

  for (i=1; i <= 8; i++) {
    if (str[i-1] != ' ') {
      result |= 1 << (8-i);
    }
  }

  return result;
}

void pchar(char c)
{
  char **p;

  if ((int)c > 127)
      return;
  for (p = asctab[(int)c]; *p; p++) {
    if (hexflag) {
      printf("%02x ", charof(*p));
    } else if (rawflag) {
      printf("%c", charof(*p));
    } else {
      printf("%s\n", *p);
    }
  }
}

void usage(void)
{
    fprintf(stderr, "usage: tape <word> [word ...]\n");
    exit(1);
}

int main(int argc, char **argv)
{
  int c;

  while ((c = getopt(argc, argv, "rh")) != EOF) {
    switch (c) {
    case 'r':
      rawflag = 1;
      break;
    case 'h':
      hexflag = 1;
      break;
    }
  }

  if (NULL == argv[optind]) {
      usage();
  }
  
  char **word;
  for (word = &argv[optind]; *word; word++) {
      char *str = *word;
      while (*str) {
	  pchar(*str++);
	  if (hexflag) {
	      printf(" ");
	  } else if (rawflag) {
	      putc(0,stdout);  // ???
	  } else {
	      puts("");
	  }
      }
  }

  return 0;
}
