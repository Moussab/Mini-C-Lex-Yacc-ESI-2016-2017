#############################################################################
#                     U N R E G I S T E R E D   C O P Y
# 
# You are on day 92 of your 30 day trial period.
# 
# This file was produced by an UNREGISTERED COPY of Parser Generator. It is
# for evaluation purposes only. If you continue to use Parser Generator 30
# days after installation then you are required to purchase a license. For
# more information see the online help or go to the Bumble-Bee Software
# homepage at:
# 
# http://www.bumblebeesoftware.com
# 
# This notice must remain present in the file. It cannot be removed.
#############################################################################

#############################################################################
# Mini-C-yacc.v
# YACC verbose file generated from Mini-C-yacc.y.
# 
# Date: 01/22/17
# Time: 10:30:59
# 
# AYACC Version: 2.07
#############################################################################


##############################################################################
# Rules
##############################################################################

    0  $accept : Function $end

    1  Function : Type IDENTIFIER '(' ArgList ')' CompoundStmt

    2  ArgList : Arg
    3          | ArgList ',' Arg
    4          |

    5  Arg : Type IDENTIFIER

    6  Declaration : Type IdentList ';'

    7  Type : INT
    8       | FLOAT

    9  IdentList : IDENTIFIER ',' IdentList
   10            | IDENTIFIER

   11  Stmt : ForStmt
   12       | WhileStmt
   13       | Expr ';'
   14       | IfStmt
   15       | CompoundStmt
   16       | Declaration
   17       | DoWhileStmt ';'
   18       | IfElseStmt
   19       | ';'

   20  DoWhileStmt : DO DO_WHILE1 Stmt WHILE '(' Expr ')'

   21  DO_WHILE1 :

   22  ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2 ';' FOR3 OptExpr FOR4 ')' Stmt

   23  FOR1 :

   24  FOR2 :

   25  FOR3 :

   26  FOR4 :

   27  OptExpr : Expr
   28          |

   29  WhileStmt : WHILE '(' WHILE1 Expr WHILE2 ')' Stmt

   30  WHILE1 :

   31  WHILE2 :

   32  IfStmt : IF '(' Expr ')' IF1 Stmt ElsePart

   33  ElsePart : ELSE IF2 Stmt
   34           | IF3

   35  IfElseStmt : IFELSE '(' Expr IFELSE1 ';' Stmt IFELSE2 ';' IFELSE3 Stmt ')'

   36  IFELSE1 :

   37  IFELSE2 :

   38  IFELSE3 :

   39  IF1 :

   40  IF2 :

   41  IF3 :

   42  CompoundStmt : '{' StmtList '}'

   43  StmtList : StmtList Stmt
   44           |

   45  Expr : IDENTIFIER '=' Expr
   46       | Rvalue

   47  Rvalue : Rvalue Compare Mag
   48         | Mag

   49  Compare : EQ
   50          | GT
   51          | LT
   52          | LE
   53          | GE
   54          | NE

   55  Mag : Mag '+' Term
   56      | Mag '-' Term
   57      | Term

   58  Term : Term '*' Factor
   59       | Term '/' Factor
   60       | Factor

   61  Factor : '(' Expr ')'
   62         | '-' Factor
   63         | '+' Factor
   64         | IDENTIFIER
   65         | NUMBER


##############################################################################
# States
##############################################################################

state 0
	$accept : . Function $end

	INT  shift 1
	FLOAT  shift 2

	Type  goto 3
	Function  goto 4


state 1
	Type : INT .  (7)

	.  reduce 7


state 2
	Type : FLOAT .  (8)

	.  reduce 8


state 3
	Function : Type . IDENTIFIER '(' ArgList ')' CompoundStmt

	IDENTIFIER  shift 5


state 4
	$accept : Function . $end  (0)

	$end  accept


state 5
	Function : Type IDENTIFIER . '(' ArgList ')' CompoundStmt

	'('  shift 6


state 6
	Function : Type IDENTIFIER '(' . ArgList ')' CompoundStmt
	ArgList : .  (4)

	INT  shift 1
	FLOAT  shift 2
	.  reduce 4

	ArgList  goto 7
	Arg  goto 8
	Type  goto 9


state 7
	Function : Type IDENTIFIER '(' ArgList . ')' CompoundStmt
	ArgList : ArgList . ',' Arg

	')'  shift 10
	','  shift 11


state 8
	ArgList : Arg .  (2)

	.  reduce 2


state 9
	Arg : Type . IDENTIFIER

	IDENTIFIER  shift 12


state 10
	Function : Type IDENTIFIER '(' ArgList ')' . CompoundStmt

	'{'  shift 13

	CompoundStmt  goto 14


state 11
	ArgList : ArgList ',' . Arg

	INT  shift 1
	FLOAT  shift 2

	Arg  goto 15
	Type  goto 9


state 12
	Arg : Type IDENTIFIER .  (5)

	.  reduce 5


state 13
	CompoundStmt : '{' . StmtList '}'
	StmtList : .  (44)

	.  reduce 44

	StmtList  goto 16


state 14
	Function : Type IDENTIFIER '(' ArgList ')' CompoundStmt .  (1)

	.  reduce 1


state 15
	ArgList : ArgList ',' Arg .  (3)

	.  reduce 3


state 16
	CompoundStmt : '{' StmtList . '}'
	StmtList : StmtList . Stmt

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	';'  shift 20
	'{'  shift 13
	'}'  shift 21
	NUMBER  shift 22
	IDENTIFIER  shift 23
	INT  shift 1
	FLOAT  shift 2
	FOR  shift 24
	WHILE  shift 25
	DO  shift 26
	IF  shift 27
	IFELSE  shift 28

	Declaration  goto 29
	Stmt  goto 30
	ForStmt  goto 31
	CompoundStmt  goto 32
	Type  goto 33
	Expr  goto 34
	IfStmt  goto 35
	WhileStmt  goto 36
	DoWhileStmt  goto 37
	IfElseStmt  goto 38
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 17
	Factor : '(' . Expr ')'

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23

	Expr  goto 43
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 18
	Factor : '+' . Factor

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 44

	Factor  goto 45


state 19
	Factor : '-' . Factor

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 44

	Factor  goto 46


state 20
	Stmt : ';' .  (19)

	.  reduce 19


state 21
	CompoundStmt : '{' StmtList '}' .  (42)

	.  reduce 42


state 22
	Factor : NUMBER .  (65)

	.  reduce 65


state 23
	Expr : IDENTIFIER . '=' Expr
	Factor : IDENTIFIER .  (64)

	'='  shift 47
	.  reduce 64


state 24
	ForStmt : FOR . '(' Expr ';' FOR1 OptExpr FOR2 ';' FOR3 OptExpr FOR4 ')' Stmt

	'('  shift 48


state 25
	WhileStmt : WHILE . '(' WHILE1 Expr WHILE2 ')' Stmt

	'('  shift 49


state 26
	DoWhileStmt : DO . DO_WHILE1 Stmt WHILE '(' Expr ')'
	DO_WHILE1 : .  (21)

	.  reduce 21

	DO_WHILE1  goto 50


state 27
	IfStmt : IF . '(' Expr ')' IF1 Stmt ElsePart

	'('  shift 51


state 28
	IfElseStmt : IFELSE . '(' Expr IFELSE1 ';' Stmt IFELSE2 ';' IFELSE3 Stmt ')'

	'('  shift 52


state 29
	Stmt : Declaration .  (16)

	.  reduce 16


state 30
	StmtList : StmtList Stmt .  (43)

	.  reduce 43


state 31
	Stmt : ForStmt .  (11)

	.  reduce 11


state 32
	Stmt : CompoundStmt .  (15)

	.  reduce 15


state 33
	Declaration : Type . IdentList ';'

	IDENTIFIER  shift 53

	IdentList  goto 54


state 34
	Stmt : Expr . ';'

	';'  shift 55


state 35
	Stmt : IfStmt .  (14)

	.  reduce 14


state 36
	Stmt : WhileStmt .  (12)

	.  reduce 12


state 37
	Stmt : DoWhileStmt . ';'

	';'  shift 56


state 38
	Stmt : IfElseStmt .  (18)

	.  reduce 18


state 39
	Rvalue : Rvalue . Compare Mag
	Expr : Rvalue .  (46)

	LE  shift 57
	GE  shift 58
	EQ  shift 59
	NE  shift 60
	LT  shift 61
	GT  shift 62
	.  reduce 46

	Compare  goto 63


state 40
	Rvalue : Mag .  (48)
	Mag : Mag . '-' Term
	Mag : Mag . '+' Term

	'+'  shift 64
	'-'  shift 65
	.  reduce 48


state 41
	Mag : Term .  (57)
	Term : Term . '*' Factor
	Term : Term . '/' Factor

	'*'  shift 66
	'/'  shift 67
	.  reduce 57


state 42
	Term : Factor .  (60)

	.  reduce 60


state 43
	Factor : '(' Expr . ')'

	')'  shift 68


state 44
	Factor : IDENTIFIER .  (64)

	.  reduce 64


state 45
	Factor : '+' Factor .  (63)

	.  reduce 63


state 46
	Factor : '-' Factor .  (62)

	.  reduce 62


state 47
	Expr : IDENTIFIER '=' . Expr

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23

	Expr  goto 69
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 48
	ForStmt : FOR '(' . Expr ';' FOR1 OptExpr FOR2 ';' FOR3 OptExpr FOR4 ')' Stmt

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23

	Expr  goto 70
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 49
	WhileStmt : WHILE '(' . WHILE1 Expr WHILE2 ')' Stmt
	WHILE1 : .  (30)

	.  reduce 30

	WHILE1  goto 71


state 50
	DoWhileStmt : DO DO_WHILE1 . Stmt WHILE '(' Expr ')'

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	';'  shift 20
	'{'  shift 13
	NUMBER  shift 22
	IDENTIFIER  shift 23
	INT  shift 1
	FLOAT  shift 2
	FOR  shift 24
	WHILE  shift 25
	DO  shift 26
	IF  shift 27
	IFELSE  shift 28

	Declaration  goto 29
	Stmt  goto 72
	ForStmt  goto 31
	CompoundStmt  goto 32
	Type  goto 33
	Expr  goto 34
	IfStmt  goto 35
	WhileStmt  goto 36
	DoWhileStmt  goto 37
	IfElseStmt  goto 38
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 51
	IfStmt : IF '(' . Expr ')' IF1 Stmt ElsePart

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23

	Expr  goto 73
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 52
	IfElseStmt : IFELSE '(' . Expr IFELSE1 ';' Stmt IFELSE2 ';' IFELSE3 Stmt ')'

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23

	Expr  goto 74
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 53
	IdentList : IDENTIFIER . ',' IdentList
	IdentList : IDENTIFIER .  (10)

	','  shift 75
	.  reduce 10


state 54
	Declaration : Type IdentList . ';'

	';'  shift 76


state 55
	Stmt : Expr ';' .  (13)

	.  reduce 13


state 56
	Stmt : DoWhileStmt ';' .  (17)

	.  reduce 17


state 57
	Compare : LE .  (52)

	.  reduce 52


state 58
	Compare : GE .  (53)

	.  reduce 53


state 59
	Compare : EQ .  (49)

	.  reduce 49


state 60
	Compare : NE .  (54)

	.  reduce 54


state 61
	Compare : LT .  (51)

	.  reduce 51


state 62
	Compare : GT .  (50)

	.  reduce 50


state 63
	Rvalue : Rvalue Compare . Mag

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 44

	Mag  goto 77
	Term  goto 41
	Factor  goto 42


state 64
	Mag : Mag '+' . Term

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 44

	Term  goto 78
	Factor  goto 42


state 65
	Mag : Mag '-' . Term

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 44

	Term  goto 79
	Factor  goto 42


state 66
	Term : Term '*' . Factor

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 44

	Factor  goto 80


state 67
	Term : Term '/' . Factor

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 44

	Factor  goto 81


state 68
	Factor : '(' Expr ')' .  (61)

	.  reduce 61


state 69
	Expr : IDENTIFIER '=' Expr .  (45)

	.  reduce 45


state 70
	ForStmt : FOR '(' Expr . ';' FOR1 OptExpr FOR2 ';' FOR3 OptExpr FOR4 ')' Stmt

	';'  shift 82


state 71
	WhileStmt : WHILE '(' WHILE1 . Expr WHILE2 ')' Stmt

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23

	Expr  goto 83
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 72
	DoWhileStmt : DO DO_WHILE1 Stmt . WHILE '(' Expr ')'

	WHILE  shift 84


state 73
	IfStmt : IF '(' Expr . ')' IF1 Stmt ElsePart

	')'  shift 85


state 74
	IfElseStmt : IFELSE '(' Expr . IFELSE1 ';' Stmt IFELSE2 ';' IFELSE3 Stmt ')'
	IFELSE1 : .  (36)

	.  reduce 36

	IFELSE1  goto 86


state 75
	IdentList : IDENTIFIER ',' . IdentList

	IDENTIFIER  shift 53

	IdentList  goto 87


state 76
	Declaration : Type IdentList ';' .  (6)

	.  reduce 6


state 77
	Rvalue : Rvalue Compare Mag .  (47)
	Mag : Mag . '-' Term
	Mag : Mag . '+' Term

	'+'  shift 64
	'-'  shift 65
	.  reduce 47


state 78
	Term : Term . '*' Factor
	Term : Term . '/' Factor
	Mag : Mag '+' Term .  (55)

	'*'  shift 66
	'/'  shift 67
	.  reduce 55


state 79
	Mag : Mag '-' Term .  (56)
	Term : Term . '*' Factor
	Term : Term . '/' Factor

	'*'  shift 66
	'/'  shift 67
	.  reduce 56


state 80
	Term : Term '*' Factor .  (58)

	.  reduce 58


state 81
	Term : Term '/' Factor .  (59)

	.  reduce 59


state 82
	ForStmt : FOR '(' Expr ';' . FOR1 OptExpr FOR2 ';' FOR3 OptExpr FOR4 ')' Stmt
	FOR1 : .  (23)

	.  reduce 23

	FOR1  goto 88


state 83
	WhileStmt : WHILE '(' WHILE1 Expr . WHILE2 ')' Stmt
	WHILE2 : .  (31)

	.  reduce 31

	WHILE2  goto 89


state 84
	DoWhileStmt : DO DO_WHILE1 Stmt WHILE . '(' Expr ')'

	'('  shift 90


state 85
	IfStmt : IF '(' Expr ')' . IF1 Stmt ElsePart
	IF1 : .  (39)

	.  reduce 39

	IF1  goto 91


state 86
	IfElseStmt : IFELSE '(' Expr IFELSE1 . ';' Stmt IFELSE2 ';' IFELSE3 Stmt ')'

	';'  shift 92


state 87
	IdentList : IDENTIFIER ',' IdentList .  (9)

	.  reduce 9


state 88
	ForStmt : FOR '(' Expr ';' FOR1 . OptExpr FOR2 ';' FOR3 OptExpr FOR4 ')' Stmt
	OptExpr : .  (28)

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23
	.  reduce 28

	Expr  goto 93
	OptExpr  goto 94
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 89
	WhileStmt : WHILE '(' WHILE1 Expr WHILE2 . ')' Stmt

	')'  shift 95


state 90
	DoWhileStmt : DO DO_WHILE1 Stmt WHILE '(' . Expr ')'

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23

	Expr  goto 96
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 91
	IfStmt : IF '(' Expr ')' IF1 . Stmt ElsePart

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	';'  shift 20
	'{'  shift 13
	NUMBER  shift 22
	IDENTIFIER  shift 23
	INT  shift 1
	FLOAT  shift 2
	FOR  shift 24
	WHILE  shift 25
	DO  shift 26
	IF  shift 27
	IFELSE  shift 28

	Declaration  goto 29
	Stmt  goto 97
	ForStmt  goto 31
	CompoundStmt  goto 32
	Type  goto 33
	Expr  goto 34
	IfStmt  goto 35
	WhileStmt  goto 36
	DoWhileStmt  goto 37
	IfElseStmt  goto 38
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 92
	IfElseStmt : IFELSE '(' Expr IFELSE1 ';' . Stmt IFELSE2 ';' IFELSE3 Stmt ')'

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	';'  shift 20
	'{'  shift 13
	NUMBER  shift 22
	IDENTIFIER  shift 23
	INT  shift 1
	FLOAT  shift 2
	FOR  shift 24
	WHILE  shift 25
	DO  shift 26
	IF  shift 27
	IFELSE  shift 28

	Declaration  goto 29
	Stmt  goto 98
	ForStmt  goto 31
	CompoundStmt  goto 32
	Type  goto 33
	Expr  goto 34
	IfStmt  goto 35
	WhileStmt  goto 36
	DoWhileStmt  goto 37
	IfElseStmt  goto 38
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 93
	OptExpr : Expr .  (27)

	.  reduce 27


state 94
	ForStmt : FOR '(' Expr ';' FOR1 OptExpr . FOR2 ';' FOR3 OptExpr FOR4 ')' Stmt
	FOR2 : .  (24)

	.  reduce 24

	FOR2  goto 99


state 95
	WhileStmt : WHILE '(' WHILE1 Expr WHILE2 ')' . Stmt

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	';'  shift 20
	'{'  shift 13
	NUMBER  shift 22
	IDENTIFIER  shift 23
	INT  shift 1
	FLOAT  shift 2
	FOR  shift 24
	WHILE  shift 25
	DO  shift 26
	IF  shift 27
	IFELSE  shift 28

	Declaration  goto 29
	Stmt  goto 100
	ForStmt  goto 31
	CompoundStmt  goto 32
	Type  goto 33
	Expr  goto 34
	IfStmt  goto 35
	WhileStmt  goto 36
	DoWhileStmt  goto 37
	IfElseStmt  goto 38
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 96
	DoWhileStmt : DO DO_WHILE1 Stmt WHILE '(' Expr . ')'

	')'  shift 101


state 97
	IfStmt : IF '(' Expr ')' IF1 Stmt . ElsePart
	IF3 : .  (41)

	ELSE  shift 102
	.  reduce 41

	IF3  goto 103
	ElsePart  goto 104


state 98
	IfElseStmt : IFELSE '(' Expr IFELSE1 ';' Stmt . IFELSE2 ';' IFELSE3 Stmt ')'
	IFELSE2 : .  (37)

	.  reduce 37

	IFELSE2  goto 105


state 99
	ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2 . ';' FOR3 OptExpr FOR4 ')' Stmt

	';'  shift 106


state 100
	WhileStmt : WHILE '(' WHILE1 Expr WHILE2 ')' Stmt .  (29)

	.  reduce 29


state 101
	DoWhileStmt : DO DO_WHILE1 Stmt WHILE '(' Expr ')' .  (20)

	.  reduce 20


state 102
	ElsePart : ELSE . IF2 Stmt
	IF2 : .  (40)

	.  reduce 40

	IF2  goto 107


state 103
	ElsePart : IF3 .  (34)

	.  reduce 34


state 104
	IfStmt : IF '(' Expr ')' IF1 Stmt ElsePart .  (32)

	.  reduce 32


state 105
	IfElseStmt : IFELSE '(' Expr IFELSE1 ';' Stmt IFELSE2 . ';' IFELSE3 Stmt ')'

	';'  shift 108


state 106
	ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2 ';' . FOR3 OptExpr FOR4 ')' Stmt
	FOR3 : .  (25)

	.  reduce 25

	FOR3  goto 109


state 107
	ElsePart : ELSE IF2 . Stmt

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	';'  shift 20
	'{'  shift 13
	NUMBER  shift 22
	IDENTIFIER  shift 23
	INT  shift 1
	FLOAT  shift 2
	FOR  shift 24
	WHILE  shift 25
	DO  shift 26
	IF  shift 27
	IFELSE  shift 28

	Declaration  goto 29
	Stmt  goto 110
	ForStmt  goto 31
	CompoundStmt  goto 32
	Type  goto 33
	Expr  goto 34
	IfStmt  goto 35
	WhileStmt  goto 36
	DoWhileStmt  goto 37
	IfElseStmt  goto 38
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 108
	IfElseStmt : IFELSE '(' Expr IFELSE1 ';' Stmt IFELSE2 ';' . IFELSE3 Stmt ')'
	IFELSE3 : .  (38)

	.  reduce 38

	IFELSE3  goto 111


state 109
	ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2 ';' FOR3 . OptExpr FOR4 ')' Stmt
	OptExpr : .  (28)

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	NUMBER  shift 22
	IDENTIFIER  shift 23
	.  reduce 28

	Expr  goto 93
	OptExpr  goto 112
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 110
	ElsePart : ELSE IF2 Stmt .  (33)

	.  reduce 33


state 111
	IfElseStmt : IFELSE '(' Expr IFELSE1 ';' Stmt IFELSE2 ';' IFELSE3 . Stmt ')'

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	';'  shift 20
	'{'  shift 13
	NUMBER  shift 22
	IDENTIFIER  shift 23
	INT  shift 1
	FLOAT  shift 2
	FOR  shift 24
	WHILE  shift 25
	DO  shift 26
	IF  shift 27
	IFELSE  shift 28

	Declaration  goto 29
	Stmt  goto 113
	ForStmt  goto 31
	CompoundStmt  goto 32
	Type  goto 33
	Expr  goto 34
	IfStmt  goto 35
	WhileStmt  goto 36
	DoWhileStmt  goto 37
	IfElseStmt  goto 38
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 112
	ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2 ';' FOR3 OptExpr . FOR4 ')' Stmt
	FOR4 : .  (26)

	.  reduce 26

	FOR4  goto 114


state 113
	IfElseStmt : IFELSE '(' Expr IFELSE1 ';' Stmt IFELSE2 ';' IFELSE3 Stmt . ')'

	')'  shift 115


state 114
	ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2 ';' FOR3 OptExpr FOR4 . ')' Stmt

	')'  shift 116


state 115
	IfElseStmt : IFELSE '(' Expr IFELSE1 ';' Stmt IFELSE2 ';' IFELSE3 Stmt ')' .  (35)

	.  reduce 35


state 116
	ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2 ';' FOR3 OptExpr FOR4 ')' . Stmt

	'('  shift 17
	'+'  shift 18
	'-'  shift 19
	';'  shift 20
	'{'  shift 13
	NUMBER  shift 22
	IDENTIFIER  shift 23
	INT  shift 1
	FLOAT  shift 2
	FOR  shift 24
	WHILE  shift 25
	DO  shift 26
	IF  shift 27
	IFELSE  shift 28

	Declaration  goto 29
	Stmt  goto 117
	ForStmt  goto 31
	CompoundStmt  goto 32
	Type  goto 33
	Expr  goto 34
	IfStmt  goto 35
	WhileStmt  goto 36
	DoWhileStmt  goto 37
	IfElseStmt  goto 38
	Rvalue  goto 39
	Mag  goto 40
	Term  goto 41
	Factor  goto 42


state 117
	ForStmt : FOR '(' Expr ';' FOR1 OptExpr FOR2 ';' FOR3 OptExpr FOR4 ')' Stmt .  (22)

	.  reduce 22


##############################################################################
# Summary
##############################################################################

31 token(s), 36 nonterminal(s)
66 grammar rule(s), 118 state(s)


##############################################################################
# End of File
##############################################################################
