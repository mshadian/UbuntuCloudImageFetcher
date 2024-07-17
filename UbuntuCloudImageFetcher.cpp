//
// Created by Mohammad Hadian on 7/17/24.
//

#include "IUbuntuCloudImageFetcher.h"
#include <curl/curl.h>
#include <json/json.h>
#include <iostream>


class UbuntuCloudImageFetcher : public IUbuntuCloudImageFetcher {
private:
    Json::Value jsonData;

    static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    bool fetchData() {
        std::string url = "https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json";
        CURL *curl;
        CURLcode res;
        std::string readBuffer;

        curl_global_init(CURL_GLOBAL_DEFAULT);
        curl = curl_easy_init();
        if(curl) {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);
            curl_easy_cleanup(curl);

            if(res != CURLE_OK) {
                std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
                return false;
            }
        }
        curl_global_cleanup();

        Json::CharReaderBuilder builder;
        std::string errs;
        std::istringstream s(readBuffer);
        if (!Json::parseFromStream(builder, s, &jsonData, &errs)) {
            std::cerr << "Error parsing JSON data: " << errs << std::endl;
            return false;
        }
        return true;
    }

public:
    UbuntuCloudImageFetcher() {
        if (!fetchData()) {
            std::cerr << "Failed to fetch data." << std::endl;
        }
    }

    std::vector<std::string> getAllSupportedReleases() override {

        const std::vector<std::string> res = {};
        return res;
    }

    std::string getCurrentLTSVersion() override {

        return "";
    }

    std::string getSha256OfDiskImage(const std::string &release) override {

        return "";
    }


};