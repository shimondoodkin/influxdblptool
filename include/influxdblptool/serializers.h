#ifndef INFLUXDBLPTOOL_SERIALIZERS_H
#define INFLUXDBLPTOOL_SERIALIZERS_H
#include <ostream>
#include "field_value.h"
#include <map>
#include <vector>
#include "string_types.h"
#include "point.h"

namespace influxdblptool::serializers {

    std::ostream& operator<<(std::ostream& s, const tag_key& tk);
    std::ostream& operator<<(std::ostream& s, const tag_value& tv);
    std::ostream& operator<<(std::ostream& s, const field_key& fk);
    std::ostream& operator<<(std::ostream& s, const field_string_value& fsv);
    std::ostream& operator<<(std::ostream& s, const measurement_value& mv);
    std::ostream& operator<<(std::ostream& s, const field_variant& fv);
    std::ostream& operator<<(std::ostream& s, const fields_map& items);
    std::ostream& operator<<(std::ostream& s, const tags_map& items);
    std::ostream& operator<<(std::ostream& s, const point& item);
    std::ostream& operator<<(std::ostream& s, const points& items);

}


#endif //INFLUXDBLPTOOL_SERIALIZERS_H
