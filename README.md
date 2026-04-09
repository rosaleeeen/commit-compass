# 🧭 commit-compass 🐙
_your repo's little heartbeat monitor._

a cli that fetches a github user's recent public activity and prints short, human-friendly summaries. 

## features:
- fetches public events from github events api
- formats common events: pushes, issues, stars, forks, creates
- prints easy-to-scan lines like:
  - ```pushed 2 commit(s) to torvalds/linux```
  - ```starred someuser/somerepo```

## prereqs:
- c++17 toolchain (g++/clang++)
- libcurl (for http)
- nlohmann/json (single-header ```json.hpp```)

## build (two options):
1. vendor header (recommended, fast):
  - drop json.hpp into third_party/ (or include/).
  - from project root: ```mkdir -p build && cd build cmake .. cmake --build .```
2. direct compile: ```g++ -o commitcompass src/main.cpp src/http_client.cpp src/github_parser.cpp -lcurl -std=c++17 -Iinclude -Ithird_party```

## usage:
```./commitcompass``` 

_example:_ \
```./commitcompass torvalds``` 

_output:_ \
```pushed 2 commit(s) to torvalds/linux``` \
```starred someuser/somerepo```

## notes:
- unauthenticated github api = 60 requests/hour per ip. 
- parser assumes typical event payload shapes (robust enough for casual use).
- future improvements: paging, token auth, filters, nicer formatting.
