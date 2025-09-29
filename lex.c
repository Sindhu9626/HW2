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
    int token;
    
} Token;


// PRINT FUNCTIONS

void printSourceProgram(char **input, int size){
    printf("\nSource Program:\n\n");
    for(int i = 0; i < size; i++) {
        printf("%s\n", input[i]);
    }
}

void printLexemeTable(){
    printf("\n\nLexeme Table:\n\n");
    printf("lexeme\ttoken type");
}

void printTokenList(){
    printf("\n\nToken List:\n\n");
    
}

int main(int argc, char *argv[]){

    if(argc != 2){
        printf("Error! Wrong number of arguments.\n");
        return 1;
    } 

    
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
    printLexemeTable();
    printTokenList();
}

