#ifndef PARSEPARAMETERS_HPP
#define PARSEPARAMETERS_HPP

#include "common/FunctionType.h"

#include <QtCore/QString>
#include <QtCore/QStringList>

#include <vector>

std::vector<Parameter>
parseParameters(QString parameterList)
{
    std::vector<Parameter> parameters;

    QStringList parameterStringValues
            = parametersList.split(" ");

    for (QString& currentParameter: parameterStringValues)
    {
        Parameter parameter;
        parameter.value = currentParameter;
        parameters.push_back(parameterTemp);
    }

    return paramaters;
}

#endif // PARSEPARAMETERS_HPP
