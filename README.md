# Mini-C-Lex-Yacc-ESI-2016-2017

input :

int main(int F, int G)
{

int a,b,c,d,e;

	while((a+b) > c <= (d*e+a)){
	
		a = a +1 ;
		do
			F = a + 1;
		while( F <= a);
		
		G = F;
	
	}
}

output :

adr	|op  	|src1	|src2	|dest 

0    	|+	|a	|b	|tmp1

1  	|CMP	|tmp1	|c   	|

2  	|JG	|   	|	|5

3	|=	|0	|	|tmp2

4  	|JUMP	|   	|	|6

5	|=	|1  	|	|tmp2

6	|*  	|d	|e	|tmp3

7	|+	|tmp3	|a	|tmp4

8	|CMP	|tmp2	|tmp4	|

9	|JLE	|	|	|12

10	|=	|0	|	|tmp5

11	|JUMP	|	|	|13

12	|=	|1	|	|tmp5

13	|JZ	|	|	|26

14	|+	|a	|1	|tmp6

15	|=	|tmp6	|	|a

16	|+	|a	|1	|tmp7

17	|=	|tmp7	|	|F

18	|CMP	|F	|a	|

19	|JLE	|	|	|22

20	|=	|0	|	|tmp8

21	|JUMP	|	|	|23

22	|=	|1	|	|tmp8

23	|JZ	|	|	|16

24	|=	|F	|	|G

25	|JUMP	|	|	|0

