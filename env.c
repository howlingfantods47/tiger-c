/*
 * =====================================================================================
 *
 *       Filename:  env.c
 *
 *    Description:  see env.h
 *
 *        Version:  1.0
 *        Created:  03/05/2016 03:52:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Neel Shah (), neelshah.sa@gmail.com
 *   Organization:
 *
 * =====================================================================================
 */

#include <stdlib.h>
#include "env.h"
#include "util.h"

ENV_entry ENV_VarEntry(Ty_ty type) {
    ENV_entry entry = checked_malloc(sizeof(*entry));
    entry->kind = ENV_varEntry;
    entry->u.var.type = type;
    return entry;
}

ENV_entry ENV_FunEntry(Ty_tyList formals, Ty_ty result) {
    ENV_entry entry = checked_malloc(sizeof(*entry));
    entry->kind = ENV_funEntry;
    entry->u.fun.formals = formals;
    entry->u.fun.result = result;
    return entry;
}

S_table ENV_base_tenv(void) {
    S_table tenv = S_empty();
    S_enter(tenv, S_Symbol("int"), Ty_Int());
    S_enter(tenv, S_Symbol("string"), Ty_String());
    return tenv;
}

S_table ENV_base_venv(void) {
    S_table venv = S_empty();

    // tiger starndard lib functions
    ENV_entry env_print = ENV_FunEntry(
            Ty_TyList(Ty_String(), NULL),
            Ty_Void()
            );
    S_enter(venv, S_Symbol("print"), env_print);

    ENV_entry env_flush = ENV_FunEntry(
            NULL,
            Ty_Void()
            );
    S_enter(venv, S_Symbol("flush"), env_flush);

    ENV_entry env_getchar = ENV_FunEntry(
            NULL,
            Ty_String()
            );
    S_enter(venv, S_Symbol("getchar"), env_getchar);

    ENV_entry env_ord = ENV_FunEntry(
            Ty_TyList(Ty_String(), NULL),
            Ty_Int()
            );
    S_enter(venv, S_Symbol("ord"), env_ord);


    ENV_entry env_chr = ENV_FunEntry(
            Ty_TyList(Ty_Int(), NULL),
            Ty_String()
            );
    S_enter(venv, S_Symbol("chr"), env_chr);

    ENV_entry env_size = ENV_FunEntry(
            Ty_TyList(Ty_String(), NULL),
            Ty_Int()
            );
    S_enter(venv, S_Symbol("size"), env_size);

    ENV_entry env_substring = ENV_FunEntry(
            Ty_TyList(Ty_String(), Ty_TyList(
                    Ty_Int(), Ty_TyList(Ty_Int(), NULL))
                ),
            Ty_String()
            );
    S_enter(venv, S_Symbol("substring"), env_substring);

   ENV_entry env_concat = ENV_FunEntry(
            Ty_TyList(Ty_String(), Ty_TyList(
                    Ty_String(), NULL)
                ),
            Ty_String()
            );
    S_enter(venv, S_Symbol("concat"), env_concat);

    ENV_entry env_not = ENV_FunEntry(
            Ty_TyList(Ty_Int(), NULL),
            Ty_Int()
            );
    S_enter(venv, S_Symbol("not"), env_not);

    ENV_entry env_exit = ENV_FunEntry(
            Ty_TyList(Ty_Int(), NULL),
            Ty_Void()
            );
    S_enter(venv, S_Symbol("exit"), env_exit);



    return venv;

}
