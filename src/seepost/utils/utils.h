#ifndef SEEPOST_UTILS_H
#define SEEPOST_UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <ldns/ldns.h>
#include <botan/botan.h>

std::string getMX(std::string &domain);
std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);
std::map<std::string, std::string> decodeKV(std::string const &s);
void decodeKV(std::string const &s, std::map<std::string, std::string> &mp);
std::string encodeKV(std::map<std::string, std::string> const &mp);
std::string encodeKVIndex(std::map<size_t, size_t> const &mp);
std::map<size_t, size_t> decodeKVIndex(std::string const &s);
size_t str2uint(std::string const &s);
size_t hex2uint(std::string const &s);
std::string pubkeySig(Botan::Public_Key &pubkey);
bool match_regex(std::string const &regex, std::string const &data);
std::string implode(std::vector<std::string> const &data, char delim);
Botan::SymmetricKey derive_key(const std::string& param,
                        const Botan::SymmetricKey& masterkey,
                        size_t outputlength);

#endif
