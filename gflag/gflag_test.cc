#include <gflags/gflags.h>

#include <csignal>
#include <fstream>
#include <iostream>
#include <vector>

DEFINE_string(input_file, "", "input file path");
DEFINE_string(output_file, "", "output file path");
DEFINE_bool(is_binary, false, "is binary file or not");
DEFINE_int32(num_threads, 1, "number of threads");
DEFINE_int64(chunk_size, 1000000, "chunk size for each thread");
DEFINE_bool(verbose, false, "verbose output");
DEFINE_double(timeout, 10.0, "timeout for each thread");

int main(int argc, char* argv[]) {
  gflags::ParseCommandLineFlags(&argc, &argv, true);

  std::cout << "input file path:" << FLAGS_input_file << std::endl;
  std::cout << "output file path:" << FLAGS_output_file << std::endl;
}