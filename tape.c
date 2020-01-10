/// \file tape.c
///
/// Paper-tape banner program.
///
/// This is a reimplementation of a program that existed on the
/// HP-2000 TSB system that would punch an input string as ASCII
/// characters on the paper-tape punch.
///
/// The essence of the program is to expand each input character
/// into a set of output values that reproduce the character,
/// rotated sideways.  The original version of this program would
/// then write the produced data to the paper-tape puncher, which
/// would punch the message-string you provided as input.
///
/// By default, this program presumes you do not have a paper-tape
/// punch attached, and just produces ascii-art output.
///
/// Yes, it would have been more compact to store the hex values
/// of the output data and expanded them when they are printed,
/// but it is easier to edit them this way (and storage is free,
/// these days...)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>

int rawflag = 0; ///< If non-zero, output the character equivalent of a binary string.
                 ///< (If you have a paper-tape punch, this is what you
                 ///< write to it.)
                 ///<
int hexflag = 0; ///< If non-zero, output the hex value of the input characters.
                 ///<

///
/// Character data.
char *asctab_00[] = /**< 00 nul */
{
     "",
     "  nul",
     "",
     "",
     NULL
};

char *asctab_01[] = /**< 01 soh */
{
     "",
     "  soh",
     "",
     "",
     NULL
};

char *asctab_02[] = /**< 02 stx */
{
     "",
     "  stx",
     "",
     "",
     NULL
};

char *asctab_03[] = /**< 03 etx */
{
     "",
     "  etx",
     "",
     "",
     NULL
};

char *asctab_04[] = /**< 04 eot */
{
     "",
     "  eot",
     "",
     "",
     NULL
};

char *asctab_05[] = /**< 05 enq */
{
     "",
     "  enq",
     "",
     "",
     NULL
};

char *asctab_06[] = /**< 06 ack */
{
     "",
     "  ack",
     "",
     "",
     NULL
};

char *asctab_07[] = /**< 07 bel */
{
     "",
     "  bel",
     "",
     "",
     NULL
};

char *asctab_08[] = /**< 08 bs */
{
     "",
     "  bs",
     "",
     "",
     NULL
};

char *asctab_09[] = /**< 09 ht */
{
     "",
     "  ht",
     "",
     "",
     NULL
};

char *asctab_0a[] = /**< 0a lf */
{
     "",
     "  lf",
     "",
     "",
     NULL
};

char *asctab_0b[] = /**< 0b vt */
{
     "",
     "  vt",
     "",
     "",
     NULL
};

char *asctab_0c[] = /**< 0c ff */
{
     "",
     "  ff",
     "",
     "",
     NULL
};

char *asctab_0d[] = /**< 0d cr */
{
     "",
     "  cr",
     "",
     "",
     NULL
};

char *asctab_0e[] = /**< 0e so */
{
     "",
     "  so",
     "",
     "",
     NULL
};

char *asctab_0f[] = /**< 0f si */
{
     "",
     "  si",
     "",
     "",
     NULL
};

char *asctab_10[] = /**< 10 dle */
{
     "",
     "  dle",
     "",
     "",
     NULL
};

char *asctab_11[] = /**< 11 dc1 */
{
     "",
     "  dc1",
     "",
     "",
     NULL
};

char *asctab_12[] = /**< 12 dc2 */
{
     "",
     "  dc2",
     "",
     "",
     NULL
};

char *asctab_13[] = /**< 13 dc3 */
{
     "",
     "  dc3",
     "",
     "",
     NULL
};

char *asctab_14[] = /**< 14 dc4 */
{
     "",
     "  dc4",
     "",
     "",
     NULL
};

char *asctab_15[] = /**< 15 nak */
{
     "",
     "  nak",
     "",
     "",
     NULL
};

char *asctab_16[] = /**< 16 syn */
{
     "",
     "  syn",
     "",
     "",
     NULL
};

char *asctab_17[] = /**< 17 etb */
{
     "",
     "  etb",
     "",
     "",
     NULL
};

char *asctab_18[] = /**< 18 can */
{
     "",
     "  can",
     "",
     "",
     NULL
};

char *asctab_19[] = /**< 19 em */
{
     "",
     "  em",
     "",
     "",
     NULL
};

char *asctab_1a[] = /**< 1a sub */
{
     "",
     "  sub",
     "",
     "",
     NULL
};

char *asctab_1b[] = /**< 1b esc */
{
     "",
     "  esc",
     "",
     "",
     NULL
};

char *asctab_1c[] = /**< 1c fs */
{
     "",
     "  fs",
     "",
     "",
     NULL
};

char *asctab_1d[] = /**< 1d gs */
{
     "",
     "  gs",
     "",
     "",
     NULL
};

char *asctab_1e[] = /**< 1e rs */
{
     "",
     "  rs",
     "",
     "",
     NULL
};

char *asctab_1f[] = /**< 1f us */
{
     "",
     "  us",
     "",
     "",
     NULL
};

char *asctab_20[] = /**< 20 ' '*/
{
     "",
     "",
     "",
     "",
     NULL
};

char *asctab_21[] = /**< 21 '!'*/
{
     "       ",
     "       ",
     "* *****",
     "       ",
     "       ",
     NULL
};

char *asctab_22[] = /**< 22 '"'*/
{
     "",
     NULL
};

char *asctab_23[] = /**< 23 '#'*/
{
     "",
     NULL
};

char *asctab_24[] = /**< 24 '$'*/
{
     "",
     NULL
};

char *asctab_25[] = /**< 25 '%'*/
{
     "",
     NULL
};

char *asctab_26[] = /**< 26 '&'*/
{
     "",
     NULL
};

char *asctab_27[] = /**< 27 '''*/
{
     "",
     "      *",
     "",
     "",
     NULL
};

char *asctab_28[] = /**< 28 '('*/
{
     "",
     "",
     " *****",
     "*     *",
     NULL
};

char *asctab_29[] = /**< 29 ')'*/
{
     "*     *",
     " *****",
     "",
     NULL
};

char *asctab_2a[] = /**< 2a '*'*/
{
     "",
     "",
     "   *",
     "",
     NULL
};

char *asctab_2b[] = /**< 2b '+'*/
{
     "",
     "   *",
     "  ***",
     "   *",
     "",
     NULL
};

char *asctab_2c[] = /**< 2c ','*/
{
     "*",
     " *",
     "",
     "",
     NULL
};

char *asctab_2d[] = /**< 2d '-'*/
{
     "",
     "   *",
     "   *",
     "",
     NULL
};

char *asctab_2e[] = /**< 2e '.'*/
{
     "*",
     "",
     "",
     "",
     NULL
};

char *asctab_2f[] = /**< 2f '/'*/
{
     "*",
     "  *",
     "    *",
     "      *",
     NULL
};

char *asctab_30[] = /**< 30 '0'*/
{
     " *****",
     "* *   *",
     "*  *  *",
     "*   * *",
     " *****",
     NULL
};

char *asctab_31[] = /**< 31 '1'*/
{
     "*   *",
     "******",
     "*",
     NULL
};

char *asctab_32[] = /**< 32 '2'*/
{
     "*    *",
     "* *   *",
     "*   **",
     NULL
};

char *asctab_33[] = /**< 33 '3'*/
{
     "*  *  *",
     "*  *  *",
     " ** **",
     NULL
};

char *asctab_34[] = /**< 34 '4'*/
{
     "  *",
     "  * * ",
     "******* ",
     "  *",
     NULL
};

char *asctab_35[] = /**< 35 '5'*/
{
     " * ****",
     "*  *  *",
     "*  *  *",
     " **",
     NULL
};

char *asctab_36[] = /**< 36 '6'*/
{
     " *****",
     "*  *  *",
     "*  *  *",
     " **",
     NULL
};

char *asctab_37[] = /**< 37 '7'*/
{
     "*     *",
     "  *   *",
     "    * *",
     "      *",
     NULL
};

char *asctab_38[] = /**< 38 '8'*/
{
     " ** **",
     "*  *  *",
     "*  *  *",
     " ** **",
     NULL
};

char *asctab_39[] = /**< 39 '9'*/
{
     "    **",
     "*  *  *",
     "*  *  *",
     " *****",
     NULL
};

char *asctab_3a[] = /**< 3a ':'*/
{
     "",
     NULL
};

char *asctab_3b[] = /**< 3b ';'*char */
{
     "",
     NULL
};

char *asctab_3c[] = /**< 3c '<'*/
{
     "",
     NULL
};

char *asctab_3d[] = /**< 3d '='*/
{
     "",
     NULL
};

char *asctab_3e[] = /**< 3e '>'*/
{
     "",
     NULL
};

char *asctab_3f[] = /**< 3f '?'*/
{
     "",
     NULL
};

char *asctab_40[] = /**< 40 '@'*/
{
     "",
     NULL
};

char *asctab_41[] = /**< 41 'A'*/
{
     "*****",
     "   * *",
     "   *  *",
     "   * *",
     "*****",
     NULL
};

char *asctab_42[] = /**< 42 'B'*/
{
     "*******",
     "*  *  *",
     "*  *  *",
     " ** **",
     NULL
};

char *asctab_43[] = /**< 43 'C'*/
{
     " ***** ",
     "*     *",
     "*     *",
     " *   *",

     NULL
};

char *asctab_44[] = /**< 44 'D'*/
{
     "*******",
     "*     *",
     "*     *",
     " *****",
     NULL
};

char *asctab_45[] = /**< 45 'E'*/
{
     "*******",
     "*  *  *",
     "*  *  *",
     "*  *  *",
     NULL
};

char *asctab_46[] = /**< 46 'F'*/
{
     "*******",
     "   *  *",
     "   *  *",
     "   *  *",
     NULL
};

char *asctab_47[] = /**< 47 'G'*/
{
     " *****",
     "*     *",
     "*  *  *",
     " **  *",
     NULL
};

char *asctab_48[] = /**< 48 'H'*/
{
     "*******",
     "   *",
     "   *",
     "*******",
     NULL
};

char *asctab_49[] = /**< 49 'I'*/
{
     "*     *",
     "*******",
     "*     *",
     "",
     NULL
};

char *asctab_4a[] = /**< 4a 'J'*/
{
     " *",
     "*",
     "*",
     " ******",
     NULL
};

char *asctab_4b[] = /**< 4b 'K'*/
{
     "*******",
     "   *",
     " *   *",
     "*     *",
     NULL
};

char *asctab_4c[] = /**< 4c 'L'*/
{
     "*******",
     "*",
     "*",
     "*",
     NULL
};

char *asctab_4d[] = /**< 4d 'M'*/
{
     "*******",
     "   * ",
     "*",
     "   * ",
     "*******",
     NULL
};

char *asctab_4e[] = /**< 4e 'N'*/
{
     "*******",
     "    *",
     "  *",
     "*******",
     NULL
};

char *asctab_4f[] = /**< 4f 'O'*/
{
     " *****",
     "*     *",
     "*     *",
     " *****",
     NULL
};

char *asctab_50[] = /**< 50 'P'*/
{
     "*******",
     "   *  *",
     "    **",
     "",
     NULL
};

char *asctab_51[] = /**< 51 'Q'*/
{
     " *****",
     "*     *",
     "**    *",
     "* ****",
     NULL
};

char *asctab_52[] = /**< 52 'R'*/
{
     "*******",
     "   *  *",
     "  * **",
     "*",
     NULL
};

char *asctab_53[] = /**< 53 'S'*/
{
     " *  **",
     "*  *  *",
     " **  *",
     "",
     NULL
};

char *asctab_54[] = /**< 54 'T'*/
{
     "      *",
     "      *",
     "*******",
     "      *",
     "      *",
     NULL
};

char *asctab_55[] = /**< 55 'U'*/
{
     " ******",
     "*",
     "*",
     " ******",
     NULL
};

char *asctab_56[] = /**< 56 'V'*/
{
     "  *****",
     " *",
     "*",
     " *",
     "  *****",
     NULL
};

char *asctab_57[] = /**< 57 'W'*/
{
     "    ***",
     "***",
     " *",
     "***",
     "    ***",
     NULL
};

char *asctab_58[] = /**< 58 'X'*/
{
     "*     *",
     " *   *",
     "   *",
     " *   *",
     "*     *",
     NULL
};

char *asctab_59[] = /**< 59 'Y'*/
{
     "      *",
     "     *",
     "*****",
     "     *",
     "      *",
     NULL
};

char *asctab_5a[] = /**< 5a 'Z'*/
{
     "*     *",
     "* *   *",
     "*   * *",
     "*     *",
     NULL
};

char *asctab_5b[] = /**< 5b '['*/
{
     "",
     "",
     "*******",
     "*     *",
     NULL
};

char *asctab_5c[] = /**< 5c '\'*/
{
     "      *",
     "    *",
     "  *",
     "*",
     NULL
};

char *asctab_5d[] = /**< 5d ']'*/
{
     "*     *",
     "*******",
     "",
     "",
     NULL
};

char *asctab_5e[] = /**< 5e '^'*/
{
     "",
     "     *",
     "      *",
     "     *",
     "",
     NULL
};

char *asctab_5f[] = /**< 5f '_'*/
{
     "",
     "*",
     "*",
     "",
     NULL
};

char *asctab_60[] = /**< 60 '`'*/
{
     "      *",
     "     *",
     NULL
};

char *asctab_61[] = /**< 61 'a'*/
{
     " ***",
     "*   *",
     "*****",
     NULL
};

char *asctab_62[] = /**< 62 'b'*/
{
     "*******",
     " ***",
     "*   *",
     " ***",
     NULL
};

char *asctab_63[] = /**< 63 'c'*/
{
     " ***",
     "*   *",
     " * *",
     NULL
};

char *asctab_64[] = /**< 64 'd'*/
{
     " ***",
     "*   *",
     " ***",
     "*******",
     NULL
};

char *asctab_65[] = /**< 65 'e'*/
{
     " ****",
     "*  * *",
     " * **",
     NULL
};

char *asctab_66[] = /**< 66 'f'*/
{
     "  *",
     "******",
     "  *   *",
     "     *",
     NULL
};

char *asctab_67[] = /**< 67 'g'*/
{
     "*   **",
     "*  *  *",
     " *****",
     NULL
};

char *asctab_68[] = /**< 68 'h'*/
{
     "*******",
     "   *",
     "***",
     NULL
};

char *asctab_69[] = /**< 69 'i'*/
{
     "*** *",
     NULL
};

char *asctab_6a[] = /**< 6a 'j'*/
{
     " *",
     "*",
     " ***** *",
     NULL
};

char *asctab_6b[] = /**< 6b 'k'*/
{
     "*******",
     " **",
     "*  *",
     NULL
};

char *asctab_6c[] = /**< 6c 'l'*/
{
     "*******",
     NULL
};

char *asctab_6d[] = /**< 6d 'm'*/
{
     "**",
     "  *",
     " *",
     "  *",
     "**",
     NULL
};

char *asctab_6e[] = /**< 6e 'n'*/
{
     "****",
     "    *",
     "****",
     NULL
};

char *asctab_6f[] = /**< 6f 'o'*/
{
     " **",
     "*  *",
     " **",
     NULL
};

char *asctab_70[] = /**< 70 'p'*/
{
     "*****",
     "  *  *",
     "   **",
     NULL
};

char *asctab_71[] = /**< 71 'q'*/
{
     "   **",
     "  *  *",
     "*****",
     NULL
};

char *asctab_72[] = /**< 72 'r'*/
{
     "***",
     "   *",
     "  *",
     NULL
};

char *asctab_73[] = /**< 73 's'*/
{
     "*  *",
     "* * *",
     " * *",
     NULL
};

char *asctab_74[] = /**< 74 't'*/
{
     "  *",
     "****",
     "  *",
     NULL
};

char *asctab_75[] = /**< 75 'u'*/
{
     "***",
     "*",
     "***",
     NULL
};

char *asctab_76[] = /**< 76 'v'*/
{
     " **",
     "*",
     " **",
     NULL
};

char *asctab_77[] = /**< 77 'w'*/
{
     " ***",
     "*",
     " *",
     "*",
     " ***",
     NULL
};

char *asctab_78[] = /**< 78 'x'*/
{
     "*   *",
     " * *"
     "  *"
     " * *"
     "*   *",
     NULL
};

char *asctab_79[] = /**< 79 'y'*/
{
     "*  **",
     "* *",
     " ****",
     NULL
};

char *asctab_7a[] = /**< 7a 'z'*/
{
     "*   *",
     "* * *",
     "*  **",
     NULL
};

char *asctab_7b[] = /**< 7b '{'*/
{
     "",
     "   *",
     "**   **",
     "*     *",
     NULL
};

char *asctab_7c[] = /**< 7c '|'*/
{
     "",
     "",
     "*******",
     "",
     "",
     NULL
};

char *asctab_7d[] = /**< 7d '}'*/
{
     "*     *",
     "**   **",
     "   *",
     "",
     NULL
};

char *asctab_7e[] = /**< 7e '~'*/
{
     "",
     "  *",
     "    *",
     "  *",
     "   *",
     "",
     NULL
};

char *asctab_7f[] = /**< 7f del */
{
     "",
     "DEL",
     "",
     "",
     NULL
};

/// Top-level character-data table.
/// This is indexed by an input character,
/// and each entry contains a reference to a NULL-terminated array of strings
/// representing the output data values for that input character.
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

/// Convert a character string representing a binary number
/// (using non-space for 1 and space for 0) into its numeric equivalent.
/// @param [in] str the input string to be converted
/// @return the numeric equivalent of the input string
unsigned char charof(char *str)
{
     unsigned char result = 0;
     int i;

     for (i=0; i <= 6; i++) {
	  if (str[i] != ' ') {
	       result |= 1 << (6-i);
	  }
     }

     return result;
}

///
/// Output an input char.

///
/// This converts an ASCII character from the input into the constituent
/// output data values needed to graphically reproduce it.
/// @param c the character that is to be printed (only the bottom 7 bits are used)
void pchar(char c)
{
     char **p;

     for (p = asctab[0x7f & (int)c]; *p; p++) {
	  if (hexflag) {
	       printf("%02x ", charof(*p));
	  } else if (rawflag) {
	       printf("%c", charof(*p));
	  } else {
	       printf("%s\n", *p);
	  }
     }
}

/// Provide a helpful message describing how to run this program.
///
/// Run with no arguments to get this message.
void usage(void)
{
     fprintf(stderr, "usage: tape <message>\n");
     exit(1);
}

int main(int argc, char **argv)
{
     char *str;
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

     while ((str = argv[optind++])) {
	  while (*str) {
	       pchar(*str++);
	       if (hexflag) {
		    printf(" ");
	       } else if (rawflag) {
		    putc(0,stdout);
	       } else {
		    puts("");
	       }
	  }
     }

     return 0;
}
