/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#include "symbol.h"

namespace sqltoast {

symbol_map::symbol_map_t  _init_symbol_map() {
    symbol_map::symbol_map_t m;

    m[SYMBOL_SOS] = std::string("SOS");
    m[SYMBOL_EOS] = std::string("EOS");

    // Punctuators
    m[SYMBOL_SEMICOLON] = std::string("SEMICOLON");
    m[SYMBOL_COMMA] = std::string("COMMA");
    m[SYMBOL_LPAREN] = std::string("LPAREN");
    m[SYMBOL_RPAREN] = std::string("RPAREN");

    // Reserved keywords
    m[SYMBOL_AUTHORIZATION] = std::string("AUTHORIZATION");
    m[SYMBOL_BIT] = std::string("BIT");
    m[SYMBOL_CASCADE] = std::string("CASCADE");
    m[SYMBOL_CHAR] = std::string("CHAR");
    m[SYMBOL_CHARACTER] = std::string("CHARACTER");
    m[SYMBOL_CREATE] = std::string("CREATE");
    m[SYMBOL_DEC] = std::string("DEC");
    m[SYMBOL_DECIMAL] = std::string("DECIMAL");
    m[SYMBOL_DEFAULT] = std::string("DEFAULT");
    m[SYMBOL_DROP] = std::string("DROP");
    m[SYMBOL_DOUBLE] = std::string("DOUBLE");
    m[SYMBOL_FLOAT] = std::string("FLOAT");
    m[SYMBOL_GLOBAL] = std::string("GLOBAL");
    m[SYMBOL_INT] = std::string("INT");
    m[SYMBOL_INTEGER] = std::string("INTEGER");
    m[SYMBOL_LOCAL] = std::string("LOCAL");
    m[SYMBOL_NATIONAL] = std::string("NATIONAL");
    m[SYMBOL_NCHAR] = std::string("NCHAR");
    m[SYMBOL_NUMERIC] = std::string("NUMERIC");
    m[SYMBOL_PRECISION] = std::string("PRECISION");
    m[SYMBOL_REAL] = std::string("REAL");
    m[SYMBOL_RESTRICT] = std::string("RESTRICT");
    m[SYMBOL_SCHEMA] = std::string("SCHEMA");
    m[SYMBOL_SET] = std::string("SET");
    m[SYMBOL_SMALLINT] = std::string("SMALLINT");
    m[SYMBOL_TABLE] = std::string("TABLE");
    m[SYMBOL_TEMPORARY] = std::string("TEMPORARY");
    m[SYMBOL_VARCHAR] = std::string("VARCHAR");

    // Non-Reserved keywordsr

    // Other symbols
    m[SYMBOL_IDENTIFIER] = std::string("<< identifier >>");
    m[SYMBOL_COMMENT] = std::string("<< comment >>");
    m[SYMBOL_LITERAL_UNSIGNED_INTEGER] = std::string("<< unsigned integer >>");
    m[SYMBOL_LITERAL_SIGNED_INTEGER] = std::string("<< signed integer >>");
    m[SYMBOL_LITERAL_UNSIGNED_DECIMAL] = std::string("<< unsigned decimal >>");
    m[SYMBOL_LITERAL_SIGNED_DECIMAL] = std::string("<< signed decimal >>");
    m[SYMBOL_LITERAL_APPROXIMATE_NUMBER] = std::string("<< approximate number >>");

    return m;
}

symbol_map::symbol_map_t symbol_map::m = _init_symbol_map();

} // namespace sqltoast
