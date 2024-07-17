//
// Created by Mohammad Hadian on 7/17/24.
//

#include "IUbuntuCloudImageFetcher.h"
#include "UbuntuCloudImageFetcher.cpp"
#include <iostream>

int main() {
    std::cout << "Fetcher initialization!" << std::endl;
    UbuntuCloudImageFetcher fetcher;

    std::cout << "All Supported Releases:" << std::endl;
    for (const auto& release : fetcher.getAllSupportedReleases()) {
        std::cout << release << std::endl;
    }


    std::string release = "noble"; // Example release name
    std::cout << "SHA256 of disk1.img for " << release << ": " << fetcher.getSha256OfDiskImage(release) << std::endl;



    return 0;
}