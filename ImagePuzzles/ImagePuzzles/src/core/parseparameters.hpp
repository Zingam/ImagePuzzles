#ifndef PARSEPARAMETERS_HPP
#define PARSEPARAMETERS_HPP

#include <vector>

#include <QtCore/QString>
#include <QtCore/QStringList>

#include "common/FunctionType.h"

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

