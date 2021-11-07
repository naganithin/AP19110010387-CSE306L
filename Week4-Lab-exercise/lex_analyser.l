<<<<<<< HEAD
digit 	[0-9]*
id 	[a-zA-Z][a-zA-Z0-9]*
num 	digit*\.digit*

%{
	#include<stdio.h>
	#include<string.h>
	int i=0,j=0,cnt=0,n=0,com=0,scom=0;
	char st[20][20];
	int look_up(char st[20][20],char *id,int n);
%}

%%

\n 	{scom=0;n++;}
"//" 	{scom=1;fprintf(yyout," \n %s is singleline comment",yytext);}
"/*" 	{com=1;fprintf(yyout," \n %s is comment start",yytext);}
"*/" 	{com=0;fprintf(yyout," \n %s is comment end",yytext);}
int |
float |
char |
double |
string |
else |
while |
long |
return |
if |
void 	{if(!com&&!scom) fprintf(yyout," \n %s is keyword",yytext);}
"<=" 	{if (!com&&!scom) fprintf(yyout,"\n %s is Relational operator Less than or Equal to",yytext);}
"<" 	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Less than",yytext);}
">=" 	{if(!com) fprintf(yyout,"\n %s is Relational operator Greater than or Equal to",yytext);}
">" 	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Greater than",yytext);}
"==" 	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Equal to",yytext);}
"!=" 	{if (!com&&!scom) fprintf(yyout,"\n %s is Relational operator Not Equal to",yytext);}

{num} 	{if(!com&&!scom) fprintf(yyout,"\n %s is float",yytext);}
{id} 	{if(!com&&!scom) fprintf(yyout,"\n %s is identifier",yytext); cnt++;

	if(!look_up(st,yytext,i))
	strcpy(st[i++],yytext);
	}

{digit} {if (!com&&!scom) fprintf(yyout,"\n %s is digit",yytext);}
.

%%
int main()
{
	yyin =fopen("x.txt","r");
	yyout=fopen("y.txt","w");
	yylex();
	fprintf(yyout,"\n symbol table items: \n");
	for(j=0;j<i;j++)
	fprintf(yyout,"\n %s",st[j]); fprintf(yyout,"\n\n");
	return 0;
}

int yywrap()
{
return 1;
}

int look_up(char st[20][20],char *id,int n)
{
	for(j=0;j<n;j++)
	if(!strcmp(st[j],id))
	return 1;
	return 0;
=======
digit 	[0-9]*
id 	[a-zA-Z][a-zA-Z0-9]*
num 	digit*\.digit*

%{
	#include<stdio.h>
	#include<string.h>
	int i=0,j=0,cnt=0,n=0,com=0,scom=0;
	char st[20][20];
	int look_up(char st[20][20],char *id,int n);
%}

%%

\n 	{scom=0;n++;}
"//" 	{scom=1;fprintf(yyout," \n %s is singleline comment",yytext);}
"/*" 	{com=1;fprintf(yyout," \n %s is comment start",yytext);}
"*/" 	{com=0;fprintf(yyout," \n %s is comment end",yytext);}
int |
float |
char |
double |
string |
else |
while |
long |
return |
if |
void 	{if(!com&&!scom) fprintf(yyout," \n %s is keyword",yytext);}
"<=" 	{if (!com&&!scom) fprintf(yyout,"\n %s is Relational operator Less than or Equal to",yytext);}
"<" 	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Less than",yytext);}
">=" 	{if(!com) fprintf(yyout,"\n %s is Relational operator Greater than or Equal to",yytext);}
">" 	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Greater than",yytext);}
"==" 	{if(!com&&!scom) fprintf(yyout,"\n %s is Relational operator Equal to",yytext);}
"!=" 	{if (!com&&!scom) fprintf(yyout,"\n %s is Relational operator Not Equal to",yytext);}

{num} 	{if(!com&&!scom) fprintf(yyout,"\n %s is float",yytext);}
{id} 	{if(!com&&!scom) fprintf(yyout,"\n %s is identifier",yytext); cnt++;

	if(!look_up(st,yytext,i))
	strcpy(st[i++],yytext);
	}

{digit} {if (!com&&!scom) fprintf(yyout,"\n %s is digit",yytext);}
.

%%
int main()
{
	yyin =fopen("x.txt","r");
	yyout=fopen("y.txt","w");
	yylex();
	fprintf(yyout,"\n symbol table items: \n");
	for(j=0;j<i;j++)
	fprintf(yyout,"\n %s",st[j]); fprintf(yyout,"\n\n");
	return 0;
}

int yywrap()
{
return 1;
}

int look_up(char st[20][20],char *id,int n)
{
	for(j=0;j<n;j++)
	if(!strcmp(st[j],id))
	return 1;
	return 0;
>>>>>>> 5f468bca96f7019ecc198b07a07779e13f0e0a68
}