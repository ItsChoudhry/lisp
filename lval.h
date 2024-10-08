#include "mpc.h"

struct lval;
struct lenv;

typedef struct lval lval;
typedef struct lenv lenv;

enum { LVAL_ERR, LVAL_NUM, LVAL_SYM, LVAL_FUN, LVAL_SEXPR, LVAL_QEXPR };

typedef lval *(*lbuiltin)(lenv *, lval *);

struct lval {
  int type;
  long num;
  char *err;
  char *sym;
  lbuiltin fun;
  int count;
  struct lval **cell;
};

struct lenv {
  int count;
  char **syms;
  lval **vals;
};

lval *lval_num(long x);
lval *lval_err(char *m);
lval *lval_sym(char *s);
lval *lval_sexpr(void);
lval *lval_qexpr(void);
lval *lval_fun(lbuiltin func);
void lval_del(lval *v);
lval *lval_add(lval *v, lval *x);
lval *lval_pop(lval *v, int i);
lval *lval_take(lval *v, int i);
lval *lval_copy(lval *v);
void lval_expr_print(lval *v, char open, char close);
void lval_print(lval *v);
void lval_println(lval *v);
lval *lval_eval_sexpr(lval *v);
lval *lval_eval(lval *v);
lval *lval_read_num(mpc_ast_t *t);
lval *lval_read(mpc_ast_t *t);
lval *lval_join(lval *x, lval *y);
lval *builtin_op(lval *a, char *op);
lval *builtin_head(lval *a);
lval *builtin_tail(lval *a);
lval *builtin_list(lval *a);
lval *builtin_eval(lval *a);
lval *builtin_join(lval *a);
lval *builtin(lval *a, char *func);

lenv *lenv_new(void);
void lenv_del(lenv *e);
lval *lenv_get(lenv *e, lval *k);
void lenv_put(lenv *e, lval *k, lval *v);
