#include "mpc.h"
#include <wchar.h>

typedef struct lval {
  int type;
  long num;
  char *err;
  char *sym;
  int count;
  struct lval **cell;
} lval;

enum { LVAL_NUM, LVAL_ERR, LVAL_SYM, LVAL_SEXPR };
enum { LERR_DIV_ZERO, LERR_BAD_OP, LERR_BAD_NUM };

lval *lval_num(long x);

lval *lval_err(char *x);

void lval_print(lval v);

void lval_println(lval v);

lval *lval_sexpr(void);

lval *lval_sym(char *s);

void lval_del(lval *v);

lval *lval_read_num(mpc_ast_t *t);

lval *lval_add(lval *v, lval *x);
