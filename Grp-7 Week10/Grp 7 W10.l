%{
#include<stdio.h>
#include "week10.tab.h"
#include<string.h>
%}
%%
[a-z]([a-z]|[0-9])* { strcpy(yylval.exp,yytext);

return VAR;
}
\t ;
\n return 0;
. return yytext[0];
%%