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
* Mini-C-yacc.c
* C source file generated from Mini-C-yacc.y.
* 
* Date: 01/22/17
* Time: 10:30:59
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#line 1 ".\\Mini-C-yacc.y"

	void yyerror (char *s);
	#include <stdio.h>   
	#include <stdlib.h>
	
	void GenererQuadruplet(char CodeOp[50],char source1[50],char source2[50],char destination[50]);
	
	FILE *yyin, *f;
	
	int quadCourant =0,
		i = 0,
		tmp1 = 0,
		tmp2 = 0,
		b = 0,
		cpt =0,
		cpt_tmp=1,
		esp1 = 0,
		esp2 = 0,
		pile[100],
		l = 1;
	
	char buf[50],
		 buf1[50],
		 buf2[50],
		 buf3[50],
		 tmp_tab[50],
		 buffer[20],
		 tmp[20];
	
	typedef struct Quad {
		char op[50];
		char src1[50];
		char src2[50];
		char dest[50];
	}Quad;	
	
	
	Quad tmpQuad;
	Quad quad[100];
	Quad pileQuad[100];
	
	void empilerQuad(Quad tab[] ,Quad val,int* ptr){
		*ptr = *ptr + 1;
		strcpy(tab[*ptr].op , val.op );
		strcpy(tab[*ptr].src1 ,val.src1) ;
		strcpy(tab[*ptr].src2 , val.src2); 
		strcpy(tab[*ptr].dest , val.dest) ;
	}
	
	Quad depilerQuad (Quad tab[] ,int *ptr){
		Quad quad = tab[*ptr];
		*ptr = *ptr - 1;
		return quad;
	}
	
	void empiler(int tab[] ,int val,int* ptr){
		*ptr = *ptr + 1;
		tab[*ptr] = val ;
	}
	
	int depiler (int tab[] ,int *ptr){
		int val = tab[*ptr];
		*ptr = *ptr - 1;
		return val;
	}
	


#line 109 "Mini-C-yacc.c"
/* repeated because of possible precompiled header */
#include <yypars.h>

/* namespaces */
#if defined(__cplusplus) && defined(YYSTDCPPLIB)
using namespace std;
#endif
#if defined(__cplusplus) && defined(YYNAMESPACE)
using namespace yl;
#endif

#define YYFASTPARSER

#include ".\Mini-C-yacc.h"

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/* (state) stack */
#if (YYSTACK_SIZE) != 0
static yystack_t YYNEAR yystack[(YYSTACK_SIZE)];
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = yystack;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = yystack;
#else
yystack_t YYFAR *YYNEAR YYDCDECL yysstackptr = NULL;
yystack_t YYFAR *YYNEAR YYDCDECL yystackptr = NULL;
#endif

/* attribute stack */
#if (YYSTACK_SIZE) != 0
static YYSTYPE YYNEAR yyattributestack[(YYSTACK_SIZE)];
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = yyattributestack;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = yyattributestack;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = (char YYFAR *) yyattributestack;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = (char YYFAR *) yyattributestack;
#endif
#else
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
void YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#else
char YYFAR *YYNEAR YYDCDECL yysattributestackptr = NULL;
char YYFAR *YYNEAR YYDCDECL yyattributestackptr = NULL;
#endif
#endif

int YYNEAR YYDCDECL yysstack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_size = (YYSTACK_SIZE);
int YYNEAR YYDCDECL yystack_max = (YYSTACK_MAX);

/* attributes */
YYSTYPE YYNEAR yyval;
YYSTYPE YYNEAR yylval;
#ifdef YYPROTOTYPE
void YYFAR *YYNEAR YYDCDECL yyvalptr = &yyval;
void YYFAR *YYNEAR YYDCDECL yylvalptr = &yylval;
#else
char YYFAR *YYNEAR YYDCDECL yyvalptr = (char *) &yyval;
char YYFAR *YYNEAR YYDCDECL yylvalptr = (char *) &yylval;
#endif

size_t YYNEAR YYDCDECL yyattribute_size = sizeof(YYSTYPE);

/* yyattribute */
#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static YYSTYPE YYFAR *yyattribute1(int index)
#else
static YYSTYPE YYFAR *yyattribute1(index)
int index;
#endif
{
	YYSTYPE YYFAR *p = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR *) yyattributestackptr)[yytop + (index)])
#endif

#ifdef YYDEBUG
#ifdef YYPROTOTYPE
static void yyinitdebug(YYSTYPE YYFAR **p, int count)
#else
static void yyinitdebug(p, count)
YYSTYPE YYFAR **p;
int count;
#endif
{
	int i;
	yyassert(p != NULL);
	yyassert(count >= 1);

	for (i = 0; i < count; i++) {
		p[i] = &((YYSTYPE YYFAR *) yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

#ifdef YYPROTOTYPE
void YYCDECL yyparseraction(int action)
#else
void YYCDECL yyparseraction(action)
int action;
#endif
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 117 ".\\Mini-C-yacc.y"
yyval.Quadruplet.index=0;
#line 235 "Mini-C-yacc.c"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 118 ".\\Mini-C-yacc.y"
yyval.Quadruplet.index=1;
#line 248 "Mini-C-yacc.c"
			}
		}
		break;
	case 2:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 137 ".\\Mini-C-yacc.y"
tmp1 = depiler(pile,&esp1);  // @ de DO_WHILE1
													itoa(tmp1,buffer,10);
													GenererQuadruplet("JZ","","",buffer);
													
#line 264 "Mini-C-yacc.c"
			}
		}
		break;
	case 3:
		{
#line 143 ".\\Mini-C-yacc.y"
empiler(pile,quadCourant,&esp1);
#line 272 "Mini-C-yacc.c"
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[14];
			yyinitdebug(yya, 14);
#endif
			{
#line 146 ".\\Mini-C-yacc.y"

												for(tmp1 = 0 ; tmp1 < cpt ; tmp1++){
													tmpQuad = depilerQuad(pileQuad,&esp2);
													strcpy(quad[quadCourant+cpt-tmp1-l].op,tmpQuad.op);
													strcpy(quad[quadCourant+cpt-tmp1-l].src1,tmpQuad.src1);
													strcpy(quad[quadCourant+cpt-tmp1-l].src2,tmpQuad.src2);
													strcpy(quad[quadCourant+cpt-tmp1-l].dest,tmpQuad.dest);
													quadCourant++;l++;
												}
												cpt = 0; l = 1;
												tmp1 = depiler(pile,&esp1);  // @ de JZ
												tmp2 = depiler(pile,&esp1);  // @ avant la condition 'FOR1'
												itoa(tmp2,buffer,10);
												GenererQuadruplet("JUMP","","",buffer);
												itoa(quadCourant,buffer,10);
												strcpy(quad[tmp1].dest,buffer);
#line 299 "Mini-C-yacc.c"
			}
		}
		break;
	case 5:
		{
#line 164 ".\\Mini-C-yacc.y"
empiler(pile,quadCourant,&esp1);
#line 307 "Mini-C-yacc.c"
		}
		break;
	case 6:
		{
#line 168 ".\\Mini-C-yacc.y"
empiler(pile,quadCourant,&esp1);
		GenererQuadruplet("JZ","","","");
#line 315 "Mini-C-yacc.c"
		}
		break;
	case 7:
		{
#line 172 ".\\Mini-C-yacc.y"
 b=1;
#line 322 "Mini-C-yacc.c"
		}
		break;
	case 8:
		{
#line 176 ".\\Mini-C-yacc.y"
b=0;
#line 329 "Mini-C-yacc.c"
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 185 ".\\Mini-C-yacc.y"
 tmp1 = depiler(pile,&esp1);  // @ de JZ
													tmp2 = depiler(pile,&esp1);  // @ avant la condition 'WHILE1'
													itoa(tmp2,buffer,10);
													GenererQuadruplet("JUMP","","",buffer);
													itoa(quadCourant,buffer,10);
													strcpy(quad[tmp1].dest,buffer);
												  
#line 347 "Mini-C-yacc.c"
			}
		}
		break;
	case 10:
		{
#line 194 ".\\Mini-C-yacc.y"
empiler(pile,quadCourant,&esp1);
#line 355 "Mini-C-yacc.c"
		}
		break;
	case 11:
		{
#line 197 ".\\Mini-C-yacc.y"
 empiler(pile,quadCourant,&esp1);
		   GenererQuadruplet("JZ","","","");
#line 363 "Mini-C-yacc.c"
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[8];
			yyinitdebug(yya, 8);
#endif
			{
#line 201 ".\\Mini-C-yacc.y"
 tmp1 = depiler(pile,&esp1);
												itoa(quadCourant,buffer,10);
												strcpy(quad[tmp1].dest,buffer);
#line 377 "Mini-C-yacc.c"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[12];
			yyinitdebug(yya, 12);
#endif
			{
#line 210 ".\\Mini-C-yacc.y"

																			tmp1 = depiler(pile,&esp1);
																			itoa(quadCourant,buffer,10);
																			strcpy(quad[tmp1].dest,buffer);
																		
#line 394 "Mini-C-yacc.c"
			}
		}
		break;
	case 14:
		{
#line 218 ".\\Mini-C-yacc.y"
 empiler(pile,quadCourant,&esp1);
			GenererQuadruplet("JZ","\0","\0","\0");
#line 403 "Mini-C-yacc.c"
		}
		break;
	case 15:
		{
#line 222 ".\\Mini-C-yacc.y"
 empiler(pile,quadCourant,&esp1);
			GenererQuadruplet("JUMP","\0","\0","\0");
#line 411 "Mini-C-yacc.c"
		}
		break;
	case 16:
		{
#line 226 ".\\Mini-C-yacc.y"
 tmp1 = depiler(pile,&esp1);
			tmp2 = depiler(pile,&esp1);
			empiler(pile,tmp1,&esp1);
			itoa(quadCourant,buffer,10);
			strcpy(quad[tmp2].dest,buffer);
#line 422 "Mini-C-yacc.c"
		}
		break;
	case 17:
		{
#line 234 ".\\Mini-C-yacc.y"
	empiler(pile,quadCourant,&esp1);
		GenererQuadruplet("JZ","","","");
#line 430 "Mini-C-yacc.c"
		}
		break;
	case 18:
		{
#line 238 ".\\Mini-C-yacc.y"
 tmp1 = depiler(pile,&esp1);
		itoa(quadCourant+1,buffer,10);
		strcpy(quad[tmp1].dest,buffer);
		empiler(pile,quadCourant,&esp1);
		GenererQuadruplet("JUMP","","","");
#line 441 "Mini-C-yacc.c"
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[1];
			yyinitdebug(yya, 1);
#endif
			{
#line 245 ".\\Mini-C-yacc.y"
	tmp1 = depiler(pile,&esp1);
		itoa(quadCourant,buffer,10);
		strcpy(quad[tmp1].dest,buffer);
#line 455 "Mini-C-yacc.c"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 253 ".\\Mini-C-yacc.y"
yyval=yyattribute(2 - 3);
#line 468 "Mini-C-yacc.c"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 260 ".\\Mini-C-yacc.y"


			switch(yyattribute(3 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",yyattribute(3 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",yyattribute(3 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",yyattribute(3 - 3).Quadruplet.idval);
					break;
				}
				default: {
					sprintf(buf,"%s%d","tmp",yyattribute(3 - 3).Quadruplet.val);
					break;
				}
			}

			if(b==0){
				GenererQuadruplet("=",buf,"\0",yyattribute(1 - 3).Quadruplet.idval);
			}
			else{
				strcpy(tmpQuad.op,"="); 
				strcpy(tmpQuad.src1,buf);
				strcpy(tmpQuad.src2,"\0");
				strcpy(tmpQuad.dest,yyattribute(1 - 3).Quadruplet.idval); 
				empilerQuad(pileQuad,tmpQuad,&esp2);
				cpt++;
			}
			yyval=yyattribute(3 - 3);
		
#line 514 "Mini-C-yacc.c"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 294 ".\\Mini-C-yacc.y"
yyval=yyattribute(1 - 1);
#line 527 "Mini-C-yacc.c"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 297 ".\\Mini-C-yacc.y"
	
				
			switch(yyattribute(1 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",yyattribute(1 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",yyattribute(1 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",yyattribute(1 - 3).Quadruplet.idval);
					break;
				}
			}
			
			switch(yyattribute(3 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",yyattribute(3 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",yyattribute(3 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",yyattribute(3 - 3).Quadruplet.idval);
					break;
				}
			}
				
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf(yyval.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			yyval.Quadruplet.val=cpt_tmp;
			
			if(b==0){
				
				GenererQuadruplet("CMP",buf,buf1,"\0");

				sprintf(buf3,"%d",quadCourant+3);
				
				switch(yyattribute(2 - 3).Quadruplet.idval[0]){
					case '>' : strcpy(tmp,"JG");	break;
					case '<' : strcpy(tmp,"JL");	break;
				}
				if(strcmp("eq",yyattribute(2 - 3).Quadruplet.idval)==0){strcpy(tmp,"JZ");}
				if(strcmp("le",yyattribute(2 - 3).Quadruplet.idval)==0){strcpy(tmp,"JLE");}
				if(strcmp("ge",yyattribute(2 - 3).Quadruplet.idval)==0){strcpy(tmp,"JGE");}
				if(strcmp("ne",yyattribute(2 - 3).Quadruplet.idval)==0){strcpy(tmp,"JNZ");}
				
				GenererQuadruplet(tmp,"\0","\0",buf3);
				
				GenererQuadruplet("=","0","\0",buf2);
				
				sprintf(buf3,"%d",quadCourant+2);
				
				
				GenererQuadruplet("JUMP","\0","\0",buf3);
				
				GenererQuadruplet("=","1","\0",buf2);

			} else{
				cpt+=5;
				
				strcpy(tmpQuad.op,"CMP"); 
				strcpy(tmpQuad.src1,buf);
				strcpy(tmpQuad.src2,buf1);
				strcpy(tmpQuad.dest,"\0"); 
				quadCourant++;
				
				empilerQuad(pileQuad,tmpQuad,&esp2);
				
				sprintf(buf3,"%d",quadCourant+3);
								
				switch(yyattribute(2 - 3).Quadruplet.idval[0]){
					case '>' : strcpy(tmpQuad.op,"JG");	break;
					case '<' : strcpy(tmpQuad.op,"JL");	break;
				}
				
				if(strcmp("eq",yyattribute(2 - 3).Quadruplet.idval)==0){strcpy(tmpQuad.op,"JZ");}
				if(strcmp("le",yyattribute(2 - 3).Quadruplet.idval)==0){strcpy(tmpQuad.op,"JLE");}
				if(strcmp("ge",yyattribute(2 - 3).Quadruplet.idval)==0){strcpy(tmpQuad.op,"JGE");}
				if(strcmp("ne",yyattribute(2 - 3).Quadruplet.idval)==0){strcpy(tmpQuad.op,"JNZ");}
				strcpy(tmpQuad.src1,"\0");
				strcpy(tmpQuad.src2,"\0");
				strcpy(tmpQuad.dest,buf3); 
				quadCourant++;
				empilerQuad(pileQuad,tmpQuad,&esp2);
				
				strcpy(tmpQuad.op,"="); 
				strcpy(tmpQuad.src1,"0");
				strcpy(tmpQuad.src2,"\0");
				strcpy(tmpQuad.dest,buf2); 
				quadCourant++;
				empilerQuad(pileQuad,tmpQuad,&esp2);
				
				sprintf(buf3,"%d",quadCourant+2);
				strcpy(tmpQuad.op,"JUMP"); 
				strcpy(tmpQuad.src1,"\0");
				strcpy(tmpQuad.src2,"\0");
				strcpy(tmpQuad.dest,buf3); 
				quadCourant++;
				empilerQuad(pileQuad,tmpQuad,&esp2);
				
				strcpy(tmpQuad.op,"="); 
				strcpy(tmpQuad.src1,"1");
				strcpy(tmpQuad.src2,"\0");
				strcpy(tmpQuad.dest,buf2); 
				quadCourant++;
				empilerQuad(pileQuad,tmpQuad,&esp2);
			}
		
#line 653 "Mini-C-yacc.c"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 411 ".\\Mini-C-yacc.y"
yyval=yyattribute(1 - 1);
#line 666 "Mini-C-yacc.c"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 414 ".\\Mini-C-yacc.y"
sprintf(yyval.Quadruplet.idval,"eq");
#line 679 "Mini-C-yacc.c"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 415 ".\\Mini-C-yacc.y"
sprintf(yyval.Quadruplet.idval,">");
#line 692 "Mini-C-yacc.c"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 416 ".\\Mini-C-yacc.y"
sprintf(yyval.Quadruplet.idval,"<");
#line 705 "Mini-C-yacc.c"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 417 ".\\Mini-C-yacc.y"
sprintf(yyval.Quadruplet.idval,"le");
#line 718 "Mini-C-yacc.c"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 418 ".\\Mini-C-yacc.y"
sprintf(yyval.Quadruplet.idval,"ge");
#line 731 "Mini-C-yacc.c"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 419 ".\\Mini-C-yacc.y"
sprintf(yyval.Quadruplet.idval,"ne");
#line 744 "Mini-C-yacc.c"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 422 ".\\Mini-C-yacc.y"

			switch(yyattribute(1 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",yyattribute(1 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",yyattribute(1 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",yyattribute(1 - 3).Quadruplet.idval);
					break;
				}
			}
			switch(yyattribute(3 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",yyattribute(3 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",yyattribute(3 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",yyattribute(3 - 3).Quadruplet.idval);
					break;
				}
			}
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf(yyval.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			yyval.Quadruplet.val=cpt_tmp;
			cpt_tmp++;
			yyval.Quadruplet.index=2;
			
			if(b==0){
				GenererQuadruplet("+",buf,buf1,buf2);
			}else{
				strcpy(tmpQuad.op,"+"); 
				strcpy(tmpQuad.src1,buf);
				strcpy(tmpQuad.src2,buf1);
				strcpy(tmpQuad.dest,buf2); 
				empilerQuad(pileQuad,tmpQuad,&esp2);
				cpt++;
			}
		
#line 802 "Mini-C-yacc.c"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 468 ".\\Mini-C-yacc.y"

			switch(yyattribute(1 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",yyattribute(1 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",yyattribute(1 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",yyattribute(1 - 3).Quadruplet.idval);
					break;
				}
			}
			switch(yyattribute(3 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",yyattribute(3 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",yyattribute(3 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",yyattribute(3 - 3).Quadruplet.idval);
					break;
				}
			}
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf(yyval.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			yyval.Quadruplet.val=cpt_tmp;
			cpt_tmp++;
			yyval.Quadruplet.index=2;
			
			if(b==0){
				GenererQuadruplet("-",buf,buf1,buf2);
			}else{
				strcpy(tmpQuad.op,"-"); 
				strcpy(tmpQuad.src1,buf);
				strcpy(tmpQuad.src2,buf1);
				strcpy(tmpQuad.dest,buf2); 
				empilerQuad(pileQuad,tmpQuad,&esp2);
				cpt++;
			}
		
#line 860 "Mini-C-yacc.c"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 514 ".\\Mini-C-yacc.y"
yyval=yyattribute(1 - 1);
#line 873 "Mini-C-yacc.c"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 517 ".\\Mini-C-yacc.y"

			switch(yyattribute(1 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",yyattribute(1 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",yyattribute(1 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",yyattribute(1 - 3).Quadruplet.idval);
					break;
				}
			}
			switch(yyattribute(3 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",yyattribute(3 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",yyattribute(3 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",yyattribute(3 - 3).Quadruplet.idval);
					break;
				}
			}
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf(yyval.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			yyval.Quadruplet.val=cpt_tmp;
			cpt_tmp++;
			yyval.Quadruplet.index=2;
			
			if(b==0){
				GenererQuadruplet("*",buf,buf1,buf2);
			}else{
				strcpy(tmpQuad.op,"*"); 
				strcpy(tmpQuad.src1,buf);
				strcpy(tmpQuad.src2,buf1);
				strcpy(tmpQuad.dest,buf2); 
				empilerQuad(pileQuad,tmpQuad,&esp2);
				cpt++;
			}
		
#line 931 "Mini-C-yacc.c"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 563 ".\\Mini-C-yacc.y"

			switch(yyattribute(1 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",yyattribute(1 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",yyattribute(1 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",yyattribute(1 - 3).Quadruplet.idval);
					break;
				}
			}
			switch(yyattribute(3 - 3).Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",yyattribute(3 - 3).Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",yyattribute(3 - 3).Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",yyattribute(3 - 3).Quadruplet.idval);
					break;
				}
			}
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf(yyval.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			yyval.Quadruplet.val=cpt_tmp;
			cpt_tmp++;
			yyval.Quadruplet.index=2;
			
			if(b==0){
				GenererQuadruplet("/",buf,buf1,buf2);
			}else{
				strcpy(tmpQuad.op,"/"); 
				strcpy(tmpQuad.src1,buf);
				strcpy(tmpQuad.src2,buf1);
				strcpy(tmpQuad.dest,buf2); 
				empilerQuad(pileQuad,tmpQuad,&esp2);
				cpt++;
			}
		
#line 989 "Mini-C-yacc.c"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 609 ".\\Mini-C-yacc.y"
	yyval=yyattribute(1 - 1);
#line 1002 "Mini-C-yacc.c"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[4];
			yyinitdebug(yya, 4);
#endif
			{
#line 612 ".\\Mini-C-yacc.y"
yyval=yyattribute(2 - 3);
#line 1015 "Mini-C-yacc.c"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 613 ".\\Mini-C-yacc.y"
	
						switch(yyattribute(2 - 2).Quadruplet.index){
							case 0 : {
								yyval.Quadruplet.IntegerValue =-yyattribute(2 - 2).Quadruplet.IntegerValue;
								yyval.Quadruplet.index=0;
								break;
							}
							case 1 : {
								yyval.Quadruplet.FloatValue=-yyattribute(2 - 2).Quadruplet.FloatValue;
								yyval.Quadruplet.index=1;
								break;
							}
							default : {
								strcpy(buf,"-");
								strcat(buf,yyattribute(2 - 2).Quadruplet.idval);
								strcpy(yyval.Quadruplet.idval,buf);
								yyval.Quadruplet.index=2;
								break;
							}
						}
		
#line 1048 "Mini-C-yacc.c"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[3];
			yyinitdebug(yya, 3);
#endif
			{
#line 634 ".\\Mini-C-yacc.y"
yyval=yyattribute(2 - 2);
#line 1061 "Mini-C-yacc.c"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 635 ".\\Mini-C-yacc.y"
	
									if(yyattribute(1 - 1).Quadruplet.index == 2) {
										strcpy(yyval.Quadruplet.idval,yyattribute(1 - 1).Quadruplet.idval);
										yyval.Quadruplet.index=2;
									}
								
#line 1079 "Mini-C-yacc.c"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR *yya[2];
			yyinitdebug(yya, 2);
#endif
			{
#line 641 ".\\Mini-C-yacc.y"
	
						switch(yyattribute(1 - 1).Quadruplet.index){
							case 0 : {
								yyval.Quadruplet.IntegerValue = yyattribute(1 - 1).Quadruplet.IntegerValue;
								yyval.Quadruplet.index=0;
								break;
							}
							case 1 : {
								yyval.Quadruplet.FloatValue=yyattribute(1 - 1).Quadruplet.FloatValue;
								yyval.Quadruplet.index=1;
								break;
							}
						}		
					
#line 1105 "Mini-C-yacc.c"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}
#ifdef YYDEBUG
YYCONST yysymbol_t YYNEARFAR YYBASED_CODE YYDCDECL yysymbol[] = {
	{ "$end", 0 },
	{ "\'(\'", 40 },
	{ "\')\'", 41 },
	{ "\'*\'", 42 },
	{ "\'+\'", 43 },
	{ "\',\'", 44 },
	{ "\'-\'", 45 },
	{ "\'/\'", 47 },
	{ "\';\'", 59 },
	{ "\'=\'", 61 },
	{ "\'{\'", 123 },
	{ "\'}\'", 125 },
	{ "error", 256 },
	{ "NUMBER", 257 },
	{ "IDENTIFIER", 258 },
	{ "INT", 259 },
	{ "FLOAT", 260 },
	{ "FOR", 261 },
	{ "WHILE", 262 },
	{ "DO", 263 },
	{ "IF", 264 },
	{ "ELSE", 265 },
	{ "IFELSE", 266 },
	{ "moins_unitaire", 267 },
	{ "plus_unitaire", 268 },
	{ "LE", 269 },
	{ "GE", 270 },
	{ "EQ", 271 },
	{ "NE", 272 },
	{ "LT", 273 },
	{ "GT", 274 },
	{ NULL, 0 }
};

YYCONST char *YYCONST YYNEARFAR YYBASED_CODE YYDCDECL yyrule[] = {
	"$accept: Function",
	"Function: Type IDENTIFIER \'(\' ArgList \')\' CompoundStmt",
	"ArgList: Arg",
	"ArgList: ArgList \',\' Arg",
	"ArgList:",
	"Arg: Type IDENTIFIER",
	"Declaration: Type IdentList \';\'",
	"Type: INT",
	"Type: FLOAT",
	"IdentList: IDENTIFIER \',\' IdentList",
	"IdentList: IDENTIFIER",
	"Stmt: ForStmt",
	"Stmt: WhileStmt",
	"Stmt: Expr \';\'",
	"Stmt: IfStmt",
	"Stmt: CompoundStmt",
	"Stmt: Declaration",
	"Stmt: DoWhileStmt \';\'",
	"Stmt: IfElseStmt",
	"Stmt: \';\'",
	"DoWhileStmt: DO DO_WHILE1 Stmt WHILE \'(\' Expr \')\'",
	"DO_WHILE1:",
	"ForStmt: FOR \'(\' Expr \';\' FOR1 OptExpr FOR2 \';\' FOR3 OptExpr FOR4 \')\' Stmt",
	"FOR1:",
	"FOR2:",
	"FOR3:",
	"FOR4:",
	"OptExpr: Expr",
	"OptExpr:",
	"WhileStmt: WHILE \'(\' WHILE1 Expr WHILE2 \')\' Stmt",
	"WHILE1:",
	"WHILE2:",
	"IfStmt: IF \'(\' Expr \')\' IF1 Stmt ElsePart",
	"ElsePart: ELSE IF2 Stmt",
	"ElsePart: IF3",
	"IfElseStmt: IFELSE \'(\' Expr IFELSE1 \';\' Stmt IFELSE2 \';\' IFELSE3 Stmt \')\'",
	"IFELSE1:",
	"IFELSE2:",
	"IFELSE3:",
	"IF1:",
	"IF2:",
	"IF3:",
	"CompoundStmt: \'{\' StmtList \'}\'",
	"StmtList: StmtList Stmt",
	"StmtList:",
	"Expr: IDENTIFIER \'=\' Expr",
	"Expr: Rvalue",
	"Rvalue: Rvalue Compare Mag",
	"Rvalue: Mag",
	"Compare: EQ",
	"Compare: GT",
	"Compare: LT",
	"Compare: LE",
	"Compare: GE",
	"Compare: NE",
	"Mag: Mag \'+\' Term",
	"Mag: Mag \'-\' Term",
	"Mag: Term",
	"Term: Term \'*\' Factor",
	"Term: Term \'/\' Factor",
	"Term: Factor",
	"Factor: \'(\' Expr \')\'",
	"Factor: \'-\' Factor",
	"Factor: \'+\' Factor",
	"Factor: IDENTIFIER",
	"Factor: NUMBER"
};
#endif

YYCONST yyreduction_t YYNEARFAR YYBASED_CODE YYDCDECL yyreduction[] = {
	{ 0, 1, -1 },
	{ 1, 6, -1 },
	{ 2, 1, -1 },
	{ 2, 3, -1 },
	{ 2, 0, -1 },
	{ 3, 2, -1 },
	{ 4, 3, -1 },
	{ 5, 1, 0 },
	{ 5, 1, 1 },
	{ 6, 3, -1 },
	{ 6, 1, -1 },
	{ 7, 1, -1 },
	{ 7, 1, -1 },
	{ 7, 2, -1 },
	{ 7, 1, -1 },
	{ 7, 1, -1 },
	{ 7, 1, -1 },
	{ 7, 2, -1 },
	{ 7, 1, -1 },
	{ 7, 1, -1 },
	{ 8, 7, 2 },
	{ 9, 0, 3 },
	{ 10, 13, 4 },
	{ 11, 0, 5 },
	{ 12, 0, 6 },
	{ 13, 0, 7 },
	{ 14, 0, 8 },
	{ 15, 1, -1 },
	{ 15, 0, -1 },
	{ 16, 7, 9 },
	{ 17, 0, 10 },
	{ 18, 0, 11 },
	{ 19, 7, 12 },
	{ 20, 3, -1 },
	{ 20, 1, -1 },
	{ 21, 11, 13 },
	{ 22, 0, 14 },
	{ 23, 0, 15 },
	{ 24, 0, 16 },
	{ 25, 0, 17 },
	{ 26, 0, 18 },
	{ 27, 0, 19 },
	{ 28, 3, 20 },
	{ 29, 2, -1 },
	{ 29, 0, -1 },
	{ 30, 3, 21 },
	{ 30, 1, 22 },
	{ 31, 3, 23 },
	{ 31, 1, 24 },
	{ 32, 1, 25 },
	{ 32, 1, 26 },
	{ 32, 1, 27 },
	{ 32, 1, 28 },
	{ 32, 1, 29 },
	{ 32, 1, 30 },
	{ 33, 3, 31 },
	{ 33, 3, 32 },
	{ 33, 1, 33 },
	{ 34, 3, 34 },
	{ 34, 3, 35 },
	{ 34, 1, 36 },
	{ 35, 3, 37 },
	{ 35, 2, 38 },
	{ 35, 2, 39 },
	{ 35, 1, 40 },
	{ 35, 1, 41 }
};

int YYNEAR YYDCDECL yytokenaction_size = 228;
YYCONST yytokenaction_t YYNEARFAR YYBASED_CODE YYDCDECL yytokenaction[] = {
	{ 116, YYAT_SHIFT, 20 },
	{ 109, YYAT_SHIFT, 17 },
	{ 79, YYAT_SHIFT, 66 },
	{ 114, YYAT_SHIFT, 116 },
	{ 109, YYAT_SHIFT, 18 },
	{ 90, YYAT_SHIFT, 17 },
	{ 109, YYAT_SHIFT, 19 },
	{ 79, YYAT_SHIFT, 67 },
	{ 90, YYAT_SHIFT, 18 },
	{ 88, YYAT_SHIFT, 17 },
	{ 90, YYAT_SHIFT, 19 },
	{ 77, YYAT_SHIFT, 64 },
	{ 88, YYAT_SHIFT, 18 },
	{ 77, YYAT_SHIFT, 65 },
	{ 88, YYAT_SHIFT, 19 },
	{ 39, YYAT_SHIFT, 57 },
	{ 39, YYAT_SHIFT, 58 },
	{ 39, YYAT_SHIFT, 59 },
	{ 39, YYAT_SHIFT, 60 },
	{ 39, YYAT_SHIFT, 61 },
	{ 39, YYAT_SHIFT, 62 },
	{ 78, YYAT_SHIFT, 66 },
	{ 41, YYAT_SHIFT, 66 },
	{ 11, YYAT_SHIFT, 1 },
	{ 11, YYAT_SHIFT, 2 },
	{ 7, YYAT_SHIFT, 10 },
	{ 78, YYAT_SHIFT, 67 },
	{ 41, YYAT_SHIFT, 67 },
	{ 7, YYAT_SHIFT, 11 },
	{ 40, YYAT_SHIFT, 64 },
	{ 113, YYAT_SHIFT, 115 },
	{ 40, YYAT_SHIFT, 65 },
	{ 6, YYAT_SHIFT, 1 },
	{ 6, YYAT_SHIFT, 2 },
	{ 105, YYAT_SHIFT, 108 },
	{ 99, YYAT_SHIFT, 106 },
	{ 97, YYAT_SHIFT, 102 },
	{ 96, YYAT_SHIFT, 101 },
	{ 89, YYAT_SHIFT, 95 },
	{ 86, YYAT_SHIFT, 92 },
	{ 84, YYAT_SHIFT, 90 },
	{ 75, YYAT_SHIFT, 53 },
	{ 73, YYAT_SHIFT, 85 },
	{ 72, YYAT_SHIFT, 84 },
	{ 70, YYAT_SHIFT, 82 },
	{ 67, YYAT_SHIFT, 44 },
	{ 54, YYAT_SHIFT, 76 },
	{ 53, YYAT_SHIFT, 75 },
	{ 43, YYAT_SHIFT, 68 },
	{ 37, YYAT_SHIFT, 56 },
	{ 34, YYAT_SHIFT, 55 },
	{ 28, YYAT_SHIFT, 52 },
	{ 27, YYAT_SHIFT, 51 },
	{ 25, YYAT_SHIFT, 49 },
	{ 24, YYAT_SHIFT, 48 },
	{ 23, YYAT_SHIFT, 47 },
	{ 16, YYAT_SHIFT, 21 },
	{ 10, YYAT_SHIFT, 13 },
	{ 9, YYAT_SHIFT, 12 },
	{ 5, YYAT_SHIFT, 6 },
	{ 4, YYAT_ACCEPT, 0 },
	{ 3, YYAT_SHIFT, 5 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 116, YYAT_SHIFT, 13 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 116, YYAT_SHIFT, 1 },
	{ 116, YYAT_SHIFT, 2 },
	{ 116, YYAT_SHIFT, 24 },
	{ 116, YYAT_SHIFT, 25 },
	{ 116, YYAT_SHIFT, 26 },
	{ 116, YYAT_SHIFT, 27 },
	{ -1, YYAT_ERROR, 0 },
	{ 116, YYAT_SHIFT, 28 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 109, YYAT_SHIFT, 22 },
	{ 109, YYAT_SHIFT, 23 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 90, YYAT_SHIFT, 22 },
	{ 90, YYAT_SHIFT, 23 },
	{ -1, YYAT_ERROR, 0 },
	{ -1, YYAT_ERROR, 0 },
	{ 88, YYAT_SHIFT, 22 },
	{ 88, YYAT_SHIFT, 23 }
};

YYCONST yystateaction_t YYNEARFAR YYBASED_CODE YYDCDECL yystateaction[] = {
	{ 0, 0, YYAT_DEFAULT, 11 },
	{ 0, 0, YYAT_REDUCE, 7 },
	{ 0, 0, YYAT_REDUCE, 8 },
	{ -197, 1, YYAT_ERROR, 0 },
	{ 60, 1, YYAT_ERROR, 0 },
	{ 19, 1, YYAT_ERROR, 0 },
	{ -227, 1, YYAT_REDUCE, 4 },
	{ -16, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 2 },
	{ -200, 1, YYAT_ERROR, 0 },
	{ -66, 1, YYAT_ERROR, 0 },
	{ -236, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 5 },
	{ 0, 0, YYAT_REDUCE, 44 },
	{ 0, 0, YYAT_REDUCE, 1 },
	{ 0, 0, YYAT_REDUCE, 3 },
	{ -69, 1, YYAT_DEFAULT, 116 },
	{ 0, 0, YYAT_DEFAULT, 90 },
	{ 0, 0, YYAT_DEFAULT, 67 },
	{ 0, 0, YYAT_DEFAULT, 67 },
	{ 0, 0, YYAT_REDUCE, 19 },
	{ 0, 0, YYAT_REDUCE, 42 },
	{ 0, 0, YYAT_REDUCE, 65 },
	{ -6, 1, YYAT_REDUCE, 64 },
	{ 14, 1, YYAT_ERROR, 0 },
	{ 13, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 21 },
	{ 12, 1, YYAT_ERROR, 0 },
	{ 11, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 16 },
	{ 0, 0, YYAT_REDUCE, 43 },
	{ 0, 0, YYAT_REDUCE, 11 },
	{ 0, 0, YYAT_REDUCE, 15 },
	{ 0, 0, YYAT_DEFAULT, 75 },
	{ -9, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 14 },
	{ 0, 0, YYAT_REDUCE, 12 },
	{ -10, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 18 },
	{ -254, 1, YYAT_REDUCE, 46 },
	{ -14, 1, YYAT_REDUCE, 48 },
	{ -20, 1, YYAT_REDUCE, 57 },
	{ 0, 0, YYAT_REDUCE, 60 },
	{ 7, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 64 },
	{ 0, 0, YYAT_REDUCE, 63 },
	{ 0, 0, YYAT_REDUCE, 62 },
	{ 0, 0, YYAT_DEFAULT, 90 },
	{ 0, 0, YYAT_DEFAULT, 90 },
	{ 0, 0, YYAT_REDUCE, 30 },
	{ 0, 0, YYAT_DEFAULT, 116 },
	{ 0, 0, YYAT_DEFAULT, 90 },
	{ 0, 0, YYAT_DEFAULT, 90 },
	{ 3, 1, YYAT_REDUCE, 10 },
	{ -13, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 13 },
	{ 0, 0, YYAT_REDUCE, 17 },
	{ 0, 0, YYAT_REDUCE, 52 },
	{ 0, 0, YYAT_REDUCE, 53 },
	{ 0, 0, YYAT_REDUCE, 49 },
	{ 0, 0, YYAT_REDUCE, 54 },
	{ 0, 0, YYAT_REDUCE, 51 },
	{ 0, 0, YYAT_REDUCE, 50 },
	{ 0, 0, YYAT_DEFAULT, 67 },
	{ 0, 0, YYAT_DEFAULT, 67 },
	{ 0, 0, YYAT_DEFAULT, 67 },
	{ 0, 0, YYAT_DEFAULT, 67 },
	{ -213, 1, YYAT_DEFAULT, 90 },
	{ 0, 0, YYAT_REDUCE, 61 },
	{ 0, 0, YYAT_REDUCE, 45 },
	{ -15, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 90 },
	{ -219, 1, YYAT_ERROR, 0 },
	{ 1, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 36 },
	{ -217, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 6 },
	{ -32, 1, YYAT_REDUCE, 47 },
	{ -21, 1, YYAT_REDUCE, 55 },
	{ -40, 1, YYAT_REDUCE, 56 },
	{ 0, 0, YYAT_REDUCE, 58 },
	{ 0, 0, YYAT_REDUCE, 59 },
	{ 0, 0, YYAT_REDUCE, 23 },
	{ 0, 0, YYAT_REDUCE, 31 },
	{ 0, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 39 },
	{ -20, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 9 },
	{ -31, 1, YYAT_REDUCE, 28 },
	{ -3, 1, YYAT_ERROR, 0 },
	{ -35, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_DEFAULT, 116 },
	{ 0, 0, YYAT_DEFAULT, 116 },
	{ 0, 0, YYAT_REDUCE, 27 },
	{ 0, 0, YYAT_REDUCE, 24 },
	{ 0, 0, YYAT_DEFAULT, 116 },
	{ -4, 1, YYAT_ERROR, 0 },
	{ -229, 1, YYAT_REDUCE, 41 },
	{ 0, 0, YYAT_REDUCE, 37 },
	{ -24, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 29 },
	{ 0, 0, YYAT_REDUCE, 20 },
	{ 0, 0, YYAT_REDUCE, 40 },
	{ 0, 0, YYAT_REDUCE, 34 },
	{ 0, 0, YYAT_REDUCE, 32 },
	{ -25, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 25 },
	{ 0, 0, YYAT_DEFAULT, 116 },
	{ 0, 0, YYAT_REDUCE, 38 },
	{ -39, 1, YYAT_REDUCE, 28 },
	{ 0, 0, YYAT_REDUCE, 33 },
	{ 0, 0, YYAT_DEFAULT, 116 },
	{ 0, 0, YYAT_REDUCE, 26 },
	{ -11, 1, YYAT_ERROR, 0 },
	{ -38, 1, YYAT_ERROR, 0 },
	{ 0, 0, YYAT_REDUCE, 35 },
	{ -59, 1, YYAT_DEFAULT, 90 },
	{ 0, 0, YYAT_REDUCE, 22 }
};

int YYNEAR YYDCDECL yynontermgoto_size = 64;

YYCONST yynontermgoto_t YYNEARFAR YYBASED_CODE YYDCDECL yynontermgoto[] = {
	{ 116, 29 },
	{ 116, 33 },
	{ 97, 104 },
	{ 116, 117 },
	{ 116, 37 },
	{ 109, 112 },
	{ 116, 31 },
	{ 90, -1 },
	{ 112, 114 },
	{ 97, 103 },
	{ 0, 4 },
	{ 11, 15 },
	{ 116, 36 },
	{ 11, 9 },
	{ 0, 3 },
	{ 116, 35 },
	{ 111, 113 },
	{ 116, 38 },
	{ 65, 79 },
	{ 65, 42 },
	{ 109, 93 },
	{ 109, 39 },
	{ 90, 96 },
	{ 109, 40 },
	{ 116, 32 },
	{ 108, 111 },
	{ 116, 34 },
	{ 63, 77 },
	{ 63, 41 },
	{ 6, 7 },
	{ 6, 8 },
	{ 107, 110 },
	{ 106, 109 },
	{ 102, 107 },
	{ 98, 105 },
	{ 95, 100 },
	{ 94, 99 },
	{ 92, 98 },
	{ 91, 97 },
	{ 88, 94 },
	{ 85, 91 },
	{ 83, 89 },
	{ 82, 88 },
	{ 75, 87 },
	{ 74, 86 },
	{ 71, 83 },
	{ 67, 81 },
	{ 66, 80 },
	{ 64, 78 },
	{ 52, 74 },
	{ 51, 73 },
	{ 50, 72 },
	{ 49, 71 },
	{ 48, 70 },
	{ 47, 69 },
	{ 39, 63 },
	{ 33, 54 },
	{ 26, 50 },
	{ 19, 46 },
	{ 18, 45 },
	{ 17, 43 },
	{ 16, 30 },
	{ 13, 16 },
	{ 10, 14 }
};

YYCONST yystategoto_t YYNEARFAR YYBASED_CODE YYDCDECL yystategoto[] = {
	{ 9, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 27, 11 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 35, -1 },
	{ 8, -1 },
	{ 0, -1 },
	{ 33, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 54, 116 },
	{ 30, 90 },
	{ 24, -1 },
	{ 23, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 48, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 50, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 23, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 24, 90 },
	{ 23, 90 },
	{ 35, -1 },
	{ 44, 116 },
	{ 20, 90 },
	{ 19, 90 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -6, 65 },
	{ 14, 65 },
	{ -16, -1 },
	{ 12, -1 },
	{ 11, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 15, 90 },
	{ 0, -1 },
	{ 0, -1 },
	{ 22, -1 },
	{ 37, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 31, -1 },
	{ 23, -1 },
	{ 0, -1 },
	{ 15, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 24, 109 },
	{ 0, -1 },
	{ -8, 109 },
	{ 31, 116 },
	{ 30, 116 },
	{ 0, -1 },
	{ 24, -1 },
	{ 28, 116 },
	{ 0, -1 },
	{ -18, -1 },
	{ 11, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 7, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 19, -1 },
	{ 24, 116 },
	{ 1, -1 },
	{ -10, 63 },
	{ 0, -1 },
	{ 9, 116 },
	{ -6, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ 0, -1 },
	{ -4, 90 },
	{ 0, -1 }
};

YYCONST yydestructor_t YYNEARFAR *YYNEAR YYDCDECL yydestructorptr = NULL;

YYCONST yytokendest_t YYNEARFAR *YYNEAR YYDCDECL yytokendestptr = NULL;
int YYNEAR YYDCDECL yytokendest_size = 0;

YYCONST yytokendestbase_t YYNEARFAR *YYNEAR YYDCDECL yytokendestbaseptr = NULL;
int YYNEAR YYDCDECL yytokendestbase_size = 0;
#line 656 ".\\Mini-C-yacc.y"
                  


void yyerror(char *s) {fprintf (stderr, "erreur : %s\n", s);} 

void GenererQuadruplet(char CodeOp[50],char source1[50],char source2[50],char destination[50]){
	strcpy(quad[quadCourant].op,CodeOp);
	strcpy(quad[quadCourant].src1,source1);
	strcpy(quad[quadCourant].src2,source2);
	strcpy(quad[quadCourant].dest,destination);
	quadCourant++;
}

int main (void) {
	yyin = fopen("a.txt", "r");
	f = fopen("code.txt", "r+");
	
	if(!yyparse())
		printf("\n analyse correcte\n");
	else
		printf("\n analayse echouer\n");
		
	fprintf(f,"adr\t|op\t|src1\t|src2\t|dest\n");
	printf("adr\t|op\t|src1\t|src2\t|dest\n");	
	for	( i = 0 ; i < quadCourant ; i++ ){
		fprintf(f,"%d\t|%s\t|%s\t|%s\t|%s\n",i,quad[i].op,quad[i].src1,quad[i].src2,quad[i].dest);
		printf("%d\t|%s\t|%s\t|%s\t|%s\n",i,quad[i].op,quad[i].src1,quad[i].src2,quad[i].dest);
	}
	fclose(yyin);
	fclose(f);
	system("pause");
    return 0;
}



