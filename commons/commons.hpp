//
// Created by HYPERPC on 5/25/2022.
//

#ifndef WEB_CLIENT_COMMONS_HPP
#define WEB_CLIENT_COMMONS_HPP

#include <string>

namespace web_cli::commons {

    class IToString {
    public:
        virtual std::string asString() = 0;
    };

} // web_cli

#endif //WEB_CLIENT_COMMONS_HPP
