#include <QCoreApplication>
#include "Factory.h"
#include "Unit.h"

std::string generateProgram(AbstractFactory* factory) {
    std::shared_ptr<ClassUnit> myClass = factory->buildClass("MyClass");

    myClass->add(
        factory->buildMethod("testFunc1", "void", MethodUnit::PUBLIC),
        ClassUnit::PUBLIC
        );

    myClass->add(
        factory->buildMethod("testFunc2", "void", MethodUnit::STATIC | MethodUnit::PRIVATE),
        ClassUnit::PRIVATE
        );

    myClass->add(
        factory->buildMethod("testFunc3", "void", MethodUnit::CONST | MethodUnit::PROTECTED | MethodUnit::PRIVATE),
        ClassUnit::PROTECTED
        );

    std::shared_ptr<MethodUnit> method = factory->buildMethod("testFunc4", "void", MethodUnit::STATIC | MethodUnit::PROTECTED);
    method->add(factory->buildPrintOperator( R"(Hello, world!\n)"));
    myClass->add(method, ClassUnit::PROTECTED);

    return myClass->compile();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::cout << "C++:" << std::endl;
    CPlusPlusFactory cPlusPlusFactory;
    std::cout << generateProgram(&cPlusPlusFactory) << std::endl;

    std::cout << "Java:" << std::endl;
    JavaFactory javaFactory;
    std::cout << generateProgram(&javaFactory) << std::endl;

    std::cout << "C#:" << std::endl;
    CSharpFactory cSharpFactory;
    std::cout << generateProgram(&cSharpFactory) << std::endl;

    return a.exec();
}
