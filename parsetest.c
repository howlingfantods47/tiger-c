/*
 * parse.c - Parse source file.
 */

#include <stdio.h>
#include "util.h"
#include "symbol.h"
#include "absyn.h"
#include "errormsg.h"
#include "parsetest.h"
#include "prabsyn.h"


extern FILE *yyin, *yyout;
extern int yyparse(void);
int yydebug = 1;
extern A_exp absyn_root;

/* parse source file fname;
   return abstract syntax data structure */
A_exp parse(string fname)
{EM_reset(fname);
    if (yyparse() == 0) /* parsing worked */
        return absyn_root;
    else return NULL;
}


int main(int argc, char **argv) {
    if (argc!=2) {fprintf(stderr,"usage: a.out filename\n"); exit(1);}
    yyin = stdin;
    yyout = stdout;
    A_exp parsed = parse(argv[1]);
    if(parsed) {
        pr_exp(stdout, parsed, 4);
        fprintf(stdout, "\n");
    }
    return 0;
}
