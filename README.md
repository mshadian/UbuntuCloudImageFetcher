# UbuntuCloudImageFetcher

UbuntuCloudImageFetcher is a command-line interface (CLI) tool written in C++ that fetches the latest Ubuntu Cloud image information in Simplestreams format from [Ubuntu Cloud Images](https://cloud-images.ubuntu.com/releases/streams/v1/com.ubuntu.cloud:released:download.json). It provides methods to:
- Return a list of all currently supported Ubuntu releases for `amd64` architecture.
- Return the current Ubuntu LTS (Long Term Support) version for `amd64` architecture.
- Return the sha256 checksum of the `disk1.img` item of a given Ubuntu release for `amd64` architecture.

## Features

- **List all supported Ubuntu releases**: Fetches and lists all currently supported Ubuntu releases for `amd64` architecture.
- **Get the current LTS version**: Identifies and returns the latest Ubuntu LTS version for `amd64` architecture.
- **Get sha256 checksum**: Returns the sha256 checksum of the `disk1.img` item for a specified Ubuntu release and `amd64` architecture.

## Requirements

- C++11 or higher
- CMake (for building the project)
- [libcurl](https://curl.se/libcurl/) (for HTTP requests)
- [jsoncpp](https://github.com/open-source-parsers/jsoncpp) (for JSON parsing)

## Installation

### Installing Dependencies on macOS

1. **Install Homebrew (if not already installed)**:
    ```sh
    /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
    ```

2. **Install `libcurl` and `jsoncpp`**:
    ```sh
    brew install curl jsoncpp
    ```