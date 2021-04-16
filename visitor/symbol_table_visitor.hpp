#pragma once
#include "visitor.hpp"
#include <base_scope.hpp>
#include <iostream>


class MethodSymbol;
class ClassSymbol;
class Simple_Type;
class Type;

class symbol_table_visitor: public Visitor
{
    Simple_Type* int_simple;
    Simple_Type* bool_simple;
    ClassSymbol* curr_class;
    MethodSymbol* curr_method;

public:
    symbol_table_visitor();

    ~symbol_table_visitor();

    #include "visitor_header_body"

    BaseScope* curr;

    void dump() {
        tabs = 0;
        dump(curr);
    }

    int tabs = 0;
    void dump(BaseScope* now) {
        for(auto i: now->symbols) {
            for(int i = 0; i < tabs; ++i) {
                std::cout << '\t';
            }
            std::cout << i.first << ' ';
        }
        std::cout << '\n';
        ++tabs;
        for (auto i: now->children) {
            dump(i);
        }
        --tabs;
    }

    BaseSymbol* Find(const std::string& name) {
        BaseScope* scope = curr;
        while (scope != nullptr && scope->symbols.count(name) == 0)
            scope = scope->parent;
        
        return scope == nullptr ? nullptr : scope->symbols[name];
    }

    BaseSymbol* Find(std::string* name) {
        return Find(*name);
    }



    void assert_declared(std::string* name, int type);

    void assert_not_declared_in_this_scope(std::string* name);

    void assert_type(const Type* checking, const Type* needed);

    void assert_array(Type* type);
};