# guess_the_language
Simple CLI programming language guessing game that fetches random code snippets from random files from random github repos and asks the user which one of the 4 given languages the code is written in.

![demo_gif](https://i.imgur.com/hRErJqa.gif)

The following libraries were used:
- [cpr](https://github.com/libcpr/cpr) for http requests
- [nlohmann's json](https://github.com/nlohmann/json) to work with the requests
- [fmt](https://github.com/fmtlib/fmt) for formatting
