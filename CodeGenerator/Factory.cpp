#include "Factory.h"
#include "CPlusPlusUnit.h"

std::shared_ptr<ClassUnit> CPlusPlusFactory::buildClass(const std::string& name) {
    return std::make_shared<CPlusPlusClassUnit>(name);
}

std::shared_ptr<MethodUnit> CPlusPlusFactory::buildMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) {
    return std::make_shared<CPlusPlusMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CPlusPlusFactory::buildPrintOperator(const std::string& text) {
    return std::make_shared<CPlusPlusPrintOperatorUnit>(text);
}

