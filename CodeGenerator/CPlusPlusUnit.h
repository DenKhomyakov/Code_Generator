#ifndef CPLUSPLUSUNIT_H
#define CPLUSPLUSUNIT_H

#include "Unit.h"

class CPlusPlusUnit : public ClassUnit {
public:
    CPlusPlusUnit(const std::string& name) : ClassUnit(name) {}

    std::string complile(unsigned int level = 0) const;
};

class CPlusPlusMethodUnit : public MethodUint {
public:
    enum Modifier {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2
    };

public:
    CPlusPlusMethodUnit(const std::string& name, const std::string& returnType, Flags flags) : MethodUint(name, returnType, flags){}

    std::string compile(unsigned int level = 0) const;
};

#endif // CPLUSPLUSUNIT_H
