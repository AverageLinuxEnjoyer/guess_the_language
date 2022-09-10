#include "../include/languages.h"

using Type = Language::Type;

std::map<Type, std::pair<std::string, std::string>> Language::map = {
    {Language::Javascript, {"javascript", "Javascript"}},
    {Language::Html, {"html", "HTML"}},
    {Language::Css, {"css", "CSS"}},
    {Language::Python, {"python", "Python"}},
    {Language::SQL, {"sql", "SQL"}},
    {Language::Java, {"java", "Java"}},
    {Language::TypeScript, {"typescript", "TypeScript"}},
    {Language::CSharp, {"csharp", "C#"}},
    {Language::Bash, {"bash", "Bash"}},
    {Language::Cpp, {"cpp", "C++"}},
    {Language::Php, {"php", "PHP"}},
    {Language::C, {"c", "C"}},
    {Language::PowerShell, {"powershell", "PowerShell"}},
    {Language::Go, {"go", "Go"}},
    {Language::Kotlin, {"kotlin", "Kotlin"}},
    {Language::Rust, {"rust", "Rust"}},
    {Language::Ruby, {"ruby", "Ruby"}},
    {Language::Dart, {"dart", "Dart"}},
    {Language::Assembly, {"assembly", "Assembly"}},
    {Language::Swift, {"swift", "Swift"}},
    {Language::R, {"r", "R"}},
    {Language::VBA, {"vba", "Visual Basic"}},
    {Language::Matlab, {"matlab", "Matlab"}},
    {Language::Groovy, {"groovy", "Groovy"}},
    {Language::Objective_C, {"objectivec", "Objective C"}},
    {Language::Scala, {"scala", "Scala"}},
    {Language::Perl, {"perl", "Perl"}},
    {Language::Haskell, {"haskell", "Haskell"}},
    {Language::Delphi, {"delphi", "Delphi"}},
    {Language::Clojure, {"clojure", "Clojure"}},
    {Language::Elixir, {"elixir", "Elixir"}},
    {Language::LISP, {"lisp", "Lisp"}},
    {Language::Julia, {"julia", "Julia"}},
    {Language::FSharp, {"fsharp", "F#"}},
    {Language::Erlang, {"erlang", "Erlang"}},
    {Language::Crystal, {"crystal", "Crystal"}},
    {Language::COBOL, {"cobol", "Cobols"}},
};

std::string Language::get_github_string(Type type) {
  return Language::map[type].first;
}

std::string Language::get_display_string(Type type) {
  return Language::map[type].second;
}
