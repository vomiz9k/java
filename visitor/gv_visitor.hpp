#pragma once
#include "visitor.hpp"
#include <fstream>

class gv_visitor: public Visitor
{
    std::ofstream out;
    void box(const void* ptr, const std::string& name);
    void arrow(const void* first, const void* second);
    void arrow(const void* first, const void* second, const std::string& text);
public:
    gv_visitor(const std::string&);

    void visit(Program*) override; //program
    void visit(Main_class*) override;

    void visit(Not_empty_Class_declarations*) override;
    void visit(Empty_Class_declarations*) override;   
    
    void visit(Empty_Statements*) override;
    void visit(Not_empty_Statements*) override;

    void visit(Extended_Class_declaration*) override;
    void visit(Not_extended_Class_declaration*) override;

    void visit(If_else_Statement*) override;
    void visit(If_Statement*) override;
    void visit(Assert_Statement*) override;
    void visit(Var_decl_Statement*) override;
    void visit(Big_Statement*) override;
    void visit(While_Statement*) override;
    void visit(Print_Statement*) override;
    void visit(Assignment_Statement*) override;
    void visit(Return_Statement*) override;
    void visit(Method_invocation_Statement*) override;


    
    

    void visit(Declarations_with_variable*) override;
    void visit(Declarations_with_method*) override;
    void visit(Empty_Declarations*) override;

    void visit(Method_declaration*) override;
    void visit(Variable_declaration*) override;
    
    void visit(Empty_Method_args*) override;
    void visit(Single_Method_args*) override;
    void visit(Many_Method_args*) override;
    void visit(Method_arg*) override;
    void visit(Last_Method_multiple_arg*) override;
    void visit(Many_Method_multiple_arg*) override;

    void visit(Simple_Type*) override;
    void visit(Array_Type*) override;

    void visit(Assignment*) override;
    void visit(Method_invocation*) override;
    void visit(Field_invocation*) override;

    void visit(Empty_Expressions*) override;
    void visit(Single_Expressions*) override;
    void visit(Many_Expressions*) override;
    void visit(Single_Multiple_expressions*) override;
    void visit(Many_Multiple_expressions*) override;

    void visit(Value_Expr*) override;
    void visit(Id_Expr*) override;
    void visit(Array_el_Expr*) override;
    void visit(Length_Expr*) override;

    void visit(Field_invocation_Expr*) override;

    void visit(New_arr_Expr*) override;
    void visit(New_single_Expr*) override;
    void visit(This_Expr*) override;

    void visit(Not_Expr*) override;
    void visit(Method_invocation_Expr*) override;
    void visit(Plus_Expr*) override;
    void visit(Minus_Expr*) override;
    void visit(Star_Expr*) override;
    void visit(Slash_Expr*) override;
    void visit(Percent_Expr*) override;
    void visit(And_Expr*) override;
    void visit(Or_Expr*) override;
    void visit(Smaller_Expr*) override;
    void visit(Bigger_Expr*) override;
    void visit(Equal_Expr*) override;
    void visit(Not_equal_Expr*) override;
    void visit(Brackets_Expr*) override;

    void visit(Number_Value*) override;
    void visit(TF_Value*) override;
};