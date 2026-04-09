{\rtf1\ansi\ansicpg1252\cocoartf2868
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fnil\fcharset0 .AppleSystemUIFontMonospaced-Regular;}
{\colortbl;\red255\green255\blue255;\red236\green244\blue251;\red12\green14\blue18;}
{\*\expandedcolortbl;;\cssrgb\c94118\c96471\c98824;\cssrgb\c5098\c6667\c9020;}
\margl1440\margr1440\vieww18880\viewh24100\viewkind0
\deftab720
\pard\pardeftab720\partightenfactor0

\f0\fs24 \cf2 \cb3 \expnd0\expndtw0\kerning0
cmake_minimum_required(VERSION 3.10)\
project(CommitCompass VERSION 0.1 LANGUAGES CXX)\
\
set(CMAKE_CXX_STANDARD 17)\
set(CMAKE_CXX_STANDARD_REQUIRED ON)\
\
find_package(CURL REQUIRED)\
\
add_executable(commitcompass\
  src/main.cpp\
  src/http_client.cpp\
  src/github_parser.cpp\
)\
\
target_include_directories(commitcompass PRIVATE include third_party)\
target_link_libraries(commitcompass PRIVATE CURL::libcurl)}
