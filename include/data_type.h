/*
 * Use and distribution licensed under the Apache license version 2.
 *
 * See the COPYING file in the root project directory for full text.
 */

#ifndef SQLTOAST_DATA_TYPE_H
#define SQLTOAST_DATA_TYPE_H

#include <string>

namespace sqltoast {

typedef enum data_type {
    DATA_TYPE_CHAR,
    DATA_TYPE_VARCHAR,
    DATA_TYPE_NCHAR,
    DATA_TYPE_VARNCHAR,
    DATA_TYPE_BIT,
    DATA_TYPE_VARBIT,
    DATA_TYPE_NUMERIC,
    DATA_TYPE_DECIMAL,
    DATA_TYPE_INT,
    DATA_TYPE_SMALLINT,
    DATA_TYPE_FLOAT,
    DATA_TYPE_DOUBLE,
    DATA_TYPE_DATE,
    DATA_TYPE_TIME,
    DATA_TYPE_TIMESTAMP,
    DATA_TYPE_INTERVAL
} data_type_t;

typedef struct data_type_descriptor {
    data_type_t type;
    data_type_descriptor(data_type_t type) : type(type)
    {}
    virtual const std::string to_string() = 0;
} data_type_descriptor_t;

typedef struct character_string : data_type_descriptor_t {
    character_string() :
        data_type_descriptor_t(DATA_TYPE_CHAR)
    {}
    virtual const std::string to_string();
} character_string_t;

} // namespace sqltoast

#endif /* SQLTOAST_DATA_TYPE_H */