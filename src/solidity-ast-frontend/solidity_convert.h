#ifndef SOLIDITY_AST_FRONTEND_SOLIDITY_CONVERT_H_
#define SOLIDITY_AST_FRONTEND_SOLIDITY_CONVERT_H_

//#define __STDC_LIMIT_MACROS
//#define __STDC_FORMAT_MACROS

#include <memory>
#include <util/context.h>
#include <util/namespace.h>
#include <util/std_types.h>
#include <nlohmann/json.hpp>
#include <solidity-ast-frontend/solidity_type.h>
#include <solidity-ast-frontend/solidity_decl_tracker.h>

using varDeclTrackerPtr = std::shared_ptr<VarDeclTracker>&;

class solidity_convertert
{
public:
  solidity_convertert(
    contextt &_context,
    nlohmann::json &_ast_json);
  virtual ~solidity_convertert() = default;

  bool convert();

protected:
  contextt &context;
  nlohmann::json &ast_json; // json for Solidity AST. Use vector for multiple contracts
  void print_json_element(nlohmann::json &json_in, const unsigned index,
    const std::string &key, const std::string& json_name);
  void print_json_array_element(nlohmann::json &json_in,
      const std::string& node_type, const unsigned index);

  unsigned int current_scope_var_num; // tracking scope while getting declarations

  bool convert_ast_nodes(nlohmann::json &contract_def);

  bool get_decl(nlohmann::json &ast_node, exprt &new_expr);
  bool get_var(varDeclTrackerPtr vd_tracker, exprt &new_expr);
  bool get_type(const QualTypeTracker &q_type, typet &new_type); // bool clang_c_convertert::get_type(const clang::QualType &q_type, typet &new_type)
  bool get_sub_type(const QualTypeTracker &q_type, typet &new_type); // bool clang_c_convertert::get_type(const clang::Type &the_type, typet &new_type)
  bool get_builtin_type(const QualTypeTracker &q_type, typet &new_type);
};

#endif /* SOLIDITY_AST_FRONTEND_SOLIDITY_CONVERT_H_ */
