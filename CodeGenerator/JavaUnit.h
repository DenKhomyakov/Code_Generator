#ifndef JAVAUNIT_H
#define JAVAUNIT_H

#include "Unit.h"

class JavaClassUnit : public ClassUnit {
public:
    JavaClassUnit(const std::string& name) : ClassUnit(name) {}

    std::string compile(unsigned int level = 0) const override;
};

class JavaMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        FINAL = 1 << 3,
        ABSTRACT = 1 << 4,
        PUBLIC = 1 << 5,
        PROTECTED = 1 << 6,
        PRIVATE = 1 << 7
    };

public:
    JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags) : MethodUnit(name, returnType, flags) {}

    std::string compile(unsigned int level = 0) const override;
};

class JavaPrintOperatorUnit : public PrintOperatorUnit {
public:
    JavaPrintOperatorUnit(const std::string& text) : PrintOperatorUnit(text) {}

    std::string compile (unsigned int level = 0) const override;
};

#endif // JAVAUNIT_H
