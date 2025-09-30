/*
Assignment :
lex - Lexical Analyzer for PL /0

Author : Sindhuja Sesham, Mikayla Philpot

Language : C ( only )

To Compile :
gcc - O2 - std = c11 -o lex lex . c

To Execute ( on Eustis ):
./ lex < input file >

where :
< input file > is the path to the PL /0 source program

Notes :
- Implement a lexical analyser for the PL /0 language .
- The program must detect errors such as
- numbers longer than five digits
- identifiers longer than eleven characters
- invalid characters .
- The output format must exactly match the specification .
- Tested on Eustis .

Class : COP 3402 - System Software - Fall 2025
Instructor : Dr . Jie Lin
Due Date : Friday , October 3 , 2025 at 11:59 PM ET
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXNUM 5
#define MAXID 11

typedef enum {
skipsym = 1,        // Skip / ignore token
identsym = 2,       // Identifier
numbersym = 3,      // Number
plussym = 4,        // +
minussym = 5,       // -
multsym = 6,        // *
slashsym = 7,       // /
eqsym = 8,          // =
neqsym = 9,         // <>
lessym = 10,        // <
leqsym = 11,        // <=
gtrsym = 12,        // >
geqsym = 13,        // >=
lparentsym = 14,    // (
rparentsym = 15,    // )
commasym = 16,      // =
semicolonsym = 17,  // ,
periodsym = 18,     // .
becomessym = 19,    // :=
beginsym = 20,      // begin
endsym = 21,        // end
ifsym = 22,         // if
fisym = 23,         // fi
thensym = 24,       // then
whilesym = 25,      // while
dosym = 26,         // do
callsym = 27,       // call
constsym = 28,      // const
varsym = 29,        // var
procsym = 30,       // procedure
writesym = 31,      // write
readsym = 32,       // read
elsesym = 33,       // else
evensym = 34,       // even
} TokenType;

typedef struct {
    TokenType tokenType;
    char * lexeme;
    
} Token;


// PRINT FUNCTIONS

void printSourceProgram(char **input, int size){
    printf("\nSource Program:\n\n");
    for(int i = 0; i < size; i++) {
        printf("%s\n", input[i]);
    }
}

void printLexemeTable(Token * allTokens, int size){
    printf("\n\nLexeme Table:\n\n");
    printf("lexeme\ttoken type");
    for (int i = 0; i < size; i++) {
        printf("\n%s\t%d", allTokens[i].lexeme, allTokens[i].tokenType);
    }

}

void printTokenList(Token * allTokens, int size){
    printf("\n\nToken List:\n\n\n");
    for(int i = 0; i < size; i++) {
        printf("%d ", allTokens[i].tokenType);
        if(allTokens[i].tokenType == 2) {
            printf("%s ", allTokens[i].lexeme);
        }
    }
    
}

int main(int argc, char *argv[]){

    if(argc != 1){
        printf("Error! Wrong number of arguments.\n");
        return 1;
    } 

    // Adjust as needed
    Token * allTokens = malloc(100*sizeof(Token));
    
    FILE *inputFile = fopen("input.txt", "r");
    
    char **lines = malloc(sizeof(char*)*100);
    int index = 0;
     for(int i = 0; i < 100; i++){
        lines[i] = (char*)malloc(50*sizeof(char));
     }

    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while(fscanf(inputFile,"%[^\n]", lines[index]) == 1){
        index++;
        getc(inputFile);
    }

    

    printSourceProgram(lines, index);

    int tokenIndex = 0;
    
    for(int i = 0; i < index; i++) { 
        
        if(strstr(lines[i], "+") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = plussym;
            
            allTokens[tokenIndex].lexeme = "+";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "-") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = minussym;
            
            allTokens[tokenIndex].lexeme = "-";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "*") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = multsym;
            
            allTokens[tokenIndex].lexeme = "*";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "/") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = slashsym;
            
            allTokens[tokenIndex].lexeme = "/";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "=") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = eqsym;
            
            allTokens[tokenIndex].lexeme = "=";
            
            tokenIndex++;
        }
        else if(strstr(lines[i], "<>") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = neqsym;
            
            allTokens[tokenIndex].lexeme = "<>";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "<") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = lessym;
            
            allTokens[tokenIndex].lexeme = "<";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "<=") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = leqsym;
            
            allTokens[tokenIndex].lexeme = "<=";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ">") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = gtrsym;
            
            allTokens[tokenIndex].lexeme = ">";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ">=") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = geqsym;
            
            allTokens[tokenIndex].lexeme = ">=";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "(") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = lparentsym;
            
            allTokens[tokenIndex].lexeme = "(";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ")") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = rparentsym;
            
            allTokens[tokenIndex].lexeme = ")";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ",") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = commasym;
            
            allTokens[tokenIndex].lexeme = ",";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ";") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = semicolonsym;
            
            allTokens[tokenIndex].lexeme = ";";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "*") != NULL) {
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = periodsym;
            
            allTokens[tokenIndex].lexeme = ".";
            
            tokenIndex++;
        }

        //becomes (:=)
        if(strstr(lines[i], ":=") != NULL ) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = becomessym;
            
            allTokens[i].lexeme = ":=";
            
            tokenIndex++;
        }
        

        //begin
        if(strstr(lines[i], "begin") != NULL) {

            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].lexeme = "begin";

            allTokens[i].tokenType = beginsym;
            
            tokenIndex++;
        }

        
        //end
        if(strstr(lines[i], "end") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = endsym;
            
            allTokens[i].lexeme = "end";
            
            tokenIndex++;
        }

        //if
        if(strstr(lines[i], "if") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = ifsym;
            
            allTokens[i].lexeme = "if";
            
            tokenIndex++;
        }

        //fi
        if(strstr(lines[i], "fi") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = fisym;
            
            allTokens[i].lexeme = "fi";
            
            tokenIndex++;
        }

        //then
        if(strstr(lines[i], "then") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = thensym;
            
            allTokens[i].lexeme = "then";
            
            tokenIndex++;
        }

        //while
        if(strstr(lines[i], "while") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = whilesym;
            
            allTokens[i].lexeme = "while";
            
            tokenIndex++;
        }

        //do
        if(strstr(lines[i], "do") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = dosym;
            
            allTokens[i].lexeme = "do";
            
            tokenIndex++;
        }

        //call
        if(strstr(lines[i], "call") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = callsym;
            
            allTokens[i].lexeme = "call";
            
            tokenIndex++;
        }

        //const
        if(strstr(lines[i], "const") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = constsym;
            
            allTokens[i].lexeme = "const";
            
            tokenIndex++;
        }

        //var
        if(strstr(lines[i], "var") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = varsym;
            
            allTokens[i].lexeme = "var";
            
            tokenIndex++;
        }

        //procedure
        if(strstr(lines[i], "procedure") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = procsym;
            
            allTokens[i].lexeme = "procedure";
            
            tokenIndex++;
        }

        //write
        if(strstr(lines[i], "write") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = writesym;
            
            allTokens[i].lexeme = "write";
            
            tokenIndex++;
        }

        //read
        if(strstr(lines[i], "read") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = readsym;
            
            allTokens[i].lexeme = "read";
            
            tokenIndex++;
        }

        //else
        if(strstr(lines[i], "else") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = elsesym;
            
            allTokens[i].lexeme = "else";
            
            tokenIndex++;
        }

        //even
        if(strstr(lines[i], "even") != NULL) {
            allTokens[i].lexeme = malloc(sizeof(char)*11);
            allTokens[i].tokenType = evensym;
            
            allTokens[i].lexeme = "even";
            
            tokenIndex++;
        }
    }
    printLexemeTable(allTokens, tokenIndex);
    printTokenList(allTokens, tokenIndex);   
}