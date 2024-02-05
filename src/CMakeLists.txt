set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Add source to this project's executable.
add_executable (33-1-shopping-basket "main.cpp" ${MY_INCLUDE_DIR}/onlinestore.h "onlinestore.cpp")

target_include_directories(33-1-shopping-basket PUBLIC ${CMAKE_SOURCE_DIR}/include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 33-1-shopping-basket PROPERTY CXX_STANDARD 20)
endif()