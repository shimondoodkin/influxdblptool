#include "doctest.h"
#include "influxdblptool/field.h"
#include <sstream>

using namespace std::literals;
using namespace influxdblptool;

TEST_SUITE("field") {
    TEST_CASE("field_double works correctly") {
        SUBCASE("field_double accepts double") {
            CHECK_NOTHROW(field_double fd{1.0});
        }
        SUBCASE("field_double accepts float") {
            CHECK_NOTHROW(field_double fd{1.0f});
        }
        SUBCASE("field_double casts to double") {
            const double d{100.5};
            field_double fd{d};
            CHECK_EQ(d,double{fd});
        }
        SUBCASE("field_double throws when infinite double is given") {
            CHECK_THROWS_AS_MESSAGE(field_double{std::numeric_limits<double>::infinity()},validator_exception,"Infinite value not allowed.");
        }
        SUBCASE("field_double throws when infinite float is given") {
            CHECK_THROWS_AS_MESSAGE(field_double{std::numeric_limits<float>::infinity()},validator_exception,"Infinite value not allowed.");
        }
        SUBCASE("field_double throws when quiet_NaN double is given") {
            CHECK_THROWS_AS_MESSAGE(field_double{std::numeric_limits<double>::quiet_NaN()},validator_exception,"NaN value not allowed.");
        }
        SUBCASE("field_double throws when quiet_NaN float is given") {
            CHECK_THROWS_AS_MESSAGE(field_double{std::numeric_limits<float>::quiet_NaN()},validator_exception,"NaN value not allowed.");
        }
        SUBCASE("field_double throws when signaling_NaN double is given") {
            CHECK_THROWS_AS_MESSAGE(field_double{std::numeric_limits<double>::signaling_NaN()},validator_exception,"NaN value not allowed.");
        }
        SUBCASE("field_double throws when signaling_NaN float is given") {
            CHECK_THROWS_AS_MESSAGE(field_double{std::numeric_limits<float>::signaling_NaN()},validator_exception,"NaN value not allowed.");
        }
    }
    TEST_CASE("field constructs and serializes correctly") {
        SUBCASE("field accepts field_double and serializes correctly") {
            field f{field_double{100.5}};
            std::stringstream s;
            s << f;
            CHECK_EQ("100.5"s,s.str());
        }
        SUBCASE("field double and serializes correctly") {
            field f{100.5};
            std::stringstream s;
            s << f;
            CHECK_EQ("100.5"s,s.str());
        }
        SUBCASE("field accepts float and serializes correctly") {
            field f{100.5f};
            std::stringstream s;
            s << f;
            CHECK_EQ("100.5"s,s.str());
        }
        SUBCASE("field accepts bool true and serializes correctly") {
            field f{true};
            std::stringstream s;
            s << f;
            CHECK_EQ("t"s,s.str());
        }
        SUBCASE("field accepts bool true and serializes correctly") {
            field f{false};
            std::stringstream s;
            s << f;
            CHECK_EQ("f"s,s.str());
        }
        SUBCASE("field accepts const char* string and serializes correctly") {
            field f{"string"};
            std::stringstream s;
            s << f;
            CHECK_EQ("\"string\""s,s.str());
        }
        SUBCASE("field accepts string_view and serializes correctly") {
            field f{"string"sv};
            std::stringstream s;
            s << f;
            CHECK_EQ("\"string\""s,s.str());
        }
        SUBCASE("field accepts string and serializes correctly") {
            field f{"string"s};
            std::stringstream s;
            s << f;
            CHECK_EQ("\"string\""s,s.str());
        }
        SUBCASE("field accepts field_string_value and serializes correctly") {
            field_string_value v{"string"s};
            field f{v};
            std::stringstream s;
            s << f;
            CHECK_EQ("\"string\""s,s.str());
        }
        SUBCASE("field accepts uint64_t and serializes correctly") {
            field f{std::numeric_limits<uint64_t>::max()};
            std::stringstream s;
            s << f;
            CHECK_EQ("18446744073709551615"s,s.str());
        }
        SUBCASE("field accepts int64_t and serializes correctly") {
            field f{std::numeric_limits<int64_t>::min()};
            std::stringstream s;
            s << f;
            CHECK_EQ("-9223372036854775808"s,s.str());
        }
        SUBCASE("field accepts uint32_t and serializes correctly") {
            field f{std::numeric_limits<uint32_t>::max()};
            std::stringstream s;
            s << f;
            CHECK_EQ("4294967295"s,s.str());
        }
        SUBCASE("field accepts int32_t and serializes correctly") {
            field f{std::numeric_limits<int32_t>::min()};
            std::stringstream s;
            s << f;
            CHECK_EQ("-2147483648"s,s.str());
        }
        SUBCASE("field accepts uint16_t and serializes correctly") {
            field f{std::numeric_limits<uint16_t>::max()};
            std::stringstream s;
            s << f;
            CHECK_EQ("65535"s,s.str());
        }
        SUBCASE("field accepts int16_t and serializes correctly") {
            field f{std::numeric_limits<int16_t>::min()};
            std::stringstream s;
            s << f;
            CHECK_EQ("-32768"s,s.str());
        }
        SUBCASE("field accepts uint8_t and serializes correctly") {
            field f{std::numeric_limits<uint8_t>::max()};
            std::stringstream s;
            s << f;
            CHECK_EQ("255"s,s.str());
        }
        SUBCASE("field accepts int8_t and serializes correctly") {
            field f{std::numeric_limits<int8_t>::min()};
            std::stringstream s;
            s << f;
            CHECK_EQ("-128"s,s.str());
        }
    }
}