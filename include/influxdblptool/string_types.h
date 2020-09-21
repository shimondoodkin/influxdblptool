#ifndef INFLUXDBLPTOOL_VALIDATED_SERIALIZABLE_STRING_H
#define INFLUXDBLPTOOL_VALIDATED_SERIALIZABLE_STRING_H
#include <string>
#include "influxdblptool/abstractions/serializable.h"
#include "influxdblptool/validators.h"
#include "influxdblptool/escapers.h"

namespace influxdblptool {
    namespace internal {

        template <auto throw_when_invalid, auto escape>
        class validated_serializable_string : public influxdblptool::abstractions::serializable {
            std::string value_;
        public:
            explicit validated_serializable_string(std::string_view input) : value_{input} {
                throw_when_invalid(value_);
            }

            explicit validated_serializable_string(const char *input) : value_{input} {
                throw_when_invalid(value_);
            }

            explicit validated_serializable_string(std::string input) : value_{input} {
                throw_when_invalid(value_);
            }

            explicit validated_serializable_string(const validated_serializable_string &input) : value_{input.value_} {
                throw_when_invalid(value_);
            }

            explicit validated_serializable_string(const validated_serializable_string &&input) : value_{
                std::move(input.value_)} {
                throw_when_invalid(value_);
            }

            validated_serializable_string &operator=(std::string s) {
                value_ = std::move(s);
                throw_when_invalid(value_);
                return *this;
            }

            operator std::string() const {
                return value_;
            }

            operator std::string_view() const {
                return value_;
            }

            const std::string &operator*() const {
                return value_;
            }

            void serialize(std::ostream &s) const override {
                s << escape(value_);
            }

            bool operator<(const validated_serializable_string&rhs) const {
                return value_<rhs.value_;
            }

            bool operator>(const validated_serializable_string&rhs) const {
                return value_>rhs.value_;
            }

            bool operator==(const validated_serializable_string&rhs) const {
                return value_==rhs.value_;
            }

            bool operator!=(const validated_serializable_string&rhs) const {
                return value_!=rhs.value_;
            }
        };
    }

    using tag_key = internal::validated_serializable_string<validators::throw_when_tag_key_invalid,escapers::escape_tag_key>;
    using tag_value = internal::validated_serializable_string<validators::throw_when_tag_value_invalid,escapers::escape_tag_value>;
    using field_key = internal::validated_serializable_string<validators::throw_when_field_key_invalid,escapers::escape_field_key>;
    using field_string_value = internal::validated_serializable_string<validators::throw_when_field_string_value_invalid,escapers::escape_field_string_value>;
    using measurement = internal::validated_serializable_string<validators::throw_when_measurement_invalid,escapers::escape_measurement>;

}

#endif //INFLUXDBLPTOOL_VALIDATED_SERIALIZABLE_STRING_H