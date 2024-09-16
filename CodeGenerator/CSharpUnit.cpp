#include "CSharpUnit.h"

std::string CSharpClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if (m_fields[i].empty()) {
            continue;
        }

        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 1);
            result += "\n";
        }
    }

    result += generateShift(level) + "}\n";
    return result;
}

std::string CSharpMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);

    if (m_flags & PUBLIC) {
        result += "public ";
    } else if (m_flags & PROTECTED) {
        result += "protected ";
    } else if (m_flags & PRIVATE) {
        result += "private ";
    } else if (m_flags & INTERNAL) {
        result += "internal ";
    }

    if (m_flags & STATIC) {
        result += "static ";
    } else if (m_flags & CONST) {
        result += "const ";
    } else if (m_flags & VIRTUAL) {
        result += "virtual ";
    }

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";
    return result;
}

std::string CSharpPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}
