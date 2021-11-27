#include <string>

enum class Color {
    Red,
    Green,
    Yellow,
    Magenta,
    Cyan,
    White
};

enum class Modifier {
    Reset,
    Bold,
    Underline
};

static std::string ConvertColor(Color color)
{
    switch(color)
    {
    case Color::Red:
        return "31";
    case Color::Green:
        return "32";
    case Color::Yellow:
        return "33";
    case Color::Magenta:
        return "35";
    case Color::Cyan:
        return "36";
    case Color::White:
        return "37";
    }
}

static std::string ConvertModifier(Modifier modifier)
{
    switch(modifier)
    {
    case Modifier::Reset:
        return "0";
    case Modifier::Bold:
        return "1";
    case Modifier::Underline:
        return "4";
    }
}

static std::string Format(Color color, Modifier modifier)
{
    return "\033[" + ConvertModifier(modifier) + ";" + ConvertColor(color) + "m";
}

namespace std
{
    std::string red()       { return Format(Color::Red, Modifier::Bold); }
    std::string green()     { return Format(Color::Green, Modifier::Bold); }
    std::string yellow()    { return Format(Color::Yellow, Modifier::Bold); }
    std::string magenta()   { return Format(Color::Magenta, Modifier::Bold); }
    std::string cyan()      { return Format(Color::Cyan, Modifier::Bold); }
    std::string white()     { return Format(Color::White, Modifier::Reset); }
}
