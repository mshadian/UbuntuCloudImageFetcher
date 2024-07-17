//
// Created by Mohammad Hadian on 7/17/24.
//

#ifndef IUBUNTUCLOUDIMAGEFETCHER_H
#define IUBUNTUCLOUDIMAGEFETCHER_H
#include <string>
#include <vector>

class IUbuntuCloudImageFetcher {
public:
    virtual ~IUbuntuCloudImageFetcher() = default;

    virtual std::vector<std::string> getAllSupportedReleases() = 0;
    virtual std::string getCurrentLTSVersion() = 0;
    virtual std::string getSha256OfDiskImage(const std::string &release) = 0;
};

#endif //IUBUNTUCLOUDIMAGEFETCHER_H
