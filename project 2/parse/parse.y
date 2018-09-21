

%{     /* pars1.y    Pascal Parser      Gordon S. Novak Jr.  ; 30 Jul 13   */

/* Copyright (c) 2013 Gordon S. Novak Jr. and
   The University of Texas at Austin. */

/* 14 Feb 01; 01 Oct 04; 02 Mar 07; 27 Feb 08; 24 Jul 09; 02 Aug 12 */

/*
; This program is free software; you can redistribute it and/or modify
; it under the terms of the GNU General Public License as published by
; the Free Software Foundation; either version 2 of the License, or
; (at your option) any later version.

; This program is distributed in the hope that it will be useful,
; but WITHOUT ANY WARRANTY; without even the implied warranty of
; MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
; GNU General Public License for more details.

; You should have received a copy of the GNU General Public License
; along with this program; if not, see <http://www.gnu.org/licenses/>.
  */


/* NOTE:   Copy your lexan.l lexical analyzer to this directory.      */

       /* To use:
                     make pars1y              has 1 shift/reduce conflict
                     pars1y                   execute the parser
                     i:=j .
                     ^D                       control-D to end input

                     pars1y                   execute the parser
                     begin i:=j; if i+j then x:=a+b*c else x:=a*b+c; k:=i end.
                     ^D

                     pars1y                   execute the parser
                     if x+y then if y+z then i:=j else k:=2.
                     ^D

           You may copy pars1.y to be parse.y and extend it for your
           assignment.  Then use   make parser   as above.
        */

        /* Yacc reports 1 shift/reduce conflict, due to the ELSE part of
           the IF statement, but Yacc's default resolves it in the right way.*/

#include <stdio.h>
#include <ctype.h>
#include "token.h"
#include "lexan.h"
#include "symtab.h"
#include "parse.h"
#include "pprint.h"
#include <string.h>
#include <float.h>
#include "codegen.h"
        /* define the type of the Yacc stack element to be TOKEN */

#define YYSTYPE TOKEN

TOKEN parseresult;

%}

/* Order of tokens corresponds to tokendefs.c; do not change */

%token IDENTIFIER STRING NUMBER   /* token types */

%token PLUS MINUS TIMES DIVIDE    /* Operators */
%token ASSIGN EQ NE LT LE GE GT POINT DOT AND OR NOT DIV MOD IN

%token COMMA                      /* Delimiters */
%token SEMICOLON COLON LPAREN RPAREN LBRACKET RBRACKET DOTDOT

%token ARRAY BEGINBEGIN           /* Lex uses BEGIN */
%token CASE CONST DO DOWNTO ELSE END FILEFILE FOR FUNCTION GOTO IF LABEL NIL
%token OF PACKED PROCEDURE PROGRAM RECORD REPEAT SET THEN TO TYPE UNTIL
%token VAR WHILE WITH


%%

  program       :  PROGRAM IDENTIFIER LPAREN IDENTIFIER RPAREN SEMICOLON haslabel DOT
                                                { parseresult = makeprogram($2, $4, $7); }
                ;

  statement     :  BEGINBEGIN statement endpart { $$ = makeprogn($1, cons($2, $3)); }
                |  IDENTIFIER LPAREN argslist RPAREN { $$ = makefuncall((TOKEN)talloc(), $1, $3); }
                |  NUMBER COLON statement       { $$ = dolabel($1, $2, $3); }
                |  IF compexpr THEN statement endif { $$ = makeif($1, $2, $4, $5); }
                |  FOR assignment TO compexpr DO statement { $$ = makefor(1, $1, $2, $3, $4, $5, $6); }
                |  WHILE compexpr DO statement  { $$ = makewhile($1, $2, $3, $4); }
                |  REPEAT statelist UNTIL compexpr { $$ = makerepeat($1, $2, $3, $4); }
                |  GOTO NUMBER                  { $$ = makegoto($2->intval); }
                |  assignment
                ;

  statelist     :  statement SEMICOLON statelist { $$ = cons($1, $3); }
                |  statement
                ;
  idlist        :  IDENTIFIER COMMA idlist      { $$ = cons($1, $3); }
                |  IDENTIFIER                   
                ;
  argslist      :  compexpr COMMA argslist      { $$ = cons($1, $3); }
                |  compexpr                     { $$ = cons($1, NULL); }
                ;
  haslabel      :  LABEL labels SEMICOLON hasconst { $$ = $4; }
                |  hasconst
                ;
  hasconst      :  CONST consts hastype         { $$ = $3; }
                |  hastype
                ;
  hastype       :  TYPE types hasvar            { $$ = $3; }
                |  hasvar
                ;
  hasvar        :  VAR var block                { $$ = $3; }
                |  block
                ;
  block		:  BEGINBEGIN statement endpart { $$ = makeprogn($1, cons($2, $3)); }
                ;
  labels        :  NUMBER COMMA labels          { instlabel($1); }
                |  NUMBER                       { instlabel($1); }
                ;
  consts        :  IDENTIFIER EQ NUMBER SEMICOLON consts { instconst($1, $3); }
                |  IDENTIFIER EQ NUMBER SEMICOLON { instconst($1, $3); }
                ;
  types         :  typedef SEMICOLON types      
                |  typedef SEMICOLON            { $$ = $1; }
                ;
  typedef       :  IDENTIFIER EQ type           { insttype($1, $3); }
                ;
  type          :  type2						{ $$ = $1; }
                |  POINT IDENTIFIER				{ $$ = instpoint($1, $2); }
                |  ARRAY LBRACKET list RBRACKET OF type { $$ = instarray($3, $6); }
                |  RECORD fields END			{ $$ = instrec($1, $2); }
                ;
  type2		:  IDENTIFIER					{ $$ = findtype($1); }
		|  LPAREN idlist RPAREN			{ $$ = instenum($2); }
		|  NUMBER DOTDOT NUMBER			{ $$ = instdotdot($1, $2, $3); }
                ;
  list		:  type2 COMMA list				{ $$ = cons($1, $3); }
                |  type2						{ $$ = $1; }
                ;
  var           :  vars SEMICOLON var           { $$ = $3; }
                |  vars SEMICOLON               { $$ = $1; }
                ;
  vars          :  idlist COLON type			{ instvars($1, $3); }
                ;
  dovar         :  IDENTIFIER					{ $$ = findid($1); }
                |  dovar DOT IDENTIFIER			{ $$ = reducedot($1, $2, $3); }
                |  dovar POINT                  { $$ = dopoint($1, $2); }
                |  arrayref
                ;
  arrayref	:  IDENTIFIER arraylist			{ $$ = arrayref($1, NULL, $2, NULL); }
                ;
  arraylist     :  LBRACKET argslist RBRACKET   { $$ = $2; }
                |  LBRACKET argslist RBRACKET arraylist { $$ = nconc($2, $4); }
                ;
  fields	:  idlist COLON type SEMICOLON fields { $$ = nconc(instfields($1, $3), $5); }
                |  idlist COLON type            { $$ = instfields($1, $3); }
                ;
  compexpr      :  expr EQ expr                 { $$ = binop($2, $1, $3); }
                |  expr NE expr                 { $$ = binop($2, $1, $3); }
                |  expr LT expr                 { $$ = binop($2, $1, $3); }
                |  expr LE expr                 { $$ = binop($2, $1, $3); }
                |  expr GE expr                 { $$ = binop($2, $1, $3); }
                |  expr GT expr                 { $$ = binop($2, $1, $3); }
                |  expr
                ;
  expr          :  unaryexpr PLUS term          { $$ = binop($2, $1, $3); }
                |  unaryexpr MINUS term         { $$ = binop($2, $1, $3); }
                |  unaryexpr OR term            { $$ = binop($2, $1, $3); }
                |  unaryexpr
                ;
  unaryexpr     :  PLUS term                    { $$ = unaryop($1, $2); }
                |  MINUS term                   { $$ = unaryop($1, $2); }
                |  term
                ;
  term          :  factor TIMES factor          { $$ = binop($2, $1, $3); }
                |  factor DIVIDE factor         { $$ = binop($2, $1, $3); }
                |  factor DIV factor            { $$ = binop($2, $1, $3); }
                |  factor MOD factor            { $$ = binop($2, $1, $3); }
                |  factor AND factor            { $$ = binop($2, $1, $3); }
                |  factor
                ;
  factor        :  LPAREN compexpr RPAREN	{ $$ = $2; }
                |  NUMBER
                |  IDENTIFIER LPAREN argslist RPAREN { $$ = makefuncall((TOKEN)talloc(), $1, $3); }
                |  dovar
                |  NOT factor                   { $$ = unaryop($1, $2); }
                |  LBRACKET factorlist RBRACKET { $$ = $2; }
                |  STRING
                |  NIL
                ;
  factorlist    : compexpr                      { $$ = $1; }
                | compexpr DOTDOT compexpr      { $$ = instdotdot($1, $2, $3); }
                | compexpr DOTDOT compexpr COMMA factorlist { $$ = instdotdot($1, $2, $3); }
                ;
  endpart       :  SEMICOLON statement endpart  { $$ = cons($2, $3); }
                |  END                          { $$ = NULL; }
                ;
  endif         :  ELSE statement               { $$ = $2; }
				|								{ $$ = NULL; }
                ;
  assignment    : factor ASSIGN compexpr        { $$ = binop($2, $1, $3); }
                ;

  // printDebug : IDENTIFIER   {printf("%s\n", yylval->stringval);}
  //            ;
%%


/* You should add your own debugging is below, and add debugging
   printouts to your programs.
   You will want to change DEBUG to turn off printouts once things
   are working.  */

#define DEBUG		0             /* set bits here for debugging, 0 = off  */
#define DB_CONS		0             /* bit to trace cons */
#define DB_BINOP	0             /* bit to trace binop */
#define DB_MAKEIF	0             /* bit to trace makeif */
#define DB_MAKEPROGN	0             /* bit to trace makeprogn */
#define DB_PARSERES	0             /* bit to trace parseresult */


 int labelnumber = 0;  /* sequential counter for internal label numbers */
 int labeltable [1000]; 
   /*  Note: you should add to the above values and insert debugging
       printouts in your routines similar to those that are shown here.     */


TOKEN cons(TOKEN item, TOKEN list)           /* add item to front of list */
  { 
  //printf("\nin cons\n");fflush(0);
  item->link = list;
    if (DEBUG & DB_CONS)
       { printf("cons\n");fflush(0);
         dbugprinttok(item);
         dbugprinttok(list);
       };
	  //printf("\nend cons\n");fflush(0);
    return item;
  }

TOKEN nconc(TOKEN lista, TOKEN listb) {
	//printf("\nin nconc\n");fflush(0);
	TOKEN list = lista;
	while(list->link != NULL) {
		list = list->link;
	}
	list->link = listb;
	//printf("\nend nconc\n");fflush(0);

	return list;
}

TOKEN findid(TOKEN tok) {
       //printf("\nin findid\n");fflush(0);

        //printf("\n f1\n");fflush(0);

        SYMBOL s;
        SYMBOL type;
        s = searchst(tok->stringval);
        //printf("\n f2\n");fflush(0);

        if(s == NULL) {
        //      return tok;
        }
        //printstlevel(1);
        tok->symentry = s;
        //printf("\n f3\n");fflush(0);

        type = s->datatype;
        //printf("\n f4\n");fflush(0);

        tok->symtype = type;

        //printf("\n f5\n");fflush(0);

        if (s->kind == CONSTSYM) {
                 if (s->basicdt == REAL) {
                        //printf("\n f6\n");fflush(0);

                        tok->tokentype = NUMBERTOK;
                        tok->datatype = REAL;
                        tok->realval = s->constval.realnum;
                } else if (s->basicdt == INTEGER) {
                        //printf("\n f7\n");fflush(0);

                        tok->tokentype = NUMBERTOK;
                        tok->datatype = INTEGER;
                        tok->intval = s->constval.intnum;
                }
        } else if( s->datatype->kind == TYPESYM && s->datatype->datatype->kind == POINTERSYM ) {
                //printf("\n f8\n");fflush(0);
                tok->symtype = s->datatype->datatype->datatype;
        }
        //printf("\nend findid\n");fflush(0);

        return tok;
}

TOKEN unaryop(TOKEN op, TOKEN lhs) {
	//printf("\nin unaryop");
	//dbugprinttok(op);
	//dbugprinttok(lhs);
	op->operands = lhs;
	lhs->link = NULL;
	return op;
	//printf("\nend unaryop");
}

int isReal(TOKEN tok) {
	SYMBOL s = searchst(tok->stringval);
	if(s->basicdt == REAL)
		return 1;
	else
		return 0;
}

int isInt(TOKEN tok) {
	SYMBOL s = searchst(tok->stringval);
	if(s->basicdt == INTEGER)
		return 1;
	else
		return 0;
}

int isId(TOKEN tok) {
	if(tok->tokentype == IDENTIFIERTOK)	
		return 1;
	else
		return 0;
}

TOKEN binop(TOKEN op, TOKEN lhs, TOKEN rhs) {
        //printf("\nin binop\n");fflush(0);


        op->operands = lhs;          /* link operands to operator       */
        lhs->link = rhs;             /* link second operand to first    */
        rhs->link = NULL;            /* terminate operand list          */

if (isId(lhs)) {
        if (isId(rhs)) {
                if (isReal(lhs) && isReal(rhs)) {
                        op->datatype = REAL;
                } else if (isReal(lhs) && isInt(rhs)) {
                        op->datatype = REAL;
                        TOKEN floattok = makeop(FLOATOP);
                        floattok->operands = rhs;
                        lhs->link = floattok;
                } else if (isInt(lhs) && isReal(rhs)) {
                        if (op->whichval == ASSIGNOP) {
                                TOKEN fixtok = makeop(FIXOP);
                                fixtok->operands =rhs;
                                lhs->link = fixtok;
                        } else {
                                op->datatype = REAL;
                                TOKEN floattok = makeop(FLOATOP);
                                floattok->operands = lhs;
                                floattok->link = rhs;
                        }
                }
        } else {
                if (isReal(lhs) && (rhs->datatype == REAL)) {
                        op->datatype = REAL;
                } else if (isReal(lhs) && (rhs->datatype == INTEGER)) {
                        op->datatype = REAL;
                        rhs->datatype = REAL;
                        rhs->realval = (double) rhs->intval;
                } else if (isInt(lhs) && (rhs->datatype == REAL)) {
                        if (op->whichval == ASSIGNOP) {
                                if (rhs->tokentype == NUMBERTOK) {
                                        rhs->datatype = INTEGER;
                                        rhs->intval = (int) rhs->realval;
                                } else if (rhs->tokentype == IDENTIFIERTOK || rhs->tokentype == OPERATOR) {
                                        TOKEN fixtok = makeop(FIXOP);
                                        fixtok->operands = rhs;
                                        lhs->link = fixtok;
                                }
                        } else {
                                op->datatype = REAL;
                                TOKEN floattok = makeop(FLOATOP);
                                floattok->operands = lhs;
                                floattok->link = rhs;
                        }
                }
        }
} else if((op->whichval == 1) && (lhs->whichval == FUNCALLOP)) {
//} else if((lhs->whichval == FUNCALLOP)) {

        TOKEN t = lhs->operands;
        SYMBOL s = searchst(t->stringval);
        SYMBOL type = s->datatype;
        //printf("making real\n");fflush(0);

        if(type->basicdt == 1) {
                //printf("basicdt\n");fflush(0);
                rhs->datatype = 1;
                rhs->realval = rhs->intval;
                op->datatype = 1;
        }
        //op->operands = lhs;
        //lhs->link = rhs;
        //rhs->link = NULL;
} else if( lhs->whichval == FUNCALLOP && rhs->whichval == FUNCALLOP) {
	//printf("in funcallop\n");fflush(0);	
	//dbugprinttok(lhs);
	//dbugprinttok(rhs);
	//dbugprinttok(op);
        TOKEN t1 = lhs->operands;
        SYMBOL s1 = searchst(t1->stringval);
        SYMBOL type1 = s1->datatype;
        TOKEN t2 = rhs->operands;
        SYMBOL s2 = searchst(t2->stringval);
        SYMBOL type2 = s2->datatype;
	
	if(type1->basicdt == 1 || type2->basicdt == 1) {
		op->datatype = REAL;
	}
} else {
        if (isId(rhs)) {
                if ((lhs->datatype == REAL) && isReal(rhs)) {
                        op->datatype = REAL;
                } else if ((lhs->datatype == INTEGER) && isReal(rhs)) {
                        op->datatype = REAL;
                        lhs->datatype = REAL;
                        lhs->realval = (double) lhs->intval;
                } else if ((lhs->datatype == REAL) && isInt(rhs)) {
                        op->datatype = REAL;
                        TOKEN floattok = makeop(FLOATOP);
                        floattok->operands = rhs;
                        lhs->link = floattok;
                }
        } else {
                if ((lhs->datatype == REAL) && (rhs->datatype == REAL)) {
                        op->datatype = REAL;
                } else if ((lhs->datatype == INTEGER) && (rhs->datatype == REAL)) {
                        op->datatype = REAL;
                        lhs->datatype = REAL;
                        lhs->realval = (double) lhs->intval;
                } else if ((lhs->datatype == REAL) && (rhs->datatype == INTEGER)) {
                        op->datatype = REAL;
                        rhs->datatype = REAL;
                        rhs->realval = (double) rhs->intval;
                }
        }
}

          //printf("\nend binop\n");fflush(0);
        return op;
}

TOKEN makeif(TOKEN tok, TOKEN exp, TOKEN thenpart, TOKEN elsepart) {
	  //printf("\nin makeif\n");fflush(0);
	tok->tokentype = OPERATOR;  /* Make it look like an operator   */
     tok->whichval = IFOP;
     if (elsepart != NULL) elsepart->link = NULL;
     thenpart->link = elsepart;
     exp->link = thenpart;
     tok->operands = exp;
     if (DEBUG & DB_MAKEIF)
        { printf("makeif\n");fflush(0);
          dbugprinttok(tok);
          dbugprinttok(exp);
          dbugprinttok(thenpart);
          dbugprinttok(elsepart);
        };
  //printf("\nend makeif\n");fflush(0);
     return tok;
   }

TOKEN findtype(TOKEN tok) {
	//printf("\nin findtype\n");fflush(0);
	tok->symtype = searchst(tok->stringval);
	//printf("\nend findtype\n");fflush(0);
	return tok;
}

void instconst(TOKEN idtok, TOKEN consttok) {
	//printf("\nin instconst\n");fflush(0);
	SYMBOL s;
	SYMBOL type;
//	type = idtok->symtype;
//	int align = alignsize(type);
//	i = alignsize(type);

	s = insertsym(idtok->stringval);
	s->datatype = type;
	s->kind = CONSTSYM;
//	s->size = type->size;
	s->basicdt = consttok->datatype;
	if(s->basicdt == REAL) {
	        s->constval.realnum = consttok->realval;
	}
	if(s->basicdt == INTEGER) {
	        s->constval.intnum = consttok->intval;
	}
	//printf("\nend instconst\n");fflush(0);
}

void instvars(TOKEN idlist, TOKEN typetok) {
        //printf("\n in instvars\n");fflush(0);
        SYMBOL s;
        SYMBOL type;
        int i;
        type = typetok->symtype;
        //dbugprinttok(idlist);
        //dbugprinttok(typetok);
        //ppsym(type);
        //printstlevel(1);
        i = alignsize(type);
        while ( idlist != NULL ) {
                s = insertsym(idlist->stringval);
                s->datatype = type;
                s->kind = VARSYM;
                s->size = type->size;
                s->basicdt = type->basicdt;
                s->offset = wordaddress(blockoffs[blocknumber], i);
                blockoffs[blocknumber] = s->offset + s->size;
                idlist = idlist->link;
        };
        //printf("\n end instvars\n");fflush(0);
}

void instlabel (TOKEN num) {
	//printf("\n in instlabel\n");fflush(0);
	labeltable[labelnumber++] = num->intval;
	//printf("\n end instlabel\n");fflush(0);
}

TOKEN dolabel(TOKEN labeltok, TOKEN tok, TOKEN statement) {
	//printf("\nin dolabel\n");fflush(0);

	TOKEN progn = makeprogn(tok, statement);
	TOKEN label = talloc();
	label->tokentype = OPERATOR;
	label->whichval = LABELOP;
	label->operands = labeltok;
	int i = 0;
	while(labeltable[i] != labeltok->intval) {
		i++;
	}
	labeltok->intval = i;
	progn->operands = label;
	label->link = statement;

	//printf("\nend dolabel\n");fflush(0);
	
	return progn;
}

void insttype(TOKEN typename, TOKEN typetok) {
	//printf("\nin insttype\n");fflush(0);
	SYMBOL sym, typesym;
	typesym = typetok->symtype;
	
//	printstlevel(1);
	sym = searchins(typename->stringval);
//	dbugprinttok(typename);
	sym->datatype = typesym;
	sym->kind = TYPESYM;
	sym->size = typesym->size;
	sym->basicdt = typesym->basicdt;
	
//	printstlevel(1);
	
	//printf("\nend insttype\n");fflush(0);
}

TOKEN instpoint(TOKEN tok, TOKEN typename) {
	//printf("\nin instpoint\n");fflush(0);
	SYMBOL ptrsym, sym;
	ptrsym = symalloc();
	ptrsym->kind = POINTERSYM;
	ptrsym->basicdt = POINTER;
	ptrsym->size = basicsizes[POINTER];
	tok->symtype = ptrsym;
	sym = searchins(typename->stringval);
	sym->kind = TYPESYM;
	ptrsym->datatype = sym;

	tok->datatype = POINTER;
	//printstlevel(1);
	//dbugprinttok(tok);
	//printf("\nend instpoint\n");fflush(0);
	return tok;
}

TOKEN instdotdot(TOKEN lowtok, TOKEN dottok, TOKEN hightok) {
	//printf("\nin instdotdot\n");fflush(0);
	TOKEN t = makesubrange(dottok, lowtok->intval, hightok->intval);
	//printf("\nend instdotdot\n");fflush(0);
	return t;
}

TOKEN instarray(TOKEN bounds, TOKEN typetok) {
	//printf("\nin instarray\n");fflush(0);
	SYMBOL s = makesym("array");
	//printf("\n a1\n");fflush(0);
	
	//printf("\n%d , %d\n", bounds->symtype->lowbound, bounds->symtype->highbound);
	//dbugprinttok(bounds);
	//dbugprinttok(typetok);
	
	s->kind = ARRAYSYM;
	s->datatype = typetok->symtype;
	s->lowbound = bounds->symtype->lowbound;
	s->highbound = bounds->symtype->highbound;


	//printf("\n%p \n", s->datatype);fflush(0);
	//printf("\n a2\n");fflush(0);
	int size = s->datatype->size * (s->highbound - s->lowbound + 1);
	s->size = size;
	//printf("\n a3\n");fflush(0);

	TOKEN t;
	if(bounds->link) {
	//printf("\n a4\n");fflush(0);

		int low = bounds->link->symtype->datatype->lowbound;
		int high = bounds->link->symtype->datatype->highbound;
		TOKEN subrange = makesubrange(copytok(typetok), low, high);
		t = instarray(subrange, typetok);
		s->datatype = t->symtype;
		s->size = s->datatype->size * (s->highbound - s->lowbound + 1);
	}

	//printf("\n a5\n");fflush(0);
	
	typetok->symtype = s;
	
	//printf("\nend instarray\n");fflush(0);
	return typetok;
}

TOKEN instrec(TOKEN rectok, TOKEN argstok) {
	//printf("\nin instrec\n");fflush(0);

	int size, offset;
	SYMBOL s = symalloc();
	s->kind = RECORDSYM;
	rectok->symtype = s;
	s->datatype = argstok->symtype;
	offset = wordaddress(argstok->symtype->size, 8);
	size = offset;
	TOKEN curr = argstok;
	TOKEN next = argstok->link;
	while(next) {
		curr->symtype->link = next->symtype;
		offset = wordaddress(next->symtype->size, 8);
		next->symtype->offset = size;
		size += offset;
		curr = next;
		next = next->link;
	}
	s->size = size;
	//printf("\nend instrec\n");fflush(0);
	return rectok;
}

TOKEN instfields(TOKEN idlist, TOKEN typetok) {
	//printf("\n in instfields\n");fflush(0);

	int next = 0;
	int offset = 0;

	SYMBOL recsym, typesym;

	TOKEN temp = idlist;

	while (temp) {
		typesym = searchst(typetok->stringval);
		recsym = makesym(temp->stringval);
		recsym->datatype = typesym;
		offset = next;
		next = next + typesym->size;

		recsym->offset = offset;
		recsym->size = typesym->size;
		recsym->datatype = typesym;

		if (typesym->kind == BASICTYPE) {
			recsym->basicdt = typesym->basicdt;
		}

		temp->symtype = recsym;

		temp = temp->link;
	}

	return idlist;
}

TOKEN makewhile(TOKEN tok, TOKEN expr, TOKEN tokb, TOKEN statement) {
	//printf("\nin makewhile\n");fflush(0);
	TOKEN label = talloc();
	label->tokentype = OPERATOR;
	label->whichval = LABELOP;

	TOKEN number = talloc();
	number->tokentype = NUMBERTOK;
	number->intval = labelnumber++;
	label->operands = number;

	TOKEN progn = makeprogn(tok, label);

	TOKEN ifop = talloc();
	ifop->tokentype = OPERATOR;
	ifop->whichval = IFOP;
	TOKEN iftok = unaryop(ifop, expr);
	
	label->link = ifop;
	iftok->operands->link = statement;
	
	TOKEN temp = statement->operands;

	while(temp->link) {
		//printf("\n in makewhile\n");fflush(0);
		temp = temp->link;
	}
	//printf("endmakewhile\n");fflush(0);

	TOKEN gototok = talloc();
	gototok->tokentype = OPERATOR;
	gototok->whichval = GOTOOP;
	TOKEN gotonum = copytok(number);
	temp->link = unaryop(gototok, gotonum);
	
	//printf("\nend makewhile\n");fflush(0);

	return progn;
}

TOKEN instenum(TOKEN idlist) {
	//printf("\n in instenum\n");fflush(0);

	int low = 0;
	int high = 0;
	TOKEN t = idlist;
	while(t) {
		t = t->link;
		high++;
	}
	TOKEN subrange = makesubrange(copytok(idlist), low, high - 1);
	t = idlist;
	TOKEN number = copytok(idlist);
	number->tokentype = NUMBERTOK;
	number->datatype = INTEGER;
	
	int i = 0;
	for(; i < high; i++) {
		number->intval = i;
		instconst(t, number);
		number = copytok(number);
		t = t->link;
	}

	//printf("\n end instenum\n");fflush(0);

	return subrange;
}

TOKEN makesubrange(TOKEN tok, int low, int high) {
	//printf("\nin makesubrange\n");fflush(0);
	TOKEN out = copytok(tok);
	SYMBOL subrange = symalloc();
	subrange->kind = SUBRANGE;
	subrange->basicdt = INTEGER;
	subrange->lowbound = low;
	subrange->highbound = high;
	subrange->size = basicsizes[INTEGER];
	out->symtype = subrange;

	//printf("\nend makesubrange\n");fflush(0);
	return out;
}

TOKEN arrayref(TOKEN arr, TOKEN tok, TOKEN subs, TOKEN tokb) {
	//printf("\n in arrayref\n");fflush(0);
	int i = 0;
	int is2d = 0;
	if(subs->link) {
		is2d = 1;
	}

	TOKEN t;
	SYMBOL s = searchst(arr->stringval);
	SYMBOL type = s->datatype->datatype->datatype;
	SYMBOL prevtype = s->datatype;

	if(is2d) {
		type = s->datatype->datatype;
		if(subs->tokentype == IDENTIFIERTOK) {
			
			TOKEN size = talloc();
			size->tokentype = NUMBERTOK;
			size->datatype = INTEGER;
			size->intval = type->size;
			
			TOKEN top = talloc();
			top->tokentype = OPERATOR;
			top->whichval = TIMESOP;
			
			t = binop(top, size, subs);
			TOKEN plus = copytok(top);
			plus->whichval = PLUSOP;
			TOKEN neg = copytok(size);
			neg->intval = -neg->intval + 4;
			t = binop(plus, neg, t);
			i = 1;
		}	
		
		int offset = type->size * (subs->intval - 1);
		TOKEN aref = talloc();
		aref->tokentype = OPERATOR;
		aref->whichval = AREFOP;
		aref->operands = arr;
		
		if(i) {
			arr->link = t;
		} else {
			subs->intval = offset;
			arr->link = subs;
		}
		aref->symtype = prevtype;				
		//printf("\n end arrayref\n");fflush(0);
		return aref;
	} else {
		if(subs->tokentype == IDENTIFIERTOK) {
			TOKEN size = talloc();
			size->tokentype = NUMBERTOK;
			size->datatype = INTEGER;
			size->intval = type->size;
			
			TOKEN top = talloc();
			top->tokentype = OPERATOR;
			top->whichval = TIMESOP;
			
			t = binop(top, size, subs);
			TOKEN plus = copytok(top);
			plus->whichval = PLUSOP;
			TOKEN neg = copytok(size);
			neg->intval = -neg->intval;
			t = binop(plus, neg, t);
			i = 1;
		}	
		
		int offset = type->size * (subs->intval - 1);
		TOKEN aref = talloc();
		aref->tokentype = OPERATOR;
		aref->whichval = AREFOP;
		aref->operands = arr;
		if(i) {
			arr->link = t;
		} else {
			subs->intval = offset;
			arr->link = subs;
		}
		aref->symtype = prevtype;
		//printf("\n end arrayref\n");fflush(0);				
		return aref;
	}
}


TOKEN reducedot(TOKEN var, TOKEN dot, TOKEN field) {
	int ispointer = 0;
	SYMBOL fields = var->symtype->datatype->datatype->datatype;
	while(fields) {
		if(strcmp(fields->namestring, field->stringval) == 0) {
			ispointer = 1;
		}
		fields = fields->link;
	}
	SYMBOL s;
	if(ispointer) {
		s = var->symtype->datatype->datatype->datatype;
		int offset = 0;
		while(s && (strcmp(s->namestring, field->stringval) != 0)) {
			offset += s->size;
			if((offset % 8 != 0) && (s->size == 8)){
				offset += 4;
			}
			s = s->link;
		}
		var->operands->link->intval += offset;
		
		return var;
	} else {
		SYMBOL r = var->symtype->datatype->datatype->datatype;
		s = r->datatype->datatype;
		TOKEN aref = talloc();
		aref->tokentype = OPERATOR;
		aref->whichval = AREFOP;
		aref->operands = var;
	
		int offset = 0;
		while(s && (strcmp(s->namestring, field->stringval) != 0)) {
			offset += s->size;
			if((offset % 8 != 0) && (s->size == 8)) {
				offset += 4;
			}
			s = s->link;
		}
		aref->symtype = s;
		
		if((offset % 8 != 0) && (s->size == 8)) {
				offset += 4;
		}
			
		TOKEN numtok = talloc();
		numtok->tokentype = NUMBERTOK;
		numtok->datatype = INTEGER;
		numtok->intval = offset;
		var->link = numtok;
	
		return aref;
	}
}

TOKEN dopoint(TOKEN var, TOKEN tok) {
	//printf("\n in dopoint\n");fflush(0);
	SYMBOL s = searchst(var->stringval);
	TOKEN t = talloc();
	t->tokentype = OPERATOR;
	t->whichval = POINTEROP;
	t->operands = var;
	
	if(var->whichval == AREFOP) {
		t->symtype = var->symtype;
		//printf("\n end dopoint\n");fflush(0);
		return t;
	} else {
		t->symtype = s;
		//printf("\n end dopoint\n");fflush(0);
		return t;
	}
}

TOKEN dogoto(TOKEN tok, TOKEN labeltok) {
	//printf("\nin dogoto\n");fflush(0);
	TOKEN t = talloc();
	t->tokentype = OPERATOR;
	t->whichval = GOTOOP;
	TOKEN number = talloc();
	number->tokentype = NUMBERTOK;
	int i = 0;
	while(labeltable[i] != labeltok->intval) {
		i++;
	}
	number->intval = i;
	t->operands = number;
	//printf("\nend dogoto\n");fflush(0);
	return t;
}

TOKEN makeprogram(TOKEN name, TOKEN args, TOKEN statements) {
	//printf("\nin makeprogram\n");fflush(0);
	TOKEN program = talloc();
	TOKEN aux = talloc();
	program->tokentype = OPERATOR;
	program->whichval = PROGRAMOP;
	program->operands = name;
	
	aux = makeprogn(aux, args);
	name->link = aux;
	aux->link = statements;
	
	//printf("\nend makeprogram\n");fflush(0);
	return program;
}

TOKEN makeop(int opnum) {
	TOKEN tok = talloc();
	tok->tokentype = OPERATOR;
	tok->whichval = opnum;
	return tok;
}

TOKEN makerepeat(TOKEN tok, TOKEN statements, TOKEN tokb, TOKEN expr) {
	int labelnum = labelnumber;
	TOKEN label = makelabel();
	tok = makeprogn(tok, label);

	TOKEN statetok = makeprogn(tokb, statements);
	label->link = statetok;
	TOKEN gototok = makegoto(labelnum);
	TOKEN progn = makeprogn((TOKEN)talloc(), NULL);
	progn->link = gototok;

	TOKEN iftok = talloc();
	iftok = makeif(iftok, expr, progn, gototok);
	statetok->link = iftok;

	return tok;
}

TOKEN copytok(TOKEN origtok) {
	//printf("\nin copytok\n");fflush(0);
	TOKEN newtok = talloc();
	newtok->tokentype = origtok->tokentype;
	newtok->datatype = origtok->datatype;
	newtok->symtype = origtok->symtype;
	newtok->symentry = origtok->symentry;
	newtok->operands = origtok->operands;
	newtok->link = origtok->link;
	newtok->whichval = origtok->whichval;
	newtok->intval = origtok->intval;
	newtok->realval = origtok->realval;

	//printf("\nend copytok\n");fflush(0);

	return newtok;
}

TOKEN makeintc(int num) {
	//printf("\nin makeintc\n");fflush(0);

	TOKEN tok = talloc();
	tok->tokentype = NUMBERTOK;
	tok->datatype = INTEGER;
	tok->intval = num;

	//printf("\nend makeintc\n");fflush(0);

	return tok;
}

TOKEN makegoto(int label) {
	//printf("\nin makegoto\n");fflush(0);

	TOKEN tok = talloc();
	tok->tokentype = OPERATOR;
	tok->whichval = GOTOOP;
	tok->operands = makeintc(label);
	
	//printf("\nend makegoto\n");fflush(0);

	return tok;
}

TOKEN makelabel() {
	//printf("\nin makelabel\n");fflush(0);

	TOKEN tok = talloc();
	tok->tokentype = OPERATOR;
	tok->whichval = LABELOP;
	tok->operands = makeintc(labelnumber);
	labelnumber+=1;
	//printf("\nend makelabel\n");fflush(0);

	return tok;
}

TOKEN makefor(int sign, TOKEN tok, TOKEN asg, TOKEN tokb, TOKEN endexpr, TOKEN tokc, TOKEN statement) {
	TOKEN t = talloc();
	TOKEN t2 = copytok(asg->operands);
	TOKEN t3 = copytok(asg->operands);
	TOKEN t4 = copytok(asg->operands);
	TOKEN labeltok = makelabel();

	TOKEN compareop = talloc();
	TOKEN tokop = talloc();

	if(sign == 1) {
		compareop = makeop(LEOP);
		tokop = makeop(PLUSOP);
	} else if(sign == -1) {
		compareop = makeop(GEOP);
		tokop = makeop(MINUSOP);
	} else {
		compareop = makeop(LEOP);
		tokop = makeop(PLUS);
	}

	TOKEN t5 = talloc();
	t5 = makeprogn(t5, statement);
	
	TOKEN t6 = talloc();
	t6 = makeif(t6, compareop, t5, NULL);
	binop(compareop, t2, endexpr);
	
	TOKEN assignop = makeop(ASSIGNOP);
	TOKEN t7 = makeintc(1);
	
	binop(assignop, t3, tokop);
	binop(tokop, t4, t7);
	
	t = makeprogn(t, asg);
	asg->link = labeltok;
	labeltok->link = t6;
	statement->link = assignop;
	assignop->link = makegoto(labelnumber - 1);
	
	return t;
}


TOKEN makefuncall(TOKEN tok, TOKEN fn, TOKEN args) {
        //printf("\nin makefuncall\n");fflush(0);
	//dbugprinttok(tok);
        //dbugprinttok(fn);
        //dbugprinttok(args);

        tok->operands = fn;
        tok->whichval = FUNCALLOP;
        tok->datatype = fn->datatype;
        tok->tokentype = OPERATOR;
        fn->link = args;

        //printf("\nend makefuncall\n");fflush(0);

        return tok;
}

TOKEN makeprogn(TOKEN tok, TOKEN statements)
  {
	//printf("\nin makeprog\n");fflush(0);	
  tok->tokentype = OPERATOR;
     tok->whichval = PROGNOP;
     tok->operands = statements;
     if (DEBUG & DB_MAKEPROGN)
       { printf("makeprogn\n");fflush(0);
         dbugprinttok(tok);
         dbugprinttok(statements);
       };
	//printf("\nend makeprog\n");fflush(0);	

     return tok;
   }

int wordaddress(int n, int wordsize)
  { return ((n + wordsize - 1) / wordsize) * wordsize; }
 
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

int main(void) {
	int res;
	initsyms();
	res = yyparse();

	//printst();       /* to shorten, change to:  printstlevel(1);  */
	//printstlevel(1);

	//printf("yyparse result = %8d\n", res);
	//if (DEBUG & DB_PARSERES) dbugprinttok(parseresult);
	//ppexpr(parseresult);           /* Pretty-print the result tree */
	/* uncomment following to call code generator. */
	
	gencode(parseresult, blockoffs[blocknumber], labelnumber);
 
  }
