#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include "loguru.hpp"

namespace loguru {

    struct loguru_opts {
        loguru::Verbosity verbosity = loguru::Verbosity_INFO; // logging verbosity
        bool colorlogtostderr = true; // If you don't want color in your terminal.
        int flush_interval_ms = 0;    // Unbuffered (0) by default.
        bool preamble = true; // Prefix each log line with date, time etc?

        // Turn off individual parts of the preamble
        bool preamble_date = false; // The date field
        bool preamble_time = false; // The time of the current day
        bool preamble_uptime = true; // The time since init call
        bool preamble_thread = false; // The logging thread
        bool preamble_file = true; // The file from which the log originates from
        bool preamble_verbose = true; // The verbosity field
        bool preamble_pipe = true; // The pipe symbol right before the message
    };

    inline void init_loguru(const loguru_opts &opts = loguru_opts()) {
        loguru::set_fatal_handler([](const loguru::Message &message) {
            throw std::runtime_error(std::string(message.prefix) + message.message);
        });

        loguru::g_stderr_verbosity = opts.verbosity;
        loguru::g_colorlogtostderr = opts.colorlogtostderr;
        loguru::g_flush_interval_ms = opts.flush_interval_ms;
        loguru::g_preamble = opts.preamble;

        // Turn off individual parts of the preamble
        loguru::g_preamble_date = opts.preamble_date;
        loguru::g_preamble_time = opts.preamble_time;
        loguru::g_preamble_uptime = opts.preamble_uptime;
        loguru::g_preamble_thread = opts.preamble_thread;
        loguru::g_preamble_file = opts.preamble_file;
        loguru::g_preamble_verbose = opts.preamble_verbose;
        loguru::g_preamble_pipe = opts.preamble_pipe;
    }

} // end of namespace loguru