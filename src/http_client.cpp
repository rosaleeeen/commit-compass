{\rtf1\ansi\ansicpg1252\cocoartf2868
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\margl1440\margr1440\vieww18880\viewh23380\viewkind0
\pard\tx720\tx1440\tx2160\tx2880\tx3600\tx4320\tx5040\tx5760\tx6480\tx7200\tx7920\tx8640\pardirnatural\partightenfactor0

\f0\fs24 \cf0 #include "http_client.hpp"\
#include <curl/curl.h>\
\
static size_t write_cb(void* ptr, size_t size, size_t nmemb, void* userdata) \{\
    std::string* s = static_cast<std::string*>(userdata);\
    s->append(static_cast<char*>(ptr), size * nmemb);\
    return size * nmemb;\
\}\
\
HttpResponse http_get(const std::string &url, const std::string &user_agent) \{\
    CURL* curl = curl_easy_init();\
    HttpResponse res\{0, ""\};\
    if (!curl) return res;\
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());\
    struct curl_slist* headers = nullptr;\
    std::string ua = "User-Agent: " + user_agent;\
    headers = curl_slist_append(headers, ua.c_str());\
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);\
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);\
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &res.body);\
    CURLcode rc = curl_easy_perform(curl);\
    if (rc == CURLE_OK) curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &res.status);\
    curl_slist_free_all(headers);\
    curl_easy_cleanup(curl);\
    return res;\
\}\
}