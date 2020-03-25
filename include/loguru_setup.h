#pragma once

#include <stdexcept>
#include <string>
#include <iostream>
#include "loguru.hpp"

inline void init_loguru(loguru::Verbosity verbosity)
{

    loguru::set_fatal_handler([](const loguru::Message& message){
        throw std::runtime_error(std::string(message.prefix) + message.message);
    });

    loguru::g_stderr_verbosity  = verbosity; // 0 (INFO) by default.
    loguru::g_colorlogtostderr  = true; // If you don't want color in your terminal.
    loguru::g_flush_interval_ms = 0;    // Unbuffered (0) by default.
    loguru::g_preamble          = true; // Prefix each log line with date, time etc?

    // Turn off individual parts of the preamble
    loguru::g_preamble_date    = false; // The date field
    loguru::g_preamble_time    = false; // The time of the current day
    loguru::g_preamble_uptime  = true; // The time since init call
    loguru::g_preamble_thread  = false; // The logging thread
    loguru::g_preamble_file    = true; // The file from which the log originates from
    loguru::g_preamble_verbose = true; // The verbosity field
    loguru::g_preamble_pipe    = true; // The pipe symbol right before the message
}
