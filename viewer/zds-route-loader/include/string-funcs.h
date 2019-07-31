#ifndef     STRING_FUNCS_H
#define     STRING_FUNCS_H

#include    <string>
#include    <QDir>

std::string delete_symbol(const std::string &str, char symbol);

std::string getNativePath(const std::string &path);

std::string toNativeSeparators(const std::string &path);

char separator();

std::string combinePath(const std::string &path1, const std::string &path2);

#endif // STRING_FUNCS_H
