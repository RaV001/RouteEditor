#include    "string-funcs.h"

#include    <algorithm>

//------------------------------------------------------------------------------
//
//------------------------------------------------------------------------------
std::string delete_symbol(const std::string &str, char symbol)
{
    std::string tmp = str;
    tmp.erase(std::remove(tmp.begin(), tmp.end(), symbol), tmp.end());
    return tmp;
}

std::string getNativePath(const std::string &path)
{
    return QDir::toNativeSeparators(QString(path.c_str())).toStdString();
}

std::string toNativeSeparators(const std::string &path)
{
    std::string tmp = path;

#if __unix__
    std::replace(tmp.begin(), tmp.end(), '\\', '/');
#else
    std::replace(tmp.begin(), tmp.end(), '/', '\\');
#endif

    return tmp;
}

char separator()
{
    return QDir::separator().toLatin1();
}

std::string combinePath(const std::string &path1, const std::string &path2)
{
    if (*(path1.end() - 1) != separator())
        return getNativePath(path1 + separator() + path2);
    else
        return getNativePath(path1 + path2);
}
