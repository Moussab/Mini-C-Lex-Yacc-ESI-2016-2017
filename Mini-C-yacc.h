/****************************************************************************
*                     U N R E G I S T E R E D   C O P Y
* 
* You are on day 92 of your 30 day trial period.
* 
* This file was produced by an UNREGISTERED COPY of Parser Generator. It is
* for evaluation purposes only. If you continue to use Parser Generator 30
* days after installation then you are required to purchase a license. For
* more information see the online help or go to the Bumble-Bee Software
* homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* Mini-C-yacc.h
* C header file generated from Mini-C-yacc.y.
* 
* Date: 01/22/17
* Time: 10:30:59
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _MINI_C_YACC_H
#define _MINI_C_YACC_H

#include <yypars.h>

#ifndef YYSTYPE
union tagYYSTYPE {
#line 75 ".\\Mini-C-yacc.y"

	struct Quadruplet{
		float FloatValue;
		int IntegerValue;
		char idval[50];
		int val;								
		int index;								
	}Quadruplet;

#line 45 "Mini-C-yacc.h"
};

#define YYSTYPE union tagYYSTYPE
#endif

extern YYSTYPE YYNEAR yylval;

#define NUMBER 257
#define IDENTIFIER 258
#define INT 259
#define FLOAT 260
#define FOR 261
#define WHILE 262
#define DO 263
#define IF 264
#define ELSE 265
#define IFELSE 266
#define moins_unitaire 267
#define plus_unitaire 268
#define LE 269
#define GE 270
#define EQ 271
#define NE 272
#define LT 273
#define GT 274
#endif
