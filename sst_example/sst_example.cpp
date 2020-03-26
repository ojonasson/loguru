#include <iostream>
#include "loguru.hpp"
#include "loguru_setup.h"

int main()
{
    loguru::loguru_opts opts;
    opts.verbosity = loguru::Verbosity_DEBUG;

    loguru::init_loguru(opts);

    LOG_S(DEBUG) << "Debug message";
    LOG_S(INFO) << "Info message";
    LOG_S(WARNING) << "Warning message";
    LOG_S(ERROR) << "Error message";

    // FATAL throws an error
    try {
        LOG_S(FATAL) << "This is a fatal message. It throws a runtime error";
    } catch (std::exception &e) {
        LOG_S(ERROR) << "Something bad happened. what(): " << e.what();
    }

    LOG_S(INFO) << "End of example!";

    return 0;
}