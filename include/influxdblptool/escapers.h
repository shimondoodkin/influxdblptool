#ifndef INFLUXDBLPTOOL_ESCAPERS_H
#define INFLUXDBLPTOOL_ESCAPERS_H
#include <algorithm>
#include <sstream>
#include <array>

namespace influxdblptool::escapers {

    std::string escape_measurement_value(std::string_view s);
    std::string escape_tag_key(std::string_view s);
    std::string escape_tag_value(std::string_view s);
    std::string escape_field_key(std::string_view s);
    std::string escape_field_string_value(std::string_view s);

}

#endif //INFLUXDBLPTOOL_ESCAPERS_H
