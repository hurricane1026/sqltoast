/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#include "compare.h"
#include "keyword.h"
#include "symbol.h"

namespace sqltoast {

kw_jump_table_t _init_kw_jump_table(char lead_char) {
    kw_jump_table_t t;

    switch (lead_char) {
        case 'c':
            t.push_back(kw_jump_table_entry_t(CREATE, std::string("CREATE")));
            return t;
        case 'd':
            t.push_back(kw_jump_table_entry_t(DATABASE, std::string("DATABASE")));
            return t;
    }
    return t;
}

kw_jump_table_t kw_jump_tables::c = _init_kw_jump_table('c');
kw_jump_table_t kw_jump_tables::d = _init_kw_jump_table('d');

bool keyword(parse_context_t& ctx) {
    kw_jump_table_t jump_tbl;
    switch (*ctx.cursor) {
        case 'c':
        case 'C':
            jump_tbl = kw_jump_tables::c;
            break;
        case 'd':
        case 'D':
            jump_tbl = kw_jump_tables::d;
            break;
        default:
            return false;
    }
    for (auto entry : jump_tbl) {
        const std::string to_end(parse_position_t(ctx.cursor), ctx.end_pos);
        if (ci_find_substr(to_end, entry.second) != -1) {
            ctx.current_symbol = entry.first;
            ctx.cursor += entry.second.size();
            return true;
        }
    }
    return false;
}

} // namespace sqltoast
