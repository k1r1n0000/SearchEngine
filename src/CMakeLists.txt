cmake_minimum_required (VERSION 3.22)

set(Src
	"ConverterJSON.cpp"
	"InvertedIndex.cpp"
	"SearchServer.cpp"
	"main.cpp"
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
add_executable(SearchEngine ${Src})

target_link_libraries(SearchEngine nlohmann_json::nlohmann_json)
target_include_directories(SearchEngine PUBLIC ${MY_INCLUDE_DIR})