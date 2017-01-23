%{
	#include <string.h>
	#include "Mini-C-yacc.h"
%}

alpha [a-zA-Z]
digit [0-9]

%%


[ \t]							;
[ \n]							{ yylineno = yylineno + 1;}
int								return INT;
float							return FLOAT;
for								return FOR;
while							return WHILE;
if								return IF;
do								return DO;
else							return ELSE;
ifelse							return IFELSE;
{digit}+						{yylval.Quadruplet.IntegerValue=atoi(yytext);yylval.Quadruplet.index=0;return NUMBER ;}
{digit}+(\.{digit})				{yylval.Quadruplet.FloatValue=atof(yytext);yylval.Quadruplet.index=1;return NUMBER ;}
{alpha}({alpha}|{digit})*		{yylval.Quadruplet.index=2;strcpy(yylval.Quadruplet.idval,yytext);return IDENTIFIER;}
"<="							return LE;
">="							return GE;
"=="							return EQ;
"!="							return NE;
">"								return GT;
"<"								return LT;
								;
.								return yytext[0];
^"#include ".+					;


%%


int yywrap (void) {return 1;}