//
// Created by HYPERPC on 5/25/2022.
//

#include "request_type.hpp"

#include <sstream>

namespace web_cli {

    std::ostream &operator<<(std::stringstream &ostream, const web_cli::MediaType &obj) {
        ostream << obj.p_type;
        ostream << std::string("/");
        ostream << obj.p_subtype;

        if (obj.p_rawCharset != "NOT SET") {
            ostream << std::string("; charset=");
            ostream << obj.p_rawCharset;
        }

        return ostream;
    }

    std::string MediaType::asString() {
        std::stringstream ostream;

        ostream << this;

        return ostream.str();
    }

    std::ostream &operator<<(std::stringstream &ostream, const RequestBody &obj) {
        ostream << obj.p_rawBody;
        return ostream;
    }

    std::string RequestBody::asString() {
        std::stringstream ostream;

        ostream << this;

        return ostream.str();
    }
} // namespace web_cli