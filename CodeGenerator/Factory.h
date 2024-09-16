#ifndef FACTORY_H
#define FACTORY_H

#include "Unit.h"

class AbstractFactory {
public:
    virtual std::shared_ptr<ClassUnit> buildClass(const std::string& name) = 0;
    virtual std::shared_ptr<MethodUnit> buildMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) = 0;
    virtual std::shared_ptr<PrintOperatorUnit> buildPrintOperator(const std::string& text) = 0;
};

class CPlusPlusFactory : public AbstractFactory {
    std::shared_ptr<ClassUnit> buildClass(const std::string& name) override;
    std::shared_ptr<MethodUnit> buildMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> buildPrintOperator(const std::string& text) override;
};

class JavaFactory : public AbstractFactory {
    std::shared_ptr<ClassUnit> buildClass(const std::string& name) override;
    std::shared_ptr<MethodUnit> buildMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> buildPrintOperator(const std::string& text) override;
};

class CSharpFactory : public AbstractFactory {
    std::shared_ptr<ClassUnit> buildClass(const std::string& name) override;
    std::shared_ptr<MethodUnit> buildMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) override;
    std::shared_ptr<PrintOperatorUnit> buildPrintOperator(const std::string& text) override;
};

#endif // FACTORY_H
