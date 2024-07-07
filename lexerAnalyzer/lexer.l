%{
#include <stdio.h>
%}

%%

"int"               { printf("TYPE: %s\n", yytext); }
"str"               { printf("TYPE: %s\n", yytext); }
"float"             { printf("TYPE: %s\n", yytext); }
"bool"              { printf("TYPE: %s\n", yytext); }
"char"              { printf("TYPE: %s\n", yytext); }
"return"            { printf("COMMAND: %s\n", yytext); }
'[^']'              { printf("CHAR: %s\n", yytext); }
\"[^\']*\"          { printf("CHAR: %s\n", yytext); }   
"write"             { printf("COMMAND: %s\n", yytext); }
"writeln"           { printf("COMMAND: %s\n", yytext); }
"read"              { printf("COMMAND: %s\n", yytext); }
"break"             { printf("COMMAND: %s\n", yytext); }
"ln"                { printf("LINE: %s\n", yytext);}
"if"                { printf("CONDITION: %s\n", yytext); }
"while"             { printf("CONDITION: %s\n", yytext); } 
"else"              { printf("CONDITION: %s\n", yytext); } 
[a-zA-Z_][a-zA-Z0-9_]* { printf("IDENTIFIER: %s\n", yytext); }
[0-9]+\.[0-9]+      { printf("FLOAT: %s\n", yytext); }
[0-9]+              { printf("INTEGER: %s\n", yytext); }
"("                 { printf("OPENING_PARETHESIS: %s\n", yytext); }
")"                 { printf("CLOSING_PARETHESIS: %s\n", yytext); }
"["                 { printf("OPENING_SQUARE_BRACKETS: %s\n", yytext); }
"]"                 { printf("CLOSING_SQUARE_BRAKCETS: %s\n", yytext); }
"{"                 { printf("OPENING_CURLY_BRACKETS: %s\n", yytext); }
"}"                 { printf("CLOSING_CURLY_BRACKETS: %s\n", yytext); }
";"                 { printf("SEMICOLON: %s\n", yytext); }
"="                 { printf("EQUALS: %s\n", yytext); }
","                 { printf("COMMA: %s\n", yytext); }
"+"                 { printf("PLUS: %s\n", yytext); }
"-"                 { printf("MINUS: %s\n", yytext);}
"*"                 { printf("MULTIPY: %s\n", yytext);}
"<"                 { printf("LESS_THAN: %s\n", yytext);}
">"                 { printf("GREATER_THAN: %s\n", yytext);}
"!"                 { printf("NOT: %s\n", yytext);}
"&&"                { printf("AND: %s\n", yytext);}
"/"                 { printf("DIVIDE: %s\n", yytext);}
[ \t\n\r]+          { /* ignore whitespace */ }
\.                  { printf("PERIOD: %s\n", yytext);}
.                   { printf("UNKNOWN: %s\n", yytext); } 

%%

int main(int argc, char **argv) {
    ++argv, --argc;  /* skip over program name */
    if (argc > 0)
        yyin = fopen(argv[0], "r");
    else
        yyin = stdin;

    yylex();
    return 0;
}
