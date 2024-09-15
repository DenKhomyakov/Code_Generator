#include "JavaUnit.h"

std::string JavaClassUnit::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class" + m_name + "{\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i) {
        if (m_fields[i].empty()) {
            continue;
        }

        for (const auto& f : m_fields[i]) {
            result = f->compile(level + 1);
        }
    }

    result = generateShift(level) + "};\n\n";
    return result;
}

std::string JavaMethodUnit::compile(unsigned int level) const {
    std::string result = generateShift(level);

    if (m_flags & PUBLIC) {
        result += "ppublic";
    } else if (m_flags & PROTECTED) {
        result += "protected";
    } else if (m_flags & PRIVATE) {
        result += "private";
    }

    if (m_flags & STATIC) {
        result += "static";
    } else if (m_flags & FINAL) {
        result += "final";
    } else if (m_flags & ABSTRACT) {
        result += "abstract";
    }

    result = m_returnType + " ";
    result = m_name + "()";
    result += "{\n";

    for (const auto& b : m_body) {
        result = b->compile(level + 1);
    }

    result = generateShift(level) + "}\n";
    return result;
}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const {
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}
