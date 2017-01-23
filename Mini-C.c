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
* Mini-C.c
* C source file generated from Mini-C.l.
* 
* Date: 01/22/17
* Time: 09:39:58
* 
* ALex Version: 2.07
****************************************************************************/

#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#line 1 ".\\Mini-C.l"

	#include <string.h>
	#include "Mini-C-yacc.h"

#line 45 "Mini-C.c"
/* repeated because of possible precompiled header */
#include <yylex.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTLEXER

#include ".\Mini-C.h"

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/* yytext */
static char YYNEAR yysatext[(YYTEXT_SIZE) + 1];		/* extra char for \0 */
char YYFAR *YYNEAR YYDCDECL yystext = yysatext;
char YYFAR *YYNEAR YYDCDECL yytext = yysatext;
int YYNEAR YYDCDECL yystext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_size = (YYTEXT_SIZE);
int YYNEAR YYDCDECL yytext_max = (YYTEXT_MAX);

/* yystatebuf */
#if (YYTEXT_SIZE) != 0
static int YYNEAR yysastatebuf[(YYTEXT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysstatebuf = yysastatebuf;
int YYFAR *YYNEAR YYDCDECL yystatebuf = yysastatebuf;
#else
int YYFAR *YYNEAR YYDCDECL yysstatebuf = NULL;
int YYFAR *YYNEAR YYDCDECL yystatebuf = NULL;
#endif

/* yyunputbuf */
#if (YYUNPUT_SIZE) != 0
static int YYNEAR yysaunputbuf[(YYUNPUT_SIZE)];
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = yysaunputbuf;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = yysaunputbuf;
#else
int YYFAR *YYNEAR YYDCDECL yysunputbufptr = NULL;
int YYFAR *YYNEAR YYDCDECL yyunputbufptr = NULL;
#endif
int YYNEAR YYDCDECL yysunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_size = (YYUNPUT_SIZE);
int YYNEAR YYDCDECL yyunput_max = (YYUNPUT_MAX);

/* backwards compatability with lex */
#ifdef input
#ifdef YYPROTOTYPE
int YYCDECL yyinput(void)
#else
int YYCDECL yyinput()
#endif
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
#ifdef YYPROTOTYPE
void YYCDECL yyoutput(int ch)
#else
void YYCDECL yyoutput(ch)
int ch;
#endif
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
#ifdef YYPROTOTYPE
void YYCDECL yyunput(int ch)
#else
void YYCDECL yyunput(ch)
int ch;
#endif
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		/* <warning: unreachable code> off */
#endif
#endif

#ifdef YYPROTOTYPE
int YYCDECL yylexeraction(int action)
#else
int YYCDECL yylexeraction(action)
int action;
#endif
{
	yyreturnflg = YYTRUE;
	switch (action) {
	case 1:
		{
#line 12 ".\\Mini-C.l"
;
#line 166 "Mini-C.c"
		}
		break;
	case 2:
		{
#line 13 ".\\Mini-C.l"
 yylineno = yylineno + 1;
#line 173 "Mini-C.c"
		}
		break;
	case 3:
		{
#line 14 ".\\Mini-C.l"
return INT;
#line 180 "Mini-C.c"
		}
		break;
	case 4:
		{
#line 15 ".\\Mini-C.l"
return FLOAT;
#line 187 "Mini-C.c"
		}
		break;
	case 5:
		{
#line 16 ".\\Mini-C.l"
return FOR;
#line 194 "Mini-C.c"
		}
		break;
	case 6:
		{
#line 17 ".\\Mini-C.l"
return WHILE;
#line 201 "Mini-C.c"
		}
		break;
	case 7:
		{
#line 18 ".\\Mini-C.l"
return IF;
#line 208 "Mini-C.c"
		}
		break;
	case 8:
		{
#line 19 ".\\Mini-C.l"
return DO;
#line 215 "Mini-C.c"
		}
		break;
	case 9:
		{
#line 20 ".\\Mini-C.l"
return ELSE;
#line 222 "Mini-C.c"
		}
		break;
	case 10:
		{
#line 21 ".\\Mini-C.l"
return IFELSE;
#line 229 "Mini-C.c"
		}
		break;
	case 11:
		{
#line 22 ".\\Mini-C.l"
yylval.Quadruplet.IntegerValue=atoi(yytext);yylval.Quadruplet.index=0;return NUMBER ;
#line 236 "Mini-C.c"
		}
		break;
	case 12:
		{
#line 23 ".\\Mini-C.l"
yylval.Quadruplet.FloatValue=atof(yytext);yylval.Quadruplet.index=1;return NUMBER ;
#line 243 "Mini-C.c"
		}
		break;
	case 13:
		{
#line 24 ".\\Mini-C.l"
yylval.Quadruplet.index=2;strcpy(yylval.Quadruplet.idval,yytext);return IDENTIFIER;
#line 250 "Mini-C.c"
		}
		break;
	case 14:
		{
#line 25 ".\\Mini-C.l"
return LE;
#line 257 "Mini-C.c"
		}
		break;
	case 15:
		{
#line 26 ".\\Mini-C.l"
return GE;
#line 264 "Mini-C.c"
		}
		break;
	case 16:
		{
#line 27 ".\\Mini-C.l"
return EQ;
#line 271 "Mini-C.c"
		}
		break;
	case 17:
		{
#line 28 ".\\Mini-C.l"
return NE;
#line 278 "Mini-C.c"
		}
		break;
	case 18:
		{
#line 29 ".\\Mini-C.l"
return GT;
#line 285 "Mini-C.c"
		}
		break;
	case 19:
		{
#line 30 ".\\Mini-C.l"
return LT;
#line 292 "Mini-C.c"
		}
		break;
#line 31 ".\\Mini-C.l"
								;
#line 297 "Mini-C.c"
	case 20:
		{
#line 32 ".\\Mini-C.l"
return yytext[0];
#line 302 "Mini-C.c"
		}
		break;
	case 21:
		{
#line 33 ".\\Mini-C.l"
;
#line 309 "Mini-C.c"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = YYFALSE;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		/* <warning: unreachable code> to the old state */
#endif
#endif
YYCONST yymatch_t YYNEARFAR YYBASED_CODE YYDCDECL yymatch[] = {
	0
};

int YYNEAR YYDCDECL yytransitionmax = 190;
YYCONST yytransition_t YYNEARFAR YYBASED_CODE YYDCDECL yytransition[] = {
	{ 0, 0 },
	{ 4, 2 },
	{ 5, 2 },
	{ 18, 7 },
	{ 22, 12 },
	{ 7, 7 },
	{ 7, 7 },
	{ 7, 7 },
	{ 7, 7 },
	{ 7, 7 },
	{ 7, 7 },
	{ 7, 7 },
	{ 7, 7 },
	{ 7, 7 },
	{ 7, 7 },
	{ 26, 15 },
	{ 24, 14 },
	{ 23, 13 },
	{ 17, 6 },
	{ 25, 14 },
	{ 3, 1 },
	{ 28, 16 },
	{ 19, 8 },
	{ 27, 15 },
	{ 4, 2 },
	{ 6, 2 },
	{ 30, 23 },
	{ 44, 2 },
	{ 29, 18 },
	{ 29, 18 },
	{ 29, 18 },
	{ 29, 18 },
	{ 29, 18 },
	{ 29, 18 },
	{ 29, 18 },
	{ 29, 18 },
	{ 29, 18 },
	{ 29, 18 },
	{ 31, 24 },
	{ 32, 25 },
	{ 7, 2 },
	{ 7, 2 },
	{ 7, 2 },
	{ 7, 2 },
	{ 7, 2 },
	{ 7, 2 },
	{ 7, 2 },
	{ 7, 2 },
	{ 7, 2 },
	{ 7, 2 },
	{ 33, 26 },
	{ 34, 27 },
	{ 8, 2 },
	{ 9, 2 },
	{ 10, 2 },
	{ 35, 28 },
	{ 36, 30 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 37, 31 },
	{ 38, 33 },
	{ 39, 35 },
	{ 40, 37 },
	{ 41, 38 },
	{ 42, 39 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 12, 2 },
	{ 13, 2 },
	{ 14, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 15, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 16, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 2 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 43, 41 },
	{ 20, 9 },
	{ 21, 10 },
	{ 45, 44 },
	{ 46, 45 },
	{ 47, 46 },
	{ 48, 47 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 49, 48 },
	{ 50, 49 },
	{ 51, 50 },
	{ 52, 51 },
	{ 0, 53 },
	{ 0, 0 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 },
	{ 11, 43 }
};

YYCONST yystate_t YYNEARFAR YYBASED_CODE YYDCDECL yystate[] = {
	{ 0, 0, 0 },
	{ 2, -15, 0 },
	{ -3, -8, 0 },
	{ 0, 0, 20 },
	{ 0, 0, 1 },
	{ 0, 0, 2 },
	{ 0, -43, 20 },
	{ 0, -43, 11 },
	{ 0, -39, 19 },
	{ 0, 65, 20 },
	{ 0, 66, 18 },
	{ 43, 0, 13 },
	{ 43, -107, 13 },
	{ 43, -91, 13 },
	{ 43, -92, 13 },
	{ 43, -87, 13 },
	{ 43, -83, 13 },
	{ 0, 0, 17 },
	{ 0, -20, 0 },
	{ 0, 0, 14 },
	{ 0, 0, 16 },
	{ 0, 0, 15 },
	{ 43, 0, 8 },
	{ 43, -89, 13 },
	{ 43, -73, 13 },
	{ 43, -75, 13 },
	{ 43, -51, 7 },
	{ 43, -65, 13 },
	{ 43, -50, 13 },
	{ 0, 0, 12 },
	{ 43, -45, 13 },
	{ 43, -14, 13 },
	{ 43, 0, 5 },
	{ 43, -24, 13 },
	{ 43, 0, 3 },
	{ 43, -23, 13 },
	{ 43, 0, 9 },
	{ 43, -30, 13 },
	{ 43, -28, 13 },
	{ 43, -13, 13 },
	{ 43, 0, 4 },
	{ 43, 24, 13 },
	{ 43, 0, 6 },
	{ 0, 67, 10 },
	{ 0, 23, 20 },
	{ 0, 19, 0 },
	{ 0, 31, 0 },
	{ 0, 23, 0 },
	{ 0, 41, 0 },
	{ 0, 59, 0 },
	{ 0, 59, 0 },
	{ 0, 129, 0 },
	{ 53, 0, 0 },
	{ -53, 152, 21 }
};

YYCONST yybackup_t YYNEARFAR YYBASED_CODE YYDCDECL yybackup[] = {
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	0
};

#line 36 ".\\Mini-C.l"



int yywrap (void) {return 1;}
