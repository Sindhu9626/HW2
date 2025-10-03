
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
    int startingIndex;
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

    if(argc != 2){
        printf("Error! Wrong number of arguments.\n");
        return 1;
    } 
    
    FILE *inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    
    char **lines = malloc(sizeof(char*)*100);
    int index = 0;

    for(int i = 0; i < 100; i++){
        lines[i] = (char*)malloc(50*sizeof(char));
    }

    while(fscanf(inputFile,"%[^\n]", lines[index]) == 1){
        index++;
        getc(inputFile);
    }

    

    printSourceProgram(lines, index);

    // Adjust as needed
    Token * allTokens = malloc(100*sizeof(Token));
    int tokenIndex = 0;
    char *resultPtr;
    char *resultPtr;
    
    for(int i=0; i < index; i++) { 
        int startingTokenIndex = tokenIndex;
        if(strstr(lines[i], "begin") != NULL) {
            resultPtr = strstr(lines[i], "begin");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = beginsym;
            
            allTokens[tokenIndex].lexeme = "begin";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "+") != NULL) {
            resultPtr = strstr(lines[i], "+");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], "+");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = plussym;
            
            allTokens[tokenIndex].lexeme = "+";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "-") != NULL) {
            resultPtr = strstr(lines[i], "-");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], "-");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = minussym;
            
            allTokens[tokenIndex].lexeme = "-";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "*") != NULL) {
            resultPtr = strstr(lines[i], "*");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], "*");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = multsym;
            
            allTokens[tokenIndex].lexeme = "*";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "/") != NULL) {
            resultPtr = strstr(lines[i], "/");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], "/");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = slashsym;
            
            allTokens[tokenIndex].lexeme = "/";
            
            tokenIndex++;
        }
        
        if(strstr(lines[i], "<>") != NULL) {
            resultPtr = strstr(lines[i], "<>");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], "<>");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = neqsym;
            
            allTokens[tokenIndex].lexeme = "<>";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "<") != NULL) {
            resultPtr = strstr(lines[i], "<");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];

            if(lines[i][resultPtr-lines[i]+1] != '>'){
                allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
                allTokens[tokenIndex].tokenType = lessym;
                
                allTokens[tokenIndex].lexeme = "<";
                
                tokenIndex++;
            }
        }
        if(strstr(lines[i], "<=") != NULL) {
            resultPtr = strstr(lines[i], "<=");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], "<=");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = leqsym;
            
            allTokens[tokenIndex].lexeme = "<=";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ">") != NULL) {
            resultPtr = strstr(lines[i], ">");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            if(lines[i][resultPtr-lines[i]-1] != '<'){
                
                allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
                allTokens[tokenIndex].tokenType = gtrsym;
                
                allTokens[tokenIndex].lexeme = ">";
                
                tokenIndex++;
            }
        }
        if(strstr(lines[i], ">=") != NULL) {
            resultPtr = strstr(lines[i], ">=");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], ">=");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = geqsym;
            
            allTokens[tokenIndex].lexeme = ">=";
            
            tokenIndex++;
        }
        if(strstr(lines[i], "(") != NULL) {
            resultPtr = strstr(lines[i], "(");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], "(");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = lparentsym;
            
            allTokens[tokenIndex].lexeme = "(";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ")") != NULL) {
            resultPtr = strstr(lines[i], ")");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], ")");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = rparentsym;
            
            allTokens[tokenIndex].lexeme = ")";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ",") != NULL) {
            resultPtr = strstr(lines[i], ",");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], ",");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = commasym;
            
            allTokens[tokenIndex].lexeme = ",";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ";") != NULL) {
            resultPtr = strstr(lines[i], ";");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], ";");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = semicolonsym;
            
            allTokens[tokenIndex].lexeme = ";";
            
            tokenIndex++;
        }
        if(strstr(lines[i], ".") != NULL) {
            resultPtr = strstr(lines[i], ".");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], ".");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = periodsym;
            
            allTokens[tokenIndex].lexeme = ".";
            
            tokenIndex++;
        }

        //becomes (:=)
        if(strstr(lines[i], ":=") != NULL ) {
            resultPtr = strstr(lines[i], ":=");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            resultPtr = strstr(lines[i], ":=");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = becomessym;
            
            allTokens[tokenIndex].lexeme = ":=";
            
            tokenIndex++;
        }

        if(strstr(lines[i], "=") != NULL) {
            resultPtr = strstr(lines[i], "=");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            if (lines[i][resultPtr-lines[i]-1] != ':' && lines[i][resultPtr-lines[i]-1] != '>' && lines[i][resultPtr-lines[i]-1] != '<') {
                allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
                allTokens[tokenIndex].tokenType = eqsym;
            
                allTokens[tokenIndex].lexeme = "=";
            
                tokenIndex++;
            }
                tokenIndex++;
            }
        }

        
        //end
        if(strstr(lines[i], "end") != NULL) {
            resultPtr = strstr(lines[i], "end");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = endsym;
            
            allTokens[tokenIndex].lexeme = "end";
            
            tokenIndex++;
        }

        //if
        if(strstr(lines[i], "if") != NULL) {
            resultPtr = strstr(lines[i], "if");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = ifsym;
            
            allTokens[tokenIndex].lexeme = "if";
            
            tokenIndex++;
        }

        //fi
        if(strstr(lines[i], "fi") != NULL) {
            resultPtr = strstr(lines[i], "fi");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];

            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = fisym;
            
            allTokens[tokenIndex].lexeme = "fi";
            
            tokenIndex++;
        }

        //then
        if(strstr(lines[i], "then") != NULL) {
            resultPtr = strstr(lines[i], "then");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];

            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = thensym;
            
            allTokens[tokenIndex].lexeme = "then";
            
            tokenIndex++;
        }

        //while
        if(strstr(lines[i], "while") != NULL) {
            resultPtr = strstr(lines[i], "while");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = whilesym;
            
            allTokens[tokenIndex].lexeme = "while";
            
            tokenIndex++;
        }

        //do
        if(strstr(lines[i], "do") != NULL) {
            resultPtr = strstr(lines[i], "do");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];

            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = dosym;
            
            allTokens[tokenIndex].lexeme = "do";
            
            tokenIndex++;
        }

        //call
        if(strstr(lines[i], "call") != NULL) {
            resultPtr = strstr(lines[i], "call");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = callsym;
            
            allTokens[tokenIndex].lexeme = "call";
            
            tokenIndex++;
        }

        //const
        if(strstr(lines[i], "const") != NULL) {
            resultPtr = strstr(lines[i], "const");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = constsym;
            
            allTokens[tokenIndex].lexeme = "const";
            
            tokenIndex++;
        }

        //var
        if(strstr(lines[i], "var") != NULL) {
            resultPtr = strstr(lines[i], "var");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = varsym;
            
            allTokens[tokenIndex].lexeme = "var";
            
            tokenIndex++;
        }

        //procedure
        if(strstr(lines[i], "procedure") != NULL) {
            resultPtr = strstr(lines[i], "procedure");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = procsym;
            
            allTokens[tokenIndex].lexeme = "procedure";
            
            tokenIndex++;
        }

        //write
        if(strstr(lines[i], "write") != NULL) {
            resultPtr = strstr(lines[i], "write");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = writesym;
            
            allTokens[tokenIndex].lexeme = "write";
            
            tokenIndex++;
        }

        //read
        if(strstr(lines[i], "read") != NULL) {
            resultPtr = strstr(lines[i], "read");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = readsym;
            
            allTokens[tokenIndex].lexeme = "read";
            
            tokenIndex++;
        }

        //else
        if(strstr(lines[i], "else") != NULL) {
            resultPtr = strstr(lines[i], "else");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = elsesym;
            
            allTokens[tokenIndex].lexeme = "else";
            
            tokenIndex++;
        }

        //even
        if(strstr(lines[i], "even") != NULL) {
            resultPtr = strstr(lines[i], "even");
            allTokens[tokenIndex].startingIndex = resultPtr - lines[i];
            allTokens[tokenIndex].lexeme = malloc(sizeof(char)*11);
            allTokens[tokenIndex].tokenType = evensym;
            
            allTokens[tokenIndex].lexeme = "even";
            
            tokenIndex++;
        }

        for (int j = startingTokenIndex; j < tokenIndex - 1; j++) {
            //printf("\n%d %d\n", j, tokenIndex-j-1);
            int swapped = 0;
            for (int k = startingTokenIndex; k < tokenIndex - j - 1; k++) {
                printf("\n%d %d", allTokens[k].startingIndex, allTokens[k+1].startingIndex);
                if(allTokens[k].startingIndex > allTokens[k + 1].startingIndex) {
                    printf("here");
                    int swapped = 1; 
                    Token temp;
                    temp.startingIndex = allTokens[k].startingIndex;
                    temp.lexeme = allTokens[k].lexeme;
                    temp.tokenType = allTokens[k].tokenType;
                    allTokens[k].startingIndex = allTokens[k+1].startingIndex;
                    allTokens[k].lexeme = allTokens[k+1].lexeme;
                    allTokens[k].tokenType = allTokens[k+1].tokenType;
                    allTokens[k+1].startingIndex = temp.startingIndex;
                    allTokens[k+1].lexeme = temp.lexeme;
                    allTokens[k+1].tokenType = temp.tokenType;
                    printf("%s", allTokens[k].lexeme);
                    printf("%s", allTokens[k+1].lexeme);
                }            
            if (swapped == 0) {
                break;
            }
            }
            //printf("%d %d\n", i, allTokens[j].startingIndex);
        }
    }

        for (int j = startingTokenIndex; j < tokenIndex - 1; j++) {
            int swapped = 0;
            for (int k = 0; k < tokenIndex - j - 1; k++) {
                if(allTokens[k].startingIndex > allTokens[k + 1].startingIndex) {
                    int swapped = 1; 
                    Token temp;
                    temp.startingIndex = allTokens[k].startingIndex;
                    temp.lexeme = allTokens[k].lexeme;
                    temp.tokenType = allTokens[k].tokenType;
                    allTokens[k].startingIndex = allTokens[k+1].startingIndex;
                    allTokens[k].lexeme = allTokens[k+1].lexeme;
                    allTokens[k].tokenType = allTokens[k+1].tokenType;
                    allTokens[k+1].startingIndex = temp.startingIndex;
                    allTokens[k+1].lexeme = temp.lexeme;
                    allTokens[k+1].tokenType = temp.tokenType;
                }            
            if (swapped == 0) {
                break;
            }
            }
            /* TO DO SWAP FUNCTION*/
            // if startingIndex > then one after swap
            printf("%d %d\n", i, allTokens[j].startingIndex);
        }
    }
    printLexemeTable(allTokens, tokenIndex);
    printTokenList(allTokens, tokenIndex);   
      
}
