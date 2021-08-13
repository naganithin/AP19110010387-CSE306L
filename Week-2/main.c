#include <stdio.h>
#include <ctype.h>
#include <string.h>
char keyword[24][30] = {"int", "while", "break", "for", "do", "if", "float", "char", "switch", "double", "short", "long", "unsigned", "sizeof", "else", "register", "extern", "static", "auto", "case", "break", "volatile", "enum", "typedef"};
char symb_tab[30][30]; //Q 1:Declaring symbol table as a doubly dimensional array of characters.
int pos=0;
int check_keyword(char s[])
{
    for (int i = 0; i < 24; ++i)
        if (strcmp(s, keyword[i]) == 0)
            return 1;
    return 0;
}
void store_symb_tab(char id[], char symb_tab[][30])//Q 2:Writing a function to store identifier in symbol table
{
int flag=0;
for(int i=0;i<pos;i++){
    if(strcmp(id,symb_tab[i])==0){
        flag=1;
        
    }
    }
if(flag==1){
    strcpy(symb_tab[pos],id);
    pos++;
}
}

int main()
{
    FILE *fp1, *fp2;
    char c, id[30], num[10];
    int state = 0, i = 0, j = 0;
    fp1 = fopen("x.txt", "r");
    fp2 = fopen("y.txt", "w");
    while ((c = fgetc(fp1)) != EOF)
    {
        switch (state)
        {
        case 0:
            if (isalpha(c) || c == '_')
            {
                state = 1;
                id[i++] = c;
            }
            else if (isdigit(c))
            {
                state = 3;
                num[j++] = c;
            }
            else if (c == '<' || c == '>')
            {
                state = 5;
            }
            else if (c == '=' || c == '!')
            {
                state = 8;
            }
            else if (c == '/')
            {
                state = 10;
            }
            else if (c == ' ' || c == '\t' || c == '\n' || c == '\r')
            {
                state = 0;
            }
            else
            {
                fprintf(fp2, "\n%c", c);
            }
            break;
        case 1:
            if (isalnum(c) || c == '_')
            {
                state = 1;
                id[i++] = c;
            }
            else
            {
                id[i] = '\0';
                if (check_keyword(id))
                {
                    fprintf(fp2, " \n%s : keyword ", id);
                }
                else
                {
                    store_symb_tab(id, symb_tab);// Q 3:Calling  function to store id in symbol table.
                    fprintf(fp2, "\n%s : identifier", id);
                }
                state = 0;
                i = 0;
                ungetc(c, fp1);
            }
            break;
        case 3:
            if (isdigit(c))
            {
                num[j++] = c;
                state = 3;
            }
            else
            {
                num[j] = '\0';
                fprintf(fp2, " \n%s: number", num);
                state = 0;
                j = 0;
                ungetc(c, fp1);
            }
            break;
        case 5: // Q 4 :Write code to print specific operator like <, > ,<= or >=
            if (c == '=')
            {
                fseek(fp1, -2, SEEK_CUR);
                c = fgetc(fp1);
                if (c == '<')
                {
                    fprintf(fp2, "\n Relational operator representing less than or equal to : <=");
                }
                else
                {
                    fprintf(fp2, "\nRelational operator represnting greater than or equal to : >=");
                }
                c = fgetc(fp1);
                state = 0;
            }
            else
            {
                fseek(fp1, -2, SEEK_CUR);
                c = fgetc(fp1);
                if (c == '<')
                {
                    fprintf(fp2, "\nRelational operator Represnting less than : <");
                }
                else
                {
                    fprintf(fp2, "\nRelational operator Represening greater than : >");
                }
                state = 0;
            }
            break;
        case 8:                       // Q 4 :Write code to print eqaul to and not equal to
            if (c == '=')
            {
                fseek(fp1, -2, SEEK_CUR);
                c = fgetc(fp1);
                if (c == '=')
                {
                    fprintf(fp2, "\nRelational operator representing equal to : ==");
                }
                else
                {
                    fprintf(fp2, "\nRelational operator representing not equal to : !=");
                }
                c = fgetc(fp1);
                state = 0;
            }
            else
            {
                fprintf(fp2, "\n!");
                ungetc(c, fp1);
                state = 0;
            }
            break;
        case 10:
            if (c == '*')
            {
                state = 11;
            }
            else
            {
                fprintf(fp2, "\n/%c: invalid lexeme", c);
                state = 0;
            }
            break;
        case 11:
            if (c == '*')
            {
                state = 12;
            }
            break;
        case 12:
            if (c == '*')
            {
                state = 12;
            }
            else if (c == '/')
            {
                state = 0;
            }
            else
            {
                state = 11;
            }
            break;
        }
    }
    if (state == 11)
    {
        fprintf(fp2, "\nComment Not Closed");
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}