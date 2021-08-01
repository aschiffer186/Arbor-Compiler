#ifndef PREPROCESSOR_HH
#define PREPROCESSOR_HH 1

///@file preprocessor.hh Preprocesses the source file and creates a @b source_file_t object represeting the source file. 

#include "../Arbor.hh"

///\namespace Arbor::FE The parent namespace for all code for the front end of the compiler'
namespace Arbor::FE
{
    /**
     * @brief Preprocesses the specified source file.
     * 
     * Preprocesses the specified source file. Specficially, the preprocess function performs the following steps 
     * in this order
     *  1. It creates a @b source_file_t object for the source file
     *  2. It replaces all __XXX__ constants with their actual value as a string. Acceptable constants are 
     *      __LINE__: the current line in the source file
     *      __FILE__: the name of the current source file
     *      __VERSION__: the current version of Arbor being run
     *      __DATE__: the current date and time
     *      __TIME__: the current time
     *      __OS__: the operating system the file was compiled on. The values for each operating system are
     *          WIN32: 32 bit Windows,
     *          WIN64: 64 bit Windows,
     *          APPLE: Any Apple operating system,
     *          LINUX: Any Linux operating system,
     *          OTHER: Unrecognized operating system
     *  
     */ 
    source_file_t preprocess(const std::string& filename);
} // namespace Arbor::FE


#endif