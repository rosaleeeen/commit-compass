{\rtf1\ansi\ansicpg1252\cocoartf2868
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww18880\viewh23380\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include <iostream>\
#include "http_client.hpp"\
#include "github_parser.hpp"\
\
int main(int argc, char** argv) \{\
    if (argc < 2) \{\
        std::cerr << "Please provide a GitHub username.\\n";\
        return 1;\
    \}\
    std::string username = argv[1];\
    std::string url = "https://api.github.com/users/" + username + "/events";\
    auto resp = http_get(url, \'93commitcompass-cpp");\
    if (resp.status == 0) \{\
        std::cerr << "Network error.\\n";\
        return 1;\
    \}\
    if (resp.status == 404) \{\
        std::cerr << "User not found. Please check the username.\\n";\
        return 1;\
    \}\
    if (resp.status < 200 || resp.status >= 300) \{\
        std::cerr << "Error fetching data: " << resp.status << "\\n";\
        return 1;\
    \}\
    auto messages = parse_and_format_events(resp.body);\
    if (messages.empty()) \{\
        std::cout << "No recent activity found.\\n";\
        return 0;\
    \}\
    for (const auto &m : messages) std::cout << "- " << m << "\\n";\
    return 0;\
\}\
}