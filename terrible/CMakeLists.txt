
add_executable(terrible
    terrible.cpp
)

target_link_libraries(terrible
    ${Boost_LIBRARIES}

    # other random libraries listings go here
)
