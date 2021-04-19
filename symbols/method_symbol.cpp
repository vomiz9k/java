#include "method_symbol.hpp"
#include <big_include.hpp>

MethodSymbol::MethodSymbol(Method_declaration* decl) {
    name = *decl->name;
    type = decl->type;
}

int MethodSymbol::SymbolType() {
    return SYMBOL_METHOD;
}
