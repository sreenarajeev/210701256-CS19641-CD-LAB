%{
#include<stdio.h>
#include<string.h>
int word_count = 0;
%}

%%
[a-zA-Z0-9]+ { word_count++; } /* Rule for counting number of words */
\n { printf("%d\n", word_count); word_count = 0; }
.
%%

int main() {
    
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
