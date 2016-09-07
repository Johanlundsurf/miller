#ifndef FUNCTION_MANAGER_H
#define FUNCTION_MANAGER_H

#include "containers/lhmsv.h"
#include "containers/lhmsi.h"
#include "containers/mlr_dsl_ast.h" // xxx factor out this dependency?
#include "mapping/rval_evaluator.h"
#include "mapping/type_inference.h"

// ----------------------------------------------------------------
struct _function_lookup_t;
typedef struct _fmgr_t {
	struct _function_lookup_t * function_lookup_table;
	lhmsv_t* pUDF_names_to_evaluators;
	lhmsi_t* pUDF_names_to_arities;
} fmgr_t;

// ----------------------------------------------------------------
fmgr_t* fmgr_alloc();

void fmgr_free(fmgr_t* pfmgr);

// xxx disallow redefine ?
void fmgr_install_UDF(fmgr_t* pfmgr, char* name, int arity, rval_evaluator_t* pevaluator);

rval_evaluator_t* fmgr_alloc_from_operator_or_function(fmgr_t* pfmgr, mlr_dsl_ast_node_t* pnode,
	int type_inferencing, int context_flags);

void fmgr_list_functions(fmgr_t* pfmgr, FILE* output_stream, char* leader);

// Pass function_name == NULL to get usage for all functions:
void fmgr_function_usage(fmgr_t* pfmgr, FILE* output_stream, char* function_name);

void fmgr_list_all_functions_raw(fmgr_t* pfmgr, FILE* output_stream);

#endif // FUNCTION_MANAGER_H