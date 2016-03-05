/*
 * =====================================================================================
 *
 *       Filename:  env.h
 *
 *    Description:  ENV_ set up base environments, environment entries
 *
 *        Version:  1.0
 *        Created:  03/05/2016 03:38:40 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Neel Shah (), neelshah.sa@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */


#ifndef  env_INC
#define  env_INC

#include "types.h"
#include "symbol.h"

typedef struct ENV_entry_ *ENV_entry;

struct ENV_entry_ {
    enum { ENV_varEntry, ENV_funEntry } kind;
    union {
        struct {Ty_ty type;} var;
        struct {Ty_tyList formals; Ty_ty result;} fun;
    } u;
};

ENV_entry ENV_VarEntry(Ty_ty type);
ENV_entry ENV_FunEntry(Ty_tyList formals, Ty_ty result);

S_table ENV_base_tenv(void);
S_table ENV_base_venv(void);


#endif   /* ----- #ifndef env_INC  ----- */
