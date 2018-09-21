




/* lex1.c         14 Feb 01; 31 May 12       */

/* This file contains code stubs for the lexical analyzer.
   Rename this file to be lexanc.c and fill in the stubs.    */

/* Copyright (c) 2001 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/*
    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "token.h"
#include "lexan.h"
#include <math.h>

char *operator[] = {" ", "+", "-", "*", "/", ":=", "=", "<>", "<", "<=", ">=", ">", "^", ".", "and", "or", "not", "div", "mod", "in"};
char *delimiter[] = {" ", ",", ";", ":", "(", ")", "[", "]", ".."};
char *reserved[] = {" ","array", "begin", "case", "const", "do",
			"downto", "else", "end", "file", "for",
			"function", "goto", "if", "label", "nil",
			"of", "packed", "procedure", "program", "record",
 			"repeat", "set", "then", "to", "type",
			"until", "var", "while", "with" };


/* This file will work as given with an input file consisting only
   of integers separated by blanks:
   make lex1
   lex1
   12345 123    345  357
   */

/* Skip blanks and whitespace.  Expand this function to skip comments too. */
void skipblanks () {
     	int c;
      	while ((c = peekchar()) != EOF && (c == ' ' || c == '\n' || c == '\t'
			|| c == '{' || ( c == '(' && peek2char() == '*') )) {

		if(peekchar() == '{') {
			while(peekchar() != '}') {
				getchar();
			}
		}
		int i = 1;
		if((c = peekchar()) == '(' && peek2char() == '*') {
			getchar();
			while(i){
				getchar();
				if(peekchar() == '*' && peek2char() == ')') {
					getchar();
					i = 0;
				}
			}
		}
		getchar();
	}
}

/* Get identifiers and reserved words */
TOKEN identifier (TOKEN tok) {
	char identifier[16];
	char c = peekchar();
	int i = 0;
	while(CHARCLASS[c] == ALPHA || CHARCLASS[c] == NUMERIC) {
		c = getchar();
		if(i < 15) {
			identifier[i] = c;
			i++;
		}
		c = peekchar();
	}
	identifier[i] = 0;
	strcpy(tok->stringval, identifier);
	tok->tokentype = IDENTIFIERTOK;
	tok->datatype = STRINGTYPE;

	i = 0;
	for(; i < 30; i++) {
		if(strcmp(reserved[i], identifier) == 0) {
			tok->tokentype = RESERVED;
			tok->whichval = i;
		}
	}

	i = 0;
	for(; i < 20; i++) {
		if(strcmp(operator[i], identifier) == 0) {
			tok->tokentype = OPERATOR;
			tok->whichval = i;
		}
	}
}

TOKEN getstring (TOKEN tok) {
	char string[16];
	int i = 0, j = 1;
	int c;
	getchar();

	while(j) {
		c = getchar();
		if(peekchar() == '\'') {
			if(peek2char() != '\'') {
				getchar();
				if(i < 15) {
					string[i] = c;
					string[i+1] = 0;
				}
				j = 0;
			} else {
				string[i] = c;
				i++;
				getchar();
			}
		} else if(i < 15) {
			string[i] = c;
			i++;
		}
		string[15] = 0;
	}

	strcpy(tok->stringval, string);
	tok->tokentype = STRINGTOK;
	tok->datatype = STRINGTYPE;
}

TOKEN special (TOKEN tok){
	char special[3];
	int c;

	if((c = peekchar()) != '.' && c != '<' && c != '>' && c != ':') {
		c = getchar();
		special[0] = c;
		special[1] = 0;
	} else {
		c = getchar();
		int c2 = peekchar();
		if(c2 != '.' && c2 != '=' && c2 != '>') {
			special[0] = c;
			special[1] = 0;
		} else {
			c2 = getchar();
			special[0] = c;
			special[1] = c2;
			special[2] = 0;
		}
	}

	int i = 0;

	for(; i < 9; i++) {
		if(strcmp(delimiter[i], special) == 0) {
			strcpy(tok->stringval, special);
			tok->tokentype = DELIMITER;
			tok->datatype = STRINGTYPE;
			tok->whichval = i;
		}
	}

	i = 0;
	for(; i < 20; i++) {
		if(strcmp(operator[i], special) == 0) {
			strcpy(tok->stringval, special);
			tok->tokentype = OPERATOR;
			tok->datatype = STRINGTYPE;
			tok->whichval = i;
		}
	}

}

/* Get and convert unsigned numbers of all types. */

TOKEN number (TOKEN tok) {
	long num;
	int  c, charval;
	num = 0;

	char integer[64], frac[64];
	int is_decimal = 0, decimal_location = 0, int_size = 0, frac_size = 0, has_exponent = 0, exponent = 0;
	int i, index = 0;
	int zeros_after = 0, zeros_before = 0;

	while ((c = peekchar()) != EOF && ((CHARCLASS[c] == NUMERIC) || c == 'e' || c == '.')) {
		while(((c = peekchar()) == '.' || c == '0')) {
			c = getchar();

			if(c == '.') {
				if(peekchar() == '.') {
					ungetc(c, stdin);
					tok->tokentype = NUMBERTOK;
					tok->datatype = INTEGER;
					tok->intval = num;
					return tok;
				}
				is_decimal = 1;
				decimal_location = index;
			} else if(is_decimal && c == '0') {
				zeros_after++;
			} else if(!is_decimal && c == '0') {
				zeros_before++;
			}
			index++;
		}

		c = getchar();
		if(c == 'e') {
			has_exponent = 1;
			int c2 = peekchar();
			int is_negative = 0;
			int j = 0;

			if(c2 == '-') {
				is_negative = 1;
				c2 = getchar();
			} else if(c2 == '+')
				c2 = getchar();

			while(peekchar() == '0')
				getchar();
			while(((c2 = peekchar()) == '-' || c2 == '+' || CHARCLASS[c2] == NUMERIC) && j < 3) {
				c2 = getchar();
				exponent = exponent * 10 + (c2 - '0');
				j++;
			}

			if(is_negative)
				exponent = exponent * -1;

		} else if(c == '.') {
			decimal_location = index;
			is_decimal = 1;
		} else if(CHARCLASS[c] == NUMERIC) {
			if(!is_decimal) {
				charval = (c - '0');
				num = num * 10 + charval;
				integer[index - zeros_before] = c;
				int_size++;
			} else if(c != '.' && is_decimal){
				frac[index - decimal_location - zeros_after - 1] = c;
				frac_size++;
			}
		} else
			ungetc(c, stdin);
		index++;
	}

	// check int overflow
	char maxint[10] = "2147483647";
	if(int_size > 0 && !is_decimal) {
		i = 0;
		if(int_size > 10) {
			printf("Integer number out of range\n");
			for(; i < 10; i++) {
				charval = integer[i] - '0';
				num = num * 10 + charval;
			}
		} else if(int_size == 10){
			for(; i < 10; i++) {
				if(integer[i] > maxint[i])
					printf("Integer number out of range\n");
			}
		}
	}

	// truncate
	if(is_decimal && int_size > 8) {
		frac_size = 0;
		exponent += int_size - 8;

		i = 0;
		num = 0;
		for(; i < 8; i++){
			charval = integer[i] - '0';
			num = num * 10 + charval;
		}
	}

	tok->tokentype = NUMBERTOK;

	if(!is_decimal && !has_exponent) {
		tok->datatype = INTEGER;
		tok->intval = num;
	} else {
		float x = 0.1f, float_num = num/1.0;
		i = 0;
		for(; i < frac_size; i++){
			float_num = float_num + (frac[i] - '0') * x;
			x = x/10;
		}
		if((exponent - zeros_after) < -38 || (exponent - zeros_after) > 38 )
			printf("Floating number out of range\n");
		float_num = float_num * pow(10.0, exponent/1.0) * pow(10.0, -zeros_after/1.0);
		if(float_num > 3.1415927e38) {
			tok->datatype = REAL;
			tok->realval = 0.0f;
		} else {
			tok->datatype = REAL;
			tok->realval = float_num;
		}
	}
    return (tok);
}
