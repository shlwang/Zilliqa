add_library (Database LevelDB.cpp MemoryDB.cpp OverlayDB.cpp)
add_library (Overlay SHARED MemoryDB.cpp OverlayDB.cpp)

target_include_directories (Database PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_include_directories (Overlay PUBLIC ${PROJECT_SOURCE_DIR}/src)

target_link_libraries (Database LINK_PUBLIC Common leveldb Utils Overlay)