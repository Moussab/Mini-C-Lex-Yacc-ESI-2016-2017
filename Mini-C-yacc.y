%{
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
	

%}






%union{
	struct Quadruplet{
		float FloatValue;
		int IntegerValue;
		char idval[50];
		int val;								
		int index;								
	}Quadruplet;
}

%token  NUMBER 
%token  IDENTIFIER
%token INT FLOAT
%token FOR WHILE DO
%token IF ELSE IFELSE
%right '=' 
%left '+','-'
%left '*','/'
%right moins_unitaire, plus_unitaire 
%right ELSE


%left LE GE EQ NE LT GT

%%



Function :	Type IDENTIFIER '(' ArgList ')' CompoundStmt 
		 ;

ArgList : Arg
		| ArgList ',' Arg
		| 
		;
		
Arg		: Type IDENTIFIER
		;
		
Declaration : Type IdentList ';'
			;
			
Type : INT	{$$.Quadruplet.index=0;}
	 | FLOAT {$$.Quadruplet.index=1;}
	 ;
	 
IdentList : IDENTIFIER ',' IdentList
		  | IDENTIFIER
		  ;
		  
Stmt : ForStmt
	 | WhileStmt
	 | Expr ';'
	 | IfStmt
	 | CompoundStmt 
	 | Declaration 
	 | DoWhileStmt ';'
	 | IfElseStmt
	 | ';'
	 ;
	 
	 
DoWhileStmt : DO DO_WHILE1 Stmt WHILE '(' Expr ')' {tmp1 = depiler(pile,&esp1);  // @ de DO_WHILE1
													itoa(tmp1,buffer,10);
													GenererQuadruplet("JZ","","",buffer);
													}
			;

DO_WHILE1: {empiler(pile,quadCourant,&esp1);}
		 ;
		 
ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2';'FOR3 OptExpr FOR4')' Stmt {
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
												strcpy(quad[tmp1].dest,buffer);}
		;

FOR1 : {empiler(pile,quadCourant,&esp1);}
	 ;
	 
	 
FOR2 : {empiler(pile,quadCourant,&esp1);
		GenererQuadruplet("JZ","","","");}
	 ;
	 
FOR3 :  { b=1;}
	 ;
	 
	 
FOR4 : {b=0;}
	 ;
	 
	 	
OptExpr : Expr
		|
		;
		
		
WhileStmt : WHILE '(' WHILE1 Expr WHILE2 ')' Stmt { tmp1 = depiler(pile,&esp1);  // @ de JZ
													tmp2 = depiler(pile,&esp1);  // @ avant la condition 'WHILE1'
													itoa(tmp2,buffer,10);
													GenererQuadruplet("JUMP","","",buffer);
													itoa(quadCourant,buffer,10);
													strcpy(quad[tmp1].dest,buffer);
												  }
		  ;
						
WHILE1 : {empiler(pile,quadCourant,&esp1);}
	   ;

WHILE2 : { empiler(pile,quadCourant,&esp1);
		   GenererQuadruplet("JZ","","","");}
	   ;
	   
IfStmt : IF '(' Expr ')' IF1  Stmt  ElsePart  { tmp1 = depiler(pile,&esp1);
												itoa(quadCourant,buffer,10);
												strcpy(quad[tmp1].dest,buffer);}
       ;
       
ElsePart : ELSE IF2 Stmt   
		 | IF3 %prec ELSE
		 ;

IfElseStmt : IFELSE '(' Expr IFELSE1 ';' Stmt IFELSE2 ';' IFELSE3 Stmt ')' {
																			tmp1 = depiler(pile,&esp1);
																			itoa(quadCourant,buffer,10);
																			strcpy(quad[tmp1].dest,buffer);
																		}
		;
		 
		 
IFELSE1 : { empiler(pile,quadCourant,&esp1);
			GenererQuadruplet("JZ","\0","\0","\0");}
		;
		
IFELSE2 : { empiler(pile,quadCourant,&esp1);
			GenererQuadruplet("JUMP","\0","\0","\0");}
		;
		
IFELSE3 : { tmp1 = depiler(pile,&esp1);
			tmp2 = depiler(pile,&esp1);
			empiler(pile,tmp1,&esp1);
			itoa(quadCourant,buffer,10);
			strcpy(quad[tmp2].dest,buffer);}
		;
		
		
IF1 : {	empiler(pile,quadCourant,&esp1);
		GenererQuadruplet("JZ","","","");}
	;
	
IF2 : { tmp1 = depiler(pile,&esp1);
		itoa(quadCourant+1,buffer,10);
		strcpy(quad[tmp1].dest,buffer);
		empiler(pile,quadCourant,&esp1);
		GenererQuadruplet("JUMP","","","");}
	;

IF3 : %prec ELSE {	tmp1 = depiler(pile,&esp1);
		itoa(quadCourant,buffer,10);
		strcpy(quad[tmp1].dest,buffer);}
	;	
	
	


CompoundStmt : '{' StmtList '}' {$$=$2;}
			 ;

StmtList : 	StmtList Stmt 
		 |
		 ;

Expr : IDENTIFIER '=' Expr {

			switch($3.Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",$3.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",$3.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",$3.Quadruplet.idval);
					break;
				}
				default: {
					sprintf(buf,"%s%d","tmp",$3.Quadruplet.val);
					break;
				}
			}

			if(b==0){
				GenererQuadruplet("=",buf,"\0",$1.Quadruplet.idval);
			}
			else{
				strcpy(tmpQuad.op,"="); 
				strcpy(tmpQuad.src1,buf);
				strcpy(tmpQuad.src2,"\0");
				strcpy(tmpQuad.dest,$1.Quadruplet.idval); 
				empilerQuad(pileQuad,tmpQuad,&esp2);
				cpt++;
			}
			$$=$3;
		}
	 | Rvalue {$$=$1;}
	 ;
 
Rvalue : Rvalue Compare Mag {	
				
			switch($1.Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",$1.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",$1.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",$1.Quadruplet.idval);
					break;
				}
			}
			
			switch($3.Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",$3.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",$3.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",$3.Quadruplet.idval);
					break;
				}
			}
				
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf($$.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			cpt_tmp++;
			$$.Quadruplet.val=cpt_tmp;
			
			if(b==0){
				
				GenererQuadruplet("CMP",buf,buf1,"\0");

				sprintf(buf3,"%d",quadCourant+3);
				
				switch($2.Quadruplet.idval[0]){
					case '>' : strcpy(tmp,"JG");	break;
					case '<' : strcpy(tmp,"JL");	break;
				}
				if(strcmp("eq",$2.Quadruplet.idval)==0){strcpy(tmp,"JZ");}
				if(strcmp("le",$2.Quadruplet.idval)==0){strcpy(tmp,"JLE");}
				if(strcmp("ge",$2.Quadruplet.idval)==0){strcpy(tmp,"JGE");}
				if(strcmp("ne",$2.Quadruplet.idval)==0){strcpy(tmp,"JNZ");}
				
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
								
				switch($2.Quadruplet.idval[0]){
					case '>' : strcpy(tmpQuad.op,"JG");	break;
					case '<' : strcpy(tmpQuad.op,"JL");	break;
				}
				
				if(strcmp("eq",$2.Quadruplet.idval)==0){strcpy(tmpQuad.op,"JZ");}
				if(strcmp("le",$2.Quadruplet.idval)==0){strcpy(tmpQuad.op,"JLE");}
				if(strcmp("ge",$2.Quadruplet.idval)==0){strcpy(tmpQuad.op,"JGE");}
				if(strcmp("ne",$2.Quadruplet.idval)==0){strcpy(tmpQuad.op,"JNZ");}
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
		}
	   | Mag {$$=$1;}
	   ;
	   
Compare : EQ	{sprintf($$.Quadruplet.idval,"eq");}
		| GT	{sprintf($$.Quadruplet.idval,">");}
		| LT	{sprintf($$.Quadruplet.idval,"<");}
		| LE	{sprintf($$.Quadruplet.idval,"le");} 
		| GE	{sprintf($$.Quadruplet.idval,"ge");}
		| NE	{sprintf($$.Quadruplet.idval,"ne");}	
		;
		
Mag : Mag '+' Term{
			switch($1.Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",$1.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",$1.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",$1.Quadruplet.idval);
					break;
				}
			}
			switch($3.Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",$3.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",$3.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",$3.Quadruplet.idval);
					break;
				}
			}
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf($$.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			$$.Quadruplet.val=cpt_tmp;
			cpt_tmp++;
			$$.Quadruplet.index=2;
			
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
		}
	| Mag '-' Term{
			switch($1.Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",$1.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",$1.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",$1.Quadruplet.idval);
					break;
				}
			}
			switch($3.Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",$3.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",$3.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",$3.Quadruplet.idval);
					break;
				}
			}
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf($$.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			$$.Quadruplet.val=cpt_tmp;
			cpt_tmp++;
			$$.Quadruplet.index=2;
			
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
		}
	| Term	{$$=$1;}
	;
	
Term : Term '*' Factor {
			switch($1.Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",$1.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",$1.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",$1.Quadruplet.idval);
					break;
				}
			}
			switch($3.Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",$3.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",$3.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",$3.Quadruplet.idval);
					break;
				}
			}
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf($$.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			$$.Quadruplet.val=cpt_tmp;
			cpt_tmp++;
			$$.Quadruplet.index=2;
			
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
		}
	 | Term '/' Factor  {
			switch($1.Quadruplet.index){
				case 0 : {
					sprintf(buf,"%d",$1.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf,"%f",$1.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf,"%s",$1.Quadruplet.idval);
					break;
				}
			}
			switch($3.Quadruplet.index){
				case 0 : {
					sprintf(buf1,"%d",$3.Quadruplet.IntegerValue);
					break;
				}
				case 1 : {
					sprintf(buf1,"%f",$3.Quadruplet.FloatValue);
					break;
				}
				case 2 : {
					sprintf(buf1,"%s",$3.Quadruplet.idval);
					break;
				}
			}
			sprintf(buf2,"%s%d","tmp",cpt_tmp);
			sprintf($$.Quadruplet.idval,"%s%d","tmp",cpt_tmp);
			$$.Quadruplet.val=cpt_tmp;
			cpt_tmp++;
			$$.Quadruplet.index=2;
			
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
		}
	 | Factor {	$$=$1;}
	 ;
	 
Factor : '(' Expr ')'  {$$=$2;}
	   | '-' Factor  %prec moins_unitaire {	
						switch($2.Quadruplet.index){
							case 0 : {
								$$.Quadruplet.IntegerValue =-$2.Quadruplet.IntegerValue;
								$$.Quadruplet.index=0;
								break;
							}
							case 1 : {
								$$.Quadruplet.FloatValue=-$2.Quadruplet.FloatValue;
								$$.Quadruplet.index=1;
								break;
							}
							default : {
								strcpy(buf,"-");
								strcat(buf,$2.Quadruplet.idval);
								strcpy($$.Quadruplet.idval,buf);
								$$.Quadruplet.index=2;
								break;
							}
						}
		}
	   | '+' Factor  %prec plus_unitaire {$$=$2;}
	   | IDENTIFIER %prec '='	{	
									if($1.Quadruplet.index == 2) {
										strcpy($$.Quadruplet.idval,$1.Quadruplet.idval);
										$$.Quadruplet.index=2;
									}
								} 
	   | NUMBER		{	
						switch($1.Quadruplet.index){
							case 0 : {
								$$.Quadruplet.IntegerValue = $1.Quadruplet.IntegerValue;
								$$.Quadruplet.index=0;
								break;
							}
							case 1 : {
								$$.Quadruplet.FloatValue=$1.Quadruplet.FloatValue;
								$$.Quadruplet.index=1;
								break;
							}
						}		
					}
	   ;
%%                  


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


