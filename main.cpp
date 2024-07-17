#include "IUbuntuCloudImageFetcher.h"
#include "UbuntuCloudImageFetcher.cpp"
#include <iostream>
#include <getopt.h>

void printHelp() {
    std::cout << "Usage: UbuntuCloudImageFetcher [options]\n"
              << "Options:\n"
              << "  -a, --all           List all supported Ubuntu releases\n"
              << "  -l, --lts           Show the current Ubuntu LTS version\n"
              << "  -s, --sha256 <release>  Show the sha256 of disk1.img for the specified release\n"
              << "  -h, --help          Display this help message\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printHelp();
        return 1;
    }

    UbuntuCloudImageFetcher fetcher;

    const char *short_options = "als:h";
    const struct option long_options[] = {
            {"all", no_argument, nullptr, 'a'},
            {"lts", no_argument, nullptr, 'l'},
            {"sha256", required_argument, nullptr, 's'},
            {"help", no_argument, nullptr, 'h'},
            {nullptr, 0, nullptr, 0}
    };

    int option_index = 0;
    int opt;
    while ((opt = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (opt) {
            case 'a': {
                std::cout << "All Supported Releases:" << std::endl;
                for (const auto& release : fetcher.getAllSupportedReleases()) {
                    std::cout << release << std::endl;
                }
                break;
            }
            case 'l': {
                std::cout << "Current LTS Version: " << fetcher.getCurrentLTSVersion() << std::endl;
                break;
            }
            case 's': {
                if (optarg) {
                    std::string release = optarg;
                    std::cout << "SHA256 of disk1.img for " << release << ": " << fetcher.getSha256OfDiskImage(release) << std::endl;
                } else {
                    std::cerr << "Error: No release specified for --sha256 option" << std::endl;
                    return 1;
                }
                break;
            }
            case 'h':
            default: {
                printHelp();
                return 1;
            }
        }
    }

    return 0;
}
