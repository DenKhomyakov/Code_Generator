#include "Factory.h"
#include "CPlusPlusUnit.h"
#include "JavaUnit.h"
#include "CSharpUnit.h"

std::shared_ptr<ClassUnit> CPlusPlusFactory::buildClass(const std::string& name) {
    return std::make_shared<CPlusPlusClassUnit>(name);
}

std::shared_ptr<MethodUnit> CPlusPlusFactory::buildMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) {
    return std::make_shared<CPlusPlusMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CPlusPlusFactory::buildPrintOperator(const std::string& text) {
    return std::make_shared<CPlusPlusPrintOperatorUnit>(text);
}

std::shared_ptr<ClassUnit> JavaFactory::buildClass(const std::string& name) {
    return std::make_shared<JavaClassUnit>(name);
}

std::shared_ptr<MethodUnit> JavaFactory::buildMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) {
    return std::make_shared<JavaMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> JavaFactory::buildPrintOperator(const std::string& text) {
    return std::make_shared<JavaPrintOperatorUnit>(text);
}

std::shared_ptr<ClassUnit> CSharpFactory::buildClass(const std::string& name) {
    return std::make_shared<CSharpClassUnit>(name);
}

std::shared_ptr<MethodUnit> CSharpFactory::buildMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) {
    return std::make_shared<CSharpMethodUnit>(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> CSharpFactory::buildPrintOperator(const std::string& text) {
    return std::make_shared<CSharpPrintOperatorUnit>(text);
}
