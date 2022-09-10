#ifndef LANGUAGES_H
#define LANGUAGES_H

#include <map>
#include <string>

class Language {
public:
  enum Type {
    Javascript,
    Html,
    Css,
    Python,
    SQL,
    Java,
    TypeScript,
    CSharp,
    Bash,
    Cpp,
    Php,
    C,
    PowerShell,
    Go,
    Kotlin,
    Rust,
    Ruby,
    Dart,
    Assembly,
    Swift,
    R,
    VBA,
    Matlab,
    Groovy,
    Objective_C,
    Scala,
    Perl,
    Haskell,
    Delphi,
    Clojure,
    Elixir,
    LISP,
    Julia,
    FSharp,
    Erlang,
    Crystal,
    COBOL,
  };

  Language() = delete;

  static std::string get_github_string(Type type);
  static std::string get_display_string(Type type);

private:
  static std::map<Type, std::pair<std::string, std::string>> map;
};

#endif // LANGUAGES_H
